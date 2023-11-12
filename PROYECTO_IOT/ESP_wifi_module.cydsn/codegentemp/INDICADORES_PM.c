/*******************************************************************************
* File Name: INDICADORES_PM.c
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

#include "INDICADORES.h"

/* Check for removal by optimization */
#if !defined(INDICADORES_Sync_ctrl_reg__REMOVED)

static INDICADORES_BACKUP_STRUCT  INDICADORES_backup = {0u};

    
/*******************************************************************************
* Function Name: INDICADORES_SaveConfig
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
void INDICADORES_SaveConfig(void) 
{
    INDICADORES_backup.controlState = INDICADORES_Control;
}


/*******************************************************************************
* Function Name: INDICADORES_RestoreConfig
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
void INDICADORES_RestoreConfig(void) 
{
     INDICADORES_Control = INDICADORES_backup.controlState;
}


/*******************************************************************************
* Function Name: INDICADORES_Sleep
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
void INDICADORES_Sleep(void) 
{
    INDICADORES_SaveConfig();
}


/*******************************************************************************
* Function Name: INDICADORES_Wakeup
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
void INDICADORES_Wakeup(void)  
{
    INDICADORES_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
