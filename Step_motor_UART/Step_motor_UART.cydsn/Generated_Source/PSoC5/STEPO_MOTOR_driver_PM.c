/*******************************************************************************
* File Name: STEPO_MOTOR_driver_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "STEPO_MOTOR_driver.h"

/* Check for removal by optimization */
#if !defined(STEPO_MOTOR_driver_Sync_ctrl_reg__REMOVED)

static STEPO_MOTOR_driver_BACKUP_STRUCT  STEPO_MOTOR_driver_backup = {0u};

    
/*******************************************************************************
* Function Name: STEPO_MOTOR_driver_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void STEPO_MOTOR_driver_SaveConfig(void) 
{
    STEPO_MOTOR_driver_backup.controlState = STEPO_MOTOR_driver_Control;
}


/*******************************************************************************
* Function Name: STEPO_MOTOR_driver_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void STEPO_MOTOR_driver_RestoreConfig(void) 
{
     STEPO_MOTOR_driver_Control = STEPO_MOTOR_driver_backup.controlState;
}


/*******************************************************************************
* Function Name: STEPO_MOTOR_driver_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void STEPO_MOTOR_driver_Sleep(void) 
{
    STEPO_MOTOR_driver_SaveConfig();
}


/*******************************************************************************
* Function Name: STEPO_MOTOR_driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void STEPO_MOTOR_driver_Wakeup(void)  
{
    STEPO_MOTOR_driver_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
