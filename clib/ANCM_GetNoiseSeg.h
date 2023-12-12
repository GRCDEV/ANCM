/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetNoiseSeg.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETNOISESEG_H
#define ANCM_GETNOISESEG_H

/* Include Files */
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern double ANCM_GetNoiseSeg(const struct0_T *Seg, const double Ob[3],
                               const emxArray_struct1_T *NPDdataSt,
                               const char NoiseMetric[3], char OpMode,
                               double Vref, const struct2_T *Aircraft,
                               const struct3_T *AtmCond, unsigned char trace);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ANCM_GetNoiseSeg.h
 *
 * [EOF]
 */
