// License       : License.txt
// Specifications: Spec-CHS-MSS.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : CHS_MSS.cpp
// Reason for change: 01.00.00 : 28/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "CHS_MSS.h"

#if     iCHS_MSS_ma == iSMA                             // Simple moving average filter
static float32 CHS_MSS_sma_buf[iCHS_MSS_SMA_num];
static sma_f32_t CHS_MSS_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iCHS_MSS_SMA_num ,                              // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &CHS_MSS_sma_buf[0]                             // buffer
};

#elif   iCHS_MSS_ma == iEMA                             // Exponential moving average filter
static ema_f32_t CHS_MSS_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iCHS_MSS_EMA_K                                  // Exponential smoothing factor
};

#elif   iCHS_MSS_ma == iWMA                             // Weighted moving average filter
static float32 CHS_MSS_wma_buf[iCHS_MSS_WMA_num];
static wma_f32_t CHS_MSS_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iCHS_MSS_WMA_num ,                              // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iCHS_MSS_WMA_num * (iCHS_MSS_WMA_num + 1)/2 ,   // kn sum
        &CHS_MSS_wma_buf[0]                             // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_CHS_MSS =
{
        iCHS_MSS                ,
        iCHS_MSS_pin            ,
        iCHS_MSS_xoff           ,
        iCHS_MSS_yoff           ,
        iCHS_MSS_gain           ,
        iCHS_MSS_max            ,
        iCHS_MSS_min            ,
        iCHS_MSS_ma             ,
        
#if     iCHS_MSS_ma == iSMA                             // Simple moving average filter
        &CHS_MSS_Phy_SMA        ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iCHS_MSS_ma == iEMA                             // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &CHS_MSS_Phy_EMA        ,
        (wma_f32_t*)iDummy_adr
#elif   iCHS_MSS_ma == iWMA                             // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &CHS_MSS_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
