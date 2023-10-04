/*******************************************************************************
* File Name: GREEN.h  
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

#if !defined(CY_PINS_GREEN_H) /* Pins GREEN_H */
#define CY_PINS_GREEN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GREEN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 GREEN__PORT == 15 && ((GREEN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    GREEN_Write(uint8 value);
void    GREEN_SetDriveMode(uint8 mode);
uint8   GREEN_ReadDataReg(void);
uint8   GREEN_Read(void);
void    GREEN_SetInterruptMode(uint16 position, uint16 mode);
uint8   GREEN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the GREEN_SetDriveMode() function.
     *  @{
     */
        #define GREEN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define GREEN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define GREEN_DM_RES_UP          PIN_DM_RES_UP
        #define GREEN_DM_RES_DWN         PIN_DM_RES_DWN
        #define GREEN_DM_OD_LO           PIN_DM_OD_LO
        #define GREEN_DM_OD_HI           PIN_DM_OD_HI
        #define GREEN_DM_STRONG          PIN_DM_STRONG
        #define GREEN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define GREEN_MASK               GREEN__MASK
#define GREEN_SHIFT              GREEN__SHIFT
#define GREEN_WIDTH              1u

/* Interrupt constants */
#if defined(GREEN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in GREEN_SetInterruptMode() function.
     *  @{
     */
        #define GREEN_INTR_NONE      (uint16)(0x0000u)
        #define GREEN_INTR_RISING    (uint16)(0x0001u)
        #define GREEN_INTR_FALLING   (uint16)(0x0002u)
        #define GREEN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define GREEN_INTR_MASK      (0x01u) 
#endif /* (GREEN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GREEN_PS                     (* (reg8 *) GREEN__PS)
/* Data Register */
#define GREEN_DR                     (* (reg8 *) GREEN__DR)
/* Port Number */
#define GREEN_PRT_NUM                (* (reg8 *) GREEN__PRT) 
/* Connect to Analog Globals */                                                  
#define GREEN_AG                     (* (reg8 *) GREEN__AG)                       
/* Analog MUX bux enable */
#define GREEN_AMUX                   (* (reg8 *) GREEN__AMUX) 
/* Bidirectional Enable */                                                        
#define GREEN_BIE                    (* (reg8 *) GREEN__BIE)
/* Bit-mask for Aliased Register Access */
#define GREEN_BIT_MASK               (* (reg8 *) GREEN__BIT_MASK)
/* Bypass Enable */
#define GREEN_BYP                    (* (reg8 *) GREEN__BYP)
/* Port wide control signals */                                                   
#define GREEN_CTL                    (* (reg8 *) GREEN__CTL)
/* Drive Modes */
#define GREEN_DM0                    (* (reg8 *) GREEN__DM0) 
#define GREEN_DM1                    (* (reg8 *) GREEN__DM1)
#define GREEN_DM2                    (* (reg8 *) GREEN__DM2) 
/* Input Buffer Disable Override */
#define GREEN_INP_DIS                (* (reg8 *) GREEN__INP_DIS)
/* LCD Common or Segment Drive */
#define GREEN_LCD_COM_SEG            (* (reg8 *) GREEN__LCD_COM_SEG)
/* Enable Segment LCD */
#define GREEN_LCD_EN                 (* (reg8 *) GREEN__LCD_EN)
/* Slew Rate Control */
#define GREEN_SLW                    (* (reg8 *) GREEN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GREEN_PRTDSI__CAPS_SEL       (* (reg8 *) GREEN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GREEN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GREEN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GREEN_PRTDSI__OE_SEL0        (* (reg8 *) GREEN__PRTDSI__OE_SEL0) 
#define GREEN_PRTDSI__OE_SEL1        (* (reg8 *) GREEN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GREEN_PRTDSI__OUT_SEL0       (* (reg8 *) GREEN__PRTDSI__OUT_SEL0) 
#define GREEN_PRTDSI__OUT_SEL1       (* (reg8 *) GREEN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GREEN_PRTDSI__SYNC_OUT       (* (reg8 *) GREEN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(GREEN__SIO_CFG)
    #define GREEN_SIO_HYST_EN        (* (reg8 *) GREEN__SIO_HYST_EN)
    #define GREEN_SIO_REG_HIFREQ     (* (reg8 *) GREEN__SIO_REG_HIFREQ)
    #define GREEN_SIO_CFG            (* (reg8 *) GREEN__SIO_CFG)
    #define GREEN_SIO_DIFF           (* (reg8 *) GREEN__SIO_DIFF)
#endif /* (GREEN__SIO_CFG) */

/* Interrupt Registers */
#if defined(GREEN__INTSTAT)
    #define GREEN_INTSTAT            (* (reg8 *) GREEN__INTSTAT)
    #define GREEN_SNAP               (* (reg8 *) GREEN__SNAP)
    
	#define GREEN_0_INTTYPE_REG 		(* (reg8 *) GREEN__0__INTTYPE)
#endif /* (GREEN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_GREEN_H */


/* [] END OF FILE */
