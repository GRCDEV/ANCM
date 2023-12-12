function [DeltaI] = ANCM_GetDeltaI(Gd,Aircraft)
% ANCM_GetDeltaI Engine installation correction
% See section 4.5.3 of Doc.29, 4th edition, Vol.2 
% Input
%   Gd: geometry data
%   Aircraft: information about the aircraft (sn struct)
%       WingMounted: true -> wing-mounted engine;false -> fuselage mounted
%       TurboFan: true: turbo-fan propelled, false: turbo-prop propelled
% Output
%   DeltaI: Engine installation correction
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

if Aircraft.TurboFan

    if Aircraft.WingMounted
        a = 0.0039; b = 0.062; c = 0.8766;
    else
        a = 0.1225; b = 0.329; c = 1;
    end
    
    % Eq. 4-15
    DeltaI = 10*log10( (a*cosd(Gd.phi)^2+ sind(Gd.phi)^2)^b / (c*sind(2*Gd.phi)^2+cosd(2*Gd.phi)^2) );

else
    % Propeller is zero
    DeltaI = 0;
end

end

