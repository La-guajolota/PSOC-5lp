/*******************************************************************************
* File Name: Linea_3.h  
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

#if !defined(CY_PINS_Linea_3_ALIASES_H) /* Pins Linea_3_ALIASES_H */
#define CY_PINS_Linea_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Linea_3_0			(Linea_3__0__PC)
#define Linea_3_0_INTR	((uint16)((uint16)0x0001u << Linea_3__0__SHIFT))

#define Linea_3_1			(Linea_3__1__PC)
#define Linea_3_1_INTR	((uint16)((uint16)0x0001u << Linea_3__1__SHIFT))

#define Linea_3_INTR_ALL	 ((uint16)(Linea_3_0_INTR| Linea_3_1_INTR))

#endif /* End Pins Linea_3_ALIASES_H */


/* [] END OF FILE */
