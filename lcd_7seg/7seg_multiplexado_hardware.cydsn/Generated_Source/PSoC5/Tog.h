/*******************************************************************************
* File Name: Tog.h  
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

#if !defined(CY_PINS_Tog_H) /* Pins Tog_H */
#define CY_PINS_Tog_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Tog_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Tog__PORT == 15 && ((Tog__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Tog_Write(uint8 value);
void    Tog_SetDriveMode(uint8 mode);
uint8   Tog_ReadDataReg(void);
uint8   Tog_Read(void);
void    Tog_SetInterruptMode(uint16 position, uint16 mode);
uint8   Tog_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Tog_SetDriveMode() function.
     *  @{
     */
        #define Tog_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Tog_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Tog_DM_RES_UP          PIN_DM_RES_UP
        #define Tog_DM_RES_DWN         PIN_DM_RES_DWN
        #define Tog_DM_OD_LO           PIN_DM_OD_LO
        #define Tog_DM_OD_HI           PIN_DM_OD_HI
        #define Tog_DM_STRONG          PIN_DM_STRONG
        #define Tog_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Tog_MASK               Tog__MASK
#define Tog_SHIFT              Tog__SHIFT
#define Tog_WIDTH              1u

/* Interrupt constants */
#if defined(Tog__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Tog_SetInterruptMode() function.
     *  @{
     */
        #define Tog_INTR_NONE      (uint16)(0x0000u)
        #define Tog_INTR_RISING    (uint16)(0x0001u)
        #define Tog_INTR_FALLING   (uint16)(0x0002u)
        #define Tog_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Tog_INTR_MASK      (0x01u) 
#endif /* (Tog__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Tog_PS                     (* (reg8 *) Tog__PS)
/* Data Register */
#define Tog_DR                     (* (reg8 *) Tog__DR)
/* Port Number */
#define Tog_PRT_NUM                (* (reg8 *) Tog__PRT) 
/* Connect to Analog Globals */                                                  
#define Tog_AG                     (* (reg8 *) Tog__AG)                       
/* Analog MUX bux enable */
#define Tog_AMUX                   (* (reg8 *) Tog__AMUX) 
/* Bidirectional Enable */                                                        
#define Tog_BIE                    (* (reg8 *) Tog__BIE)
/* Bit-mask for Aliased Register Access */
#define Tog_BIT_MASK               (* (reg8 *) Tog__BIT_MASK)
/* Bypass Enable */
#define Tog_BYP                    (* (reg8 *) Tog__BYP)
/* Port wide control signals */                                                   
#define Tog_CTL                    (* (reg8 *) Tog__CTL)
/* Drive Modes */
#define Tog_DM0                    (* (reg8 *) Tog__DM0) 
#define Tog_DM1                    (* (reg8 *) Tog__DM1)
#define Tog_DM2                    (* (reg8 *) Tog__DM2) 
/* Input Buffer Disable Override */
#define Tog_INP_DIS                (* (reg8 *) Tog__INP_DIS)
/* LCD Common or Segment Drive */
#define Tog_LCD_COM_SEG            (* (reg8 *) Tog__LCD_COM_SEG)
/* Enable Segment LCD */
#define Tog_LCD_EN                 (* (reg8 *) Tog__LCD_EN)
/* Slew Rate Control */
#define Tog_SLW                    (* (reg8 *) Tog__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Tog_PRTDSI__CAPS_SEL       (* (reg8 *) Tog__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Tog_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Tog__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Tog_PRTDSI__OE_SEL0        (* (reg8 *) Tog__PRTDSI__OE_SEL0) 
#define Tog_PRTDSI__OE_SEL1        (* (reg8 *) Tog__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Tog_PRTDSI__OUT_SEL0       (* (reg8 *) Tog__PRTDSI__OUT_SEL0) 
#define Tog_PRTDSI__OUT_SEL1       (* (reg8 *) Tog__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Tog_PRTDSI__SYNC_OUT       (* (reg8 *) Tog__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Tog__SIO_CFG)
    #define Tog_SIO_HYST_EN        (* (reg8 *) Tog__SIO_HYST_EN)
    #define Tog_SIO_REG_HIFREQ     (* (reg8 *) Tog__SIO_REG_HIFREQ)
    #define Tog_SIO_CFG            (* (reg8 *) Tog__SIO_CFG)
    #define Tog_SIO_DIFF           (* (reg8 *) Tog__SIO_DIFF)
#endif /* (Tog__SIO_CFG) */

/* Interrupt Registers */
#if defined(Tog__INTSTAT)
    #define Tog_INTSTAT            (* (reg8 *) Tog__INTSTAT)
    #define Tog_SNAP               (* (reg8 *) Tog__SNAP)
    
	#define Tog_0_INTTYPE_REG 		(* (reg8 *) Tog__0__INTTYPE)
#endif /* (Tog__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Tog_H */


/* [] END OF FILE */
