/*******************************************************************************
* File Name: Seg.h  
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

#if !defined(CY_PINS_Seg_ALIASES_H) /* Pins Seg_ALIASES_H */
#define CY_PINS_Seg_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Seg_0			(Seg__0__PC)
#define Seg_0_INTR	((uint16)((uint16)0x0001u << Seg__0__SHIFT))

#define Seg_1			(Seg__1__PC)
#define Seg_1_INTR	((uint16)((uint16)0x0001u << Seg__1__SHIFT))

#define Seg_2			(Seg__2__PC)
#define Seg_2_INTR	((uint16)((uint16)0x0001u << Seg__2__SHIFT))

#define Seg_3			(Seg__3__PC)
#define Seg_3_INTR	((uint16)((uint16)0x0001u << Seg__3__SHIFT))

#define Seg_4			(Seg__4__PC)
#define Seg_4_INTR	((uint16)((uint16)0x0001u << Seg__4__SHIFT))

#define Seg_5			(Seg__5__PC)
#define Seg_5_INTR	((uint16)((uint16)0x0001u << Seg__5__SHIFT))

#define Seg_6			(Seg__6__PC)
#define Seg_6_INTR	((uint16)((uint16)0x0001u << Seg__6__SHIFT))

#define Seg_7			(Seg__7__PC)
#define Seg_7_INTR	((uint16)((uint16)0x0001u << Seg__7__SHIFT))

#define Seg_INTR_ALL	 ((uint16)(Seg_0_INTR| Seg_1_INTR| Seg_2_INTR| Seg_3_INTR| Seg_4_INTR| Seg_5_INTR| Seg_6_INTR| Seg_7_INTR))

#endif /* End Pins Seg_ALIASES_H */


/* [] END OF FILE */
