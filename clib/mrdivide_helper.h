/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mrdivide_helper.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef MRDIVIDE_HELPER_H
#define MRDIVIDE_HELPER_H

/* Include Files */
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void d_binary_expand_op(double in1_data[], int *in1_size,
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int in3_size[2],
                        const emxArray_real_T *in4, const double in5_data[],
                        const int in5_size[2], const double in6_data[],
                        const int in6_size[2]);

void f_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int in3_size[2]);

void mrdiv(const double A_data[], const int A_size[2], const double B_data[],
           const int B_size[2], double Y_data[], int *Y_size);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for mrdivide_helper.h
 *
 * [EOF]
 */
