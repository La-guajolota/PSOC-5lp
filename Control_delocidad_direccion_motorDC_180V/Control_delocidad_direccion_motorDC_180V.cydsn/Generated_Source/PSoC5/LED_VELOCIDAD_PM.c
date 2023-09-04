/*******************************************************************************
* File Name: LED_VELOCIDAD_PM.c
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

#include "LED_VELOCIDAD.h"
static LED_VELOCIDAD_backupStruct LED_VELOCIDAD_backup;


/*******************************************************************************
* Function Name: LED_VELOCIDAD_Sleep
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
void LED_VELOCIDAD_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    LED_VELOCIDAD_backup.ledEnableState = LED_VELOCIDAD_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < LED_VELOCIDAD_NUM_COM; i++)
    {
        LED_VELOCIDAD_backup.segLBackup[i] = LED_VELOCIDAD_segLBuffer[i];
        #if (LED_VELOCIDAD_NUM_SEG > 8u) 
            LED_VELOCIDAD_backup.segMBackup[i] = LED_VELOCIDAD_segMBuffer[i];
        #endif /* (LED_VELOCIDAD_NUM_SEG > 8u) */
        #if (LED_VELOCIDAD_NUM_SEG > 16u) 
            LED_VELOCIDAD_backup.segHBackup[i] = LED_VELOCIDAD_segHBuffer[i];
        #endif /* (LED_VELOCIDAD_NUM_SEG > 16u) */
    }
    
    LED_VELOCIDAD_Stop();
}


/*******************************************************************************
* Function Name: LED_VELOCIDAD_Wakeup
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
void LED_VELOCIDAD_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < LED_VELOCIDAD_NUM_COM; i++)
    {
        LED_VELOCIDAD_segLBuffer[i] = LED_VELOCIDAD_backup.segLBackup[i];
        #if (LED_VELOCIDAD_NUM_SEG > 8u) 
            LED_VELOCIDAD_segMBuffer[i] = LED_VELOCIDAD_backup.segMBackup[i];
        #endif /* (LED_VELOCIDAD_NUM_SEG > 8u) */
        #if (LED_VELOCIDAD_NUM_SEG > 16u) 
            LED_VELOCIDAD_segHBuffer[i] = LED_VELOCIDAD_backup.segHBackup[i];
        #endif /* (LED_VELOCIDAD_NUM_SEG > 16u) */
    }
    
    if(LED_VELOCIDAD_backup.ledEnableState == LED_VELOCIDAD_ENABLED)
    {
        /* Enable the component */
        LED_VELOCIDAD_Enable();
    }
}


/* [] END OF FILE */

