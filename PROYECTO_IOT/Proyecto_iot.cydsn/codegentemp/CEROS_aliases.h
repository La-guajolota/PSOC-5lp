/*******************************************************************************
* File Name: CEROS.h  
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

#if !defined(CY_PINS_CEROS_ALIASES_H) /* Pins CEROS_ALIASES_H */
#define CY_PINS_CEROS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define CEROS_0			(CEROS__0__PC)
#define CEROS_0_INTR	((uint16)((uint16)0x0001u << CEROS__0__SHIFT))

#define CEROS_INTR_ALL	 ((uint16)(CEROS_0_INTR))

#endif /* End Pins CEROS_ALIASES_H */


/* [] END OF FILE */
