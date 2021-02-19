/*******************************************************************************
* File Name: Spi_LED_Chain_INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Spi_LED_Chain_PVT.h"
#include "cyapicallbacks.h"

/* User code required at start of ISR */
/* `#START Spi_LED_Chain_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: Spi_LED_Chain_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Spi_LED_Chain_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  Spi_LED_Chain_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  Spi_LED_Chain_txBuffer[Spi_LED_Chain_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(Spi_LED_Chain_TX_ISR)
{
    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef Spi_LED_Chain_TX_ISR_ENTRY_CALLBACK
        Spi_LED_Chain_TX_ISR_EntryCallback();
    #endif /* Spi_LED_Chain_TX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START Spi_LED_Chain_TX_ISR_START` */

    /* `#END` */
    
    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(Spi_LED_Chain_txBufferRead != Spi_LED_Chain_txBufferWrite)
        {
            tmpStatus = Spi_LED_Chain_GET_STATUS_TX(Spi_LED_Chain_swStatusTx);
            Spi_LED_Chain_swStatusTx = tmpStatus;

            if(0u != (Spi_LED_Chain_swStatusTx & Spi_LED_Chain_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == Spi_LED_Chain_txBufferFull)
                {
                   Spi_LED_Chain_txBufferRead++;

                    if(Spi_LED_Chain_txBufferRead >= Spi_LED_Chain_TX_BUFFER_SIZE)
                    {
                        Spi_LED_Chain_txBufferRead = 0u;
                    }
                }
                else
                {
                    Spi_LED_Chain_txBufferFull = 0u;
                }

                /* Put data element into the TX FIFO */
                CY_SET_REG8(Spi_LED_Chain_TXDATA_PTR, 
                                             Spi_LED_Chain_txBuffer[Spi_LED_Chain_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(Spi_LED_Chain_txBufferRead == Spi_LED_Chain_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            Spi_LED_Chain_TX_STATUS_MASK_REG &= ((uint8) ~Spi_LED_Chain_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START Spi_LED_Chain_TX_ISR_END` */

    /* `#END` */
    
    #ifdef Spi_LED_Chain_TX_ISR_EXIT_CALLBACK
        Spi_LED_Chain_TX_ISR_ExitCallback();
    #endif /* Spi_LED_Chain_TX_ISR_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Spi_LED_Chain_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  Spi_LED_Chain_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  Spi_LED_Chain_rxBuffer[Spi_LED_Chain_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(Spi_LED_Chain_RX_ISR)
{
    #if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

    #ifdef Spi_LED_Chain_RX_ISR_ENTRY_CALLBACK
        Spi_LED_Chain_RX_ISR_EntryCallback();
    #endif /* Spi_LED_Chain_RX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START Spi_LED_Chain_RX_ISR_START` */

    /* `#END` */
    
    #if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = Spi_LED_Chain_GET_STATUS_RX(Spi_LED_Chain_swStatusRx);
        Spi_LED_Chain_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (Spi_LED_Chain_swStatusRx & Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG8(Spi_LED_Chain_RXDATA_PTR);

            /* Set next pointer. */
            Spi_LED_Chain_rxBufferWrite++;
            if(Spi_LED_Chain_rxBufferWrite >= Spi_LED_Chain_RX_BUFFER_SIZE)
            {
                Spi_LED_Chain_rxBufferWrite = 0u;
            }

            if(Spi_LED_Chain_rxBufferWrite == Spi_LED_Chain_rxBufferRead)
            {
                Spi_LED_Chain_rxBufferRead++;
                if(Spi_LED_Chain_rxBufferRead >= Spi_LED_Chain_RX_BUFFER_SIZE)
                {
                    Spi_LED_Chain_rxBufferRead = 0u;
                }

                Spi_LED_Chain_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            Spi_LED_Chain_rxBuffer[Spi_LED_Chain_rxBufferWrite] = rxData;

            tmpStatus = Spi_LED_Chain_GET_STATUS_RX(Spi_LED_Chain_swStatusRx);
            Spi_LED_Chain_swStatusRx = tmpStatus;
        }

    #endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START Spi_LED_Chain_RX_ISR_END` */

    /* `#END` */
    
    #ifdef Spi_LED_Chain_RX_ISR_EXIT_CALLBACK
        Spi_LED_Chain_RX_ISR_ExitCallback();
    #endif /* Spi_LED_Chain_RX_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
