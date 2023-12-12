/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ifWhileCond.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "ifWhileCond.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const boolean_T x_data[]
 *                const int x_size[2]
 * Return Type  : boolean_T
 */
boolean_T ifWhileCond(const boolean_T x_data[], const int x_size[2])
{
  boolean_T y;
  y = (x_size[1] != 0);
  if (y) {
    int k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data[0]) {
        y = false;
        exitg1 = true;
      } else {
        k = 1;
      }
    }
  }
  return y;
}

/*
 * File trailer for ifWhileCond.c
 *
 * [EOF]
 */
