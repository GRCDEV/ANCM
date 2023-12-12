function [Lseg, Gd, Corr] = ANCM_GetLseg(Seg, Ob, NPDdata, NoiseMetric, OpMode, MOS, Vref, Aircraft, AtmCond)
% ANCM_GetLseg Get Segment Event Level Lseg 
% Implements interpolation equations of Section 4.3.1 from  Doc.29, 4th edition, Vol.2  
% Inputs:
%   Seg: An struct with the segment data. It has the following fields
%       S1,S2: Points of the segment of the route
%       epsilon: bank angle (in Euler angles: phi - roll) 
%       P: Power
%       Vseg: Speed of the segment
%       isRolling: the plane is in takeoff roll or landing roll
%   Ob: Observer location 
%   NPDdata: table with all the NPD data of the aircraft
%       Imported directly from the .csv spreadsheet with the same columns names 
%   NoiseMetric, OpMode: to select the data from NPD
%       It depends on the plane, but NoiseMetric can be 'EPNL', 'LAmax',
%       'PNLTM' and 'SEL'; and OpMode is 'A' arrival and 'D' descending
%       In case 'LAmax', the formulas used are different.
%   MOS: Method to obtain the slant 
%       'MLM' : Maximum level metrics (D=Ds always)
%       'EMT' : Exposure metrics takeoff (D can be Ds or Dp)
%       'EML' : Exposure metrics landing (D can be Ds or Dp)
%   Vref: Reference groundspeed for which NPD data are defined
%   Aircraft: information about the aircraft (an struct)
%       WingMounted: true -> wing-mounted engine;false -> fuselage mounted
%       TurboFan: true: turbo-fan propelled, false: turbo-prop propelled
%   AtmCond: Atmospheric conditions to get the impedance adjustament. Two fields:
%       p: Ambient air pressure at the observer in KPa
%       T: Air temperature at the observer altitude (celcius)
% Output
%   Lseg: Segment event noise (in dB)
%   Gd: An struct with all these geometrics data fields
%       D: Slant distance for obtaining the baseline noise level
%       Dp: Perpendicular distance between observer and extended segment
%       D1,D2: Distance to the points of the segment
%       q: distance from S1 to Sp (negative if the observer is behind the segment)
%       lambda: length of flight path segment
%       gamma: climb angle
%       beta: elevation angle 
%       l: lateral displacement
%       phi: depression angle
%       heading: angle direction to 0,0
%   Corr: An struct with the baseline noise and all the corrections
%       Ld: baseline noise
%       DeltaV: Duration correction
%       DeltaI: Installation effect 
%       Lambda: Lateral attenuation
%       DeltaF: Finite segment correctionx
%       DeltaSOR: Directivity correction
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

    % 1: Get all the necessary geometry data 
    Gd = ANCM_GetGeometryData(Seg,Ob,MOS);

    % 2: Get the baseline noise level from the slant distance
    Corr.Ld = ANCM_GetLPd(Seg.P,Gd.D,NPDdata,NoiseMetric,OpMode);
    
    % 3: Calculate the corrections
    Corr.DeltaImp = ANCM_GetDeltaImpedance(AtmCond.p, AtmCond.T);
    Corr.DeltaV = ANCM_GetDeltaV(Vref,Seg.Vseg);
    Corr.DeltaI = ANCM_GetDeltaI(Gd,Aircraft);
    Corr.Lambda = ANCM_GetLambda(Gd);
    Corr.DeltaF = ANCM_GetDeltaF(Gd,Seg,NPDdata,OpMode,Vref);
    if Seg.isRolling && Gd.q < 0 && OpMode == 'D'
        % Correction only when departing, rolling and behing the segment
        Corr.DeltaSOR = ANCM_GetDeltaSOR(Gd, Aircraft.TurboFan);
    else
        Corr.DeltaSOR = 0;
    end

    if ~strcmp(NoiseMetric,'LAmax')
        % Eq. 4-9b  
        Lseg = Corr.Ld+Corr.DeltaV+Corr.DeltaImp+Corr.DeltaI-Corr.Lambda+Corr.DeltaF+Corr.DeltaSOR;
    else
        % Eq. 4.9a (only for LAmax)
        Lseg = Corr.Ld+Corr.DeltaImp+Corr.DeltaI-Corr.Lambda+Corr.DeltaSOR;
    end
end
