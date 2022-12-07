//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: islocalmax.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:34:27
//
#ifndef ISLOCALMAX_H
#define ISLOCALMAX_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "NDVI64to505_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void b_islocalmax(const double A[494], boolean_T tf[494]);
extern void c_islocalmax(const double A[493], boolean_T tf[493]);
extern void d_islocalmax(const double A[492], boolean_T tf[492]);
extern void e_islocalmax(const double A[365], boolean_T tf[365]);
extern void islocalmax(const double A[545], boolean_T tf[545]);

#endif

//
// File trailer for islocalmax.h
//
// [EOF]
//
