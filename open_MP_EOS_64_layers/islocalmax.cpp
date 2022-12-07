//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: islocalmax.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:34:27
//

// Include Files
#include "islocalmax.h"
#include "NDVI64to505.h"
#include "isLocalExtrema.h"
#include "phen_6method.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions

//
// Arguments    : const double A[494]
//                boolean_T tf[494]
// Return Type  : void
//
void b_islocalmax(const double A[494], boolean_T tf[494])
{
  int i;
  boolean_T y;
  boolean_T isnanA[494];
  int k;
  boolean_T exitg1;
  double b_A[494];
  double varargout_2[494];
  int A_size[1];
  boolean_T tmp_data[494];
  int tmp_size[1];
  int b_tmp_size[1];
  short b_tmp_data[494];
  short c_tmp_data[494];
  for (i = 0; i < 494; i++) {
    isnanA[i] = rtIsNaN(A[i]);
  }

  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 494)) {
    if (isnanA[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!y) {
    int trueCount;
    trueCount = 0;
    k = 0;
    for (i = 0; i < 494; i++) {
      tf[i] = false;
      y = !isnanA[i];
      isnanA[i] = y;
      if (y) {
        trueCount++;
        b_tmp_data[k] = static_cast<short>(i + 1);
        k++;
      }
    }

    A_size[0] = trueCount;
    for (i = 0; i < trueCount; i++) {
      varargout_2[i] = A[b_tmp_data[i] - 1];
    }

    c_doLocalMaxSearch(varargout_2, A_size, tmp_data, tmp_size, b_A, b_tmp_size);
    k = 0;
    for (i = 0; i < 494; i++) {
      if (isnanA[i]) {
        c_tmp_data[k] = static_cast<short>(i + 1);
        k++;
      }
    }

    k = tmp_size[0];
    for (i = 0; i < k; i++) {
      tf[c_tmp_data[i] - 1] = tmp_data[i];
    }
  } else {
    std::memcpy(&b_A[0], &A[0], 494U * sizeof(double));
    d_doLocalMaxSearch(b_A, tf, varargout_2);
  }
}

//
// Arguments    : const double A[493]
//                boolean_T tf[493]
// Return Type  : void
//
void c_islocalmax(const double A[493], boolean_T tf[493])
{
  int i;
  boolean_T y;
  boolean_T isnanA[493];
  int k;
  boolean_T exitg1;
  double b_A[493];
  double varargout_2[493];
  int A_size[1];
  short tmp_data[493];
  double A_data[494];
  boolean_T b_tmp_data[494];
  int tmp_size[1];
  double c_tmp_data[494];
  int b_tmp_size[1];
  short d_tmp_data[493];
  for (i = 0; i < 493; i++) {
    isnanA[i] = rtIsNaN(A[i]);
  }

  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 493)) {
    if (isnanA[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!y) {
    int trueCount;
    trueCount = 0;
    k = 0;
    for (i = 0; i < 493; i++) {
      tf[i] = false;
      y = !isnanA[i];
      isnanA[i] = y;
      if (y) {
        trueCount++;
        tmp_data[k] = static_cast<short>(i + 1);
        k++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      varargout_2[i] = A[tmp_data[i] - 1];
    }

    A_size[0] = trueCount;
    k = trueCount - 1;
    if (0 <= k) {
      std::memcpy(&A_data[0], &varargout_2[0], (k + 1) * sizeof(double));
    }

    c_doLocalMaxSearch(A_data, A_size, b_tmp_data, tmp_size, c_tmp_data,
                       b_tmp_size);
    k = 0;
    for (i = 0; i < 493; i++) {
      if (isnanA[i]) {
        d_tmp_data[k] = static_cast<short>(i + 1);
        k++;
      }
    }

    k = tmp_size[0];
    for (i = 0; i < k; i++) {
      tf[d_tmp_data[i] - 1] = b_tmp_data[i];
    }
  } else {
    std::memcpy(&b_A[0], &A[0], 493U * sizeof(double));
    e_doLocalMaxSearch(b_A, tf, varargout_2);
  }
}

//
// Arguments    : const double A[492]
//                boolean_T tf[492]
// Return Type  : void
//
void d_islocalmax(const double A[492], boolean_T tf[492])
{
  int i;
  boolean_T y;
  boolean_T isnanA[492];
  int k;
  boolean_T exitg1;
  double b_A[492];
  double varargout_2[492];
  int A_size[1];
  short tmp_data[492];
  double A_data[494];
  boolean_T b_tmp_data[494];
  int tmp_size[1];
  double c_tmp_data[494];
  int b_tmp_size[1];
  short d_tmp_data[492];
  for (i = 0; i < 492; i++) {
    isnanA[i] = rtIsNaN(A[i]);
  }

  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 492)) {
    if (isnanA[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!y) {
    int trueCount;
    trueCount = 0;
    k = 0;
    for (i = 0; i < 492; i++) {
      tf[i] = false;
      y = !isnanA[i];
      isnanA[i] = y;
      if (y) {
        trueCount++;
        tmp_data[k] = static_cast<short>(i + 1);
        k++;
      }
    }

    for (i = 0; i < trueCount; i++) {
      varargout_2[i] = A[tmp_data[i] - 1];
    }

    A_size[0] = trueCount;
    k = trueCount - 1;
    if (0 <= k) {
      std::memcpy(&A_data[0], &varargout_2[0], (k + 1) * sizeof(double));
    }

    c_doLocalMaxSearch(A_data, A_size, b_tmp_data, tmp_size, c_tmp_data,
                       b_tmp_size);
    k = 0;
    for (i = 0; i < 492; i++) {
      if (isnanA[i]) {
        d_tmp_data[k] = static_cast<short>(i + 1);
        k++;
      }
    }

    k = tmp_size[0];
    for (i = 0; i < k; i++) {
      tf[d_tmp_data[i] - 1] = b_tmp_data[i];
    }
  } else {
    std::memcpy(&b_A[0], &A[0], 492U * sizeof(double));
    f_doLocalMaxSearch(b_A, tf, varargout_2);
  }
}

//
// Arguments    : const double A[365]
//                boolean_T tf[365]
// Return Type  : void
//
void e_islocalmax(const double A[365], boolean_T tf[365])
{
  int i;
  boolean_T y;
  boolean_T isnanA[365];
  boolean_T exitg1;
  double b_A[365];
  double varargout_2[365];
  int A_size[1];
  short tmp_data[365];
  double A_data[494];
  boolean_T b_tmp_data[494];
  int tmp_size[1];
  double c_tmp_data[494];
  int b_tmp_size[1];
  short d_tmp_data[365];
  for (i = 0; i < 365; i++) {
    isnanA[i] = rtIsNaN(A[i]);
  }

  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 365)) {
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
    for (i = 0; i < 365; i++) {
      tf[i] = false;
      y = !isnanA[i];
      isnanA[i] = y;
      if (y) {
        trueCount++;
        tmp_data[partialTrueCount] = static_cast<short>(i + 1);
        partialTrueCount++;
      }
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      varargout_2[partialTrueCount] = A[tmp_data[partialTrueCount] - 1];
    }

    A_size[0] = trueCount;
    i = trueCount - 1;
    if (0 <= i) {
      std::memcpy(&A_data[0], &varargout_2[0], (i + 1) * sizeof(double));
    }

    c_doLocalMaxSearch(A_data, A_size, b_tmp_data, tmp_size, c_tmp_data,
                       b_tmp_size);
    partialTrueCount = 0;
    for (i = 0; i < 365; i++) {
      if (isnanA[i]) {
        d_tmp_data[partialTrueCount] = static_cast<short>(i + 1);
        partialTrueCount++;
      }
    }

    i = tmp_size[0];
    for (partialTrueCount = 0; partialTrueCount < i; partialTrueCount++) {
      tf[d_tmp_data[partialTrueCount] - 1] = b_tmp_data[partialTrueCount];
    }
  } else {
    std::memcpy(&b_A[0], &A[0], 365U * sizeof(double));
    g_doLocalMaxSearch(b_A, tf, varargout_2);
  }
}

