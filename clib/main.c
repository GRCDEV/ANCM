/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 29-Nov-2022 18:22:39
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


char NPDdataFile[1024] = "./NPD_Data/NPD_data_Test_JETF.csv";
// char NPDdataFile[] = "./NPD_Data/NPD_data_A320-232.csv";
struct1_T *pNPD;
struct0_T Seg;
emxArray_struct1_T *NPDdataSt;
struct2_T Aircraft;
struct3_T AtmCond;
double Ob[3];
double Lseg;
char NoiseMetric[3];
char OpMode;
double Vref;
char MOS[3];
unsigned char TRACE = 4;
int sizeNPD ;

/*
struct1_T NPD[] ={
       { "LAm", 'A' , 2000,  97.4, 90.1, 85.2, 80.1, 72.1, 63.6, 57.4, 50.4, 42.6, 34.6},
       { "LAm", 'A' , 2500,  97.6, 90.3, 85.4, 80.3, 72.3, 63.8, 57.6, 50.6, 42.8, 34.8},
       { "LAm", 'A' , 7500,  99.9, 92.6, 87.7, 82.6, 74.6, 66.1, 59.9, 52.9, 45.1, 37.1},
       { "SEL", 'A' , 2000, 101.2, 97.2, 94.3, 91.0, 85.5, 79.5, 75.2, 70.5, 65.4, 60.2},
       { "SEL", 'A' , 2500, 101.4, 97.4, 94.5, 91.2, 85.7, 79.7, 75.4, 70.7, 65.6, 60.4},
       { "SEL", 'A' , 7500, 103.0, 99.0, 96.1, 92.8, 87.3, 81.3, 77.0, 72.3, 67.2, 62.0}
};
*/

// Read NPDData from file
// IMPORTANT: The csv file must use '.' as a decimal separator (not comma)
int read_NPD_Data(const char *file)
{
    struct1_T *pNPD;
    int num_lines;
    int NPDdata_tam;
    char c;
    char *token;

    
    FILE* fp;
    char line[1024];
    int i;
    
    fp = fopen(file, "r");
    if (fp == NULL) {
        return -1;
    }

    /* FIRST: Count the number of lines */
    num_lines = 0;
    while (fgets(line, 1024, fp))
    {
        token = strtok(line, ";");
        if (token != NULL) {
            num_lines = num_lines + 1;
        }
    }
    sizeNPD = num_lines-1; // Dp not counter the header
    
    pNPD = malloc(sizeNPD * sizeof *pNPD);

    fseek(fp, 0, SEEK_SET);

    /* SECOND: Read the fields */
    fgets(line, 1024, fp); // The first line is the header
    i = 0;
    while (fgets(line, 1024, fp))
    {
        token = strtok(line, ";"); // First column is not used
        memcpy(pNPD[i].NoiseMetric, strtok(NULL, ";"), 3);
        token = strtok(NULL, ";");
        pNPD[i].OpMode = token[0];
        pNPD[i].PowerSetting = atof(strtok(NULL, ";"));
        pNPD[i].L_200ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_400ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_630ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_1000ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_2000ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_4000ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_6300ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_10000ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_16000ft = atof(strtok(NULL, ";"));;
        pNPD[i].L_25000ft = atof(strtok(NULL, ";"));;
        i++;
    }
    
    /* THIRD: Create the struct */
    free(NPDdataSt);
    NPDdataSt = emxCreateND_struct1_T(1, &sizeNPD);
    NPDdataSt->data = pNPD;
        
    return sizeNPD;
}


/* These are the default parameters. They can be changed with the command arguments */
void SetDefaultParameters() {

    /* Seg struct */
    Seg.S1[0] = 3141.5; Seg.S1[1] = 0; Seg.S1[2] = 3.3;
    Seg.S2[0] = 3869.3; Seg.S2[1] = 0; Seg.S2[2] = 3.3;
    Seg.isRolling = 1;
    Seg.epsilon = 0;
    Seg.P = 7500;
    Seg.Vseg = 149.0962;
    
    /* Observer */
    Ob[0] = 9842.5; Ob[1] = 1640.4; Ob[2] = 0;
    
    /* Default NPDdata */
    // NPDdataSt = emxCreateND_struct1_T(1, &sizeNPD);
    // NPDdataSt->data = NPD;
    
    memcpy(NoiseMetric,"LAm",3);
    OpMode = 'A';   
    Vref = 270.05;
    
    /* Aircraft stuct */
    Aircraft.WingMounted = 0;
    Aircraft.TurboFan = 1;
    
    /* AtmCond struct */
    AtmCond.p = 101.3250;
    AtmCond.T = 15;
    
}

