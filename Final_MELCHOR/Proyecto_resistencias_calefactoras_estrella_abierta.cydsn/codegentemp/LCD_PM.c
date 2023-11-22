/*******************************************************************************
* File Name: LCD_PM.c
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

#include "LCD.h"

/* Check for removal by optimization */
#if !defined(LCD_Sync_ctrl_reg__REMOVED)

static LCD_BACKUP_STRUCT  LCD_backup = {0u};

    
/*******************************************************************************
* Function Name: LCD_SaveConfig
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
void LCD_SaveConfig(void) 
{
    LCD_backup.controlState = LCD_Control;
}


/*******************************************************************************
* Function Name: LCD_RestoreConfig
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
void LCD_RestoreConfig(void) 
{
     LCD_Control = LCD_backup.controlState;
}


/*******************************************************************************
* Function Name: LCD_Sleep
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
void LCD_Sleep(void) 
{
    LCD_SaveConfig();
}


/*******************************************************************************
* Function Name: LCD_Wakeup
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
void LCD_Wakeup(void)  
{
    LCD_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
