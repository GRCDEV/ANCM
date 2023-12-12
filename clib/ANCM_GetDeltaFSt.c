/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetDeltaFSt.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "ANCM_GetDeltaFSt.h"
#include "ANCM_GetLPdSt.h"
#include "ANCM_GetNoiseSeg_data.h"
#include "ANCM_GetNoiseSeg_emxutil.h"
#include "ANCM_GetNoiseSeg_internal_types.h"
#include "ANCM_GetNoiseSeg_rtwutil.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * FiniteSegmentCorrection (DeltaF) adjusts the level to what it would be if the
 * aircraft traversed the finite segment only See section 4.5.6 of Doc.29, 4th
 * edition, Vol.2 Input Gd: geometry data Seg: An struct with the segment data.
 * It has the following fields S1,S2: Points of the segment of the route
 *        epsilon: bank angle (in Euler angles: phi - roll)
 *        P: Power
 *        isRolling: the plane is in takeoff roll or landing roll
 *    NPDdata: STRUCT with all the NPD data of the aircraft
 *    OpMode: Operation mode ('A','D')
 *    Vref: Reference groundspeed for which NPD data are defined
 *  Output
 *    DeltaF: Finite segment correction
 *
 *   ANCM: Aircraft Noise Countour Modelling Library.
 *   2022 (c) Universidad Politécnica de Valencia
 *
 * Arguments    : double Gd_lambda
 *                double Gd_q
 *                double Gd_D
 *                double Seg_isRolling
 *                double Seg_P
 *                const emxArray_struct1_T *NPDdataSt
 *                char OpMode
 *                double Vref
 * Return Type  : double
 */
