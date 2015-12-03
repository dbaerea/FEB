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
L       =1525;              %Totale lengte tussen beide assen
Lf      =780;               %Lengte ZWP tot vooras
Lr      =745;               %Lengte ZWP tot achteras
Tf      =1200;              %Trackbreedte vooraan
Tr      =1200;              %Trackbreedte achteraan
g       =9.81;              %Valversnelling
Ksf     =12153;             %Veerstijfheid vooraan
Ksr     =14563;             %Veerstijfheid achteraan
Krf_a	=183.26;            %Stijfheid anti-rollbar vooraan
Krr_a	=325.31;            %Stijfheid anti-rollbar achteraan
Kwf     =0;                 %
Kwr     =0;                 %
Hrcf	=32;                %Hoogte rolcentrum vooraan
Hrcr	=41;                %Hoogte rolcentrum achteraan
Hurcf	=0;                 %Hoogte onafgeveerde massa vooraan
Hurcr	=0;                 %Hoogte onafgeveerde massa achteraan
H       =273.5;             %Hoogte ZWP
D       =0;                 %Afstand ZWP tot rol-as
Rm      =0;                 %Rolmoment
Reff	=0;                 %Bandenstraal
Gr      =10.32;             %Overbrengingsverhouding gearbox
Sr      =600;               %Halve trackbreedte
Tmax	=38.5;              %Maximumkoppel per motor
Cte     =0;                 %Constante voor verhouding Lineaire programmatiemethoden
R1      = 0;                %Afstand van zwaartepunt naar yaw-rate in de x-richting 
R2      = 0;                %Afstand van zwaartepunt naar yaw-rate in de y-richting
R4_x      = 0;              %De afstand van het linkervoorwiel tot het zwaartepunt in de x-richting
R4_y     = 0;               %De afstand van het linkervoorwiel tot het zwaartepunt in de y-richting