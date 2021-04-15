/*
 * ACC_LaneControl_2018version.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ACC_LaneControl_2018version".
 *
 * Model version              : 2.9
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Apr 12 05:04:31 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC_LaneControl_2018version.h"
#include "ACC_LaneControl_2018version_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define ACC_LaneCont_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ACC_LaneContr_IN_ManualOverride ((uint8_T)3U)
#define ACC_LaneContr_IN_Manul_Override ((uint8_T)3U)
#define ACC_LaneContro_IN_ManualControl ((uint8_T)2U)
#define ACC_LaneControl_2018_IN_Warning ((uint8_T)3U)
#define ACC_LaneControl_2018v_IN_Active ((uint8_T)1U)
#define ACC_LaneControl_2018v_IN_Cruise ((uint8_T)3U)
#define ACC_LaneControl_2018v_IN_Follow ((uint8_T)1U)
#define ACC_LaneControl_2018ve_IN_Abort ((uint8_T)1U)
#define ACC_LaneControl_2018ve_IN_Brake ((uint8_T)2U)
#define ACC_LaneControl_2018ver_IN_Free ((uint8_T)2U)
#define ACC_LaneControl_2018ver_IN_Gap1 ((uint8_T)1U)
#define ACC_LaneControl_2018ver_IN_Gap2 ((uint8_T)2U)
#define ACC_LaneControl_2018ver_IN_Gap3 ((uint8_T)3U)
#define ACC_LaneControl_2018ver_IN_Gap4 ((uint8_T)4U)
#define ACC_LaneControl_2018ver_IN_Gap5 ((uint8_T)5U)
#define ACC_LaneControl_2018ver_IN_Gap6 ((uint8_T)6U)
#define ACC_LaneControl_201_IN_Continue ((uint8_T)2U)
#define ACC_LaneControl_201_IN_Inactive ((uint8_T)2U)
#define ACC_LaneControl_20_IN_Attentive ((uint8_T)1U)
#define ACC_LaneControl_20_IN_EngineOff ((uint8_T)1U)
#define ACC_LaneControl_20_IN_Engine_ON ((uint8_T)2U)
#define ACC_LaneControl_2_IN_Accelerate ((uint8_T)1U)
#define ACC_LaneControl_IN_CruiseCntrol ((uint8_T)1U)
#define ACC_LaneControl_IN_Intermediate ((uint8_T)2U)
#define ACC_LaneControl__IN_InAttentive ((uint8_T)2U)
#define ACC_LaneControl__IN_VehicleStop ((uint8_T)4U)

/* Block states (default storage) */
DW_ACC_LaneControl_2018versio_T ACC_LaneControl_2018version_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ACC_LaneControl_2018vers_T ACC_LaneControl_2018version_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ACC_LaneControl_2018vers_T ACC_LaneControl_2018version_Y;

/* Real-time model */
static RT_MODEL_ACC_LaneControl_2018_T ACC_LaneControl_2018version_M_;
RT_MODEL_ACC_LaneControl_2018_T *const ACC_LaneControl_2018version_M =
  &ACC_LaneControl_2018version_M_;

