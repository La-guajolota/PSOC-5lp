/*******************************************************************************
* File Name: disparo.h  
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

#if !defined(CY_PINS_disparo_H) /* Pins disparo_H */
#define CY_PINS_disparo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "disparo_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 disparo__PORT == 15 && ((disparo__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    disparo_Write(uint8 value);
void    disparo_SetDriveMode(uint8 mode);
uint8   disparo_ReadDataReg(void);
uint8   disparo_Read(void);
void    disparo_SetInterruptMode(uint16 position, uint16 mode);
uint8   disparo_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the disparo_SetDriveMode() function.
     *  @{
     */
        #define disparo_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define disparo_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define disparo_DM_RES_UP          PIN_DM_RES_UP
        #define disparo_DM_RES_DWN         PIN_DM_RES_DWN
        #define disparo_DM_OD_LO           PIN_DM_OD_LO
        #define disparo_DM_OD_HI           PIN_DM_OD_HI
        #define disparo_DM_STRONG          PIN_DM_STRONG
        #define disparo_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define disparo_MASK               disparo__MASK
#define disparo_SHIFT              disparo__SHIFT
#define disparo_WIDTH              1u

/* Interrupt constants */
#if defined(disparo__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in disparo_SetInterruptMode() function.
     *  @{
     */
        #define disparo_INTR_NONE      (uint16)(0x0000u)
        #define disparo_INTR_RISING    (uint16)(0x0001u)
        #define disparo_INTR_FALLING   (uint16)(0x0002u)
        #define disparo_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define disparo_INTR_MASK      (0x01u) 
#endif /* (disparo__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define disparo_PS                     (* (reg8 *) disparo__PS)
/* Data Register */
#define disparo_DR                     (* (reg8 *) disparo__DR)
/* Port Number */
#define disparo_PRT_NUM                (* (reg8 *) disparo__PRT) 
/* Connect to Analog Globals */                                                  
#define disparo_AG                     (* (reg8 *) disparo__AG)                       
/* Analog MUX bux enable */
#define disparo_AMUX                   (* (reg8 *) disparo__AMUX) 
/* Bidirectional Enable */                                                        
#define disparo_BIE                    (* (reg8 *) disparo__BIE)
/* Bit-mask for Aliased Register Access */
#define disparo_BIT_MASK               (* (reg8 *) disparo__BIT_MASK)
/* Bypass Enable */
#define disparo_BYP                    (* (reg8 *) disparo__BYP)
/* Port wide control signals */                                                   
#define disparo_CTL                    (* (reg8 *) disparo__CTL)
/* Drive Modes */
#define disparo_DM0                    (* (reg8 *) disparo__DM0) 
#define disparo_DM1                    (* (reg8 *) disparo__DM1)
#define disparo_DM2                    (* (reg8 *) disparo__DM2) 
/* Input Buffer Disable Override */
#define disparo_INP_DIS                (* (reg8 *) disparo__INP_DIS)
/* LCD Common or Segment Drive */
#define disparo_LCD_COM_SEG            (* (reg8 *) disparo__LCD_COM_SEG)
/* Enable Segment LCD */
#define disparo_LCD_EN                 (* (reg8 *) disparo__LCD_EN)
/* Slew Rate Control */
#define disparo_SLW                    (* (reg8 *) disparo__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define disparo_PRTDSI__CAPS_SEL       (* (reg8 *) disparo__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define disparo_PRTDSI__DBL_SYNC_IN    (* (reg8 *) disparo__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define disparo_PRTDSI__OE_SEL0        (* (reg8 *) disparo__PRTDSI__OE_SEL0) 
#define disparo_PRTDSI__OE_SEL1        (* (reg8 *) disparo__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define disparo_PRTDSI__OUT_SEL0       (* (reg8 *) disparo__PRTDSI__OUT_SEL0) 
#define disparo_PRTDSI__OUT_SEL1       (* (reg8 *) disparo__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define disparo_PRTDSI__SYNC_OUT       (* (reg8 *) disparo__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(disparo__SIO_CFG)
    #define disparo_SIO_HYST_EN        (* (reg8 *) disparo__SIO_HYST_EN)
    #define disparo_SIO_REG_HIFREQ     (* (reg8 *) disparo__SIO_REG_HIFREQ)
    #define disparo_SIO_CFG            (* (reg8 *) disparo__SIO_CFG)
    #define disparo_SIO_DIFF           (* (reg8 *) disparo__SIO_DIFF)
#endif /* (disparo__SIO_CFG) */

/* Interrupt Registers */
#if defined(disparo__INTSTAT)
    #define disparo_INTSTAT            (* (reg8 *) disparo__INTSTAT)
    #define disparo_SNAP               (* (reg8 *) disparo__SNAP)
    
	#define disparo_0_INTTYPE_REG 		(* (reg8 *) disparo__0__INTTYPE)
#endif /* (disparo__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_disparo_H */


/* [] END OF FILE */
