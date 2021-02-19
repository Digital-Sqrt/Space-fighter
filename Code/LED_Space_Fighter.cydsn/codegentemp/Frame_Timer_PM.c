/*******************************************************************************
* File Name: Frame_Timer_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Frame_Timer.h"

static Frame_Timer_backupStruct Frame_Timer_backup;


/*******************************************************************************
* Function Name: Frame_Timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Frame_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Frame_Timer_SaveConfig(void) 
{
    #if (!Frame_Timer_UsingFixedFunction)
        Frame_Timer_backup.TimerUdb = Frame_Timer_ReadCounter();
        Frame_Timer_backup.InterruptMaskValue = Frame_Timer_STATUS_MASK;
        #if (Frame_Timer_UsingHWCaptureCounter)
            Frame_Timer_backup.TimerCaptureCounter = Frame_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Frame_Timer_UDB_CONTROL_REG_REMOVED)
            Frame_Timer_backup.TimerControlRegister = Frame_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Frame_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Frame_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Frame_Timer_RestoreConfig(void) 
{   
    #if (!Frame_Timer_UsingFixedFunction)

        Frame_Timer_WriteCounter(Frame_Timer_backup.TimerUdb);
        Frame_Timer_STATUS_MASK =Frame_Timer_backup.InterruptMaskValue;
        #if (Frame_Timer_UsingHWCaptureCounter)
            Frame_Timer_SetCaptureCount(Frame_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Frame_Timer_UDB_CONTROL_REG_REMOVED)
            Frame_Timer_WriteControlRegister(Frame_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Frame_Timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Frame_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Frame_Timer_Sleep(void) 
{
    #if(!Frame_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Frame_Timer_CTRL_ENABLE == (Frame_Timer_CONTROL & Frame_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Frame_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Frame_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Frame_Timer_Stop();
    Frame_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Frame_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Frame_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Frame_Timer_Wakeup(void) 
{
    Frame_Timer_RestoreConfig();
    #if(!Frame_Timer_UDB_CONTROL_REG_REMOVED)
        if(Frame_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Frame_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
