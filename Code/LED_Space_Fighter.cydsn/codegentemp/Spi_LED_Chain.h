/*******************************************************************************
* File Name: Spi_LED_Chain.h
* Version 2.50
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Master Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_Spi_LED_Chain_H)
#define CY_SPIM_Spi_LED_Chain_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Spi_LED_Chain_INTERNAL_CLOCK             (0u)

#if(0u != Spi_LED_Chain_INTERNAL_CLOCK)
    #include "Spi_LED_Chain_IntClock.h"
#endif /* (0u != Spi_LED_Chain_INTERNAL_CLOCK) */

#define Spi_LED_Chain_MODE                       (1u)
#define Spi_LED_Chain_DATA_WIDTH                 (8u)
#define Spi_LED_Chain_MODE_USE_ZERO              (1u)
#define Spi_LED_Chain_BIDIRECTIONAL_MODE         (0u)

/* Internal interrupt handling */
#define Spi_LED_Chain_TX_BUFFER_SIZE             (4u)
#define Spi_LED_Chain_RX_BUFFER_SIZE             (4u)
#define Spi_LED_Chain_INTERNAL_TX_INT_ENABLED    (1u)
#define Spi_LED_Chain_INTERNAL_RX_INT_ENABLED    (0u)

#define Spi_LED_Chain_SINGLE_REG_SIZE            (8u)
#define Spi_LED_Chain_USE_SECOND_DATAPATH        (Spi_LED_Chain_DATA_WIDTH > Spi_LED_Chain_SINGLE_REG_SIZE)

#define Spi_LED_Chain_FIFO_SIZE                  (4u)
#define Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED    ((0u != Spi_LED_Chain_INTERNAL_TX_INT_ENABLED) && \
                                                     (Spi_LED_Chain_TX_BUFFER_SIZE > Spi_LED_Chain_FIFO_SIZE))

#define Spi_LED_Chain_RX_SOFTWARE_BUF_ENABLED    ((0u != Spi_LED_Chain_INTERNAL_RX_INT_ENABLED) && \
                                                     (Spi_LED_Chain_RX_BUFFER_SIZE > Spi_LED_Chain_FIFO_SIZE))


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint8 cntrPeriod;
} Spi_LED_Chain_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  Spi_LED_Chain_Init(void)                           ;
void  Spi_LED_Chain_Enable(void)                         ;
void  Spi_LED_Chain_Start(void)                          ;
void  Spi_LED_Chain_Stop(void)                           ;

void  Spi_LED_Chain_EnableTxInt(void)                    ;
void  Spi_LED_Chain_EnableRxInt(void)                    ;
void  Spi_LED_Chain_DisableTxInt(void)                   ;
void  Spi_LED_Chain_DisableRxInt(void)                   ;

void  Spi_LED_Chain_Sleep(void)                          ;
void  Spi_LED_Chain_Wakeup(void)                         ;
void  Spi_LED_Chain_SaveConfig(void)                     ;
void  Spi_LED_Chain_RestoreConfig(void)                  ;

void  Spi_LED_Chain_SetTxInterruptMode(uint8 intSrc)     ;
void  Spi_LED_Chain_SetRxInterruptMode(uint8 intSrc)     ;
uint8 Spi_LED_Chain_ReadTxStatus(void)                   ;
uint8 Spi_LED_Chain_ReadRxStatus(void)                   ;
void  Spi_LED_Chain_WriteTxData(uint8 txData)  \
                                                            ;
uint8 Spi_LED_Chain_ReadRxData(void) \
                                                            ;
uint8 Spi_LED_Chain_GetRxBufferSize(void)                ;
uint8 Spi_LED_Chain_GetTxBufferSize(void)                ;
void  Spi_LED_Chain_ClearRxBuffer(void)                  ;
void  Spi_LED_Chain_ClearTxBuffer(void)                  ;
void  Spi_LED_Chain_ClearFIFO(void)                              ;
void  Spi_LED_Chain_PutArray(const uint8 buffer[], uint8 byteCount) \
                                                            ;

#if(0u != Spi_LED_Chain_BIDIRECTIONAL_MODE)
    void  Spi_LED_Chain_TxEnable(void)                   ;
    void  Spi_LED_Chain_TxDisable(void)                  ;
#endif /* (0u != Spi_LED_Chain_BIDIRECTIONAL_MODE) */

CY_ISR_PROTO(Spi_LED_Chain_TX_ISR);
CY_ISR_PROTO(Spi_LED_Chain_RX_ISR);


/***************************************
*   Variable with external linkage
***************************************/

