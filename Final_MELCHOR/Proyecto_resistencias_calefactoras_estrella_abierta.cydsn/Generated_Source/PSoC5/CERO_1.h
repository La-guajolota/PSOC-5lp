/*******************************************************************************
* File Name: CERO_1.h  
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

#if !defined(CY_PINS_CERO_1_H) /* Pins CERO_1_H */
#define CY_PINS_CERO_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CERO_1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CERO_1__PORT == 15 && ((CERO_1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CERO_1_Write(uint8 value);
void    CERO_1_SetDriveMode(uint8 mode);
uint8   CERO_1_ReadDataReg(void);
uint8   CERO_1_Read(void);
void    CERO_1_SetInterruptMode(uint16 position, uint16 mode);
uint8   CERO_1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CERO_1_SetDriveMode() function.
     *  @{
     */
        #define CERO_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CERO_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CERO_1_DM_RES_UP          PIN_DM_RES_UP
        #define CERO_1_DM_RES_DWN         PIN_DM_RES_DWN
        #define CERO_1_DM_OD_LO           PIN_DM_OD_LO
        #define CERO_1_DM_OD_HI           PIN_DM_OD_HI
        #define CERO_1_DM_STRONG          PIN_DM_STRONG
        #define CERO_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CERO_1_MASK               CERO_1__MASK
#define CERO_1_SHIFT              CERO_1__SHIFT
#define CERO_1_WIDTH              1u

/* Interrupt constants */
#if defined(CERO_1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CERO_1_SetInterruptMode() function.
     *  @{
     */
        #define CERO_1_INTR_NONE      (uint16)(0x0000u)
        #define CERO_1_INTR_RISING    (uint16)(0x0001u)
        #define CERO_1_INTR_FALLING   (uint16)(0x0002u)
        #define CERO_1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CERO_1_INTR_MASK      (0x01u) 
#endif /* (CERO_1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CERO_1_PS                     (* (reg8 *) CERO_1__PS)
/* Data Register */
#define CERO_1_DR                     (* (reg8 *) CERO_1__DR)
/* Port Number */
#define CERO_1_PRT_NUM                (* (reg8 *) CERO_1__PRT) 
/* Connect to Analog Globals */                                                  
#define CERO_1_AG                     (* (reg8 *) CERO_1__AG)                       
/* Analog MUX bux enable */
#define CERO_1_AMUX                   (* (reg8 *) CERO_1__AMUX) 
/* Bidirectional Enable */                                                        
#define CERO_1_BIE                    (* (reg8 *) CERO_1__BIE)
/* Bit-mask for Aliased Register Access */
#define CERO_1_BIT_MASK               (* (reg8 *) CERO_1__BIT_MASK)
/* Bypass Enable */
#define CERO_1_BYP                    (* (reg8 *) CERO_1__BYP)
/* Port wide control signals */                                                   
#define CERO_1_CTL                    (* (reg8 *) CERO_1__CTL)
/* Drive Modes */
#define CERO_1_DM0                    (* (reg8 *) CERO_1__DM0) 
#define CERO_1_DM1                    (* (reg8 *) CERO_1__DM1)
#define CERO_1_DM2                    (* (reg8 *) CERO_1__DM2) 
/* Input Buffer Disable Override */
#define CERO_1_INP_DIS                (* (reg8 *) CERO_1__INP_DIS)
/* LCD Common or Segment Drive */
#define CERO_1_LCD_COM_SEG            (* (reg8 *) CERO_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define CERO_1_LCD_EN                 (* (reg8 *) CERO_1__LCD_EN)
/* Slew Rate Control */
#define CERO_1_SLW                    (* (reg8 *) CERO_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CERO_1_PRTDSI__CAPS_SEL       (* (reg8 *) CERO_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CERO_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CERO_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CERO_1_PRTDSI__OE_SEL0        (* (reg8 *) CERO_1__PRTDSI__OE_SEL0) 
#define CERO_1_PRTDSI__OE_SEL1        (* (reg8 *) CERO_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CERO_1_PRTDSI__OUT_SEL0       (* (reg8 *) CERO_1__PRTDSI__OUT_SEL0) 
#define CERO_1_PRTDSI__OUT_SEL1       (* (reg8 *) CERO_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CERO_1_PRTDSI__SYNC_OUT       (* (reg8 *) CERO_1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CERO_1__SIO_CFG)
    #define CERO_1_SIO_HYST_EN        (* (reg8 *) CERO_1__SIO_HYST_EN)
    #define CERO_1_SIO_REG_HIFREQ     (* (reg8 *) CERO_1__SIO_REG_HIFREQ)
    #define CERO_1_SIO_CFG            (* (reg8 *) CERO_1__SIO_CFG)
    #define CERO_1_SIO_DIFF           (* (reg8 *) CERO_1__SIO_DIFF)
#endif /* (CERO_1__SIO_CFG) */

/* Interrupt Registers */
#if defined(CERO_1__INTSTAT)
    #define CERO_1_INTSTAT            (* (reg8 *) CERO_1__INTSTAT)
    #define CERO_1_SNAP               (* (reg8 *) CERO_1__SNAP)
    
	#define CERO_1_0_INTTYPE_REG 		(* (reg8 *) CERO_1__0__INTTYPE)
#endif /* (CERO_1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CERO_1_H */


/* [] END OF FILE */
