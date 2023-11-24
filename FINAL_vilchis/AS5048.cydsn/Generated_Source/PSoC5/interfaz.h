/*******************************************************************************
* File Name: interfaz.h
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
#if !defined(CY_ISR_interfaz_H)
#define CY_ISR_interfaz_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void interfaz_Start(void);
void interfaz_StartEx(cyisraddress address);
void interfaz_Stop(void);

CY_ISR_PROTO(interfaz_Interrupt);

void interfaz_SetVector(cyisraddress address);
cyisraddress interfaz_GetVector(void);

void interfaz_SetPriority(uint8 priority);
uint8 interfaz_GetPriority(void);

void interfaz_Enable(void);
uint8 interfaz_GetState(void);
void interfaz_Disable(void);

void interfaz_SetPending(void);
void interfaz_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the interfaz ISR. */
#define interfaz_INTC_VECTOR            ((reg32 *) interfaz__INTC_VECT)

/* Address of the interfaz ISR priority. */
#define interfaz_INTC_PRIOR             ((reg8 *) interfaz__INTC_PRIOR_REG)

/* Priority of the interfaz interrupt. */
#define interfaz_INTC_PRIOR_NUMBER      interfaz__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable interfaz interrupt. */
#define interfaz_INTC_SET_EN            ((reg32 *) interfaz__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the interfaz interrupt. */
#define interfaz_INTC_CLR_EN            ((reg32 *) interfaz__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the interfaz interrupt state to pending. */
#define interfaz_INTC_SET_PD            ((reg32 *) interfaz__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the interfaz interrupt. */
#define interfaz_INTC_CLR_PD            ((reg32 *) interfaz__INTC_CLR_PD_REG)


#endif /* CY_ISR_interfaz_H */


/* [] END OF FILE */
