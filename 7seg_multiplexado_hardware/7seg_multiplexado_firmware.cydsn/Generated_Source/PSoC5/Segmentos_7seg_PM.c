/*******************************************************************************
* File Name: Segmentos_7seg_PM.c
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

#include "Segmentos_7seg.h"

/* Check for removal by optimization */
#if !defined(Segmentos_7seg_Sync_ctrl_reg__REMOVED)

static Segmentos_7seg_BACKUP_STRUCT  Segmentos_7seg_backup = {0u};

    
/*******************************************************************************
* Function Name: Segmentos_7seg_SaveConfig
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
void Segmentos_7seg_SaveConfig(void) 
{
    Segmentos_7seg_backup.controlState = Segmentos_7seg_Control;
}


/*******************************************************************************
* Function Name: Segmentos_7seg_RestoreConfig
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
void Segmentos_7seg_RestoreConfig(void) 
{
     Segmentos_7seg_Control = Segmentos_7seg_backup.controlState;
}


/*******************************************************************************
* Function Name: Segmentos_7seg_Sleep
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
void Segmentos_7seg_Sleep(void) 
{
    Segmentos_7seg_SaveConfig();
}


/*******************************************************************************
* Function Name: Segmentos_7seg_Wakeup
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
void Segmentos_7seg_Wakeup(void)  
{
    Segmentos_7seg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
