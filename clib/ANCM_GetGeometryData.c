/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetGeometryData.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "ANCM_GetGeometryData.h"
#include "ANCM_GetNoiseSeg_internal_types.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * ANCM_GetGeometryData Get the geometry data necessary for obtaining
 *  % the baseline noise level and the rest of corrections
 *  See sections 4.4.1, 4.5.2 and 4.5.5 of Doc.29, 4th edition, Vol.2
 *  Input
 *   Seg: An struct with the segment data. It has the following fields
 *        S1,S2: Points of the segment of the route
 *        epsilon: bank angle (in Euler angles: phi - roll)
 *        P: Power
 *        isRolling: the plane is in takeoff roll or landing roll
 *   Ob: Observer location
 *   MOS: Method to obtain the slant
 *        'MLM' : Maximum level metrics (D=Ds always)
 *        'EMT' : Exposure metrics takeoff (D can be Ds or Dp)
 *        'EML' : Exposure metrics landing (D can be Ds or Dp)
 *  Output
 *   An Gd struct with all these fields
 *    D: Slant distance for obtaining the baseline noise level
 *    Dp: Perpendicular distance between observer and extended segment
 *    D1,D2: Distance to the points of the segment
 *    q: distance from S1 to Sp (negative if the observer is behind the segment)
 *    lambda: length of flight path segment
 *    gamma: climb angle
 *    beta: elevation angle
 *    l: lateral displacement
 *    phi: depression angle
 *    heading: angle direction to 0,0
 *
 *   ANCM: Aircraft Noise Countour Modelling Library.
 *   2022 (c) Universidad Politécnica de Valencia
 *
 * Arguments    : const double Seg_S1[3]
 *                const double Seg_S2[3]
 *                double Seg_isRolling
 *                double Seg_epsilon
 *                const double Ob[3]
 *                const char MOS[3]
 *                struct_T *Gd
 * Return Type  : void
 */
