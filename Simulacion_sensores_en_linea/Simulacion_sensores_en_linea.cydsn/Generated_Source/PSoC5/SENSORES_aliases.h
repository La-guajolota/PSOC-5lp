/*******************************************************************************
* File Name: SENSORES.h  
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

#if !defined(CY_PINS_SENSORES_ALIASES_H) /* Pins SENSORES_ALIASES_H */
#define CY_PINS_SENSORES_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define SENSORES_0			(SENSORES__0__PC)
#define SENSORES_0_INTR	((uint16)((uint16)0x0001u << SENSORES__0__SHIFT))

#define SENSORES_1			(SENSORES__1__PC)
#define SENSORES_1_INTR	((uint16)((uint16)0x0001u << SENSORES__1__SHIFT))

#define SENSORES_2			(SENSORES__2__PC)
#define SENSORES_2_INTR	((uint16)((uint16)0x0001u << SENSORES__2__SHIFT))

#define SENSORES_3			(SENSORES__3__PC)
#define SENSORES_3_INTR	((uint16)((uint16)0x0001u << SENSORES__3__SHIFT))

#define SENSORES_INTR_ALL	 ((uint16)(SENSORES_0_INTR| SENSORES_1_INTR| SENSORES_2_INTR| SENSORES_3_INTR))

#endif /* End Pins SENSORES_ALIASES_H */


/* [] END OF FILE */
