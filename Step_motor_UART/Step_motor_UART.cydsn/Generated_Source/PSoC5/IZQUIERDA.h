/*******************************************************************************
* File Name: IZQUIERDA.h  
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

#if !defined(CY_PINS_IZQUIERDA_H) /* Pins IZQUIERDA_H */
#define CY_PINS_IZQUIERDA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IZQUIERDA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IZQUIERDA__PORT == 15 && ((IZQUIERDA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IZQUIERDA_Write(uint8 value);
void    IZQUIERDA_SetDriveMode(uint8 mode);
uint8   IZQUIERDA_ReadDataReg(void);
uint8   IZQUIERDA_Read(void);
void    IZQUIERDA_SetInterruptMode(uint16 position, uint16 mode);
uint8   IZQUIERDA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IZQUIERDA_SetDriveMode() function.
     *  @{
     */
        #define IZQUIERDA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IZQUIERDA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IZQUIERDA_DM_RES_UP          PIN_DM_RES_UP
        #define IZQUIERDA_DM_RES_DWN         PIN_DM_RES_DWN
        #define IZQUIERDA_DM_OD_LO           PIN_DM_OD_LO
        #define IZQUIERDA_DM_OD_HI           PIN_DM_OD_HI
        #define IZQUIERDA_DM_STRONG          PIN_DM_STRONG
        #define IZQUIERDA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IZQUIERDA_MASK               IZQUIERDA__MASK
#define IZQUIERDA_SHIFT              IZQUIERDA__SHIFT
#define IZQUIERDA_WIDTH              1u

/* Interrupt constants */
#if defined(IZQUIERDA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IZQUIERDA_SetInterruptMode() function.
     *  @{
     */
        #define IZQUIERDA_INTR_NONE      (uint16)(0x0000u)
        #define IZQUIERDA_INTR_RISING    (uint16)(0x0001u)
        #define IZQUIERDA_INTR_FALLING   (uint16)(0x0002u)
        #define IZQUIERDA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IZQUIERDA_INTR_MASK      (0x01u) 
#endif /* (IZQUIERDA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IZQUIERDA_PS                     (* (reg8 *) IZQUIERDA__PS)
/* Data Register */
#define IZQUIERDA_DR                     (* (reg8 *) IZQUIERDA__DR)
/* Port Number */
#define IZQUIERDA_PRT_NUM                (* (reg8 *) IZQUIERDA__PRT) 
/* Connect to Analog Globals */                                                  
#define IZQUIERDA_AG                     (* (reg8 *) IZQUIERDA__AG)                       
/* Analog MUX bux enable */
#define IZQUIERDA_AMUX                   (* (reg8 *) IZQUIERDA__AMUX) 
/* Bidirectional Enable */                                                        
#define IZQUIERDA_BIE                    (* (reg8 *) IZQUIERDA__BIE)
/* Bit-mask for Aliased Register Access */
#define IZQUIERDA_BIT_MASK               (* (reg8 *) IZQUIERDA__BIT_MASK)
/* Bypass Enable */
#define IZQUIERDA_BYP                    (* (reg8 *) IZQUIERDA__BYP)
/* Port wide control signals */                                                   
#define IZQUIERDA_CTL                    (* (reg8 *) IZQUIERDA__CTL)
/* Drive Modes */
#define IZQUIERDA_DM0                    (* (reg8 *) IZQUIERDA__DM0) 
#define IZQUIERDA_DM1                    (* (reg8 *) IZQUIERDA__DM1)
#define IZQUIERDA_DM2                    (* (reg8 *) IZQUIERDA__DM2) 
/* Input Buffer Disable Override */
#define IZQUIERDA_INP_DIS                (* (reg8 *) IZQUIERDA__INP_DIS)
/* LCD Common or Segment Drive */
#define IZQUIERDA_LCD_COM_SEG            (* (reg8 *) IZQUIERDA__LCD_COM_SEG)
/* Enable Segment LCD */
#define IZQUIERDA_LCD_EN                 (* (reg8 *) IZQUIERDA__LCD_EN)
/* Slew Rate Control */
#define IZQUIERDA_SLW                    (* (reg8 *) IZQUIERDA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IZQUIERDA_PRTDSI__CAPS_SEL       (* (reg8 *) IZQUIERDA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IZQUIERDA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IZQUIERDA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IZQUIERDA_PRTDSI__OE_SEL0        (* (reg8 *) IZQUIERDA__PRTDSI__OE_SEL0) 
#define IZQUIERDA_PRTDSI__OE_SEL1        (* (reg8 *) IZQUIERDA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IZQUIERDA_PRTDSI__OUT_SEL0       (* (reg8 *) IZQUIERDA__PRTDSI__OUT_SEL0) 
#define IZQUIERDA_PRTDSI__OUT_SEL1       (* (reg8 *) IZQUIERDA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IZQUIERDA_PRTDSI__SYNC_OUT       (* (reg8 *) IZQUIERDA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IZQUIERDA__SIO_CFG)
    #define IZQUIERDA_SIO_HYST_EN        (* (reg8 *) IZQUIERDA__SIO_HYST_EN)
    #define IZQUIERDA_SIO_REG_HIFREQ     (* (reg8 *) IZQUIERDA__SIO_REG_HIFREQ)
    #define IZQUIERDA_SIO_CFG            (* (reg8 *) IZQUIERDA__SIO_CFG)
    #define IZQUIERDA_SIO_DIFF           (* (reg8 *) IZQUIERDA__SIO_DIFF)
#endif /* (IZQUIERDA__SIO_CFG) */

/* Interrupt Registers */
#if defined(IZQUIERDA__INTSTAT)
    #define IZQUIERDA_INTSTAT            (* (reg8 *) IZQUIERDA__INTSTAT)
    #define IZQUIERDA_SNAP               (* (reg8 *) IZQUIERDA__SNAP)
    
	#define IZQUIERDA_0_INTTYPE_REG 		(* (reg8 *) IZQUIERDA__0__INTTYPE)
#endif /* (IZQUIERDA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IZQUIERDA_H */


/* [] END OF FILE */
