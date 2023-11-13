/*******************************************************************************
* File Name: DIS_2.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_DIS_2_H)
#define CY_ISR_DIS_2_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DIS_2_Start(void);
void DIS_2_StartEx(cyisraddress address);
void DIS_2_Stop(void);

CY_ISR_PROTO(DIS_2_Interrupt);

void DIS_2_SetVector(cyisraddress address);
cyisraddress DIS_2_GetVector(void);

void DIS_2_SetPriority(uint8 priority);
uint8 DIS_2_GetPriority(void);

void DIS_2_Enable(void);
uint8 DIS_2_GetState(void);
void DIS_2_Disable(void);

void DIS_2_SetPending(void);
void DIS_2_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DIS_2 ISR. */
#define DIS_2_INTC_VECTOR            ((reg32 *) DIS_2__INTC_VECT)

/* Address of the DIS_2 ISR priority. */
#define DIS_2_INTC_PRIOR             ((reg8 *) DIS_2__INTC_PRIOR_REG)

/* Priority of the DIS_2 interrupt. */
#define DIS_2_INTC_PRIOR_NUMBER      DIS_2__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DIS_2 interrupt. */
#define DIS_2_INTC_SET_EN            ((reg32 *) DIS_2__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DIS_2 interrupt. */
#define DIS_2_INTC_CLR_EN            ((reg32 *) DIS_2__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DIS_2 interrupt state to pending. */
#define DIS_2_INTC_SET_PD            ((reg32 *) DIS_2__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DIS_2 interrupt. */
#define DIS_2_INTC_CLR_PD            ((reg32 *) DIS_2__INTC_CLR_PD_REG)


#endif /* CY_ISR_DIS_2_H */


/* [] END OF FILE */
