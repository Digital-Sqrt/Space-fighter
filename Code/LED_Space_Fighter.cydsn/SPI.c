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
#include "SPI.h"
#include "DOT_STAR.h"   
#include "Spi_LED_Chain.h"
#include <stdbool.h>
#include <isr_spi_tx_done.h>
#include <isr_frame.h>

struct DisplayBuffer Display;
volatile bool TxDone = false;

extern void SpiLightLeds(void){
    TxDone = false;
    isr_spi_tx_done_Enable();
    SpiSendNextByte();
};

extern void SpiSendNextByte(void){
    Spi_LED_Chain_WriteTxData(*(Display.Buffer + Display.Index));
    
    Display.Index++;
    if (Display.Index >= Display.Count){
      SpiStopSendingBytes();  
    }
};

extern void SpiSetNextFrame(struct LedChain *MyLedChain){
    Display.Buffer = (uint8_t*)MyLedChain->DotStar;
    Display.Count = MyLedChain->Count * (uint8_t)sizeof(struct OneLed );
    Display.Index = 0; 
};
                       
extern void SpiStopSendingBytes(void){
    isr_spi_tx_done_Disable();
    Display.Index = 0;
    TxDone = true;
};

extern bool IsTxDone(void){
    return TxDone;
};


/* [] END OF FILE */

