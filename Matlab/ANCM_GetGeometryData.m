function [Gd] = ANCM_GetGeometryData(Seg,Ob,MOS)
% ANCM_GetGeometryData Get the geometry data necessary for obtaining 
% % the baseline noise level and the rest of corrections
% See sections 4.4.1, 4.5.2 and 4.5.5 of Doc.29, 4th edition, Vol.2  
% Input
%  Seg: An struct with the segment data. It has the following fields
%       S1,S2: Points of the segment of the route
%       epsilon: bank angle (in Euler angles: phi - roll) 
%       P: Power
%       isRolling: the plane is in takeoff roll or landing roll
%  Ob: Observer location 
%  MOS: Method to obtain the slant 
%       'MLM' : Maximum level metrics (D=Ds always)
%       'EMT' : Exposure metrics takeoff (D can be Ds or Dp)
%       'EML' : Exposure metrics landing (D can be Ds or Dp)
% Output
%  An Gd struct with all these fields
%   D: Slant distance for obtaining the baseline noise level
%   Dp: Perpendicular distance between observer and extended segment
%   D1,D2: Distance to the points of the segment
%   q: distance from S1 to Sp (negative if the observer is behind the segment)
%   lambda: length of flight path segment
%   gamma: climb angle
%   beta: elevation angle 
%   l: lateral displacement
%   phi: depression angle
%   heading: angle direction to 0,0
%
%  ANCM: Aircraft Noise Countour Modelling Library.
%  2022 (c) Universidad Politécnica de Valencia

    % FIRST: BASIC GEOMETRIC PARAMETERS: section 4.4.1 

    % Distance to the points of the segment
    Gd.D1 = norm(Ob-Seg.S1);
    Gd.D2 = norm(Ob-Seg.S2);
    
    % Gd.lambda: length of flight path segment
    Gd.lambda = norm(Seg.S2-Seg.S1);

    % Slant distance or slant range (perpendicular distance from an observation
    % point to the flight path
    
    % Dp: Perpendicular distance between observer and extended segment
    a = Seg.S2 - Seg.S1;
    b = Seg.S2 - Ob;
    Gd.Dp = norm(cross(a,b)) / norm(a);
    
    % Sp: Point of the perpendicular closest approach to the observer on the
    % segment or its extension (that is, the project of point O on the
    % trajectory)
    b = Seg.S2 - Seg.S1;
    a = Ob - Seg.S1;
    ap = dot(a,b)/norm(b)*b/norm(b);
    Sp = Seg.S1+ap;
    
    % q: distance from S1 to Sp (negative if the observer is behind the
    % segment)
    Gd.q = dot(a,b)/norm(b);
    
    % Ds: Shortest distance between Observer and the segment
    if Gd.q < 0
        Ds = Gd.D1;
    elseif Gd.q > Gd.lambda
        Ds = Gd.D2;
    else
        Ds = Gd.Dp;
    end
    
    switch MOS
        case 'MLM'  % Maximum level metrics (D=Ds always)
           Gd.D= Ds; % Gd.Dp;
        case 'EMT'  % Exposure metrics takeoff 
            if Seg.isRolling && Gd.q < 0 
                %  behind the ground segments during the takeoff roll
               Gd.D = Ds;
            else
               Gd.D = Gd.Dp;
            end
        case 'EML' % Exposure metrics landing
            if Seg.isRolling && Gd.q > Gd.lambda 
                %  locations ahead of ground segments during the landing roll, 
               Gd.D = Ds;
            else
               Gd.D = Gd.Dp;
            end
        otherwise
            error('MOS option not valid');
    end
 
     
    % SECOND: AIRCRAFT-OBSERVER ANGLES : sections 4.5.2. and 4.5.5
    % FIGURES 4-3, 4-6 and 4.7

    % gamma: climb angle -> pitch (theta)
    a = Seg.S2-Seg.S1;
    b = [Seg.S2(1:2) Seg.S1(3)] - Seg.S1;
    Gd.gamma = acosd(dot(a,b)/(norm(a)*norm(b)));
    if Seg.S2(3) < Seg.S1(3) % Descending -> angle negative
        Gd.gamma = -1*Gd.gamma;
    end

    % get heading 
    if Seg.S1(1) == 0 && Seg.S1(2) == 0
        Gd.heading = 0;
    else
        a = Seg.S2(1:2) - Seg.S1(1:2);
        b = [0,0] - Seg.S1(1:2);
        Gd.heading = acosd(dot(a,b)/(norm(a)*norm(b)));
        left=((0 - Seg.S1(1))*(Seg.S2(2) - Seg.S1(2)) - (0 - Seg.S1(2))*(Seg.S2(1) - Seg.S1(1))) > 0;
        if left 
            Gd.heading = - Gd.heading;
        end
    end



    % R: minimun distance point perpendicular of the ground track from the
    % observer
    S = Sp;

%     C = euler2dcm(Gd.heading/180, Gd.theta/180, epsilon/180);
%     Z = (C*[0 0 1]')';
%     t = -S(3)/Z(3);
%     R = Z*t+S;
    R = [S(1:2) 0]; % The difference is too small.

    % l : lateral displacement
    Gd.l = norm(R-Ob);

    % beta : Elevation angle
    h = norm(S-R);
    z1 = Seg.S1(3); z2 = Seg.S2(3);


    if Gd.q < 0 % behind the segment
        Gd.beta = atand(z1/Gd.l);
    elseif Gd.q > Gd.lambda % ahead the segment
        Gd.beta = atand(z2/Gd.l);
    else
        Gd.beta = atand(h/Gd.l);
    end

    switch MOS
        case 'MLM'  % Maximum level metrics 
            if Gd.q < 0 % behind the segment
                Gd.beta = asind(z1/Gd.D1); 
                Gd.l = sqrt(Gd.D1^2-z1^2);
            end
        case 'EMT'  % Exposure metrics takeoff 
            if Seg.isRolling && Gd.q < 0 
                %  behind the ground segments during the takeoff roll
               Gd.beta = asind(z1/Gd.D1);
               Gd.l = sqrt(Gd.D1^2-z1^2);
            end
        case 'EML' % Exposure metrics landing
            if Seg.isRolling && Gd.q > Gd.lambda 
                %  locations ahead of ground segments during the landing roll, 
               Gd.beta = asind(z2/Gd.D2);
               Gd.l = sqrt(Gd.D2^2-z2^2);
            end
        otherwise
            error('MOS option not valid');
    end

    % phi: depression angle
    if Gd.q < 0 || Gd.q > Gd.lambda % out of the segment
        betap = atand(Sp(3)/Gd.l);
        Gd.phi = betap - Seg.epsilon;
    else
        Gd.phi = Gd.beta-Seg.epsilon;
    end
    Gd.phi = max(0,Gd.phi);

end

