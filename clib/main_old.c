/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 23-Nov-2022 13:03:16
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "ANCM_GetNoiseSeg.h"
#include "ANCM_GetNoiseSeg_emxAPI.h"
#include "ANCM_GetNoiseSeg_terminate.h"
#include "ANCM_GetNoiseSeg_types.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stdio.h>

/* Function Declarations */
static void argInit_1x3_char_T(char result[3]);

static void argInit_1x3_real_T(double result[3]);

static void argInit_1x5_char_T(char result[5]);

static void argInit_1xd5_char_T(char result_data[], int result_size[2]);

static emxArray_struct1_T *argInit_Unboundedx1_struct1_T(void);

static boolean_T argInit_boolean_T(void);

static char argInit_char_T(void);

static double argInit_real_T(void);

static b_rtString argInit_rtString(void);

static void argInit_struct0_T(struct0_T *result);

static void argInit_struct1_T(struct1_T *result);

static struct2_T argInit_struct2_T(void);

static struct3_T argInit_struct3_T(void);

static rtString b_argInit_rtString(void);

/* Function Definitions */
/*
 * Arguments    : char result[3]
 * Return Type  : void
 */
static void argInit_1x3_char_T(char result[3])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 3; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_1x3_real_T(double result[3])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 3; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : char result[5]
 * Return Type  : void
 */
