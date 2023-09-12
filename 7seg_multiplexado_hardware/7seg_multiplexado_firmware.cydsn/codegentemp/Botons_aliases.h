/*******************************************************************************
* File Name: Botons.h  
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

#if !defined(CY_PINS_Botons_ALIASES_H) /* Pins Botons_ALIASES_H */
#define CY_PINS_Botons_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Botons_0			(Botons__0__PC)
#define Botons_0_INTR	((uint16)((uint16)0x0001u << Botons__0__SHIFT))

#define Botons_1			(Botons__1__PC)
#define Botons_1_INTR	((uint16)((uint16)0x0001u << Botons__1__SHIFT))

#define Botons_INTR_ALL	 ((uint16)(Botons_0_INTR| Botons_1_INTR))

#endif /* End Pins Botons_ALIASES_H */


/* [] END OF FILE */
