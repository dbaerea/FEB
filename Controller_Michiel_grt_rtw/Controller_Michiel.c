/*
 * Controller_Michiel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Controller_Michiel".
 *
 * Model version              : 1.75
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Mar 31 21:07:57 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller_Michiel.h"
#include "Controller_Michiel_private.h"

/* Block signals (auto storage) */
B_Controller_Michiel_T Controller_Michiel_B;

/* Continuous states */
X_Controller_Michiel_T Controller_Michiel_X;

/* Block states (auto storage) */
DW_Controller_Michiel_T Controller_Michiel_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Controller_Michiel_T Controller_Michiel_U;

/* Real-time model */
RT_MODEL_Controller_Michiel_T Controller_Michiel_M_;
RT_MODEL_Controller_Michiel_T *const Controller_Michiel_M =
  &Controller_Michiel_M_;

/* Forward declaration for local functions */
static void Controller_Michiel_sqrt(creal_T *x);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Controller_Michiel_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  Controller_Michiel_step();
  Controller_Michiel_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  Controller_Michiel_step();
  Controller_Michiel_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  Controller_Michiel_step();
  Controller_Michiel_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/Slip-controle ' */
static void Controller_Michiel_sqrt(creal_T *x)
{
  real_T absxr;
  real_T absxi;
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      absxr = 0.0;
      absxi = sqrt(fabs(x->re));
    } else {
      absxr = sqrt(x->re);
      absxi = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      absxr = sqrt(-x->im / 2.0);
      absxi = -absxr;
    } else {
      absxr = sqrt(x->im / 2.0);
      absxi = absxr;
    }
  } else if (rtIsNaN(x->re) || rtIsNaN(x->im)) {
    absxr = (rtNaN);
    absxi = (rtNaN);
  } else if (rtIsInf(x->im)) {
    absxr = (rtInf);
    absxi = x->im;
  } else if (rtIsInf(x->re)) {
    if (x->re < 0.0) {
      absxr = 0.0;
      absxi = (rtInf);
    } else {
      absxr = (rtInf);
      absxi = 0.0;
    }
  } else {
    absxr = fabs(x->re);
    absxi = fabs(x->im);
    if ((absxr > 4.4942328371557893E+307) || (absxi > 4.4942328371557893E+307))
    {
      absxr *= 0.5;
      absxi *= 0.5;
      absxi = rt_hypotd_snf(absxr, absxi);
      if (absxi > absxr) {
        absxr = sqrt(absxr / absxi + 1.0) * sqrt(absxi);
      } else {
        absxr = sqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxr = sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
    }

    if (x->re > 0.0) {
      absxi = x->im / absxr * 0.5;
    } else {
      if (x->im < 0.0) {
        absxi = -absxr;
      } else {
        absxi = absxr;
      }

      absxr = x->im / absxi * 0.5;
    }
  }

  x->re = absxr;
  x->im = absxi;
}

