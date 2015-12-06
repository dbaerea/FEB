function [Trl_max,Trr_max,Wfl,Wfr,Wrl,Wrr] = Test(~,~,~)
% Berekening van de maximale torques die men kan toepassen op de wielen
% door berekening van de normaalkrachten op de wielen.

% Parameters
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
Rm      =576.35;            %Rolmoment
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
Vzwp    =40;                %constante snelheid voor testen code


%Wielbelastingen

%Statische wielbelasting
Ws_fl = (Lr/(2*(L)))*M*g;
Ws_fr = Ws_fl;
Ws_rl = (Lf/(2*L))*M*g;
Ws_rr = Ws_rl;

Ms_f = (Ws_fl + Ws_fr)/g - Mu_f;                       %Afgeveerde massa op vooras
Ms_r = (Ws_rl + Ws_rr)/g - Mu_r;                       %Afgeveerde massa op achteras


%Laterale wielbelasting (door rollen van de wagen)
FfsM = ((Ksf*M*ay*D)/(Tf*((Ksf+Ksr)-(M*g*D))));    %Kracht door rolmoment
FrsM = ((Ksr*M*ay*D)/(Tr*((Ksf+Ksr)-(M*g*D))));

FfsF = (Ms_f*ay*Hrcf)/Tf;                   %Kracht door afgeveerde massa
FrsF = (Ms_r*ay*Hrcr)/Tr;

FfuF = (Mu_f*ay*Hurcf)/Tf;                  %Kracht door onafgeveerde massa
FruF = (Mu_r*ay*Hurcr)/Tr;

Ff = FfsM + FfsF + FfuF;                    %Totale gewichtsverplaatsing
Fr = FrsM + FrsF + FruF;

Wy_fl = Ff/2;                               %Kracht per wiel
Wy_fr = -Wy_fl;
Wy_rl = Fr/2;
Wy_rr = -Wy_rl;

%Longitudinale wielbelasting
Wx_fl = (-H/(2*L))*M*ax;
Wx_fr = Wx_fl;
Wx_rl = (H/(2*L))*M*ax;
Wx_rr = Wx_rl;

%Aerodynamische wielbelasting
LF = -0.0237*(Vzwp)^2 + 0.0958*Vzwp;
LR = -0.0237*(Vzwp)^2 + 0.0958*Vzwp;

Wa_fl = (-LF/(2))  %+((Ksf/(Ksf+Ksr))*(Rm/Tf));
Wa_fr = (-LF/(2))  %-((Ksf/(Ksf+Ksr))*(Rm/Tf));
Wa_rl = (-LR/(2))  %+((Ksr/(Ksf+Ksr))*(Rm/Tr));
Wa_rr = (-LR/(2))  %-((Ksr/(Ksf+Ksr))*(Rm/Tr));

%anti-roll bar wielbelasting
Wab_fl = (Krf_a/((Krf_a+((Kwf*(Tf)^2)/2)))*Wy_fl);
Wab_fr = -Wab_fl;
Wab_rl = (Krr_a/((Krr_a+((Kwr*(Tr)^2)/2)))*Wy_rl);
Wab_rr = -Wab_rl;

%Totale belasting per wiel
Wfl = Ws_fl + Wy_fl + Wx_fl + Wa_fl + Wab_fl;   %Ongebruikt, kan later gebruikt worden voor 4WD
Wfr = Ws_fr + Wy_fr + Wx_fr + Wa_fr + Wab_fr;   %^ Idem
Wrl = Ws_rl + Wy_rl + Wx_rl + Wa_rl + Wab_rl;
Wrr = Ws_rr + Wy_rr + Wx_rr + Wa_rr + Wab_rr;



%Omrekening naar torques

%Wrijvingscirkels
%Fx_rl = sqrt((Wrl^2*mu_max^2)-(Wrl^2*ay^2));
%Fx_rr = sqrt((Wrr^2*mu_max^2)-(Wrr^2*ay^2));

%Maximum torques
%Trl_max = Fx_rl*Reff_r;
%Trr_max = Fx_rr*Reff_r;