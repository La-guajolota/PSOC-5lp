/*******************************************************************************
* File Name: Toggle.h  
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

#if !defined(CY_PINS_Toggle_H) /* Pins Toggle_H */
#define CY_PINS_Toggle_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Toggle_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Toggle__PORT == 15 && ((Toggle__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Toggle_Write(uint8 value);
void    Toggle_SetDriveMode(uint8 mode);
uint8   Toggle_ReadDataReg(void);
uint8   Toggle_Read(void);
void    Toggle_SetInterruptMode(uint16 position, uint16 mode);
uint8   Toggle_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Toggle_SetDriveMode() function.
     *  @{
     */
        #define Toggle_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Toggle_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Toggle_DM_RES_UP          PIN_DM_RES_UP
        #define Toggle_DM_RES_DWN         PIN_DM_RES_DWN
        #define Toggle_DM_OD_LO           PIN_DM_OD_LO
        #define Toggle_DM_OD_HI           PIN_DM_OD_HI
        #define Toggle_DM_STRONG          PIN_DM_STRONG
        #define Toggle_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Toggle_MASK               Toggle__MASK
#define Toggle_SHIFT              Toggle__SHIFT
#define Toggle_WIDTH              1u

/* Interrupt constants */
#if defined(Toggle__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Toggle_SetInterruptMode() function.
     *  @{
     */
        #define Toggle_INTR_NONE      (uint16)(0x0000u)
        #define Toggle_INTR_RISING    (uint16)(0x0001u)
        #define Toggle_INTR_FALLING   (uint16)(0x0002u)
        #define Toggle_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Toggle_INTR_MASK      (0x01u) 
#endif /* (Toggle__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Toggle_PS                     (* (reg8 *) Toggle__PS)
/* Data Register */
#define Toggle_DR                     (* (reg8 *) Toggle__DR)
/* Port Number */
#define Toggle_PRT_NUM                (* (reg8 *) Toggle__PRT) 
/* Connect to Analog Globals */                                                  
#define Toggle_AG                     (* (reg8 *) Toggle__AG)                       
/* Analog MUX bux enable */
#define Toggle_AMUX                   (* (reg8 *) Toggle__AMUX) 
/* Bidirectional Enable */                                                        
#define Toggle_BIE                    (* (reg8 *) Toggle__BIE)
/* Bit-mask for Aliased Register Access */
#define Toggle_BIT_MASK               (* (reg8 *) Toggle__BIT_MASK)
/* Bypass Enable */
#define Toggle_BYP                    (* (reg8 *) Toggle__BYP)
/* Port wide control signals */                                                   
#define Toggle_CTL                    (* (reg8 *) Toggle__CTL)
/* Drive Modes */
#define Toggle_DM0                    (* (reg8 *) Toggle__DM0) 
#define Toggle_DM1                    (* (reg8 *) Toggle__DM1)
#define Toggle_DM2                    (* (reg8 *) Toggle__DM2) 
/* Input Buffer Disable Override */
#define Toggle_INP_DIS                (* (reg8 *) Toggle__INP_DIS)
/* LCD Common or Segment Drive */
#define Toggle_LCD_COM_SEG            (* (reg8 *) Toggle__LCD_COM_SEG)
/* Enable Segment LCD */
#define Toggle_LCD_EN                 (* (reg8 *) Toggle__LCD_EN)
/* Slew Rate Control */
#define Toggle_SLW                    (* (reg8 *) Toggle__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Toggle_PRTDSI__CAPS_SEL       (* (reg8 *) Toggle__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Toggle_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Toggle__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Toggle_PRTDSI__OE_SEL0        (* (reg8 *) Toggle__PRTDSI__OE_SEL0) 
#define Toggle_PRTDSI__OE_SEL1        (* (reg8 *) Toggle__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Toggle_PRTDSI__OUT_SEL0       (* (reg8 *) Toggle__PRTDSI__OUT_SEL0) 
#define Toggle_PRTDSI__OUT_SEL1       (* (reg8 *) Toggle__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Toggle_PRTDSI__SYNC_OUT       (* (reg8 *) Toggle__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Toggle__SIO_CFG)
    #define Toggle_SIO_HYST_EN        (* (reg8 *) Toggle__SIO_HYST_EN)
    #define Toggle_SIO_REG_HIFREQ     (* (reg8 *) Toggle__SIO_REG_HIFREQ)
    #define Toggle_SIO_CFG            (* (reg8 *) Toggle__SIO_CFG)
    #define Toggle_SIO_DIFF           (* (reg8 *) Toggle__SIO_DIFF)
#endif /* (Toggle__SIO_CFG) */

/* Interrupt Registers */
#if defined(Toggle__INTSTAT)
    #define Toggle_INTSTAT            (* (reg8 *) Toggle__INTSTAT)
    #define Toggle_SNAP               (* (reg8 *) Toggle__SNAP)
    
	#define Toggle_0_INTTYPE_REG 		(* (reg8 *) Toggle__0__INTTYPE)
#endif /* (Toggle__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Toggle_H */


/* [] END OF FILE */