//
// Arguments    : const double A[545]
//                boolean_T tf[545]
// Return Type  : void
//
void islocalmax(const double A[545], boolean_T tf[545])
{
  int i;
  boolean_T y;
  boolean_T isnanA[545];
  boolean_T exitg1;
  double b_A[545];
  double varargout_2[545];
  int A_size[1];
  short tmp_data[545];
  boolean_T b_tmp_data[545];
  int tmp_size[1];
  double c_tmp_data[545];
  int b_tmp_size[1];
  short d_tmp_data[545];
  for (i = 0; i < 545; i++) {
    isnanA[i] = rtIsNaN(A[i]);
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
      varargout_2[partialTrueCount] = A[tmp_data[partialTrueCount] - 1];
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      b_A[partialTrueCount] = (static_cast<double>(tmp_data[partialTrueCount]) -
        1.0) + 1.0;
    }

    doLocalMaxSearch(varargout_2, A_size, b_A, b_tmp_data, tmp_size, c_tmp_data,
                     b_tmp_size);
    partialTrueCount = 0;
    for (i = 0; i < 545; i++) {
      if (isnanA[i]) {
        d_tmp_data[partialTrueCount] = static_cast<short>(i + 1);
        partialTrueCount++;
      }
    }

    i = tmp_size[0];
    for (partialTrueCount = 0; partialTrueCount < i; partialTrueCount++) {
      tf[d_tmp_data[partialTrueCount] - 1] = b_tmp_data[partialTrueCount];
    }
  } else {
    std::memcpy(&b_A[0], &A[0], 545U * sizeof(double));
    b_doLocalMaxSearch(b_A, tf, varargout_2);
  }
}

//
// File trailer for islocalmax.cpp
//
// [EOF]
//
