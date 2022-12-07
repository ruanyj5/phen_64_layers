//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: phen_6method.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:34:27
//

// Include Files
#include "phen_6method.h"
#include "NDVI64to505.h"
#include "NDVI64to505_data.h"
#include "NDVI64to505_initialize.h"
#include "islocalmax.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <math.h>

// Function Declarations
static double rt_powd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : double EXT09FEVI[545]
//                const double EXT09DMSK2[545]
//                const double ParamFit[4]
//                double *Date1
//                double *Date2
//                double *Date3
//                double *Date4
//                double *Date5
//                double *Date6
// Return Type  : void
//
void phen_6method(double EXT09FEVI[545], const double EXT09DMSK2[545], const
                  double ParamFit[4], double *Date1, double *Date2, double
                  *Date3, double *Date4, double *Date5, double *Date6)
{
  int i;
  short EXT09Time[495];
  int xtmp;
  boolean_T ex;
  int idx;
  int k;
  boolean_T exitg1;
  double work;
  double d;
  double tmp2;
  double b_ex;
  int iindx;
  boolean_T varargin_1[495];
  int iyLead;
  double TMEP_tmp[494];
  boolean_T MethodTmp[494];
  int b_iindx;
  double TMEP[493];
  boolean_T b_MethodTmp[493];
  int c_iindx;
  double y[492];
  boolean_T c_MethodTmp[492];
  double a;
  double b_a;
  double c_a;
  double z[365];
  boolean_T d_MethodTmp[365];
  if (!isInitialized_NDVI64to505) {
    NDVI64to505_initialize();
  }

  for (i = 0; i < 495; i++) {
    EXT09Time[i] = static_cast<short>(i - 64);
  }

  for (i = 0; i < 247; i++) {
    xtmp = EXT09Time[i];
    EXT09Time[i] = EXT09Time[494 - i];
    EXT09Time[494 - i] = static_cast<short>(xtmp);
  }

  for (i = 0; i < 545; i++) {
    if (!(EXT09DMSK2[i] != 0.0)) {
      EXT09FEVI[i] = rtNaN;
    }
  }

  //  hold on; plot(EXT09FEVI)
  //  plot(MOD09TMEP)
  // MOD09TMEP=MOD09TMEP;
  //  Method 1 : 0.2 amplitude thresholding
  ex = rtIsNaN(EXT09FEVI[50]);
  if (!ex) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 496)) {
      if (!rtIsNaN(EXT09FEVI[k + 49])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    work = EXT09FEVI[50];
  } else {
    work = EXT09FEVI[idx + 49];
    i = idx + 1;
    for (k = i; k < 496; k++) {
      d = EXT09FEVI[k + 49];
      if (work < d) {
        work = d;
      }
    }
  }

  if (!ex) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 496)) {
      if (!rtIsNaN(EXT09FEVI[k + 49])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    tmp2 = EXT09FEVI[50];
  } else {
    tmp2 = EXT09FEVI[idx + 49];
    i = idx + 1;
    for (k = i; k < 496; k++) {
      d = EXT09FEVI[k + 49];
      if (tmp2 > d) {
        tmp2 = d;
      }
    }
  }

  if (!ex) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 496)) {
      if (!rtIsNaN(EXT09FEVI[k + 49])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    b_ex = EXT09FEVI[50];
  } else {
    b_ex = EXT09FEVI[idx + 49];
    i = idx + 1;
    for (k = i; k < 496; k++) {
      d = EXT09FEVI[k + 49];
      if (b_ex > d) {
        b_ex = d;
      }
    }
  }

  d = 0.2 * (work - tmp2) + b_ex;
  for (i = 0; i < 495; i++) {
    varargin_1[i] = (EXT09FEVI[i + 50] > d);
  }

  iindx = -1;
  ex = varargin_1[0];

  //  Method 2 : maximum changing rate
  xtmp = 1;
  iyLead = 0;
  work = EXT09FEVI[50];
  for (k = 0; k < 494; k++) {
    if (static_cast<int>(ex) < static_cast<int>(varargin_1[k + 1])) {
      ex = true;
      iindx = k;
    }

    tmp2 = work;
    work = EXT09FEVI[xtmp + 50];
    TMEP_tmp[iyLead] = work - tmp2;
    xtmp++;
    iyLead++;
  }

  b_islocalmax(TMEP_tmp, MethodTmp);
  b_iindx = -1;
  ex = MethodTmp[0];

  //  Method 3 : maximum second-order derivative
  xtmp = 1;
  iyLead = 0;
  work = TMEP_tmp[0];
  for (k = 0; k < 493; k++) {
    if (static_cast<int>(ex) < static_cast<int>(MethodTmp[k + 1])) {
      ex = true;
      b_iindx = k;
    }

    tmp2 = work;
    work = TMEP_tmp[xtmp];
    TMEP[iyLead] = TMEP_tmp[xtmp] - tmp2;
    xtmp++;
    iyLead++;
  }

  c_islocalmax(TMEP, b_MethodTmp);
  c_iindx = -1;
  ex = b_MethodTmp[0];
  for (k = 0; k < 492; k++) {
    if (static_cast<int>(ex) < static_cast<int>(b_MethodTmp[k + 1])) {
      ex = true;
      c_iindx = k;
    }
  }

  //  Method 4 : maximum relative increases in vegetation index
  for (i = 0; i < 494; i++) {
    TMEP_tmp[i] /= EXT09FEVI[i + 50];
  }

  if (!rtIsNaN(TMEP_tmp[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 495)) {
      if (!rtIsNaN(TMEP_tmp[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    idx = 1;
  } else {
    work = TMEP_tmp[idx - 1];
    i = idx + 1;
    for (k = i; k < 495; k++) {
      d = TMEP_tmp[k - 1];
      if (work < d) {
        work = d;
        idx = k;
      }
    }
  }

  //  Method 5 : maximum third-order derivative plot(MethodTmp)
  xtmp = 1;
  iyLead = 0;
  work = TMEP[0];
  for (i = 0; i < 492; i++) {
    tmp2 = work;
    work = TMEP[xtmp];
    y[iyLead] = TMEP[xtmp] - tmp2;
    xtmp++;
    iyLead++;
  }

  d_islocalmax(y, c_MethodTmp);
  i = -1;
  ex = c_MethodTmp[0];
  for (k = 0; k < 491; k++) {
    if (static_cast<int>(ex) < static_cast<int>(c_MethodTmp[k + 1])) {
      ex = true;
      i = k;
    }
  }

  //  Methcod 6 : maximum changing rate in curvature
  a = ParamFit[2] * ParamFit[3];
  work = ParamFit[1] - ParamFit[0];
  b_a = rt_powd_snf(-ParamFit[3], 3.0) * work;
  c_a = -ParamFit[3] * -ParamFit[3] * (work * work);
  work *= -ParamFit[3];
  for (k = 0; k < 365; k++) {
    double d1;
    double d2;
    d = std::exp(a + -ParamFit[3] * (static_cast<double>(k) + 1.0));
    tmp2 = rt_powd_snf(d + 1.0, 3.0);
    b_ex = rt_powd_snf(d + 1.0, 4.0);
    d1 = work * d;
    d2 = rt_powd_snf(b_ex + d1 * d1, 2.5);
    b_ex += d1 * d1;
    d = b_a * d * (3.0 * d * (1.0 - d) * tmp2 * (2.0 * tmp2 + c_a * d) / d2 - (d
      + 1.0) * (d + 1.0) * ((2.0 * d + 1.0) - 5.0 * (d * d)) / rt_powd_snf(b_ex,
      1.5));
    z[k] = d;
  }

  e_islocalmax(z, d_MethodTmp);
  xtmp = -1;
  ex = d_MethodTmp[0];
  for (k = 0; k < 364; k++) {
    if (static_cast<int>(ex) < static_cast<int>(d_MethodTmp[k + 1])) {
      ex = true;
      xtmp = k;
    }
  }

  //  get DOY
  *Date1 = EXT09Time[iindx + 1];
  *Date2 = EXT09Time[b_iindx + 1];
  *Date3 = EXT09Time[c_iindx + 1];
  *Date4 = EXT09Time[idx - 1];
  *Date5 = EXT09Time[i + 1];
  *Date6 = EXT09Time[xtmp + 1];
}

//
// File trailer for phen_6method.cpp
//
// [EOF]
//
