function [DeltaImp] = ANCM_GetDeltaImpedance(p, T)
% ANCM_GetDeltaImpedance IMPEDANCE ADJUSTMENT OF STANDARD NPD DATA
% The acoustic impedance adjustment is usually less than a few tenths of one dB. 
% See section 4.2.1 of Doc.29, 4th edition, Vol.2 
% Input
%   p: Ambient air pressure at the observer in KPa
%   T: Air temperature at the observer altitude (celcius)
% Output
%   DeltaImp: Impedante adjustment of standard NPD data
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

% Eq. 4.7
T0 = 15; % º celcius reference temperature
p0 = 101.325; % kPa: air pressure at mean sea level
theta = (T+273.15)/(T0+273.15);
delta = p/p0;
rho_c = 416.86*(delta/sqrt(theta));

% Eq. 4.6
DeltaImp = 10*log10(rho_c/409.81);