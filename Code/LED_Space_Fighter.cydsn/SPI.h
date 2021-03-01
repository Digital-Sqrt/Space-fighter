/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "cytypes.h"
#include "DOT_STAR.h"  

/* [] END OF FILE */
#ifndef SPI_H
    #define SPI_H

    extern void SpiLightLeds(void); 
    extern void SpiLockNextFrameBuffer(void);
    extern void SpiHalt(void);
    extern void SpiSetNextFrame(struct LedChain *MyLedChain);
    extern void SpiSendNextByte(void);
    extern void SpiStopSendingBytes(void);
    
#endif    