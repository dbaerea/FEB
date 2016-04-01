/*
 * Controller_Michiel.h
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

#ifndef RTW_HEADER_Controller_Michiel_h_
#define RTW_HEADER_Controller_Michiel_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Controller_Michiel_COMMON_INCLUDES_
# define Controller_Michiel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Controller_Michiel_COMMON_INCLUDES_ */

#include "Controller_Michiel_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  creal_T Trl;                         /* '<S3>/Lineaire programering' */
  creal_T Trr;                         /* '<S3>/Lineaire programering' */
  real_T Sum;                          /* '<S6>/Sum' */
  real_T IntegralGain;                 /* '<S6>/Integral Gain' */
  real_T Yaw_ref;                      /* '<Root>/Pre-processor' */
  real_T Mz_sat;                       /* '<S3>/Lineaire programering' */
  real_T a_zwpx;                       /* '<Root>/Inputs' */
  real_T a_zwpy;                       /* '<Root>/Inputs' */
  real_T Vzwp;                         /* '<Root>/Inputs' */
} B_Controller_Michiel_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[10];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_Controller_Michiel_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
} X_Controller_Michiel_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
} XDot_Controller_Michiel_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S6>/Integrator' */
} XDis_Controller_Michiel_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In3;                          /* '<Root>/In3' */
  real_T In6;                          /* '<Root>/In6' */
  real_T In7;                          /* '<Root>/In7' */
  real_T In8;                          /* '<Root>/In8' */
  real_T In1;                          /* '<Root>/In1' */
  real_T In2;                          /* '<Root>/In2' */
  real_T In4;                          /* '<Root>/In4' */
  real_T In5;                          /* '<Root>/In5' */
  real_T In9;                          /* '<Root>/In9' */
  real_T In10;                         /* '<Root>/In10' */
} ExtU_Controller_Michiel_T;

/* Parameters (auto storage) */
struct P_Controller_Michiel_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S6>/Integral Gain'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S6>/Proportional Gain'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant16'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant15_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant15'
                                        */
  real_T Constant14_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0.8
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant10_Value;             /* Expression: 1000
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant9_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant8_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant7_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<Root>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Controller_Michiel_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_Controller_Michiel_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[1];
    real_T odeF[4][1];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Controller_Michiel_T Controller_Michiel_P;

/* Block signals (auto storage) */
extern B_Controller_Michiel_T Controller_Michiel_B;

/* Continuous states (auto storage) */
extern X_Controller_Michiel_T Controller_Michiel_X;

/* Block states (auto storage) */
extern DW_Controller_Michiel_T Controller_Michiel_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Controller_Michiel_T Controller_Michiel_U;

/* Model entry point functions */
extern void Controller_Michiel_initialize(void);
extern void Controller_Michiel_step(void);
extern void Controller_Michiel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_Michiel_T *const Controller_Michiel_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Controller_Michiel'
 * '<S1>'   : 'Controller_Michiel/Controller'
 * '<S2>'   : 'Controller_Michiel/Inputs'
 * '<S3>'   : 'Controller_Michiel/Post-processor'
 * '<S4>'   : 'Controller_Michiel/Pre-processor'
 * '<S5>'   : 'Controller_Michiel/Simulatiemodel'
 * '<S6>'   : 'Controller_Michiel/Controller/PID Controller'
 * '<S7>'   : 'Controller_Michiel/Post-processor/Lineaire programering'
 * '<S8>'   : 'Controller_Michiel/Post-processor/Slip-controle '
 */
#endif                                 /* RTW_HEADER_Controller_Michiel_h_ */
