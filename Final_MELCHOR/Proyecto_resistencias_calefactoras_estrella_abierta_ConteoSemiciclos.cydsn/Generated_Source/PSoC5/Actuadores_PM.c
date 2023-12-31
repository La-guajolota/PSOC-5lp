/*******************************************************************************
* File Name: Actuadores_PM.c
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

#include "Actuadores.h"

/* Check for removal by optimization */
#if !defined(Actuadores_Sync_ctrl_reg__REMOVED)

static Actuadores_BACKUP_STRUCT  Actuadores_backup = {0u};

    
/*******************************************************************************
* Function Name: Actuadores_SaveConfig
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
void Actuadores_SaveConfig(void) 
{
    Actuadores_backup.controlState = Actuadores_Control;
}


/*******************************************************************************
* Function Name: Actuadores_RestoreConfig
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
void Actuadores_RestoreConfig(void) 
{
     Actuadores_Control = Actuadores_backup.controlState;
}


/*******************************************************************************
* Function Name: Actuadores_Sleep
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
void Actuadores_Sleep(void) 
{
    Actuadores_SaveConfig();
}


/*******************************************************************************
* Function Name: Actuadores_Wakeup
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
void Actuadores_Wakeup(void)  
{
    Actuadores_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
