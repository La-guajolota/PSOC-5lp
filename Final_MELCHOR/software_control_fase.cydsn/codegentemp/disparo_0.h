/*******************************************************************************
* File Name: disparo_0.h  
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

#if !defined(CY_PINS_disparo_0_H) /* Pins disparo_0_H */
#define CY_PINS_disparo_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "disparo_0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 disparo_0__PORT == 15 && ((disparo_0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    disparo_0_Write(uint8 value);
void    disparo_0_SetDriveMode(uint8 mode);
uint8   disparo_0_ReadDataReg(void);
uint8   disparo_0_Read(void);
void    disparo_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   disparo_0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the disparo_0_SetDriveMode() function.
     *  @{
     */
        #define disparo_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define disparo_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define disparo_0_DM_RES_UP          PIN_DM_RES_UP
        #define disparo_0_DM_RES_DWN         PIN_DM_RES_DWN
        #define disparo_0_DM_OD_LO           PIN_DM_OD_LO
        #define disparo_0_DM_OD_HI           PIN_DM_OD_HI
        #define disparo_0_DM_STRONG          PIN_DM_STRONG
        #define disparo_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define disparo_0_MASK               disparo_0__MASK
#define disparo_0_SHIFT              disparo_0__SHIFT
#define disparo_0_WIDTH              1u

/* Interrupt constants */
#if defined(disparo_0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in disparo_0_SetInterruptMode() function.
     *  @{
     */
        #define disparo_0_INTR_NONE      (uint16)(0x0000u)
        #define disparo_0_INTR_RISING    (uint16)(0x0001u)
        #define disparo_0_INTR_FALLING   (uint16)(0x0002u)
        #define disparo_0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define disparo_0_INTR_MASK      (0x01u) 
#endif /* (disparo_0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define disparo_0_PS                     (* (reg8 *) disparo_0__PS)
/* Data Register */
#define disparo_0_DR                     (* (reg8 *) disparo_0__DR)
/* Port Number */
#define disparo_0_PRT_NUM                (* (reg8 *) disparo_0__PRT) 
/* Connect to Analog Globals */                                                  
#define disparo_0_AG                     (* (reg8 *) disparo_0__AG)                       
/* Analog MUX bux enable */
#define disparo_0_AMUX                   (* (reg8 *) disparo_0__AMUX) 
/* Bidirectional Enable */                                                        
#define disparo_0_BIE                    (* (reg8 *) disparo_0__BIE)
/* Bit-mask for Aliased Register Access */
#define disparo_0_BIT_MASK               (* (reg8 *) disparo_0__BIT_MASK)
/* Bypass Enable */
#define disparo_0_BYP                    (* (reg8 *) disparo_0__BYP)
/* Port wide control signals */                                                   
#define disparo_0_CTL                    (* (reg8 *) disparo_0__CTL)
/* Drive Modes */
#define disparo_0_DM0                    (* (reg8 *) disparo_0__DM0) 
#define disparo_0_DM1                    (* (reg8 *) disparo_0__DM1)
#define disparo_0_DM2                    (* (reg8 *) disparo_0__DM2) 
/* Input Buffer Disable Override */
#define disparo_0_INP_DIS                (* (reg8 *) disparo_0__INP_DIS)
/* LCD Common or Segment Drive */
#define disparo_0_LCD_COM_SEG            (* (reg8 *) disparo_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define disparo_0_LCD_EN                 (* (reg8 *) disparo_0__LCD_EN)
/* Slew Rate Control */
#define disparo_0_SLW                    (* (reg8 *) disparo_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define disparo_0_PRTDSI__CAPS_SEL       (* (reg8 *) disparo_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define disparo_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) disparo_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define disparo_0_PRTDSI__OE_SEL0        (* (reg8 *) disparo_0__PRTDSI__OE_SEL0) 
#define disparo_0_PRTDSI__OE_SEL1        (* (reg8 *) disparo_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define disparo_0_PRTDSI__OUT_SEL0       (* (reg8 *) disparo_0__PRTDSI__OUT_SEL0) 
#define disparo_0_PRTDSI__OUT_SEL1       (* (reg8 *) disparo_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define disparo_0_PRTDSI__SYNC_OUT       (* (reg8 *) disparo_0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(disparo_0__SIO_CFG)
    #define disparo_0_SIO_HYST_EN        (* (reg8 *) disparo_0__SIO_HYST_EN)
    #define disparo_0_SIO_REG_HIFREQ     (* (reg8 *) disparo_0__SIO_REG_HIFREQ)
    #define disparo_0_SIO_CFG            (* (reg8 *) disparo_0__SIO_CFG)
    #define disparo_0_SIO_DIFF           (* (reg8 *) disparo_0__SIO_DIFF)
#endif /* (disparo_0__SIO_CFG) */

/* Interrupt Registers */
#if defined(disparo_0__INTSTAT)
    #define disparo_0_INTSTAT            (* (reg8 *) disparo_0__INTSTAT)
    #define disparo_0_SNAP               (* (reg8 *) disparo_0__SNAP)
    
	#define disparo_0_0_INTTYPE_REG 		(* (reg8 *) disparo_0__0__INTTYPE)
#endif /* (disparo_0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_disparo_0_H */


/* [] END OF FILE */
