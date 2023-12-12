# ANCM: Aircraft Noise Contour Modelling Library

This repository contains the Matlab and C library code to get the noise level from an observer point given the segment of an aeroplane. It implements the standard noise model defined by ANC Doc.29, 4th edition, Vol.2.

The Matlab code was developed to evaluate the noise generated in aircraft approach maneuvers and is described in the following paper (section 5):

*"Rafael Casado, Aurelio Bermúdez, Enrique Hernández-Orallo, Pablo Boronat, Miguel Pérez-Francisco, Carlos T.Calafate "Pollution and noise reduction through missed approach maneuvers based on aircraft reinjection" Elsevier Transportation Research Part D: Transport and Environment, Volume 114, January 2023, 103574 doi.org/10.1016/j.trd.2022.103574 (Open access)"*

The noise model is based on the flight paths adopted by the aircraft that approaches to, or departs from, the target runway, and it is described as a set of segments. Thus, based on these segments, the ECAC Doc. 29 model provides a noise calculation method for a single event (that is, the noise generated in a segment) considering an observer point at a given distance d. Thus, the Matlab Aircraft Noise Contour Modeling (ANCM) library follows the methodology and equations described in Chapter 4 of ECAC.CEAC. These MATLAB functions have been tested and validated with the ??Reference Cases and Verification Framework?? of the ECAC Doc. 29.

The ECAC Doc. 29 methodology to obtain a single event noise level is based on using the Aircraft Noise and Performance (ANP) database (Eurocontrol, 2022). This database is the primary source of aircraft noise for specific aircraft types, variants, and flight configurations (approach or departure). 

This repository contains two versions of the library:

## MATLAB

The code is in the 'Matlab' folder. It contains all the functions that implement the noise model (files starting with ANCM_) and some test programs. The NPD_Data contains some flight path data and aircraft models. 

The main function of our library is ANCM_GetLpath. This function has as inputs the desired type of metric (SEL or Lmax), the FlightPath data structure, the observer?s location, the aircraft?s NPD-data, and some additional information about the aircraft and atmospheric conditions (see the help of the function). The function returns a vector with the noise level of all the segments of the flight path. 
The "Test_SimpleTestFlight.m" file contains a simple code to test this function.

Another example program is "Test_NoiseMap.m", which generates a noise map using the ANCM_GelLpath. 

## C Lib

The code and executables are in the 'clib' folder. This code was generated from Matlab using its MATLAB TO C tool. The main function is ANCM_GetNoiseSeg in file 'ANCM_GetNoiseSeg.c'. A main function has also been created (main.c) that uses this function and also provides a way to use it from the command line or external programs. You can obtain help about the use of the executable by typing in the console:
  ./ANCM_Lib_PLATFORM -H

  The code generated is standard C and can be compiled with any C compiler. Actually, it has been compiled using gcc in Windows, Mac and Linux:

 - WINDOWS: ANCM_Lib_Win64.exe : Compiled with DevC++ (gcc). The project is ANCM_Lib.dev
 - MAC-ARM: ANCM_lib_MacARM : Compiled in a terminal using gcc, with make_ANCM_Lib_MacARM
 - MAC-Intel: ANCM_lib_MacIntel : Compiled in a terminal using gcc, with make_ANCM_Lib_MacIntel
 - LINUX: ANCM_lib_Linux : Compiled in a terminal using gcc, and make_ANCM_Lib_Linux


  You can test the executable with the Test_ANCM_LIB_XXXX scripts. 
  The library requires a directory with the NPD file data of the plane in csv format. These files can be downloaded from https://www.aircraftnoisemodel.org/


## Copyright and disclaimer

Developed by GRC, Grupo de Redes de Computadores, Universitat Politecnica de Valencia, 2022

ANCM: Aircraft Noise Contour Modelling Library.
   2022 (c) Universidad Politécnica de Valencia.

IMPORTANT: This software is not for commercial use, and it is provided as it is. The authors and the University disclaim any responsibility for the use of this software.

-----------------------------------------------------------------------------------------------------

