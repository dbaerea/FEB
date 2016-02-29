%%understeer_vehicle
clc
clear all
close all

Lr=1.5834;      %from Cr to G [m]
Lf=1.0766;      %from G to Cf [m]
m=2068;         %mass [kg]
Th=3231;        %yaw inertia [kgm^2]
Car=60000;      %rear tire cornering stiffness [N/rad]
Caf=70000;      %front tire cornering stiffness [N/rad]
v = 10;     %Speed [m/s]



a11 = (-1/v)*((Caf*Lf^2+Car*Lr^2)/Th);
a12 = -((Caf*Lf-Car*Lr)/Th);
a21 = (-1-((1/v^2)*((Caf*Lf-Car*Lr)/m)));
a22 = (-1/v)*((Caf+Car)/m);


% b1 = (Caf*Lf)/Th;
% b2 = (1/v)*(Caf/m);

b2 = 0;
b1 = 1/Th;

open Single_track.mdl

%%%EOF%%%