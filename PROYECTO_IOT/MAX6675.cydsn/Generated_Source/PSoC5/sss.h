/*******************************************************************************
* File Name: sss.h  
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

#if !defined(CY_PINS_sss_H) /* Pins sss_H */
#define CY_PINS_sss_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sss_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sss__PORT == 15 && ((sss__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sss_Write(uint8 value);
void    sss_SetDriveMode(uint8 mode);
uint8   sss_ReadDataReg(void);
uint8   sss_Read(void);
void    sss_SetInterruptMode(uint16 position, uint16 mode);
uint8   sss_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sss_SetDriveMode() function.
     *  @{
     */
        #define sss_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sss_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sss_DM_RES_UP          PIN_DM_RES_UP
        #define sss_DM_RES_DWN         PIN_DM_RES_DWN
        #define sss_DM_OD_LO           PIN_DM_OD_LO
        #define sss_DM_OD_HI           PIN_DM_OD_HI
        #define sss_DM_STRONG          PIN_DM_STRONG
        #define sss_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sss_MASK               sss__MASK
#define sss_SHIFT              sss__SHIFT
#define sss_WIDTH              1u

/* Interrupt constants */
#if defined(sss__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sss_SetInterruptMode() function.
     *  @{
     */
        #define sss_INTR_NONE      (uint16)(0x0000u)
        #define sss_INTR_RISING    (uint16)(0x0001u)
        #define sss_INTR_FALLING   (uint16)(0x0002u)
        #define sss_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sss_INTR_MASK      (0x01u) 
#endif /* (sss__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sss_PS                     (* (reg8 *) sss__PS)
/* Data Register */
#define sss_DR                     (* (reg8 *) sss__DR)
/* Port Number */
#define sss_PRT_NUM                (* (reg8 *) sss__PRT) 
/* Connect to Analog Globals */                                                  
#define sss_AG                     (* (reg8 *) sss__AG)                       
/* Analog MUX bux enable */
#define sss_AMUX                   (* (reg8 *) sss__AMUX) 
/* Bidirectional Enable */                                                        
#define sss_BIE                    (* (reg8 *) sss__BIE)
/* Bit-mask for Aliased Register Access */
#define sss_BIT_MASK               (* (reg8 *) sss__BIT_MASK)
/* Bypass Enable */
#define sss_BYP                    (* (reg8 *) sss__BYP)
/* Port wide control signals */                                                   
#define sss_CTL                    (* (reg8 *) sss__CTL)
/* Drive Modes */
#define sss_DM0                    (* (reg8 *) sss__DM0) 
#define sss_DM1                    (* (reg8 *) sss__DM1)
#define sss_DM2                    (* (reg8 *) sss__DM2) 
/* Input Buffer Disable Override */
#define sss_INP_DIS                (* (reg8 *) sss__INP_DIS)
/* LCD Common or Segment Drive */
#define sss_LCD_COM_SEG            (* (reg8 *) sss__LCD_COM_SEG)
/* Enable Segment LCD */
#define sss_LCD_EN                 (* (reg8 *) sss__LCD_EN)
/* Slew Rate Control */
#define sss_SLW                    (* (reg8 *) sss__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sss_PRTDSI__CAPS_SEL       (* (reg8 *) sss__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sss_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sss__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sss_PRTDSI__OE_SEL0        (* (reg8 *) sss__PRTDSI__OE_SEL0) 
#define sss_PRTDSI__OE_SEL1        (* (reg8 *) sss__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sss_PRTDSI__OUT_SEL0       (* (reg8 *) sss__PRTDSI__OUT_SEL0) 
#define sss_PRTDSI__OUT_SEL1       (* (reg8 *) sss__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sss_PRTDSI__SYNC_OUT       (* (reg8 *) sss__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sss__SIO_CFG)
    #define sss_SIO_HYST_EN        (* (reg8 *) sss__SIO_HYST_EN)
    #define sss_SIO_REG_HIFREQ     (* (reg8 *) sss__SIO_REG_HIFREQ)
    #define sss_SIO_CFG            (* (reg8 *) sss__SIO_CFG)
    #define sss_SIO_DIFF           (* (reg8 *) sss__SIO_DIFF)
#endif /* (sss__SIO_CFG) */

/* Interrupt Registers */
#if defined(sss__INTSTAT)
    #define sss_INTSTAT            (* (reg8 *) sss__INTSTAT)
    #define sss_SNAP               (* (reg8 *) sss__SNAP)
    
	#define sss_0_INTTYPE_REG 		(* (reg8 *) sss__0__INTTYPE)
#endif /* (sss__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sss_H */


/* [] END OF FILE */
