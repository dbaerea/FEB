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

M       =265;               %Massa wagen + driver
L       =1.525;             %Totale lengte tussen beide assen
Lf      =0.780;             %Lengte ZWP tot vooras
Lr      =0.745;             %Lengte ZWP tot achteras
Tf      =1.200;             %Trackbreedte vooraan
Tr      =1.200;             %Trackbreedte achteraan
g       =9.81;              %Valversnelling
Ksf     =12153;             %Veerstijfheid vooraan
Ksr     =14563;             %Veerstijfheid achteraan
Krf_a	=183.26;            %Stijfheid anti-rollbar vooraan
Krr_a	=325.31;            %Stijfheid anti-rollbar achteraan
Kwf     =0;                 %
Kwr     =0;                 %
Hrcf	=0.032;             %Hoogte rolcentrum vooraan
Hrcr	=0.041;             %Hoogte rolcentrum achteraan
Hurcf	=0;                 %Hoogte onafgeveerde massa vooraan
Hurcr	=0;                 %Hoogte onafgeveerde massa achteraan
H       =0.2735;            %Hoogte ZWP
D       =0.2369;            %Afstand ZWP tot rol-as
Rm      =0;                 %Rolmoment
Reff	=0;                 %Bandenstraal
Gr      =10.32;             %Overbrengingsverhouding gearbox
Sr      =0.600;             %Halve trackbreedte
Tmax	=38.5;              %Maximumkoppel per motor
Cte     =0;                 %Constante voor verhouding Lineaire programmatiemethoden
ax      =0;                 %constante versnelling voor testen code
ay      =0;                 %constante versnelling voor testen code
Mu_f    =8.5;               %Onafgeveerde massa vooraan
Mu_r    =8.5;               %Onafgeveerde massa achteraan
R1      =0;                 %Afstand van zwaartepunt naar yaw-rate in de x-richting 
R2      =0;                 %Afstand van zwaartepunt naar yaw-rate in de y-richting
R4_x    =0;                 %De afstand van het linkervoorwiel tot het zwaartepunt in de x-richting
R4_y    =0;                 %De afstand van het linkervoorwiel tot het zwaartepunt in de y-richting