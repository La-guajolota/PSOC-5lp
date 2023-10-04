/*******************************************************************************
* File Name: Botones.h  
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

#if !defined(CY_PINS_Botones_ALIASES_H) /* Pins Botones_ALIASES_H */
#define CY_PINS_Botones_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Botones_0			(Botones__0__PC)
#define Botones_0_INTR	((uint16)((uint16)0x0001u << Botones__0__SHIFT))

#define Botones_1			(Botones__1__PC)
#define Botones_1_INTR	((uint16)((uint16)0x0001u << Botones__1__SHIFT))

#define Botones_INTR_ALL	 ((uint16)(Botones_0_INTR| Botones_1_INTR))

#endif /* End Pins Botones_ALIASES_H */


/* [] END OF FILE */
