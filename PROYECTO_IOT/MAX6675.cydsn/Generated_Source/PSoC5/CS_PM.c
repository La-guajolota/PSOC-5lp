/*******************************************************************************
* File Name: CS_PM.c
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

#include "CS.h"

/* Check for removal by optimization */
#if !defined(CS_Sync_ctrl_reg__REMOVED)

static CS_BACKUP_STRUCT  CS_backup = {0u};

    
/*******************************************************************************
* Function Name: CS_SaveConfig
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
void CS_SaveConfig(void) 
{
    CS_backup.controlState = CS_Control;
}


/*******************************************************************************
* Function Name: CS_RestoreConfig
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
void CS_RestoreConfig(void) 
{
     CS_Control = CS_backup.controlState;
}


/*******************************************************************************
* Function Name: CS_Sleep
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
void CS_Sleep(void) 
{
    CS_SaveConfig();
}


/*******************************************************************************
* Function Name: CS_Wakeup
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
void CS_Wakeup(void)  
{
    CS_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
