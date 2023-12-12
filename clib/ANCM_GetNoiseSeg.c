/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetNoiseSeg.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "ANCM_GetNoiseSeg.h"
#include "ANCM_GetDeltaFSt.h"
#include "ANCM_GetGeometryData.h"
#include "ANCM_GetLPdSt.h"
#include "ANCM_GetNoiseSeg_data.h"
#include "ANCM_GetNoiseSeg_emxutil.h"
#include "ANCM_GetNoiseSeg_internal_types.h"
#include "ANCM_GetNoiseSeg_rtwutil.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "cosd.h"
#include "find.h"
#include "ifWhileCond.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "strcmp.h"
#include "validate_print_arguments.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Function Definitions */
/*
 * ANCM_GetLseg Get Segment Event Level Lseg
 * Implements interpolation equations of Section 4.3.1 from  Doc.29, 4th edition, Vol.2
 * IMPORTANT: All coordinates and distance are in FEET (ft)
 * Inputs:
 *   Seg: An struct with the segment data. It has the following fields
 *       S1,S2: Points of the segment of the route
 *       epsilon: bank angle (in Euler angles: phi - roll)
 *       P: Power
 *       Vseg: Speed of the segment
 *       isRolling: the plane is in takeoff roll or landing roll
 *   Ob: Observer location
 *   NPDdataSt: struct array with all the NPD data of the aircraft
 *       Converted directly from the .csv spreadsheet considering as fields the columns names
 *   NoiseMetric, OpMode: to select the data from NPD
 *       It depends on the plane, but NoiseMetric can be 'EPNL', 'LAmax',
 *       'PNLTM' and 'SEL'; and OpMode is 'A' arrival and 'D' descending
 *       In case 'LAmax', the formulas used are different.
 *   Vref: Reference groundspeed for which NPD data are defined
 *   Aircraft: information about the aircraft (an struct)
 *       WingMounted: true -> wing-mounted engine;false -> fuselage mounted
 *       TurboFan: true: turbo-fan propelled, false: turbo-prop propelled
 *   AtmCond: Atmospheric conditions to get the impedance adjustament. Two fields:
 *       p: Ambient air pressure at the observer in KPa
 *       T: Air temperature at the observer altitude (celcius)
 *   Trace: Configure the display of trace (An 8 ubits integer)
 *       bit 0: Show input parameters and results
 *       bit 1: Show all geometric data and correction value
 *       bit 2: Show NPDdataSt
 * Output
 *   Lseg: Segment event noise (in dB)
 *
 *  ANCM: Aircraft Noise Countour Modelling Library.
 *  2022 (c) Universidad Politécnica de Valencia
 *
 * Arguments    : const struct0_T *Seg
 *                const double Ob[3]
 *                const emxArray_struct1_T *NPDdataSt
 *                const char NoiseMetric[3]
 *                char OpMode
 *                double Vref
 *                const struct2_T *Aircraft
 *                const struct3_T *AtmCond
 *                unsigned char trace
 * Return Type  : double
 */
