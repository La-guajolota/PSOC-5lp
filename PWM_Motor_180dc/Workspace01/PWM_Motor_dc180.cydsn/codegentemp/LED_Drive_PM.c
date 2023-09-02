/*******************************************************************************
* File Name: LED_Drive_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code to API for the
*  LED_Driver component.
*
* Note:
*  None
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "LED_Drive.h"
static LED_Drive_backupStruct LED_Drive_backup;


/*******************************************************************************
* Function Name: LED_Drive_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_Drive_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    LED_Drive_backup.ledEnableState = LED_Drive_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < LED_Drive_NUM_COM; i++)
    {
        LED_Drive_backup.segLBackup[i] = LED_Drive_segLBuffer[i];
        #if (LED_Drive_NUM_SEG > 8u) 
            LED_Drive_backup.segMBackup[i] = LED_Drive_segMBuffer[i];
        #endif /* (LED_Drive_NUM_SEG > 8u) */
        #if (LED_Drive_NUM_SEG > 16u) 
            LED_Drive_backup.segHBackup[i] = LED_Drive_segHBuffer[i];
        #endif /* (LED_Drive_NUM_SEG > 16u) */
    }
    
    LED_Drive_Stop();
}


/*******************************************************************************
* Function Name: LED_Drive_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_Drive_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < LED_Drive_NUM_COM; i++)
    {
        LED_Drive_segLBuffer[i] = LED_Drive_backup.segLBackup[i];
        #if (LED_Drive_NUM_SEG > 8u) 
            LED_Drive_segMBuffer[i] = LED_Drive_backup.segMBackup[i];
        #endif /* (LED_Drive_NUM_SEG > 8u) */
        #if (LED_Drive_NUM_SEG > 16u) 
            LED_Drive_segHBuffer[i] = LED_Drive_backup.segHBackup[i];
        #endif /* (LED_Drive_NUM_SEG > 16u) */
    }
    
    if(LED_Drive_backup.ledEnableState == LED_Drive_ENABLED)
    {
        /* Enable the component */
        LED_Drive_Enable();
    }
}


/* [] END OF FILE */