/* Forward declaration for local functions */
static void ACC_LaneControl_2018versi_Drive(void);
static void ACC_LaneCo_exit_internal_Active(void);
static void ACC_LaneControl__Lane_centering(void);
boolean_T sMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) == 0;
}

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T i;
  int32_T y;
  uint32_T su1;
  uint32_T u2i;
  su1 = u1[n - 1] & 2147483648U;
  if ((u2[n - 1] & 2147483648U) != su1) {
    y = su1 != 0U ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

/* Function for Chart: '<Root>/Chart' */
static void ACC_LaneControl_2018versi_Drive(void)
{
  static const int64m_T tmp = { { 1U, 0U }/* chunks */
  };

  static const int64m_T tmp_0 = { { 0U, 0U }/* chunks */
  };

  switch (ACC_LaneControl_2018version_DW.is_Drive) {
   case ACC_LaneControl_IN_CruiseCntrol:
    /* Outport: '<Root>/cruise' */
    ACC_LaneControl_2018version_Y.cruise = 1.0;

    /* Inport: '<Root>/CC' incorporates:
     *  Inport: '<Root>/GasPedal'
     *  Inport: '<Root>/MBrake'
     *  Inport: '<Root>/Speed'
     */
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.CC.chunks[0U],
                     &tmp_0.chunks[0U], 2) || sMultiWordEq
        (&ACC_LaneControl_2018version_U.MBrake.chunks[0U], &tmp.chunks[0U], 2))
    {
      switch (ACC_LaneControl_2018version_DW.is_CruiseCntrol) {
       case ACC_LaneControl_2_IN_Accelerate:
        /* Outport: '<Root>/accelerate' */
        ACC_LaneControl_2018version_Y.accelerate = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneControl_2018ve_IN_Brake:
        /* Outport: '<Root>/brake' */
        ACC_LaneControl_2018version_Y.brake = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneControl_2018v_IN_Cruise:
        /* Outport: '<Root>/Nominal_Cruise' */
        ACC_LaneControl_2018version_Y.Nominal_Cruise = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       default:
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;
      }

      ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneContro_IN_ManualControl;

      /* Outport: '<Root>/cruise' */
      ACC_LaneControl_2018version_Y.cruise = 0.0;
    } else if (sMultiWordEq(&ACC_LaneControl_2018version_U.GasPedal.chunks[0U],
                            &tmp.chunks[0U], 2)) {
      switch (ACC_LaneControl_2018version_DW.is_CruiseCntrol) {
       case ACC_LaneControl_2_IN_Accelerate:
        /* Outport: '<Root>/accelerate' */
        ACC_LaneControl_2018version_Y.accelerate = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneControl_2018ve_IN_Brake:
        /* Outport: '<Root>/brake' */
        ACC_LaneControl_2018version_Y.brake = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneControl_2018v_IN_Cruise:
        /* Outport: '<Root>/Nominal_Cruise' */
        ACC_LaneControl_2018version_Y.Nominal_Cruise = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       default:
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;
      }

      ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneContr_IN_ManualOverride;

      /* Outport: '<Root>/OverRide' */
      ACC_LaneControl_2018version_Y.OverRide = 1.0;
    } else if (ACC_LaneControl_2018version_U.Speed == 0.0) {
      switch (ACC_LaneControl_2018version_DW.is_CruiseCntrol) {
       case ACC_LaneControl_2_IN_Accelerate:
        /* Outport: '<Root>/accelerate' */
        ACC_LaneControl_2018version_Y.accelerate = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneControl_2018ve_IN_Brake:
        /* Outport: '<Root>/brake' */
        ACC_LaneControl_2018version_Y.brake = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneControl_2018v_IN_Cruise:
        /* Outport: '<Root>/Nominal_Cruise' */
        ACC_LaneControl_2018version_Y.Nominal_Cruise = 0.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       default:
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;
      }

      ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneControl__IN_VehicleStop;
    } else {
      switch (ACC_LaneControl_2018version_DW.is_CruiseCntrol) {
       case ACC_LaneControl_2_IN_Accelerate:
        /* Inport: '<Root>/Speed' incorporates:
         *  Inport: '<Root>/Headway'
         *  Inport: '<Root>/Target'
         */
        if (ACC_LaneControl_2018version_U.Speed ==
            ACC_LaneControl_2018version_U.Target) {
          /* Outport: '<Root>/accelerate' */
          ACC_LaneControl_2018version_Y.accelerate = 0.0;
          ACC_LaneControl_2018version_DW.is_CruiseCntrol =
            ACC_LaneControl_2018v_IN_Cruise;

          /* Outport: '<Root>/Nominal_Cruise' */
          ACC_LaneControl_2018version_Y.Nominal_Cruise = 1.0;
        } else {
          if ((ACC_LaneControl_2018version_U.Speed >
               ACC_LaneControl_2018version_U.Target) ||
              (ACC_LaneControl_2018version_U.Headway < 0.0)) {
            /* Outport: '<Root>/accelerate' */
            ACC_LaneControl_2018version_Y.accelerate = 0.0;
            ACC_LaneControl_2018version_DW.is_CruiseCntrol =
              ACC_LaneControl_2018ve_IN_Brake;

            /* Outport: '<Root>/brake' */
            ACC_LaneControl_2018version_Y.brake = 1.0;
          }
        }
        break;

       case ACC_LaneControl_2018ve_IN_Brake:
        /* Inport: '<Root>/Speed' incorporates:
         *  Inport: '<Root>/Headway'
         *  Inport: '<Root>/Target'
         */
        if ((ACC_LaneControl_2018version_U.Speed <
             ACC_LaneControl_2018version_U.Target) &&
            (ACC_LaneControl_2018version_U.Headway > 0.0)) {
          /* Outport: '<Root>/brake' */
          ACC_LaneControl_2018version_Y.brake = 0.0;
          ACC_LaneControl_2018version_DW.is_CruiseCntrol =
            ACC_LaneControl_2_IN_Accelerate;

          /* Outport: '<Root>/accelerate' */
          ACC_LaneControl_2018version_Y.accelerate = 1.0;
        } else {
          if ((ACC_LaneControl_2018version_U.Speed ==
               ACC_LaneControl_2018version_U.Target) ||
              (ACC_LaneControl_2018version_U.Headway >= 0.0)) {
            /* Outport: '<Root>/brake' */
            ACC_LaneControl_2018version_Y.brake = 0.0;
            ACC_LaneControl_2018version_DW.is_CruiseCntrol =
              ACC_LaneControl_2018v_IN_Cruise;

            /* Outport: '<Root>/Nominal_Cruise' */
            ACC_LaneControl_2018version_Y.Nominal_Cruise = 1.0;
          }
        }
        break;

       default:
        /* Inport: '<Root>/Speed' incorporates:
         *  Inport: '<Root>/Headway'
         *  Inport: '<Root>/Target'
         */
        /* case IN_Cruise: */
        if ((ACC_LaneControl_2018version_U.Speed <
             ACC_LaneControl_2018version_U.Target) &&
            (ACC_LaneControl_2018version_U.Headway > 5.0)) {
          /* Outport: '<Root>/Nominal_Cruise' */
          ACC_LaneControl_2018version_Y.Nominal_Cruise = 0.0;
          ACC_LaneControl_2018version_DW.is_CruiseCntrol =
            ACC_LaneControl_2_IN_Accelerate;

          /* Outport: '<Root>/accelerate' */
          ACC_LaneControl_2018version_Y.accelerate = 1.0;
        } else {
          if ((ACC_LaneControl_2018version_U.Speed >
               ACC_LaneControl_2018version_U.Target) ||
              (ACC_LaneControl_2018version_U.Headway < 0.0)) {
            /* Outport: '<Root>/Nominal_Cruise' */
            ACC_LaneControl_2018version_Y.Nominal_Cruise = 0.0;
            ACC_LaneControl_2018version_DW.is_CruiseCntrol =
              ACC_LaneControl_2018ve_IN_Brake;

            /* Outport: '<Root>/brake' */
            ACC_LaneControl_2018version_Y.brake = 1.0;
          }
        }
        break;
      }
    }
    break;

   case ACC_LaneContro_IN_ManualControl:
    /* Outport: '<Root>/cruise' */
    ACC_LaneControl_2018version_Y.cruise = 0.0;

    /* Inport: '<Root>/CC' incorporates:
     *  Inport: '<Root>/MBrake'
     */
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.CC.chunks[0U], &tmp.chunks
                     [0U], 2) && sMultiWordEq
        (&ACC_LaneControl_2018version_U.MBrake.chunks[0U], &tmp_0.chunks[0U], 2))
    {
      ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneControl_IN_CruiseCntrol;

      /* Outport: '<Root>/cruise' */
      ACC_LaneControl_2018version_Y.cruise = 1.0;
      ACC_LaneControl_2018version_DW.is_CruiseCntrol =
        ACC_LaneControl_2018v_IN_Cruise;

      /* Outport: '<Root>/Nominal_Cruise' */
      ACC_LaneControl_2018version_Y.Nominal_Cruise = 1.0;
    }
    break;

   case ACC_LaneContr_IN_ManualOverride:
    /* Inport: '<Root>/MBrake' incorporates:
     *  Inport: '<Root>/CC'
     *  Inport: '<Root>/GasPedal'
     */
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.MBrake.chunks[0U],
                     &tmp.chunks[0U], 2) || sMultiWordEq
        (&ACC_LaneControl_2018version_U.CC.chunks[0U], &tmp_0.chunks[0U], 2)) {
      /* Outport: '<Root>/OverRide' */
      ACC_LaneControl_2018version_Y.OverRide = 0.0;
      ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneContro_IN_ManualControl;

      /* Outport: '<Root>/cruise' */
      ACC_LaneControl_2018version_Y.cruise = 0.0;
    } else {
      if (sMultiWordEq(&ACC_LaneControl_2018version_U.GasPedal.chunks[0U],
                       &tmp_0.chunks[0U], 2)) {
        /* Outport: '<Root>/OverRide' */
        ACC_LaneControl_2018version_Y.OverRide = 0.0;
        ACC_LaneControl_2018version_DW.is_Drive =
          ACC_LaneControl_IN_CruiseCntrol;

        /* Outport: '<Root>/cruise' */
        ACC_LaneControl_2018version_Y.cruise = 1.0;
        ACC_LaneControl_2018version_DW.is_CruiseCntrol =
          ACC_LaneControl_2018v_IN_Cruise;

        /* Outport: '<Root>/Nominal_Cruise' */
        ACC_LaneControl_2018version_Y.Nominal_Cruise = 1.0;
      }
    }
    break;

   default:
    /* Inport: '<Root>/GasPedal' incorporates:
     *  Inport: '<Root>/CC'
     *  Inport: '<Root>/MBrake'
     */
    /* case IN_VehicleStop: */
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.GasPedal.chunks[0U],
                     &tmp.chunks[0U], 2)) {
      ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneControl_IN_CruiseCntrol;

      /* Outport: '<Root>/cruise' */
      ACC_LaneControl_2018version_Y.cruise = 1.0;
      ACC_LaneControl_2018version_DW.is_CruiseCntrol =
        ACC_LaneControl_2018v_IN_Cruise;

      /* Outport: '<Root>/Nominal_Cruise' */
      ACC_LaneControl_2018version_Y.Nominal_Cruise = 1.0;
    } else {
      if (sMultiWordEq(&ACC_LaneControl_2018version_U.MBrake.chunks[0U],
                       &tmp.chunks[0U], 2) || sMultiWordEq
          (&ACC_LaneControl_2018version_U.CC.chunks[0U], &tmp_0.chunks[0U], 2))
      {
        ACC_LaneControl_2018version_DW.is_Drive =
          ACC_LaneContro_IN_ManualControl;

        /* Outport: '<Root>/cruise' */
        ACC_LaneControl_2018version_Y.cruise = 0.0;
      }
    }
    break;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void ACC_LaneCo_exit_internal_Active(void)
{
  ACC_LaneControl_2018version_DW.is_Execution = ACC_LaneCont_IN_NO_ACTIVE_CHILD;

  /* Outport: '<Root>/LaneChanged' */
  ACC_LaneControl_2018version_Y.LaneChanged = 0.0;
  ACC_LaneControl_2018version_DW.is_Need = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  if (ACC_LaneControl_2018version_DW.is_DriverActive ==
      ACC_LaneControl_2018_IN_Warning) {
    /* Outport: '<Root>/warningMsg' */
    ACC_LaneControl_2018version_Y.warningMsg = 0.0;
    ACC_LaneControl_2018version_DW.is_DriverActive =
      ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  } else {
    ACC_LaneControl_2018version_DW.is_DriverActive =
      ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  }

  if (ACC_LaneControl_2018version_DW.is_LC_Level ==
      ACC_LaneContr_IN_Manul_Override) {
    /* Outport: '<Root>/warningMsg' */
    ACC_LaneControl_2018version_Y.warningMsg = 0.0;
    ACC_LaneControl_2018version_DW.is_LC_Level = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  } else {
    ACC_LaneControl_2018version_DW.is_LC_Level = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void ACC_LaneControl__Lane_centering(void)
{
  static const int64m_T tmp = { { 2U, 0U }/* chunks */
  };

  static const int64m_T tmp_0 = { { 1U, 0U }/* chunks */
  };

  static const int64m_T tmp_1 = { { 0U, 0U }/* chunks */
  };

  const int64m_T *tmp_2;
  if (ACC_LaneControl_2018version_DW.is_Lane_centering ==
      ACC_LaneControl_2018v_IN_Active) {
    /* Outport: '<Root>/LCentering' */
    ACC_LaneControl_2018version_Y.LCentering = 1.0;
    tmp_2 = &tmp_1;

    /* Inport: '<Root>/LC' incorporates:
     *  Inport: '<Root>/CC'
     */
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.LC.chunks[0U],
                     &tmp_2->chunks[0U], 2) || sMultiWordEq
        (&ACC_LaneControl_2018version_U.CC.chunks[0U], &tmp_1.chunks[0U], 2)) {
      ACC_LaneCo_exit_internal_Active();
      ACC_LaneControl_2018version_DW.is_Lane_centering =
        ACC_LaneControl_201_IN_Inactive;

      /* Outport: '<Root>/LCentering' */
      ACC_LaneControl_2018version_Y.LCentering = 0.0;
    } else {
      switch (ACC_LaneControl_2018version_DW.is_LC_Level) {
       case ACC_LaneControl_2018v_IN_Active:
        /* Outport: '<Root>/LC_active' */
        ACC_LaneControl_2018version_Y.LC_active = 1.0;

        /* Outport: '<Root>/LC_override' */
        ACC_LaneControl_2018version_Y.LC_override = 0.0;

        /* Outport: '<Root>/LC_intermediate' */
        ACC_LaneControl_2018version_Y.LC_intermediate = 0.0;

        /* Inport: '<Root>/MStreer' incorporates:
         *  Inport: '<Root>/Signal'
         */
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.MStreer.chunks[0U],
                         &tmp_0.chunks[0U], 2) || sMultiWordEq
            (&ACC_LaneControl_2018version_U.Signal.chunks[0U], &tmp_1.chunks[0U],
             2)) {
          ACC_LaneControl_2018version_DW.is_LC_Level =
            ACC_LaneContr_IN_Manul_Override;

          /* Outport: '<Root>/LC_override' */
          ACC_LaneControl_2018version_Y.LC_override = 1.0;

          /* Outport: '<Root>/LC_active' */
          ACC_LaneControl_2018version_Y.LC_active = 0.0;

          /* Outport: '<Root>/LC_intermediate' */
          ACC_LaneControl_2018version_Y.LC_intermediate = 0.0;
          if (sMultiWordEq(&ACC_LaneControl_2018version_U.Signal.chunks[0U],
                           &tmp_1.chunks[0U], 2)) {
            /* Outport: '<Root>/warningMsg' */
            ACC_LaneControl_2018version_Y.warningMsg = 2.0;
          }
        } else {
          if (sMultiWordEq(&ACC_LaneControl_2018version_U.Signal.chunks[0U],
                           &tmp_0.chunks[0U], 2)) {
            ACC_LaneControl_2018version_DW.is_LC_Level =
              ACC_LaneControl_IN_Intermediate;

            /* Outport: '<Root>/LC_intermediate' */
            ACC_LaneControl_2018version_Y.LC_intermediate = 1.0;

            /* Outport: '<Root>/LC_active' */
            ACC_LaneControl_2018version_Y.LC_active = 0.0;

            /* Outport: '<Root>/LC_override' */
            ACC_LaneControl_2018version_Y.LC_override = 0.0;
          }
        }
        break;

       case ACC_LaneControl_IN_Intermediate:
        /* Outport: '<Root>/LC_intermediate' */
        ACC_LaneControl_2018version_Y.LC_intermediate = 1.0;

        /* Outport: '<Root>/LC_active' */
        ACC_LaneControl_2018version_Y.LC_active = 0.0;

        /* Outport: '<Root>/LC_override' */
        ACC_LaneControl_2018version_Y.LC_override = 0.0;

        /* Inport: '<Root>/Signal' incorporates:
         *  Inport: '<Root>/MStreer'
         */
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.Signal.chunks[0U],
                         &tmp.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_LC_Level =
            ACC_LaneControl_2018v_IN_Active;

          /* Outport: '<Root>/LC_active' */
          ACC_LaneControl_2018version_Y.LC_active = 1.0;

          /* Outport: '<Root>/LC_override' */
          ACC_LaneControl_2018version_Y.LC_override = 0.0;

          /* Outport: '<Root>/LC_intermediate' */
          ACC_LaneControl_2018version_Y.LC_intermediate = 0.0;
        } else {
          if (sMultiWordEq(&ACC_LaneControl_2018version_U.MStreer.chunks[0U],
                           &tmp_0.chunks[0U], 2) || sMultiWordEq
              (&ACC_LaneControl_2018version_U.Signal.chunks[0U], &tmp_1.chunks
               [0U], 2)) {
            ACC_LaneControl_2018version_DW.is_LC_Level =
              ACC_LaneContr_IN_Manul_Override;

            /* Outport: '<Root>/LC_override' */
            ACC_LaneControl_2018version_Y.LC_override = 1.0;

            /* Outport: '<Root>/LC_active' */
            ACC_LaneControl_2018version_Y.LC_active = 0.0;

            /* Outport: '<Root>/LC_intermediate' */
            ACC_LaneControl_2018version_Y.LC_intermediate = 0.0;
            if (sMultiWordEq(&ACC_LaneControl_2018version_U.Signal.chunks[0U],
                             &tmp_1.chunks[0U], 2)) {
              /* Outport: '<Root>/warningMsg' */
              ACC_LaneControl_2018version_Y.warningMsg = 2.0;
            }
          }
        }
        break;

       default:
        /* Outport: '<Root>/LC_override' */
        /* case IN_Manul_Override: */
        ACC_LaneControl_2018version_Y.LC_override = 1.0;

        /* Outport: '<Root>/LC_active' */
        ACC_LaneControl_2018version_Y.LC_active = 0.0;

        /* Outport: '<Root>/LC_intermediate' */
        ACC_LaneControl_2018version_Y.LC_intermediate = 0.0;

        /* Inport: '<Root>/MStreer' incorporates:
         *  Inport: '<Root>/Signal'
         */
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.MStreer.chunks[0U],
                         &tmp_1.chunks[0U], 2) && sMultiWordEq
            (&ACC_LaneControl_2018version_U.Signal.chunks[0U], &tmp.chunks[0U],
             2)) {
          /* Outport: '<Root>/warningMsg' */
          ACC_LaneControl_2018version_Y.warningMsg = 0.0;
          ACC_LaneControl_2018version_DW.is_LC_Level =
            ACC_LaneControl_2018v_IN_Active;

          /* Outport: '<Root>/LC_active' */
          ACC_LaneControl_2018version_Y.LC_active = 1.0;

          /* Outport: '<Root>/LC_override' */
          ACC_LaneControl_2018version_Y.LC_override = 0.0;

          /* Outport: '<Root>/LC_intermediate' */
          ACC_LaneControl_2018version_Y.LC_intermediate = 0.0;
        } else {
          if (sMultiWordEq(&ACC_LaneControl_2018version_U.MStreer.chunks[0U],
                           &tmp_1.chunks[0U], 2) && sMultiWordEq
              (&ACC_LaneControl_2018version_U.Signal.chunks[0U], &tmp_0.chunks
               [0U], 2)) {
            /* Outport: '<Root>/warningMsg' */
            ACC_LaneControl_2018version_Y.warningMsg = 0.0;
            ACC_LaneControl_2018version_DW.is_LC_Level =
              ACC_LaneControl_IN_Intermediate;

            /* Outport: '<Root>/LC_intermediate' */
            ACC_LaneControl_2018version_Y.LC_intermediate = 1.0;

            /* Outport: '<Root>/LC_active' */
            ACC_LaneControl_2018version_Y.LC_active = 0.0;

            /* Outport: '<Root>/LC_override' */
            ACC_LaneControl_2018version_Y.LC_override = 0.0;
          }
        }
        break;
      }

      switch (ACC_LaneControl_2018version_DW.is_DriverActive) {
       case ACC_LaneControl_20_IN_Attentive:
        /* Inport: '<Root>/SteeringHeld' */
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.SteeringHeld.chunks[0U],
                         &tmp_1.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_DriverActive =
            ACC_LaneControl__IN_InAttentive;
          ACC_LaneControl_2018version_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/warningMsg' */
          ACC_LaneControl_2018version_Y.warningMsg = 0.0;
        }
        break;

       case ACC_LaneControl__IN_InAttentive:
        /* Inport: '<Root>/SteeringHeld' */
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.SteeringHeld.chunks[0U],
                         &tmp_0.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_DriverActive =
            ACC_LaneControl_20_IN_Attentive;

          /* Outport: '<Root>/warningMsg' */
          ACC_LaneControl_2018version_Y.warningMsg = 0.0;
        } else {
          if (ACC_LaneControl_2018version_DW.temporalCounter_i1 >= 7U) {
            ACC_LaneControl_2018version_DW.is_DriverActive =
              ACC_LaneControl_2018_IN_Warning;

            /* Outport: '<Root>/warningMsg' */
            ACC_LaneControl_2018version_Y.warningMsg = 1.0;
          }
        }
        break;

       default:
        /* Inport: '<Root>/SteeringHeld' */
        /* case IN_Warning: */
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.SteeringHeld.chunks[0U],
                         &tmp_0.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_DriverActive =
            ACC_LaneControl_20_IN_Attentive;

          /* Outport: '<Root>/warningMsg' */
          ACC_LaneControl_2018version_Y.warningMsg = 0.0;
        }
        break;
      }

      if (ACC_LaneControl_2018version_DW.is_Need ==
          ACC_LaneControl_2018v_IN_Follow) {
        /* Inport: '<Root>/Speed' incorporates:
         *  Inport: '<Root>/Headway'
         *  Inport: '<Root>/Target'
         */
        if ((ACC_LaneControl_2018version_U.Speed ==
             ACC_LaneControl_2018version_U.Target) ||
            (ACC_LaneControl_2018version_U.Headway >= 5.0)) {
          ACC_LaneControl_2018version_DW.is_Need =
            ACC_LaneControl_2018ver_IN_Free;
          ACC_LaneControl_2018version_DW.LC_Needed = 0.0;
        }
      } else {
        /* Outport: '<Root>/Nominal_Cruise' incorporates:
         *  Inport: '<Root>/Speed'
         *  Inport: '<Root>/Target'
         *  Outport: '<Root>/brake'
         */
        /* case IN_Free: */
        if (((ACC_LaneControl_2018version_Y.Nominal_Cruise == 1.0) ||
             (ACC_LaneControl_2018version_Y.brake == 1.0)) &&
            (ACC_LaneControl_2018version_U.Speed <
             ACC_LaneControl_2018version_U.Target)) {
          ACC_LaneControl_2018version_DW.is_Need =
            ACC_LaneControl_2018v_IN_Follow;
          ACC_LaneControl_2018version_DW.LC_Needed = 1.0;
        }

        /* End of Outport: '<Root>/Nominal_Cruise' */
      }

      if (ACC_LaneControl_2018version_DW.is_Execution ==
          ACC_LaneControl_2018ve_IN_Abort) {
        tmp_2 = &tmp_1;

        /* Inport: '<Root>/L_CarDetected' incorporates:
         *  Inport: '<Root>/R_CarDetected'
         */
        if ((ACC_LaneControl_2018version_DW.LC_Needed == 1.0) && (sMultiWordEq
             (&ACC_LaneControl_2018version_U.L_CarDetected.chunks[0U],
              &tmp_2->chunks[0U], 2) || sMultiWordEq
             (&ACC_LaneControl_2018version_U.R_CarDetected.chunks[0U],
              &tmp_1.chunks[0U], 2))) {
          ACC_LaneControl_2018version_DW.is_Execution =
            ACC_LaneControl_201_IN_Continue;

          /* Outport: '<Root>/LaneChanged' */
          ACC_LaneControl_2018version_Y.LaneChanged = 1.0;

          /* Outport: '<Root>/action' incorporates:
           *  Outport: '<Root>/DeltaLane'
           */
          ACC_LaneControl_2018version_Y.action =
            ACC_LaneControl_2018version_Y.DeltaLane;
        }
      } else {
        /* case IN_Continue: */
        tmp_2 = &tmp_0;

        /* Inport: '<Root>/L_CarDetected' incorporates:
         *  Inport: '<Root>/R_CarDetected'
         *  Outport: '<Root>/LC_override'
         *  Outport: '<Root>/LaneChanged'
         *  Outport: '<Root>/action'
         */
        if ((ACC_LaneControl_2018version_DW.LC_Needed == 0.0) || (sMultiWordEq
             (&ACC_LaneControl_2018version_U.L_CarDetected.chunks[0U],
              &tmp_2->chunks[0U], 2) && sMultiWordEq
             (&ACC_LaneControl_2018version_U.R_CarDetected.chunks[0U],
              &tmp_0.chunks[0U], 2)) ||
            (ACC_LaneControl_2018version_Y.LC_override == 1.0)) {
          ACC_LaneControl_2018version_DW.is_Execution =
            ACC_LaneControl_2018ve_IN_Abort;
          ACC_LaneControl_2018version_Y.LaneChanged = 0.0;
          ACC_LaneControl_2018version_Y.action = 0.0;
        }
      }
    }
  } else {
    /* Outport: '<Root>/LCentering' */
    /* case IN_Inactive: */
    ACC_LaneControl_2018version_Y.LCentering = 0.0;
    tmp_2 = &tmp_0;

    /* Inport: '<Root>/LC' incorporates:
     *  Inport: '<Root>/CC'
     */
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.LC.chunks[0U],
                     &tmp_2->chunks[0U], 2) && sMultiWordEq
        (&ACC_LaneControl_2018version_U.CC.chunks[0U], &tmp_0.chunks[0U], 2)) {
      ACC_LaneControl_2018version_DW.is_Lane_centering =
        ACC_LaneControl_2018v_IN_Active;

      /* Outport: '<Root>/LCentering' */
      ACC_LaneControl_2018version_Y.LCentering = 1.0;
      ACC_LaneControl_2018version_DW.is_LC_Level =
        ACC_LaneControl_2018v_IN_Active;

      /* Outport: '<Root>/LC_active' */
      ACC_LaneControl_2018version_Y.LC_active = 1.0;

      /* Outport: '<Root>/LC_override' */
      ACC_LaneControl_2018version_Y.LC_override = 0.0;

      /* Outport: '<Root>/LC_intermediate' */
      ACC_LaneControl_2018version_Y.LC_intermediate = 0.0;
      ACC_LaneControl_2018version_DW.is_DriverActive =
        ACC_LaneControl_20_IN_Attentive;

      /* Outport: '<Root>/warningMsg' */
      ACC_LaneControl_2018version_Y.warningMsg = 0.0;
      ACC_LaneControl_2018version_DW.is_Need = ACC_LaneControl_2018ver_IN_Free;
      ACC_LaneControl_2018version_DW.LC_Needed = 0.0;

      /* Inport: '<Root>/L_CarDetected' incorporates:
       *  Inport: '<Root>/L_Shift'
       *  Inport: '<Root>/R_CarDetected'
       *  Inport: '<Root>/R_Shift'
       */
      if (sMultiWordEq(&ACC_LaneControl_2018version_U.L_CarDetected.chunks[0U],
                       &tmp_1.chunks[0U], 2) || sMultiWordEq
          (&ACC_LaneControl_2018version_U.L_Shift.chunks[0U], &tmp_0.chunks[0U],
           2)) {
        /* SystemInitialize for Outport: '<Root>/DeltaLane' */
        ACC_LaneControl_2018version_Y.DeltaLane = 1.0;
      } else {
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.R_CarDetected.chunks[0U],
                         &tmp_1.chunks[0U], 2) || sMultiWordEq
            (&ACC_LaneControl_2018version_U.R_Shift.chunks[0U], &tmp_0.chunks[0U],
             2)) {
          /* SystemInitialize for Outport: '<Root>/DeltaLane' */
          ACC_LaneControl_2018version_Y.DeltaLane = -1.0;
        }
      }

      ACC_LaneControl_2018version_DW.is_Execution =
        ACC_LaneControl_2018ve_IN_Abort;

      /* Outport: '<Root>/LaneChanged' */
      ACC_LaneControl_2018version_Y.LaneChanged = 0.0;

      /* Outport: '<Root>/action' */
      ACC_LaneControl_2018version_Y.action = 0.0;
    }
  }
}

