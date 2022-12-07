//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: islocalmin.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:02:37
//

// Include Files
#include "islocalmin.h"
#include "NDVI64to505.h"
#include "isLocalExtrema.h"
#include "phen_6method.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const double A[545]
//                boolean_T tf[545]
// Return Type  : void
//
void islocalmin(const double A[545], boolean_T tf[545])
{
  int i;
  boolean_T y;
  double b_A[545];
  boolean_T isnanA[545];
  boolean_T exitg1;
  double varargout_2[545];
  int A_size[1];
  double A_data[545];
  short tmp_data[545];
  boolean_T b_tmp_data[545];
  int tmp_size[1];
  int b_tmp_size[1];
  short c_tmp_data[545];
  for (i = 0; i < 545; i++) {
    b_A[i] = -A[i];
    isnanA[i] = rtIsNaN(-A[i]);
  }

  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 545)) {
    if (isnanA[i]) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (!y) {
    int trueCount;
    int partialTrueCount;
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 545; i++) {
      tf[i] = false;
      y = !isnanA[i];
      isnanA[i] = y;
      if (y) {
        trueCount++;
        tmp_data[partialTrueCount] = static_cast<short>(i + 1);
        partialTrueCount++;
      }
    }

    A_size[0] = trueCount;
    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      A_data[partialTrueCount] = b_A[tmp_data[partialTrueCount] - 1];
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      varargout_2[partialTrueCount] = (static_cast<double>
        (tmp_data[partialTrueCount]) - 1.0) + 1.0;
    }

    doLocalMaxSearch(A_data, A_size, varargout_2, b_tmp_data, tmp_size, b_A,
                     b_tmp_size);
    partialTrueCount = 0;
    for (i = 0; i < 545; i++) {
      if (isnanA[i]) {
        c_tmp_data[partialTrueCount] = static_cast<short>(i + 1);
        partialTrueCount++;
      }
    }

    i = tmp_size[0];
    for (partialTrueCount = 0; partialTrueCount < i; partialTrueCount++) {
      tf[c_tmp_data[partialTrueCount] - 1] = b_tmp_data[partialTrueCount];
    }
  } else {
    b_doLocalMaxSearch(b_A, tf, varargout_2);
  }
}

//
// File trailer for islocalmin.cpp
//
// [EOF]
//