extern uint8 Spi_LED_Chain_initVar;


/***************************************
*           API Constants
***************************************/

#define Spi_LED_Chain_TX_ISR_NUMBER     ((uint8) (Spi_LED_Chain_TxInternalInterrupt__INTC_NUMBER))
#define Spi_LED_Chain_RX_ISR_NUMBER     ((uint8) (Spi_LED_Chain_RxInternalInterrupt__INTC_NUMBER))

#define Spi_LED_Chain_TX_ISR_PRIORITY   ((uint8) (Spi_LED_Chain_TxInternalInterrupt__INTC_PRIOR_NUM))
#define Spi_LED_Chain_RX_ISR_PRIORITY   ((uint8) (Spi_LED_Chain_RxInternalInterrupt__INTC_PRIOR_NUM))


/***************************************
*    Initial Parameter Constants
***************************************/

#define Spi_LED_Chain_INT_ON_SPI_DONE    ((uint8) (0u   << Spi_LED_Chain_STS_SPI_DONE_SHIFT))
#define Spi_LED_Chain_INT_ON_TX_EMPTY    ((uint8) (0u   << Spi_LED_Chain_STS_TX_FIFO_EMPTY_SHIFT))
#define Spi_LED_Chain_INT_ON_TX_NOT_FULL ((uint8) (0u << \
                                                                           Spi_LED_Chain_STS_TX_FIFO_NOT_FULL_SHIFT))
#define Spi_LED_Chain_INT_ON_BYTE_COMP   ((uint8) (1u  << Spi_LED_Chain_STS_BYTE_COMPLETE_SHIFT))
#define Spi_LED_Chain_INT_ON_SPI_IDLE    ((uint8) (0u   << Spi_LED_Chain_STS_SPI_IDLE_SHIFT))

/* Disable TX_NOT_FULL if software buffer is used */
#define Spi_LED_Chain_INT_ON_TX_NOT_FULL_DEF ((Spi_LED_Chain_TX_SOFTWARE_BUF_ENABLED) ? \
                                                                        (0u) : (Spi_LED_Chain_INT_ON_TX_NOT_FULL))

/* TX interrupt mask */
#define Spi_LED_Chain_TX_INIT_INTERRUPTS_MASK    (Spi_LED_Chain_INT_ON_SPI_DONE  | \
                                                     Spi_LED_Chain_INT_ON_TX_EMPTY  | \
                                                     Spi_LED_Chain_INT_ON_TX_NOT_FULL_DEF | \
                                                     Spi_LED_Chain_INT_ON_BYTE_COMP | \
                                                     Spi_LED_Chain_INT_ON_SPI_IDLE)

#define Spi_LED_Chain_INT_ON_RX_FULL         ((uint8) (0u << \
                                                                          Spi_LED_Chain_STS_RX_FIFO_FULL_SHIFT))
#define Spi_LED_Chain_INT_ON_RX_NOT_EMPTY    ((uint8) (0u << \
                                                                          Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define Spi_LED_Chain_INT_ON_RX_OVER         ((uint8) (0u << \
                                                                          Spi_LED_Chain_STS_RX_FIFO_OVERRUN_SHIFT))

/* RX interrupt mask */
#define Spi_LED_Chain_RX_INIT_INTERRUPTS_MASK    (Spi_LED_Chain_INT_ON_RX_FULL      | \
                                                     Spi_LED_Chain_INT_ON_RX_NOT_EMPTY | \
                                                     Spi_LED_Chain_INT_ON_RX_OVER)
/* Nubmer of bits to receive/transmit */
#define Spi_LED_Chain_BITCTR_INIT            (((uint8) (Spi_LED_Chain_DATA_WIDTH << 1u)) - 1u)


/***************************************
*             Registers
***************************************/
#if(CY_PSOC3 || CY_PSOC5)
    #define Spi_LED_Chain_TXDATA_REG (* (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F0_REG)
    #define Spi_LED_Chain_TXDATA_PTR (  (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F0_REG)
    #define Spi_LED_Chain_RXDATA_REG (* (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F1_REG)
    #define Spi_LED_Chain_RXDATA_PTR (  (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F1_REG)
