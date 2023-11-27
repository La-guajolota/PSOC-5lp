/*******************************************************************************
* File Name: DIS_0.h
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
#if !defined(CY_ISR_DIS_0_H)
#define CY_ISR_DIS_0_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DIS_0_Start(void);
void DIS_0_StartEx(cyisraddress address);
void DIS_0_Stop(void);

CY_ISR_PROTO(DIS_0_Interrupt);

void DIS_0_SetVector(cyisraddress address);
cyisraddress DIS_0_GetVector(void);

void DIS_0_SetPriority(uint8 priority);
uint8 DIS_0_GetPriority(void);

void DIS_0_Enable(void);
uint8 DIS_0_GetState(void);
void DIS_0_Disable(void);

void DIS_0_SetPending(void);
void DIS_0_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DIS_0 ISR. */
#define DIS_0_INTC_VECTOR            ((reg32 *) DIS_0__INTC_VECT)

/* Address of the DIS_0 ISR priority. */
#define DIS_0_INTC_PRIOR             ((reg8 *) DIS_0__INTC_PRIOR_REG)

/* Priority of the DIS_0 interrupt. */
#define DIS_0_INTC_PRIOR_NUMBER      DIS_0__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DIS_0 interrupt. */
#define DIS_0_INTC_SET_EN            ((reg32 *) DIS_0__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DIS_0 interrupt. */
#define DIS_0_INTC_CLR_EN            ((reg32 *) DIS_0__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DIS_0 interrupt state to pending. */
#define DIS_0_INTC_SET_PD            ((reg32 *) DIS_0__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DIS_0 interrupt. */
#define DIS_0_INTC_CLR_PD            ((reg32 *) DIS_0__INTC_CLR_PD_REG)


#endif /* CY_ISR_DIS_0_H */


/* [] END OF FILE */