double ANCM_GetDeltaFSt(double Gd_lambda, double Gd_q, double Gd_D,
                        double Seg_isRolling, double Seg_P,
                        const emxArray_struct1_T *NPDdataSt, char OpMode,
                        double Vref)
{
  static const char b_cv[3] = {'S', 'E', 'L'};
  static const char cv1[3] = {'L', 'A', 'm'};
  b_captured_var LXft;
  b_captured_var b_LXft;
  captured_var Dis;
  emxArray_boolean_T *b_PowerSetting;
  emxArray_real_T *PowerSetting;
  const struct1_T *NPDdataSt_data;
  double DeltaF;
  double LP1_data;
  double LP2_data;
  double P1_data;
  double b_LP2_data;
  double count;
  double d_tmp;
  double iP2_data;
  double id1_data;
  double id2_data;
  double *PowerSetting_data;
  int LP2_size[2];
  int P1_size[2];
  int iP1_size[2];
  int iP2_size[2];
  int id1_size[2];
  int id2_size[2];
  int tmp_size[2];
  int x_size[2];
  int b_i;
  int exitg1;
  int i;
  unsigned int j;
  int kstr;
  boolean_T b_Dis[10];
  boolean_T b_bool;
  boolean_T exitg2;
  boolean_T y;
  boolean_T *b_PowerSetting_data;
  NPDdataSt_data = NPDdataSt->data;
  /*  Some precalculation for the the next equations */
  /*  1 seems to be OK */
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
  d_tmp = fmax(Gd_D, 100.0);
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
    b_bool = false;
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (cv[(unsigned char)NPDdataSt_data[b_i].NoiseMetric[kstr] & 127] !=
            cv[(int)b_cv[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool && (NPDdataSt_data[b_i].OpMode == OpMode)) {
      count++;
    }
  }
  j = 1U;
  emxInit_real_T(&PowerSetting);
  i = PowerSetting->size[0] * PowerSetting->size[1];
  PowerSetting->size[0] = 1;
  kstr = (int)count;
  PowerSetting->size[1] = (int)count;
  emxEnsureCapacity_real_T(PowerSetting, i);
  PowerSetting_data = PowerSetting->data;
  for (i = 0; i < kstr; i++) {
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
    b_bool = false;
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (cv[(unsigned char)NPDdataSt_data[b_i].NoiseMetric[kstr] & 127] !=
            cv[(int)b_cv[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool && (NPDdataSt_data[b_i].OpMode == OpMode)) {
      PowerSetting_data[(int)j - 1] = NPDdataSt_data[b_i].PowerSetting;
      /*  Creata a matrix with all the data of L */
      kstr = 10 * ((int)j - 1);
      LXft.contents->data[kstr] = NPDdataSt_data[b_i].L_200ft;
      LXft.contents->data[kstr + 1] = NPDdataSt_data[b_i].L_400ft;
      LXft.contents->data[kstr + 2] = NPDdataSt_data[b_i].L_630ft;
      LXft.contents->data[kstr + 3] = NPDdataSt_data[b_i].L_1000ft;
      LXft.contents->data[kstr + 4] = NPDdataSt_data[b_i].L_2000ft;
      LXft.contents->data[kstr + 5] = NPDdataSt_data[b_i].L_4000ft;
      LXft.contents->data[kstr + 6] = NPDdataSt_data[b_i].L_6300ft;
      LXft.contents->data[kstr + 7] = NPDdataSt_data[b_i].L_10000ft;
      LXft.contents->data[kstr + 8] = NPDdataSt_data[b_i].L_16000ft;
      LXft.contents->data[kstr + 9] = NPDdataSt_data[b_i].L_25000ft;
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
    b_PowerSetting_data[i] = (PowerSetting_data[i] >= Seg_P);
  }
  eml_find(b_PowerSetting, (int *)&kstr, tmp_size);
  iP2_size[0] = 1;
  iP2_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    iP2_data = kstr;
  }
  iP1_size[0] = 1;
  iP1_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    count = iP2_data - 1.0;
  }
  if (tmp_size[1] == 0) {
    iP1_size[0] = 1;
    iP1_size[1] = 1;
    count = PowerSetting->size[1];
    /*  outwards */
    iP2_size[0] = 1;
    iP2_size[1] = 1;
    iP2_data = PowerSetting->size[1];
  }
  /*  Get the d interval */
  for (i = 0; i < 10; i++) {
    b_Dis[i] = (Dis.contents[i] >= d_tmp);
  }
  b_eml_find(b_Dis, (int *)&kstr, tmp_size);
  id2_size[0] = 1;
  id2_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    id2_data = kstr;
  }
  id1_size[0] = 1;
  id1_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    id1_data = id2_data - 1.0;
  }
  if (tmp_size[1] == 0) {
    id1_size[0] = 1;
    id1_size[1] = 1;
    id1_data = 10.0;
    /*  outwards */
    id2_size[0] = 1;
    id2_size[1] = 1;
    id2_data = 10.0;
  }
  x_size[0] = 1;
  x_size[1] = iP1_size[1];
  b_i = iP1_size[1];
  for (i = 0; i < b_i; i++) {
    b_bool = (count == 0.0);
  }
  y = (iP1_size[1] != 0);
  if (y) {
    kstr = 0;
    exitg2 = false;
    while ((!exitg2) && (kstr <= x_size[1] - 1)) {
      if (!b_bool) {
        y = false;
        exitg2 = true;
      } else {
        kstr = 1;
      }
    }
  }
  if (y) {
    /*  Inwards */
    L_int_d(&LXft, &Dis, (double *)&id2_data, id2_size, (double *)&id1_data,
            id1_size, d_tmp, (double *)&LP1_data, tmp_size);
    b_L_int_d(&LXft, &Dis, (double *)&id2_data, id2_size, (double *)&id1_data,
              id1_size, d_tmp, (double *)&LP2_data, LP2_size);
    /*  Eq. 4.3. inwards modification!! */
    count = PowerSetting_data[1] - Seg_P;
    if (tmp_size[0] == 1) {
      i = LP2_size[0];
    } else {
      i = tmp_size[0];
    }
    if (tmp_size[1] == 1) {
      kstr = LP2_size[1];
    } else {
      kstr = tmp_size[1];
    }
    if ((tmp_size[0] == LP2_size[0]) && (tmp_size[1] == LP2_size[1]) &&
        (LP2_size[0] == i) && (LP2_size[1] == kstr)) {
      id2_data = PowerSetting_data[1] - PowerSetting_data[0];
      b_i = LP2_size[0] * LP2_size[1];
      for (i = 0; i < b_i; i++) {
        LP2_data += (LP1_data - LP2_data) / id2_data * count;
      }
    } else {
      binary_expand_op((double *)&LP2_data, LP2_size, (double *)&LP1_data,
                       tmp_size, PowerSetting, count);
    }
  } else {
    if (iP1_size[1] == 1) {
      x_size[1] = 1;
      b_bool = (count == iP2_data);
    } else {
      eq((boolean_T *)&b_bool, x_size, (double *)&count, iP1_size,
         (double *)&iP2_data, iP2_size);
    }
    y = (x_size[1] != 0);
    if (y) {
      kstr = 0;
      exitg2 = false;
      while ((!exitg2) && (kstr <= x_size[1] - 1)) {
        if (!b_bool) {
          y = false;
          exitg2 = true;
        } else {
          kstr = 1;
        }
      }
    }
    if (y) {
      /*  Outwards */
      c_L_int_d(&LXft, &Dis, (double)PowerSetting->size[1] - 1.0,
                (double *)&id2_data, id2_size, (double *)&id1_data, id1_size,
                d_tmp, (double *)&LP1_data, tmp_size);
      c_L_int_d(&LXft, &Dis, PowerSetting->size[1], (double *)&id2_data,
                id2_size, (double *)&id1_data, id1_size, d_tmp,
                (double *)&LP2_data, LP2_size);
      /*  Eq. 4.3. outwards */
      count = Seg_P - PowerSetting_data[PowerSetting->size[1] - 1];
      if (LP2_size[0] == 1) {
        i = tmp_size[0];
      } else {
        i = LP2_size[0];
      }
      if (LP2_size[1] == 1) {
        kstr = tmp_size[1];
      } else {
        kstr = LP2_size[1];
      }
      if ((LP2_size[0] == tmp_size[0]) && (LP2_size[1] == tmp_size[1]) &&
          (LP2_size[0] == i) && (LP2_size[1] == kstr)) {
        id2_data = PowerSetting_data[PowerSetting->size[1] - 1] -
                   PowerSetting_data[PowerSetting->size[1] - 2];
        b_i = LP2_size[0] * LP2_size[1];
        for (i = 0; i < b_i; i++) {
          LP2_data += (LP2_data - LP1_data) / id2_data * count;
        }
      } else {
        b_binary_expand_op((double *)&LP2_data, LP2_size, (double *)&LP1_data,
                           tmp_size, PowerSetting, count);
      }
    } else {
      P1_size[0] = 1;
      P1_size[1] = iP1_size[1];
      b_i = iP1_size[1];
      for (i = 0; i < b_i; i++) {
        P1_data = PowerSetting_data[(int)count - 1];
      }
      d_L_int_d(&LXft, &Dis, (double *)&count, iP1_size, (double *)&id2_data,
                id2_size, (double *)&id1_data, id1_size, d_tmp,
                (double *)&LP1_data, tmp_size);
      d_L_int_d(&LXft, &Dis, (double *)&iP2_data, iP2_size, (double *)&id2_data,
                id2_size, (double *)&id1_data, id1_size, d_tmp,
                (double *)&LP2_data, LP2_size);
      /*  Eq. 4.3. */
      if ((LP2_size[0] == tmp_size[0]) && (LP2_size[1] == tmp_size[1])) {
        b_i = LP2_size[0] * LP2_size[1];
        for (i = 0; i < b_i; i++) {
          LP2_data -= LP1_data;
        }
      } else {
        minus((double *)&LP2_data, LP2_size, (double *)&LP1_data, tmp_size);
      }
      if (iP2_size[1] == iP1_size[1]) {
        iP1_size[1] = iP2_size[1];
        b_i = iP2_size[1];
        for (i = 0; i < b_i; i++) {
          count = PowerSetting_data[(int)iP2_data - 1] - P1_data;
        }
      } else {
        s_binary_expand_op((double *)&count, iP1_size, PowerSetting,
                           (double *)&iP2_data, iP2_size, (double *)&P1_data,
                           P1_size);
      }
      if ((LP2_size[0] == 0) || (LP2_size[1] == 0) || (iP1_size[1] == 0)) {
        kstr = LP2_size[0];
        b_i = LP2_size[0];
        for (i = 0; i < b_i; i++) {
          count = 0.0;
        }
      } else {
        kstr = 1;
        count = LP2_data / count;
      }
      if ((tmp_size[0] == kstr) && (tmp_size[1] == P1_size[1])) {
        b_i = P1_size[1];
        for (i = 0; i < b_i; i++) {
          iP2_data = Seg_P - P1_data;
        }
        b_i = P1_size[1];
        if (b_i - 1 >= 0) {
          for (i = 0; i < kstr; i++) {
            LP2_data = LP1_data + count * iP2_data;
          }
        }
      } else {
        r_binary_expand_op((double *)&LP2_data, LP2_size, (double *)&LP1_data,
                           tmp_size, (double *)&count, &kstr, Seg_P,
                           (double *)&P1_data, P1_size);
      }
    }
  }
  emxFreeStruct_captured_var(&LXft);
  /*  Avoid the return of imaginary numbers for the MATLAB coder */
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
    b_bool = false;
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (cv[(unsigned char)NPDdataSt_data[b_i].NoiseMetric[kstr] & 127] !=
            cv[(int)cv1[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool && (NPDdataSt_data[b_i].OpMode == OpMode)) {
      count++;
    }
  }
  j = 1U;
  i = PowerSetting->size[0] * PowerSetting->size[1];
  PowerSetting->size[0] = 1;
  kstr = (int)count;
  PowerSetting->size[1] = (int)count;
  emxEnsureCapacity_real_T(PowerSetting, i);
  PowerSetting_data = PowerSetting->data;
  for (i = 0; i < kstr; i++) {
    PowerSetting_data[i] = 0.0;
  }
  emxInitStruct_captured_var(&b_LXft);
  i = b_LXft.contents->size[0] * b_LXft.contents->size[1];
  b_LXft.contents->size[0] = 10;
  b_LXft.contents->size[1] = (int)count;
  emxEnsureCapacity_real_T(b_LXft.contents, i);
  b_i = 10 * (int)count;
  for (i = 0; i < b_i; i++) {
    b_LXft.contents->data[i] = 0.0;
  }
  i = NPDdataSt->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    b_bool = false;
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (cv[(unsigned char)NPDdataSt_data[b_i].NoiseMetric[kstr] & 127] !=
            cv[(int)cv1[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool && (NPDdataSt_data[b_i].OpMode == OpMode)) {
      PowerSetting_data[(int)j - 1] = NPDdataSt_data[b_i].PowerSetting;
      /*  Creata a matrix with all the data of L */
      kstr = 10 * ((int)j - 1);
      b_LXft.contents->data[kstr] = NPDdataSt_data[b_i].L_200ft;
      b_LXft.contents->data[kstr + 1] = NPDdataSt_data[b_i].L_400ft;
      b_LXft.contents->data[kstr + 2] = NPDdataSt_data[b_i].L_630ft;
      b_LXft.contents->data[kstr + 3] = NPDdataSt_data[b_i].L_1000ft;
      b_LXft.contents->data[kstr + 4] = NPDdataSt_data[b_i].L_2000ft;
      b_LXft.contents->data[kstr + 5] = NPDdataSt_data[b_i].L_4000ft;
      b_LXft.contents->data[kstr + 6] = NPDdataSt_data[b_i].L_6300ft;
      b_LXft.contents->data[kstr + 7] = NPDdataSt_data[b_i].L_10000ft;
      b_LXft.contents->data[kstr + 8] = NPDdataSt_data[b_i].L_16000ft;
      b_LXft.contents->data[kstr + 9] = NPDdataSt_data[b_i].L_25000ft;
      j++;
    }
  }
  /*  Get the P interval */
  i = b_PowerSetting->size[0] * b_PowerSetting->size[1];
  b_PowerSetting->size[0] = 1;
  b_PowerSetting->size[1] = PowerSetting->size[1];
  emxEnsureCapacity_boolean_T(b_PowerSetting, i);
  b_PowerSetting_data = b_PowerSetting->data;
  b_i = PowerSetting->size[1];
  for (i = 0; i < b_i; i++) {
    b_PowerSetting_data[i] = (PowerSetting_data[i] >= Seg_P);
  }
  eml_find(b_PowerSetting, (int *)&kstr, tmp_size);
  emxFree_boolean_T(&b_PowerSetting);
  iP2_size[0] = 1;
  iP2_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    iP2_data = kstr;
  }
  iP1_size[0] = 1;
  iP1_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    count = iP2_data - 1.0;
  }
  if (tmp_size[1] == 0) {
    iP1_size[0] = 1;
    iP1_size[1] = 1;
    count = PowerSetting->size[1];
    /*  outwards */
    iP2_size[0] = 1;
    iP2_size[1] = 1;
    iP2_data = PowerSetting->size[1];
  }
  /*  Get the d interval */
  for (i = 0; i < 10; i++) {
    b_Dis[i] = (Dis.contents[i] >= d_tmp);
  }
  b_eml_find(b_Dis, (int *)&kstr, tmp_size);
  id2_size[0] = 1;
  id2_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    id2_data = kstr;
  }
  id1_size[0] = 1;
  id1_size[1] = tmp_size[1];
  b_i = tmp_size[1];
  for (i = 0; i < b_i; i++) {
    id1_data = id2_data - 1.0;
  }
  if (tmp_size[1] == 0) {
    id1_size[0] = 1;
    id1_size[1] = 1;
    id1_data = 10.0;
    /*  outwards */
    id2_size[0] = 1;
    id2_size[1] = 1;
    id2_data = 10.0;
  }
  x_size[0] = 1;
  x_size[1] = iP1_size[1];
  b_i = iP1_size[1];
  for (i = 0; i < b_i; i++) {
    b_bool = (count == 0.0);
  }
  y = (iP1_size[1] != 0);
  if (y) {
    kstr = 0;
    exitg2 = false;
    while ((!exitg2) && (kstr <= x_size[1] - 1)) {
      if (!b_bool) {
        y = false;
        exitg2 = true;
      } else {
        kstr = 1;
      }
    }
  }
  if (y) {
    /*  Inwards */
    L_int_d(&b_LXft, &Dis, (double *)&id2_data, id2_size, (double *)&id1_data,
            id1_size, d_tmp, (double *)&LP1_data, tmp_size);
    b_L_int_d(&b_LXft, &Dis, (double *)&id2_data, id2_size, (double *)&id1_data,
              id1_size, d_tmp, (double *)&b_LP2_data, LP2_size);
    /*  Eq. 4.3. inwards modification!! */
    count = PowerSetting_data[1] - Seg_P;
    if (tmp_size[0] == 1) {
      i = LP2_size[0];
    } else {
      i = tmp_size[0];
    }
    if (tmp_size[1] == 1) {
      kstr = LP2_size[1];
    } else {
      kstr = tmp_size[1];
    }
    if ((tmp_size[0] == LP2_size[0]) && (tmp_size[1] == LP2_size[1]) &&
        (LP2_size[0] == i) && (LP2_size[1] == kstr)) {
      id2_data = PowerSetting_data[1] - PowerSetting_data[0];
      b_i = LP2_size[0] * LP2_size[1];
      for (i = 0; i < b_i; i++) {
        b_LP2_data += (LP1_data - b_LP2_data) / id2_data * count;
      }
    } else {
      binary_expand_op((double *)&b_LP2_data, LP2_size, (double *)&LP1_data,
                       tmp_size, PowerSetting, count);
    }
  } else {
    if (iP1_size[1] == 1) {
      x_size[1] = 1;
      b_bool = (count == iP2_data);
    } else {
      eq((boolean_T *)&b_bool, x_size, (double *)&count, iP1_size,
         (double *)&iP2_data, iP2_size);
    }
    y = (x_size[1] != 0);
    if (y) {
      kstr = 0;
      exitg2 = false;
      while ((!exitg2) && (kstr <= x_size[1] - 1)) {
        if (!b_bool) {
          y = false;
          exitg2 = true;
        } else {
          kstr = 1;
        }
      }
    }
    if (y) {
      /*  Outwards */
      c_L_int_d(&b_LXft, &Dis, (double)PowerSetting->size[1] - 1.0,
                (double *)&id2_data, id2_size, (double *)&id1_data, id1_size,
                d_tmp, (double *)&LP1_data, tmp_size);
      c_L_int_d(&b_LXft, &Dis, PowerSetting->size[1], (double *)&id2_data,
                id2_size, (double *)&id1_data, id1_size, d_tmp,
                (double *)&b_LP2_data, LP2_size);
      /*  Eq. 4.3. outwards */
      count = Seg_P - PowerSetting_data[PowerSetting->size[1] - 1];
      if (LP2_size[0] == 1) {
        i = tmp_size[0];
      } else {
        i = LP2_size[0];
      }
      if (LP2_size[1] == 1) {
        kstr = tmp_size[1];
      } else {
        kstr = LP2_size[1];
      }
      if ((LP2_size[0] == tmp_size[0]) && (LP2_size[1] == tmp_size[1]) &&
          (LP2_size[0] == i) && (LP2_size[1] == kstr)) {
        id2_data = PowerSetting_data[PowerSetting->size[1] - 1] -
                   PowerSetting_data[PowerSetting->size[1] - 2];
        b_i = LP2_size[0] * LP2_size[1];
        for (i = 0; i < b_i; i++) {
          b_LP2_data += (b_LP2_data - LP1_data) / id2_data * count;
        }
      } else {
        b_binary_expand_op((double *)&b_LP2_data, LP2_size, (double *)&LP1_data,
                           tmp_size, PowerSetting, count);
      }
    } else {
      P1_size[0] = 1;
      P1_size[1] = iP1_size[1];
      b_i = iP1_size[1];
      for (i = 0; i < b_i; i++) {
        P1_data = PowerSetting_data[(int)count - 1];
      }
      d_L_int_d(&b_LXft, &Dis, (double *)&count, iP1_size, (double *)&id2_data,
                id2_size, (double *)&id1_data, id1_size, d_tmp,
                (double *)&LP1_data, tmp_size);
      d_L_int_d(&b_LXft, &Dis, (double *)&iP2_data, iP2_size,
                (double *)&id2_data, id2_size, (double *)&id1_data, id1_size,
                d_tmp, (double *)&b_LP2_data, LP2_size);
      /*  Eq. 4.3. */
      if ((LP2_size[0] == tmp_size[0]) && (LP2_size[1] == tmp_size[1])) {
        b_i = LP2_size[0] * LP2_size[1];
        for (i = 0; i < b_i; i++) {
          b_LP2_data -= LP1_data;
        }
      } else {
        minus((double *)&b_LP2_data, LP2_size, (double *)&LP1_data, tmp_size);
      }
      if (iP2_size[1] == iP1_size[1]) {
        iP1_size[1] = iP2_size[1];
        b_i = iP2_size[1];
        for (i = 0; i < b_i; i++) {
          count = PowerSetting_data[(int)iP2_data - 1] - P1_data;
        }
      } else {
        s_binary_expand_op((double *)&count, iP1_size, PowerSetting,
                           (double *)&iP2_data, iP2_size, (double *)&P1_data,
                           P1_size);
      }
      if ((LP2_size[0] == 0) || (LP2_size[1] == 0) || (iP1_size[1] == 0)) {
        kstr = LP2_size[0];
        b_i = LP2_size[0];
        for (i = 0; i < b_i; i++) {
          count = 0.0;
        }
      } else {
        kstr = 1;
        count = b_LP2_data / count;
      }
      if ((tmp_size[0] == kstr) && (tmp_size[1] == P1_size[1])) {
        b_i = P1_size[1];
        for (i = 0; i < b_i; i++) {
          iP2_data = Seg_P - P1_data;
        }
        b_i = P1_size[1];
        if (b_i - 1 >= 0) {
          for (i = 0; i < kstr; i++) {
            b_LP2_data = LP1_data + count * iP2_data;
          }
        }
      } else {
        r_binary_expand_op((double *)&b_LP2_data, LP2_size, (double *)&LP1_data,
                           tmp_size, (double *)&count, &kstr, Seg_P,
                           (double *)&P1_data, P1_size);
      }
    }
  }
  emxFreeStruct_captured_var(&b_LXft);
  emxFree_real_T(&PowerSetting);
  /*  Avoid the return of imaginary numbers for the MATLAB coder */
  count = 0.63661977236758138 * Vref *
          rt_powd_snf(10.0, (LP2_data - b_LP2_data) / 10.0);
  if ((Seg_isRolling != 0.0) && (OpMode == 'D') && (Gd_q < 0.0)) {
    /*  Rolling, takeoff and behind (D=departure mode) */
    /*  Eq. 4.21a */
    count = Gd_lambda / count;
    DeltaF = 10.0 * log10(0.31830988618379069 *
                          (count / (count * count + 1.0) + atan(count)));
  } else if ((Seg_isRolling != 0.0) && (OpMode == 'A') && (Gd_q > Gd_lambda)) {
    /*  Rolling, landing and ahead (A=arrival mode) */
    /*  Eq. 4.21b */
    id2_data = -Gd_lambda / count;
    DeltaF = 10.0 *
             log10(0.31830988618379069 *
                   (-id2_data / (id2_data * id2_data + 1.0) - atan(id2_data)));
  } else {
    /*  Eq. 4-20 */
    id2_data = -Gd_q / count;
    count = -(Gd_q - Gd_lambda) / count;
    DeltaF = 10.0 * log10(0.31830988618379069 *
                          (((count / (count * count + 1.0) + atan(count)) -
                            id2_data / (id2_data * id2_data + 1.0)) -
                           atan(id2_data)));
  }
  /*  Avoid returning imaginary number for the MATLAB coder */
  return DeltaF;
}

/*
 * File trailer for ANCM_GetDeltaFSt.c
 *
 * [EOF]
 */
