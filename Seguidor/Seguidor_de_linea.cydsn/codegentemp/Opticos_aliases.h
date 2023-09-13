/*******************************************************************************
* File Name: Opticos.h  
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

#if !defined(CY_PINS_Opticos_ALIASES_H) /* Pins Opticos_ALIASES_H */
#define CY_PINS_Opticos_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Opticos_0			(Opticos__0__PC)
#define Opticos_0_INTR	((uint16)((uint16)0x0001u << Opticos__0__SHIFT))

#define Opticos_1			(Opticos__1__PC)
#define Opticos_1_INTR	((uint16)((uint16)0x0001u << Opticos__1__SHIFT))

#define Opticos_2			(Opticos__2__PC)
#define Opticos_2_INTR	((uint16)((uint16)0x0001u << Opticos__2__SHIFT))

#define Opticos_3			(Opticos__3__PC)
#define Opticos_3_INTR	((uint16)((uint16)0x0001u << Opticos__3__SHIFT))

#define Opticos_4			(Opticos__4__PC)
#define Opticos_4_INTR	((uint16)((uint16)0x0001u << Opticos__4__SHIFT))

#define Opticos_5			(Opticos__5__PC)
#define Opticos_5_INTR	((uint16)((uint16)0x0001u << Opticos__5__SHIFT))

#define Opticos_6			(Opticos__6__PC)
#define Opticos_6_INTR	((uint16)((uint16)0x0001u << Opticos__6__SHIFT))

#define Opticos_7			(Opticos__7__PC)
#define Opticos_7_INTR	((uint16)((uint16)0x0001u << Opticos__7__SHIFT))

#define Opticos_INTR_ALL	 ((uint16)(Opticos_0_INTR| Opticos_1_INTR| Opticos_2_INTR| Opticos_3_INTR| Opticos_4_INTR| Opticos_5_INTR| Opticos_6_INTR| Opticos_7_INTR))

#endif /* End Pins Opticos_ALIASES_H */


/* [] END OF FILE */
