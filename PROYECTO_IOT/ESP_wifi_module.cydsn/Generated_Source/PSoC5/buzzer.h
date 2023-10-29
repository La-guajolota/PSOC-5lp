/*******************************************************************************
* File Name: buzzer.h  
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

#if !defined(CY_PINS_buzzer_H) /* Pins buzzer_H */
#define CY_PINS_buzzer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "buzzer_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 buzzer__PORT == 15 && ((buzzer__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    buzzer_Write(uint8 value);
void    buzzer_SetDriveMode(uint8 mode);
uint8   buzzer_ReadDataReg(void);
uint8   buzzer_Read(void);
void    buzzer_SetInterruptMode(uint16 position, uint16 mode);
uint8   buzzer_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the buzzer_SetDriveMode() function.
     *  @{
     */
        #define buzzer_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define buzzer_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define buzzer_DM_RES_UP          PIN_DM_RES_UP
        #define buzzer_DM_RES_DWN         PIN_DM_RES_DWN
        #define buzzer_DM_OD_LO           PIN_DM_OD_LO
        #define buzzer_DM_OD_HI           PIN_DM_OD_HI
        #define buzzer_DM_STRONG          PIN_DM_STRONG
        #define buzzer_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define buzzer_MASK               buzzer__MASK
#define buzzer_SHIFT              buzzer__SHIFT
#define buzzer_WIDTH              1u

/* Interrupt constants */
#if defined(buzzer__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in buzzer_SetInterruptMode() function.
     *  @{
     */
        #define buzzer_INTR_NONE      (uint16)(0x0000u)
        #define buzzer_INTR_RISING    (uint16)(0x0001u)
        #define buzzer_INTR_FALLING   (uint16)(0x0002u)
        #define buzzer_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define buzzer_INTR_MASK      (0x01u) 
#endif /* (buzzer__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define buzzer_PS                     (* (reg8 *) buzzer__PS)
/* Data Register */
#define buzzer_DR                     (* (reg8 *) buzzer__DR)
/* Port Number */
#define buzzer_PRT_NUM                (* (reg8 *) buzzer__PRT) 
/* Connect to Analog Globals */                                                  
#define buzzer_AG                     (* (reg8 *) buzzer__AG)                       
/* Analog MUX bux enable */
#define buzzer_AMUX                   (* (reg8 *) buzzer__AMUX) 
/* Bidirectional Enable */                                                        
#define buzzer_BIE                    (* (reg8 *) buzzer__BIE)
/* Bit-mask for Aliased Register Access */
#define buzzer_BIT_MASK               (* (reg8 *) buzzer__BIT_MASK)
/* Bypass Enable */
#define buzzer_BYP                    (* (reg8 *) buzzer__BYP)
/* Port wide control signals */                                                   
#define buzzer_CTL                    (* (reg8 *) buzzer__CTL)
/* Drive Modes */
#define buzzer_DM0                    (* (reg8 *) buzzer__DM0) 
#define buzzer_DM1                    (* (reg8 *) buzzer__DM1)
#define buzzer_DM2                    (* (reg8 *) buzzer__DM2) 
/* Input Buffer Disable Override */
#define buzzer_INP_DIS                (* (reg8 *) buzzer__INP_DIS)
/* LCD Common or Segment Drive */
#define buzzer_LCD_COM_SEG            (* (reg8 *) buzzer__LCD_COM_SEG)
/* Enable Segment LCD */
#define buzzer_LCD_EN                 (* (reg8 *) buzzer__LCD_EN)
/* Slew Rate Control */
#define buzzer_SLW                    (* (reg8 *) buzzer__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define buzzer_PRTDSI__CAPS_SEL       (* (reg8 *) buzzer__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define buzzer_PRTDSI__DBL_SYNC_IN    (* (reg8 *) buzzer__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define buzzer_PRTDSI__OE_SEL0        (* (reg8 *) buzzer__PRTDSI__OE_SEL0) 
#define buzzer_PRTDSI__OE_SEL1        (* (reg8 *) buzzer__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define buzzer_PRTDSI__OUT_SEL0       (* (reg8 *) buzzer__PRTDSI__OUT_SEL0) 
#define buzzer_PRTDSI__OUT_SEL1       (* (reg8 *) buzzer__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define buzzer_PRTDSI__SYNC_OUT       (* (reg8 *) buzzer__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(buzzer__SIO_CFG)
    #define buzzer_SIO_HYST_EN        (* (reg8 *) buzzer__SIO_HYST_EN)
    #define buzzer_SIO_REG_HIFREQ     (* (reg8 *) buzzer__SIO_REG_HIFREQ)
    #define buzzer_SIO_CFG            (* (reg8 *) buzzer__SIO_CFG)
    #define buzzer_SIO_DIFF           (* (reg8 *) buzzer__SIO_DIFF)
#endif /* (buzzer__SIO_CFG) */

/* Interrupt Registers */
#if defined(buzzer__INTSTAT)
    #define buzzer_INTSTAT            (* (reg8 *) buzzer__INTSTAT)
    #define buzzer_SNAP               (* (reg8 *) buzzer__SNAP)
    
	#define buzzer_0_INTTYPE_REG 		(* (reg8 *) buzzer__0__INTTYPE)
#endif /* (buzzer__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_buzzer_H */


/* [] END OF FILE */
