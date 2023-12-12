% Get the noise level from a given point
clear;

file_name = 'FlightPath_JETFAC';
%file_name = 'FlightPath_JETFAS';
load(file_name);

load('./NPD_Data/NPDdata_TestJETF');   % Jet body-mounted turbo-fan engines
% load('./NPD_Data/NPDdata_TestJETW');   % Jet wing-mounted turbo-fan engines
% load('./NPD_Data/NPDdata_TestPROP'); % Turbo-Prop engines

%
% Some required info about the plane and the atmospheric conditions
%
Vref = 270.05; % Reference groundspeed for which NPD data are defined
               % ft/s for the reference 160 knots reference speed
Aircraft.WingMounted = false;
Aircraft.TurboFan = true;
% Atmospheric conditions: have very little impact (< 0.1 dB)
AtmCond.p = 101.325; % Standard air pressure at the mean sea level (kPa) 
AtmCond.T = 15; % Standard temperature (Celcius degrees)

M2FT = 3.28084;
Ob = [3000, 500, 0]*M2FT;  % Obsever points

NoiseMetric = 'LAmax'; % Npise metric NPD data 'SEL' or 'LAmax' 

Lseg = ANCM_GetLpath(FlightPath, Ob, NPDdata, NoiseMetric, Vref, Aircraft, AtmCond); 
    
if strcmp(NoiseMetric,'SEL')
    Lw=ANCM_GetEqSoundLevel(Lseg);
else
    Lw=max(Lseg);
end

fprintf('Noise Level %f dB from point [%5.2f,%5.2f,%5.2f] ft\n', Lw, Ob(1),Ob(2),Ob(3));