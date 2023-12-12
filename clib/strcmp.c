/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: strcmp.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "strcmp.h"
#include "ANCM_GetNoiseSeg_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const char a[3]
 * Return Type  : boolean_T
 */
boolean_T b_strcmp(const char a[3])
{
  static const char b[3] = {'L', 'A', 'm'};
  int ret;
  ret = memcmp(&a[0], &b[0], 3);
  return ret == 0;
}

/*
 * Arguments    : const char a[3]
 *                const char b[3]
 * Return Type  : boolean_T
 */
boolean_T c_strcmp(const char a[3], const char b[3])
{
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  kstr = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (kstr < 3) {
      if (cv[(unsigned char)a[kstr] & 127] !=
          cv[(unsigned char)b[kstr] & 127]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return b_bool;
}

/*
 * File trailer for strcmp.c
 *
 * [EOF]
 */
