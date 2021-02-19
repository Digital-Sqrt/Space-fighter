/*******************************************************************************
* File Name: Spi_LED_Chain_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Spi_LED_Chain_PVT.h"

static Spi_LED_Chain_BACKUP_STRUCT Spi_LED_Chain_backup =
{
    Spi_LED_Chain_DISABLED,
    Spi_LED_Chain_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: Spi_LED_Chain_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Spi_LED_Chain_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: Spi_LED_Chain_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Spi_LED_Chain_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: Spi_LED_Chain_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Spi_LED_Chain_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_Sleep(void) 
{
    /* Save components enable state */
    Spi_LED_Chain_backup.enableState = ((uint8) Spi_LED_Chain_IS_ENABLED);

    Spi_LED_Chain_Stop();
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Spi_LED_Chain_backup - used when non-retention registers are restored.
*  Spi_LED_Chain_txBufferWrite - modified every function call - resets to
*  zero.
*  Spi_LED_Chain_txBufferRead - modified every function call - resets to
*  zero.
*  Spi_LED_Chain_rxBufferWrite - modified every function call - resets to
*  zero.
*  Spi_LED_Chain_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_Wakeup(void) 
{
    #if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)
        Spi_LED_Chain_rxBufferFull  = 0u;
        Spi_LED_Chain_rxBufferRead  = 0u;
        Spi_LED_Chain_rxBufferWrite = 0u;
    #endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
        Spi_LED_Chain_txBufferFull  = 0u;
        Spi_LED_Chain_txBufferRead  = 0u;
        Spi_LED_Chain_txBufferWrite = 0u;
    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    Spi_LED_Chain_ClearFIFO();

    /* Restore components block enable state */
    if(0u != Spi_LED_Chain_backup.enableState)
    {
        Spi_LED_Chain_Enable();
    }
}


/* [] END OF FILE */