#else   /* PSOC4 */
    #if(Spi_LED_Chain_USE_SECOND_DATAPATH)
        #define Spi_LED_Chain_TXDATA_REG (* (reg16 *) \
                                          Spi_LED_Chain_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define Spi_LED_Chain_TXDATA_PTR (  (reg16 *) \
                                          Spi_LED_Chain_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define Spi_LED_Chain_RXDATA_REG (* (reg16 *) \
                                          Spi_LED_Chain_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
        #define Spi_LED_Chain_RXDATA_PTR (  (reg16 *) \
                                          Spi_LED_Chain_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
    #else
        #define Spi_LED_Chain_TXDATA_REG (* (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F0_REG)
        #define Spi_LED_Chain_TXDATA_PTR (  (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F0_REG)
        #define Spi_LED_Chain_RXDATA_REG (* (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F1_REG)
        #define Spi_LED_Chain_RXDATA_PTR (  (reg8 *) \
                                                Spi_LED_Chain_BSPIM_sR8_Dp_u0__F1_REG)
    #endif /* (Spi_LED_Chain_USE_SECOND_DATAPATH) */
#endif     /* (CY_PSOC3 || CY_PSOC5) */

#define Spi_LED_Chain_AUX_CONTROL_DP0_REG (* (reg8 *) \
                                        Spi_LED_Chain_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)
#define Spi_LED_Chain_AUX_CONTROL_DP0_PTR (  (reg8 *) \
                                        Spi_LED_Chain_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)

#if(Spi_LED_Chain_USE_SECOND_DATAPATH)
    #define Spi_LED_Chain_AUX_CONTROL_DP1_REG  (* (reg8 *) \
                                        Spi_LED_Chain_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
    #define Spi_LED_Chain_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
                                        Spi_LED_Chain_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
#endif /* (Spi_LED_Chain_USE_SECOND_DATAPATH) */

#define Spi_LED_Chain_COUNTER_PERIOD_REG     (* (reg8 *) Spi_LED_Chain_BSPIM_BitCounter__PERIOD_REG)
#define Spi_LED_Chain_COUNTER_PERIOD_PTR     (  (reg8 *) Spi_LED_Chain_BSPIM_BitCounter__PERIOD_REG)
#define Spi_LED_Chain_COUNTER_CONTROL_REG    (* (reg8 *) Spi_LED_Chain_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define Spi_LED_Chain_COUNTER_CONTROL_PTR    (  (reg8 *) Spi_LED_Chain_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define Spi_LED_Chain_TX_STATUS_REG          (* (reg8 *) Spi_LED_Chain_BSPIM_TxStsReg__STATUS_REG)
#define Spi_LED_Chain_TX_STATUS_PTR          (  (reg8 *) Spi_LED_Chain_BSPIM_TxStsReg__STATUS_REG)
#define Spi_LED_Chain_RX_STATUS_REG          (* (reg8 *) Spi_LED_Chain_BSPIM_RxStsReg__STATUS_REG)
#define Spi_LED_Chain_RX_STATUS_PTR          (  (reg8 *) Spi_LED_Chain_BSPIM_RxStsReg__STATUS_REG)

#define Spi_LED_Chain_CONTROL_REG            (* (reg8 *) \
                                      Spi_LED_Chain_BSPIM_BidirMode_CtrlReg__CONTROL_REG)
#define Spi_LED_Chain_CONTROL_PTR            (  (reg8 *) \
                                      Spi_LED_Chain_BSPIM_BidirMode_CtrlReg__CONTROL_REG)

#define Spi_LED_Chain_TX_STATUS_MASK_REG     (* (reg8 *) Spi_LED_Chain_BSPIM_TxStsReg__MASK_REG)
#define Spi_LED_Chain_TX_STATUS_MASK_PTR     (  (reg8 *) Spi_LED_Chain_BSPIM_TxStsReg__MASK_REG)
#define Spi_LED_Chain_RX_STATUS_MASK_REG     (* (reg8 *) Spi_LED_Chain_BSPIM_RxStsReg__MASK_REG)
#define Spi_LED_Chain_RX_STATUS_MASK_PTR     (  (reg8 *) Spi_LED_Chain_BSPIM_RxStsReg__MASK_REG)

#define Spi_LED_Chain_TX_STATUS_ACTL_REG     (* (reg8 *) Spi_LED_Chain_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define Spi_LED_Chain_TX_STATUS_ACTL_PTR     (  (reg8 *) Spi_LED_Chain_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define Spi_LED_Chain_RX_STATUS_ACTL_REG     (* (reg8 *) Spi_LED_Chain_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define Spi_LED_Chain_RX_STATUS_ACTL_PTR     (  (reg8 *) Spi_LED_Chain_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

#if(Spi_LED_Chain_USE_SECOND_DATAPATH)
    #define Spi_LED_Chain_AUX_CONTROLDP1     (Spi_LED_Chain_AUX_CONTROL_DP1_REG)
