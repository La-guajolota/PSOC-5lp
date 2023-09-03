/*******************************************************************************
* File Name: Mas.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Mas_H) /* Pins Mas_H */
#define CY_PINS_Mas_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Mas_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Mas__PORT == 15 && ((Mas__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Mas_Write(uint8 value);
void    Mas_SetDriveMode(uint8 mode);
uint8   Mas_ReadDataReg(void);
uint8   Mas_Read(void);
void    Mas_SetInterruptMode(uint16 position, uint16 mode);
uint8   Mas_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Mas_SetDriveMode() function.
     *  @{
     */
        #define Mas_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Mas_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Mas_DM_RES_UP          PIN_DM_RES_UP
        #define Mas_DM_RES_DWN         PIN_DM_RES_DWN
        #define Mas_DM_OD_LO           PIN_DM_OD_LO
        #define Mas_DM_OD_HI           PIN_DM_OD_HI
        #define Mas_DM_STRONG          PIN_DM_STRONG
        #define Mas_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Mas_MASK               Mas__MASK
#define Mas_SHIFT              Mas__SHIFT
#define Mas_WIDTH              1u

/* Interrupt constants */
#if defined(Mas__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Mas_SetInterruptMode() function.
     *  @{
     */
        #define Mas_INTR_NONE      (uint16)(0x0000u)
        #define Mas_INTR_RISING    (uint16)(0x0001u)
        #define Mas_INTR_FALLING   (uint16)(0x0002u)
        #define Mas_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Mas_INTR_MASK      (0x01u) 
#endif /* (Mas__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Mas_PS                     (* (reg8 *) Mas__PS)
/* Data Register */
#define Mas_DR                     (* (reg8 *) Mas__DR)
/* Port Number */
#define Mas_PRT_NUM                (* (reg8 *) Mas__PRT) 
/* Connect to Analog Globals */                                                  
#define Mas_AG                     (* (reg8 *) Mas__AG)                       
/* Analog MUX bux enable */
#define Mas_AMUX                   (* (reg8 *) Mas__AMUX) 
/* Bidirectional Enable */                                                        
#define Mas_BIE                    (* (reg8 *) Mas__BIE)
/* Bit-mask for Aliased Register Access */
#define Mas_BIT_MASK               (* (reg8 *) Mas__BIT_MASK)
/* Bypass Enable */
#define Mas_BYP                    (* (reg8 *) Mas__BYP)
/* Port wide control signals */                                                   
#define Mas_CTL                    (* (reg8 *) Mas__CTL)
/* Drive Modes */
#define Mas_DM0                    (* (reg8 *) Mas__DM0) 
#define Mas_DM1                    (* (reg8 *) Mas__DM1)
#define Mas_DM2                    (* (reg8 *) Mas__DM2) 
/* Input Buffer Disable Override */
#define Mas_INP_DIS                (* (reg8 *) Mas__INP_DIS)
/* LCD Common or Segment Drive */
#define Mas_LCD_COM_SEG            (* (reg8 *) Mas__LCD_COM_SEG)
/* Enable Segment LCD */
#define Mas_LCD_EN                 (* (reg8 *) Mas__LCD_EN)
/* Slew Rate Control */
#define Mas_SLW                    (* (reg8 *) Mas__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Mas_PRTDSI__CAPS_SEL       (* (reg8 *) Mas__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Mas_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Mas__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Mas_PRTDSI__OE_SEL0        (* (reg8 *) Mas__PRTDSI__OE_SEL0) 
#define Mas_PRTDSI__OE_SEL1        (* (reg8 *) Mas__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Mas_PRTDSI__OUT_SEL0       (* (reg8 *) Mas__PRTDSI__OUT_SEL0) 
#define Mas_PRTDSI__OUT_SEL1       (* (reg8 *) Mas__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Mas_PRTDSI__SYNC_OUT       (* (reg8 *) Mas__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Mas__SIO_CFG)
    #define Mas_SIO_HYST_EN        (* (reg8 *) Mas__SIO_HYST_EN)
    #define Mas_SIO_REG_HIFREQ     (* (reg8 *) Mas__SIO_REG_HIFREQ)
    #define Mas_SIO_CFG            (* (reg8 *) Mas__SIO_CFG)
    #define Mas_SIO_DIFF           (* (reg8 *) Mas__SIO_DIFF)
#endif /* (Mas__SIO_CFG) */

/* Interrupt Registers */
#if defined(Mas__INTSTAT)
    #define Mas_INTSTAT            (* (reg8 *) Mas__INTSTAT)
    #define Mas_SNAP               (* (reg8 *) Mas__SNAP)
    
	#define Mas_0_INTTYPE_REG 		(* (reg8 *) Mas__0__INTTYPE)
#endif /* (Mas__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Mas_H */


/* [] END OF FILE */
