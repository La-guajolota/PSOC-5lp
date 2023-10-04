/*******************************************************************************
* File Name: num_Centenas_MIllar_PM.c
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

#include "num_Centenas_MIllar.h"

/* Check for removal by optimization */
#if !defined(num_Centenas_MIllar_Sync_ctrl_reg__REMOVED)

static num_Centenas_MIllar_BACKUP_STRUCT  num_Centenas_MIllar_backup = {0u};

    
/*******************************************************************************
* Function Name: num_Centenas_MIllar_SaveConfig
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
void num_Centenas_MIllar_SaveConfig(void) 
{
    num_Centenas_MIllar_backup.controlState = num_Centenas_MIllar_Control;
}


/*******************************************************************************
* Function Name: num_Centenas_MIllar_RestoreConfig
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
void num_Centenas_MIllar_RestoreConfig(void) 
{
     num_Centenas_MIllar_Control = num_Centenas_MIllar_backup.controlState;
}


/*******************************************************************************
* Function Name: num_Centenas_MIllar_Sleep
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
void num_Centenas_MIllar_Sleep(void) 
{
    num_Centenas_MIllar_SaveConfig();
}


/*******************************************************************************
* Function Name: num_Centenas_MIllar_Wakeup
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
void num_Centenas_MIllar_Wakeup(void)  
{
    num_Centenas_MIllar_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
