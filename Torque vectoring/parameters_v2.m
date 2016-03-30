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

%Car Parameters
par.car.mass        =265;               %Massa wagen + driver
par.car.length      =1.525;             %Totale lengte tussen beide assen
par.car.Lf          =0.780;             %Lengte ZWP tot vooras
par.car.Lr          =0.745;             %Lengte ZWP tot achteras
par.car.Tf          =1.200;             %Trackbreedte vooraan
par.car.Tr          =1.200;             %Trackbreedte achteraan
par.car.Hrcf        =0.032;             %Hoogte rolcentrum vooraan
par.car.Hrcr        =0.041;             %Hoogte rolcentrum achteraan
par.car.Hurcf       =0;                 %Hoogte onafgeveerde massa vooraan
par.car.Hurcr       =0;                 %Hoogte onafgeveerde massa achteraan
par.car.H           =0.2735;            %Hoogte ZWP
par.car.D           =0.2369;            %Afstand ZWP tot rol-as
par.car.Sr          =0.600;             %Halve trackbreedte
par.car.Mu_f        =8.5;               %Onafgeveerde massa vooraan
par.car.Mu_r        =8.5;               %Onafgeveerde massa achteraan

par.car.R1          =0;                 %Afstand van zwaartepunt naar yaw-rate in de x-richting 
par.car.R2          =0;                 %Afstand van zwaartepunt naar yaw-rate in de y-richting
par.car.R4_x        =0;                 %De afstand van het linkervoorwiel tot het zwaartepunt in de x-richting
par.car.R4_y        =0;                 %De afstand van het linkervoorwiel tot het zwaartepunt in de y-richting

%Constant parameters
par.cte.g           =9.81;              %Valversnelling
par.cte.Cte         =0;                 %Constante voor verhouding Lineaire programmatiemethoden
par.cte.Rm      =0;                 %Rolmoment

%Suspension parameters
par.sus.Ksf         =12153;             %Veerstijfheid vooraan
par.sus.Ksr         =14563;             %Veerstijfheid achteraan
par.sus.Krf_a       =183.26;            %Stijfheid anti-rollbar vooraan
par.sus.Krr_a       =325.31;            %Stijfheid anti-rollbar achteraan

%Tire parameters
par.tire.Kwf        =0;                 %Stijfheid banden vooraan     /formule uit excel sheet halen
par.tire.Kwr        =0;                 %Stijfheid banden achteraan   /formule uit excel sheet halen
par.tire.Reff       =0;                 %Bandenstraal

%Powertrain parameters
par.pwr.Gr          =10.32;             %Overbrengingsverhouding gearbox
par.pwr.Tmax        =38.5;              %Maximumkoppel per motor

%Test parameters
par.test.ax         =0;                 %constante versnelling voor testen code
par.test.ay         =0;                 %constante versnelling voor testen code