#endif /* (Spi_LED_Chain_USE_SECOND_DATAPATH) */


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define Spi_LED_Chain_STS_SPI_DONE_SHIFT             (0x00u)
#define Spi_LED_Chain_STS_TX_FIFO_EMPTY_SHIFT        (0x01u)
#define Spi_LED_Chain_STS_TX_FIFO_NOT_FULL_SHIFT     (0x02u)
#define Spi_LED_Chain_STS_BYTE_COMPLETE_SHIFT        (0x03u)
#define Spi_LED_Chain_STS_SPI_IDLE_SHIFT             (0x04u)
#define Spi_LED_Chain_STS_RX_FIFO_FULL_SHIFT         (0x04u)
#define Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x05u)
#define Spi_LED_Chain_STS_RX_FIFO_OVERRUN_SHIFT      (0x06u)

#define Spi_LED_Chain_STS_SPI_DONE           ((uint8) (0x01u << Spi_LED_Chain_STS_SPI_DONE_SHIFT))
#define Spi_LED_Chain_STS_TX_FIFO_EMPTY      ((uint8) (0x01u << Spi_LED_Chain_STS_TX_FIFO_EMPTY_SHIFT))
#define Spi_LED_Chain_STS_TX_FIFO_NOT_FULL   ((uint8) (0x01u << Spi_LED_Chain_STS_TX_FIFO_NOT_FULL_SHIFT))
#define Spi_LED_Chain_STS_BYTE_COMPLETE      ((uint8) (0x01u << Spi_LED_Chain_STS_BYTE_COMPLETE_SHIFT))
#define Spi_LED_Chain_STS_SPI_IDLE           ((uint8) (0x01u << Spi_LED_Chain_STS_SPI_IDLE_SHIFT))
#define Spi_LED_Chain_STS_RX_FIFO_FULL       ((uint8) (0x01u << Spi_LED_Chain_STS_RX_FIFO_FULL_SHIFT))
#define Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY  ((uint8) (0x01u << Spi_LED_Chain_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define Spi_LED_Chain_STS_RX_FIFO_OVERRUN    ((uint8) (0x01u << Spi_LED_Chain_STS_RX_FIFO_OVERRUN_SHIFT))

/* TX and RX masks for clear on read bits */
#define Spi_LED_Chain_TX_STS_CLR_ON_RD_BYTES_MASK    (0x09u)
#define Spi_LED_Chain_RX_STS_CLR_ON_RD_BYTES_MASK    (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define Spi_LED_Chain_INT_ENABLE     (0x10u) /* Enable interrupt from statusi */
#define Spi_LED_Chain_TX_FIFO_CLR    (0x01u) /* F0 - TX FIFO */
#define Spi_LED_Chain_RX_FIFO_CLR    (0x02u) /* F1 - RX FIFO */
#define Spi_LED_Chain_FIFO_CLR       (Spi_LED_Chain_TX_FIFO_CLR | Spi_LED_Chain_RX_FIFO_CLR)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define Spi_LED_Chain_CNTR_ENABLE    (0x20u) /* Enable CNT7 */

/* Bi-Directional mode control bit */
#define Spi_LED_Chain_CTRL_TX_SIGNAL_EN  (0x01u)

/* Datapath Auxillary Control Register definitions */
#define Spi_LED_Chain_AUX_CTRL_FIFO0_CLR         (0x01u)
#define Spi_LED_Chain_AUX_CTRL_FIFO1_CLR         (0x02u)
#define Spi_LED_Chain_AUX_CTRL_FIFO0_LVL         (0x04u)
#define Spi_LED_Chain_AUX_CTRL_FIFO1_LVL         (0x08u)
#define Spi_LED_Chain_STATUS_ACTL_INT_EN_MASK    (0x10u)

/* Component disabled */
#define Spi_LED_Chain_DISABLED   (0u)


/***************************************
*       Macros
***************************************/

/* Returns true if componentn enabled */
#define Spi_LED_Chain_IS_ENABLED (0u != (Spi_LED_Chain_TX_STATUS_ACTL_REG & Spi_LED_Chain_INT_ENABLE))

/* Retuns TX status register */
#define Spi_LED_Chain_GET_STATUS_TX(swTxSts) ( (uint8)(Spi_LED_Chain_TX_STATUS_REG | \
                                                          ((swTxSts) & Spi_LED_Chain_TX_STS_CLR_ON_RD_BYTES_MASK)) )
