function [DeltaV] = ANCM_GetDeltaV(Vref, Vseg)
% ANCM_GetDeltaV (Duration correction) 
% accounts for a change in exposure levels if the actual segment speed is
% different to the aircraft reference speed Vref to which the basic NPD data relate.
% See section 4.5.1 of Doc.29, 4th edition, Vol.2 
% Input
%   Vref: Speed of reference
%   Vseg: Speed of the segment
% Output
%   DeltaV: Duration correction
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia
DeltaV = 10*log10(Vref/Vseg);