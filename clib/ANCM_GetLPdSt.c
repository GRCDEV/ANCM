/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetLPdSt.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "ANCM_GetLPdSt.h"
#include "ANCM_GetNoiseSeg_internal_types.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void b_minus(double in1_data[], int in1_size[2], const double in2_data[],
                    const int in2_size[2]);

static void e_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2]);

static void g_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2]);

static void h_binary_expand_op(double in1_data[], int *in1_size,
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size);

static void i_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2]);

static void j_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2]);

static void k_binary_expand_op(double in1_data[], int *in1_size,
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size);

static void l_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               double in4, const double in5_data[],
                               const int *in5_size, double in6,
                               const double in7_data[], const int in7_size[2]);

static void m_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               double in4, const double in5_data[],
                               const int *in5_size, double in6,
                               const double in7_data[], const int in7_size[2]);

static void n_binary_expand_op(double in1_data[], int *in1_size,
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               double in4, const double in5_data[],
                               const int *in5_size);

static void o_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               const double in5_data[], const int *in5_size,
                               double in6, const double in7_data[],
                               const int in7_size[2]);

static void p_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               const double in4_data[], const int *in4_size,
                               const double in5_data[], const int *in5_size,
                               double in6, const double in7_data[],
                               const int in7_size[2]);

static void q_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               const double in5_data[], const int *in5_size);

/* Function Definitions */
/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 * Return Type  : void
 */
