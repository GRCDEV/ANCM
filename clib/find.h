/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: find.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef FIND_H
#define FIND_H

/* Include Files */
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_eml_find(const boolean_T x[10], int i_data[], int i_size[2]);

void eml_find(const emxArray_boolean_T *x, int i_data[], int i_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for find.h
 *
 * [EOF]
 */
