% This script defines a project shortcut. 
%
% To get a handle to the current project use the following function:
%
% project = simulinkproject();
%
% You can use the fields of project to get information about the currently 
% loaded project. 
%
% See: help simulinkproject

M       =265;            % massa wagen 
L       =1525;           % Lengte wagen
Lf      =780;            % Lengte vooras tot zwaartepunt
Lr      =745;            % Lengte achteras tot zwaartepunt
Tf      =1200;
Tr      =1200;
g       =9.81;           % Valversnelling
Ksf     =12153;
Ksr     =14563;
Krf_a	=183.26;
Krr_a	=325.31;
Kwf     =0;
Kwr     =0;
Hrcf	=32;
Hrcr	=41;
Hurcf	=0;
Hurcr	=0;
H       =273.5;
D       =0;
LF      =-150;
LR      =110;
Rm      =0;
Reff	=0;                  %Bandenstraal
Gr      =10.32;
Sr      =600;
Tmax	=38.5;
Cte     =0;
R1      = 0;                % afstand van zwaartepunt naar yaw-rate in de x-richting 
R2      = 0;                 % afstand van zwaartepunt naar yaw-rate in de y-richting
R4_x      = 0;                % de afstand van het linkervoorwiel tot het zwaartepunt in de x-richting
R4_y     = 0;                % de afstand van het linkervoorwiel tot het zwaartepunt in de y-richting