/* Model step function */
void Controller_Michiel_step(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T Vzwpacc;
  real_T V_FL;
  real_T LR;
  real_T Wab_rl;
  real_T Wrl;
  creal_T b;
  real_T rtb_Sum;
  if (rtmIsMajorTimeStep(Controller_Michiel_M)) {
    /* set solver stop time */
    if (!(Controller_Michiel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Controller_Michiel_M->solverInfo,
                            ((Controller_Michiel_M->Timing.clockTickH0 + 1) *
        Controller_Michiel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Controller_Michiel_M->solverInfo,
                            ((Controller_Michiel_M->Timing.clockTick0 + 1) *
        Controller_Michiel_M->Timing.stepSize0 +
        Controller_Michiel_M->Timing.clockTickH0 *
        Controller_Michiel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Controller_Michiel_M)) {
    Controller_Michiel_M->Timing.t[0] = rtsiGetT
      (&Controller_Michiel_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Controller_Michiel_M->Timing.t[0];

  /* MATLAB Function: '<Root>/Inputs' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/Constant13'
   *  Constant: '<Root>/Constant14'
   *  Constant: '<Root>/Constant15'
   *  Constant: '<Root>/Constant16'
   */
  /* MATLAB Function 'Inputs': '<S2>:1' */
  /*  hier zullen de inputs verwerkt worden die nodig zijn voor de  */
  /*  aansturing van het controle algortihme. */
  /*  */
  /*  YRS is de versnelling die gemeten word door de yaw-rate sensor */
  /*  V_ang is de hoeksnelheid        */
  /*  V_acc is de hoekversnelling */
  /* '<S2>:1:9' */
  /* '<S2>:1:10' */
  /* YRS_X = 2; */
  /* YRS_Y = 2; */
  /* V_acc = 1; */
  /* V_ang = 1; */
  /* '<S2>:1:15' */
  /* '<S2>:1:16' */
  /* '<S2>:1:17' */
  /* '<S2>:1:18' */
  /*  berekening van de versnelling van het zwaartepunt in de x-richting */
  /* '<S2>:1:22' */
  rtb_Sum = (Controller_Michiel_P.Constant13_Value * 0.1 +
             Controller_Michiel_P.Constant_Value) +
    Controller_Michiel_P.Constant12_Value * 0.0 *
    Controller_Michiel_P.Constant12_Value;

  /*  versnelling in de y-richting */
  /* '<S2>:1:25' */
  Wrl = (Controller_Michiel_P.Constant13_Value * 0.0 +
         Controller_Michiel_P.Constant16_Value) +
    Controller_Michiel_P.Constant12_Value * 0.1 *
    Controller_Michiel_P.Constant12_Value;

  /*  Totale versnelling van het zwaartepunt */
  /* '<S2>:1:28' */
  /*  De snelheid van het zwaartepunt */
  /* '<S2>:1:35' */
  Vzwpacc = sqrt(rtb_Sum * rtb_Sum + Wrl * Wrl) * rtb_Clock;

  /*  C is de beginsnelheid */
  /*  De snelheid op bassis van de wielspeed sensoren  */
  /*  V_FL is de snelheid van het linker voorwiel, WS_FL is de hoeksnelheid van */
  /*  dit wiel en R3 is de banden straal */
  /* '<S2>:1:42' */
  V_FL = Controller_Michiel_P.Constant15_Value * 0.2325;

  /* '<S2>:1:43' */
  V_FL = (V_FL * cos(Controller_Michiel_P.Constant14_Value) + V_FL * sin
          (Controller_Michiel_P.Constant14_Value)) +
    Controller_Michiel_P.Constant12_Value * 0.05;

  /*  vergelijken van deze twee snelheden */
  if ((V_FL - Vzwpacc > -0.05) && (V_FL - Vzwpacc < 0.05)) {
    /* '<S2>:1:47' */
    /* '<S2>:1:48' */
    Controller_Michiel_B.Vzwp = V_FL;

    /*  wagen slipt niet */
  } else {
    /* '<S2>:1:50' */
    Controller_Michiel_B.Vzwp = Vzwpacc;

    /*  wagen slipt               */
  }

  /* '<S2>:1:54' */
  Controller_Michiel_B.a_zwpx = rtb_Sum;
  Controller_Michiel_B.a_zwpy = Wrl;

  /* End of MATLAB Function: '<Root>/Inputs' */

  /* MATLAB Function: '<Root>/Pre-processor' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   *  Constant: '<Root>/Constant9'
   */
  /* MATLAB Function 'Pre-processor': '<S4>:1' */
  /* De pre-processor berekend de gewenste yaw rate door het minimum te nemen */
  /* van de ideale en de maximale yaw rate waarde. */
  /* '<S4>:1:8' */
  /* '<S4>:1:9' */
  /* Vzwp    =0;                  */
  /* mu_max  =0.9; */
  /* Berekening massa's */
  /* Berekening Cornering stiffness */
  /* '<S4>:1:48' */
  /* '<S4>:1:49' */
  /* '<S4>:1:50' */
  /* '<S4>:1:51' */
  /* Gemiddelde van de cornering stiffness vooraan en achteraan nemen */
  /* '<S4>:1:54' */
  /* '<S4>:1:55' */
  /* Berekening van de onderstuur factor. */
  /* '<S4>:1:58' */
  /* Berekening van de ideale yaw rate. */
  /* '<S4>:1:61' */
  /*  berekening van de sliphoek beita */
  /* Berekening van de maximale yaw rate. */
  /* Minimale yaw rate. */
  /* '<S4>:1:72' */
  /* '<S4>:1:73' */
  Controller_Michiel_B.Yaw_ref = Controller_Michiel_B.Vzwp *
    Controller_Michiel_P.Constant1_Value / ((129.45901639344262 /
    ((Controller_Michiel_P.Constant10_Value /
      Controller_Michiel_P.Constant6_Value +
      Controller_Michiel_P.Constant9_Value /
      Controller_Michiel_P.Constant5_Value) / 2.0) - 135.5409836065574 /
    ((Controller_Michiel_P.Constant8_Value /
      Controller_Michiel_P.Constant11_Value +
      Controller_Michiel_P.Constant7_Value /
      Controller_Michiel_P.Constant4_Value) / 2.0)) * (Controller_Michiel_B.Vzwp
    * Controller_Michiel_B.Vzwp) + 1.525);

  /* Sum: '<S1>/Sum' */
  rtb_Sum = Controller_Michiel_B.Yaw_ref;

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/Proportional Gain'
   *  Integrator: '<S6>/Integrator'
   *  Sum: '<S1>/Sum'
   */
  Controller_Michiel_B.Sum = Controller_Michiel_P.PIDController_P *
    Controller_Michiel_B.Yaw_ref + Controller_Michiel_X.Integrator_CSTATE;

  /* MATLAB Function: '<S3>/Slip-controle ' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  /* MATLAB Function 'Post-processor/Slip-controle ': '<S8>:1' */
  /*  Berekening van de maximale torques die men kan toepassen op de wielen */
  /*  door berekening van de normaalkrachten op de wielen. */
  /* load('parameters.mat'); */
  /* '<S8>:1:7' */
  /* '<S8>:1:15' */
  /* '<S8>:1:17' */
  /* '<S8>:1:21' */
  /* '<S8>:1:23' */
  /* '<S8>:1:25' */
  /* ax      =0;                  */
  /* ay      =0;                  */
  /* '<S8>:1:35' */
  /* Vzwp    =0;                  */
  /* mu_max  =0.9; */
  /* Wielbelastingen */
  /* Statische wielbelasting */
  /* '<S8>:1:48' */
  /* '<S8>:1:49' */
  /* '<S8>:1:52' */
  /* Laterale wielbelasting (door rollen van de wagen) */
  /* Kracht door rolmoment */
  /* '<S8>:1:56' */
  /* Kracht door afgeveerde massa */
  /* '<S8>:1:59' */
  /* Kracht door onafgeveerde massa */
  /* '<S8>:1:62' */
  /* Totale gewichtsverplaatsing */
  /* '<S8>:1:65' */
  /* Kracht per wiel */
  /* '<S8>:1:69' */
  Vzwpacc = ((3.859195E+6 * Controller_Michiel_B.a_zwpy * 0.2369 / 31320.171498
              + 1269.9929508196722 * Controller_Michiel_B.a_zwpy * 0.041 / 1.2)
             + 8.5 * Controller_Michiel_B.a_zwpy * 0.0 / 1.2) / 2.0;

  /* '<S8>:1:70' */
  /* Longitudinale wielbelasting */
  /* '<S8>:1:75' */
  V_FL = 23.763114754098364 * Controller_Michiel_B.a_zwpx;

  /* Aerodynamische wielbelasting */
  /* Nog na te kijken */
  /* '<S8>:1:80' */
  LR = Controller_Michiel_B.Vzwp * Controller_Michiel_B.Vzwp * -0.0237 + 0.0958 *
    Controller_Michiel_B.Vzwp;

  /* Nog na te kijken */
  /* +((Krf/(Krf+Krr))*(Rm/Tf));      %is er hier 2x rolmoment??? (zie lateraal) */
  /* -((Krf/(Krf+Krr))*(Rm/Tf)); */
  /* '<S8>:1:84' */
  /* +((Krr/(Krf+Krr))*(Rm/Tr)); */
  /* '<S8>:1:85' */
  /* -((Krr/(Krf+Krr))*(Rm/Tr)); */
  /* anti-roll bar wielbelasting */
  /* '<S8>:1:90' */
  Wab_rl = 325.31 * Vzwpacc / 325.31;

  /* '<S8>:1:91' */
  /* Totale belasting per wiel */
  /* Ongebruikt, kan later eventueel gebruikt worden voor 4WD */
  /* ^ Idem */
  /* '<S8>:1:96' */
  Wrl = (((634.99647540983608 + Vzwpacc) + V_FL) + -LR / 3.05) + Wab_rl;

  /* '<S8>:1:97' */
  Vzwpacc = (((634.99647540983608 + -Vzwpacc) + V_FL) + -LR / 3.05) + -Wab_rl;

  /* %Omrekening naar torques */
  /* Wrijvingscirkels */
  /* '<S8>:1:104' */
  /* '<S8>:1:105' */
  /* Maximum torques */
  /* '<S8>:1:108' */
  b.re = Wrl * Wrl * (Controller_Michiel_P.Constant2_Value *
                      Controller_Michiel_P.Constant2_Value) - Wrl * Wrl *
    (Controller_Michiel_B.a_zwpy * Controller_Michiel_B.a_zwpy);
  b.im = 0.0;
  Controller_Michiel_sqrt(&b);
  Wrl = b.re * 0.2325;
  V_FL = b.im * 0.2325;

  /* '<S8>:1:109' */
  b.re = Vzwpacc * Vzwpacc * (Controller_Michiel_P.Constant2_Value *
    Controller_Michiel_P.Constant2_Value) - Vzwpacc * Vzwpacc *
    (Controller_Michiel_B.a_zwpy * Controller_Michiel_B.a_zwpy);
  b.im = 0.0;
  Controller_Michiel_sqrt(&b);

  /* MATLAB Function: '<S3>/Lineaire programering' incorporates:
   *  Constant: '<Root>/Constant3'
   *  MATLAB Function: '<S3>/Slip-controle '
   */
  /* MATLAB Function 'Post-processor/Lineaire programering': '<S7>:1' */
  /* Deze blok staat in voor het berekenen van de te leveren torque per wiel */
  /* aan de hand van twee lineaire doelen. Het eerste doel is het netto moment */
  /* rond het zwaartepunt optimaliseren. Het tweede doel is de torque die wordt */
  /* overgedragen op het wegdek optimaliseren. */
  /* % */
  /* Vzwp    =0;                  */
  /* mu_max  =0.9; */
  /* coder.extrinsic('eval','num2str','linprog'); */
  /* % */
  /* voorbereidende berekeningen */
  /* % */
  /* Gevraagd Moment */
  /* Maken van variabelen */
  /* variables1 = {'Trr_1','Trl_1','e','maxi'}; */
  /* N = length(variables1);  */
  /*  create variables for indexing  */
  /* for v = 1:N  */
  /*    eval([variables1{v},' = ', num2str(v),';']);  */
  /* end */
  /* Ondergrenzen bepalen */
  /* lb = zeros(size(variables1)); */
  /* lb([1 2 3]) = [-40,-40,0]; */
  /* Bovengrenzen bepalen */
  /* ub = Inf(size(variables1)); */
  /* ub([1 2]) = [40,40]; */
  /* Ongelijkheden */
  /* A = zeros(2,4); b = zeros(1,4); */
  /* A(1,1) = 1; A(1,2) = 1; b(1) = Tmax; */
  /* A(2,4) = 1; b(2) = maximum1; */
  /* Gelijkheden */
  /* Aeq = zeros(1,4); beq = zeros(1,1); */
  /* Aeq(1,[1 2 3 4]) = [1,-1,1,-1]; */
  /* Te optimaliseren kostenfunctie */
  /* f = zeros(size(variables1)); */
  /* f([1 2 3]) = [-1 -1 -1]; */
  /* Optimalisatie */
  /* x = linprogram(f,A,b,Aeq,beq,lb,ub); */
  /* % */
  /* Gevraagde torque */
  /* '<S7>:1:101' */
  /* Maken van variabelen */
  /* variables2 = {'Trr_2','Trl_2','maxi'}; */
  /* N = length(variables2);  */
  /*  create variables for indexing  */
  /* for v = 1:N  */
  /*    eval([variables2{v},' = ', num2str(v),';']);  */
  /* end */
  /* Ondergrenzen bepalen */
  /* lb_2 = zeros(size(variables2)); */
  /* lb_2([1 2]) = [-40,-40]; */
  /* Bovengrenzen bepalen */
  /* ub_2 = Inf(size(variables2)); */
  /* ub_2([1 2]) = [40,40]; */
  /* Ongelijkheden */
  /* A_2 = zeros(2,3); b_2 = zeros(1,3); */
  /* A_2(1,1) = 1; A_2(1,2) = 1; b_2(1) = Tmax; */
  /* A_2(2,3) = 1; b_2(2) = maximum2; */
  /* Gelijkheden */
  /* Aeq_2 = zeros(1,3); beq_2 = zeros(1,1); */
  /* Aeq_2(1,[1 2 3]) = [1,-1,-1]; */
  /* Te optimaliseren kostenfunctie */
  /* f_2 = zeros(size(variables2)); */
  /* f_2([1 2]) = [-1 -1]; */
  /* Optimalisatie */
  /* x_2 = linprogram(f_2,A_2,b_2,Aeq_2,beq_2,lb_2,ub_2); */
  /* % */
  /* Effectieve torques naar motordrives */
  /* Trl_1 = x(2,1); */
  /* Trl_2 = x_2(2,1); */
  /* Trr_1 = x(1,1); */
  /* Trr_2 = x_2(1,1); */
  /* '<S7>:1:145' */
  Controller_Michiel_B.Trl.re = Controller_Michiel_P.Constant3_Value * Wrl;
  Controller_Michiel_B.Trl.im = Controller_Michiel_P.Constant3_Value * V_FL;

  /* Trl_1*Cte + Trl_2*(1-Cte); */
  /* '<S7>:1:146' */
  Controller_Michiel_B.Trr.re = 0.2325 * b.re *
    Controller_Michiel_P.Constant3_Value;
  Controller_Michiel_B.Trr.im = 0.2325 * b.im *
    Controller_Michiel_P.Constant3_Value;

  /* Trr_1*Cte + Trr_2*(1-Cte); */
  /* '<S7>:1:149' */
  Controller_Michiel_B.Mz_sat = 10.0;
  if (rtmIsMajorTimeStep(Controller_Michiel_M)) {
  }

  /* Gain: '<S6>/Integral Gain' */
  Controller_Michiel_B.IntegralGain = Controller_Michiel_P.PIDController_I *
    rtb_Sum;
  if (rtmIsMajorTimeStep(Controller_Michiel_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Controller_Michiel_M->rtwLogInfo,
                        (Controller_Michiel_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Controller_Michiel_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Controller_Michiel_M)!=-1) &&
          !((rtmGetTFinal(Controller_Michiel_M)-
             (((Controller_Michiel_M->Timing.clockTick1+
                Controller_Michiel_M->Timing.clockTickH1* 4294967296.0)) * 0.001))
            > (((Controller_Michiel_M->Timing.clockTick1+
                 Controller_Michiel_M->Timing.clockTickH1* 4294967296.0)) *
               0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Controller_Michiel_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Controller_Michiel_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Controller_Michiel_M->Timing.clockTick0)) {
      ++Controller_Michiel_M->Timing.clockTickH0;
    }

    Controller_Michiel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Controller_Michiel_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Controller_Michiel_M->Timing.clockTick1++;
      if (!Controller_Michiel_M->Timing.clockTick1) {
        Controller_Michiel_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Controller_Michiel_derivatives(void)
{
  XDot_Controller_Michiel_T *_rtXdot;
  _rtXdot = ((XDot_Controller_Michiel_T *)
             Controller_Michiel_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = Controller_Michiel_B.IntegralGain;
}

/* Model initialize function */
void Controller_Michiel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Controller_Michiel_M, 0,
                sizeof(RT_MODEL_Controller_Michiel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Controller_Michiel_M->solverInfo,
                          &Controller_Michiel_M->Timing.simTimeStep);
    rtsiSetTPtr(&Controller_Michiel_M->solverInfo, &rtmGetTPtr
                (Controller_Michiel_M));
    rtsiSetStepSizePtr(&Controller_Michiel_M->solverInfo,
                       &Controller_Michiel_M->Timing.stepSize0);
    rtsiSetdXPtr(&Controller_Michiel_M->solverInfo,
                 &Controller_Michiel_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Controller_Michiel_M->solverInfo, (real_T **)
                         &Controller_Michiel_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Controller_Michiel_M->solverInfo,
      &Controller_Michiel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Controller_Michiel_M->solverInfo,
      &Controller_Michiel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Controller_Michiel_M->solverInfo,
      &Controller_Michiel_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Controller_Michiel_M->solverInfo,
      &Controller_Michiel_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Controller_Michiel_M->solverInfo, (&rtmGetErrorStatus
      (Controller_Michiel_M)));
    rtsiSetRTModelPtr(&Controller_Michiel_M->solverInfo, Controller_Michiel_M);
  }

  rtsiSetSimTimeStep(&Controller_Michiel_M->solverInfo, MAJOR_TIME_STEP);
  Controller_Michiel_M->ModelData.intgData.y =
    Controller_Michiel_M->ModelData.odeY;
  Controller_Michiel_M->ModelData.intgData.f[0] =
    Controller_Michiel_M->ModelData.odeF[0];
  Controller_Michiel_M->ModelData.intgData.f[1] =
    Controller_Michiel_M->ModelData.odeF[1];
  Controller_Michiel_M->ModelData.intgData.f[2] =
    Controller_Michiel_M->ModelData.odeF[2];
  Controller_Michiel_M->ModelData.intgData.f[3] =
    Controller_Michiel_M->ModelData.odeF[3];
  Controller_Michiel_M->ModelData.contStates = ((X_Controller_Michiel_T *)
    &Controller_Michiel_X);
  rtsiSetSolverData(&Controller_Michiel_M->solverInfo, (void *)
                    &Controller_Michiel_M->ModelData.intgData);
  rtsiSetSolverName(&Controller_Michiel_M->solverInfo,"ode4");
  rtmSetTPtr(Controller_Michiel_M, &Controller_Michiel_M->Timing.tArray[0]);
  rtmSetTFinal(Controller_Michiel_M, 2.0);
  Controller_Michiel_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Controller_Michiel_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Controller_Michiel_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Controller_Michiel_M->rtwLogInfo, (NULL));
    rtliSetLogT(Controller_Michiel_M->rtwLogInfo, "tout");
    rtliSetLogX(Controller_Michiel_M->rtwLogInfo, "");
    rtliSetLogXFinal(Controller_Michiel_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Controller_Michiel_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Controller_Michiel_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Controller_Michiel_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Controller_Michiel_M->rtwLogInfo, 1);
    rtliSetLogY(Controller_Michiel_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Controller_Michiel_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Controller_Michiel_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Controller_Michiel_B), 0,
                sizeof(B_Controller_Michiel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Controller_Michiel_X, 0,
                  sizeof(X_Controller_Michiel_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Controller_Michiel_DW, 0,
                sizeof(DW_Controller_Michiel_T));

  /* external inputs */
  (void) memset((void *)&Controller_Michiel_U, 0,
                sizeof(ExtU_Controller_Michiel_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Controller_Michiel_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Controller_Michiel_M), Controller_Michiel_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Controller_Michiel_M)));

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  Controller_Michiel_X.Integrator_CSTATE = Controller_Michiel_P.Integrator_IC;
}

/* Model terminate function */
void Controller_Michiel_terminate(void)
{
  /* (no terminate code required) */
}
