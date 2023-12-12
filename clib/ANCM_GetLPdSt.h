/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetLPdSt.h
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

#ifndef ANCM_GETLPDST_H
#define ANCM_GETLPDST_H

/* Include Files */
#include "ANCM_GetNoiseSeg_internal_types.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void L_int_d(const b_captured_var *LXft, const captured_var *Dis,
             const double id2_data[], const int id2_size[2],
             const double id1_data[], const int id1_size[2], double d,
             double Ld_data[], int Ld_size[2]);

void b_L_int_d(const b_captured_var *LXft, const captured_var *Dis,
               const double id2_data[], const int id2_size[2],
               const double id1_data[], const int id1_size[2], double d,
               double Ld_data[], int Ld_size[2]);

void b_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const emxArray_real_T *in3, double in4);

void binary_expand_op(double in1_data[], int in1_size[2],
                      const double in2_data[], const int in2_size[2],
                      const emxArray_real_T *in3, double in4);

void c_L_int_d(const b_captured_var *LXft, const captured_var *Dis, double iP,
               const double id2_data[], const int id2_size[2],
               const double id1_data[], const int id1_size[2], double d,
               double Ld_data[], int Ld_size[2]);

void c_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int *in3_size,
                        const struct0_T *in4, const double in5_data[],
                        const int in5_size[2]);

void d_L_int_d(const b_captured_var *LXft, const captured_var *Dis,
               const double iP_data[], const int iP_size[2],
               const double id2_data[], const int id2_size[2],
               const double id1_data[], const int id1_size[2], double d,
               double Ld_data[], int Ld_size[2]);

void eq(boolean_T in1_data[], int in1_size[2], const double in2_data[],
        const int in2_size[2], const double in3_data[], const int in3_size[2]);

void minus(double in1_data[], int in1_size[2], const double in2_data[],
           const int in2_size[2]);

void r_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int *in3_size,
                        double in4, const double in5_data[],
                        const int in5_size[2]);

void s_binary_expand_op(double in1_data[], int in1_size[2],
                        const emxArray_real_T *in2, const double in3_data[],
                        const int in3_size[2], const double in4_data[],
                        const int in4_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ANCM_GetLPdSt.h
 *
 * [EOF]
 */
