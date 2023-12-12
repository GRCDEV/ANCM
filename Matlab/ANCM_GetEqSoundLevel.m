function [Lw] = ANCM_GetEqSoundLevel(Lseg,G,t0,T0,C)
% ANCM_GetEqSoundLevel Get weighted equivalent sound levels
% See section 51. of Doc.29, 4th edition, Vol.2 
% Input
%   Lseg: vector with the single event noise of each segment
%   G: vector with the weighting factor (optional - 1 by default)
%   t0,T0: time interval (optional - 1 by default)
%   C: normalised contact (optional - 0 by default)
% Output
%   Lw: Equivalent sound level
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

if nargin < 5
    C = 0;
end
if nargin < 3
    t0 = 1; 
    T0 = 1;  
end
if nargin < 2
    gi = ones(1,length(Lseg));  % All have the same weigh
end
    
Lw = 10*log10(t0/T0*sum(10.^(Lseg/10)));

end