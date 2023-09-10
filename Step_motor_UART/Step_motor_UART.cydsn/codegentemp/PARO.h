/*******************************************************************************
* File Name: PARO.h  
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

#if !defined(CY_PINS_PARO_H) /* Pins PARO_H */
#define CY_PINS_PARO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PARO_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PARO__PORT == 15 && ((PARO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PARO_Write(uint8 value);
void    PARO_SetDriveMode(uint8 mode);
uint8   PARO_ReadDataReg(void);
uint8   PARO_Read(void);
void    PARO_SetInterruptMode(uint16 position, uint16 mode);
uint8   PARO_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PARO_SetDriveMode() function.
     *  @{
     */
        #define PARO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PARO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PARO_DM_RES_UP          PIN_DM_RES_UP
        #define PARO_DM_RES_DWN         PIN_DM_RES_DWN
        #define PARO_DM_OD_LO           PIN_DM_OD_LO
        #define PARO_DM_OD_HI           PIN_DM_OD_HI
        #define PARO_DM_STRONG          PIN_DM_STRONG
        #define PARO_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PARO_MASK               PARO__MASK
#define PARO_SHIFT              PARO__SHIFT
#define PARO_WIDTH              1u

/* Interrupt constants */
#if defined(PARO__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PARO_SetInterruptMode() function.
     *  @{
     */
        #define PARO_INTR_NONE      (uint16)(0x0000u)
        #define PARO_INTR_RISING    (uint16)(0x0001u)
        #define PARO_INTR_FALLING   (uint16)(0x0002u)
        #define PARO_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PARO_INTR_MASK      (0x01u) 
#endif /* (PARO__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PARO_PS                     (* (reg8 *) PARO__PS)
/* Data Register */
#define PARO_DR                     (* (reg8 *) PARO__DR)
/* Port Number */
#define PARO_PRT_NUM                (* (reg8 *) PARO__PRT) 
/* Connect to Analog Globals */                                                  
#define PARO_AG                     (* (reg8 *) PARO__AG)                       
/* Analog MUX bux enable */
#define PARO_AMUX                   (* (reg8 *) PARO__AMUX) 
/* Bidirectional Enable */                                                        
#define PARO_BIE                    (* (reg8 *) PARO__BIE)
/* Bit-mask for Aliased Register Access */
#define PARO_BIT_MASK               (* (reg8 *) PARO__BIT_MASK)
/* Bypass Enable */
#define PARO_BYP                    (* (reg8 *) PARO__BYP)
/* Port wide control signals */                                                   
#define PARO_CTL                    (* (reg8 *) PARO__CTL)
/* Drive Modes */
#define PARO_DM0                    (* (reg8 *) PARO__DM0) 
#define PARO_DM1                    (* (reg8 *) PARO__DM1)
#define PARO_DM2                    (* (reg8 *) PARO__DM2) 
/* Input Buffer Disable Override */
#define PARO_INP_DIS                (* (reg8 *) PARO__INP_DIS)
/* LCD Common or Segment Drive */
#define PARO_LCD_COM_SEG            (* (reg8 *) PARO__LCD_COM_SEG)
/* Enable Segment LCD */
#define PARO_LCD_EN                 (* (reg8 *) PARO__LCD_EN)
/* Slew Rate Control */
#define PARO_SLW                    (* (reg8 *) PARO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PARO_PRTDSI__CAPS_SEL       (* (reg8 *) PARO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PARO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PARO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PARO_PRTDSI__OE_SEL0        (* (reg8 *) PARO__PRTDSI__OE_SEL0) 
#define PARO_PRTDSI__OE_SEL1        (* (reg8 *) PARO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PARO_PRTDSI__OUT_SEL0       (* (reg8 *) PARO__PRTDSI__OUT_SEL0) 
#define PARO_PRTDSI__OUT_SEL1       (* (reg8 *) PARO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PARO_PRTDSI__SYNC_OUT       (* (reg8 *) PARO__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PARO__SIO_CFG)
    #define PARO_SIO_HYST_EN        (* (reg8 *) PARO__SIO_HYST_EN)
    #define PARO_SIO_REG_HIFREQ     (* (reg8 *) PARO__SIO_REG_HIFREQ)
    #define PARO_SIO_CFG            (* (reg8 *) PARO__SIO_CFG)
    #define PARO_SIO_DIFF           (* (reg8 *) PARO__SIO_DIFF)
#endif /* (PARO__SIO_CFG) */

/* Interrupt Registers */
#if defined(PARO__INTSTAT)
    #define PARO_INTSTAT            (* (reg8 *) PARO__INTSTAT)
    #define PARO_SNAP               (* (reg8 *) PARO__SNAP)
    
	#define PARO_0_INTTYPE_REG 		(* (reg8 *) PARO__0__INTTYPE)
#endif /* (PARO__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PARO_H */


/* [] END OF FILE */
