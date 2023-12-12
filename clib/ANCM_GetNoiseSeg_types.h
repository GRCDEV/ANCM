/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetNoiseSeg_types.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETNOISESEG_TYPES_H
#define ANCM_GETNOISESEG_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  boolean_T WingMounted;
  boolean_T TurboFan;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  double p;
  double T;
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  char NoiseMetric[3];
  char OpMode;
  double PowerSetting;
  double L_200ft;
  double L_400ft;
  double L_630ft;
  double L_1000ft;
  double L_2000ft;
  double L_4000ft;
  double L_6300ft;
  double L_10000ft;
  double L_16000ft;
  double L_25000ft;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  double S1[3];
  double S2[3];
  double isRolling;
  double epsilon;
  double P;
  double Vseg;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_emxArray_struct1_T
#define typedef_emxArray_struct1_T
typedef struct {
  struct1_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct1_T;
#endif /* typedef_emxArray_struct1_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_b_captured_var
#define typedef_b_captured_var
typedef struct {
  emxArray_real_T *contents;
} b_captured_var;
#endif /* typedef_b_captured_var */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#endif
/*
 * File trailer for ANCM_GetNoiseSeg_types.h
 *
 * [EOF]
 */
