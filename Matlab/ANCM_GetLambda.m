function [Lambda] = ANCM_GetLambda(Gd)
% ANCM_GetLambda Lateral attenuation 
% See section 4.5.4 of Doc.29, 4th edition, Vol.2 
% Input
%   Gd: geometry data
% Output
%   Lambda: Lateral attenuation
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

M2FT = 3.28084;  % Meters to feet

% Eq. 4.19 a-b
l = Gd.l/M2FT;  % l must be in meters
if l <= 914
    GAMMAl = 1.089*(1-exp(-0.00274*l));
else
    GAMMAl = 1;
end

% Eq. 4.19 c-d
if Gd.beta < 0
    LambdaB = 10.857;
elseif Gd.beta <= 50
    LambdaB = 1.137 - 0.0229*Gd.beta+9.72*exp(-0.142*Gd.beta);
else
    LambdaB = 0;
end

% Eq. 4-18
Lambda = GAMMAl*LambdaB;