/* Retuns RX status register */
#define Spi_LED_Chain_GET_STATUS_RX(swRxSts) ( (uint8)(Spi_LED_Chain_RX_STATUS_REG | \
                                                          ((swRxSts) & Spi_LED_Chain_RX_STS_CLR_ON_RD_BYTES_MASK)) )


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define Spi_LED_Chain_WriteByte   Spi_LED_Chain_WriteTxData
#define Spi_LED_Chain_ReadByte    Spi_LED_Chain_ReadRxData
void  Spi_LED_Chain_SetInterruptMode(uint8 intSrc)       ;
uint8 Spi_LED_Chain_ReadStatus(void)                     ;
void  Spi_LED_Chain_EnableInt(void)                      ;
void  Spi_LED_Chain_DisableInt(void)                     ;

#define Spi_LED_Chain_TXDATA                 (Spi_LED_Chain_TXDATA_REG)
#define Spi_LED_Chain_RXDATA                 (Spi_LED_Chain_RXDATA_REG)
#define Spi_LED_Chain_AUX_CONTROLDP0         (Spi_LED_Chain_AUX_CONTROL_DP0_REG)
#define Spi_LED_Chain_TXBUFFERREAD           (Spi_LED_Chain_txBufferRead)
#define Spi_LED_Chain_TXBUFFERWRITE          (Spi_LED_Chain_txBufferWrite)
#define Spi_LED_Chain_RXBUFFERREAD           (Spi_LED_Chain_rxBufferRead)
#define Spi_LED_Chain_RXBUFFERWRITE          (Spi_LED_Chain_rxBufferWrite)

#define Spi_LED_Chain_COUNTER_PERIOD         (Spi_LED_Chain_COUNTER_PERIOD_REG)
#define Spi_LED_Chain_COUNTER_CONTROL        (Spi_LED_Chain_COUNTER_CONTROL_REG)
#define Spi_LED_Chain_STATUS                 (Spi_LED_Chain_TX_STATUS_REG)
#define Spi_LED_Chain_CONTROL                (Spi_LED_Chain_CONTROL_REG)
#define Spi_LED_Chain_STATUS_MASK            (Spi_LED_Chain_TX_STATUS_MASK_REG)
#define Spi_LED_Chain_STATUS_ACTL            (Spi_LED_Chain_TX_STATUS_ACTL_REG)

#define Spi_LED_Chain_INIT_INTERRUPTS_MASK  (Spi_LED_Chain_INT_ON_SPI_DONE     | \
                                                Spi_LED_Chain_INT_ON_TX_EMPTY     | \
                                                Spi_LED_Chain_INT_ON_TX_NOT_FULL_DEF  | \
                                                Spi_LED_Chain_INT_ON_RX_FULL      | \
                                                Spi_LED_Chain_INT_ON_RX_NOT_EMPTY | \
                                                Spi_LED_Chain_INT_ON_RX_OVER      | \
                                                Spi_LED_Chain_INT_ON_BYTE_COMP)
                                                
#define Spi_LED_Chain_DataWidth                  (Spi_LED_Chain_DATA_WIDTH)
#define Spi_LED_Chain_InternalClockUsed          (Spi_LED_Chain_INTERNAL_CLOCK)
#define Spi_LED_Chain_InternalTxInterruptEnabled (Spi_LED_Chain_INTERNAL_TX_INT_ENABLED)
#define Spi_LED_Chain_InternalRxInterruptEnabled (Spi_LED_Chain_INTERNAL_RX_INT_ENABLED)
#define Spi_LED_Chain_ModeUseZero                (Spi_LED_Chain_MODE_USE_ZERO)
#define Spi_LED_Chain_BidirectionalMode          (Spi_LED_Chain_BIDIRECTIONAL_MODE)
#define Spi_LED_Chain_Mode                       (Spi_LED_Chain_MODE)
#define Spi_LED_Chain_DATAWIDHT                  (Spi_LED_Chain_DATA_WIDTH)
#define Spi_LED_Chain_InternalInterruptEnabled   (0u)

#define Spi_LED_Chain_TXBUFFERSIZE   (Spi_LED_Chain_TX_BUFFER_SIZE)
#define Spi_LED_Chain_RXBUFFERSIZE   (Spi_LED_Chain_RX_BUFFER_SIZE)

#define Spi_LED_Chain_TXBUFFER       Spi_LED_Chain_txBuffer
#define Spi_LED_Chain_RXBUFFER       Spi_LED_Chain_rxBuffer

#endif /* (CY_SPIM_Spi_LED_Chain_H) */


/* [] END OF FILE */
