/*******************************************************************************
* File Name: wifi.h
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
#if !defined(CY_ISR_wifi_H)
#define CY_ISR_wifi_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void wifi_Start(void);
void wifi_StartEx(cyisraddress address);
void wifi_Stop(void);

CY_ISR_PROTO(wifi_Interrupt);

void wifi_SetVector(cyisraddress address);
cyisraddress wifi_GetVector(void);

void wifi_SetPriority(uint8 priority);
uint8 wifi_GetPriority(void);

void wifi_Enable(void);
uint8 wifi_GetState(void);
void wifi_Disable(void);

void wifi_SetPending(void);
void wifi_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the wifi ISR. */
#define wifi_INTC_VECTOR            ((reg32 *) wifi__INTC_VECT)

/* Address of the wifi ISR priority. */
#define wifi_INTC_PRIOR             ((reg8 *) wifi__INTC_PRIOR_REG)

/* Priority of the wifi interrupt. */
#define wifi_INTC_PRIOR_NUMBER      wifi__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable wifi interrupt. */
#define wifi_INTC_SET_EN            ((reg32 *) wifi__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the wifi interrupt. */
#define wifi_INTC_CLR_EN            ((reg32 *) wifi__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the wifi interrupt state to pending. */
#define wifi_INTC_SET_PD            ((reg32 *) wifi__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the wifi interrupt. */
#define wifi_INTC_CLR_PD            ((reg32 *) wifi__INTC_CLR_PD_REG)


#endif /* CY_ISR_wifi_H */


/* [] END OF FILE */
