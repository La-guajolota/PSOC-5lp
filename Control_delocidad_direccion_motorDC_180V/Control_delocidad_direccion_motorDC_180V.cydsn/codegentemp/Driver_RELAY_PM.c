/*******************************************************************************
* File Name: Driver_RELAY_PM.c
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

#include "Driver_RELAY.h"

/* Check for removal by optimization */
#if !defined(Driver_RELAY_Sync_ctrl_reg__REMOVED)

static Driver_RELAY_BACKUP_STRUCT  Driver_RELAY_backup = {0u};

    
/*******************************************************************************
* Function Name: Driver_RELAY_SaveConfig
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
void Driver_RELAY_SaveConfig(void) 
{
    Driver_RELAY_backup.controlState = Driver_RELAY_Control;
}


/*******************************************************************************
* Function Name: Driver_RELAY_RestoreConfig
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
void Driver_RELAY_RestoreConfig(void) 
{
     Driver_RELAY_Control = Driver_RELAY_backup.controlState;
}


/*******************************************************************************
* Function Name: Driver_RELAY_Sleep
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
void Driver_RELAY_Sleep(void) 
{
    Driver_RELAY_SaveConfig();
}


/*******************************************************************************
* Function Name: Driver_RELAY_Wakeup
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
void Driver_RELAY_Wakeup(void)  
{
    Driver_RELAY_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
