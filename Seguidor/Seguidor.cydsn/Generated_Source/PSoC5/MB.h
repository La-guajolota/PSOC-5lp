/*******************************************************************************
* File Name: MB.h  
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

#if !defined(CY_PINS_MB_H) /* Pins MB_H */
#define CY_PINS_MB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MB__PORT == 15 && ((MB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MB_Write(uint8 value);
void    MB_SetDriveMode(uint8 mode);
uint8   MB_ReadDataReg(void);
uint8   MB_Read(void);
void    MB_SetInterruptMode(uint16 position, uint16 mode);
uint8   MB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MB_SetDriveMode() function.
     *  @{
     */
        #define MB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MB_DM_RES_UP          PIN_DM_RES_UP
        #define MB_DM_RES_DWN         PIN_DM_RES_DWN
        #define MB_DM_OD_LO           PIN_DM_OD_LO
        #define MB_DM_OD_HI           PIN_DM_OD_HI
        #define MB_DM_STRONG          PIN_DM_STRONG
        #define MB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MB_MASK               MB__MASK
#define MB_SHIFT              MB__SHIFT
#define MB_WIDTH              1u

/* Interrupt constants */
#if defined(MB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MB_SetInterruptMode() function.
     *  @{
     */
        #define MB_INTR_NONE      (uint16)(0x0000u)
        #define MB_INTR_RISING    (uint16)(0x0001u)
        #define MB_INTR_FALLING   (uint16)(0x0002u)
        #define MB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MB_INTR_MASK      (0x01u) 
#endif /* (MB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MB_PS                     (* (reg8 *) MB__PS)
/* Data Register */
#define MB_DR                     (* (reg8 *) MB__DR)
/* Port Number */
#define MB_PRT_NUM                (* (reg8 *) MB__PRT) 
/* Connect to Analog Globals */                                                  
#define MB_AG                     (* (reg8 *) MB__AG)                       
/* Analog MUX bux enable */
#define MB_AMUX                   (* (reg8 *) MB__AMUX) 
/* Bidirectional Enable */                                                        
#define MB_BIE                    (* (reg8 *) MB__BIE)
/* Bit-mask for Aliased Register Access */
#define MB_BIT_MASK               (* (reg8 *) MB__BIT_MASK)
/* Bypass Enable */
#define MB_BYP                    (* (reg8 *) MB__BYP)
/* Port wide control signals */                                                   
#define MB_CTL                    (* (reg8 *) MB__CTL)
/* Drive Modes */
#define MB_DM0                    (* (reg8 *) MB__DM0) 
#define MB_DM1                    (* (reg8 *) MB__DM1)
#define MB_DM2                    (* (reg8 *) MB__DM2) 
/* Input Buffer Disable Override */
#define MB_INP_DIS                (* (reg8 *) MB__INP_DIS)
/* LCD Common or Segment Drive */
#define MB_LCD_COM_SEG            (* (reg8 *) MB__LCD_COM_SEG)
/* Enable Segment LCD */
#define MB_LCD_EN                 (* (reg8 *) MB__LCD_EN)
/* Slew Rate Control */
#define MB_SLW                    (* (reg8 *) MB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MB_PRTDSI__CAPS_SEL       (* (reg8 *) MB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MB_PRTDSI__OE_SEL0        (* (reg8 *) MB__PRTDSI__OE_SEL0) 
#define MB_PRTDSI__OE_SEL1        (* (reg8 *) MB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MB_PRTDSI__OUT_SEL0       (* (reg8 *) MB__PRTDSI__OUT_SEL0) 
#define MB_PRTDSI__OUT_SEL1       (* (reg8 *) MB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MB_PRTDSI__SYNC_OUT       (* (reg8 *) MB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MB__SIO_CFG)
    #define MB_SIO_HYST_EN        (* (reg8 *) MB__SIO_HYST_EN)
    #define MB_SIO_REG_HIFREQ     (* (reg8 *) MB__SIO_REG_HIFREQ)
    #define MB_SIO_CFG            (* (reg8 *) MB__SIO_CFG)
    #define MB_SIO_DIFF           (* (reg8 *) MB__SIO_DIFF)
#endif /* (MB__SIO_CFG) */

/* Interrupt Registers */
#if defined(MB__INTSTAT)
    #define MB_INTSTAT            (* (reg8 *) MB__INTSTAT)
    #define MB_SNAP               (* (reg8 *) MB__SNAP)
    
	#define MB_0_INTTYPE_REG 		(* (reg8 *) MB__0__INTTYPE)
#endif /* (MB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MB_H */


/* [] END OF FILE */
