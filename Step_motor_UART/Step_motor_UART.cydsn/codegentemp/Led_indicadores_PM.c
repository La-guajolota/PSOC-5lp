/*******************************************************************************
* File Name: Led_indicadores_PM.c
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

#include "Led_indicadores.h"

/* Check for removal by optimization */
#if !defined(Led_indicadores_Sync_ctrl_reg__REMOVED)

static Led_indicadores_BACKUP_STRUCT  Led_indicadores_backup = {0u};

    
/*******************************************************************************
* Function Name: Led_indicadores_SaveConfig
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
void Led_indicadores_SaveConfig(void) 
{
    Led_indicadores_backup.controlState = Led_indicadores_Control;
}


/*******************************************************************************
* Function Name: Led_indicadores_RestoreConfig
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
void Led_indicadores_RestoreConfig(void) 
{
     Led_indicadores_Control = Led_indicadores_backup.controlState;
}


/*******************************************************************************
* Function Name: Led_indicadores_Sleep
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
void Led_indicadores_Sleep(void) 
{
    Led_indicadores_SaveConfig();
}


/*******************************************************************************
* Function Name: Led_indicadores_Wakeup
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
void Led_indicadores_Wakeup(void)  
{
    Led_indicadores_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
