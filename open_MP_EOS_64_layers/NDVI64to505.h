//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NDVI64to505.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:34:27
//
#ifndef NDVI64TO505_H
#define NDVI64TO505_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "NDVI64to505_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void NDVI64to505(const double MOD09DEVI[64], double EXT09Data[545],
  double EXT09DMSK2[545], double *LocMaxima);

#endif

//
// File trailer for NDVI64to505.h
//
// [EOF]
//
