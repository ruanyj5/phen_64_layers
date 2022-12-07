//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NDVI64to505_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:34:27
//

// Include Files
#include "NDVI64to505_initialize.h"
#include "NDVI64to505.h"
#include "NDVI64to505_data.h"
#include "phen_6method.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void NDVI64to505_initialize()
{
  rt_InitInfAndNaN();
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_NDVI64to505 = true;
}

//
// File trailer for NDVI64to505_initialize.cpp
//
// [EOF]
//
