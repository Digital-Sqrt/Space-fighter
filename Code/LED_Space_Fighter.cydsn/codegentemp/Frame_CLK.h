/*******************************************************************************
* File Name: Frame_CLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Frame_CLK_H)
#define CY_CLOCK_Frame_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Frame_CLK_Start(void) ;
void Frame_CLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Frame_CLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Frame_CLK_StandbyPower(uint8 state) ;
void Frame_CLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Frame_CLK_GetDividerRegister(void) ;
void Frame_CLK_SetModeRegister(uint8 modeBitMask) ;
void Frame_CLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 Frame_CLK_GetModeRegister(void) ;
void Frame_CLK_SetSourceRegister(uint8 clkSource) ;
uint8 Frame_CLK_GetSourceRegister(void) ;
#if defined(Frame_CLK__CFG3)
void Frame_CLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 Frame_CLK_GetPhaseRegister(void) ;
#endif /* defined(Frame_CLK__CFG3) */

#define Frame_CLK_Enable()                       Frame_CLK_Start()
#define Frame_CLK_Disable()                      Frame_CLK_Stop()
#define Frame_CLK_SetDivider(clkDivider)         Frame_CLK_SetDividerRegister(clkDivider, 1u)
#define Frame_CLK_SetDividerValue(clkDivider)    Frame_CLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define Frame_CLK_SetMode(clkMode)               Frame_CLK_SetModeRegister(clkMode)
#define Frame_CLK_SetSource(clkSource)           Frame_CLK_SetSourceRegister(clkSource)
#if defined(Frame_CLK__CFG3)
#define Frame_CLK_SetPhase(clkPhase)             Frame_CLK_SetPhaseRegister(clkPhase)
#define Frame_CLK_SetPhaseValue(clkPhase)        Frame_CLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Frame_CLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Frame_CLK_CLKEN              (* (reg8 *) Frame_CLK__PM_ACT_CFG)
#define Frame_CLK_CLKEN_PTR          ((reg8 *) Frame_CLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Frame_CLK_CLKSTBY            (* (reg8 *) Frame_CLK__PM_STBY_CFG)
#define Frame_CLK_CLKSTBY_PTR        ((reg8 *) Frame_CLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Frame_CLK_DIV_LSB            (* (reg8 *) Frame_CLK__CFG0)
#define Frame_CLK_DIV_LSB_PTR        ((reg8 *) Frame_CLK__CFG0)
#define Frame_CLK_DIV_PTR            ((reg16 *) Frame_CLK__CFG0)

/* Clock MSB divider configuration register. */
#define Frame_CLK_DIV_MSB            (* (reg8 *) Frame_CLK__CFG1)
#define Frame_CLK_DIV_MSB_PTR        ((reg8 *) Frame_CLK__CFG1)

/* Mode and source configuration register */
#define Frame_CLK_MOD_SRC            (* (reg8 *) Frame_CLK__CFG2)
#define Frame_CLK_MOD_SRC_PTR        ((reg8 *) Frame_CLK__CFG2)

#if defined(Frame_CLK__CFG3)
/* Analog clock phase configuration register */
#define Frame_CLK_PHASE              (* (reg8 *) Frame_CLK__CFG3)
#define Frame_CLK_PHASE_PTR          ((reg8 *) Frame_CLK__CFG3)
#endif /* defined(Frame_CLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Frame_CLK_CLKEN_MASK         Frame_CLK__PM_ACT_MSK
#define Frame_CLK_CLKSTBY_MASK       Frame_CLK__PM_STBY_MSK

/* CFG2 field masks */
#define Frame_CLK_SRC_SEL_MSK        Frame_CLK__CFG2_SRC_SEL_MASK
#define Frame_CLK_MODE_MASK          (~(Frame_CLK_SRC_SEL_MSK))

#if defined(Frame_CLK__CFG3)
/* CFG3 phase mask */
#define Frame_CLK_PHASE_MASK         Frame_CLK__CFG3_PHASE_DLY_MASK
#endif /* defined(Frame_CLK__CFG3) */

#endif /* CY_CLOCK_Frame_CLK_H */


/* [] END OF FILE */
