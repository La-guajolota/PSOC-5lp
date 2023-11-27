/*******************************************************************************
* File Name: Sampling_PM.c
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

#include "Sampling.h"

static Sampling_backupStruct Sampling_backup;


/*******************************************************************************
* Function Name: Sampling_SaveConfig
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
*  Sampling_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Sampling_SaveConfig(void) 
{
    #if (!Sampling_UsingFixedFunction)
        Sampling_backup.TimerUdb = Sampling_ReadCounter();
        Sampling_backup.InterruptMaskValue = Sampling_STATUS_MASK;
        #if (Sampling_UsingHWCaptureCounter)
            Sampling_backup.TimerCaptureCounter = Sampling_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Sampling_UDB_CONTROL_REG_REMOVED)
            Sampling_backup.TimerControlRegister = Sampling_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Sampling_RestoreConfig
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
*  Sampling_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Sampling_RestoreConfig(void) 
{   
    #if (!Sampling_UsingFixedFunction)

        Sampling_WriteCounter(Sampling_backup.TimerUdb);
        Sampling_STATUS_MASK =Sampling_backup.InterruptMaskValue;
        #if (Sampling_UsingHWCaptureCounter)
            Sampling_SetCaptureCount(Sampling_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Sampling_UDB_CONTROL_REG_REMOVED)
            Sampling_WriteControlRegister(Sampling_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Sampling_Sleep
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
*  Sampling_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Sampling_Sleep(void) 
{
    #if(!Sampling_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Sampling_CTRL_ENABLE == (Sampling_CONTROL & Sampling_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Sampling_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Sampling_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Sampling_Stop();
    Sampling_SaveConfig();
}


/*******************************************************************************
* Function Name: Sampling_Wakeup
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
*  Sampling_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Sampling_Wakeup(void) 
{
    Sampling_RestoreConfig();
    #if(!Sampling_UDB_CONTROL_REG_REMOVED)
        if(Sampling_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Sampling_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
