/*******************************************************************************
* File Name: DISPARADORES_PM.c
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

#include "DISPARADORES.h"

/* Check for removal by optimization */
#if !defined(DISPARADORES_Sync_ctrl_reg__REMOVED)

static DISPARADORES_BACKUP_STRUCT  DISPARADORES_backup = {0u};

    
/*******************************************************************************
* Function Name: DISPARADORES_SaveConfig
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
void DISPARADORES_SaveConfig(void) 
{
    DISPARADORES_backup.controlState = DISPARADORES_Control;
}


/*******************************************************************************
* Function Name: DISPARADORES_RestoreConfig
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
void DISPARADORES_RestoreConfig(void) 
{
     DISPARADORES_Control = DISPARADORES_backup.controlState;
}


/*******************************************************************************
* Function Name: DISPARADORES_Sleep
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
void DISPARADORES_Sleep(void) 
{
    DISPARADORES_SaveConfig();
}


/*******************************************************************************
* Function Name: DISPARADORES_Wakeup
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
void DISPARADORES_Wakeup(void)  
{
    DISPARADORES_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
