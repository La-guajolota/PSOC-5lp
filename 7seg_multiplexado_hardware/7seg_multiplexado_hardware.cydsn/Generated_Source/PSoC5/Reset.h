/*******************************************************************************
* File Name: Reset.h  
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

#if !defined(CY_PINS_Reset_H) /* Pins Reset_H */
#define CY_PINS_Reset_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Reset_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Reset__PORT == 15 && ((Reset__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Reset_Write(uint8 value);
void    Reset_SetDriveMode(uint8 mode);
uint8   Reset_ReadDataReg(void);
uint8   Reset_Read(void);
void    Reset_SetInterruptMode(uint16 position, uint16 mode);
uint8   Reset_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Reset_SetDriveMode() function.
     *  @{
     */
        #define Reset_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Reset_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Reset_DM_RES_UP          PIN_DM_RES_UP
        #define Reset_DM_RES_DWN         PIN_DM_RES_DWN
        #define Reset_DM_OD_LO           PIN_DM_OD_LO
        #define Reset_DM_OD_HI           PIN_DM_OD_HI
        #define Reset_DM_STRONG          PIN_DM_STRONG
        #define Reset_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Reset_MASK               Reset__MASK
#define Reset_SHIFT              Reset__SHIFT
#define Reset_WIDTH              1u

/* Interrupt constants */
#if defined(Reset__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Reset_SetInterruptMode() function.
     *  @{
     */
        #define Reset_INTR_NONE      (uint16)(0x0000u)
        #define Reset_INTR_RISING    (uint16)(0x0001u)
        #define Reset_INTR_FALLING   (uint16)(0x0002u)
        #define Reset_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Reset_INTR_MASK      (0x01u) 
#endif /* (Reset__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Reset_PS                     (* (reg8 *) Reset__PS)
/* Data Register */
#define Reset_DR                     (* (reg8 *) Reset__DR)
/* Port Number */
#define Reset_PRT_NUM                (* (reg8 *) Reset__PRT) 
/* Connect to Analog Globals */                                                  
#define Reset_AG                     (* (reg8 *) Reset__AG)                       
/* Analog MUX bux enable */
#define Reset_AMUX                   (* (reg8 *) Reset__AMUX) 
/* Bidirectional Enable */                                                        
#define Reset_BIE                    (* (reg8 *) Reset__BIE)
/* Bit-mask for Aliased Register Access */
#define Reset_BIT_MASK               (* (reg8 *) Reset__BIT_MASK)
/* Bypass Enable */
#define Reset_BYP                    (* (reg8 *) Reset__BYP)
/* Port wide control signals */                                                   
#define Reset_CTL                    (* (reg8 *) Reset__CTL)
/* Drive Modes */
#define Reset_DM0                    (* (reg8 *) Reset__DM0) 
#define Reset_DM1                    (* (reg8 *) Reset__DM1)
#define Reset_DM2                    (* (reg8 *) Reset__DM2) 
/* Input Buffer Disable Override */
#define Reset_INP_DIS                (* (reg8 *) Reset__INP_DIS)
/* LCD Common or Segment Drive */
#define Reset_LCD_COM_SEG            (* (reg8 *) Reset__LCD_COM_SEG)
/* Enable Segment LCD */
#define Reset_LCD_EN                 (* (reg8 *) Reset__LCD_EN)
/* Slew Rate Control */
#define Reset_SLW                    (* (reg8 *) Reset__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Reset_PRTDSI__CAPS_SEL       (* (reg8 *) Reset__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Reset_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Reset__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Reset_PRTDSI__OE_SEL0        (* (reg8 *) Reset__PRTDSI__OE_SEL0) 
#define Reset_PRTDSI__OE_SEL1        (* (reg8 *) Reset__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Reset_PRTDSI__OUT_SEL0       (* (reg8 *) Reset__PRTDSI__OUT_SEL0) 
#define Reset_PRTDSI__OUT_SEL1       (* (reg8 *) Reset__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Reset_PRTDSI__SYNC_OUT       (* (reg8 *) Reset__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Reset__SIO_CFG)
    #define Reset_SIO_HYST_EN        (* (reg8 *) Reset__SIO_HYST_EN)
    #define Reset_SIO_REG_HIFREQ     (* (reg8 *) Reset__SIO_REG_HIFREQ)
    #define Reset_SIO_CFG            (* (reg8 *) Reset__SIO_CFG)
    #define Reset_SIO_DIFF           (* (reg8 *) Reset__SIO_DIFF)
#endif /* (Reset__SIO_CFG) */

/* Interrupt Registers */
#if defined(Reset__INTSTAT)
    #define Reset_INTSTAT            (* (reg8 *) Reset__INTSTAT)
    #define Reset_SNAP               (* (reg8 *) Reset__SNAP)
    
	#define Reset_0_INTTYPE_REG 		(* (reg8 *) Reset__0__INTTYPE)
#endif /* (Reset__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Reset_H */


/* [] END OF FILE */
