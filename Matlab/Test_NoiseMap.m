% Gen the noise map using one of the routes of the using a FlightPath
clear;
t=tic;

file_name = 'FlightPath_JETFAC';
load(file_name);

load('./NPD_Data/NPDdataA320-232');   

%
% Some required info about the plane and the atmospheric conditions
%
Vref = 270.05; % Reference groundspeed for which NPD data are defined
               % ft/s for the reference 160 knots reference speed
Aircraft.WingMounted = true;
Aircraft.TurboFan = true;
% Atmospheric conditions: have very little impact (< 0.1 dB)
AtmCond.p = 101.325; % Standard air pressure at the mean sea level (kPa) 
AtmCond.T = 15; % Standard temperature (Celcius degrees)

M2FT = 3.28084;

NoiseMetric = 'LAmax'; % Noise metric NPD data 'SEL' or 'LAmax' 


    

x_range = -30000:1000:30000;
y_range = -30000:1000:30000;

ix_start = 1;

for ix = ix_start:length(x_range)
    for iy = 1:length(y_range)
        
        RXX = [x_range(ix), y_range(iy), 0 ]*M2FT;
        fprintf('[%7.0f %7.0f] ', x_range(ix), y_range(iy) );
  
        Lseg = ANCM_GetLpath(FlightPath, RXX, NPDdata, NoiseMetric, Vref, Aircraft, AtmCond); 
    
        if strcmp(NoiseMetric,'SEL')
            Lw(ix,iy)=ANCM_GetEqSoundLevel(Lseg);
            fprintf('Leq %5.2f\n', Lw(ix,iy));
        else
            Lw(ix,iy)=max(Lseg);
            fprintf('Lmax %f\n', Lw(ix,iy));
        end
    end
end

save(['NoiseMap_', file_name, '_', NoiseMetric ], 'x_range','y_range','Lw');

levels = [50:5:120];
contourf(x_range,y_range,Lw',levels, 'ShowText','on','LineWidth',2);
xlabel('x (m)');
ylabel('y (m)');
set(gca,'FontSize',18);

toc(t)