static void b_minus(double in1_data[], int in1_size[2], const double in2_data[],
                    const int in2_size[2])
{
  double b_in1_data;
  int i;
  int in1_size_idx_1;
  int loop_ub;
  if (in2_size[1] == 1) {
    in1_size_idx_1 = in1_size[1];
    loop_ub = in1_size[1];
  } else {
    in1_size_idx_1 = in2_size[1];
    loop_ub = in2_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1_data = in1_data[0] - in2_data[0];
  }
  in1_size[0] = 1;
  in1_size[1] = in1_size_idx_1;
  for (i = 0; i < in1_size_idx_1; i++) {
    in1_data[0] = b_in1_data;
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4_data[]
 *                const int *in4_size
 *                double in5
 *                const double in6_data[]
 *                const int in6_size[2]
 * Return Type  : void
 */
static void e_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2])
{
  double b_in4_data;
  double in5_data;
  int i;
  int i1;
  int in3_idx_0;
  int in4_size_idx_0;
  int in5_size_idx_1;
  int loop_ub;
  in3_idx_0 = in3_size[1];
  in5_size_idx_1 = in6_size[1];
  loop_ub = in6_size[1];
  for (i = 0; i < loop_ub; i++) {
    in5_data = in5 - in6_data[0];
  }
  in4_size_idx_0 = *in4_size;
  for (i = 0; i < in5_size_idx_1; i++) {
    for (i1 = 0; i1 < *in4_size; i1++) {
      b_in4_data = in4_data[0] * in5_data;
    }
  }
  if (in4_size_idx_0 == 1) {
    in1_size[0] = in3_idx_0;
  } else {
    in1_size[0] = in4_size_idx_0;
  }
  in1_size[1] = in5_size_idx_1;
  for (i = 0; i < in5_size_idx_1; i++) {
    if (in4_size_idx_0 == 1) {
      loop_ub = in3_idx_0;
    } else {
      loop_ub = in4_size_idx_0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[0] = in2->contents->data[(int)in3_data[0] - 1] + b_in4_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int *in3_size
 *                const double in4_data[]
 *                const int *in4_size
 *                double in5
 *                const double in6_data[]
 *                const int in6_size[2]
 * Return Type  : void
 */
static void g_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2])
{
  double b_in4_data;
  double in5_data;
  int i;
  int i1;
  int in3_idx_0;
  int in4_size_idx_0;
  int in5_size_idx_1;
  int loop_ub;
  in3_idx_0 = *in3_size;
  in5_size_idx_1 = in6_size[1];
  loop_ub = in6_size[1];
  for (i = 0; i < loop_ub; i++) {
    in5_data = in5 - in6_data[0];
  }
  in4_size_idx_0 = *in4_size;
  for (i = 0; i < in5_size_idx_1; i++) {
    for (i1 = 0; i1 < *in4_size; i1++) {
      b_in4_data = in4_data[0] * in5_data;
    }
  }
  if (in4_size_idx_0 == 1) {
    in1_size[0] = in3_idx_0;
  } else {
    in1_size[0] = in4_size_idx_0;
  }
  in1_size[1] = in5_size_idx_1;
  for (i = 0; i < in5_size_idx_1; i++) {
    if (in4_size_idx_0 == 1) {
      loop_ub = in3_idx_0;
    } else {
      loop_ub = in4_size_idx_0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[0] = in2->contents->data[(int)in3_data[0] - 1] + b_in4_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int *in1_size
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4_data[]
 *                const int *in4_size
 * Return Type  : void
 */
static void h_binary_expand_op(double in1_data[], int *in1_size,
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size)
{
  int i;
  int loop_ub;
  if (*in4_size == 1) {
    *in1_size = in3_size[1];
    loop_ub = in3_size[1];
  } else {
    *in1_size = *in4_size;
    loop_ub = *in4_size;
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[0] = in2->contents->data[(int)in3_data[0] - 1] -
                  in2->contents->data[(int)in4_data[0] - 1];
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4_data[]
 *                const int *in4_size
 *                double in5
 *                const double in6_data[]
 *                const int in6_size[2]
 * Return Type  : void
 */
static void i_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2])
{
  double b_in4_data;
  double in5_data;
  int i;
  int i1;
  int in3_idx_0;
  int in4_size_idx_0;
  int in5_size_idx_1;
  int loop_ub;
  in3_idx_0 = in3_size[1];
  in5_size_idx_1 = in6_size[1];
  loop_ub = in6_size[1];
  for (i = 0; i < loop_ub; i++) {
    in5_data = in5 - in6_data[0];
  }
  in4_size_idx_0 = *in4_size;
  for (i = 0; i < in5_size_idx_1; i++) {
    for (i1 = 0; i1 < *in4_size; i1++) {
      b_in4_data = in4_data[0] * in5_data;
    }
  }
  if (in4_size_idx_0 == 1) {
    in1_size[0] = in3_idx_0;
  } else {
    in1_size[0] = in4_size_idx_0;
  }
  in1_size[1] = in5_size_idx_1;
  for (i = 0; i < in5_size_idx_1; i++) {
    if (in4_size_idx_0 == 1) {
      loop_ub = in3_idx_0;
    } else {
      loop_ub = in4_size_idx_0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[0] = in2->contents->data[(int)in3_data[0] + 9] + b_in4_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int *in3_size
 *                const double in4_data[]
 *                const int *in4_size
 *                double in5
 *                const double in6_data[]
 *                const int in6_size[2]
 * Return Type  : void
 */
static void j_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               const double in4_data[], const int *in4_size,
                               double in5, const double in6_data[],
                               const int in6_size[2])
{
  double b_in4_data;
  double in5_data;
  int i;
  int i1;
  int in3_idx_0;
  int in4_size_idx_0;
  int in5_size_idx_1;
  int loop_ub;
  in3_idx_0 = *in3_size;
  in5_size_idx_1 = in6_size[1];
  loop_ub = in6_size[1];
  for (i = 0; i < loop_ub; i++) {
    in5_data = in5 - in6_data[0];
  }
  in4_size_idx_0 = *in4_size;
  for (i = 0; i < in5_size_idx_1; i++) {
    for (i1 = 0; i1 < *in4_size; i1++) {
      b_in4_data = in4_data[0] * in5_data;
    }
  }
  if (in4_size_idx_0 == 1) {
    in1_size[0] = in3_idx_0;
  } else {
    in1_size[0] = in4_size_idx_0;
  }
  in1_size[1] = in5_size_idx_1;
  for (i = 0; i < in5_size_idx_1; i++) {
    if (in4_size_idx_0 == 1) {
      loop_ub = in3_idx_0;
    } else {
      loop_ub = in4_size_idx_0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[0] = in2->contents->data[(int)in3_data[0] + 9] + b_in4_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int *in1_size
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4_data[]
 *                const int *in4_size
 * Return Type  : void
 */
static void k_binary_expand_op(double in1_data[], int *in1_size,
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size)
{
  int i;
  int loop_ub;
  if (*in4_size == 1) {
    *in1_size = in3_size[1];
    loop_ub = in3_size[1];
  } else {
    *in1_size = *in4_size;
    loop_ub = *in4_size;
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[0] = in2->contents->data[(int)in3_data[0] + 9] -
                  in2->contents->data[(int)in4_data[0] + 9];
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                double in4
 *                const double in5_data[]
 *                const int *in5_size
 *                double in6
 *                const double in7_data[]
 *                const int in7_size[2]
 * Return Type  : void
 */
static void l_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               double in4, const double in5_data[],
                               const int *in5_size, double in6,
                               const double in7_data[], const int in7_size[2])
{
  double b_in5_data;
  double in6_data;
  int i;
  int i1;
  int in3_idx_0;
  int in5_size_idx_0;
  int in6_size_idx_1;
  int loop_ub;
  in3_idx_0 = in3_size[1];
  in6_size_idx_1 = in7_size[1];
  loop_ub = in7_size[1];
  for (i = 0; i < loop_ub; i++) {
    in6_data = in6 - in7_data[0];
  }
  in5_size_idx_0 = *in5_size;
  for (i = 0; i < in6_size_idx_1; i++) {
    for (i1 = 0; i1 < *in5_size; i1++) {
      b_in5_data = in5_data[0] * in6_data;
    }
  }
  if (in5_size_idx_0 == 1) {
    in1_size[0] = in3_idx_0;
  } else {
    in1_size[0] = in5_size_idx_0;
  }
  in1_size[1] = in6_size_idx_1;
  for (i = 0; i < in6_size_idx_1; i++) {
    if (in5_size_idx_0 == 1) {
      loop_ub = in3_idx_0;
    } else {
      loop_ub = in5_size_idx_0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[0] =
          in2->contents->data[((int)in3_data[0] + 10 * ((int)in4 - 1)) - 1] +
          b_in5_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int *in3_size
 *                double in4
 *                const double in5_data[]
 *                const int *in5_size
 *                double in6
 *                const double in7_data[]
 *                const int in7_size[2]
 * Return Type  : void
 */
static void m_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               double in4, const double in5_data[],
                               const int *in5_size, double in6,
                               const double in7_data[], const int in7_size[2])
{
  double b_in5_data;
  double in6_data;
  int i;
  int i1;
  int in3_idx_0;
  int in5_size_idx_0;
  int in6_size_idx_1;
  int loop_ub;
  in3_idx_0 = *in3_size;
  in6_size_idx_1 = in7_size[1];
  loop_ub = in7_size[1];
  for (i = 0; i < loop_ub; i++) {
    in6_data = in6 - in7_data[0];
  }
  in5_size_idx_0 = *in5_size;
  for (i = 0; i < in6_size_idx_1; i++) {
    for (i1 = 0; i1 < *in5_size; i1++) {
      b_in5_data = in5_data[0] * in6_data;
    }
  }
  if (in5_size_idx_0 == 1) {
    in1_size[0] = in3_idx_0;
  } else {
    in1_size[0] = in5_size_idx_0;
  }
  in1_size[1] = in6_size_idx_1;
  for (i = 0; i < in6_size_idx_1; i++) {
    if (in5_size_idx_0 == 1) {
      loop_ub = in3_idx_0;
    } else {
      loop_ub = in5_size_idx_0;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[0] =
          in2->contents->data[((int)in3_data[0] + 10 * ((int)in4 - 1)) - 1] +
          b_in5_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int *in1_size
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                double in4
 *                const double in5_data[]
 *                const int *in5_size
 * Return Type  : void
 */
static void n_binary_expand_op(double in1_data[], int *in1_size,
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               double in4, const double in5_data[],
                               const int *in5_size)
{
  int i;
  int loop_ub;
  if (*in5_size == 1) {
    *in1_size = in3_size[1];
    loop_ub = in3_size[1];
  } else {
    *in1_size = *in5_size;
    loop_ub = *in5_size;
  }
  for (i = 0; i < loop_ub; i++) {
    int i1;
    i1 = 10 * ((int)in4 - 1);
    in1_data[0] = in2->contents->data[((int)in3_data[0] + i1) - 1] -
                  in2->contents->data[((int)in5_data[0] + i1) - 1];
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4_data[]
 *                const int *in4_size
 *                const double in5_data[]
 *                const int *in5_size
 *                double in6
 *                const double in7_data[]
 *                const int in7_size[2]
 * Return Type  : void
 */
static void o_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               const double in5_data[], const int *in5_size,
                               double in6, const double in7_data[],
                               const int in7_size[2])
{
  double b_in5_data;
  double in6_data;
  int aux_0_1;
  int i;
  int i1;
  int in5_size_idx_0;
  int in6_size_idx_1;
  int loop_ub;
  int stride_0_1;
  in6_size_idx_1 = in7_size[1];
  loop_ub = in7_size[1];
  for (i = 0; i < loop_ub; i++) {
    in6_data = in6 - in7_data[0];
  }
  in5_size_idx_0 = *in5_size;
  for (i = 0; i < in6_size_idx_1; i++) {
    for (i1 = 0; i1 < *in5_size; i1++) {
      b_in5_data = in5_data[0] * in6_data;
    }
  }
  if (in5_size_idx_0 == 1) {
    in1_size[0] = in3_size[1];
  } else {
    in1_size[0] = in5_size_idx_0;
  }
  if (in6_size_idx_1 == 1) {
    in1_size[1] = *in4_size;
  } else {
    in1_size[1] = in6_size_idx_1;
  }
  stride_0_1 = (*in4_size != 1);
  aux_0_1 = 0;
  if (in6_size_idx_1 == 1) {
    loop_ub = *in4_size;
  } else {
    loop_ub = in6_size_idx_1;
  }
  for (i = 0; i < loop_ub; i++) {
    if (in5_size_idx_0 == 1) {
      in6_size_idx_1 = in3_size[1];
    } else {
      in6_size_idx_1 = in5_size_idx_0;
    }
    for (i1 = 0; i1 < in6_size_idx_1; i1++) {
      in1_data[0] =
          in2->contents
              ->data[((int)in3_data[0] + 10 * ((int)in4_data[aux_0_1] - 1)) -
                     1] +
          b_in5_data;
    }
    aux_0_1 += stride_0_1;
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int *in3_size
 *                const double in4_data[]
 *                const int *in4_size
 *                const double in5_data[]
 *                const int *in5_size
 *                double in6
 *                const double in7_data[]
 *                const int in7_size[2]
 * Return Type  : void
 */
static void p_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int *in3_size,
                               const double in4_data[], const int *in4_size,
                               const double in5_data[], const int *in5_size,
                               double in6, const double in7_data[],
                               const int in7_size[2])
{
  double b_in5_data;
  double in6_data;
  int aux_0_1;
  int i;
  int i1;
  int in5_size_idx_0;
  int in6_size_idx_1;
  int loop_ub;
  int stride_0_1;
  in6_size_idx_1 = in7_size[1];
  loop_ub = in7_size[1];
  for (i = 0; i < loop_ub; i++) {
    in6_data = in6 - in7_data[0];
  }
  in5_size_idx_0 = *in5_size;
  for (i = 0; i < in6_size_idx_1; i++) {
    for (i1 = 0; i1 < *in5_size; i1++) {
      b_in5_data = in5_data[0] * in6_data;
    }
  }
  if (in5_size_idx_0 == 1) {
    in1_size[0] = *in3_size;
  } else {
    in1_size[0] = in5_size_idx_0;
  }
  if (in6_size_idx_1 == 1) {
    in1_size[1] = *in4_size;
  } else {
    in1_size[1] = in6_size_idx_1;
  }
  stride_0_1 = (*in4_size != 1);
  aux_0_1 = 0;
  if (in6_size_idx_1 == 1) {
    loop_ub = *in4_size;
  } else {
    loop_ub = in6_size_idx_1;
  }
  for (i = 0; i < loop_ub; i++) {
    if (in5_size_idx_0 == 1) {
      in6_size_idx_1 = *in3_size;
    } else {
      in6_size_idx_1 = in5_size_idx_0;
    }
    for (i1 = 0; i1 < in6_size_idx_1; i1++) {
      in1_data[0] =
          in2->contents
              ->data[((int)in3_data[0] + 10 * ((int)in4_data[aux_0_1] - 1)) -
                     1] +
          b_in5_data;
    }
    aux_0_1 += stride_0_1;
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const b_captured_var *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4_data[]
 *                const int *in4_size
 *                const double in5_data[]
 *                const int *in5_size
 * Return Type  : void
 */
static void q_binary_expand_op(double in1_data[], int in1_size[2],
                               const b_captured_var *in2,
                               const double in3_data[], const int in3_size[2],
                               const double in4_data[], const int *in4_size,
                               const double in5_data[], const int *in5_size)
{
  int i;
  int i1;
  if (*in5_size == 1) {
    in1_size[0] = in3_size[1];
  } else {
    in1_size[0] = *in5_size;
  }
  in1_size[1] = *in4_size;
  for (i = 0; i < *in4_size; i++) {
    int loop_ub;
    i1 = *in5_size;
    if (i1 == 1) {
      loop_ub = in3_size[1];
    } else {
      loop_ub = i1;
    }
    for (i1 = 0; i1 < loop_ub; i1++) {
      int i2;
      i2 = (int)in4_data[0] - 1;
      in1_data[0] = in2->contents->data[((int)in3_data[0] + 10 * i2) - 1] -
                    in2->contents->data[((int)in5_data[0] + 10 * i2) - 1];
    }
  }
}

/*
 * Eq. 4.4. and 4.5a/4.6b
 *
 * Arguments    : const b_captured_var *LXft
 *                const captured_var *Dis
 *                const double id2_data[]
 *                const int id2_size[2]
 *                const double id1_data[]
 *                const int id1_size[2]
 *                double d
 *                double Ld_data[]
 *                int Ld_size[2]
 * Return Type  : void
 */
void L_int_d(const b_captured_var *LXft, const captured_var *Dis,
             const double id2_data[], const int id2_size[2],
             const double id1_data[], const int id1_size[2], double d,
             double Ld_data[], int Ld_size[2])
{
  double A_data;
  double B_data;
  int b_tmp_size[2];
  int b_x_size[2];
  int x_size[2];
  int A_size;
  int i;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T x_data;
  boolean_T y;
  /*  Obtain the noise level using the tables */
  /*      function Lout = L(id,iP) */
  /*          % id index of the distance */
  /*          % iP index of the Power */
  /*          Lout = table2array(NPDdata_f(iP,4+id));  */
  /*      end */
  x_size[0] = 1;
  x_size[1] = id1_size[1];
  loop_ub = id1_size[1];
  for (i = 0; i < loop_ub; i++) {
    x_data = (id1_data[0] == 0.0);
  }
  y = (id1_size[1] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data) {
        y = false;
        exitg1 = true;
      } else {
        k = 1;
      }
    }
  }
  if (y) {
    /*  inwards equation 4.5a */
    Ld_size[0] = 1;
    Ld_size[1] = 1;
    A_data = log(Dis->contents[1]);
    Ld_data[0] = LXft->contents->data[1] +
                 (LXft->contents->data[0] - LXft->contents->data[1]) /
                     (A_data - log(Dis->contents[0])) * (A_data - log(d));
  } else {
    if (id1_size[1] == id2_size[1]) {
      x_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        x_data = (id1_data[0] == id2_data[0]);
      }
    } else {
      eq((boolean_T *)&x_data, x_size, id1_data, id1_size, id2_data, id2_size);
    }
    y = (x_size[1] != 0);
    if (y) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size[1] - 1)) {
        if (!x_data) {
          y = false;
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
    if (y) {
      double b_tmp_data;
      double b_x_data;
      double tmp_data;
      /*  outwards equation 4.5b -> the formula in the doc. is incorrect */
      /*  Ld = L(id1-1,iP)+
       * (L(id1-1,iP)-L(id1,iP))/(reallog(Dis(id1))-reallog(Dis(id1-1)))*
       * (reallog(d)-reallog(Dis(id1-1))); */
      /*  The use of reallog is to avoid generating imaginary numbers */
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        A_data = LXft->contents->data[(int)id1_data[0] - 1];
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data = LXft->contents->data[(int)(id1_data[0] - 1.0) - 1];
      }
      b_tmp_size[0] = 1;
      b_tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_tmp_data = log(b_tmp_data);
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)(id1_data[0] - 1.0) - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        A_data -= tmp_data;
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        B_data = b_tmp_data - b_x_data;
      }
      if (id1_size[1] == 0) {
        A_size = 0;
      } else {
        A_size = 1;
        B_data = A_data / B_data;
      }
      A_data = log(d);
      if (A_size == id1_size[1]) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = A_data - b_tmp_data;
        }
        k = id1_size[1];
        loop_ub = id1_size[1];
        if (loop_ub - 1 >= 0) {
          for (i = 0; i < A_size; i++) {
            A_data = B_data * b_x_data;
          }
        }
        Ld_size[0] = id1_size[1];
        Ld_size[1] = id1_size[1];
        if (k - 1 >= 0) {
          loop_ub = id1_size[1];
          if (loop_ub - 1 >= 0) {
            Ld_data[0] = LXft->contents->data[(int)id1_data[0] - 1] + A_data;
          }
        }
      } else {
        e_binary_expand_op(Ld_data, Ld_size, LXft, id1_data, id1_size,
                           (double *)&B_data, &A_size, A_data,
                           (double *)&b_tmp_data, b_tmp_size);
      }
    } else {
      double b_tmp_data;
      double b_x_data;
      double tmp_data;
      int tmp_size;
      tmp_size = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data = id1_data[0];
      }
      b_tmp_size[0] = 1;
      b_tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_tmp_data = log(b_tmp_data);
      }
      if (id1_size[1] == id2_size[1]) {
        A_size = id2_size[1];
        loop_ub = id2_size[1];
        for (i = 0; i < loop_ub; i++) {
          A_data = LXft->contents->data[(int)id2_data[0] - 1] -
                   LXft->contents->data[(int)tmp_data - 1];
        }
      } else {
        h_binary_expand_op((double *)&A_data, &A_size, LXft, id2_data, id2_size,
                           (double *)&tmp_data, &id1_size[1]);
      }
      b_x_size[0] = 1;
      b_x_size[1] = id2_size[1];
      loop_ub = id2_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)id2_data[0] - 1];
      }
      i = id2_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      if (id2_size[1] == id1_size[1]) {
        loop_ub = id2_size[1];
        for (i = 0; i < loop_ub; i++) {
          B_data = b_x_data - b_tmp_data;
        }
      } else {
        f_binary_expand_op((double *)&B_data, x_size, (double *)&b_x_data,
                           b_x_size, (double *)&b_tmp_data, b_tmp_size);
      }
      if (A_size == 0) {
        A_size = 0;
      } else {
        A_size = 1;
        B_data = A_data / B_data;
      }
      A_data = log(d);
      if (id1_size[1] == A_size) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = A_data - b_tmp_data;
        }
        k = id1_size[1];
        loop_ub = id1_size[1];
        if (loop_ub - 1 >= 0) {
          for (i = 0; i < A_size; i++) {
            A_data = B_data * b_x_data;
          }
        }
        Ld_size[0] = id1_size[1];
        Ld_size[1] = id1_size[1];
        if ((k - 1 >= 0) && (tmp_size - 1 >= 0)) {
          Ld_data[0] = LXft->contents->data[(int)tmp_data - 1] + A_data;
        }
      } else {
        g_binary_expand_op(Ld_data, Ld_size, LXft, (double *)&tmp_data,
                           &id1_size[1], (double *)&B_data, &A_size, A_data,
                           (double *)&b_tmp_data, b_tmp_size);
      }
    }
  }
}

/*
 * Eq. 4.4. and 4.5a/4.6b
 *
 * Arguments    : const b_captured_var *LXft
 *                const captured_var *Dis
 *                const double id2_data[]
 *                const int id2_size[2]
 *                const double id1_data[]
 *                const int id1_size[2]
 *                double d
 *                double Ld_data[]
 *                int Ld_size[2]
 * Return Type  : void
 */
void b_L_int_d(const b_captured_var *LXft, const captured_var *Dis,
               const double id2_data[], const int id2_size[2],
               const double id1_data[], const int id1_size[2], double d,
               double Ld_data[], int Ld_size[2])
{
  double A_data;
  double B_data;
  int b_tmp_size[2];
  int b_x_size[2];
  int x_size[2];
  int A_size;
  int i;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T x_data;
  boolean_T y;
  /*  Obtain the noise level using the tables */
  /*      function Lout = L(id,iP) */
  /*          % id index of the distance */
  /*          % iP index of the Power */
  /*          Lout = table2array(NPDdata_f(iP,4+id));  */
  /*      end */
  x_size[0] = 1;
  x_size[1] = id1_size[1];
  loop_ub = id1_size[1];
  for (i = 0; i < loop_ub; i++) {
    x_data = (id1_data[0] == 0.0);
  }
  y = (id1_size[1] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data) {
        y = false;
        exitg1 = true;
      } else {
        k = 1;
      }
    }
  }
  if (y) {
    /*  inwards equation 4.5a */
    Ld_size[0] = 1;
    Ld_size[1] = 1;
    A_data = log(Dis->contents[1]);
    Ld_data[0] = LXft->contents->data[11] +
                 (LXft->contents->data[10] - LXft->contents->data[11]) /
                     (A_data - log(Dis->contents[0])) * (A_data - log(d));
  } else {
    if (id1_size[1] == id2_size[1]) {
      x_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        x_data = (id1_data[0] == id2_data[0]);
      }
    } else {
      eq((boolean_T *)&x_data, x_size, id1_data, id1_size, id2_data, id2_size);
    }
    y = (x_size[1] != 0);
    if (y) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size[1] - 1)) {
        if (!x_data) {
          y = false;
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
    if (y) {
      double b_tmp_data;
      double b_x_data;
      double tmp_data;
      /*  outwards equation 4.5b -> the formula in the doc. is incorrect */
      /*  Ld = L(id1-1,iP)+
       * (L(id1-1,iP)-L(id1,iP))/(reallog(Dis(id1))-reallog(Dis(id1-1)))*
       * (reallog(d)-reallog(Dis(id1-1))); */
      /*  The use of reallog is to avoid generating imaginary numbers */
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        A_data = LXft->contents->data[(int)id1_data[0] + 9];
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data = LXft->contents->data[(int)(id1_data[0] - 1.0) + 9];
      }
      b_tmp_size[0] = 1;
      b_tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_tmp_data = log(b_tmp_data);
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)(id1_data[0] - 1.0) - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        A_data -= tmp_data;
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        B_data = b_tmp_data - b_x_data;
      }
      if (id1_size[1] == 0) {
        A_size = 0;
      } else {
        A_size = 1;
        B_data = A_data / B_data;
      }
      A_data = log(d);
      if (A_size == id1_size[1]) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = A_data - b_tmp_data;
        }
        k = id1_size[1];
        loop_ub = id1_size[1];
        if (loop_ub - 1 >= 0) {
          for (i = 0; i < A_size; i++) {
            A_data = B_data * b_x_data;
          }
        }
        Ld_size[0] = id1_size[1];
        Ld_size[1] = id1_size[1];
        if (k - 1 >= 0) {
          loop_ub = id1_size[1];
          if (loop_ub - 1 >= 0) {
            Ld_data[0] = LXft->contents->data[(int)id1_data[0] + 9] + A_data;
          }
        }
      } else {
        i_binary_expand_op(Ld_data, Ld_size, LXft, id1_data, id1_size,
                           (double *)&B_data, &A_size, A_data,
                           (double *)&b_tmp_data, b_tmp_size);
      }
    } else {
      double b_tmp_data;
      double b_x_data;
      double tmp_data;
      int tmp_size;
      tmp_size = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data = id1_data[0];
      }
      b_tmp_size[0] = 1;
      b_tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_tmp_data = log(b_tmp_data);
      }
      if (id1_size[1] == id2_size[1]) {
        A_size = id2_size[1];
        loop_ub = id2_size[1];
        for (i = 0; i < loop_ub; i++) {
          A_data = LXft->contents->data[(int)id2_data[0] + 9] -
                   LXft->contents->data[(int)tmp_data + 9];
        }
      } else {
        k_binary_expand_op((double *)&A_data, &A_size, LXft, id2_data, id2_size,
                           (double *)&tmp_data, &id1_size[1]);
      }
      b_x_size[0] = 1;
      b_x_size[1] = id2_size[1];
      loop_ub = id2_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)id2_data[0] - 1];
      }
      i = id2_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      if (id2_size[1] == id1_size[1]) {
        loop_ub = id2_size[1];
        for (i = 0; i < loop_ub; i++) {
          B_data = b_x_data - b_tmp_data;
        }
      } else {
        f_binary_expand_op((double *)&B_data, x_size, (double *)&b_x_data,
                           b_x_size, (double *)&b_tmp_data, b_tmp_size);
      }
      if (A_size == 0) {
        A_size = 0;
      } else {
        A_size = 1;
        B_data = A_data / B_data;
      }
      A_data = log(d);
      if (id1_size[1] == A_size) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = A_data - b_tmp_data;
        }
        k = id1_size[1];
        loop_ub = id1_size[1];
        if (loop_ub - 1 >= 0) {
          for (i = 0; i < A_size; i++) {
            A_data = B_data * b_x_data;
          }
        }
        Ld_size[0] = id1_size[1];
        Ld_size[1] = id1_size[1];
        if ((k - 1 >= 0) && (tmp_size - 1 >= 0)) {
          Ld_data[0] = LXft->contents->data[(int)tmp_data + 9] + A_data;
        }
      } else {
        j_binary_expand_op(Ld_data, Ld_size, LXft, (double *)&tmp_data,
                           &id1_size[1], (double *)&B_data, &A_size, A_data,
                           (double *)&b_tmp_data, b_tmp_size);
      }
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 *                const emxArray_real_T *in3
 *                double in4
 * Return Type  : void
 */
