/*******************************************************************************
* File Name: .h
* Version 2.50
*
* Description:
*  This private header file contains internal definitions for the SPIM
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_PVT_Spi_LED_Chain_H)
#define CY_SPIM_PVT_Spi_LED_Chain_H

#include "Spi_LED_Chain.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 Spi_LED_Chain_swStatusTx;
extern volatile uint8 Spi_LED_Chain_swStatusRx;

#if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 Spi_LED_Chain_txBuffer[Spi_LED_Chain_TX_BUFFER_SIZE];
    extern volatile uint8 Spi_LED_Chain_txBufferRead;
    extern volatile uint8 Spi_LED_Chain_txBufferWrite;
    extern volatile uint8 Spi_LED_Chain_txBufferFull;
#endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

#if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 Spi_LED_Chain_rxBuffer[Spi_LED_Chain_RX_BUFFER_SIZE];
    extern volatile uint8 Spi_LED_Chain_rxBufferRead;
    extern volatile uint8 Spi_LED_Chain_rxBufferWrite;
    extern volatile uint8 Spi_LED_Chain_rxBufferFull;
#endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_Spi_LED_Chain_H */


/* [] END OF FILE */
