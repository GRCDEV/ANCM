/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetNoiseSeg_emxutil.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETNOISESEG_EMXUTIL_H
#define ANCM_GETNOISESEG_EMXUTIL_H

/* Include Files */
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFreeStruct_captured_var(b_captured_var *pStruct);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_struct1_T(emxArray_struct1_T **pEmxArray);

extern void emxInitStruct_captured_var(b_captured_var *pStruct);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray);

extern void emxInit_struct1_T(emxArray_struct1_T **pEmxArray,
                              int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ANCM_GetNoiseSeg_emxutil.h
 *
 * [EOF]
 */