void ANCM_GetGeometryData(const double Seg_S1[3], const double Seg_S2[3],
                          double Seg_isRolling, double Seg_epsilon,
                          const double Ob[3], const char MOS[3], struct_T *Gd)
{
  static const char b_b[3] = {'M', 'L', 'M'};
  static const char c_b[3] = {'E', 'M', 'T'};
  static const char d_b[3] = {'E', 'M', 'L'};
  double Gd_tmp[3];
  double R[3];
  double b[3];
  double b_Ob[3];
  double Ds;
  double Sp_idx_0;
  double Sp_idx_1;
  double Sp_idx_2;
  double a_tmp;
  double b_Gd_tmp;
  double d;
  double d1;
  double scale;
  int ret;
  /*  FIRST: BASIC GEOMETRIC PARAMETERS: section 4.4.1  */
  /*  Distance to the points of the segment */
  R[0] = Ob[0] - Seg_S1[0];
  b_Ob[0] = Ob[0] - Seg_S2[0];
  R[1] = Ob[1] - Seg_S1[1];
  b_Ob[1] = Ob[1] - Seg_S2[1];
  R[2] = Ob[2] - Seg_S1[2];
  b_Ob[2] = Ob[2] - Seg_S2[2];
  Gd->D1 = b_norm(R);
  Gd->D2 = b_norm(b_Ob);
  /*  Gd.lambda: length of flight path segment */
  /*  Slant distance or slant range (perpendicular distance from an observation
   */
  /*  point to the flight path */
  /*  Dp: Perpendicular distance between observer and extended segment */
  /*  Sp: Point of the perpendicular closest approach to the observer on the */
  /*  segment or its extension (that is, the project of point O on the */
  /*  trajectory) */
  d = Seg_S2[0] - Seg_S1[0];
  Gd_tmp[0] = d;
  b[0] = Seg_S2[0] - Ob[0];
  d1 = Seg_S2[1] - Seg_S1[1];
  Gd_tmp[1] = d1;
  b[1] = Seg_S2[1] - Ob[1];
  scale = Seg_S2[2] - Seg_S1[2];
  Gd_tmp[2] = scale;
  b[2] = Seg_S2[2] - Ob[2];
  b_Gd_tmp = b_norm(Gd_tmp);
  Gd->lambda = b_Gd_tmp;
  b_Ob[0] = d1 * b[2] - b[1] * scale;
  b_Ob[1] = b[0] * scale - d * b[2];
  b_Ob[2] = d * b[1] - b[0] * d1;
  Gd->Dp = b_norm(b_Ob) / b_Gd_tmp;
  a_tmp = ((R[0] * d + R[1] * d1) + R[2] * scale) / b_Gd_tmp;
  /*  q: distance from S1 to Sp (negative if the observer is behind the */
  /*  segment) */
  Sp_idx_0 = Seg_S1[0] + a_tmp * d / b_Gd_tmp;
  Sp_idx_1 = Seg_S1[1] + a_tmp * d1 / b_Gd_tmp;
  Sp_idx_2 = Seg_S1[2] + a_tmp * scale / b_Gd_tmp;
  Gd->q = a_tmp;
  /*  Ds: Shortest distance between Observer and the segment */
  if (a_tmp < 0.0) {
    Ds = Gd->D1;
  } else if (a_tmp > b_Gd_tmp) {
    Ds = Gd->D2;
  } else {
    Ds = Gd->Dp;
  }
  ret = memcmp(&MOS[0], &b_b[0], 3);
  if (ret == 0) {
    ret = 0;
  } else {
    ret = memcmp(&MOS[0], &c_b[0], 3);
    if (ret == 0) {
      ret = 1;
    } else {
      ret = memcmp(&MOS[0], &d_b[0], 3);
      if (ret == 0) {
        ret = 2;
      } else {
        ret = -1;
      }
    }
  }
  switch (ret) {
  case 0:
    /*  Maximum level metrics (D=Ds always) */
    Gd->D = Ds;
    /*  Gd.Dp; */
    break;
  case 1:
    /*  Exposure metrics takeoff  */
    if ((Seg_isRolling != 0.0) && (a_tmp < 0.0)) {
      /*   behind the ground segments during the takeoff roll */
      Gd->D = Ds;
    } else {
      Gd->D = Gd->Dp;
    }
    break;
  case 2:
    /*  Exposure metrics landing */
    if ((Seg_isRolling != 0.0) && (a_tmp > b_Gd_tmp)) {
      /*   locations ahead of ground segments during the landing roll,  */
      Gd->D = Ds;
    } else {
      Gd->D = Gd->Dp;
    }
    break;
  }
  /*  SECOND: AIRCRAFT-OBSERVER ANGLES : sections 4.5.2. and 4.5.5 */
  /*  FIGURES 4-3, 4-6 and 4.7 */
  /*  gamma: climb angle -> pitch (theta) */
  b[0] = d;
  b[1] = d1;
  b[2] = Seg_S1[2] - Seg_S1[2];
  Gd->gamma = 57.295779513082323 *
              acos(((d * d + d1 * d1) + scale * b[2]) / (b_Gd_tmp * b_norm(b)));
  if (Seg_S2[2] < Seg_S1[2]) {
    /*  Descending -> angle negative */
    Gd->gamma = -Gd->gamma;
  }
  /*  get heading  */
  if ((Seg_S1[0] == 0.0) && (Seg_S1[1] == 0.0)) {
    Gd->heading = 0.0;
  } else {
    double absxk;
    double b_y;
    double t;
    double y;
    scale = 3.3121686421112381E-170;
    Ds = 3.3121686421112381E-170;
    absxk = fabs(d);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(0.0 - Seg_S1[0]);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      Ds = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk = fabs(d1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(0.0 - Seg_S1[1]);
    if (absxk > Ds) {
      t = Ds / absxk;
      b_y = b_y * t * t + 1.0;
      Ds = absxk;
    } else {
      t = absxk / Ds;
      b_y += t * t;
    }
    y = scale * sqrt(y);
    b_y = Ds * sqrt(b_y);
    Gd->heading =
        57.295779513082323 *
        acos((d * (0.0 - Seg_S1[0]) + d1 * (0.0 - Seg_S1[1])) / (y * b_y));
    if ((0.0 - Seg_S1[0]) * d1 - (0.0 - Seg_S1[1]) * d > 0.0) {
      Gd->heading = -Gd->heading;
    }
  }
  /*  R: minimun distance point perpendicular of the ground track from the */
  /*  observer */
  /*      C = euler2dcm(Gd.heading/180, Gd.theta/180, epsilon/180); */
  /*      Z = (C*[0 0 1]')'; */
  /*      t = -S(3)/Z(3); */
  /*      R = Z*t+S; */
  /*  The difference is too small. */
  /*  l : lateral displacement */
  b_Ob[0] = Sp_idx_0 - Ob[0];
  b_Ob[1] = Sp_idx_1 - Ob[1];
  b_Ob[2] = 0.0 - Ob[2];
  Gd->l = b_norm(b_Ob);
  /*  beta : Elevation angle */
  if (a_tmp < 0.0) {
    /*  behind the segment */
    Gd->beta = 57.295779513082323 * atan(Seg_S1[2] / Gd->l);
  } else if (a_tmp > b_Gd_tmp) {
    /*  ahead the segment */
    Gd->beta = 57.295779513082323 * atan(Seg_S2[2] / Gd->l);
  } else {
    R[0] = Sp_idx_0 - Sp_idx_0;
    R[1] = Sp_idx_1 - Sp_idx_1;
    R[2] = Sp_idx_2;
    Gd->beta = 57.295779513082323 * atan(b_norm(R) / Gd->l);
  }
  ret = memcmp(&MOS[0], &b_b[0], 3);
  if (ret == 0) {
    ret = 0;
  } else {
    ret = memcmp(&MOS[0], &c_b[0], 3);
    if (ret == 0) {
      ret = 1;
    } else {
      ret = memcmp(&MOS[0], &d_b[0], 3);
      if (ret == 0) {
        ret = 2;
      } else {
        ret = -1;
      }
    }
  }
  switch (ret) {
  case 0:
    /*  Maximum level metrics  */
    if (a_tmp < 0.0) {
      /*  behind the segment */
      Gd->beta = 57.295779513082323 * asin(Seg_S1[2] / Gd->D1);
      Gd->l = sqrt(Gd->D1 * Gd->D1 - Seg_S1[2] * Seg_S1[2]);
    }
    break;
  case 1:
    /*  Exposure metrics takeoff  */
    if ((Seg_isRolling != 0.0) && (a_tmp < 0.0)) {
      /*   behind the ground segments during the takeoff roll */
      Gd->beta = 57.295779513082323 * asin(Seg_S1[2] / Gd->D1);
      Gd->l = sqrt(Gd->D1 * Gd->D1 - Seg_S1[2] * Seg_S1[2]);
    }
    break;
  case 2:
    /*  Exposure metrics landing */
    if ((Seg_isRolling != 0.0) && (a_tmp > b_Gd_tmp)) {
      /*   locations ahead of ground segments during the landing roll,  */
      Gd->beta = 57.295779513082323 * asin(Seg_S2[2] / Gd->D2);
      Gd->l = sqrt(Gd->D2 * Gd->D2 - Seg_S2[2] * Seg_S2[2]);
    }
    break;
  }
  /*  phi: depression angle */
  if ((a_tmp < 0.0) || (a_tmp > b_Gd_tmp)) {
    /*  out of the segment */
    Gd->phi = 57.295779513082323 * atan(Sp_idx_2 / Gd->l) - Seg_epsilon;
  } else {
    Gd->phi = Gd->beta - Seg_epsilon;
  }
  Gd->phi = fmax(0.0, Gd->phi);
}

/*
 * File trailer for ANCM_GetGeometryData.c
 *
 * [EOF]
 */
