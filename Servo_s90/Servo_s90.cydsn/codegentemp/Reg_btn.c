/*******************************************************************************
* File Name: Reg_btn.c  
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

#include "Reg_btn.h"

#if !defined(Reg_btn_sts_intr_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Reg_btn_Read
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
uint8 Reg_btn_Read(void) 
{ 
    return Reg_btn_Status;
}


/*******************************************************************************
* Function Name: Reg_btn_InterruptEnable
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
void Reg_btn_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Reg_btn_Status_Aux_Ctrl |= Reg_btn_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Reg_btn_InterruptDisable
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
void Reg_btn_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Reg_btn_Status_Aux_Ctrl &= (uint8)(~Reg_btn_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Reg_btn_WriteMask
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
void Reg_btn_WriteMask(uint8 mask) 
{
    #if(Reg_btn_INPUTS < 8u)
    	mask &= ((uint8)(1u << Reg_btn_INPUTS) - 1u);
	#endif /* End Reg_btn_INPUTS < 8u */
    Reg_btn_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Reg_btn_ReadMask
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
uint8 Reg_btn_ReadMask(void) 
{
    return Reg_btn_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