void b_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const emxArray_real_T *in3, double in4)
{
  const double *in3_data;
  double b_in1_data;
  double b_in3;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int i;
  int i1;
  int in1_size_idx_0;
  int in1_size_idx_1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  in3_data = in3->data;
  b_in3 = in3_data[in3->size[1] - 1] - in3_data[in3->size[1] - 2];
  if (in2_size[0] == 1) {
    i = in1_size[0];
  } else {
    i = in2_size[0];
  }
  if (i == 1) {
    in1_size_idx_0 = in1_size[0];
  } else if (in2_size[0] == 1) {
    in1_size_idx_0 = in1_size[0];
  } else {
    in1_size_idx_0 = in2_size[0];
  }
  if (in2_size[1] == 1) {
    i = in1_size[1];
  } else {
    i = in2_size[1];
  }
  if (i == 1) {
    in1_size_idx_1 = in1_size[1];
  } else if (in2_size[1] == 1) {
    in1_size_idx_1 = in1_size[1];
  } else {
    in1_size_idx_1 = in2_size[1];
  }
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  stride_2_1 = (in2_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  if (in2_size[1] == 1) {
    i = in1_size[1];
  } else {
    i = in2_size[1];
  }
  if (i == 1) {
    loop_ub = in1_size[1];
  } else if (in2_size[1] == 1) {
    loop_ub = in1_size[1];
  } else {
    loop_ub = in2_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    int i2;
    i1 = in2_size[0];
    b_loop_ub = in1_size[0];
    if (i1 == 1) {
      i2 = b_loop_ub;
    } else {
      i2 = i1;
    }
    if ((i2 != 1) && (i1 != 1)) {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1_data =
          in1_data[in1_size[0] * aux_0_1] +
          (in1_data[in1_size[0] * aux_1_1] - in2_data[in2_size[0] * aux_2_1]) /
              b_in3 * in4;
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = in1_size_idx_0;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    for (i = 0; i < in1_size_idx_0; i++) {
      in1_data[0] = b_in1_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 *                const emxArray_real_T *in3
 *                double in4
 * Return Type  : void
 */
void binary_expand_op(double in1_data[], int in1_size[2],
                      const double in2_data[], const int in2_size[2],
                      const emxArray_real_T *in3, double in4)
{
  const double *in3_data;
  double b_in1_data;
  double b_in3;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int i;
  int i1;
  int in1_size_idx_0;
  int in1_size_idx_1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  in3_data = in3->data;
  b_in3 = in3_data[1] - in3_data[0];
  if (in1_size[0] == 1) {
    i = in2_size[0];
  } else {
    i = in1_size[0];
  }
  if (i == 1) {
    in1_size_idx_0 = in1_size[0];
  } else if (in1_size[0] == 1) {
    in1_size_idx_0 = in2_size[0];
  } else {
    in1_size_idx_0 = in1_size[0];
  }
  if (in1_size[1] == 1) {
    i = in2_size[1];
  } else {
    i = in1_size[1];
  }
  if (i == 1) {
    in1_size_idx_1 = in1_size[1];
  } else if (in1_size[1] == 1) {
    in1_size_idx_1 = in2_size[1];
  } else {
    in1_size_idx_1 = in1_size[1];
  }
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  stride_2_1 = (in1_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  if (in1_size[1] == 1) {
    i = in2_size[1];
  } else {
    i = in1_size[1];
  }
  if (i == 1) {
    loop_ub = in1_size[1];
  } else if (in1_size[1] == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = in1_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    int i2;
    i1 = in1_size[0];
    b_loop_ub = in2_size[0];
    if (i1 == 1) {
      i2 = b_loop_ub;
    } else {
      i2 = i1;
    }
    if (i2 == 1) {
      b_loop_ub = i1;
    } else if (i1 != 1) {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1_data =
          in1_data[in1_size[0] * aux_0_1] +
          (in2_data[in2_size[0] * aux_1_1] - in1_data[in1_size[0] * aux_2_1]) /
              b_in3 * in4;
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = in1_size_idx_0;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    for (i = 0; i < in1_size_idx_0; i++) {
      in1_data[0] = b_in1_data;
    }
  }
}

/*
 * Eq. 4.4. and 4.5a/4.6b
 *
 * Arguments    : const b_captured_var *LXft
 *                const captured_var *Dis
 *                double iP
 *                const double id2_data[]
 *                const int id2_size[2]
 *                const double id1_data[]
 *                const int id1_size[2]
 *                double d
 *                double Ld_data[]
 *                int Ld_size[2]
 * Return Type  : void
 */
void c_L_int_d(const b_captured_var *LXft, const captured_var *Dis, double iP,
               const double id2_data[], const int id2_size[2],
               const double id1_data[], const int id1_size[2], double d,
               double Ld_data[], int Ld_size[2])
{
  double A_data;
  double B_data;
  int b_tmp_size[2];
  int b_x_size[2];
  int x_size[2];
  int A_size;
  int i;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T x_data;
  boolean_T y;
  /*  Obtain the noise level using the tables */
  /*      function Lout = L(id,iP) */
  /*          % id index of the distance */
  /*          % iP index of the Power */
  /*          Lout = table2array(NPDdata_f(iP,4+id));  */
  /*      end */
  x_size[0] = 1;
  x_size[1] = id1_size[1];
  loop_ub = id1_size[1];
  for (i = 0; i < loop_ub; i++) {
    x_data = (id1_data[0] == 0.0);
  }
  y = (id1_size[1] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data) {
        y = false;
        exitg1 = true;
      } else {
        k = 1;
      }
    }
  }
  if (y) {
    /*  inwards equation 4.5a */
    Ld_size[0] = 1;
    Ld_size[1] = 1;
    B_data = log(Dis->contents[1]);
    i = 10 * ((int)iP - 1);
    A_data = LXft->contents->data[i + 1];
    Ld_data[0] = A_data + (LXft->contents->data[i] - A_data) /
                              (B_data - log(Dis->contents[0])) *
                              (B_data - log(d));
  } else {
    if (id1_size[1] == id2_size[1]) {
      x_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        x_data = (id1_data[0] == id2_data[0]);
      }
    } else {
      eq((boolean_T *)&x_data, x_size, id1_data, id1_size, id2_data, id2_size);
    }
    y = (x_size[1] != 0);
    if (y) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size[1] - 1)) {
        if (!x_data) {
          y = false;
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
    if (y) {
      double Y_data;
      double b_tmp_data;
      double b_x_data;
      double tmp_data;
      /*  outwards equation 4.5b -> the formula in the doc. is incorrect */
      /*  Ld = L(id1-1,iP)+
       * (L(id1-1,iP)-L(id1,iP))/(reallog(Dis(id1))-reallog(Dis(id1-1)))*
       * (reallog(d)-reallog(Dis(id1-1))); */
      /*  The use of reallog is to avoid generating imaginary numbers */
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        A_data =
            LXft->contents->data[((int)id1_data[0] + 10 * ((int)iP - 1)) - 1];
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data =
            LXft->contents
                ->data[((int)(id1_data[0] - 1.0) + 10 * ((int)iP - 1)) - 1];
      }
      b_tmp_size[0] = 1;
      b_tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_tmp_data = log(b_tmp_data);
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)(id1_data[0] - 1.0) - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        A_data -= tmp_data;
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        B_data = b_tmp_data - b_x_data;
      }
      if (id1_size[1] == 0) {
        k = 0;
      } else {
        k = 1;
        Y_data = A_data / B_data;
      }
      A_data = log(d);
      if (k == id1_size[1]) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = A_data - b_tmp_data;
        }
        A_size = id1_size[1];
        loop_ub = id1_size[1];
        if (loop_ub - 1 >= 0) {
          for (i = 0; i < k; i++) {
            B_data = Y_data * b_x_data;
          }
        }
        Ld_size[0] = id1_size[1];
        Ld_size[1] = id1_size[1];
        if (A_size - 1 >= 0) {
          loop_ub = id1_size[1];
          if (loop_ub - 1 >= 0) {
            Ld_data[0] =
                LXft->contents
                    ->data[((int)id1_data[0] + 10 * ((int)iP - 1)) - 1] +
                B_data;
          }
        }
      } else {
        l_binary_expand_op(Ld_data, Ld_size, LXft, id1_data, id1_size, iP,
                           (double *)&Y_data, &k, A_data, (double *)&b_tmp_data,
                           b_tmp_size);
      }
    } else {
      double Y_data;
      double b_tmp_data;
      double b_x_data;
      double tmp_data;
      int tmp_size;
      tmp_size = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data = id1_data[0];
      }
      b_tmp_size[0] = 1;
      b_tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_tmp_data = log(b_tmp_data);
      }
      if (id1_size[1] == id2_size[1]) {
        A_size = id2_size[1];
        loop_ub = id2_size[1];
        for (i = 0; i < loop_ub; i++) {
          k = 10 * ((int)iP - 1);
          A_data = LXft->contents->data[((int)id2_data[0] + k) - 1] -
                   LXft->contents->data[((int)tmp_data + k) - 1];
        }
      } else {
        n_binary_expand_op((double *)&A_data, &A_size, LXft, id2_data, id2_size,
                           iP, (double *)&tmp_data, &id1_size[1]);
      }
      b_x_size[0] = 1;
      b_x_size[1] = id2_size[1];
      loop_ub = id2_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)id2_data[0] - 1];
      }
      i = id2_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      if (id2_size[1] == id1_size[1]) {
        loop_ub = id2_size[1];
        for (i = 0; i < loop_ub; i++) {
          B_data = b_x_data - b_tmp_data;
        }
      } else {
        f_binary_expand_op((double *)&B_data, x_size, (double *)&b_x_data,
                           b_x_size, (double *)&b_tmp_data, b_tmp_size);
      }
      if (A_size == 0) {
        k = 0;
      } else {
        k = 1;
        Y_data = A_data / B_data;
      }
      A_data = log(d);
      if (id1_size[1] == k) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = A_data - b_tmp_data;
        }
        A_size = id1_size[1];
        loop_ub = id1_size[1];
        if (loop_ub - 1 >= 0) {
          for (i = 0; i < k; i++) {
            B_data = Y_data * b_x_data;
          }
        }
        Ld_size[0] = id1_size[1];
        Ld_size[1] = id1_size[1];
        if ((A_size - 1 >= 0) && (tmp_size - 1 >= 0)) {
          Ld_data[0] =
              LXft->contents->data[((int)tmp_data + 10 * ((int)iP - 1)) - 1] +
              B_data;
        }
      } else {
        m_binary_expand_op(Ld_data, Ld_size, LXft, (double *)&tmp_data,
                           &id1_size[1], iP, (double *)&Y_data, &k, A_data,
                           (double *)&b_tmp_data, b_tmp_size);
      }
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 *                const double in3_data[]
 *                const int *in3_size
 *                const struct0_T *in4
 *                const double in5_data[]
 *                const int in5_size[2]
 * Return Type  : void
 */
