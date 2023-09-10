/*******************************************************************************
* File Name: DERECHA.h  
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

#if !defined(CY_PINS_DERECHA_H) /* Pins DERECHA_H */
#define CY_PINS_DERECHA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DERECHA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DERECHA__PORT == 15 && ((DERECHA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DERECHA_Write(uint8 value);
void    DERECHA_SetDriveMode(uint8 mode);
uint8   DERECHA_ReadDataReg(void);
uint8   DERECHA_Read(void);
void    DERECHA_SetInterruptMode(uint16 position, uint16 mode);
uint8   DERECHA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DERECHA_SetDriveMode() function.
     *  @{
     */
        #define DERECHA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DERECHA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DERECHA_DM_RES_UP          PIN_DM_RES_UP
        #define DERECHA_DM_RES_DWN         PIN_DM_RES_DWN
        #define DERECHA_DM_OD_LO           PIN_DM_OD_LO
        #define DERECHA_DM_OD_HI           PIN_DM_OD_HI
        #define DERECHA_DM_STRONG          PIN_DM_STRONG
        #define DERECHA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DERECHA_MASK               DERECHA__MASK
#define DERECHA_SHIFT              DERECHA__SHIFT
#define DERECHA_WIDTH              1u

/* Interrupt constants */
#if defined(DERECHA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DERECHA_SetInterruptMode() function.
     *  @{
     */
        #define DERECHA_INTR_NONE      (uint16)(0x0000u)
        #define DERECHA_INTR_RISING    (uint16)(0x0001u)
        #define DERECHA_INTR_FALLING   (uint16)(0x0002u)
        #define DERECHA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DERECHA_INTR_MASK      (0x01u) 
#endif /* (DERECHA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DERECHA_PS                     (* (reg8 *) DERECHA__PS)
/* Data Register */
#define DERECHA_DR                     (* (reg8 *) DERECHA__DR)
/* Port Number */
#define DERECHA_PRT_NUM                (* (reg8 *) DERECHA__PRT) 
/* Connect to Analog Globals */                                                  
#define DERECHA_AG                     (* (reg8 *) DERECHA__AG)                       
/* Analog MUX bux enable */
#define DERECHA_AMUX                   (* (reg8 *) DERECHA__AMUX) 
/* Bidirectional Enable */                                                        
#define DERECHA_BIE                    (* (reg8 *) DERECHA__BIE)
/* Bit-mask for Aliased Register Access */
#define DERECHA_BIT_MASK               (* (reg8 *) DERECHA__BIT_MASK)
/* Bypass Enable */
#define DERECHA_BYP                    (* (reg8 *) DERECHA__BYP)
/* Port wide control signals */                                                   
#define DERECHA_CTL                    (* (reg8 *) DERECHA__CTL)
/* Drive Modes */
#define DERECHA_DM0                    (* (reg8 *) DERECHA__DM0) 
#define DERECHA_DM1                    (* (reg8 *) DERECHA__DM1)
#define DERECHA_DM2                    (* (reg8 *) DERECHA__DM2) 
/* Input Buffer Disable Override */
#define DERECHA_INP_DIS                (* (reg8 *) DERECHA__INP_DIS)
/* LCD Common or Segment Drive */
#define DERECHA_LCD_COM_SEG            (* (reg8 *) DERECHA__LCD_COM_SEG)
/* Enable Segment LCD */
#define DERECHA_LCD_EN                 (* (reg8 *) DERECHA__LCD_EN)
/* Slew Rate Control */
#define DERECHA_SLW                    (* (reg8 *) DERECHA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DERECHA_PRTDSI__CAPS_SEL       (* (reg8 *) DERECHA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DERECHA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DERECHA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DERECHA_PRTDSI__OE_SEL0        (* (reg8 *) DERECHA__PRTDSI__OE_SEL0) 
#define DERECHA_PRTDSI__OE_SEL1        (* (reg8 *) DERECHA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DERECHA_PRTDSI__OUT_SEL0       (* (reg8 *) DERECHA__PRTDSI__OUT_SEL0) 
#define DERECHA_PRTDSI__OUT_SEL1       (* (reg8 *) DERECHA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DERECHA_PRTDSI__SYNC_OUT       (* (reg8 *) DERECHA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DERECHA__SIO_CFG)
    #define DERECHA_SIO_HYST_EN        (* (reg8 *) DERECHA__SIO_HYST_EN)
    #define DERECHA_SIO_REG_HIFREQ     (* (reg8 *) DERECHA__SIO_REG_HIFREQ)
    #define DERECHA_SIO_CFG            (* (reg8 *) DERECHA__SIO_CFG)
    #define DERECHA_SIO_DIFF           (* (reg8 *) DERECHA__SIO_DIFF)
#endif /* (DERECHA__SIO_CFG) */

/* Interrupt Registers */
#if defined(DERECHA__INTSTAT)
    #define DERECHA_INTSTAT            (* (reg8 *) DERECHA__INTSTAT)
    #define DERECHA_SNAP               (* (reg8 *) DERECHA__SNAP)
    
	#define DERECHA_0_INTTYPE_REG 		(* (reg8 *) DERECHA__0__INTTYPE)
#endif /* (DERECHA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DERECHA_H */


/* [] END OF FILE */
