function [Lout] = ANCM_GetLPd(P,d,NPDdata,NoiseMetric,OpMode)
% ANCM_GetLPd Interpolation of noise-power-distances curves depending on P (Power) 
% and d (distance using NPD data.
% Implements interpolation equations of Section 4.2 from 
% Doc.29, 4th edition, Vol.2  
% Inputs:
%     P: Power
%     d: Slant distance (in ft)
%     NPDdata: table with all the NPD data of the aircraft
%     NoiseMetric, OpMode: to select the data from NPD
% Output
%     Lout: Interpolated noise
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

d = max(d,100);  % it is recommended that a lower limit of 30 m be imposed on d, i.e. d = max(d, 30 m).

% Fixed distance values from the table (in ft)
Dis = [200, 400, 630, 1000, 2000, 4000, 6300, 10000, 16000, 25000];

% Obtain the noise level using the tables
    function Lout = L(id,iP)
        % id index of the distance
        % iP index of the Power
        Lout = table2array(NPDdata_f(iP,4+id)); 
    end

    function Ld = L_int_d(iP,id2,id1,d)
        % Eq. 4.4. and 4.5a/4.6b
        if id1 == 0
            % inwards equation 4.5a
            Ld = L(2,iP)+ (L(1,iP)-L(2,iP))/(log(Dis(2))-log(Dis(1)))* (log(Dis(2))-log(d));
        elseif id1==id2
            % outwards equation 4.5b -> the formula in the doc. is incorrect
            % Ld = L(id1-1,iP)+ (L(id1-1,iP)-L(id1,iP))/(log(Dis(id1))-log(Dis(id1-1)))* (log(d)-log(Dis(id1-1)));
            Ld = L(id1,iP)+ (L(id1,iP)-L(id1-1,iP))/(log(Dis(id1))-log(Dis(id1-1)))* (log(d)-log(Dis(id1)));
        else
            Ld = L(id1,iP)+(L(id2,iP)-L(id1,iP))/(log(Dis(id2))-log(Dis(id1)))*(log(d)-log(Dis(id1)));
        end
    end

    function Lp = L_int_P(LP2,LP1,P2,P1,P)
        % Eq. 4.3.
        Lp = LP1+(LP2-LP1)/(P2-P1)*(P-P1);
    end

Filter = ismember(NPDdata.NoiseMetric,NoiseMetric) & ismember(NPDdata.OpMode,OpMode);
NPDdata_f = NPDdata(Filter,:);     

% Get the P interval
iP2 = find(NPDdata_f.PowerSetting>= P,1);
if isempty(iP2) 
    iP1=length(NPDdata_f.PowerSetting);  % outwards
    iP2=iP1;
else
    iP1 = iP2 - 1;
end

% Get the d interval
id2 = find(Dis>= d,1);
if isempty(id2)
    id1=length(Dis);  % outwards
    id2=id1;
else
    id1 = id2-1;
end
        
  
if iP1 == 0
    % Inwards
    iP1 = 1;
    iP2 = 2;
    P1 = NPDdata_f.PowerSetting(iP1);
    P2 = NPDdata_f.PowerSetting(iP2);
    LP1=L_int_d(iP1,id2,id1,d);
    LP2=L_int_d(iP2,id2,id1,d);
    % Eq. 4.3. inwards modification!!
    Lout= LP2+(LP1-LP2)/(P2-P1)*(P2-P);

elseif iP1 == iP2
    % Outwards
    iP2 = length(NPDdata_f.PowerSetting);
    iP1 = iP2 - 1;
    P1 = NPDdata_f.PowerSetting(iP1);
    P2 = NPDdata_f.PowerSetting(iP2);
    LP1=L_int_d(iP1,id2,id1,d);
    LP2=L_int_d(iP2,id2,id1,d); 
    % Eq. 4.3. outwards
    Lout= LP2+(LP2-LP1)/(P2-P1)*(P-P2);
else
    P1 = NPDdata_f.PowerSetting(iP1);
    P2 = NPDdata_f.PowerSetting(iP2);
    LP1=L_int_d(iP1,id2,id1,d);
    LP2=L_int_d(iP2,id2,id1,d);
    % Eq. 4.3.
    Lout= LP1+(LP2-LP1)/(P2-P1)*(P-P1);
end 

% fprintf('L=%f, Dis = [%f,%f] d = %f P = %d\n ', L_dP1, Dis(id1), Dis(id2), d, P1); 
% fprintf('L=%f, Dis = [%f,%f] d = %f P = %d\n ', L_dP2, Dis(id1), Dis(id2), d, P2); 
% fprintf('LP=%f, P = [%f,%f] P = %d \n ', Lout, P2, P1, P); 


end

