//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NDVI64to505.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 30-Sep-2020 18:34:27
//

// Include Files
#include "NDVI64to505.h"
#include "NDVI64to505_data.h"
#include "NDVI64to505_initialize.h"
#include "fillmissing.h"
#include "interp1.h"
#include "islocalmax.h"
#include "islocalmin.h"
#include "phen_6method.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions

//
// MOD09DEVI=BlockDEVI(:,s); plot(BlockDEVI(:,s));  plot(MOD09DEVI)
//  MOD09DEVI(MOD09DEVI>1)=1;
//  MOD09DEVI(MOD09DEVI<0)=0;
// Arguments    : const double MOD09DEVI[64]
//                double EXT09Data[545]
//                double EXT09DMSK2[545]
//                double *LocMaxima
// Return Type  : void
//
void NDVI64to505(const double MOD09DEVI[64], double EXT09Data[545], double
                 EXT09DMSK2[545], double *LocMaxima)
{
  int idx;
  double dv[495];
  double b_MOD09DEVI[495];
  static const double varargin_1[64] = { -64.0, -56.0, -48.0, -40.0, -32.0,
    -24.0, -16.0, -8.0, 0.0, 4.0, 12.0, 20.0, 28.0, 36.0, 44.0, 52.0, 60.0, 68.0,
    76.0, 84.0, 92.0, 100.0, 108.0, 116.0, 124.0, 132.0, 140.0, 148.0, 156.0,
    164.0, 172.0, 180.0, 188.0, 196.0, 204.0, 212.0, 220.0, 228.0, 236.0, 244.0,
    252.0, 260.0, 268.0, 276.0, 284.0, 292.0, 300.0, 308.0, 316.0, 324.0, 332.0,
    340.0, 348.0, 356.0, 364.0, 366.0, 374.0, 382.0, 390.0, 398.0, 406.0, 414.0,
    422.0, 430.0 };

  double d;
  double xtmp;
  boolean_T MaxLoctn[545];
  boolean_T MinLoctn[545];
  boolean_T ex;
  int k;
  boolean_T exitg1;
  double b_ex;
  int LocMinima;
  short ii_data[545];
  short tmp_data[545];
  double b_EXT09Data[545];
  if (!isInitialized_NDVI64to505) {
    NDVI64to505_initialize();
  }

  //  fusion_EVI=(fusion_EVI/10000)'; MOD09DEVI=fusion_EVI;
  //  MOD09DEVI=MOD09DEVI(:,4);
  //  46 to 365
  // MOD09DEVI = interp1(1:8:505,MOD09DEVI,1:505,'linear','extrap');
  //  plot(medfilt1(MOD09DEVI,10))
  //  plot(smooth(MOD09DEVI,20))
  //  plot(sgolayfilt(MOD09DEVI,3,19));
  for (idx = 0; idx < 495; idx++) {
    b_MOD09DEVI[idx] = 0.0;
    dv[idx] = static_cast<double>(idx) + -64.0;
  }

  interp1Linear(MOD09DEVI, dv, b_MOD09DEVI, varargin_1);

  //  MOD09DEVI=sgolayfilt(MOD09DEVI,3,19);
  for (idx = 0; idx < 495; idx++) {
    d = b_MOD09DEVI[idx];
    if (b_MOD09DEVI[idx] > 1.0) {
      d = 1.0;
      b_MOD09DEVI[idx] = 1.0;
    }

    if (d < 0.0) {
      d = 0.0;
      b_MOD09DEVI[idx] = 0.0;
    }

    EXT09Data[idx] = d;
  }

  for (idx = 0; idx < 50; idx++) {
    EXT09Data[idx + 495] = rtNaN;
  }

  //  flip up-down
  for (idx = 0; idx < 272; idx++) {
    xtmp = EXT09Data[idx];
    EXT09Data[idx] = EXT09Data[544 - idx];
    EXT09Data[544 - idx] = xtmp;
  }

  //  plot(MOD09DEVI)
  //  detecting local maxima
  islocalmax(EXT09Data, MaxLoctn);

  //  3
  islocalmin(EXT09Data, MinLoctn);

  //  3
  //  index=find(MaxLoctn==1)
  ex = rtIsNaN(EXT09Data[0]);
  if (!ex) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 545)) {
      if (!rtIsNaN(EXT09Data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    b_ex = EXT09Data[0];
  } else {
    b_ex = EXT09Data[idx - 1];
    idx++;
    for (k = idx; k < 546; k++) {
      d = EXT09Data[k - 1];
      if (b_ex < d) {
        b_ex = d;
      }
    }
  }

  // max(MOD09DEVI,[],1)
  if (!ex) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 545)) {
      if (!rtIsNaN(EXT09Data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    xtmp = EXT09Data[0];
  } else {
    xtmp = EXT09Data[idx - 1];
    idx++;
    for (k = idx; k < 546; k++) {
      d = EXT09Data[k - 1];
      if (xtmp > d) {
        xtmp = d;
      }
    }
  }

  //  local maximum EVI must be greater than 0.7 annual maximum EVI
  k = 0;
  LocMinima = 0;
  for (idx = 0; idx < 545; idx++) {
    ex = (EXT09Data[idx] < 0.7 * b_ex);
    if (ex) {
      k++;
      ii_data[LocMinima] = static_cast<short>(idx + 1);
      LocMinima++;
    }
  }

  for (idx = 0; idx < k; idx++) {
    MaxLoctn[ii_data[idx] - 1] = false;
  }

  //  local maximum EVI must be after 70 points
  std::memset(&MaxLoctn[429], 0, 116U * sizeof(boolean_T));
  std::memset(&MaxLoctn[0], 0, 110U * sizeof(boolean_T));

  //  local change range must be greater than 0.35 annual change range
  k = 0;
  LocMinima = 0;
  for (idx = 0; idx < 545; idx++) {
    ex = (EXT09Data[idx] - xtmp < 0.35 * (b_ex - xtmp));
    if (ex) {
      k++;
      tmp_data[LocMinima] = static_cast<short>(idx + 1);
      LocMinima++;
    }
  }

  for (idx = 0; idx < k; idx++) {
    MaxLoctn[tmp_data[idx] - 1] = false;
  }

  //  pad values for extended observations
  //  EXT09Time = repmat((-PadStep+1:365+PadStep)',1,size(MOD09DEVI,2));
  //  EXT09DEVI = [nan(PadStep,1);MOD09DEVI]; % plot(EXT09DEVI)
  //  obtain first local maxima
  idx = 0;
  LocMinima = 0;
  exitg1 = false;
  while ((!exitg1) && (LocMinima < 545)) {
    if (MaxLoctn[LocMinima]) {
      idx++;
      ii_data[idx - 1] = static_cast<short>(LocMinima + 1);
      if (idx >= 545) {
        exitg1 = true;
      } else {
        LocMinima++;
      }
    } else {
      LocMinima++;
    }
  }

  if (1 > idx) {
    LocMinima = 0;
  } else {
    LocMinima = idx;
  }

  if (LocMinima == 0) {
    *LocMaxima = 0.0;
  } else if (LocMinima == 1) {
    LocMinima = -1;
    ex = MaxLoctn[0];
    for (k = 0; k < 544; k++) {
      if (static_cast<int>(ex) < static_cast<int>(MaxLoctn[k + 1])) {
        ex = true;
        LocMinima = k;
      }
    }

    *LocMaxima = static_cast<double>(LocMinima) + 2.0;
  } else if (LocMinima == 2) {
    *LocMaxima = ii_data[1];
  } else {
    *LocMaxima = ii_data[2];
  }

  for (idx = 0; idx < 545; idx++) {
    if (idx + 1 > static_cast<int>(*LocMaxima)) {
      EXT09Data[idx] = rtNaN;
    }
  }

  //  if (LocMaxima<330)
  //      EXT09DEVI(EXT09Time>(LocMaxima+60))=nan; % plot(EXT09DEVI)
  //  end
  //
  //  if (LocMaxima>330)
  //      EXT09DEVI(EXT09Time>LocMaxima)=nan;
  //  end
  //  EXT09DEVI(EXT09Time>LocMaxima)=nan;
  //  obtain first local minima
  idx = 0;
  LocMinima = 0;
  exitg1 = false;
  while ((!exitg1) && (LocMinima < 545)) {
    if (MinLoctn[LocMinima]) {
      idx++;
      ii_data[idx - 1] = static_cast<short>(LocMinima + 1);
      if (idx >= 545) {
        exitg1 = true;
      } else {
        LocMinima++;
      }
    } else {
      LocMinima++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  if (idx == 0) {
    LocMinima = 0;
  } else {
    LocMinima = ii_data[0];
  }

  if (LocMinima <= 110) {
    for (idx = 0; idx < 545; idx++) {
      if (idx + 1 < LocMinima) {
        EXT09Data[idx] = rtNaN;
      }
    }
  }

  if (LocMinima >= 110) {
    if (!rtIsNaN(EXT09Data[0])) {
      LocMinima = 1;
    } else {
      LocMinima = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 111)) {
        if (!rtIsNaN(EXT09Data[k - 1])) {
          LocMinima = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (LocMinima == 0) {
      LocMinima = 1;
    } else {
      b_ex = EXT09Data[LocMinima - 1];
      idx = LocMinima + 1;
      for (k = idx; k < 111; k++) {
        d = EXT09Data[k - 1];
        if (b_ex > d) {
          b_ex = d;
          LocMinima = k;
        }
      }
    }

    for (idx = 0; idx < 545; idx++) {
      if (idx + 1 < LocMinima) {
        EXT09Data[idx] = rtNaN;
      }
    }
  }

  // plot(EXT09DEVI)
  //  filling values
  //  tic
  std::memcpy(&b_EXT09Data[0], &EXT09Data[0], 545U * sizeof(double));
  fillmissing(b_EXT09Data, EXT09Data);

  //  toc
  //  mask values for extended observations
  //  EXT09DEVI(~EXT09DMSK)=nan;
  //  hold on; plot(EXT09Data)
  for (idx = 0; idx < 545; idx++) {
    EXT09DMSK2[idx] = ((idx + 1 <= static_cast<int>(*LocMaxima)) && (idx + 1 >=
      LocMinima));
  }

  //  plot(EXT09DMSK2)
}

//
// File trailer for NDVI64to505.cpp
//
// [EOF]
//
