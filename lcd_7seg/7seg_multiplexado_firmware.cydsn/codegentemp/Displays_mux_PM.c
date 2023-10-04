/*******************************************************************************
* File Name: Displays_mux_PM.c
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

#include "Displays_mux.h"

/* Check for removal by optimization */
#if !defined(Displays_mux_Sync_ctrl_reg__REMOVED)

static Displays_mux_BACKUP_STRUCT  Displays_mux_backup = {0u};

    
/*******************************************************************************
* Function Name: Displays_mux_SaveConfig
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
void Displays_mux_SaveConfig(void) 
{
    Displays_mux_backup.controlState = Displays_mux_Control;
}


/*******************************************************************************
* Function Name: Displays_mux_RestoreConfig
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
void Displays_mux_RestoreConfig(void) 
{
     Displays_mux_Control = Displays_mux_backup.controlState;
}


/*******************************************************************************
* Function Name: Displays_mux_Sleep
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
void Displays_mux_Sleep(void) 
{
    Displays_mux_SaveConfig();
}


/*******************************************************************************
* Function Name: Displays_mux_Wakeup
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
void Displays_mux_Wakeup(void)  
{
    Displays_mux_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
