/*******************************************************************************
* File Name: Linea_1.h  
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

#if !defined(CY_PINS_Linea_1_ALIASES_H) /* Pins Linea_1_ALIASES_H */
#define CY_PINS_Linea_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Linea_1_0			(Linea_1__0__PC)
#define Linea_1_0_INTR	((uint16)((uint16)0x0001u << Linea_1__0__SHIFT))

#define Linea_1_1			(Linea_1__1__PC)
#define Linea_1_1_INTR	((uint16)((uint16)0x0001u << Linea_1__1__SHIFT))

#define Linea_1_INTR_ALL	 ((uint16)(Linea_1_0_INTR| Linea_1_1_INTR))

#endif /* End Pins Linea_1_ALIASES_H */


/* [] END OF FILE */