void c_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int *in3_size,
                        const struct0_T *in4, const double in5_data[],
                        const int in5_size[2])
{
  double in4_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int in2_size_idx_1;
  int in4_size_idx_1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in4_size_idx_1 = in5_size[1];
  loop_ub = in5_size[1];
  for (i = 0; i < loop_ub; i++) {
    in4_data = in4->P - in5_data[0];
  }
  in1_size[0] = *in3_size;
  in1_size[1] = in4_size_idx_1;
  for (i = 0; i < in4_size_idx_1; i++) {
    for (i1 = 0; i1 < *in3_size; i1++) {
      in1_data[0] = in3_data[0] * in4_data;
    }
  }
  if (in1_size[0] == 1) {
    in4_size_idx_1 = in2_size[0];
  } else {
    in4_size_idx_1 = in1_size[0];
  }
  if (in1_size[1] == 1) {
    in2_size_idx_1 = in2_size[1];
  } else {
    in2_size_idx_1 = in1_size[1];
  }
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in1_size[1] == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = in1_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    i1 = in1_size[0];
    if (i1 == 1) {
      b_loop_ub = in2_size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in4_data =
          in2_data[in2_size[0] * aux_0_1] + in1_data[in1_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = in4_size_idx_1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    for (i = 0; i < in4_size_idx_1; i++) {
      in1_data[0] = in4_data;
    }
  }
}

/*
 * Eq. 4.4. and 4.5a/4.6b
 *
 * Arguments    : const b_captured_var *LXft
 *                const captured_var *Dis
 *                const double iP_data[]
 *                const int iP_size[2]
 *                const double id2_data[]
 *                const int id2_size[2]
 *                const double id1_data[]
 *                const int id1_size[2]
 *                double d
 *                double Ld_data[]
 *                int Ld_size[2]
 * Return Type  : void
 */
void d_L_int_d(const b_captured_var *LXft, const captured_var *Dis,
               const double iP_data[], const int iP_size[2],
               const double id2_data[], const int id2_size[2],
               const double id1_data[], const int id1_size[2], double d,
               double Ld_data[], int Ld_size[2])
{
  double A_data;
  int A_size[2];
  int b_x_size[2];
  int tmp_size[2];
  int x_size[2];
  int i;
  int i1;
  int k;
  int loop_ub;
  boolean_T exitg1;
  boolean_T x_data;
  boolean_T y;
  /*  Obtain the noise level using the tables */
  /*      function Lout = L(id,iP) */
  /*          % id index of the distance */
  /*          % iP index of the Power */
  /*          Lout = table2array(NPDdata_f(iP,4+id));  */
  /*      end */
  x_size[0] = 1;
  x_size[1] = id1_size[1];
  loop_ub = id1_size[1];
  for (i = 0; i < loop_ub; i++) {
    x_data = (id1_data[0] == 0.0);
  }
  y = (id1_size[1] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data) {
        y = false;
        exitg1 = true;
      } else {
        k = 1;
      }
    }
  }
  if (y) {
    double Y_data;
    double tmp_data;
    double x;
    /*  inwards equation 4.5a */
    loop_ub = iP_size[1];
    for (i = 0; i < loop_ub; i++) {
      tmp_data = iP_data[0];
    }
    A_data = log(Dis->contents[1]);
    Y_data = A_data - log(d);
    x = A_data - log(Dis->contents[0]);
    Ld_size[0] = 1;
    Ld_size[1] = iP_size[1];
    loop_ub = iP_size[1];
    if (loop_ub - 1 >= 0) {
      k = 10 * ((int)tmp_data - 1);
      A_data = LXft->contents->data[k + 1];
      Ld_data[0] = A_data + (LXft->contents->data[k] - A_data) / x * Y_data;
    }
  } else {
    if (id1_size[1] == id2_size[1]) {
      x_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        x_data = (id1_data[0] == id2_data[0]);
      }
    } else {
      eq((boolean_T *)&x_data, x_size, id1_data, id1_size, id2_data, id2_size);
    }
    y = (x_size[1] != 0);
    if (y) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size[1] - 1)) {
        if (!x_data) {
          y = false;
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
    if (y) {
      double Y_data;
      double b_tmp_data;
      double b_x_data;
      double c_tmp_data;
      double tmp_data;
      double x;
      /*  outwards equation 4.5b -> the formula in the doc. is incorrect */
      /*  Ld = L(id1-1,iP)+
       * (L(id1-1,iP)-L(id1,iP))/(reallog(Dis(id1))-reallog(Dis(id1-1)))*
       * (reallog(d)-reallog(Dis(id1-1))); */
      /*  The use of reallog is to avoid generating imaginary numbers */
      loop_ub = iP_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data = iP_data[0];
      }
      A_size[0] = id1_size[1];
      A_size[1] = iP_size[1];
      loop_ub = iP_size[1];
      for (i = 0; i < loop_ub; i++) {
        k = id1_size[1];
        for (i1 = 0; i1 < k; i1++) {
          A_data =
              LXft->contents
                  ->data[((int)id1_data[0] + 10 * ((int)tmp_data - 1)) - 1];
        }
      }
      loop_ub = iP_size[1];
      for (i = 0; i < loop_ub; i++) {
        k = id1_size[1];
        for (i1 = 0; i1 < k; i1++) {
          b_tmp_data =
              LXft->contents
                  ->data[((int)(id1_data[0] - 1.0) + 10 * ((int)tmp_data - 1)) -
                         1];
        }
      }
      tmp_size[0] = 1;
      tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        c_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        c_tmp_data = log(c_tmp_data);
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)(id1_data[0] - 1.0) - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      x = log(d);
      loop_ub = id1_size[1] * iP_size[1];
      for (i = 0; i < loop_ub; i++) {
        A_data -= b_tmp_data;
      }
      loop_ub = id1_size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_x_data = c_tmp_data - b_x_data;
      }
      if ((A_size[0] == 0) || (A_size[1] == 0) || (id1_size[1] == 0)) {
        k = A_size[0];
        loop_ub = A_size[0];
        for (i = 0; i < loop_ub; i++) {
          Y_data = 0.0;
        }
      } else {
        k = 1;
        Y_data = A_data / b_x_data;
      }
      if ((k == id1_size[1]) && (iP_size[1] == id1_size[1])) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = x - c_tmp_data;
        }
        Ld_size[0] = k;
        Ld_size[1] = id1_size[1];
        loop_ub = id1_size[1];
        if ((loop_ub - 1 >= 0) && (k - 1 >= 0)) {
          Ld_data[0] =
              LXft->contents
                  ->data[((int)id1_data[0] + 10 * ((int)tmp_data - 1)) - 1] +
              Y_data * b_x_data;
        }
      } else {
        o_binary_expand_op(Ld_data, Ld_size, LXft, id1_data, id1_size,
                           (double *)&tmp_data, &iP_size[1], (double *)&Y_data,
                           &k, x, (double *)&c_tmp_data, tmp_size);
      }
    } else {
      double Y_data;
      double b_tmp_data;
      double b_x_data;
      double c_tmp_data;
      double tmp_data;
      double x;
      loop_ub = iP_size[1];
      for (i = 0; i < loop_ub; i++) {
        tmp_data = iP_data[0];
      }
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_tmp_data = id1_data[0];
      }
      tmp_size[0] = 1;
      tmp_size[1] = id1_size[1];
      loop_ub = id1_size[1];
      for (i = 0; i < loop_ub; i++) {
        c_tmp_data = Dis->contents[(int)id1_data[0] - 1];
      }
      i = id1_size[1];
      for (k = 0; k < i; k++) {
        c_tmp_data = log(c_tmp_data);
      }
      x = log(d);
      b_x_size[0] = 1;
      b_x_size[1] = id2_size[1];
      loop_ub = id2_size[1];
      for (i = 0; i < loop_ub; i++) {
        b_x_data = Dis->contents[(int)id2_data[0] - 1];
      }
      i = id2_size[1];
      for (k = 0; k < i; k++) {
        b_x_data = log(b_x_data);
      }
      if (id1_size[1] == id2_size[1]) {
        A_size[0] = id2_size[1];
        A_size[1] = iP_size[1];
        loop_ub = iP_size[1];
        for (i = 0; i < loop_ub; i++) {
          k = id2_size[1];
          for (i1 = 0; i1 < k; i1++) {
            int A_data_tmp;
            A_data_tmp = 10 * ((int)tmp_data - 1);
            A_data = LXft->contents->data[((int)id2_data[0] + A_data_tmp) - 1] -
                     LXft->contents->data[((int)b_tmp_data + A_data_tmp) - 1];
          }
        }
      } else {
        q_binary_expand_op((double *)&A_data, A_size, LXft, id2_data, id2_size,
                           (double *)&tmp_data, &iP_size[1],
                           (double *)&b_tmp_data, &id1_size[1]);
      }
      if (id2_size[1] == id1_size[1]) {
        loop_ub = id2_size[1] - 1;
        for (i = 0; i <= loop_ub; i++) {
          b_x_data -= c_tmp_data;
        }
      } else {
        b_minus((double *)&b_x_data, b_x_size, (double *)&c_tmp_data, tmp_size);
      }
      if ((A_size[0] == 0) || (A_size[1] == 0) || (b_x_size[1] == 0)) {
        k = A_size[0];
        loop_ub = A_size[0];
        for (i = 0; i < loop_ub; i++) {
          Y_data = 0.0;
        }
      } else {
        k = 1;
        Y_data = A_data / b_x_data;
      }
      if ((id1_size[1] == k) && (iP_size[1] == id1_size[1])) {
        loop_ub = id1_size[1];
        for (i = 0; i < loop_ub; i++) {
          b_x_data = x - c_tmp_data;
        }
        Ld_size[0] = k;
        Ld_size[1] = id1_size[1];
        loop_ub = id1_size[1];
        if ((loop_ub - 1 >= 0) && (k - 1 >= 0)) {
          Ld_data[0] =
              LXft->contents
                  ->data[((int)b_tmp_data + 10 * ((int)tmp_data - 1)) - 1] +
              Y_data * b_x_data;
        }
      } else {
        p_binary_expand_op(Ld_data, Ld_size, LXft, (double *)&b_tmp_data,
                           &id1_size[1], (double *)&tmp_data, &iP_size[1],
                           (double *)&Y_data, &k, x, (double *)&c_tmp_data,
                           tmp_size);
      }
    }
  }
}