static void argInit_1x5_char_T(char result[5])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_1xd5_char_T(char result_data[], int result_size[2])
{
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result_size[0] = 1;
  result_size[1] = 2;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_struct1_T *
 */
static emxArray_struct1_T *argInit_Unboundedx1_struct1_T(void)
{
  emxArray_struct1_T *result;
  struct1_T *result_data;
  const int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_struct1_T(1, &i);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    argInit_struct1_T(&result_data[idx0]);
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : boolean_T
 */
static boolean_T argInit_boolean_T(void)
{
  return false;
}

/*
 * Arguments    : void
 * Return Type  : char
 */
static char argInit_char_T(void)
{
  return '?';
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : b_rtString
 */
static b_rtString argInit_rtString(void)
{
  b_rtString result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1xd5_char_T(result.Value.data, result.Value.size);
  return result;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x3_real_T(result->S1);
  result_tmp = argInit_real_T();
  result->epsilon = result_tmp;
  result->P = result_tmp;
  result->Vseg = result_tmp;
  result->isRolling = result_tmp;
  result->S2[0] = result->S1[0];
  result->S2[1] = result->S1[1];
  result->S2[2] = result->S1[2];
}

/*
 * Arguments    : struct1_T *result
 * Return Type  : void
 */
static void argInit_struct1_T(struct1_T *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result->L_200ft = result_tmp;
  result->L_400ft = result_tmp;
  result->L_630ft = result_tmp;
  result->L_1000ft = result_tmp;
  result->L_2000ft = result_tmp;
  result->L_4000ft = result_tmp;
  result->L_6300ft = result_tmp;
  result->L_10000ft = result_tmp;
  result->L_16000ft = result_tmp;
  result->L_25000ft = result_tmp;
  result->NoiseMetric = argInit_rtString();
  result->OpMode = b_argInit_rtString();
  result->PowerSetting = result_tmp;
}

/*
 * Arguments    : void
 * Return Type  : struct2_T
 */
static struct2_T argInit_struct2_T(void)
{
  struct2_T result;
  boolean_T result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_boolean_T();
  result.TurboFan = result_tmp;
  result.WingMounted = result_tmp;
  return result;
}

/*
 * Arguments    : void
 * Return Type  : struct3_T
 */
static struct3_T argInit_struct3_T(void)
{
  struct3_T result;
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result.T = result_tmp;
  result.p = result_tmp;
  return result;
}

/*
 * Arguments    : void
 * Return Type  : rtString
 */
static rtString b_argInit_rtString(void)
{
  rtString result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result.Value = argInit_char_T();
  return result;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_ANCM_GetNoiseSeg();
  /* Terminate the application.
You do not need to do this more than one time. */
  ANCM_GetNoiseSeg_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_ANCM_GetNoiseSeg(void)
{
    emxArray_struct1_T *NPDdataSt;
    rtString OpMode;
    struct0_T Seg;
    struct2_T Aircraft;
    struct3_T AtmCond;
    creal_T Lseg_data;
    double Ob[3];
    double Vref;
    int Lseg_size[2];
    char NoiseMetric[5];
    char MOS[3];
    
    struct1_T *result_data;
    const int sizeNPD = 6;
    int idx0;
    struct1_T NPD[] ={
        { {{"LAmax", {1,5}}}, {'A'} , 2000, 97.4, 90.1, 85.2, 80.1, 72.1, 63.6, 57.4, 50.4, 42.6, 34.6},
        { {{"LAmax", {1,5}}}, {'A'} , 2500, 97.6, 90.3, 85.4, 80.3, 72.3, 63.8, 57.6, 50.6, 42.8, 34.8},
        { {{"LAmax", {1,5}}}, {'A'} , 7500, 99.9, 92.6, 87.7, 82.6, 74.6, 66.1, 59.9, 52.9, 45.1, 37.1},
        { {{"SEL", {1,3}}}, {'A'} , 2000, 97.4, 90.1, 85.2, 80.1, 72.1, 63.6, 57.4, 50.4, 42.6, 34.6},
        { {{"SEL", {1,3}}}, {'A'} , 2500, 97.6, 90.3, 85.4, 80.3, 72.3, 63.8, 57.6, 50.6, 42.8, 34.8},
        { {{"SEL", {1,3}}}, {'A'} , 7500, 99.9, 92.6, 87.7, 82.6, 74.6, 66.1, 59.9, 52.9, 45.1, 37.1}
    };
    
    /* Seg struct */
    Seg.S1[0] = 3141.5; Seg.S1[1] = 0; Seg.S1[2] = 3.3;
    Seg.S2[0] = 3869.3; Seg.S2[1] = 0; Seg.S2[2] = 3.3;
    Seg.isRolling = 1;
    Seg.epsilon = 0;
    Seg.P = 7500;
    Seg.Vseg = 149.0962;
    
    Ob[0] = 9842.5; Ob[1] = 1640.4; Ob[2] = 0;
    
    /* Initialize function input argument 'NPDdataSt'. */
    NPDdataSt = argInit_Unboundedx1_struct1_T();
    
    /* Set the size of the array. Change this size to the value that the application requires. */
    NPDdataSt = emxCreateND_struct1_T(1, &sizeNPD);
    NPDdataSt->data = NPD;
    
    /* memcpy(NoiseMetric,"LAmax",5); */
    memcpy(NoiseMetric,"SEL  ",5);
    OpMode.Value = 'A';
    memcpy(MOS,"MLM",3);
    Vref = 270.05;
    
    /* Aircraft stuct */
    Aircraft.WingMounted = 0;
    Aircraft.TurboFan = 1;
    
    /* AtmCond struct */
    AtmCond.p = 101.3250;
    AtmCond.T = 15;

    
    /* PRINT ALL PARAMETERS */
    printf("Calling ANCS_GetNoiseSeg....\n");
    printf(" > Segment Data: S1 [%7.2f,%7.2f,%7.2f] -> S2 [%7.2f,%7.2f,%7.2f]\n", Seg.S1[0], Seg.S1[1], Seg.S1[2], Seg.S2[0], Seg.S2[1],  Seg.S2[2]);
    printf("     isRolling %1.0f, epsilon %5.2f, P %7.2f, Vseg %7.2f\n", Seg.isRolling, Seg.epsilon, Seg.P, Seg.Vseg );
    printf(" > Observer: [%7.2f,%7.2f,%7.2f]\n", Ob[0], Ob[1], Ob[2]);
    
    printf("  > NPDdataSt: size %d, allocatedSize %d numDimensions %d\n", *NPDdataSt->size, NPDdataSt->allocatedSize, NPDdataSt->numDimensions);
    
    printf(" > NoiseMetric: %5s\n", NoiseMetric);
    printf(" > OpMode: %c\n", OpMode.Value);
    printf(" > MOS: %3s\n", MOS);
    printf(" > Vref: %7.2f\n", Vref);
    
    printf(" > Aircraft: Wingmounted %d, Turbofan %d\n", Aircraft.WingMounted, Aircraft.TurboFan);
    
    printf(" > AtmCond: p %7.2f, T %4.2f\n", AtmCond.p, AtmCond.T);
    
    ANCM_GetNoiseSeg(&Seg, Ob, NPDdataSt, NoiseMetric, &OpMode, MOS, Vref, &Aircraft,
                   &AtmCond, (creal_T *)&Lseg_data, Lseg_size);

    printf("\nNOISE : %f \n", Lseg_data.re);

}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
