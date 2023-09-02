/*******************************************************************************
* File Name: MA.h  
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

#if !defined(CY_PINS_MA_H) /* Pins MA_H */
#define CY_PINS_MA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MA__PORT == 15 && ((MA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MA_Write(uint8 value);
void    MA_SetDriveMode(uint8 mode);
uint8   MA_ReadDataReg(void);
uint8   MA_Read(void);
void    MA_SetInterruptMode(uint16 position, uint16 mode);
uint8   MA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MA_SetDriveMode() function.
     *  @{
     */
        #define MA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MA_DM_RES_UP          PIN_DM_RES_UP
        #define MA_DM_RES_DWN         PIN_DM_RES_DWN
        #define MA_DM_OD_LO           PIN_DM_OD_LO
        #define MA_DM_OD_HI           PIN_DM_OD_HI
        #define MA_DM_STRONG          PIN_DM_STRONG
        #define MA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MA_MASK               MA__MASK
#define MA_SHIFT              MA__SHIFT
#define MA_WIDTH              1u

/* Interrupt constants */
#if defined(MA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MA_SetInterruptMode() function.
     *  @{
     */
        #define MA_INTR_NONE      (uint16)(0x0000u)
        #define MA_INTR_RISING    (uint16)(0x0001u)
        #define MA_INTR_FALLING   (uint16)(0x0002u)
        #define MA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MA_INTR_MASK      (0x01u) 
#endif /* (MA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MA_PS                     (* (reg8 *) MA__PS)
/* Data Register */
#define MA_DR                     (* (reg8 *) MA__DR)
/* Port Number */
#define MA_PRT_NUM                (* (reg8 *) MA__PRT) 
/* Connect to Analog Globals */                                                  
#define MA_AG                     (* (reg8 *) MA__AG)                       
/* Analog MUX bux enable */
#define MA_AMUX                   (* (reg8 *) MA__AMUX) 
/* Bidirectional Enable */                                                        
#define MA_BIE                    (* (reg8 *) MA__BIE)
/* Bit-mask for Aliased Register Access */
#define MA_BIT_MASK               (* (reg8 *) MA__BIT_MASK)
/* Bypass Enable */
#define MA_BYP                    (* (reg8 *) MA__BYP)
/* Port wide control signals */                                                   
#define MA_CTL                    (* (reg8 *) MA__CTL)
/* Drive Modes */
#define MA_DM0                    (* (reg8 *) MA__DM0) 
#define MA_DM1                    (* (reg8 *) MA__DM1)
#define MA_DM2                    (* (reg8 *) MA__DM2) 
/* Input Buffer Disable Override */
#define MA_INP_DIS                (* (reg8 *) MA__INP_DIS)
/* LCD Common or Segment Drive */
#define MA_LCD_COM_SEG            (* (reg8 *) MA__LCD_COM_SEG)
/* Enable Segment LCD */
#define MA_LCD_EN                 (* (reg8 *) MA__LCD_EN)
/* Slew Rate Control */
#define MA_SLW                    (* (reg8 *) MA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MA_PRTDSI__CAPS_SEL       (* (reg8 *) MA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MA_PRTDSI__OE_SEL0        (* (reg8 *) MA__PRTDSI__OE_SEL0) 
#define MA_PRTDSI__OE_SEL1        (* (reg8 *) MA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MA_PRTDSI__OUT_SEL0       (* (reg8 *) MA__PRTDSI__OUT_SEL0) 
#define MA_PRTDSI__OUT_SEL1       (* (reg8 *) MA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MA_PRTDSI__SYNC_OUT       (* (reg8 *) MA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MA__SIO_CFG)
    #define MA_SIO_HYST_EN        (* (reg8 *) MA__SIO_HYST_EN)
    #define MA_SIO_REG_HIFREQ     (* (reg8 *) MA__SIO_REG_HIFREQ)
    #define MA_SIO_CFG            (* (reg8 *) MA__SIO_CFG)
    #define MA_SIO_DIFF           (* (reg8 *) MA__SIO_DIFF)
#endif /* (MA__SIO_CFG) */

/* Interrupt Registers */
#if defined(MA__INTSTAT)
    #define MA_INTSTAT            (* (reg8 *) MA__INTSTAT)
    #define MA_SNAP               (* (reg8 *) MA__SNAP)
    
	#define MA_0_INTTYPE_REG 		(* (reg8 *) MA__0__INTTYPE)
#endif /* (MA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MA_H */


/* [] END OF FILE */
