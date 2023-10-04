/*******************************************************************************
* File Name: ROJO.h  
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

#if !defined(CY_PINS_ROJO_H) /* Pins ROJO_H */
#define CY_PINS_ROJO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ROJO_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ROJO__PORT == 15 && ((ROJO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ROJO_Write(uint8 value);
void    ROJO_SetDriveMode(uint8 mode);
uint8   ROJO_ReadDataReg(void);
uint8   ROJO_Read(void);
void    ROJO_SetInterruptMode(uint16 position, uint16 mode);
uint8   ROJO_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ROJO_SetDriveMode() function.
     *  @{
     */
        #define ROJO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ROJO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ROJO_DM_RES_UP          PIN_DM_RES_UP
        #define ROJO_DM_RES_DWN         PIN_DM_RES_DWN
        #define ROJO_DM_OD_LO           PIN_DM_OD_LO
        #define ROJO_DM_OD_HI           PIN_DM_OD_HI
        #define ROJO_DM_STRONG          PIN_DM_STRONG
        #define ROJO_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ROJO_MASK               ROJO__MASK
#define ROJO_SHIFT              ROJO__SHIFT
#define ROJO_WIDTH              1u

/* Interrupt constants */
#if defined(ROJO__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ROJO_SetInterruptMode() function.
     *  @{
     */
        #define ROJO_INTR_NONE      (uint16)(0x0000u)
        #define ROJO_INTR_RISING    (uint16)(0x0001u)
        #define ROJO_INTR_FALLING   (uint16)(0x0002u)
        #define ROJO_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ROJO_INTR_MASK      (0x01u) 
#endif /* (ROJO__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ROJO_PS                     (* (reg8 *) ROJO__PS)
/* Data Register */
#define ROJO_DR                     (* (reg8 *) ROJO__DR)
/* Port Number */
#define ROJO_PRT_NUM                (* (reg8 *) ROJO__PRT) 
/* Connect to Analog Globals */                                                  
#define ROJO_AG                     (* (reg8 *) ROJO__AG)                       
/* Analog MUX bux enable */
#define ROJO_AMUX                   (* (reg8 *) ROJO__AMUX) 
/* Bidirectional Enable */                                                        
#define ROJO_BIE                    (* (reg8 *) ROJO__BIE)
/* Bit-mask for Aliased Register Access */
#define ROJO_BIT_MASK               (* (reg8 *) ROJO__BIT_MASK)
/* Bypass Enable */
#define ROJO_BYP                    (* (reg8 *) ROJO__BYP)
/* Port wide control signals */                                                   
#define ROJO_CTL                    (* (reg8 *) ROJO__CTL)
/* Drive Modes */
#define ROJO_DM0                    (* (reg8 *) ROJO__DM0) 
#define ROJO_DM1                    (* (reg8 *) ROJO__DM1)
#define ROJO_DM2                    (* (reg8 *) ROJO__DM2) 
/* Input Buffer Disable Override */
#define ROJO_INP_DIS                (* (reg8 *) ROJO__INP_DIS)
/* LCD Common or Segment Drive */
#define ROJO_LCD_COM_SEG            (* (reg8 *) ROJO__LCD_COM_SEG)
/* Enable Segment LCD */
#define ROJO_LCD_EN                 (* (reg8 *) ROJO__LCD_EN)
/* Slew Rate Control */
#define ROJO_SLW                    (* (reg8 *) ROJO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ROJO_PRTDSI__CAPS_SEL       (* (reg8 *) ROJO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ROJO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ROJO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ROJO_PRTDSI__OE_SEL0        (* (reg8 *) ROJO__PRTDSI__OE_SEL0) 
#define ROJO_PRTDSI__OE_SEL1        (* (reg8 *) ROJO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ROJO_PRTDSI__OUT_SEL0       (* (reg8 *) ROJO__PRTDSI__OUT_SEL0) 
#define ROJO_PRTDSI__OUT_SEL1       (* (reg8 *) ROJO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ROJO_PRTDSI__SYNC_OUT       (* (reg8 *) ROJO__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ROJO__SIO_CFG)
    #define ROJO_SIO_HYST_EN        (* (reg8 *) ROJO__SIO_HYST_EN)
    #define ROJO_SIO_REG_HIFREQ     (* (reg8 *) ROJO__SIO_REG_HIFREQ)
    #define ROJO_SIO_CFG            (* (reg8 *) ROJO__SIO_CFG)
    #define ROJO_SIO_DIFF           (* (reg8 *) ROJO__SIO_DIFF)
#endif /* (ROJO__SIO_CFG) */

/* Interrupt Registers */
#if defined(ROJO__INTSTAT)
    #define ROJO_INTSTAT            (* (reg8 *) ROJO__INTSTAT)
    #define ROJO_SNAP               (* (reg8 *) ROJO__SNAP)
    
	#define ROJO_0_INTTYPE_REG 		(* (reg8 *) ROJO__0__INTTYPE)
#endif /* (ROJO__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ROJO_H */


/* [] END OF FILE */
