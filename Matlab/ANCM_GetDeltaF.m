function [DeltaF] = ANCM_GetDeltaF(Gd,Seg,NPDdata,OpMode,Vref)
% FiniteSegmentCorrection (DeltaF) adjusts the level to what it would be if the aircraft traversed 
% the finite segment only
% See section 4.5.6 of Doc.29, 4th edition, Vol.2 
% Input
%   Gd: geometry data
%   Seg: An struct with the segment data. It has the following fields
%       S1,S2: Points of the segment of the route
%       epsilon: bank angle (in Euler angles: phi - roll) 
%       P: Power
%       isRolling: the plane is in takeoff roll or landing roll
%   NPDdata: table with all the NPD data of the aircraft
%   OpMode: Operation mode ('A','D')
%   Vref: Reference groundspeed for which NPD data are defined
% Output
%   DeltaF: Finite segment correction
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

% Some precalculation for the the next equations
t0 = 1; % 1 seems to be OK
d0=2/pi*Vref*t0;
LE= ANCM_GetLPd(Seg.P, Gd.D,NPDdata,'SEL',OpMode);
Lmax = ANCM_GetLPd(Seg.P, Gd.D,NPDdata,'LAmax',OpMode);

d_Lambda = d0*10^((LE-Lmax)/10);

if Seg.isRolling && OpMode == 'D' && Gd.q< 0 % Rolling, takeoff and behind (D=departure mode)
    % Eq. 4.21a
    alpha2 =  Gd.lambda/d_Lambda;    
    DeltaF = 10*log10(1/pi* (alpha2/(1+alpha2^2) + atan(alpha2) ));
elseif Seg.isRolling && OpMode == 'A' && Gd.q >  Gd.lambda % Rolling, landing and ahead (A=arrival mode)
    % Eq. 4.21b
    alpha1 = -Gd.lambda/d_Lambda;  
    DeltaF = 10*log10(1/pi* ( - alpha1/(1+alpha1^2) - atan(alpha1) ));
else
    % Eq. 4-20
    alpha1 = - Gd.q/d_Lambda;
    alpha2 = -( Gd.q- Gd.lambda)/d_Lambda;
    DeltaF = 10*log10(1/pi* (alpha2/(1+alpha2^2) + atan(alpha2) - alpha1/(1+alpha1^2) - atan(alpha1) ) );
end
end

