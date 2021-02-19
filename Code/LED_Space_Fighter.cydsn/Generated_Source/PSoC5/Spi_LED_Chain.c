/*******************************************************************************
* File Name: Spi_LED_Chain.c
* Version 2.50
*
* Description:
*  This file provides all API functionality of the SPI Master component.
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

#if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
    volatile uint8 Spi_LED_Chain_txBuffer[Spi_LED_Chain_TX_BUFFER_SIZE];
    volatile uint8 Spi_LED_Chain_txBufferFull;
    volatile uint8 Spi_LED_Chain_txBufferRead;
    volatile uint8 Spi_LED_Chain_txBufferWrite;
#endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

#if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)
    volatile uint8 Spi_LED_Chain_rxBuffer[Spi_LED_Chain_RX_BUFFER_SIZE];
    volatile uint8 Spi_LED_Chain_rxBufferFull;
    volatile uint8 Spi_LED_Chain_rxBufferRead;
    volatile uint8 Spi_LED_Chain_rxBufferWrite;
#endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

uint8 Spi_LED_Chain_initVar = 0u;

volatile uint8 Spi_LED_Chain_swStatusTx;
volatile uint8 Spi_LED_Chain_swStatusRx;


/*******************************************************************************
* Function Name: Spi_LED_Chain_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIM configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the
*  interrupt service routine, configuring the bit-counter parameters and
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_Init(void) 
{
    /* Initialize the Bit counter */
    Spi_LED_Chain_COUNTER_PERIOD_REG = Spi_LED_Chain_BITCTR_INIT;

    /* Init TX ISR  */
    #if(0u != Spi_LED_Chain_INTERNAL_TX_INT_ENABLED)
        CyIntDisable         (Spi_LED_Chain_TX_ISR_NUMBER);
        CyIntSetPriority     (Spi_LED_Chain_TX_ISR_NUMBER,  Spi_LED_Chain_TX_ISR_PRIORITY);
        (void) CyIntSetVector(Spi_LED_Chain_TX_ISR_NUMBER, &Spi_LED_Chain_TX_ISR);
    #endif /* (0u != Spi_LED_Chain_INTERNAL_TX_INT_ENABLED) */

    /* Init RX ISR  */
    #if(0u != Spi_LED_Chain_INTERNAL_RX_INT_ENABLED)
        CyIntDisable         (Spi_LED_Chain_RX_ISR_NUMBER);
        CyIntSetPriority     (Spi_LED_Chain_RX_ISR_NUMBER,  Spi_LED_Chain_RX_ISR_PRIORITY);
        (void) CyIntSetVector(Spi_LED_Chain_RX_ISR_NUMBER, &Spi_LED_Chain_RX_ISR);
    #endif /* (0u != Spi_LED_Chain_INTERNAL_RX_INT_ENABLED) */

    /* Clear any stray data from the RX and TX FIFO */
    Spi_LED_Chain_ClearFIFO();

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

    (void) Spi_LED_Chain_ReadTxStatus(); /* Clear Tx status and swStatusTx */
    (void) Spi_LED_Chain_ReadRxStatus(); /* Clear Rx status and swStatusRx */

    /* Configure TX and RX interrupt mask */
    Spi_LED_Chain_TX_STATUS_MASK_REG = Spi_LED_Chain_TX_INIT_INTERRUPTS_MASK;
    Spi_LED_Chain_RX_STATUS_MASK_REG = Spi_LED_Chain_RX_INIT_INTERRUPTS_MASK;
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_Enable
********************************************************************************
*
* Summary:
*  Enable SPIM component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Spi_LED_Chain_Enable(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    Spi_LED_Chain_COUNTER_CONTROL_REG |= Spi_LED_Chain_CNTR_ENABLE;
    Spi_LED_Chain_TX_STATUS_ACTL_REG  |= Spi_LED_Chain_INT_ENABLE;
    Spi_LED_Chain_RX_STATUS_ACTL_REG  |= Spi_LED_Chain_INT_ENABLE;
    CyExitCriticalSection(enableInterrupts);

    #if(0u != Spi_LED_Chain_INTERNAL_CLOCK)
        Spi_LED_Chain_IntClock_Enable();
    #endif /* (0u != Spi_LED_Chain_INTERNAL_CLOCK) */

    Spi_LED_Chain_EnableTxInt();
    Spi_LED_Chain_EnableRxInt();
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Spi_LED_Chain_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_Start(void) 
{
    if(0u == Spi_LED_Chain_initVar)
    {
        Spi_LED_Chain_Init();
        Spi_LED_Chain_initVar = 1u;
    }

    Spi_LED_Chain_Enable();
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the clock input to enable operation.
*
*******************************************************************************/
void Spi_LED_Chain_Stop(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    Spi_LED_Chain_TX_STATUS_ACTL_REG &= ((uint8) ~Spi_LED_Chain_INT_ENABLE);
    Spi_LED_Chain_RX_STATUS_ACTL_REG &= ((uint8) ~Spi_LED_Chain_INT_ENABLE);
    CyExitCriticalSection(enableInterrupts);

    #if(0u != Spi_LED_Chain_INTERNAL_CLOCK)
        Spi_LED_Chain_IntClock_Disable();
    #endif /* (0u != Spi_LED_Chain_INTERNAL_CLOCK) */

    Spi_LED_Chain_DisableTxInt();
    Spi_LED_Chain_DisableRxInt();
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void Spi_LED_Chain_EnableTxInt(void) 
{
    #if(0u != Spi_LED_Chain_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(Spi_LED_Chain_TX_ISR_NUMBER);
    #endif /* (0u != Spi_LED_Chain_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void Spi_LED_Chain_EnableRxInt(void) 
{
    #if(0u != Spi_LED_Chain_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(Spi_LED_Chain_RX_ISR_NUMBER);
    #endif /* (0u != Spi_LED_Chain_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void Spi_LED_Chain_DisableTxInt(void) 
{
    #if(0u != Spi_LED_Chain_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(Spi_LED_Chain_TX_ISR_NUMBER);
    #endif /* (0u != Spi_LED_Chain_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void Spi_LED_Chain_DisableRxInt(void) 
{
    #if(0u != Spi_LED_Chain_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(Spi_LED_Chain_RX_ISR_NUMBER);
    #endif /* (0u != Spi_LED_Chain_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void Spi_LED_Chain_SetTxInterruptMode(uint8 intSrc) 
{
    Spi_LED_Chain_TX_STATUS_MASK_REG = intSrc;
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void Spi_LED_Chain_SetRxInterruptMode(uint8 intSrc) 
{
    Spi_LED_Chain_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  Spi_LED_Chain_swStatusTx - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Spi_LED_Chain_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        Spi_LED_Chain_DisableTxInt();

        tmpStatus = Spi_LED_Chain_GET_STATUS_TX(Spi_LED_Chain_swStatusTx);
        Spi_LED_Chain_swStatusTx = 0u;

        Spi_LED_Chain_EnableTxInt();

    #else

        tmpStatus = Spi_LED_Chain_TX_STATUS_REG;

    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  Spi_LED_Chain_swStatusRx - used to store in software Rx status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Spi_LED_Chain_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        Spi_LED_Chain_DisableRxInt();

        tmpStatus = Spi_LED_Chain_GET_STATUS_RX(Spi_LED_Chain_swStatusRx);
        Spi_LED_Chain_swStatusRx = 0u;

        Spi_LED_Chain_EnableRxInt();

    #else

        tmpStatus = Spi_LED_Chain_RX_STATUS_REG;

    #endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  Spi_LED_Chain_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  Spi_LED_Chain_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  Spi_LED_Chain_txBuffer[Spi_LED_Chain_TX_BUFFER_SIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_WriteTxData(uint8 txData) 
{
    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if TX buffer is FULL: don't overwrite */
        do
        {
            tmpTxBufferRead = Spi_LED_Chain_txBufferRead;
            if(0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = (Spi_LED_Chain_TX_BUFFER_SIZE - 1u);
            }
            else
            {
                tmpTxBufferRead--;
            }

        }while(tmpTxBufferRead == Spi_LED_Chain_txBufferWrite);

        /* Disable TX interrupt to protect global veriables */
        Spi_LED_Chain_DisableTxInt();

        tempStatus = Spi_LED_Chain_GET_STATUS_TX(Spi_LED_Chain_swStatusTx);
        Spi_LED_Chain_swStatusTx = tempStatus;


        if((Spi_LED_Chain_txBufferRead == Spi_LED_Chain_txBufferWrite) &&
           (0u != (Spi_LED_Chain_swStatusTx & Spi_LED_Chain_STS_TX_FIFO_NOT_FULL)))
        {
            /* Put data element into the TX FIFO */
            CY_SET_REG8(Spi_LED_Chain_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the TX software buffer */
            Spi_LED_Chain_txBufferWrite++;
            if(Spi_LED_Chain_txBufferWrite >= Spi_LED_Chain_TX_BUFFER_SIZE)
            {
                Spi_LED_Chain_txBufferWrite = 0u;
            }

            if(Spi_LED_Chain_txBufferWrite == Spi_LED_Chain_txBufferRead)
            {
                Spi_LED_Chain_txBufferRead++;
                if(Spi_LED_Chain_txBufferRead >= Spi_LED_Chain_TX_BUFFER_SIZE)
                {
                    Spi_LED_Chain_txBufferRead = 0u;
                }
                Spi_LED_Chain_txBufferFull = 1u;
            }

            Spi_LED_Chain_txBuffer[Spi_LED_Chain_txBufferWrite] = txData;

            Spi_LED_Chain_TX_STATUS_MASK_REG |= Spi_LED_Chain_STS_TX_FIFO_NOT_FULL;
        }

        Spi_LED_Chain_EnableTxInt();

    #else
        /* Wait until TX FIFO has a place */
        while(0u == (Spi_LED_Chain_TX_STATUS_REG & Spi_LED_Chain_STS_TX_FIFO_NOT_FULL))
        {
        }

        /* Put data element into the TX FIFO */
        CY_SET_REG8(Spi_LED_Chain_TXDATA_PTR, txData);

    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  Spi_LED_Chain_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  Spi_LED_Chain_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  Spi_LED_Chain_rxBuffer[Spi_LED_Chain_RX_BUFFER_SIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty. The user should Call
*  GetRxBufferSize() and if it returns a non-zero value then it is safe to call
*  ReadByte() function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Spi_LED_Chain_ReadRxData(void) 
{
    uint8 rxData;

    #if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        Spi_LED_Chain_DisableRxInt();

        if(Spi_LED_Chain_rxBufferRead != Spi_LED_Chain_rxBufferWrite)
        {
            if(0u == Spi_LED_Chain_rxBufferFull)
            {
                Spi_LED_Chain_rxBufferRead++;
                if(Spi_LED_Chain_rxBufferRead >= Spi_LED_Chain_RX_BUFFER_SIZE)
                {
                    Spi_LED_Chain_rxBufferRead = 0u;
                }
            }
            else
            {
                Spi_LED_Chain_rxBufferFull = 0u;
            }
        }

        rxData = Spi_LED_Chain_rxBuffer[Spi_LED_Chain_rxBufferRead];

        Spi_LED_Chain_EnableRxInt();

    #else

        rxData = CY_GET_REG8(Spi_LED_Chain_RXDATA_PTR);

    #endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

    return(rxData);
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  Spi_LED_Chain_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  Spi_LED_Chain_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 Spi_LED_Chain_GetRxBufferSize(void) 
{
    uint8 size;

    #if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        Spi_LED_Chain_DisableRxInt();

        if(Spi_LED_Chain_rxBufferRead == Spi_LED_Chain_rxBufferWrite)
        {
            size = 0u;
        }
        else if(Spi_LED_Chain_rxBufferRead < Spi_LED_Chain_rxBufferWrite)
        {
            size = (Spi_LED_Chain_rxBufferWrite - Spi_LED_Chain_rxBufferRead);
        }
        else
        {
            size = (Spi_LED_Chain_RX_BUFFER_SIZE - Spi_LED_Chain_rxBufferRead) + Spi_LED_Chain_rxBufferWrite;
        }

        Spi_LED_Chain_EnableRxInt();

    #else

        /* We can only know if there is data in the RX FIFO */
        size = (0u != (Spi_LED_Chain_RX_STATUS_REG & Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY)) ? 1u : 0u;

    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  Spi_LED_Chain_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  Spi_LED_Chain_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  Spi_LED_Chain_GetTxBufferSize(void) 
{
    uint8 size;

    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        Spi_LED_Chain_DisableTxInt();

        if(Spi_LED_Chain_txBufferRead == Spi_LED_Chain_txBufferWrite)
        {
            size = 0u;
        }
        else if(Spi_LED_Chain_txBufferRead < Spi_LED_Chain_txBufferWrite)
        {
            size = (Spi_LED_Chain_txBufferWrite - Spi_LED_Chain_txBufferRead);
        }
        else
        {
            size = (Spi_LED_Chain_TX_BUFFER_SIZE - Spi_LED_Chain_txBufferRead) + Spi_LED_Chain_txBufferWrite;
        }

        Spi_LED_Chain_EnableTxInt();

    #else

        size = Spi_LED_Chain_TX_STATUS_REG;

        if(0u != (size & Spi_LED_Chain_STS_TX_FIFO_EMPTY))
        {
            size = 0u;
        }
        else if(0u != (size & Spi_LED_Chain_STS_TX_FIFO_NOT_FULL))
        {
            size = 1u;
        }
        else
        {
            size = Spi_LED_Chain_FIFO_SIZE;
        }

    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Spi_LED_Chain_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  Spi_LED_Chain_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while(0u !=(Spi_LED_Chain_RX_STATUS_REG & Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG8(Spi_LED_Chain_RXDATA_PTR);
    }

    #if(Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        Spi_LED_Chain_DisableRxInt();

        Spi_LED_Chain_rxBufferFull  = 0u;
        Spi_LED_Chain_rxBufferRead  = 0u;
        Spi_LED_Chain_rxBufferWrite = 0u;

        Spi_LED_Chain_EnableRxInt();
    #endif /* (Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Spi_LED_Chain_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  Spi_LED_Chain_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    Spi_LED_Chain_AUX_CONTROL_DP0_REG |= ((uint8)  Spi_LED_Chain_TX_FIFO_CLR);
    Spi_LED_Chain_AUX_CONTROL_DP0_REG &= ((uint8) ~Spi_LED_Chain_TX_FIFO_CLR);

    #if(Spi_LED_Chain_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        Spi_LED_Chain_AUX_CONTROL_DP1_REG |= ((uint8)  Spi_LED_Chain_TX_FIFO_CLR);
        Spi_LED_Chain_AUX_CONTROL_DP1_REG &= ((uint8) ~Spi_LED_Chain_TX_FIFO_CLR);
    #endif /* (Spi_LED_Chain_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);

    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        Spi_LED_Chain_DisableTxInt();

        Spi_LED_Chain_txBufferFull  = 0u;
        Spi_LED_Chain_txBufferRead  = 0u;
        Spi_LED_Chain_txBufferWrite = 0u;

        /* Buffer is EMPTY: disable TX FIFO NOT FULL interrupt */
        Spi_LED_Chain_TX_STATUS_MASK_REG &= ((uint8) ~Spi_LED_Chain_STS_TX_FIFO_NOT_FULL);

        Spi_LED_Chain_EnableTxInt();
    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) */
}


#if(0u != Spi_LED_Chain_BIDIRECTIONAL_MODE)
    /*******************************************************************************
    * Function Name: Spi_LED_Chain_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Spi_LED_Chain_TxEnable(void) 
    {
        Spi_LED_Chain_CONTROL_REG |= Spi_LED_Chain_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: Spi_LED_Chain_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Spi_LED_Chain_TxDisable(void) 
    {
        Spi_LED_Chain_CONTROL_REG &= ((uint8) ~Spi_LED_Chain_CTRL_TX_SIGNAL_EN);
    }

#endif /* (0u != Spi_LED_Chain_BIDIRECTIONAL_MODE) */


/*******************************************************************************
* Function Name: Spi_LED_Chain_PutArray
********************************************************************************
*
* Summary:
*  Write available data from ROM/RAM to the TX buffer while space is available
*  in the TX buffer. Keep trying until all data is passed to the TX buffer.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Spi_LED_Chain_PutArray(const uint8 buffer[], uint8 byteCount)
                                                                          
{
    uint8 bufIndex;

    bufIndex = 0u;

    while(byteCount > 0u)
    {
        Spi_LED_Chain_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void Spi_LED_Chain_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware RX FIFO */
    while(0u !=(Spi_LED_Chain_RX_STATUS_REG & Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG8(Spi_LED_Chain_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    Spi_LED_Chain_AUX_CONTROL_DP0_REG |= ((uint8)  Spi_LED_Chain_TX_FIFO_CLR);
    Spi_LED_Chain_AUX_CONTROL_DP0_REG &= ((uint8) ~Spi_LED_Chain_TX_FIFO_CLR);

    #if(Spi_LED_Chain_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        Spi_LED_Chain_AUX_CONTROL_DP1_REG |= ((uint8)  Spi_LED_Chain_TX_FIFO_CLR);
        Spi_LED_Chain_AUX_CONTROL_DP1_REG &= ((uint8) ~Spi_LED_Chain_TX_FIFO_CLR);
    #endif /* (Spi_LED_Chain_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: Spi_LED_Chain_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void Spi_LED_Chain_EnableInt(void) 
{
    Spi_LED_Chain_EnableRxInt();
    Spi_LED_Chain_EnableTxInt();
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void Spi_LED_Chain_DisableInt(void) 
{
    Spi_LED_Chain_DisableTxInt();
    Spi_LED_Chain_DisableRxInt();
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void Spi_LED_Chain_SetInterruptMode(uint8 intSrc) 
{
    Spi_LED_Chain_TX_STATUS_MASK_REG  = (intSrc & ((uint8) ~Spi_LED_Chain_STS_SPI_IDLE));
    Spi_LED_Chain_RX_STATUS_MASK_REG  =  intSrc;
}


/*******************************************************************************
* Function Name: Spi_LED_Chain_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  Spi_LED_Chain_swStatus - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Spi_LED_Chain_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if(Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED || Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED)

        Spi_LED_Chain_DisableInt();

        tmpStatus  = Spi_LED_Chain_GET_STATUS_RX(Spi_LED_Chain_swStatusRx);
        tmpStatus |= Spi_LED_Chain_GET_STATUS_TX(Spi_LED_Chain_swStatusTx);
        tmpStatus &= ((uint8) ~Spi_LED_Chain_STS_SPI_IDLE);

        Spi_LED_Chain_swStatusTx = 0u;
        Spi_LED_Chain_swStatusRx = 0u;

        Spi_LED_Chain_EnableInt();

    #else

        tmpStatus  = Spi_LED_Chain_RX_STATUS_REG;
        tmpStatus |= Spi_LED_Chain_TX_STATUS_REG;
        tmpStatus &= ((uint8) ~Spi_LED_Chain_STS_SPI_IDLE);

    #endif /* (Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED || Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
