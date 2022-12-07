//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:02:37
//
#ifndef NULLASSIGNMENT_H
#define NULLASSIGNMENT_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "NDVI64to505_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void nullAssignment(double x_data[], int x_size[2], const boolean_T
  idx_data[], const int idx_size[1]);

#endif

//
// File trailer for nullAssignment.h
//
// [EOF]
//
