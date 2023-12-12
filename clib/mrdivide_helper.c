/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mrdivide_helper.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "mrdivide_helper.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double in1_data[]
 *                int *in1_size
 *                const double in2_data[]
 *                const int in2_size[2]
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const emxArray_real_T *in4
 *                const double in5_data[]
 *                const int in5_size[2]
 *                const double in6_data[]
 *                const int in6_size[2]
 * Return Type  : void
 */
void d_binary_expand_op(double in1_data[], int *in1_size,
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int in3_size[2],
                        const emxArray_real_T *in4, const double in5_data[],
                        const int in5_size[2], const double in6_data[],
                        const int in6_size[2])
{
  const double *in4_data;
  double b_in2_data;
  double b_in4_data;
  int b_in2_size[2];
  int in4_size[2];
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in4_data = in4->data;
  if (in3_size[0] == 1) {
    b_in2_size[0] = in2_size[0];
  } else {
    b_in2_size[0] = in3_size[0];
  }
  if (in3_size[1] == 1) {
    b_in2_size[1] = in2_size[1];
  } else {
    b_in2_size[1] = in3_size[1];
  }
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in3_size[1] == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = in3_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    i1 = in3_size[0];
    if (i1 == 1) {
      b_loop_ub = in2_size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in2_data =
          in2_data[in2_size[0] * aux_0_1] - in3_data[in3_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in4_size[0] = 1;
  if (in6_size[1] == 1) {
    in4_size[1] = in5_size[1];
    loop_ub = in5_size[1];
  } else {
    in4_size[1] = in6_size[1];
    loop_ub = in6_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in4_data = in4_data[(int)in5_data[0] - 1] - in6_data[0];
  }
  mrdiv((double *)&b_in2_data, b_in2_size, (double *)&b_in4_data, in4_size,
        in1_data, in1_size);
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 *                const double in3_data[]
 *                const int in3_size[2]
 * Return Type  : void
 */
void f_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int in3_size[2])
{
  int i;
  int loop_ub;
  in1_size[0] = 1;
  if (in3_size[1] == 1) {
    in1_size[1] = in2_size[1];
    loop_ub = in2_size[1];
  } else {
    in1_size[1] = in3_size[1];
    loop_ub = in3_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[0] = in2_data[0] - in3_data[0];
  }
}

/*
 * Arguments    : const double A_data[]
 *                const int A_size[2]
 *                const double B_data[]
 *                const int B_size[2]
 *                double Y_data[]
 *                int *Y_size
 * Return Type  : void
 */
void mrdiv(const double A_data[], const int A_size[2], const double B_data[],
           const int B_size[2], double Y_data[], int *Y_size)
{
  if ((A_size[0] == 0) || (A_size[1] == 0) || (B_size[1] == 0)) {
    int loop_ub;
    *Y_size = A_size[0];
    loop_ub = A_size[0];
    if (loop_ub - 1 >= 0) {
      Y_data[0] = 0.0;
    }
  } else {
    *Y_size = 1;
    Y_data[0] = A_data[0] / B_data[0];
  }
}

/*
 * File trailer for mrdivide_helper.c
 *
 * [EOF]
 */
