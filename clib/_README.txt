ANCM_LIB  ANCM: Aircraft Noise Countour Modelling Library.
   2022 (c) Universidad Politécnica de Valencia.

   IMPORTANT: This software is not for commercial use and it is provide as it is. The authors and the University disclaim any responsibility for the use of this software.

-----------------------------------------------------------------------------------------------------

  This folder contain the source code and executables for the ANCM_LIB. This library
get the noise level from an observer point given the segment of an airplane. It uses the noise model defined by ANC Doc.29, 4th edition, Vol.2.

  This code was generated from Matlab using its MATLAB TO C tool. The main function os ANCM_GetNoiseSeg in file 'ANCM_GetNoiseSeg.c'. A main function has also been created (main.c) that uses this function and also provides a way to use it from command line or external programs. You can obtain help about the use of the executable by typing in the console:
  ./ANCM_Lib_PLATAFOM -H

  The code generated is standard C and can be compiled with any C compiler. Actually, it has been compiled using gcc in Windows, Mac and Linux:

   WINDOWS: ANCM_Lib_Win64.exe : Compiled with DevC++ (gcc), the project is ANCM_Lib.dev
   MAC-ARM: ANCM_lib_MacARM : Compiled in a terminal using gcc, and make_ANCM_Lib_MacARM
   MAC-Intel: ANCM_lib_MacIntel : Compiled in a terminal using gcc, and make_ANCM_Lib_MacIntel
   LINUX: ANCM_lib_Linux : Compiled in a terminal using gcc, and make_ANCM_Lib_Linux

  You can test the executable with the Test_ANCM_LIB_XXXX scripts. 
  The library requires a directory with the NPD file data of the plane in csv format. These files can be downloaded from https://www.aircraftnoisemodel.org/



  
 
