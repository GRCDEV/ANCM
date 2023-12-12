/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetDeltaFSt.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETDELTAFST_H
#define ANCM_GETDELTAFST_H

/* Include Files */
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double ANCM_GetDeltaFSt(double Gd_lambda, double Gd_q, double Gd_D,
                        double Seg_isRolling, double Seg_P,
                        const emxArray_struct1_T *NPDdataSt, char OpMode,
                        double Vref);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ANCM_GetDeltaFSt.h
 *
 * [EOF]
 */