void displayHelp() {
 
    printf("\nANCM_GetNoiseSeg HELP\n");
    printf("   ANCM: Aircraft Noise Countour Modelling Library.\n");
    printf("   2022 (c) Universidad Politécnica de Valencia.\n");
    printf(" Get the noise level from an observer point given the segment of an airplane.\n");
    printf(" Use the noise model define by ANC Doc.29, 4th edition, Vol.2\n");
    printf(" IMPORTANT: All coordinates are in FEET (ft) and expressed as distance from the \n");
    printf("    coordinates of the airport. \n");
    printf("\n");
    printf("INPUT PARAMETERS\n");
    printf("  -S's1x,s1y,s1z;s2x,s2y,s2,s2z;isRolling;epsilon;P;Vseg' Segment data.\n");
    printf("    s1x,s1y,s1z;s2x,s2y,s2,s2z; Coordinates of the two points of the segment of the route\n");
    printf("    isRolling (1,0): the plane is in takeoff roll or landing roll\n");
    printf("    epsilon: bank angle (in Euler angles: phi - roll)\n");
    printf("    P: Power\n");
    printf("    Vseg: Speed of the segment\n");
    printf("    EXAMPLE -S'1.1,1.2,1.3;2.1,2.2,2.3;1;0;7600;150.1' \n");
    printf("\n");
    printf(" -O'o1x,o1y,o1z' Ob: Observer location\n");
    printf("    o1x,o1y,o1z; Coordinates of the observer\n");
    printf("    EXAMPLE -O'9842.5,1640.4,0' \n");
    printf("\n");
    printf(" -Fpath Path of the NPD file data in csv format. \n");
    printf("    EXAMPLE -F./NPD_Data/NPD_data_Test_JETF.csv \n");
    printf("\n");
    printf(" -Nmetric Noise metric (3 chars). \n");
    printf("    It depends on the plane, but NoiseMetric can be 'EPN', 'LAm', 'PNL' and 'SEL\n");
    printf("    EXAMPLE -NLAm \n");
    printf("\n");
    printf(" -Mmode A char with the mode: 'A' arrival and 'D' departing \n");
    printf("    EXAMPLE -MA \n");
    printf("\n");
    printf(" -Vspeed Reference groundspeed for which NPD data are defined\n");
    printf("    Normally omitted, so it is set to default value (270.05 ft/s)\n");
    printf("    EXAMPLE -V270.05 \n");
    printf("\n");
    printf(" -A'WingMounted,TurboFan' Aircraft: information about the aircraft\n");
    printf("    WingMounted: 1 (TRUE) -> wing-mounted engine; 0 (FALSE) -> fuselage mounted\n");
    printf("    TurboFan: 1 (TRUE): turbo-fan propelled, 0 (FALSE): turbo-prop propelled\n");
    printf("    EXAMPLE -A'0,1' \n");
    printf("\n");
    printf(" -c'p,T' Atmospheric conditions to get the impedance adjustament\n");
    printf("    Normally omitted, so it is set to default value (105.2,16)\n");
    printf("    p: Ambient air pressure at the observer in KPa\n");
    printf("    T: Air temperature at the observer in Celsius\n");
    printf("    EXAMPLE -C'105.2,16'\n");
    printf("\n");
    printf(" -Td Configure the display of trace (An 8 ubits integer)\n");
    printf("    bit 0: Show input parameters and results\n");
    printf("    bit 1: Show all geometric data and correction value\n");
    printf("    bit 2: Show NPDdata\n");
    printf("    EXAMPLE -T7 \n");
    printf("\n");
    exit(-2);
    
}

int read_arguments(int argc, char **argv) {
	int i;
    char *FileName;
    char *token;

    for (i=1; i<argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'S':
                    // All the value 3d coordinates separate by , (in feet)
                    Seg.S1[0] = atof(strtok(&argv[i][2], ","));
                    Seg.S1[1] = atof(strtok(NULL, ","));
                    Seg.S1[2] = atof(strtok(NULL, ";"));
                    Seg.S2[0] = atof(strtok(NULL, ","));
                    Seg.S2[1] = atof(strtok(NULL, ","));
                    Seg.S2[2] = atof(strtok(NULL, ";"));
                    Seg.isRolling = atof(strtok(NULL, ";"));
                    Seg.epsilon = atof(strtok(NULL, ";"));
                    Seg.P = atof(strtok(NULL, ";"));
                    Seg.Vseg = atof(strtok(NULL, ";"));
                    break;
                case 'O':
                    // The 3d coordinates separate by , (in feet)
                    Ob[0] = atof(strtok(&argv[i][2], ","));
                    Ob[1] = atof(strtok(NULL, ","));
                    Ob[2] = atof(strtok(NULL, ","));
                    break;
                case 'N':
                    memcpy(NoiseMetric,&argv[i][2],3);
                    break;
                case 'M':
                    OpMode = argv[i][2];
                    break;
                case 'V':
                    Vref = atoi(&argv[i][2]);
                    break;
                case 'F':
                    strcpy(NPDdataFile,&argv[i][2]);
                    break;
                case 'A':
                    Aircraft.WingMounted = atoi(strtok(&argv[i][2], ","));
                    Aircraft.TurboFan = atoi(strtok(NULL, ","));
                    break;
                case 'C':
                    AtmCond.p = atof(strtok(&argv[i][2], ","));
                    AtmCond.T = atof(strtok(NULL, ","));
                    break;
                case 'T':
                    TRACE = atoi(&argv[i][2]);
                    break;
                case 'H':
                    displayHelp();
                    break;
                default:
                    printf("Error Bad argument %s\n", argv[i]);
                }
        }        
    }
    return 0;

}

    

int main(int argc, char **argv)
{
    SetDefaultParameters();
                        
	if (read_arguments(argc,argv) < 0) {
        exit(-1);
	}

    if (read_NPD_Data(NPDdataFile) < 0) {
        printf("Error opening file %s\n", NPDdataFile);
        exit(-2);
    }

    Lseg = ANCM_GetNoiseSeg(&Seg, Ob, NPDdataSt, NoiseMetric, OpMode, Vref, &Aircraft,
                   &AtmCond, TRACE);

    printf("NOISE : %f \n", Lseg);
     
   	/* Terminate the application. You do not need to do this more than one time. */
  	ANCM_GetNoiseSeg_terminate();
  	return 0;
}



