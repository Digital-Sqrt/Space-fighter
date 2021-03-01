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
#include "project.h"
#include "cytypes.h"
#include "DOT_STAR.h"
#include "SPI.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
      
    Frame_Timer_Init();
    Frame_Timer_Enable();
    
    Spi_LED_Chain_Start();       
    Spi_LED_Chain_EnableTxInt();
    isr_spi_tx_done_Disable();
    Spi_LED_Chain_ClearRxBuffer();
    
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    { /* Place your application code here. */
    }
}

/* [] END OF FILE */
