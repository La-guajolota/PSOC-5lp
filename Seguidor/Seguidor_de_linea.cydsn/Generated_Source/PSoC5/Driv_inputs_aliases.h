/*******************************************************************************
* File Name: Driv_inputs.h  
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

#if !defined(CY_PINS_Driv_inputs_ALIASES_H) /* Pins Driv_inputs_ALIASES_H */
#define CY_PINS_Driv_inputs_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Driv_inputs_0			(Driv_inputs__0__PC)
#define Driv_inputs_0_INTR	((uint16)((uint16)0x0001u << Driv_inputs__0__SHIFT))

#define Driv_inputs_1			(Driv_inputs__1__PC)
#define Driv_inputs_1_INTR	((uint16)((uint16)0x0001u << Driv_inputs__1__SHIFT))

#define Driv_inputs_2			(Driv_inputs__2__PC)
#define Driv_inputs_2_INTR	((uint16)((uint16)0x0001u << Driv_inputs__2__SHIFT))

#define Driv_inputs_3			(Driv_inputs__3__PC)
#define Driv_inputs_3_INTR	((uint16)((uint16)0x0001u << Driv_inputs__3__SHIFT))

#define Driv_inputs_4			(Driv_inputs__4__PC)
#define Driv_inputs_4_INTR	((uint16)((uint16)0x0001u << Driv_inputs__4__SHIFT))

#define Driv_inputs_5			(Driv_inputs__5__PC)
#define Driv_inputs_5_INTR	((uint16)((uint16)0x0001u << Driv_inputs__5__SHIFT))

#define Driv_inputs_INTR_ALL	 ((uint16)(Driv_inputs_0_INTR| Driv_inputs_1_INTR| Driv_inputs_2_INTR| Driv_inputs_3_INTR| Driv_inputs_4_INTR| Driv_inputs_5_INTR))

#endif /* End Pins Driv_inputs_ALIASES_H */


/* [] END OF FILE */
