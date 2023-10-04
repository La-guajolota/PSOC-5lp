/*******************************************************************************
* File Name: num_Unidades_Decenas_PM.c
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

#include "num_Unidades_Decenas.h"

/* Check for removal by optimization */
#if !defined(num_Unidades_Decenas_Sync_ctrl_reg__REMOVED)

static num_Unidades_Decenas_BACKUP_STRUCT  num_Unidades_Decenas_backup = {0u};

    
/*******************************************************************************
* Function Name: num_Unidades_Decenas_SaveConfig
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
void num_Unidades_Decenas_SaveConfig(void) 
{
    num_Unidades_Decenas_backup.controlState = num_Unidades_Decenas_Control;
}


/*******************************************************************************
* Function Name: num_Unidades_Decenas_RestoreConfig
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
void num_Unidades_Decenas_RestoreConfig(void) 
{
     num_Unidades_Decenas_Control = num_Unidades_Decenas_backup.controlState;
}


/*******************************************************************************
* Function Name: num_Unidades_Decenas_Sleep
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
void num_Unidades_Decenas_Sleep(void) 
{
    num_Unidades_Decenas_SaveConfig();
}


/*******************************************************************************
* Function Name: num_Unidades_Decenas_Wakeup
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
void num_Unidades_Decenas_Wakeup(void)  
{
    num_Unidades_Decenas_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
