/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetNoiseSeg_emxAPI.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETNOISESEG_EMXAPI_H
#define ANCM_GETNOISESEG_EMXAPI_H

/* Include Files */
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_struct1_T *emxCreateND_struct1_T(int numDimensions,
                                                 const int *size);

extern emxArray_struct1_T *emxCreateWrapperND_struct1_T(struct1_T *data,
                                                        int numDimensions,
                                                        const int *size);

extern emxArray_struct1_T *emxCreateWrapper_struct1_T(struct1_T *data, int rows,
                                                      int cols);

extern emxArray_struct1_T *emxCreate_struct1_T(int rows, int cols);

extern void emxDestroyArray_struct1_T(emxArray_struct1_T *emxArray);

extern void emxInitArray_struct1_T(emxArray_struct1_T **pEmxArray,
                                   int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ANCM_GetNoiseSeg_emxAPI.h
 *
 * [EOF]
 */
