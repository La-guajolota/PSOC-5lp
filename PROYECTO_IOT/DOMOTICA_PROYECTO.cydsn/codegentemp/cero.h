/*******************************************************************************
* File Name: cero.h  
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

#if !defined(CY_PINS_cero_H) /* Pins cero_H */
#define CY_PINS_cero_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "cero_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 cero__PORT == 15 && ((cero__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    cero_Write(uint8 value);
void    cero_SetDriveMode(uint8 mode);
uint8   cero_ReadDataReg(void);
uint8   cero_Read(void);
void    cero_SetInterruptMode(uint16 position, uint16 mode);
uint8   cero_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the cero_SetDriveMode() function.
     *  @{
     */
        #define cero_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define cero_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define cero_DM_RES_UP          PIN_DM_RES_UP
        #define cero_DM_RES_DWN         PIN_DM_RES_DWN
        #define cero_DM_OD_LO           PIN_DM_OD_LO
        #define cero_DM_OD_HI           PIN_DM_OD_HI
        #define cero_DM_STRONG          PIN_DM_STRONG
        #define cero_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define cero_MASK               cero__MASK
#define cero_SHIFT              cero__SHIFT
#define cero_WIDTH              1u

/* Interrupt constants */
#if defined(cero__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in cero_SetInterruptMode() function.
     *  @{
     */
        #define cero_INTR_NONE      (uint16)(0x0000u)
        #define cero_INTR_RISING    (uint16)(0x0001u)
        #define cero_INTR_FALLING   (uint16)(0x0002u)
        #define cero_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define cero_INTR_MASK      (0x01u) 
#endif /* (cero__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define cero_PS                     (* (reg8 *) cero__PS)
/* Data Register */
#define cero_DR                     (* (reg8 *) cero__DR)
/* Port Number */
#define cero_PRT_NUM                (* (reg8 *) cero__PRT) 
/* Connect to Analog Globals */                                                  
#define cero_AG                     (* (reg8 *) cero__AG)                       
/* Analog MUX bux enable */
#define cero_AMUX                   (* (reg8 *) cero__AMUX) 
/* Bidirectional Enable */                                                        
#define cero_BIE                    (* (reg8 *) cero__BIE)
/* Bit-mask for Aliased Register Access */
#define cero_BIT_MASK               (* (reg8 *) cero__BIT_MASK)
/* Bypass Enable */
#define cero_BYP                    (* (reg8 *) cero__BYP)
/* Port wide control signals */                                                   
#define cero_CTL                    (* (reg8 *) cero__CTL)
/* Drive Modes */
#define cero_DM0                    (* (reg8 *) cero__DM0) 
#define cero_DM1                    (* (reg8 *) cero__DM1)
#define cero_DM2                    (* (reg8 *) cero__DM2) 
/* Input Buffer Disable Override */
#define cero_INP_DIS                (* (reg8 *) cero__INP_DIS)
/* LCD Common or Segment Drive */
#define cero_LCD_COM_SEG            (* (reg8 *) cero__LCD_COM_SEG)
/* Enable Segment LCD */
#define cero_LCD_EN                 (* (reg8 *) cero__LCD_EN)
/* Slew Rate Control */
#define cero_SLW                    (* (reg8 *) cero__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define cero_PRTDSI__CAPS_SEL       (* (reg8 *) cero__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define cero_PRTDSI__DBL_SYNC_IN    (* (reg8 *) cero__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define cero_PRTDSI__OE_SEL0        (* (reg8 *) cero__PRTDSI__OE_SEL0) 
#define cero_PRTDSI__OE_SEL1        (* (reg8 *) cero__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define cero_PRTDSI__OUT_SEL0       (* (reg8 *) cero__PRTDSI__OUT_SEL0) 
#define cero_PRTDSI__OUT_SEL1       (* (reg8 *) cero__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define cero_PRTDSI__SYNC_OUT       (* (reg8 *) cero__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(cero__SIO_CFG)
    #define cero_SIO_HYST_EN        (* (reg8 *) cero__SIO_HYST_EN)
    #define cero_SIO_REG_HIFREQ     (* (reg8 *) cero__SIO_REG_HIFREQ)
    #define cero_SIO_CFG            (* (reg8 *) cero__SIO_CFG)
    #define cero_SIO_DIFF           (* (reg8 *) cero__SIO_DIFF)
#endif /* (cero__SIO_CFG) */

/* Interrupt Registers */
#if defined(cero__INTSTAT)
    #define cero_INTSTAT            (* (reg8 *) cero__INTSTAT)
    #define cero_SNAP               (* (reg8 *) cero__SNAP)
    
	#define cero_0_INTTYPE_REG 		(* (reg8 *) cero__0__INTTYPE)
#endif /* (cero__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_cero_H */


/* [] END OF FILE */
