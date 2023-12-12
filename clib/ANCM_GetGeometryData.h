/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetGeometryData.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETGEOMETRYDATA_H
#define ANCM_GETGEOMETRYDATA_H

/* Include Files */
#include "ANCM_GetNoiseSeg_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ANCM_GetGeometryData(const double Seg_S1[3], const double Seg_S2[3],
                          double Seg_isRolling, double Seg_epsilon,
                          const double Ob[3], const char MOS[3], struct_T *Gd);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ANCM_GetGeometryData.h
 *
 * [EOF]
 */
