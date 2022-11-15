//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: explicitaccel_microaccel.h
//
// Code generated for Simulink model 'explicitaccel_microaccel'.
//
// Model version                  : 6.89
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Nov 15 14:00:24 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_explicitaccel_microaccel_h_
#define RTW_HEADER_explicitaccel_microaccel_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "explicitaccel_microaccel_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_explicitaccel_microaccel_T {
  SL_Bus_explicitaccel_microaccel_geometry_msgs_Twist BusAssignment1;// '<S1>/Bus Assignment1' 
  char_T b_zeroDelimName[17];
  SL_Bus_explicitaccel_microaccel_ros_time_Time r;
  real_T Subtract2;                    // '<S1>/Subtract2'
  real_T accel_memory;                 // '<S1>/accel_memory'
  real_T headway_memory;               // '<S1>/headway_memory'
  real_T TotalTime2;                   // '<S1>/Total Time2'
  real_T Memory;                       // '<S1>/Memory'
  real_T Switch;                       // '<S1>/Switch'
  real_T accel;                        // '<S1>/MATLAB Function'
  real_T a_vmax;                       // '<S1>/MATLAB Function'
  real_T lead_vel;
  real_T v_max_dot;
  real_T lead_acc_avg;
  real_T a_0;
  real_T a_12;
  real_T bsum;
  real_T difference;
  real_T alpha;
  real_T a_vdes;                       // '<S1>/MATLAB Function'
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 In1;// '<S30>/In1'
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 In1_i;// '<S29>/In1'
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 In1_n;// '<S28>/In1'
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 b_varargout_2;
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 BusAssignment5;// '<S1>/Bus Assignment5' 
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 BusAssignment2;// '<S1>/Bus Assignment2' 
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 BusAssignment3;// '<S1>/Bus Assignment3' 
};

// Block states (default storage) for system '<Root>'
struct DW_explicitaccel_microaccel_T {
  ros_slros_internal_block_Curr_T obj; // '<S1>/Current Time2'
  ros_slros_internal_block_GetP_T obj_k;// '<S1>/Get Parameter1'
  ros_slros_internal_block_GetP_T obj_e;// '<S1>/Get Parameter'
  ros_slroscpp_internal_block_P_T obj_h;// '<S22>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_l;// '<S21>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_b;// '<S20>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_g;// '<S19>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_n;// '<S18>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_nj;// '<S17>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_nb;// '<S16>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_n5;// '<S15>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_c;// '<S14>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_ke;// '<S26>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n0;// '<S25>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_hq;// '<S24>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_ep;// '<S23>/SourceBlock'
  real_T accel_memory_PreviousInput;   // '<S1>/accel_memory'
  real_T headway_memory_PreviousInput; // '<S1>/headway_memory'
  real_T Memory_PreviousInput;         // '<S1>/Memory'
  real_T previous_v_max;               // '<S1>/MATLAB Function'
  real_T previous_dx;                  // '<S1>/MATLAB Function'
  real_T previous_lead_acc;            // '<S1>/MATLAB Function'
  real_T prev_vels[2560];              // '<S1>/MATLAB Function'
  real_T no_initial_signal;            // '<S1>/MATLAB Function'
  real_T prev_lead_acc[20];            // '<S1>/MATLAB Function'
  real_T previous_lead_vel_real;       // '<S1>/MATLAB Function'
  real_T previous_target_speed;        // '<S1>/MATLAB Function'
  boolean_T previous_v_des_not_empty;  // '<S1>/MATLAB Function'
  boolean_T prev_lead_acc_not_empty;   // '<S1>/MATLAB Function'
};

// Continuous states (default storage)
struct X_explicitaccel_microaccel_T {
  real_T Integrator_CSTATE;            // '<S1>/Integrator'
};

// State derivatives (default storage)
struct XDot_explicitaccel_microaccel_T {
  real_T Integrator_CSTATE;            // '<S1>/Integrator'
};

