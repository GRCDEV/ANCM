/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetNoiseSeg_internal_types.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETNOISESEG_INTERNAL_TYPES_H
#define ANCM_GETNOISESEG_INTERNAL_TYPES_H

/* Include Files */
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  double D1;
  double D2;
  double lambda;
  double Dp;
  double q;
  double D;
  double gamma;
  double heading;
  double l;
  double beta;
  double phi;
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_captured_var
#define typedef_captured_var
typedef struct {
  double contents[10];
} captured_var;
#endif /* typedef_captured_var */

#endif
/*
 * File trailer for ANCM_GetNoiseSeg_internal_types.h
 *
 * [EOF]
 */
