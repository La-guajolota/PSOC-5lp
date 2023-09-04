/*******************************************************************************
* File Name: VEL_mas.h  
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

#if !defined(CY_PINS_VEL_mas_ALIASES_H) /* Pins VEL_mas_ALIASES_H */
#define CY_PINS_VEL_mas_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define VEL_mas_0			(VEL_mas__0__PC)
#define VEL_mas_0_INTR	((uint16)((uint16)0x0001u << VEL_mas__0__SHIFT))

#define VEL_mas_INTR_ALL	 ((uint16)(VEL_mas_0_INTR))

#endif /* End Pins VEL_mas_ALIASES_H */


/* [] END OF FILE */