/* Model step function */
void ACC_LaneControl_2018version_step(void)
{
  static const int64m_T tmp = { { 1U, 0U }/* chunks */
  };

  static const int64m_T tmp_0 = { { 0U, 0U }/* chunks */
  };

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/GapInc'
   *  Inport: '<Root>/Key'
   */
  if (ACC_LaneControl_2018version_DW.temporalCounter_i1 < 7U) {
    ACC_LaneControl_2018version_DW.temporalCounter_i1++;
  }

  if (ACC_LaneControl_2018version_DW.is_active_c1_ACC_LaneControl_20 == 0U) {
    ACC_LaneControl_2018version_DW.is_active_c1_ACC_LaneControl_20 = 1U;
    ACC_LaneControl_2018version_DW.is_c1_ACC_LaneControl_2018versi =
      ACC_LaneControl_20_IN_EngineOff;
  } else if (ACC_LaneControl_2018version_DW.is_c1_ACC_LaneControl_2018versi ==
             ACC_LaneControl_20_IN_EngineOff) {
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.Key.chunks[0U], &tmp.chunks
                     [0U], 2)) {
      ACC_LaneControl_2018version_DW.is_c1_ACC_LaneControl_2018versi =
        ACC_LaneControl_20_IN_Engine_ON;
      ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneContro_IN_ManualControl;

      /* Outport: '<Root>/cruise' */
      ACC_LaneControl_2018version_Y.cruise = 0.0;
      switch (ACC_LaneControl_2018version_DW.was_Gap) {
       case ACC_LaneControl_2018ver_IN_Gap1:
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap1;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap1;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 20.0;
        break;

       case ACC_LaneControl_2018ver_IN_Gap2:
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap2;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap2;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 40.0;
        break;

       case ACC_LaneControl_2018ver_IN_Gap3:
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap3;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap3;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 60.0;
        break;

       case ACC_LaneControl_2018ver_IN_Gap4:
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap4;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap4;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 80.0;
        break;

       case ACC_LaneControl_2018ver_IN_Gap5:
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap5;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap5;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 100.0;
        break;

       case ACC_LaneControl_2018ver_IN_Gap6:
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap6;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap6;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 120.0;
        break;

       default:
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap1;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap1;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 20.0;
        break;
      }

      ACC_LaneControl_2018version_DW.is_Lane_centering =
        ACC_LaneControl_201_IN_Inactive;

      /* Outport: '<Root>/LCentering' */
      ACC_LaneControl_2018version_Y.LCentering = 0.0;
    }
  } else {
    /* case IN_Engine_ON: */
    if (sMultiWordEq(&ACC_LaneControl_2018version_U.Key.chunks[0U],
                     &tmp_0.chunks[0U], 2)) {
      if (ACC_LaneControl_2018version_DW.is_Lane_centering ==
          ACC_LaneControl_2018v_IN_Active) {
        ACC_LaneCo_exit_internal_Active();
        ACC_LaneControl_2018version_DW.is_Lane_centering =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
      } else {
        ACC_LaneControl_2018version_DW.is_Lane_centering =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
      }

      ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
      switch (ACC_LaneControl_2018version_DW.is_Drive) {
       case ACC_LaneControl_IN_CruiseCntrol:
        switch (ACC_LaneControl_2018version_DW.is_CruiseCntrol) {
         case ACC_LaneControl_2_IN_Accelerate:
          /* Outport: '<Root>/accelerate' */
          ACC_LaneControl_2018version_Y.accelerate = 0.0;
          ACC_LaneControl_2018version_DW.is_CruiseCntrol =
            ACC_LaneCont_IN_NO_ACTIVE_CHILD;
          break;

         case ACC_LaneControl_2018ve_IN_Brake:
          /* Outport: '<Root>/brake' */
          ACC_LaneControl_2018version_Y.brake = 0.0;
          ACC_LaneControl_2018version_DW.is_CruiseCntrol =
            ACC_LaneCont_IN_NO_ACTIVE_CHILD;
          break;

         case ACC_LaneControl_2018v_IN_Cruise:
          /* Outport: '<Root>/Nominal_Cruise' */
          ACC_LaneControl_2018version_Y.Nominal_Cruise = 0.0;
          ACC_LaneControl_2018version_DW.is_CruiseCntrol =
            ACC_LaneCont_IN_NO_ACTIVE_CHILD;
          break;

         default:
          ACC_LaneControl_2018version_DW.is_CruiseCntrol =
            ACC_LaneCont_IN_NO_ACTIVE_CHILD;
          break;
        }

        ACC_LaneControl_2018version_DW.is_Drive =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneContr_IN_ManualOverride:
        /* Outport: '<Root>/OverRide' */
        ACC_LaneControl_2018version_Y.OverRide = 0.0;
        ACC_LaneControl_2018version_DW.is_Drive =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       case ACC_LaneControl__IN_VehicleStop:
        ACC_LaneControl_2018version_DW.is_Drive =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;

       default:
        ACC_LaneControl_2018version_DW.is_Drive =
          ACC_LaneCont_IN_NO_ACTIVE_CHILD;
        break;
      }

      ACC_LaneControl_2018version_DW.is_c1_ACC_LaneControl_2018versi =
        ACC_LaneControl_20_IN_EngineOff;
    } else {
      ACC_LaneControl_2018versi_Drive();
      switch (ACC_LaneControl_2018version_DW.is_Gap) {
       case ACC_LaneControl_2018ver_IN_Gap1:
        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 20.0;
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.GapInc.chunks[0U],
                         &tmp.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap2;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap2;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 40.0;
        }
        break;

       case ACC_LaneControl_2018ver_IN_Gap2:
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.GapInc.chunks[0U],
                         &tmp.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap3;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap3;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 60.0;
        } else {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap1;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap1;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 20.0;
        }
        break;

       case ACC_LaneControl_2018ver_IN_Gap3:
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.GapInc.chunks[0U],
                         &tmp.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap4;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap4;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 80.0;
        } else {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap2;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap2;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 40.0;
        }
        break;

       case ACC_LaneControl_2018ver_IN_Gap4:
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.GapInc.chunks[0U],
                         &tmp.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap5;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap5;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 100.0;
        } else {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap3;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap3;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 60.0;
        }
        break;

       case ACC_LaneControl_2018ver_IN_Gap5:
        if (sMultiWordEq(&ACC_LaneControl_2018version_U.GapInc.chunks[0U],
                         &tmp.chunks[0U], 2)) {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap6;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap6;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 120.0;
        } else {
          ACC_LaneControl_2018version_DW.is_Gap =
            ACC_LaneControl_2018ver_IN_Gap4;
          ACC_LaneControl_2018version_DW.was_Gap =
            ACC_LaneControl_2018ver_IN_Gap4;

          /* Outport: '<Root>/gap' */
          ACC_LaneControl_2018version_Y.gap = 80.0;
        }
        break;

       default:
        /* case IN_Gap6: */
        ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneControl_2018ver_IN_Gap5;
        ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneControl_2018ver_IN_Gap5;

        /* Outport: '<Root>/gap' */
        ACC_LaneControl_2018version_Y.gap = 100.0;
        break;
      }

      ACC_LaneControl__Lane_centering();
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(ACC_LaneControl_2018version_M->rtwLogInfo,
                      (&ACC_LaneControl_2018version_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.3s, 0.0s] */
    if ((rtmGetTFinal(ACC_LaneControl_2018version_M)!=-1) &&
        !((rtmGetTFinal(ACC_LaneControl_2018version_M)-
           ACC_LaneControl_2018version_M->Timing.taskTime0) >
          ACC_LaneControl_2018version_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ACC_LaneControl_2018version_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ACC_LaneControl_2018version_M->Timing.clockTick0)) {
    ++ACC_LaneControl_2018version_M->Timing.clockTickH0;
  }

  ACC_LaneControl_2018version_M->Timing.taskTime0 =
    ACC_LaneControl_2018version_M->Timing.clockTick0 *
    ACC_LaneControl_2018version_M->Timing.stepSize0 +
    ACC_LaneControl_2018version_M->Timing.clockTickH0 *
    ACC_LaneControl_2018version_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void ACC_LaneControl_2018version_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ACC_LaneControl_2018version_M, 0,
                sizeof(RT_MODEL_ACC_LaneControl_2018_T));
  rtmSetTFinal(ACC_LaneControl_2018version_M, 15.0);
  ACC_LaneControl_2018version_M->Timing.stepSize0 = 0.3;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ACC_LaneControl_2018version_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ACC_LaneControl_2018version_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ACC_LaneControl_2018version_M->rtwLogInfo, (NULL));
    rtliSetLogT(ACC_LaneControl_2018version_M->rtwLogInfo, "tout");
    rtliSetLogX(ACC_LaneControl_2018version_M->rtwLogInfo, "");
    rtliSetLogXFinal(ACC_LaneControl_2018version_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ACC_LaneControl_2018version_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ACC_LaneControl_2018version_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(ACC_LaneControl_2018version_M->rtwLogInfo, 0);
    rtliSetLogDecimation(ACC_LaneControl_2018version_M->rtwLogInfo, 1);
    rtliSetLogY(ACC_LaneControl_2018version_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ACC_LaneControl_2018version_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ACC_LaneControl_2018version_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&ACC_LaneControl_2018version_DW, 0,
                sizeof(DW_ACC_LaneControl_2018versio_T));

  /* external inputs */
  (void)memset(&ACC_LaneControl_2018version_U, 0, sizeof
               (ExtU_ACC_LaneControl_2018vers_T));

  /* external outputs */
  (void) memset((void *)&ACC_LaneControl_2018version_Y, 0,
                sizeof(ExtY_ACC_LaneControl_2018vers_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(ACC_LaneControl_2018version_M->rtwLogInfo,
    0.0, rtmGetTFinal(ACC_LaneControl_2018version_M),
    ACC_LaneControl_2018version_M->Timing.stepSize0, (&rtmGetErrorStatus
    (ACC_LaneControl_2018version_M)));

  /* SystemInitialize for Chart: '<Root>/Chart' */
  ACC_LaneControl_2018version_DW.is_Drive = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.is_CruiseCntrol =
    ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.is_Gap = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.was_Gap = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.is_Lane_centering =
    ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.is_DriverActive =
    ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.temporalCounter_i1 = 0U;
  ACC_LaneControl_2018version_DW.is_LC_Level = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.is_Need = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.is_Execution = ACC_LaneCont_IN_NO_ACTIVE_CHILD;
  ACC_LaneControl_2018version_DW.is_active_c1_ACC_LaneControl_20 = 0U;
  ACC_LaneControl_2018version_DW.is_c1_ACC_LaneControl_2018versi =
    ACC_LaneCont_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Outport: '<Root>/accelerate' incorporates:
   *  Chart: '<Root>/Chart'
   */
  ACC_LaneControl_2018version_Y.accelerate = 0.0;

  /* SystemInitialize for Outport: '<Root>/cruise' incorporates:
   *  Chart: '<Root>/Chart'
   */
  ACC_LaneControl_2018version_Y.cruise = 0.0;

  /* SystemInitialize for Outport: '<Root>/brake' incorporates:
   *  Chart: '<Root>/Chart'
   */
  ACC_LaneControl_2018version_Y.brake = 0.0;

  /* SystemInitialize for Outport: '<Root>/Nominal_Cruise' incorporates:
   *  Chart: '<Root>/Chart'
   */
  ACC_LaneControl_2018version_Y.Nominal_Cruise = 1.0;

  /* SystemInitialize for Outport: '<Root>/DeltaLane' incorporates:
   *  Chart: '<Root>/Chart'
   */
  ACC_LaneControl_2018version_Y.DeltaLane = 0.0;
}

/* Model terminate function */
void ACC_LaneControl_2018version_terminate(void)
{
  /* (no terminate code required) */
}
