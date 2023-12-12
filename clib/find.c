/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: find.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "find.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const boolean_T x[10]
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void b_eml_find(const boolean_T x[10], int i_data[], int i_size[2])
{
  int idx;
  int ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  i_size[1] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 10)) {
    if (x[ii]) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }
  if (idx == 0) {
    i_size[0] = 1;
    i_size[1] = 0;
  }
}

/*
 * Arguments    : const emxArray_boolean_T *x
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void eml_find(const emxArray_boolean_T *x, int i_data[], int i_size[2])
{
  int idx;
  int ii;
  int k;
  const boolean_T *x_data;
  boolean_T exitg1;
  x_data = x->data;
  k = (x->size[1] >= 1);
  idx = 0;
  i_size[0] = 1;
  i_size[1] = k;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x->size[1] - 1)) {
    if (x_data[ii]) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }
  if (k == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else {
    i_size[1] = (idx >= 1);
  }
}

/*
 * File trailer for find.c
 *
 * [EOF]
 */
