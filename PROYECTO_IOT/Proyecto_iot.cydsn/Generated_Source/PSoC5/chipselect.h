/*******************************************************************************
* File Name: chipselect.h  
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

#if !defined(CY_PINS_chipselect_H) /* Pins chipselect_H */
#define CY_PINS_chipselect_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chipselect_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chipselect__PORT == 15 && ((chipselect__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chipselect_Write(uint8 value);
void    chipselect_SetDriveMode(uint8 mode);
uint8   chipselect_ReadDataReg(void);
uint8   chipselect_Read(void);
void    chipselect_SetInterruptMode(uint16 position, uint16 mode);
uint8   chipselect_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chipselect_SetDriveMode() function.
     *  @{
     */
        #define chipselect_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chipselect_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chipselect_DM_RES_UP          PIN_DM_RES_UP
        #define chipselect_DM_RES_DWN         PIN_DM_RES_DWN
        #define chipselect_DM_OD_LO           PIN_DM_OD_LO
        #define chipselect_DM_OD_HI           PIN_DM_OD_HI
        #define chipselect_DM_STRONG          PIN_DM_STRONG
        #define chipselect_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chipselect_MASK               chipselect__MASK
#define chipselect_SHIFT              chipselect__SHIFT
#define chipselect_WIDTH              1u

/* Interrupt constants */
#if defined(chipselect__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chipselect_SetInterruptMode() function.
     *  @{
     */
        #define chipselect_INTR_NONE      (uint16)(0x0000u)
        #define chipselect_INTR_RISING    (uint16)(0x0001u)
        #define chipselect_INTR_FALLING   (uint16)(0x0002u)
        #define chipselect_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chipselect_INTR_MASK      (0x01u) 
#endif /* (chipselect__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chipselect_PS                     (* (reg8 *) chipselect__PS)
/* Data Register */
#define chipselect_DR                     (* (reg8 *) chipselect__DR)
/* Port Number */
#define chipselect_PRT_NUM                (* (reg8 *) chipselect__PRT) 
/* Connect to Analog Globals */                                                  
#define chipselect_AG                     (* (reg8 *) chipselect__AG)                       
/* Analog MUX bux enable */
#define chipselect_AMUX                   (* (reg8 *) chipselect__AMUX) 
/* Bidirectional Enable */                                                        
#define chipselect_BIE                    (* (reg8 *) chipselect__BIE)
/* Bit-mask for Aliased Register Access */
#define chipselect_BIT_MASK               (* (reg8 *) chipselect__BIT_MASK)
/* Bypass Enable */
#define chipselect_BYP                    (* (reg8 *) chipselect__BYP)
/* Port wide control signals */                                                   
#define chipselect_CTL                    (* (reg8 *) chipselect__CTL)
/* Drive Modes */
#define chipselect_DM0                    (* (reg8 *) chipselect__DM0) 
#define chipselect_DM1                    (* (reg8 *) chipselect__DM1)
#define chipselect_DM2                    (* (reg8 *) chipselect__DM2) 
/* Input Buffer Disable Override */
#define chipselect_INP_DIS                (* (reg8 *) chipselect__INP_DIS)
/* LCD Common or Segment Drive */
#define chipselect_LCD_COM_SEG            (* (reg8 *) chipselect__LCD_COM_SEG)
/* Enable Segment LCD */
#define chipselect_LCD_EN                 (* (reg8 *) chipselect__LCD_EN)
/* Slew Rate Control */
#define chipselect_SLW                    (* (reg8 *) chipselect__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chipselect_PRTDSI__CAPS_SEL       (* (reg8 *) chipselect__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chipselect_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chipselect__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chipselect_PRTDSI__OE_SEL0        (* (reg8 *) chipselect__PRTDSI__OE_SEL0) 
#define chipselect_PRTDSI__OE_SEL1        (* (reg8 *) chipselect__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chipselect_PRTDSI__OUT_SEL0       (* (reg8 *) chipselect__PRTDSI__OUT_SEL0) 
#define chipselect_PRTDSI__OUT_SEL1       (* (reg8 *) chipselect__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chipselect_PRTDSI__SYNC_OUT       (* (reg8 *) chipselect__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chipselect__SIO_CFG)
    #define chipselect_SIO_HYST_EN        (* (reg8 *) chipselect__SIO_HYST_EN)
    #define chipselect_SIO_REG_HIFREQ     (* (reg8 *) chipselect__SIO_REG_HIFREQ)
    #define chipselect_SIO_CFG            (* (reg8 *) chipselect__SIO_CFG)
    #define chipselect_SIO_DIFF           (* (reg8 *) chipselect__SIO_DIFF)
#endif /* (chipselect__SIO_CFG) */

/* Interrupt Registers */
#if defined(chipselect__INTSTAT)
    #define chipselect_INTSTAT            (* (reg8 *) chipselect__INTSTAT)
    #define chipselect_SNAP               (* (reg8 *) chipselect__SNAP)
    
	#define chipselect_0_INTTYPE_REG 		(* (reg8 *) chipselect__0__INTTYPE)
#endif /* (chipselect__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chipselect_H */


/* [] END OF FILE */
