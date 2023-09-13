/*******************************************************************************
* File Name: L298N.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_L298N_ALIASES_H) /* Pins L298N_ALIASES_H */
#define CY_PINS_L298N_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define L298N_0			(L298N__0__PC)
#define L298N_0_INTR	((uint16)((uint16)0x0001u << L298N__0__SHIFT))

#define L298N_1			(L298N__1__PC)
#define L298N_1_INTR	((uint16)((uint16)0x0001u << L298N__1__SHIFT))

#define L298N_2			(L298N__2__PC)
#define L298N_2_INTR	((uint16)((uint16)0x0001u << L298N__2__SHIFT))

#define L298N_3			(L298N__3__PC)
#define L298N_3_INTR	((uint16)((uint16)0x0001u << L298N__3__SHIFT))

#define L298N_4			(L298N__4__PC)
#define L298N_4_INTR	((uint16)((uint16)0x0001u << L298N__4__SHIFT))

#define L298N_5			(L298N__5__PC)
#define L298N_5_INTR	((uint16)((uint16)0x0001u << L298N__5__SHIFT))

#define L298N_INTR_ALL	 ((uint16)(L298N_0_INTR| L298N_1_INTR| L298N_2_INTR| L298N_3_INTR| L298N_4_INTR| L298N_5_INTR))

#endif /* End Pins L298N_ALIASES_H */


/* [] END OF FILE */
