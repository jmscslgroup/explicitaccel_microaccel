//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: explicitaccel_microaccel.cpp
//
// Code generated for Simulink model 'explicitaccel_microaccel'.
//
// Model version                  : 6.68
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sun Nov 13 13:57:46 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "explicitaccel_microaccel.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "explicitaccel_microaccel_types.h"
#include "explicitaccel_microaccel_private.h"

// Block signals (default storage)
B_explicitaccel_microaccel_T explicitaccel_microaccel_B;

// Continuous states
X_explicitaccel_microaccel_T explicitaccel_microaccel_X;

// Block states (default storage)
DW_explicitaccel_microaccel_T explicitaccel_microaccel_DW;

// Real-time model
RT_MODEL_explicitaccel_microa_T explicitaccel_microaccel_M_ =
  RT_MODEL_explicitaccel_microa_T();
RT_MODEL_explicitaccel_microa_T *const explicitaccel_microaccel_M =
  &explicitaccel_microaccel_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  explicitaccel_microaccel_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  explicitaccel_microaccel_step();
  explicitaccel_microaccel_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  explicitaccel_microaccel_step();
  explicitaccel_microaccel_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void explicitaccel_microaccel_step(void)
{
  SL_Bus_explicitaccel_microaccel_std_msgs_Bool rtb_BusAssignment6;
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 rtb_BusAssignment4;
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 rtb_BusAssignment7;
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 rtb_BusAssignment8;
  SL_Bus_explicitaccel_microaccel_std_msgs_Float64 rtb_BusAssignment9;
  real_T rtb_v_des;
  int32_T t_length;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&explicitaccel_microaccel_M->solverInfo,
                          ((explicitaccel_microaccel_M->Timing.clockTick0+1)*
      explicitaccel_microaccel_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(explicitaccel_microaccel_M)) {
    explicitaccel_microaccel_M->Timing.t[0] = rtsiGetT
      (&explicitaccel_microaccel_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    // Outputs for Atomic SubSystem: '<S1>/Subscribe4'
    // MATLABSystem: '<S24>/SourceBlock'
    b_varargout_1 = Sub_explicitaccel_microaccel_624.getLatestMessage
      (&explicitaccel_microaccel_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S28>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S28>/In1'
      explicitaccel_microaccel_B.In1_n =
        explicitaccel_microaccel_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S24>/SourceBlock'
    // End of Outputs for SubSystem: '<S24>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S1>/Subscribe4'

    // Outputs for Atomic SubSystem: '<S1>/Subscribe8'
    // MATLABSystem: '<S26>/SourceBlock'
    b_varargout_1 = Sub_explicitaccel_microaccel_559.getLatestMessage
      (&explicitaccel_microaccel_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S30>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S30>/In1'
      explicitaccel_microaccel_B.In1 = explicitaccel_microaccel_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S26>/SourceBlock'
    // End of Outputs for SubSystem: '<S26>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S1>/Subscribe8'

    // Sum: '<S1>/Subtract2'
    explicitaccel_microaccel_B.Subtract2 = explicitaccel_microaccel_B.In1_n.Data
      + explicitaccel_microaccel_B.In1.Data;
  }

  // BusAssignment: '<S1>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'
  //   Constant: '<S2>/Constant'
  //   Integrator: '<S1>/Integrator'

  explicitaccel_microaccel_B.BusAssignment1 =
    explicitaccel_microaccel_P.Constant_Value;
  explicitaccel_microaccel_B.BusAssignment1.Linear.X =
    explicitaccel_microaccel_X.Integrator_CSTATE;
  explicitaccel_microaccel_B.BusAssignment1.Angular.Z =
    explicitaccel_microaccel_P.Constant_Value_a;
  explicitaccel_microaccel_B.BusAssignment1.Linear.Y =
    explicitaccel_microaccel_B.Subtract2;

  // Outputs for Atomic SubSystem: '<S1>/Publish1'
  // MATLABSystem: '<S14>/SinkBlock'
  Pub_explicitaccel_microaccel_592.publish
    (&explicitaccel_microaccel_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S1>/Publish1'
  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    // Outputs for Atomic SubSystem: '<S1>/Subscribe6'
    // MATLABSystem: '<S25>/SourceBlock'
    b_varargout_1 = Sub_explicitaccel_microaccel_562.getLatestMessage
      (&explicitaccel_microaccel_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S25>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S29>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S29>/In1'
      explicitaccel_microaccel_B.In1_i =
        explicitaccel_microaccel_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S25>/SourceBlock'
    // End of Outputs for SubSystem: '<S25>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S1>/Subscribe6'
  }

  // MATLABSystem: '<S1>/Get Parameter'
  ParamGet_explicitaccel_microaccel_585.get_parameter
    (&explicitaccel_microaccel_B.v_max_dot);
  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    // Outputs for Atomic SubSystem: '<S1>/Subscribe'
    // MATLABSystem: '<S23>/SourceBlock'
    b_varargout_1 = Sub_explicitaccel_microaccel_599.getLatestMessage
      (&explicitaccel_microaccel_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S27>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S27>/In1'
      explicitaccel_microaccel_B.In1_b =
        explicitaccel_microaccel_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S23>/SourceBlock'
    // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S1>/Subscribe'
  }

  // MATLABSystem: '<S1>/Get Parameter1'
  ParamGet_explicitaccel_microaccel_631.get_parameter(&b_varargout_1);
  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    // MATLAB Function: '<S1>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S1>/Get Parameter'
    //   MATLABSystem: '<S1>/Get Parameter1'

    explicitaccel_microaccel_B.lead_vel = explicitaccel_microaccel_B.Subtract2;
    explicitaccel_microaccel_B.a_vdes = explicitaccel_microaccel_B.In1_i.Data;
    rtb_v_des = explicitaccel_microaccel_B.In1_b.Data;
    if ((!b_varargout_1) || (explicitaccel_microaccel_B.In1_b.Data == 0.0)) {
      rtb_v_des = -1.0;
    }

    if (explicitaccel_microaccel_B.Subtract2 == 0.0) {
      explicitaccel_microaccel_B.lead_vel = 0.2;
    }

    if (!explicitaccel_microaccel_DW.previous_v_des_not_empty) {
      t_length = 1;
      explicitaccel_microaccel_DW.previous_v_des_not_empty = true;
      memset(&explicitaccel_microaccel_DW.prev_vels[0], 0, 2560U * sizeof(real_T));
      explicitaccel_microaccel_DW.prev_vels[2559] =
        explicitaccel_microaccel_B.lead_vel;
    } else {
      for (t_length = 0; t_length < 2559; t_length++) {
        explicitaccel_microaccel_DW.prev_vels[t_length] =
          explicitaccel_microaccel_DW.prev_vels[t_length + 1];
      }

      explicitaccel_microaccel_DW.prev_vels[2559] =
        explicitaccel_microaccel_B.lead_vel;
      t_length = 0;
      for (int32_T i = 0; i < 2560; i++) {
        if (explicitaccel_microaccel_DW.prev_vels[i] != 0.0) {
          t_length++;
        }
      }
    }

    if (fabs(explicitaccel_microaccel_B.In1_i.Data) < 0.001) {
      explicitaccel_microaccel_B.a_vdes = 0.001;
    }

    if ((explicitaccel_microaccel_B.a_vdes >= 252.0) && rtIsNaN
        (explicitaccel_microaccel_DW.previous_dx)) {
      explicitaccel_microaccel_DW.no_initial_signal = 1.0;
      explicitaccel_microaccel_DW.prev_vels[2559] = 0.0;
      t_length = 0;
      for (int32_T i = 0; i < 2560; i++) {
        if (explicitaccel_microaccel_DW.prev_vels[i] != 0.0) {
          t_length++;
        }
      }
    } else if (explicitaccel_microaccel_B.a_vdes < 252.0) {
      explicitaccel_microaccel_DW.no_initial_signal = 0.0;
    } else if (explicitaccel_microaccel_B.a_vdes >= 252.0) {
      explicitaccel_microaccel_DW.prev_vels[2559] = 0.0;
      t_length = 0;
      for (int32_T i = 0; i < 2560; i++) {
        if (explicitaccel_microaccel_DW.prev_vels[i] != 0.0) {
          t_length++;
        }
      }

      explicitaccel_microaccel_B.lead_vel =
        explicitaccel_microaccel_DW.previous_lead_vel_real;
      if (explicitaccel_microaccel_DW.previous_dx < 220.0) {
        explicitaccel_microaccel_B.a_vdes =
          explicitaccel_microaccel_DW.previous_dx + 0.1;
      }
    }

    explicitaccel_microaccel_DW.previous_lead_vel_real =
      explicitaccel_microaccel_B.lead_vel;
    if (rtb_v_des == -1.0) {
      if (t_length == 0) {
        rtb_v_des = 30.0;
      } else {
        rtb_v_des = explicitaccel_microaccel_DW.prev_vels[0];
        for (int32_T i = 0; i < 1023; i++) {
          rtb_v_des += explicitaccel_microaccel_DW.prev_vels[i + 1];
        }

        for (int32_T i = 0; i < 2; i++) {
          int32_T hi;
          int32_T xblockoffset;
          xblockoffset = (i + 1) << 10;
          explicitaccel_microaccel_B.bsum =
            explicitaccel_microaccel_DW.prev_vels[xblockoffset];
          if (i + 2 == 3) {
            hi = 512;
          } else {
            hi = 1024;
          }

          for (int32_T e_k = 2; e_k <= hi; e_k++) {
            explicitaccel_microaccel_B.bsum +=
              explicitaccel_microaccel_DW.prev_vels[(xblockoffset + e_k) - 1];
          }

          rtb_v_des += explicitaccel_microaccel_B.bsum;
        }

        rtb_v_des /= static_cast<real_T>(t_length);
      }

      explicitaccel_microaccel_B.bsum = 3.0 *
        explicitaccel_microaccel_B.In1.Data;
      if (!(explicitaccel_microaccel_B.bsum >= 30.0)) {
        explicitaccel_microaccel_B.bsum = 30.0;
      }

      if ((explicitaccel_microaccel_B.In1.Data <= 1.0) || rtIsNaN
          (explicitaccel_microaccel_B.In1.Data)) {
        explicitaccel_microaccel_B.a_12 = 1.0;
      } else {
        explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.In1.Data;
      }

      explicitaccel_microaccel_B.a_0 = (explicitaccel_microaccel_B.a_vdes -
        explicitaccel_microaccel_B.bsum) / explicitaccel_microaccel_B.a_12;
      if ((explicitaccel_microaccel_B.a_0 <= 0.0) || rtIsNaN
          (explicitaccel_microaccel_B.a_0)) {
        explicitaccel_microaccel_B.a_0 = 0.0;
      }

      rtb_v_des += explicitaccel_microaccel_B.a_0 *
        explicitaccel_microaccel_B.a_0 * 0.1;
      if (!(rtb_v_des <= 35.0)) {
        rtb_v_des = 35.0;
      }
    } else {
      explicitaccel_microaccel_B.bsum = 1.2 *
        explicitaccel_microaccel_B.lead_vel;
      if ((!(rtb_v_des <= explicitaccel_microaccel_B.bsum)) && (!rtIsNaN
           (explicitaccel_microaccel_B.bsum))) {
        rtb_v_des = explicitaccel_microaccel_B.bsum;
      }

      if (explicitaccel_microaccel_B.lead_vel <= 35.0) {
        explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.lead_vel;
      } else {
        explicitaccel_microaccel_B.a_12 = 35.0;
      }

      explicitaccel_microaccel_B.a_0 = 0.8 * explicitaccel_microaccel_B.a_12;
      if ((!(rtb_v_des >= explicitaccel_microaccel_B.a_0)) && (!rtIsNaN
           (explicitaccel_microaccel_B.a_0))) {
        rtb_v_des = explicitaccel_microaccel_B.a_0;
      }

      if (explicitaccel_microaccel_DW.no_initial_signal == 0.0) {
        if ((rtb_v_des <= explicitaccel_microaccel_B.bsum) || rtIsNaN
            (explicitaccel_microaccel_B.bsum)) {
          explicitaccel_microaccel_B.bsum = rtb_v_des;
        }

        if (explicitaccel_microaccel_B.lead_vel <= 35.0) {
          explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.lead_vel;
        } else {
          explicitaccel_microaccel_B.a_12 = 35.0;
        }

        rtb_v_des = 0.8 * explicitaccel_microaccel_B.a_12;
        if ((explicitaccel_microaccel_B.bsum >= rtb_v_des) || rtIsNaN(rtb_v_des))
        {
          rtb_v_des = explicitaccel_microaccel_B.bsum;
        }
      }
    }

    if ((explicitaccel_microaccel_DW.prev_vels[2558] == 0.0) ||
        (explicitaccel_microaccel_DW.prev_vels[2559] == 0.0) ||
        (explicitaccel_microaccel_DW.no_initial_signal == 1.0)) {
      explicitaccel_microaccel_DW.previous_lead_acc = 0.0;
    } else {
      explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.lead_vel -
        explicitaccel_microaccel_DW.prev_vels[2558];
      if (explicitaccel_microaccel_B.a_12 < 0.165) {
        explicitaccel_microaccel_DW.previous_lead_acc =
          explicitaccel_microaccel_B.a_12 / 0.05;
      }
    }

    if (rtIsNaN(explicitaccel_microaccel_B.lead_vel) ||
        ((explicitaccel_microaccel_B.a_vdes == 252.0) &&
         (explicitaccel_microaccel_DW.previous_dx > 220.0)) ||
        (explicitaccel_microaccel_DW.no_initial_signal == 1.0)) {
      explicitaccel_microaccel_B.a_0 = 1.0;
      explicitaccel_microaccel_B.v_max_dot = 0.0;
      explicitaccel_microaccel_B.bsum = 30.0;
      if (rtIsNaN(explicitaccel_microaccel_B.lead_vel) ||
          (explicitaccel_microaccel_DW.no_initial_signal == 1.0)) {
        rtb_v_des = 30.0;
      }
    } else {
      if (rtIsNaN(explicitaccel_microaccel_DW.previous_dx)) {
        explicitaccel_microaccel_DW.previous_dx =
          explicitaccel_microaccel_B.a_vdes;
      }

      if (explicitaccel_microaccel_B.a_vdes - 18.0 >= 0.0) {
        explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.a_vdes -
          18.0;
      } else {
        explicitaccel_microaccel_B.a_12 = 0.0;
      }

      explicitaccel_microaccel_B.bsum = sqrt
        ((explicitaccel_microaccel_B.lead_vel *
          explicitaccel_microaccel_B.lead_vel * 0.5 / fabs
          (explicitaccel_microaccel_B.v_max_dot) +
          explicitaccel_microaccel_B.a_12) * 6.0);
      if (rtIsNaN(explicitaccel_microaccel_DW.previous_v_max)) {
        explicitaccel_microaccel_B.v_max_dot = 0.0;
      } else if (fabs(explicitaccel_microaccel_B.a_vdes -
                      explicitaccel_microaccel_DW.previous_dx) > 2.5) {
        explicitaccel_microaccel_B.v_max_dot = 0.0;
      } else {
        explicitaccel_microaccel_B.v_max_dot = (explicitaccel_microaccel_B.bsum
          - explicitaccel_microaccel_DW.previous_v_max) / 0.05;
      }

      explicitaccel_microaccel_DW.previous_v_max =
        explicitaccel_microaccel_B.bsum;
      if (!explicitaccel_microaccel_DW.prev_lead_acc_not_empty) {
        memset(&explicitaccel_microaccel_DW.prev_lead_acc[0], 0, 20U * sizeof
               (real_T));
        explicitaccel_microaccel_DW.prev_lead_acc_not_empty = true;
        explicitaccel_microaccel_DW.prev_lead_acc[19] =
          explicitaccel_microaccel_DW.previous_lead_acc;
      } else {
        for (t_length = 0; t_length < 19; t_length++) {
          explicitaccel_microaccel_DW.prev_lead_acc[t_length] =
            explicitaccel_microaccel_DW.prev_lead_acc[t_length + 1];
        }

        explicitaccel_microaccel_DW.prev_lead_acc[19] =
          explicitaccel_microaccel_DW.previous_lead_acc;
      }

      t_length = 0;
      for (int32_T i = 0; i < 20; i++) {
        if (explicitaccel_microaccel_DW.prev_lead_acc[i] != 0.0) {
          t_length++;
        }
      }

      if (t_length == 0) {
        explicitaccel_microaccel_B.lead_acc_avg = 0.0;
      } else {
        explicitaccel_microaccel_B.a_0 =
          explicitaccel_microaccel_DW.prev_lead_acc[0];
        for (int32_T i = 0; i < 19; i++) {
          explicitaccel_microaccel_B.a_0 +=
            explicitaccel_microaccel_DW.prev_lead_acc[i + 1];
        }

        explicitaccel_microaccel_B.lead_acc_avg = explicitaccel_microaccel_B.a_0
          / static_cast<real_T>(t_length);
      }

      if (explicitaccel_microaccel_B.lead_acc_avg < 0.0) {
        explicitaccel_microaccel_B.a_0 = explicitaccel_microaccel_B.lead_acc_avg
          * explicitaccel_microaccel_B.In1.Data /
          (explicitaccel_microaccel_B.lead_vel + 0.001);
        if ((explicitaccel_microaccel_B.a_vdes - 18.0 <= 0.0) || rtIsNaN
            (explicitaccel_microaccel_B.a_vdes - 18.0)) {
          explicitaccel_microaccel_B.a_12 = 0.0;
        } else {
          explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.a_vdes -
            18.0;
        }

        explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.In1.Data *
          explicitaccel_microaccel_B.In1.Data * -0.5 /
          ((explicitaccel_microaccel_B.lead_vel + 1.0E-5) *
           (explicitaccel_microaccel_B.lead_vel + 1.0E-5) * 0.5 / fabs
           (explicitaccel_microaccel_B.lead_acc_avg - 0.01) +
           explicitaccel_microaccel_B.a_12);
        if (explicitaccel_microaccel_B.a_0 < explicitaccel_microaccel_B.a_12) {
          explicitaccel_microaccel_B.a_0 = explicitaccel_microaccel_B.a_12;
        } else if (!(explicitaccel_microaccel_B.lead_vel >=
                     explicitaccel_microaccel_B.In1.Data)) {
          explicitaccel_microaccel_B.a_0 = explicitaccel_microaccel_B.lead_vel -
            explicitaccel_microaccel_B.In1.Data;
          if (explicitaccel_microaccel_B.a_vdes - 18.0 >= 0.001) {
            explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.a_vdes
              - 18.0;
          } else {
            explicitaccel_microaccel_B.a_12 = 0.001;
          }

          explicitaccel_microaccel_B.a_0 =
            explicitaccel_microaccel_B.lead_acc_avg -
            explicitaccel_microaccel_B.a_0 * explicitaccel_microaccel_B.a_0 /
            (2.0 * explicitaccel_microaccel_B.a_12);
        }
      } else if (explicitaccel_microaccel_B.lead_acc_avg >= 0.0) {
        if (explicitaccel_microaccel_B.lead_vel <=
            explicitaccel_microaccel_B.In1.Data) {
          explicitaccel_microaccel_B.a_0 = explicitaccel_microaccel_B.In1.Data -
            explicitaccel_microaccel_B.lead_vel;
          if ((explicitaccel_microaccel_B.a_0 <= 0.0) || rtIsNaN
              (explicitaccel_microaccel_B.a_0)) {
            explicitaccel_microaccel_B.a_0 = 0.0;
          }

          if (explicitaccel_microaccel_B.a_vdes - 18.0 >= 0.001) {
            explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.a_vdes
              - 18.0;
          } else {
            explicitaccel_microaccel_B.a_12 = 0.001;
          }

          explicitaccel_microaccel_B.a_0 =
            explicitaccel_microaccel_B.lead_acc_avg -
            explicitaccel_microaccel_B.a_0 * explicitaccel_microaccel_B.a_0 /
            (2.0 * explicitaccel_microaccel_B.a_12);
        } else {
          explicitaccel_microaccel_B.a_0 = (explicitaccel_microaccel_B.lead_vel
            - explicitaccel_microaccel_B.In1.Data) *
            explicitaccel_microaccel_B.lead_acc_avg +
            explicitaccel_microaccel_B.lead_acc_avg;
          if ((explicitaccel_microaccel_B.a_0 >= 1.0) || rtIsNaN
              (explicitaccel_microaccel_B.a_0)) {
            explicitaccel_microaccel_B.a_0 = 1.0;
          }
        }
      } else {
        explicitaccel_microaccel_B.a_0 = (rtNaN);
        printf("This is an error\n");
        fflush(stdout);
      }

      explicitaccel_microaccel_B.a_12 = explicitaccel_microaccel_B.In1.Data *
        4.0;
      if (explicitaccel_microaccel_B.a_vdes > explicitaccel_microaccel_B.a_12) {
        if (explicitaccel_microaccel_B.In1.Data >= 0.01) {
          explicitaccel_microaccel_B.lead_vel =
            explicitaccel_microaccel_B.In1.Data;
        } else {
          explicitaccel_microaccel_B.lead_vel = 0.01;
        }

        explicitaccel_microaccel_B.a_0 += (explicitaccel_microaccel_B.a_vdes -
          explicitaccel_microaccel_B.a_12) / explicitaccel_microaccel_B.lead_vel;
      }

      explicitaccel_microaccel_DW.previous_dx =
        explicitaccel_microaccel_B.a_vdes;
    }

    if (!(explicitaccel_microaccel_B.a_0 >= -1.0)) {
      explicitaccel_microaccel_B.a_0 = -1.0;
    }

    explicitaccel_microaccel_B.a_vdes = -(explicitaccel_microaccel_B.In1.Data -
      rtb_v_des);
    if (!(explicitaccel_microaccel_B.a_vdes >= -0.4)) {
      explicitaccel_microaccel_B.a_vdes = -0.4;
    }

    explicitaccel_microaccel_B.a_vmax = -(explicitaccel_microaccel_B.In1.Data -
      explicitaccel_microaccel_B.bsum) + explicitaccel_microaccel_B.v_max_dot;
    if ((explicitaccel_microaccel_B.a_vdes <= explicitaccel_microaccel_B.a_vmax)
        || rtIsNaN(explicitaccel_microaccel_B.a_vmax)) {
      explicitaccel_microaccel_B.accel = explicitaccel_microaccel_B.a_vdes;
    } else {
      explicitaccel_microaccel_B.accel = explicitaccel_microaccel_B.a_vmax;
    }

    if ((!(explicitaccel_microaccel_B.accel <= explicitaccel_microaccel_B.a_0)) &&
        (!rtIsNaN(explicitaccel_microaccel_B.a_0))) {
      explicitaccel_microaccel_B.accel = explicitaccel_microaccel_B.a_0;
    }

    if (!(explicitaccel_microaccel_B.accel >= -3.0)) {
      explicitaccel_microaccel_B.accel = -3.0;
    }

    if (!(explicitaccel_microaccel_B.accel <= 1.0)) {
      explicitaccel_microaccel_B.accel = 1.0;
    }

    if ((explicitaccel_microaccel_B.In1.Data >= 30.0) &&
        ((explicitaccel_microaccel_B.accel >= 0.0) || rtIsNaN
         (explicitaccel_microaccel_B.accel))) {
      explicitaccel_microaccel_B.accel = 0.0;
    }

    // End of MATLAB Function: '<S1>/MATLAB Function'

    // Memory: '<S1>/accel_memory'
    explicitaccel_microaccel_B.accel_memory =
      explicitaccel_microaccel_DW.accel_memory_PreviousInput;

    // Memory: '<S1>/headway_memory'
    explicitaccel_microaccel_B.headway_memory =
      explicitaccel_microaccel_DW.headway_memory_PreviousInput;
  }

  // MATLABSystem: '<S1>/Current Time2'
  currentROSTimeBus(&explicitaccel_microaccel_B.r);

  // Sum: '<S1>/Total Time2' incorporates:
  //   Gain: '<S1>/Gain2'
  //   MATLABSystem: '<S1>/Current Time2'

  explicitaccel_microaccel_B.TotalTime2 = explicitaccel_microaccel_P.Gain2_Gain *
    explicitaccel_microaccel_B.r.Nsec + explicitaccel_microaccel_B.r.Sec;
  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    // Memory: '<S1>/Memory'
    explicitaccel_microaccel_B.Memory =
      explicitaccel_microaccel_DW.Memory_PreviousInput;
  }

  // Sum: '<S1>/Subtract1'
  explicitaccel_microaccel_B.v_max_dot = explicitaccel_microaccel_B.TotalTime2 -
    explicitaccel_microaccel_B.Memory;

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function2'

  explicitaccel_microaccel_B.lead_vel = explicitaccel_microaccel_B.Subtract2 -
    explicitaccel_microaccel_B.In1.Data;
  explicitaccel_microaccel_B.alpha = explicitaccel_microaccel_B.In1_i.Data /
    explicitaccel_microaccel_B.In1.Data;
  explicitaccel_microaccel_B.a_12 = static_cast<real_T>
    (explicitaccel_microaccel_B.In1.Data > 0.0) *
    explicitaccel_microaccel_B.alpha + static_cast<real_T>
    (explicitaccel_microaccel_B.In1.Data <= 0.0) * 60.0;
  explicitaccel_microaccel_B.lead_acc_avg = static_cast<real_T>
    (explicitaccel_microaccel_B.lead_vel < 0.0) *
    (-explicitaccel_microaccel_B.In1_i.Data /
     explicitaccel_microaccel_B.lead_vel) + static_cast<real_T>
    (explicitaccel_microaccel_B.lead_vel >= 0.0) * 60.0;
  explicitaccel_microaccel_B.difference = explicitaccel_microaccel_B.In1_i.Data
    - explicitaccel_microaccel_B.headway_memory;

  // MATLAB Function: '<S1>/MATLAB Function2'
  explicitaccel_microaccel_B.alpha = (tanh((10.34 /
    explicitaccel_microaccel_B.In1_i.Data * static_cast<real_T>
    (explicitaccel_microaccel_B.lead_vel < 0.0) + static_cast<real_T>
    (explicitaccel_microaccel_B.lead_vel >= 0.0)) *
    explicitaccel_microaccel_B.lead_vel) * 0.5 + 0.5) * 0.25 + tanh((
    static_cast<real_T>(explicitaccel_microaccel_B.In1.Data > 0.0) *
    explicitaccel_microaccel_B.alpha + static_cast<real_T>
    (explicitaccel_microaccel_B.In1.Data <= 0.0) * 60.0) * 1.32) * 0.75;
  explicitaccel_microaccel_B.Switch = (1.0 - explicitaccel_microaccel_B.alpha) *
    explicitaccel_microaccel_B.accel + explicitaccel_microaccel_B.alpha *
    explicitaccel_microaccel_B.accel_memory;
  if (fabs(explicitaccel_microaccel_B.Switch - explicitaccel_microaccel_B.accel)
      < 0.3 * explicitaccel_microaccel_B.v_max_dot) {
    explicitaccel_microaccel_B.Switch = explicitaccel_microaccel_B.accel;
  }

  // MATLAB Function: '<S1>/MATLAB Function1'
  if (explicitaccel_microaccel_B.difference <= -3.5) {
    if (fabs(explicitaccel_microaccel_B.accel -
             explicitaccel_microaccel_B.accel_memory) > 0.9 *
        explicitaccel_microaccel_B.v_max_dot) {
      if ((explicitaccel_microaccel_B.lead_vel >= 0.0) &&
          (explicitaccel_microaccel_B.a_12 > 2.0)) {
        t_length = -1;
      } else if ((explicitaccel_microaccel_B.lead_vel < 0.0) &&
                 (explicitaccel_microaccel_B.lead_acc_avg > 4.5)) {
        t_length = -1;
      } else {
        t_length = 0;
      }
    } else {
      t_length = 0;
    }
  } else if ((explicitaccel_microaccel_B.difference >= 3.5) && (fabs
              (explicitaccel_microaccel_B.accel -
               explicitaccel_microaccel_B.accel_memory) > 0.9 *
              explicitaccel_microaccel_B.v_max_dot)) {
    if ((explicitaccel_microaccel_B.lead_vel >= 0.0) &&
        (explicitaccel_microaccel_B.a_12 > 2.0)) {
      t_length = 1;
    } else {
      t_length = ((explicitaccel_microaccel_B.lead_vel < 0.0) &&
                  (explicitaccel_microaccel_B.lead_acc_avg > 4.5));
    }
  } else {
    t_length = 0;
  }

  // Switch: '<S1>/Switch' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  if (t_length != 0) {
    // MATLAB Function: '<S1>/MATLAB Function2'
    if ((!(explicitaccel_microaccel_B.Switch <=
           explicitaccel_microaccel_B.a_vmax)) && (!rtIsNaN
         (explicitaccel_microaccel_B.a_vmax))) {
      // Switch: '<S1>/Switch'
      explicitaccel_microaccel_B.Switch = explicitaccel_microaccel_B.a_vmax;
    }
  } else {
    // Switch: '<S1>/Switch'
    explicitaccel_microaccel_B.Switch = explicitaccel_microaccel_B.accel;
  }

  // End of Switch: '<S1>/Switch'

  // BusAssignment: '<S1>/Bus Assignment5'
  explicitaccel_microaccel_B.BusAssignment5.Data =
    explicitaccel_microaccel_B.Switch;

  // Outputs for Atomic SubSystem: '<S1>/Publish2'
  // MATLABSystem: '<S15>/SinkBlock'
  Pub_explicitaccel_microaccel_609.publish
    (&explicitaccel_microaccel_B.BusAssignment5);

  // End of Outputs for SubSystem: '<S1>/Publish2'
  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    // BusAssignment: '<S1>/Bus Assignment2'
    explicitaccel_microaccel_B.BusAssignment2.Data =
      explicitaccel_microaccel_B.a_vdes;

    // Outputs for Atomic SubSystem: '<S1>/Publish3'
    // MATLABSystem: '<S16>/SinkBlock'
    Pub_explicitaccel_microaccel_610.publish
      (&explicitaccel_microaccel_B.BusAssignment2);

    // End of Outputs for SubSystem: '<S1>/Publish3'

    // BusAssignment: '<S1>/Bus Assignment3'
    explicitaccel_microaccel_B.BusAssignment3.Data =
      explicitaccel_microaccel_B.a_vmax;

    // Outputs for Atomic SubSystem: '<S1>/Publish4'
    // MATLABSystem: '<S17>/SinkBlock'
    Pub_explicitaccel_microaccel_611.publish
      (&explicitaccel_microaccel_B.BusAssignment3);

    // End of Outputs for SubSystem: '<S1>/Publish4'

    // BusAssignment: '<S1>/Bus Assignment4'
    rtb_BusAssignment4.Data = explicitaccel_microaccel_B.a_0;

    // Outputs for Atomic SubSystem: '<S1>/Publish5'
    // MATLABSystem: '<S18>/SinkBlock'
    Pub_explicitaccel_microaccel_612.publish(&rtb_BusAssignment4);

    // End of Outputs for SubSystem: '<S1>/Publish5'

    // BusAssignment: '<S1>/Bus Assignment7'
    rtb_BusAssignment7.Data = 0.0;

    // Outputs for Atomic SubSystem: '<S1>/Publish7'
    // MATLABSystem: '<S20>/SinkBlock'
    Pub_explicitaccel_microaccel_654.publish(&rtb_BusAssignment7);

    // End of Outputs for SubSystem: '<S1>/Publish7'

    // BusAssignment: '<S1>/Bus Assignment8'
    rtb_BusAssignment8.Data = rtb_v_des;

    // Outputs for Atomic SubSystem: '<S1>/Publish8'
    // MATLABSystem: '<S21>/SinkBlock'
    Pub_explicitaccel_microaccel_657.publish(&rtb_BusAssignment8);

    // End of Outputs for SubSystem: '<S1>/Publish8'

    // BusAssignment: '<S1>/Bus Assignment9'
    rtb_BusAssignment9.Data = explicitaccel_microaccel_B.bsum;

    // Outputs for Atomic SubSystem: '<S1>/Publish9'
    // MATLABSystem: '<S22>/SinkBlock'
    Pub_explicitaccel_microaccel_660.publish(&rtb_BusAssignment9);

    // End of Outputs for SubSystem: '<S1>/Publish9'
  }

  // BusAssignment: '<S1>/Bus Assignment6' incorporates:
  //   MATLABSystem: '<S1>/Get Parameter1'

  rtb_BusAssignment6.Data = b_varargout_1;

  // Outputs for Atomic SubSystem: '<S1>/Publish6'
  // MATLABSystem: '<S19>/SinkBlock'
  Pub_explicitaccel_microaccel_635.publish(&rtb_BusAssignment6);

  // End of Outputs for SubSystem: '<S1>/Publish6'
  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
      // Update for Memory: '<S1>/accel_memory'
      explicitaccel_microaccel_DW.accel_memory_PreviousInput =
        explicitaccel_microaccel_B.Switch;

      // Update for Memory: '<S1>/headway_memory'
      explicitaccel_microaccel_DW.headway_memory_PreviousInput =
        explicitaccel_microaccel_B.In1_i.Data;

      // Update for Memory: '<S1>/Memory'
      explicitaccel_microaccel_DW.Memory_PreviousInput =
        explicitaccel_microaccel_B.TotalTime2;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(explicitaccel_microaccel_M)) {
    rt_ertODEUpdateContinuousStates(&explicitaccel_microaccel_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++explicitaccel_microaccel_M->Timing.clockTick0;
    explicitaccel_microaccel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&explicitaccel_microaccel_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      explicitaccel_microaccel_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void explicitaccel_microaccel_derivatives(void)
{
  XDot_explicitaccel_microaccel_T *_rtXdot;
  _rtXdot = ((XDot_explicitaccel_microaccel_T *)
             explicitaccel_microaccel_M->derivs);

  // Derivatives for Integrator: '<S1>/Integrator'
  _rtXdot->Integrator_CSTATE = explicitaccel_microaccel_B.Switch;
}

// Model initialize function
void explicitaccel_microaccel_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&explicitaccel_microaccel_M->solverInfo,
                          &explicitaccel_microaccel_M->Timing.simTimeStep);
    rtsiSetTPtr(&explicitaccel_microaccel_M->solverInfo, &rtmGetTPtr
                (explicitaccel_microaccel_M));
    rtsiSetStepSizePtr(&explicitaccel_microaccel_M->solverInfo,
                       &explicitaccel_microaccel_M->Timing.stepSize0);
    rtsiSetdXPtr(&explicitaccel_microaccel_M->solverInfo,
                 &explicitaccel_microaccel_M->derivs);
    rtsiSetContStatesPtr(&explicitaccel_microaccel_M->solverInfo, (real_T **)
                         &explicitaccel_microaccel_M->contStates);
    rtsiSetNumContStatesPtr(&explicitaccel_microaccel_M->solverInfo,
      &explicitaccel_microaccel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&explicitaccel_microaccel_M->solverInfo,
      &explicitaccel_microaccel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&explicitaccel_microaccel_M->solverInfo,
      &explicitaccel_microaccel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&explicitaccel_microaccel_M->solverInfo,
      &explicitaccel_microaccel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&explicitaccel_microaccel_M->solverInfo,
                          (&rtmGetErrorStatus(explicitaccel_microaccel_M)));
    rtsiSetRTModelPtr(&explicitaccel_microaccel_M->solverInfo,
                      explicitaccel_microaccel_M);
  }

  rtsiSetSimTimeStep(&explicitaccel_microaccel_M->solverInfo, MAJOR_TIME_STEP);
  explicitaccel_microaccel_M->intgData.y = explicitaccel_microaccel_M->odeY;
  explicitaccel_microaccel_M->intgData.f[0] = explicitaccel_microaccel_M->odeF[0];
  explicitaccel_microaccel_M->intgData.f[1] = explicitaccel_microaccel_M->odeF[1];
  explicitaccel_microaccel_M->intgData.f[2] = explicitaccel_microaccel_M->odeF[2];
  explicitaccel_microaccel_M->contStates = ((X_explicitaccel_microaccel_T *)
    &explicitaccel_microaccel_X);
  rtsiSetSolverData(&explicitaccel_microaccel_M->solverInfo, static_cast<void *>
                    (&explicitaccel_microaccel_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&explicitaccel_microaccel_M->solverInfo,
    false);
  rtsiSetSolverName(&explicitaccel_microaccel_M->solverInfo,"ode3");
  rtmSetTPtr(explicitaccel_microaccel_M,
             &explicitaccel_microaccel_M->Timing.tArray[0]);
  explicitaccel_microaccel_M->Timing.stepSize0 = 0.05;

  {
    char_T b_zeroDelimTopic_2[13];
    char_T b_zeroDelimTopic_1[10];
    char_T b_zeroDelimTopic_3[9];
    char_T b_zeroDelimTopic[8];
    char_T b_zeroDelimTopic_4[6];
    char_T b_zeroDelimTopic_0[4];
    static const char_T tmp[7] = { 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_1[9] = { 'l', 'e', 'a', 'd', '_', 'd', 'i', 's', 't'
    };

    static const char_T tmp_2[12] = { 't', 'a', 'r', 'g', 'e', 't', '_', 's',
      'p', 'e', 'e', 'd' };

    static const char_T tmp_3[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    static const char_T tmp_4[9] = { 'a', '_', 'v', 'd', 'e', 's', 'o', 'u', 't'
    };

    static const char_T tmp_5[9] = { 'a', '_', 'v', 'm', 'a', 'x', 'o', 'u', 't'
    };

    static const char_T tmp_6[8] = { 'a', '_', 'm', 'n', 'g', 'o', 'u', 't' };

    static const char_T tmp_7[9] = { 'v', '_', 'd', 'e', 's', '_', 'd', 'o', 't'
    };

    static const char_T tmp_8[5] = { 'v', '_', 'd', 'e', 's' };

    static const char_T tmp_9[5] = { 'v', '_', 'm', 'a', 'x' };

    static const char_T tmp_a[15] = { 't', 'a', 'r', 'g', 'e', 't', 's', 'p',
      'e', 'e', 'd', 'f', 'l', 'a', 'g' };

    static const char_T tmp_b[16] = { 'm', 'a', 'x', '_', 'd', 'e', 'a', 'c',
      'c', 'e', 'l', '_', 'l', 'e', 'a', 'd' };

    static const char_T tmp_c[16] = { 'u', 's', 'e', '_', 't', 'a', 'r', 'g',
      'e', 't', '_', 's', 'p', 'e', 'e', 'd' };

    // InitializeConditions for Integrator: '<S1>/Integrator'
    explicitaccel_microaccel_X.Integrator_CSTATE =
      explicitaccel_microaccel_P.Integrator_IC;

    // InitializeConditions for Memory: '<S1>/accel_memory'
    explicitaccel_microaccel_DW.accel_memory_PreviousInput =
      explicitaccel_microaccel_P.accel_memory_InitialCondition;

    // InitializeConditions for Memory: '<S1>/headway_memory'
    explicitaccel_microaccel_DW.headway_memory_PreviousInput =
      explicitaccel_microaccel_P.headway_memory_InitialCondition;

    // InitializeConditions for Memory: '<S1>/Memory'
    explicitaccel_microaccel_DW.Memory_PreviousInput =
      explicitaccel_microaccel_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<S1>/Subscribe4'
    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S28>/In1' incorporates:
    //   Outport: '<S28>/Out1'

    explicitaccel_microaccel_B.In1_n = explicitaccel_microaccel_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'

    // Start for MATLABSystem: '<S24>/SourceBlock'
    explicitaccel_microaccel_DW.obj_hq.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_hq.isInitialized = 1;
    for (int32_T i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_explicitaccel_microaccel_624.createSubscriber(&b_zeroDelimTopic[0], 1);
    explicitaccel_microaccel_DW.obj_hq.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S24>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<S1>/Subscribe8'
    // SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S30>/In1' incorporates:
    //   Outport: '<S30>/Out1'

    explicitaccel_microaccel_B.In1 = explicitaccel_microaccel_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem'

    // Start for MATLABSystem: '<S26>/SourceBlock'
    explicitaccel_microaccel_DW.obj_ke.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_ke.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 'v';
    b_zeroDelimTopic_0[1] = 'e';
    b_zeroDelimTopic_0[2] = 'l';
    b_zeroDelimTopic_0[3] = '\x00';
    Sub_explicitaccel_microaccel_559.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    explicitaccel_microaccel_DW.obj_ke.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S1>/Subscribe8'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish1'
    // Start for MATLABSystem: '<S14>/SinkBlock'
    explicitaccel_microaccel_DW.obj_c.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_c.isInitialized = 1;
    for (int32_T i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp_0[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Pub_explicitaccel_microaccel_592.createPublisher(&b_zeroDelimTopic[0], 1);
    explicitaccel_microaccel_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S14>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<S1>/Subscribe6'
    // SystemInitialize for Enabled SubSystem: '<S25>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S29>/In1' incorporates:
    //   Outport: '<S29>/Out1'

    explicitaccel_microaccel_B.In1_i = explicitaccel_microaccel_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S25>/Enabled Subsystem'

    // Start for MATLABSystem: '<S25>/SourceBlock'
    explicitaccel_microaccel_DW.obj_n0.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_n0.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Sub_explicitaccel_microaccel_562.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    explicitaccel_microaccel_DW.obj_n0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S25>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Subscribe6'

    // SystemInitialize for Atomic SubSystem: '<S1>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S27>/In1' incorporates:
    //   Outport: '<S27>/Out1'

    explicitaccel_microaccel_B.In1_b = explicitaccel_microaccel_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem'

    // Start for MATLABSystem: '<S23>/SourceBlock'
    explicitaccel_microaccel_DW.obj_ep.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_ep.isInitialized = 1;
    for (int32_T i = 0; i < 12; i++) {
      b_zeroDelimTopic_2[i] = tmp_2[i];
    }

    b_zeroDelimTopic_2[12] = '\x00';
    Sub_explicitaccel_microaccel_599.createSubscriber(&b_zeroDelimTopic_2[0], 1);
    explicitaccel_microaccel_DW.obj_ep.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S23>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Subscribe'

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function'
    explicitaccel_microaccel_DW.previous_v_max = (rtNaN);
    explicitaccel_microaccel_DW.previous_dx = (rtNaN);
    explicitaccel_microaccel_DW.previous_lead_acc = (rtNaN);
    explicitaccel_microaccel_DW.previous_lead_vel_real = (rtNaN);

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish2'
    // Start for MATLABSystem: '<S15>/SinkBlock'
    explicitaccel_microaccel_DW.obj_n5.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_n5.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_3[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Pub_explicitaccel_microaccel_609.createPublisher(&b_zeroDelimTopic_1[0], 1);
    explicitaccel_microaccel_DW.obj_n5.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S15>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish3'
    // Start for MATLABSystem: '<S16>/SinkBlock'
    explicitaccel_microaccel_DW.obj_nb.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_nb.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_4[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Pub_explicitaccel_microaccel_610.createPublisher(&b_zeroDelimTopic_1[0], 1);
    explicitaccel_microaccel_DW.obj_nb.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S16>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish3'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish4'
    // Start for MATLABSystem: '<S17>/SinkBlock'
    explicitaccel_microaccel_DW.obj_nj.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_nj.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_5[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Pub_explicitaccel_microaccel_611.createPublisher(&b_zeroDelimTopic_1[0], 1);
    explicitaccel_microaccel_DW.obj_nj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S17>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish4'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish5'
    // Start for MATLABSystem: '<S18>/SinkBlock'
    explicitaccel_microaccel_DW.obj_n.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_n.isInitialized = 1;
    for (int32_T i = 0; i < 8; i++) {
      b_zeroDelimTopic_3[i] = tmp_6[i];
    }

    b_zeroDelimTopic_3[8] = '\x00';
    Pub_explicitaccel_microaccel_612.createPublisher(&b_zeroDelimTopic_3[0], 1);
    explicitaccel_microaccel_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S18>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish5'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish7'
    // Start for MATLABSystem: '<S20>/SinkBlock'
    explicitaccel_microaccel_DW.obj_b.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_b.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_7[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Pub_explicitaccel_microaccel_654.createPublisher(&b_zeroDelimTopic_1[0], 1);
    explicitaccel_microaccel_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S20>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish7'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish8'
    // Start for MATLABSystem: '<S21>/SinkBlock'
    explicitaccel_microaccel_DW.obj_l.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 5; i++) {
      b_zeroDelimTopic_4[i] = tmp_8[i];
    }

    b_zeroDelimTopic_4[5] = '\x00';
    Pub_explicitaccel_microaccel_657.createPublisher(&b_zeroDelimTopic_4[0], 1);
    explicitaccel_microaccel_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S21>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish8'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish9'
    // Start for MATLABSystem: '<S22>/SinkBlock'
    explicitaccel_microaccel_DW.obj_h.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_h.isInitialized = 1;
    for (int32_T i = 0; i < 5; i++) {
      b_zeroDelimTopic_4[i] = tmp_9[i];
    }

    b_zeroDelimTopic_4[5] = '\x00';
    Pub_explicitaccel_microaccel_660.createPublisher(&b_zeroDelimTopic_4[0], 1);
    explicitaccel_microaccel_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S22>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish9'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish6'
    // Start for MATLABSystem: '<S19>/SinkBlock'
    explicitaccel_microaccel_DW.obj_g.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_g.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      explicitaccel_microaccel_B.b_zeroDelimTopic[i] = tmp_a[i];
    }

    explicitaccel_microaccel_B.b_zeroDelimTopic[15] = '\x00';
    Pub_explicitaccel_microaccel_635.createPublisher
      (&explicitaccel_microaccel_B.b_zeroDelimTopic[0], 1);
    explicitaccel_microaccel_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S19>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish6'

    // Start for MATLABSystem: '<S1>/Get Parameter'
    explicitaccel_microaccel_DW.obj_e.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_e.isInitialized = 1;
    for (int32_T i = 0; i < 16; i++) {
      explicitaccel_microaccel_B.b_zeroDelimName[i] = tmp_b[i];
    }

    explicitaccel_microaccel_B.b_zeroDelimName[16] = '\x00';
    ParamGet_explicitaccel_microaccel_585.initialize
      (&explicitaccel_microaccel_B.b_zeroDelimName[0]);
    ParamGet_explicitaccel_microaccel_585.initialize_error_codes(0, 1, 2, 3);
    ParamGet_explicitaccel_microaccel_585.set_initial_value(-4.5);
    explicitaccel_microaccel_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/Get Parameter'

    // Start for MATLABSystem: '<S1>/Get Parameter1'
    explicitaccel_microaccel_DW.obj_k.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj_k.isInitialized = 1;
    for (int32_T i = 0; i < 16; i++) {
      explicitaccel_microaccel_B.b_zeroDelimName[i] = tmp_c[i];
    }

    explicitaccel_microaccel_B.b_zeroDelimName[16] = '\x00';
    ParamGet_explicitaccel_microaccel_631.initialize
      (&explicitaccel_microaccel_B.b_zeroDelimName[0]);
    ParamGet_explicitaccel_microaccel_631.initialize_error_codes(0, 1, 2, 3);
    ParamGet_explicitaccel_microaccel_631.set_initial_value(false);
    explicitaccel_microaccel_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/Get Parameter1'

    // Start for MATLABSystem: '<S1>/Current Time2'
    explicitaccel_microaccel_DW.obj.matlabCodegenIsDeleted = false;
    explicitaccel_microaccel_DW.obj.isInitialized = 1;
    explicitaccel_microaccel_DW.obj.isSetupComplete = true;
  }
}

// Model terminate function
void explicitaccel_microaccel_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S1>/Subscribe4'
  // Terminate for MATLABSystem: '<S24>/SourceBlock'
  if (!explicitaccel_microaccel_DW.obj_hq.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_hq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S24>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe4'

  // Terminate for Atomic SubSystem: '<S1>/Subscribe8'
  // Terminate for MATLABSystem: '<S26>/SourceBlock'
  if (!explicitaccel_microaccel_DW.obj_ke.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_ke.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe8'

  // Terminate for Atomic SubSystem: '<S1>/Publish1'
  // Terminate for MATLABSystem: '<S14>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_c.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish1'

  // Terminate for Atomic SubSystem: '<S1>/Subscribe6'
  // Terminate for MATLABSystem: '<S25>/SourceBlock'
  if (!explicitaccel_microaccel_DW.obj_n0.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_n0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S25>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe6'

  // Terminate for MATLABSystem: '<S1>/Get Parameter'
  if (!explicitaccel_microaccel_DW.obj_e.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Get Parameter'

  // Terminate for Atomic SubSystem: '<S1>/Subscribe'
  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!explicitaccel_microaccel_DW.obj_ep.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_ep.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe'

  // Terminate for MATLABSystem: '<S1>/Get Parameter1'
  if (!explicitaccel_microaccel_DW.obj_k.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Get Parameter1'

  // Terminate for MATLABSystem: '<S1>/Current Time2'
  if (!explicitaccel_microaccel_DW.obj.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Current Time2'

  // Terminate for Atomic SubSystem: '<S1>/Publish2'
  // Terminate for MATLABSystem: '<S15>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_n5.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_n5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish2'

  // Terminate for Atomic SubSystem: '<S1>/Publish3'
  // Terminate for MATLABSystem: '<S16>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_nb.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_nb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish3'

  // Terminate for Atomic SubSystem: '<S1>/Publish4'
  // Terminate for MATLABSystem: '<S17>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_nj.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_nj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish4'

  // Terminate for Atomic SubSystem: '<S1>/Publish5'
  // Terminate for MATLABSystem: '<S18>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_n.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish5'

  // Terminate for Atomic SubSystem: '<S1>/Publish7'
  // Terminate for MATLABSystem: '<S20>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_b.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S20>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish7'

  // Terminate for Atomic SubSystem: '<S1>/Publish8'
  // Terminate for MATLABSystem: '<S21>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_l.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish8'

  // Terminate for Atomic SubSystem: '<S1>/Publish9'
  // Terminate for MATLABSystem: '<S22>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_h.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S22>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish9'

  // Terminate for Atomic SubSystem: '<S1>/Publish6'
  // Terminate for MATLABSystem: '<S19>/SinkBlock'
  if (!explicitaccel_microaccel_DW.obj_g.matlabCodegenIsDeleted) {
    explicitaccel_microaccel_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish6'
}

//
// File trailer for generated code.
//
// [EOF]
//
