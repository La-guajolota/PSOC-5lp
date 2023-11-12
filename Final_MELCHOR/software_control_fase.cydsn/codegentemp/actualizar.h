/*******************************************************************************
* File Name: actualizar.h
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
#if !defined(CY_ISR_actualizar_H)
#define CY_ISR_actualizar_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void actualizar_Start(void);
void actualizar_StartEx(cyisraddress address);
void actualizar_Stop(void);

CY_ISR_PROTO(actualizar_Interrupt);

void actualizar_SetVector(cyisraddress address);
cyisraddress actualizar_GetVector(void);

void actualizar_SetPriority(uint8 priority);
uint8 actualizar_GetPriority(void);

void actualizar_Enable(void);
uint8 actualizar_GetState(void);
void actualizar_Disable(void);

void actualizar_SetPending(void);
void actualizar_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the actualizar ISR. */
#define actualizar_INTC_VECTOR            ((reg32 *) actualizar__INTC_VECT)

/* Address of the actualizar ISR priority. */
#define actualizar_INTC_PRIOR             ((reg8 *) actualizar__INTC_PRIOR_REG)

/* Priority of the actualizar interrupt. */
#define actualizar_INTC_PRIOR_NUMBER      actualizar__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable actualizar interrupt. */
#define actualizar_INTC_SET_EN            ((reg32 *) actualizar__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the actualizar interrupt. */
#define actualizar_INTC_CLR_EN            ((reg32 *) actualizar__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the actualizar interrupt state to pending. */
#define actualizar_INTC_SET_PD            ((reg32 *) actualizar__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the actualizar interrupt. */
#define actualizar_INTC_CLR_PD            ((reg32 *) actualizar__INTC_CLR_PD_REG)


#endif /* CY_ISR_actualizar_H */


/* [] END OF FILE */