/*
 * Arguments    : boolean_T in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 *                const double in3_data[]
 *                const int in3_size[2]
 * Return Type  : void
 */
void eq(boolean_T in1_data[], int in1_size[2], const double in2_data[],
        const int in2_size[2], const double in3_data[], const int in3_size[2])
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
    in1_data[0] = (in2_data[0] == in3_data[0]);
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 * Return Type  : void
 */
void minus(double in1_data[], int in1_size[2], const double in2_data[],
           const int in2_size[2])
{
  double b_in1_data;
  int i;
  int i1;
  int in1_size_idx_0;
  int in1_size_idx_1;
  int loop_ub;
  if (in2_size[0] == 1) {
    in1_size_idx_0 = in1_size[0];
  } else {
    in1_size_idx_0 = in2_size[0];
  }
  in1_size_idx_1 = in1_size[1];
  loop_ub = in1_size[1];
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    i1 = in2_size[0];
    if (i1 == 1) {
      b_loop_ub = in1_size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1_data = in1_data[0] - in2_data[0];
    }
  }
  in1_size[0] = in1_size_idx_0;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    for (i = 0; i < in1_size_idx_0; i++) {
      in1_data[0] = b_in1_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const double in2_data[]
 *                const int in2_size[2]
 *                const double in3_data[]
 *                const int *in3_size
 *                double in4
 *                const double in5_data[]
 *                const int in5_size[2]
 * Return Type  : void
 */
void r_binary_expand_op(double in1_data[], int in1_size[2],
                        const double in2_data[], const int in2_size[2],
                        const double in3_data[], const int *in3_size,
                        double in4, const double in5_data[],
                        const int in5_size[2])
{
  double in4_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int in2_size_idx_1;
  int in4_size_idx_1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in4_size_idx_1 = in5_size[1];
  loop_ub = in5_size[1];
  for (i = 0; i < loop_ub; i++) {
    in4_data = in4 - in5_data[0];
  }
  in1_size[0] = *in3_size;
  in1_size[1] = in4_size_idx_1;
  for (i = 0; i < in4_size_idx_1; i++) {
    for (i1 = 0; i1 < *in3_size; i1++) {
      in1_data[0] = in3_data[0] * in4_data;
    }
  }
  if (in1_size[0] == 1) {
    in4_size_idx_1 = in2_size[0];
  } else {
    in4_size_idx_1 = in1_size[0];
  }
  if (in1_size[1] == 1) {
    in2_size_idx_1 = in2_size[1];
  } else {
    in2_size_idx_1 = in1_size[1];
  }
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in1_size[1] == 1) {
    loop_ub = in2_size[1];
  } else {
    loop_ub = in1_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    i1 = in1_size[0];
    if (i1 == 1) {
      b_loop_ub = in2_size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in4_data =
          in2_data[in2_size[0] * aux_0_1] + in1_data[in1_size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = in4_size_idx_1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    for (i = 0; i < in4_size_idx_1; i++) {
      in1_data[0] = in4_data;
    }
  }
}

/*
 * Arguments    : double in1_data[]
 *                int in1_size[2]
 *                const emxArray_real_T *in2
 *                const double in3_data[]
 *                const int in3_size[2]
 *                const double in4_data[]
 *                const int in4_size[2]
 * Return Type  : void
 */
void s_binary_expand_op(double in1_data[], int in1_size[2],
                        const emxArray_real_T *in2, const double in3_data[],
                        const int in3_size[2], const double in4_data[],
                        const int in4_size[2])
{
  const double *in2_data;
  int i;
  int loop_ub;
  in2_data = in2->data;
  in1_size[0] = 1;
  if (in4_size[1] == 1) {
    in1_size[1] = in3_size[1];
    loop_ub = in3_size[1];
  } else {
    in1_size[1] = in4_size[1];
    loop_ub = in4_size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[0] = in2_data[(int)in3_data[0] - 1] - in4_data[0];
  }
}

/*
 * File trailer for ANCM_GetLPdSt.c
 *
 * [EOF]
 */
