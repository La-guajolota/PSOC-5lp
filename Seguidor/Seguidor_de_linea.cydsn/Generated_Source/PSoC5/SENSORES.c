/*******************************************************************************
* File Name: SENSORES.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SENSORES.h"

#if !defined(SENSORES_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: SENSORES_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 SENSORES_Read(void) 
{ 
    return SENSORES_Status;
}


/*******************************************************************************
* Function Name: SENSORES_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SENSORES_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SENSORES_Status_Aux_Ctrl |= SENSORES_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SENSORES_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SENSORES_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SENSORES_Status_Aux_Ctrl &= (uint8)(~SENSORES_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SENSORES_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void SENSORES_WriteMask(uint8 mask) 
{
    #if(SENSORES_INPUTS < 8u)
    	mask &= ((uint8)(1u << SENSORES_INPUTS) - 1u);
	#endif /* End SENSORES_INPUTS < 8u */
    SENSORES_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: SENSORES_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 SENSORES_ReadMask(void) 
{
    return SENSORES_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
