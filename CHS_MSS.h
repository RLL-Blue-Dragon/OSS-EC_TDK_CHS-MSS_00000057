// License       : License.txt
// Specifications: Spec-CHS-MSS.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : CHS_MSS.h
// Reason for change: 01.00.00 : 28/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __CHS_MSS_H__
#define __CHS_MSS_H__

#include "user_define.h"

// Components number
#define iCHS_MSS                101U                    // TDK CHS-MSS

// CHS-MSS System Parts definitions
#define iCHS_MSS_xoff           0.0F                    // X offset [V]
#define iCHS_MSS_yoff           0.0F                    // Y offset [%RH]
#define iCHS_MSS_gain           0.01F                   // Gain [V/%RH]
#define iCHS_MSS_max            85.0F                   // Humidity Max [%RH]
#define iCHS_MSS_min            20.0F                   // Humidity Min [%RH]

extern const tbl_adc_t tbl_CHS_MSS;

#endif /*__CHS_MSS_H__*/
