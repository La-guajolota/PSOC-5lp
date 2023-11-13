/*******************************************************************************
* File Name: DIS.h
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
#if !defined(CY_ISR_DIS_H)
#define CY_ISR_DIS_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DIS_Start(void);
void DIS_StartEx(cyisraddress address);
void DIS_Stop(void);

CY_ISR_PROTO(DIS_Interrupt);

void DIS_SetVector(cyisraddress address);
cyisraddress DIS_GetVector(void);

void DIS_SetPriority(uint8 priority);
uint8 DIS_GetPriority(void);

void DIS_Enable(void);
uint8 DIS_GetState(void);
void DIS_Disable(void);

void DIS_SetPending(void);
void DIS_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DIS ISR. */
#define DIS_INTC_VECTOR            ((reg32 *) DIS__INTC_VECT)

/* Address of the DIS ISR priority. */
#define DIS_INTC_PRIOR             ((reg8 *) DIS__INTC_PRIOR_REG)

/* Priority of the DIS interrupt. */
#define DIS_INTC_PRIOR_NUMBER      DIS__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DIS interrupt. */
#define DIS_INTC_SET_EN            ((reg32 *) DIS__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DIS interrupt. */
#define DIS_INTC_CLR_EN            ((reg32 *) DIS__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DIS interrupt state to pending. */
#define DIS_INTC_SET_PD            ((reg32 *) DIS__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DIS interrupt. */
#define DIS_INTC_CLR_PD            ((reg32 *) DIS__INTC_CLR_PD_REG)


#endif /* CY_ISR_DIS_H */


/* [] END OF FILE */
