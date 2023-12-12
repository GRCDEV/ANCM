function [L] = ANCM_GetLpath(FlightPath, Ob, NPDdata, NoiseMetric, Vref, Aircraft, AtmCond)
% ANCM_GetLpath Get a vector with all segment event level 
% Implements interpolation equations of Section 4.3.1 from  Doc.29, 4th edition, Vol.2  
% Inputs:
%   FlightPath: A table with the segments of the flight path. Contains the following columns.
%      case_ID: Id with the flight path (not used)
%      segment_ID: Number of the segment (not used)
%      segment_start_xft, segment_start_yft, segment_start_zft : start of segment  
%      segment_end_xft, segment_end_yft, segment_end_zft : end of segment
%      thrustlbe : Power  
%      bank_angle : bank angle (in Euler angles: phi - roll)  
%      op_mode: 'A' arrival and 'D' descending
%      isRolling: the plane is in takeoff roll or landing roll   
%      groundspeedft : ground speed of the segment
%   Ob: Observer location 
%   NPDdata: A table with all the NPD data of the aircraft
%       Imported directly from the .csv spreadsheet with the same columns names 
%   NoiseMetric: to select the data from NPD
%       It depends on the plane, but NoiseMetric can be 'EPNL', 'LAmax',
%       'PNLTM' and 'SEL'; 
%       In case 'LAmax', the formulas used are different.
%   Vref: Reference groundspeed for which NPD data are defined
%   Aircraft: information about the aircraft (an struct)
%       WingMounted: true -> wing-mounted engine;false -> fuselage mounted
%       TurboFan: true: turbo-fan propelled, false: turbo-prop propelled
%   AtmCond: Atmospheric conditions to get the impedance adjustament. Two fields:
%       p: Ambient air pressure at the observer in KPa
%       T: Air temperature at the observer altitude (celcius)
% Output
%   L: A vector with all segment event noises (in dB)
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

for i = 1:height(FlightPath)
    % Get the segment data
    Seg.S1 = [ FlightPath.segment_start_xft(i), FlightPath.segment_start_yft(i), FlightPath.segment_start_zft(i)];
    Seg.S2 = [ FlightPath.segment_end_xft(i), FlightPath.segment_end_yft(i), FlightPath.segment_end_zft(i)];
    Seg.isRolling = FlightPath.isRolling(i); 
    Seg.epsilon = FlightPath.bank_angle(i);
    Seg.P = FlightPath.thrustlbe(i);
    Seg.Vseg = FlightPath.groundspeedft(i); 
    
    if strcmp(NoiseMetric,'LAmax')
        MOS = 'MLM';
    elseif FlightPath.op_mode(i) == 'A'
        MOS = 'EML';        % Exposure metrics landing
    else
        MOS = 'EMT';        % Exposure metrics takeoff  
    end
    
    L(i) = ANCM_GetLseg(Seg, Ob, NPDdata, NoiseMetric, FlightPath.op_mode(i), MOS, Vref, Aircraft, AtmCond); 
end
