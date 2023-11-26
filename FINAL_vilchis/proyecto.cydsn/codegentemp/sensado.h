/*******************************************************************************
* File Name: sensado.h
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
#if !defined(CY_ISR_sensado_H)
#define CY_ISR_sensado_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void sensado_Start(void);
void sensado_StartEx(cyisraddress address);
void sensado_Stop(void);

CY_ISR_PROTO(sensado_Interrupt);

void sensado_SetVector(cyisraddress address);
cyisraddress sensado_GetVector(void);

void sensado_SetPriority(uint8 priority);
uint8 sensado_GetPriority(void);

void sensado_Enable(void);
uint8 sensado_GetState(void);
void sensado_Disable(void);

void sensado_SetPending(void);
void sensado_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the sensado ISR. */
#define sensado_INTC_VECTOR            ((reg32 *) sensado__INTC_VECT)

/* Address of the sensado ISR priority. */
#define sensado_INTC_PRIOR             ((reg8 *) sensado__INTC_PRIOR_REG)

/* Priority of the sensado interrupt. */
#define sensado_INTC_PRIOR_NUMBER      sensado__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable sensado interrupt. */
#define sensado_INTC_SET_EN            ((reg32 *) sensado__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the sensado interrupt. */
#define sensado_INTC_CLR_EN            ((reg32 *) sensado__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the sensado interrupt state to pending. */
#define sensado_INTC_SET_PD            ((reg32 *) sensado__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the sensado interrupt. */
#define sensado_INTC_CLR_PD            ((reg32 *) sensado__INTC_CLR_PD_REG)


#endif /* CY_ISR_sensado_H */


/* [] END OF FILE */
