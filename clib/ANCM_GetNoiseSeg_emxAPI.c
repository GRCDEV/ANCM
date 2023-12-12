/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ANCM_GetNoiseSeg_emxAPI.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 30-Nov-2022 18:20:48
 */

/* Include Files */
#include "ANCM_GetNoiseSeg_emxAPI.h"
#include "ANCM_GetNoiseSeg_emxutil.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreateND_struct1_T(int numDimensions, const int *size)
{
  emxArray_struct1_T *emx;
  int i;
  int numEl;
  emxInit_struct1_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = (struct1_T *)calloc((unsigned int)numEl, sizeof(struct1_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : struct1_T *data
 *                int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreateWrapperND_struct1_T(struct1_T *data,
                                                 int numDimensions,
                                                 const int *size)
{
  emxArray_struct1_T *emx;
  int i;
  int numEl;
  emxInit_struct1_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : struct1_T *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreateWrapper_struct1_T(struct1_T *data, int rows,
                                               int cols)
{
  emxArray_struct1_T *emx;
  emxInit_struct1_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreate_struct1_T(int rows, int cols)
{
  emxArray_struct1_T *emx;
  int numEl;
  emxInit_struct1_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (struct1_T *)calloc((unsigned int)numEl, sizeof(struct1_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : emxArray_struct1_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_struct1_T(emxArray_struct1_T *emxArray)
{
  emxFree_struct1_T(&emxArray);
}

/*
 * Arguments    : emxArray_struct1_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_struct1_T(emxArray_struct1_T **pEmxArray, int numDimensions)
{
  emxInit_struct1_T(pEmxArray, numDimensions);
}

/*
 * File trailer for ANCM_GetNoiseSeg_emxAPI.c
 *
 * [EOF]
 */
