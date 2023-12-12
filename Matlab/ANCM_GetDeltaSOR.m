function [DeltaSOR] = ANCM_GetDeltaSOR(Gd, TurboFan)
% ANCM_GetDeltaSOR The Start-of-roill directevity function DeltaSOR
% accounts for the pronounced directionality of jet engine noise behind the ground roll segment
%
% See section 4.5.7 of Doc.29, 4th edition, Vol.2 
% Input
%   Gd: geometry data
%   TurboFan: true: turbo-fan propelled, false: turbo-prop propelled
% Output
%   DeltaSOR: Impedante adjustment of standard NPD data
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia   

% Start-of-roll directivity function Delta_SOR

dSOR = Gd.D1;
dSOR0 = 2500; % ft
Phi = acosd(Gd.q/dSOR);  % in degrees
DeltaSOR = 0;
if TurboFan
    % Eq. 4-24a;
    if 90 <= Phi && Phi <= 180
        DeltaSOR0 = 2329.44-(8.0573*Phi)+(11.51*exp(pi*Phi/180))-(3.4601*Phi)/log(pi*Phi/180) - (17403338.3*log(pi*Phi/180)/Phi^2);
    end
else
    % Eq. 4-24b;
    if 90 <= Phi && Phi <= 180
        DeltaSOR0 =-34643.898+(30722161.987/Phi)-(11491573930.510/Phi^2) + (2349285669062/Phi^3) ...
            -(283584441904272/Phi^4)+(20227150391251300/Phi^5)-(790084471305203000/Phi^6) ...
            +(13050687178273800000/Phi^7);
    end
end

if dSOR <= dSOR0
    DeltaSOR = DeltaSOR0;
else
    DeltaSOR = DeltaSOR0*dSOR0/dSOR;
end


    