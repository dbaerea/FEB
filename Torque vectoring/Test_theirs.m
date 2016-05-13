function [Trl_max,Trr_max,Wfl,Wfr,Wrl,Wrr] = Test(~,~,~)
% Berekening van de maximale torques die men kan toepassen op de wielen
% door berekening van de normaalkrachten op de wielen.

% Parameters
M       =265;
L       =1525;
Lf      =780;
Lr      =745;
Tf      =1200;
Tr      =1200;
g       =9.81;
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
Reff_r	=0;
Gr      =10.32;
Sr      =600;
Tmax	=38.5;
Cte     =0;
ax      =0;
ay      =0;
Mu_f    =17;
Mu_r    =17;

%Wielbelastingen

%Statische wielbelasting
Ws_fl = (Lr/(2*(L)))*M*g;
Ws_fr = Ws_fl;
Ws_rl = (Lf/(2*L))*M*g;
Ws_rr = Ws_rl;

Ms_f = (Ws_fl + Ws_fr)/g;                       %Afgeveerde massa op vooras
Ms_r = (Ws_rl + Ws_rr)/g;                       %Afgeveerde massa op achteras


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
Wa_fl = (-LF/(2*L))+((Ksf/(Ksf+Ksr))*(Rm/Tf));
Wa_fr = (-LF/(2*L))-((Ksf/(Ksf+Ksr))*(Rm/Tf));
Wa_rl = (-LR/(2*L))+((Ksr/(Ksf+Ksr))*(Rm/Tr));
Wa_rr = (-LR/(2*L))-((Ksr/(Ksf+Ksr))*(Rm/Tr));

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