// State disabled
struct XDis_explicitaccel_microaccel_T {
  boolean_T Integrator_CSTATE;         // '<S1>/Integrator'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_explicitaccel_microaccel_T_ {
  SL_Bus_explicitaccel_microaccel_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S2>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Bool Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                    //  Referenced by: '<S7>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                      //  Referenced by: '<S3>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                      //  Referenced by: '<S4>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_og;// Computed Parameter: Constant_Value_og
                                                                      //  Referenced by: '<S5>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                      //  Referenced by: '<S6>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                      //  Referenced by: '<S8>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                      //  Referenced by: '<S9>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                      //  Referenced by: '<S10>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                              //  Referenced by: '<S27>/Out1'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                      //  Referenced by: '<S23>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                                //  Referenced by: '<S28>/Out1'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                                      //  Referenced by: '<S24>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Out1_Y0_m;// Computed Parameter: Out1_Y0_m
                                                                //  Referenced by: '<S29>/Out1'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_kw;// Computed Parameter: Constant_Value_kw
                                                                      //  Referenced by: '<S25>/Constant'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                                //  Referenced by: '<S30>/Out1'

  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 Constant_Value_pd;// Computed Parameter: Constant_Value_pd
                                                                      //  Referenced by: '<S26>/Constant'

  real_T Integrator_IC;                // Expression: 0
                                          //  Referenced by: '<S1>/Integrator'

  real_T Constant_Value_a;             // Expression: 0
                                          //  Referenced by: '<S1>/Constant'

  real_T accel_memory_InitialCondition;// Expression: 0
                                          //  Referenced by: '<S1>/accel_memory'

  real_T headway_memory_InitialCondition;// Expression: 252
                                            //  Referenced by: '<S1>/headway_memory'

  real_T Gain2_Gain;                   // Expression: 1e-9
                                          //  Referenced by: '<S1>/Gain2'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S1>/Memory'

};

// Real-time Model Data Structure
struct tag_RTM_explicitaccel_microac_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_explicitaccel_microaccel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_explicitaccel_microaccel_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_explicitaccel_microaccel_T explicitaccel_microaccel_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_explicitaccel_microaccel_T explicitaccel_microaccel_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_explicitaccel_microaccel_T explicitaccel_microaccel_X;

// Block states (default storage)
extern struct DW_explicitaccel_microaccel_T explicitaccel_microaccel_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void explicitaccel_microaccel_initialize(void);
  extern void explicitaccel_microaccel_step(void);
  extern void explicitaccel_microaccel_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_explicitaccel_microa_T *const explicitaccel_microaccel_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'explicitaccel_microaccel'
//  '<S1>'   : 'explicitaccel_microaccel/MicroAccel'
//  '<S2>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message1'
//  '<S3>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message2'
//  '<S4>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message3'
//  '<S5>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message4'
//  '<S6>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message5'
//  '<S7>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message6'
//  '<S8>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message7'
//  '<S9>'   : 'explicitaccel_microaccel/MicroAccel/Blank Message8'
//  '<S10>'  : 'explicitaccel_microaccel/MicroAccel/Blank Message9'
//  '<S11>'  : 'explicitaccel_microaccel/MicroAccel/MATLAB Function'
//  '<S12>'  : 'explicitaccel_microaccel/MicroAccel/MATLAB Function1'
//  '<S13>'  : 'explicitaccel_microaccel/MicroAccel/MATLAB Function2'
//  '<S14>'  : 'explicitaccel_microaccel/MicroAccel/Publish1'
//  '<S15>'  : 'explicitaccel_microaccel/MicroAccel/Publish2'
//  '<S16>'  : 'explicitaccel_microaccel/MicroAccel/Publish3'
//  '<S17>'  : 'explicitaccel_microaccel/MicroAccel/Publish4'
//  '<S18>'  : 'explicitaccel_microaccel/MicroAccel/Publish5'
//  '<S19>'  : 'explicitaccel_microaccel/MicroAccel/Publish6'
//  '<S20>'  : 'explicitaccel_microaccel/MicroAccel/Publish7'
//  '<S21>'  : 'explicitaccel_microaccel/MicroAccel/Publish8'
//  '<S22>'  : 'explicitaccel_microaccel/MicroAccel/Publish9'
//  '<S23>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe'
//  '<S24>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe4'
//  '<S25>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe6'
//  '<S26>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe8'
//  '<S27>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe/Enabled Subsystem'
//  '<S28>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe4/Enabled Subsystem'
//  '<S29>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe6/Enabled Subsystem'
//  '<S30>'  : 'explicitaccel_microaccel/MicroAccel/Subscribe8/Enabled Subsystem'

#endif                                // RTW_HEADER_explicitaccel_microaccel_h_

//
// File trailer for generated code.
//
// [EOF]
//