double ANCM_GetNoiseSeg(const struct0_T *Seg, const double Ob[3],
                        const emxArray_struct1_T *NPDdataSt,
                        const char NoiseMetric[3], char OpMode, double Vref,
                        const struct2_T *Aircraft, const struct3_T *AtmCond,
                        unsigned char trace)
{
  b_captured_var LXft;
  captured_var Dis;
  emxArray_boolean_T *b_PowerSetting;
  emxArray_real_T *PowerSetting;
  const struct1_T *NPDdataSt_data;
  struct_T expl_temp;
  double b_validatedHoleFilling[3];
  double DeltaV;
  double LP1_data;
  double LP2_data;
  double Lambda;
  double Lseg;
  double P1_data;
  double count;
  double iP1_data;
  double iP2_data;
  double id1_data;
  double tmp_data;
  double *PowerSetting_data;
  int LP2_size[2];
  int P1_size[2];
  int b_iP1_size[2];
  int iP1_size[2];
  int iP2_size[2];
  int id1_size[2];
  int id2_size[2];
  int tmp_size[2];
  int b_i;
  int i;
  unsigned int j;
  int loop_ub_tmp;
  char varargin_1[4];
  char MOS[3];
  unsigned char u;
  unsigned char u1;
  boolean_T b_Dis[10];
  boolean_T b_iP1_data;
  boolean_T *b_PowerSetting_data;
  NPDdataSt_data = NPDdataSt->data;
  u = (unsigned char)(trace & 1);
  if (u != 0) {
    double validatedHoleFilling[6];
    printf("Calling ANCS_GetNoiseSeg INPUT PARAMETERS....\n");
    fflush(stdout);
    validate_print_arguments(Seg->S1[0], Seg->S1[1], Seg->S1[2], Seg->S2[0],
                             Seg->S2[1], Seg->S2[2], validatedHoleFilling);
    printf("   Segment Data: S1 [%7.2f,%7.2f,%7.2f] -> S2 [%7.2f,%7.2f,%7.2f]",
           validatedHoleFilling[0], validatedHoleFilling[1],
           validatedHoleFilling[2], validatedHoleFilling[3],
           validatedHoleFilling[4], validatedHoleFilling[5]);
    fflush(stdout);
    printf(" isRolling %1.0f, epsilon %5.2f, P %7.2f, Vseg %7.2f\n",
           Seg->isRolling, Seg->epsilon, Seg->P, Seg->Vseg);
    fflush(stdout);
    b_validate_print_arguments(Ob[0], Ob[1], Ob[2], b_validatedHoleFilling);
    printf("   Observer: [%7.2f,%7.2f,%7.2f]\n", b_validatedHoleFilling[0],
           b_validatedHoleFilling[1], b_validatedHoleFilling[2]);
    fflush(stdout);
    printf("   NPDdataSt: size %d;", NPDdataSt->size[0]);
    fflush(stdout);
    varargin_1[0] = NoiseMetric[0];
    varargin_1[1] = NoiseMetric[1];
    varargin_1[2] = NoiseMetric[2];
    varargin_1[3] = '\x00';
    printf(" NoiseMetric: %s;", &varargin_1[0]);
    fflush(stdout);
    printf("   OpMode: %c;", OpMode);
    fflush(stdout);
    printf(" Vref: %7.2f\n", Vref);
    fflush(stdout);
    printf("   Aircraft: Wingmounted %d, Turbofan %d;",
           (signed char)Aircraft->WingMounted, (signed char)Aircraft->TurboFan);
    fflush(stdout);
    printf(" AtmCond: p %7.2f, T %4.2f\n", AtmCond->p, AtmCond->T);
    fflush(stdout);
  }
  if ((trace & 4) != 0) {
    printf("  NPDdataSt\n");
    fflush(stdout);
    printf("      Met O  Power    200   400   630  1000  2000  4000  6300 "
           "10000 16000 25000\n");
    fflush(stdout);
    printf("      "
           "-------------------------------------------------------------------"
           "------\n");
    fflush(stdout);
    i = NPDdataSt->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      double c_validatedHoleFilling[5];
      varargin_1[0] = NPDdataSt_data[b_i].NoiseMetric[0];
      varargin_1[1] = NPDdataSt_data[b_i].NoiseMetric[1];
      varargin_1[2] = NPDdataSt_data[b_i].NoiseMetric[2];
      varargin_1[3] = '\x00';
      printf("      %3s %c %6.0f  %5.1f", &varargin_1[0],
             NPDdataSt_data[b_i].OpMode, NPDdataSt_data[b_i].PowerSetting,
             NPDdataSt_data[b_i].L_200ft);
      fflush(stdout);
      c_validate_print_arguments(
          NPDdataSt_data[b_i].L_400ft, NPDdataSt_data[b_i].L_630ft,
          NPDdataSt_data[b_i].L_1000ft, NPDdataSt_data[b_i].L_2000ft,
          NPDdataSt_data[b_i].L_4000ft, c_validatedHoleFilling);
      printf(" %5.1f %5.1f %5.1f %5.1f %5.1f", c_validatedHoleFilling[0],
             c_validatedHoleFilling[1], c_validatedHoleFilling[2],
             c_validatedHoleFilling[3], c_validatedHoleFilling[4]);
      fflush(stdout);
      printf(" %5.1f %5.1f %5.1f %5.1f\n", NPDdataSt_data[b_i].L_6300ft,
             NPDdataSt_data[b_i].L_10000ft, NPDdataSt_data[b_i].L_16000ft,
             NPDdataSt_data[b_i].L_25000ft);
      fflush(stdout);
    }
  }
  if (b_strcmp(NoiseMetric)) {
    MOS[0] = 'M';
    MOS[1] = 'L';
    MOS[2] = 'M';
  } else if (OpMode == 'A') {
    MOS[0] = 'E';
    MOS[1] = 'M';
    MOS[2] = 'L';
    /*  Exposure metrics landing */
  } else {
    MOS[0] = 'E';
    MOS[1] = 'M';
    MOS[2] = 'T';
    /*  Exposure metrics takeoff   */
  }
  u1 = (unsigned char)(trace & 2);
  if (u1 != 0) {
    varargin_1[0] = MOS[0];
    varargin_1[1] = MOS[1];
    varargin_1[2] = MOS[2];
    varargin_1[3] = '\x00';
    printf("  MOS: %s \n", &varargin_1[0]);
    fflush(stdout);
  }
  /*  1: Get all the necessary geometry data  */
  ANCM_GetGeometryData(Seg->S1, Seg->S2, Seg->isRolling, Seg->epsilon, Ob, MOS,
                       &expl_temp);
  if (u1 != 0) {
    b_validate_print_arguments(expl_temp.D1, expl_temp.D2, expl_temp.lambda,
                               b_validatedHoleFilling);
    printf("  > CALL ANCM_GetGeometryData D1 %5.2f; D2 %5.2f; Lambda %5.2f\n",
           b_validatedHoleFilling[0], b_validatedHoleFilling[1],
           b_validatedHoleFilling[2]);
    fflush(stdout);
    printf("     Dp %5.2f; q %5.2f; D %5.2f; Gamma %5.2f\n", expl_temp.Dp,
           expl_temp.q, expl_temp.D, expl_temp.gamma);
    fflush(stdout);
    printf("     Heading %5.2f; l %5.2f; beta %5.3f; phi %5.3f\n",
           expl_temp.heading, expl_temp.l, expl_temp.beta, expl_temp.phi);
    fflush(stdout);
  }
  /*  2: Get the baseline noise level from the slant distance */
  /*  ANCM_GetLPdSt Interpolation of noise-power-distances curves depending on P
   * (Power)  */
  /*  and d (distance using NPD data.  */
  /*  Implements interpolation equations of Section 4.2 from  */
  /*  Doc.29, 4th edition, Vol.2   */
  /*  Inputs: */
  /*      P: Power */
  /*      d: Slant distance (in ft) */
  /*      NPDdata: STRUCT with all the NPD data of the aircraft */
  /*      NoiseMetric, OpMode: to select the data from NPD */
  /*  Output */
  /*      Lout: Interpolated noise */
  /*  */
  /*   ANCM: Aircraft Noise Countour Modelling Library. */
  /*   2022 (c) Universidad Politécnica de Valencia */
  Lambda = fmax(expl_temp.D, 100.0);
  /*  it is recommended that a lower limit of 30 m be imposed on d, i.e. d =
   * max(d, 30 m). */
  /*  Fixed distance values from the table (in ft) */
  for (i = 0; i < 10; i++) {
    Dis.contents[i] = iv[i];
  }
  /*  Filter by Noise Metric and OpMode */
  count = 0.0;
  /*  First obtain the number of element */
  i = NPDdataSt->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (c_strcmp(NPDdataSt_data[b_i].NoiseMetric, NoiseMetric) &&
        (NPDdataSt_data[b_i].OpMode == OpMode)) {
      count++;
    }
  }
  j = 1U;
  emxInit_real_T(&PowerSetting);
  i = PowerSetting->size[0] * PowerSetting->size[1];
  PowerSetting->size[0] = 1;
  loop_ub_tmp = (int)count;
  PowerSetting->size[1] = (int)count;
  emxEnsureCapacity_real_T(PowerSetting, i);
  PowerSetting_data = PowerSetting->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    PowerSetting_data[i] = 0.0;
  }
  emxInitStruct_captured_var(&LXft);
  i = LXft.contents->size[0] * LXft.contents->size[1];
  LXft.contents->size[0] = 10;
  LXft.contents->size[1] = (int)count;
  emxEnsureCapacity_real_T(LXft.contents, i);
  b_i = 10 * (int)count;
  for (i = 0; i < b_i; i++) {
    LXft.contents->data[i] = 0.0;
  }
  i = NPDdataSt->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (c_strcmp(NPDdataSt_data[b_i].NoiseMetric, NoiseMetric) &&
        (NPDdataSt_data[b_i].OpMode == OpMode)) {
      PowerSetting_data[(int)j - 1] = NPDdataSt_data[b_i].PowerSetting;
      /*  Creata a matrix with all the data of L */
      loop_ub_tmp = 10 * ((int)j - 1);
      LXft.contents->data[loop_ub_tmp] = NPDdataSt_data[b_i].L_200ft;
      LXft.contents->data[loop_ub_tmp + 1] = NPDdataSt_data[b_i].L_400ft;
      LXft.contents->data[loop_ub_tmp + 2] = NPDdataSt_data[b_i].L_630ft;
      LXft.contents->data[loop_ub_tmp + 3] = NPDdataSt_data[b_i].L_1000ft;
      LXft.contents->data[loop_ub_tmp + 4] = NPDdataSt_data[b_i].L_2000ft;
      LXft.contents->data[loop_ub_tmp + 5] = NPDdataSt_data[b_i].L_4000ft;
      LXft.contents->data[loop_ub_tmp + 6] = NPDdataSt_data[b_i].L_6300ft;
      LXft.contents->data[loop_ub_tmp + 7] = NPDdataSt_data[b_i].L_10000ft;
      LXft.contents->data[loop_ub_tmp + 8] = NPDdataSt_data[b_i].L_16000ft;
      LXft.contents->data[loop_ub_tmp + 9] = NPDdataSt_data[b_i].L_25000ft;
      j++;
    }
  }
  /*  Get the P interval */
  emxInit_boolean_T(&b_PowerSetting);
  i = b_PowerSetting->size[0] * b_PowerSetting->size[1];
  b_PowerSetting->size[0] = 1;
  b_PowerSetting->size[1] = PowerSetting->size[1];
  emxEnsureCapacity_boolean_T(b_PowerSetting, i);
  b_PowerSetting_data = b_PowerSetting->data;
  b_i = PowerSetting->size[1];
  for (i = 0; i < b_i; i++) {
    b_PowerSetting_data[i] = (PowerSetting_data[i] >= Seg->P);
  }
  eml_find(b_PowerSetting, (int *)&loop_ub_tmp, tmp_size);
  emxFree_boolean_T(&b_PowerSetting);
  iP2_size[0] = 1;
  iP2_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    iP2_data = loop_ub_tmp;
  }
  iP1_size[0] = 1;
  iP1_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    iP1_data = iP2_data - 1.0;
  }
  if (tmp_size[1] == 0) {
    iP1_size[0] = 1;
    iP1_size[1] = 1;
    iP1_data = PowerSetting->size[1];
    /*  outwards */
    iP2_size[0] = 1;
    iP2_size[1] = 1;
    iP2_data = PowerSetting->size[1];
  }
  /*  Get the d interval */
  for (i = 0; i < 10; i++) {
    b_Dis[i] = (Dis.contents[i] >= Lambda);
  }
  b_eml_find(b_Dis, (int *)&loop_ub_tmp, tmp_size);
  id2_size[0] = 1;
  id2_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    count = loop_ub_tmp;
  }
  id1_size[0] = 1;
  id1_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    id1_data = count - 1.0;
  }
  if (tmp_size[1] == 0) {
    id1_size[0] = 1;
    id1_size[1] = 1;
    id1_data = 10.0;
    /*  outwards */
    id2_size[0] = 1;
    id2_size[1] = 1;
    count = 10.0;
  }
  b_iP1_size[0] = 1;
  b_iP1_size[1] = iP1_size[1];
  b_i = iP1_size[1];
  for (i = 0; i < b_i; i++) {
    b_iP1_data = (iP1_data == 0.0);
  }
  if (ifWhileCond((boolean_T *)&b_iP1_data, b_iP1_size)) {
    /*  Inwards */
    L_int_d(&LXft, &Dis, (double *)&count, id2_size, (double *)&id1_data,
            id1_size, Lambda, (double *)&LP1_data, tmp_size);
    b_L_int_d(&LXft, &Dis, (double *)&count, id2_size, (double *)&id1_data,
              id1_size, Lambda, (double *)&LP2_data, b_iP1_size);
    /*  Eq. 4.3. inwards modification!! */
    tmp_data = PowerSetting_data[1] - Seg->P;
    if (tmp_size[0] == 1) {
      i = b_iP1_size[0];
    } else {
      i = tmp_size[0];
    }
    if (tmp_size[1] == 1) {
      loop_ub_tmp = b_iP1_size[1];
    } else {
      loop_ub_tmp = tmp_size[1];
    }
    if ((tmp_size[0] == b_iP1_size[0]) && (tmp_size[1] == b_iP1_size[1]) &&
        (b_iP1_size[0] == i) && (b_iP1_size[1] == loop_ub_tmp)) {
      count = PowerSetting_data[1] - PowerSetting_data[0];
      b_i = b_iP1_size[0] * b_iP1_size[1];
      for (i = 0; i < b_i; i++) {
        LP2_data += (LP1_data - LP2_data) / count * tmp_data;
      }
    } else {
      binary_expand_op((double *)&LP2_data, b_iP1_size, (double *)&LP1_data,
                       tmp_size, PowerSetting, tmp_data);
    }
  } else {
    b_iP1_size[0] = 1;
    b_iP1_size[1] = iP1_size[1];
    b_i = iP1_size[1];
    for (i = 0; i < b_i; i++) {
      b_iP1_data = (iP1_data == iP2_data);
    }
    if (ifWhileCond((boolean_T *)&b_iP1_data, b_iP1_size)) {
      /*  Outwards */
      c_L_int_d(&LXft, &Dis, (double)PowerSetting->size[1] - 1.0,
                (double *)&count, id2_size, (double *)&id1_data, id1_size,
                Lambda, (double *)&LP1_data, tmp_size);
      c_L_int_d(&LXft, &Dis, PowerSetting->size[1], (double *)&count, id2_size,
                (double *)&id1_data, id1_size, Lambda, (double *)&LP2_data,
                b_iP1_size);
      /*  Eq. 4.3. outwards */
      tmp_data = Seg->P - PowerSetting_data[PowerSetting->size[1] - 1];
      if (b_iP1_size[0] == 1) {
        i = tmp_size[0];
      } else {
        i = b_iP1_size[0];
      }
      if (b_iP1_size[1] == 1) {
        loop_ub_tmp = tmp_size[1];
      } else {
        loop_ub_tmp = b_iP1_size[1];
      }
      if ((b_iP1_size[0] == tmp_size[0]) && (b_iP1_size[1] == tmp_size[1]) &&
          (b_iP1_size[0] == i) && (b_iP1_size[1] == loop_ub_tmp)) {
        count = PowerSetting_data[PowerSetting->size[1] - 1] -
                PowerSetting_data[PowerSetting->size[1] - 2];
        b_i = b_iP1_size[0] * b_iP1_size[1];
        for (i = 0; i < b_i; i++) {
          LP2_data += (LP2_data - LP1_data) / count * tmp_data;
        }
      } else {
        b_binary_expand_op((double *)&LP2_data, b_iP1_size, (double *)&LP1_data,
                           tmp_size, PowerSetting, tmp_data);
      }
    } else {
      P1_size[0] = 1;
      P1_size[1] = iP1_size[1];
      b_i = iP1_size[1];
      for (i = 0; i < b_i; i++) {
        P1_data = PowerSetting_data[(int)iP1_data - 1];
      }
      d_L_int_d(&LXft, &Dis, (double *)&iP1_data, iP1_size, (double *)&count,
                id2_size, (double *)&id1_data, id1_size, Lambda,
                (double *)&LP1_data, tmp_size);
      d_L_int_d(&LXft, &Dis, (double *)&iP2_data, iP2_size, (double *)&count,
                id2_size, (double *)&id1_data, id1_size, Lambda,
                (double *)&LP2_data, b_iP1_size);
      /*  Eq. 4.3. */
      if ((b_iP1_size[0] == tmp_size[0]) && (b_iP1_size[1] == tmp_size[1]) &&
          (iP1_size[1] == 1)) {
        LP2_size[0] = b_iP1_size[0];
        LP2_size[1] = b_iP1_size[1];
        b_i = b_iP1_size[0] * b_iP1_size[1];
        for (i = 0; i < b_i; i++) {
          count = LP2_data - LP1_data;
        }
        iP1_size[0] = 1;
        iP1_size[1] = 1;
        iP1_data = PowerSetting_data[(int)iP2_data - 1] - P1_data;
        mrdiv((double *)&count, LP2_size, (double *)&iP1_data, iP1_size,
              (double *)&tmp_data, &loop_ub_tmp);
      } else {
        d_binary_expand_op((double *)&tmp_data, &loop_ub_tmp,
                           (double *)&LP2_data, b_iP1_size, (double *)&LP1_data,
                           tmp_size, PowerSetting, (double *)&iP2_data,
                           iP2_size, (double *)&P1_data, P1_size);
      }
      if ((tmp_size[0] == loop_ub_tmp) && (tmp_size[1] == P1_size[1])) {
        b_i = P1_size[1];
        for (i = 0; i < b_i; i++) {
          iP1_data = Seg->P - P1_data;
        }
        b_i = P1_size[1];
        if (b_i - 1 >= 0) {
          for (i = 0; i < loop_ub_tmp; i++) {
            LP2_data = LP1_data + tmp_data * iP1_data;
          }
        }
      } else {
        c_binary_expand_op((double *)&LP2_data, b_iP1_size, (double *)&LP1_data,
                           tmp_size, (double *)&tmp_data, &loop_ub_tmp, Seg,
                           (double *)&P1_data, P1_size);
      }
    }
  }
  emxFree_real_T(&PowerSetting);
  emxFreeStruct_captured_var(&LXft);
  /*  Avoid the return of imaginary numbers for the MATLAB coder */
  if (u1 != 0) {
    printf("  > CALL ANCM_GetLPdSt Ld %7.4f\n", LP2_data);
    fflush(stdout);
  }
  /*  3: Calculate the corrections */
  /*  ANCM_GetDeltaImpedance IMPEDANCE ADJUSTMENT OF STANDARD NPD DATA */
  /*  The acoustic impedance adjustment is usually less than a few tenths of one
   * dB.  */
  /*  See section 4.2.1 of Doc.29, 4th edition, Vol.2  */
  /*  Input */
  /*    p: Ambient air pressure at the observer in KPa */
  /*    T: Air temperature at the observer altitude (celcius) */
  /*  Output */
  /*    DeltaImp: Impedante adjustment of standard NPD data */
  /*  */
  /*   ANCM: Aircraft Noise Countour Modelling Library. */
  /*   2022 (c) Universidad Politécnica de Valencia */
  /*  Eq. 4.7 */
  /*  º celcius reference temperature */
  /*  kPa: air pressure at mean sea level */
  /*  Eq. 4.6 */
  LP1_data =
      10.0 *
      log10(416.86 *
            (AtmCond->p / 101.325 / sqrt((AtmCond->T + 273.15) / 288.15)) /
            409.81);
  if (u1 != 0) {
    printf("  > CALL ANCM_GetDeltaImpedance DeltaImp %7.4f\n", LP1_data);
    fflush(stdout);
  }
  /*  ANCM_GetDeltaV (Duration correction)  */
  /*  accounts for a change in exposure levels if the actual segment speed is */
  /*  different to the aircraft reference speed Vref to which the basic NPD data
   * relate. */
  /*  See section 4.5.1 of Doc.29, 4th edition, Vol.2  */
  /*  Input */
  /*    Vref: Speed of reference */
  /*    Vseg: Speed of the segment */
  /*  Output */
  /*    DeltaV: Duration correction */
  /*  */
  /*   ANCM: Aircraft Noise Countour Modelling Library. */
  /*   2022 (c) Universidad Politécnica de Valencia */
  DeltaV = 10.0 * log10(Vref / Seg->Vseg);
  if (u1 != 0) {
    printf("  > CALL ANCM_GetDeltaV DeltaV %7.4f\n", DeltaV);
    fflush(stdout);
  }
  /*  ANCM_GetDeltaI Engine installation correction */
  /*  See section 4.5.3 of Doc.29, 4th edition, Vol.2  */
  /*  Input */
  /*    Gd: geometry data */
  /*    Aircraft: information about the aircraft (sn struct) */
  /*        WingMounted: true -> wing-mounted engine;false -> fuselage mounted
   */
  /*        TurboFan: true: turbo-fan propelled, false: turbo-prop propelled */
  /*  Output */
  /*    DeltaI: Engine installation correction */
  /*  */
  /*   ANCM: Aircraft Noise Countour Modelling Library. */
  /*   2022 (c) Universidad Politécnica de Valencia */
  if (Aircraft->TurboFan) {
    if (Aircraft->WingMounted) {
      count = 0.0039;
      tmp_data = 0.062;
      id1_data = 0.8766;
    } else {
      count = 0.1225;
      tmp_data = 0.329;
      id1_data = 1.0;
    }
    /*  Eq. 4-15 */
    Lambda = expl_temp.phi;
    b_cosd(&Lambda);
    iP2_data = expl_temp.phi;
    b_sind(&iP2_data);
    iP1_data = 2.0 * expl_temp.phi;
    P1_data = iP1_data;
    b_sind(&P1_data);
    b_cosd(&iP1_data);
    P1_data = 10.0 *
              log10(rt_powd_snf(count * (Lambda * Lambda) + iP2_data * iP2_data,
                                tmp_data) /
                    (id1_data * (P1_data * P1_data) + iP1_data * iP1_data));
  } else {
    /*  Propeller is zero */
    P1_data = 0.0;
  }
  if (u1 != 0) {
    printf("  > CALL ANCM_GetDeltaI DeltaI %7.4f\n", P1_data);
    fflush(stdout);
  }
  /*  ANCM_GetLambda Lateral attenuation  */
  /*  See section 4.5.4 of Doc.29, 4th edition, Vol.2  */
  /*  Input */
  /*    Gd: geometry data */
  /*  Output */
  /*    Lambda: Lateral attenuation */
  /*  */
  /*   ANCM: Aircraft Noise Countour Modelling Library. */
  /*   2022 (c) Universidad Politécnica de Valencia */
  /*  Meters to feet */
  /*  Eq. 4.19 a-b */
  count = expl_temp.l / 3.28084;
  /*  l must be in meters */
  /*  Eq. 4.19 c-d */
  /*  Eq. 4-18 */
  if (count <= 914.0) {
    Lambda = 1.089 * (1.0 - exp(-0.00274 * count));
  } else {
    Lambda = 1.0;
  }
  if (expl_temp.beta < 0.0) {
    count = 10.857;
  } else if (expl_temp.beta <= 50.0) {
    count =
        (1.137 - 0.0229 * expl_temp.beta) + 9.72 * exp(-0.142 * expl_temp.beta);
  } else {
    count = 0.0;
  }
  Lambda *= count;
  if (u1 != 0) {
    printf("  > CALL ANCM_GetLambda Lambda %7.4f\n", Lambda);
    fflush(stdout);
  }
  iP2_data = ANCM_GetDeltaFSt(expl_temp.lambda, expl_temp.q, expl_temp.D,
                              Seg->isRolling, Seg->P, NPDdataSt, OpMode, Vref);
  if (u1 != 0) {
    printf("  > CALL ANCM_GetDeltaFSt DeltaF %7.4f\n", iP2_data);
    fflush(stdout);
  }
  if ((Seg->isRolling != 0.0) && (expl_temp.q < 0.0) && (OpMode == 'D')) {
    /*  Correction only when departing, rolling and behing the segment */
    /*  ANCM_GetDeltaSOR The Start-of-roill directevity function DeltaSOR */
    /*  accounts for the pronounced directionality of jet engine noise behind
     * the ground roll segment */
    /*  */
    /*  See section 4.5.7 of Doc.29, 4th edition, Vol.2  */
    /*  Input */
    /*    Gd: geometry data */
    /*    TurboFan: true: turbo-fan propelled, false: turbo-prop propelled */
    /*  Output */
    /*    DeltaSOR: Impedante adjustment of standard NPD data */
    /*  */
    /*   ANCM: Aircraft Noise Countour Modelling Library. */
    /*   2022 (c) Universidad Politécnica de Valencia    */
    /*  Start-of-roll directivity function Delta_SOR */
    /*  ft */
    count = 0.0;
    iP1_data = 57.295779513082323 * acos(expl_temp.q / expl_temp.D1);
    /*  in degrees */
    if (Aircraft->TurboFan) {
      /*  Eq. 4-24a; */
      if ((iP1_data >= 90.0) && (iP1_data <= 180.0)) {
        count = 3.1415926535897931 * iP1_data / 180.0;
        id1_data = log(count);
        count = (((2329.44 - 8.0573 * iP1_data) + 11.51 * exp(count)) -
                 3.4601 * iP1_data / id1_data) -
                1.74033383E+7 * id1_data / (iP1_data * iP1_data);
      }

      /*  Eq. 4-24b; */
    } else if ((iP1_data >= 90.0) && (iP1_data <= 180.0)) {
      count = ((((((3.0722161987E+7 / iP1_data - 34643.898) -
                   1.149157393051E+10 / (iP1_data * iP1_data)) +
                  2.349285669062E+12 / rt_powd_snf(iP1_data, 3.0)) -
                 2.83584441904272E+14 / rt_powd_snf(iP1_data, 4.0)) +
                2.02271503912513E+16 / rt_powd_snf(iP1_data, 5.0)) -
               7.90084471305203E+17 / rt_powd_snf(iP1_data, 6.0)) +
              1.30506871782738E+19 / rt_powd_snf(iP1_data, 7.0);
    }
    if (!(expl_temp.D1 <= 2500.0)) {
      count = count * 2500.0 / expl_temp.D1;
    }
  } else {
    count = 0.0;
  }
  if (u1 != 0) {
    printf("  > CALL ANCM_GetDeltaSOR DeltaSOR %7.4f\n", count);
    fflush(stdout);
  }
  if (!b_strcmp(NoiseMetric)) {
    /*  Eq. 4-9b   */
    Lseg =
        (((((LP2_data + DeltaV) + LP1_data) + P1_data) - Lambda) + iP2_data) +
        count;
  } else {
    /*  Eq. 4.9a (only for LAmax) */
    Lseg = (((LP2_data + LP1_data) + P1_data) - Lambda) + count;
  }
  if (u != 0) {
    printf("RETURN Lseg %7.4f\n", Lseg);
    fflush(stdout);
  }
  return Lseg;
}

/*
 * File trailer for ANCM_GetNoiseSeg.c
 *
 * [EOF]
 */
