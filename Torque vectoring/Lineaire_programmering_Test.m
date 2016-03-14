%Deze blok staat in voor het berekenen van de te leveren torque per wiel
%aan de hand van twee lineaire doelen. Het eerste doel is het netto moment
%rond het zwaartepunt optimaliseren. Het tweede doel is de torque die wordt
%overgedragen op het wegdek optimaliseren.

%%
M       =265;               
L       =1.525;             
Lf      =0.780;             
Lr      =0.745;             
Tf      =1.200;             
Tr      =1.200;             
g       =9.81;              
Ksf     =12153;             
Ksr     =14563;             
Krf_a	=183.26;            
Krr_a	=325.31;            
Kwf     =0;                 
Kwr     =0;                 
Hrcf	=0.032;             
Hrcr	=0.041;             
Hurcf	=0;                 
Hurcr	=0;                 
H       =0.2735;            
D       =0.2369;            
Rm      =576.35;            
Reff	=0.2325;            
Gr      =10.32;             
Sr      =0.600;             
Tmax	=77;              
Cte     =0;                 
ax      =0;                 
ay      =0;                 
Mu_f    =8.5;               
Mu_r    =8.5;               
R1      =0;                 
R2      =0;                 
R4_x    =0;                 
R4_y    =0;                 
Vzwp    =0;                 
mu_max  =0.9;
Pmax    =150000; 


coder.extrinsic('num2str');

%%
%Inputs
Trl_max = 40;
Trr_max = 40;
Vzwp    = 50;
Mz      = 10;
Pedal   = 10;
Omega_rl= 1500;
Omega_rr= 1500;
Ttot    = 0;

%%
%voorbereidende berekeningen
Omega = abs((Omega_rl + Omega_rr) / 2);

Tmax = min(Tmax,(Pmax/Omega)) ;

TV_control = (Mz*Reff)/(2*Sr*Gr) ;

%%
%Gevraagd Moment
TV_max_1 = min(40,((Trl_max+Trr_max)/2));

maximum1 = 2*max(-TV_max_1,min(TV_max_1,TV_control));

%Maken van variabelen
variables1 = {'Trr_1','Trl_1','e','maxi'};
N = length(variables1); 
% create variables for indexing 
for v = 1:N 
   eval([variables1{v},' = ', num2str(v),';']); 
end

%Ondergrenzen bepalen
lb = zeros(size(variables1));
lb([1 2 3]) = [-40,-40,0];

%Bovengrenzen bepalen
ub = Inf(size(variables1));
ub([1 2]) = [40,40];

%Ongelijkheden
A = zeros(2,4);
A(1,1) = 1; A(1,2) = 1; b(1) = Tmax;
A(2,4) = 1; b(2) = maximum1;

%Gelijkheden
Aeq = zeros(1,4); beq = zeros(1,1);
Aeq(1,[Trr_1,Trl_1,e,maxi]) = [1,-1,1,-1];

%Te optimaliseren kostenfunctie
f = zeros(size(variables1));
f([Trr_1 Trl_1 e]) = [-1 -1 0];

%Optimalisatie
x = linprog(f,A,b,Aeq,beq,lb,ub);
for i = 1:N
  fprintf('%12.2f \t%s\n',x(i),variables1{i}) 
end
fval


%%
%Gevraagde torque
mini = [40 (Trl_max-(Ttot/2)) (Trr_max+(Ttot/2))];
TV_max_2 = max(0,min(mini));
maximum2 = 2*max(-TV_max_2,min(TV_max_2,TV_control));

%Maken van variabelen
variables2 = {'Trr_2','Trl_2','maxi'};
N = length(variables2); 
% create variables for indexing 
for v = 1:N 
   eval([variables2{v},' = ', num2str(v),';']); 
end

%Ondergrenzen bepalen
lb_2 = zeros(size(variables2));
lb_2([Trr_1,Trl_1]) = [-40,-40];

%Bovengrenzen bepalen
ub_2 = Inf(size(variables2));
ub_2([Trr_1,Trl_1]) = [40,40];

%Ongelijkheden
A_2 = zeros(2,3);
A_2(1,Trr_2) = 1; A_2(1,Trl_2) = 1; b_2(1) = Tmax;
A_2(2,maxi) = 1; b_2(2) = maximum2;

%Gelijkheden
Aeq_2 = zeros(1,3); beq_2 = zeros(1,1);
Aeq_2(1,[Trr_2,Trl_2,maxi]) = [1,-1,-1];

%Te optimaliseren kostenfunctie
f_2 = zeros(size(variables2));
f_2([Trr_1 Trl_1]) = [-1 -1];

%Optimalisatie
[x_2 fval_2] = linprog(f_2,A_2,b_2,Aeq_2,beq_2,lb_2,ub_2);
for i = 1:N
  fprintf('%12.2f \t%s\n',x_2(i),variables2{i}) 
end
fval_2


%%
%Effectieve torques naar motordrives
Trl_1 = x(2,1)
Trl_2 = x_2(2,1)
Trr_1 = x(1,1)
Trr_2 = x_2(1,1)

Trl = Trl_1*Cte + Trl_2*(1-Cte)
Trr = Trr_1*Cte + Trr_2*(1-Cte)