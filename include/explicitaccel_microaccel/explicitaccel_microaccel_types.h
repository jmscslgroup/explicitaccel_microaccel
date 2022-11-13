//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: explicitaccel_microaccel_types.h
//
// Code generated for Simulink model 'explicitaccel_microaccel'.
//
// Model version                  : 6.70
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sun Nov 13 18:38:24 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_explicitaccel_microaccel_types_h_
#define RTW_HEADER_explicitaccel_microaccel_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_explicitaccel_microaccel_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_explicitaccel_microaccel_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_explicitaccel_microaccel_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_explicitaccel_microaccel_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_std_msgs_Float64_

// MsgType=std_msgs/Float64
struct SL_Bus_explicitaccel_microaccel_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_std_msgs_Bool_

// MsgType=std_msgs/Bool
struct SL_Bus_explicitaccel_microaccel_std_msgs_Bool
{
  boolean_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_explicitaccel_microaccel_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_explicitaccel_microaccel_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef struct_f_robotics_slcore_internal_bl_T
#define struct_f_robotics_slcore_internal_bl_T

struct f_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                                // struct_f_robotics_slcore_internal_bl_T

#ifndef struct_ros_slros_internal_block_Curr_T
#define struct_ros_slros_internal_block_Curr_T

struct ros_slros_internal_block_Curr_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_Curr_T

#ifndef struct_ros_slros_internal_block_GetP_T
#define struct_ros_slros_internal_block_GetP_T

struct ros_slros_internal_block_GetP_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_GetP_T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_explicitaccel_microaccel_T_ P_explicitaccel_microaccel_T;

// Forward declaration for rtModel
typedef struct tag_RTM_explicitaccel_microac_T RT_MODEL_explicitaccel_microa_T;

#endif                          // RTW_HEADER_explicitaccel_microaccel_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
