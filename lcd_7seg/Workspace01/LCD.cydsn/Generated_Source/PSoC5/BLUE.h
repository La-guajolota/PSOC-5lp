/*******************************************************************************
* File Name: BLUE.h  
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

#if !defined(CY_PINS_BLUE_H) /* Pins BLUE_H */
#define CY_PINS_BLUE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BLUE_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BLUE__PORT == 15 && ((BLUE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BLUE_Write(uint8 value);
void    BLUE_SetDriveMode(uint8 mode);
uint8   BLUE_ReadDataReg(void);
uint8   BLUE_Read(void);
void    BLUE_SetInterruptMode(uint16 position, uint16 mode);
uint8   BLUE_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BLUE_SetDriveMode() function.
     *  @{
     */
        #define BLUE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BLUE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BLUE_DM_RES_UP          PIN_DM_RES_UP
        #define BLUE_DM_RES_DWN         PIN_DM_RES_DWN
        #define BLUE_DM_OD_LO           PIN_DM_OD_LO
        #define BLUE_DM_OD_HI           PIN_DM_OD_HI
        #define BLUE_DM_STRONG          PIN_DM_STRONG
        #define BLUE_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BLUE_MASK               BLUE__MASK
#define BLUE_SHIFT              BLUE__SHIFT
#define BLUE_WIDTH              1u

/* Interrupt constants */
#if defined(BLUE__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BLUE_SetInterruptMode() function.
     *  @{
     */
        #define BLUE_INTR_NONE      (uint16)(0x0000u)
        #define BLUE_INTR_RISING    (uint16)(0x0001u)
        #define BLUE_INTR_FALLING   (uint16)(0x0002u)
        #define BLUE_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BLUE_INTR_MASK      (0x01u) 
#endif /* (BLUE__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BLUE_PS                     (* (reg8 *) BLUE__PS)
/* Data Register */
#define BLUE_DR                     (* (reg8 *) BLUE__DR)
/* Port Number */
#define BLUE_PRT_NUM                (* (reg8 *) BLUE__PRT) 
/* Connect to Analog Globals */                                                  
#define BLUE_AG                     (* (reg8 *) BLUE__AG)                       
/* Analog MUX bux enable */
#define BLUE_AMUX                   (* (reg8 *) BLUE__AMUX) 
/* Bidirectional Enable */                                                        
#define BLUE_BIE                    (* (reg8 *) BLUE__BIE)
/* Bit-mask for Aliased Register Access */
#define BLUE_BIT_MASK               (* (reg8 *) BLUE__BIT_MASK)
/* Bypass Enable */
#define BLUE_BYP                    (* (reg8 *) BLUE__BYP)
/* Port wide control signals */                                                   
#define BLUE_CTL                    (* (reg8 *) BLUE__CTL)
/* Drive Modes */
#define BLUE_DM0                    (* (reg8 *) BLUE__DM0) 
#define BLUE_DM1                    (* (reg8 *) BLUE__DM1)
#define BLUE_DM2                    (* (reg8 *) BLUE__DM2) 
/* Input Buffer Disable Override */
#define BLUE_INP_DIS                (* (reg8 *) BLUE__INP_DIS)
/* LCD Common or Segment Drive */
#define BLUE_LCD_COM_SEG            (* (reg8 *) BLUE__LCD_COM_SEG)
/* Enable Segment LCD */
#define BLUE_LCD_EN                 (* (reg8 *) BLUE__LCD_EN)
/* Slew Rate Control */
#define BLUE_SLW                    (* (reg8 *) BLUE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BLUE_PRTDSI__CAPS_SEL       (* (reg8 *) BLUE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BLUE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BLUE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BLUE_PRTDSI__OE_SEL0        (* (reg8 *) BLUE__PRTDSI__OE_SEL0) 
#define BLUE_PRTDSI__OE_SEL1        (* (reg8 *) BLUE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BLUE_PRTDSI__OUT_SEL0       (* (reg8 *) BLUE__PRTDSI__OUT_SEL0) 
#define BLUE_PRTDSI__OUT_SEL1       (* (reg8 *) BLUE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BLUE_PRTDSI__SYNC_OUT       (* (reg8 *) BLUE__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BLUE__SIO_CFG)
    #define BLUE_SIO_HYST_EN        (* (reg8 *) BLUE__SIO_HYST_EN)
    #define BLUE_SIO_REG_HIFREQ     (* (reg8 *) BLUE__SIO_REG_HIFREQ)
    #define BLUE_SIO_CFG            (* (reg8 *) BLUE__SIO_CFG)
    #define BLUE_SIO_DIFF           (* (reg8 *) BLUE__SIO_DIFF)
#endif /* (BLUE__SIO_CFG) */

/* Interrupt Registers */
#if defined(BLUE__INTSTAT)
    #define BLUE_INTSTAT            (* (reg8 *) BLUE__INTSTAT)
    #define BLUE_SNAP               (* (reg8 *) BLUE__SNAP)
    
	#define BLUE_0_INTTYPE_REG 		(* (reg8 *) BLUE__0__INTTYPE)
#endif /* (BLUE__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BLUE_H */


/* [] END OF FILE */
