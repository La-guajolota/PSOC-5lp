/*******************************************************************************
* File Name: LED_Grados_PM.c
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

#include "LED_Grados.h"
static LED_Grados_backupStruct LED_Grados_backup;


/*******************************************************************************
* Function Name: LED_Grados_Sleep
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
void LED_Grados_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    LED_Grados_backup.ledEnableState = LED_Grados_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < LED_Grados_NUM_COM; i++)
    {
        LED_Grados_backup.segLBackup[i] = LED_Grados_segLBuffer[i];
        #if (LED_Grados_NUM_SEG > 8u) 
            LED_Grados_backup.segMBackup[i] = LED_Grados_segMBuffer[i];
        #endif /* (LED_Grados_NUM_SEG > 8u) */
        #if (LED_Grados_NUM_SEG > 16u) 
            LED_Grados_backup.segHBackup[i] = LED_Grados_segHBuffer[i];
        #endif /* (LED_Grados_NUM_SEG > 16u) */
    }
    
    LED_Grados_Stop();
}


/*******************************************************************************
* Function Name: LED_Grados_Wakeup
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
void LED_Grados_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < LED_Grados_NUM_COM; i++)
    {
        LED_Grados_segLBuffer[i] = LED_Grados_backup.segLBackup[i];
        #if (LED_Grados_NUM_SEG > 8u) 
            LED_Grados_segMBuffer[i] = LED_Grados_backup.segMBackup[i];
        #endif /* (LED_Grados_NUM_SEG > 8u) */
        #if (LED_Grados_NUM_SEG > 16u) 
            LED_Grados_segHBuffer[i] = LED_Grados_backup.segHBackup[i];
        #endif /* (LED_Grados_NUM_SEG > 16u) */
    }
    
    if(LED_Grados_backup.ledEnableState == LED_Grados_ENABLED)
    {
        /* Enable the component */
        LED_Grados_Enable();
    }
}


/* [] END OF FILE */

