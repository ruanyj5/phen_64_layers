//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:34:27
//
#ifndef SORTIDX_H
#define SORTIDX_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "NDVI64to505_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void merge_block(int idx_data[], double x_data[], int offset, int n, int
  preSortLevel, int iwork_data[], double xwork_data[]);
extern void merge_pow2_block(int idx_data[], double x_data[], int offset);

#endif

//
// File trailer for sortIdx.h
//
// [EOF]
//
