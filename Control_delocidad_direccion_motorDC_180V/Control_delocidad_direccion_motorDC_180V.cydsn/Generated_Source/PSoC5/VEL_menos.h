/*******************************************************************************
* File Name: VEL_menos.h  
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

#if !defined(CY_PINS_VEL_menos_H) /* Pins VEL_menos_H */
#define CY_PINS_VEL_menos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VEL_menos_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VEL_menos__PORT == 15 && ((VEL_menos__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VEL_menos_Write(uint8 value);
void    VEL_menos_SetDriveMode(uint8 mode);
uint8   VEL_menos_ReadDataReg(void);
uint8   VEL_menos_Read(void);
void    VEL_menos_SetInterruptMode(uint16 position, uint16 mode);
uint8   VEL_menos_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VEL_menos_SetDriveMode() function.
     *  @{
     */
        #define VEL_menos_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VEL_menos_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VEL_menos_DM_RES_UP          PIN_DM_RES_UP
        #define VEL_menos_DM_RES_DWN         PIN_DM_RES_DWN
        #define VEL_menos_DM_OD_LO           PIN_DM_OD_LO
        #define VEL_menos_DM_OD_HI           PIN_DM_OD_HI
        #define VEL_menos_DM_STRONG          PIN_DM_STRONG
        #define VEL_menos_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VEL_menos_MASK               VEL_menos__MASK
#define VEL_menos_SHIFT              VEL_menos__SHIFT
#define VEL_menos_WIDTH              1u

/* Interrupt constants */
#if defined(VEL_menos__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VEL_menos_SetInterruptMode() function.
     *  @{
     */
        #define VEL_menos_INTR_NONE      (uint16)(0x0000u)
        #define VEL_menos_INTR_RISING    (uint16)(0x0001u)
        #define VEL_menos_INTR_FALLING   (uint16)(0x0002u)
        #define VEL_menos_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VEL_menos_INTR_MASK      (0x01u) 
#endif /* (VEL_menos__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VEL_menos_PS                     (* (reg8 *) VEL_menos__PS)
/* Data Register */
#define VEL_menos_DR                     (* (reg8 *) VEL_menos__DR)
/* Port Number */
#define VEL_menos_PRT_NUM                (* (reg8 *) VEL_menos__PRT) 
/* Connect to Analog Globals */                                                  
#define VEL_menos_AG                     (* (reg8 *) VEL_menos__AG)                       
/* Analog MUX bux enable */
#define VEL_menos_AMUX                   (* (reg8 *) VEL_menos__AMUX) 
/* Bidirectional Enable */                                                        
#define VEL_menos_BIE                    (* (reg8 *) VEL_menos__BIE)
/* Bit-mask for Aliased Register Access */
#define VEL_menos_BIT_MASK               (* (reg8 *) VEL_menos__BIT_MASK)
/* Bypass Enable */
#define VEL_menos_BYP                    (* (reg8 *) VEL_menos__BYP)
/* Port wide control signals */                                                   
#define VEL_menos_CTL                    (* (reg8 *) VEL_menos__CTL)
/* Drive Modes */
#define VEL_menos_DM0                    (* (reg8 *) VEL_menos__DM0) 
#define VEL_menos_DM1                    (* (reg8 *) VEL_menos__DM1)
#define VEL_menos_DM2                    (* (reg8 *) VEL_menos__DM2) 
/* Input Buffer Disable Override */
#define VEL_menos_INP_DIS                (* (reg8 *) VEL_menos__INP_DIS)
/* LCD Common or Segment Drive */
#define VEL_menos_LCD_COM_SEG            (* (reg8 *) VEL_menos__LCD_COM_SEG)
/* Enable Segment LCD */
#define VEL_menos_LCD_EN                 (* (reg8 *) VEL_menos__LCD_EN)
/* Slew Rate Control */
#define VEL_menos_SLW                    (* (reg8 *) VEL_menos__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VEL_menos_PRTDSI__CAPS_SEL       (* (reg8 *) VEL_menos__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VEL_menos_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VEL_menos__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VEL_menos_PRTDSI__OE_SEL0        (* (reg8 *) VEL_menos__PRTDSI__OE_SEL0) 
#define VEL_menos_PRTDSI__OE_SEL1        (* (reg8 *) VEL_menos__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VEL_menos_PRTDSI__OUT_SEL0       (* (reg8 *) VEL_menos__PRTDSI__OUT_SEL0) 
#define VEL_menos_PRTDSI__OUT_SEL1       (* (reg8 *) VEL_menos__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VEL_menos_PRTDSI__SYNC_OUT       (* (reg8 *) VEL_menos__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VEL_menos__SIO_CFG)
    #define VEL_menos_SIO_HYST_EN        (* (reg8 *) VEL_menos__SIO_HYST_EN)
    #define VEL_menos_SIO_REG_HIFREQ     (* (reg8 *) VEL_menos__SIO_REG_HIFREQ)
    #define VEL_menos_SIO_CFG            (* (reg8 *) VEL_menos__SIO_CFG)
    #define VEL_menos_SIO_DIFF           (* (reg8 *) VEL_menos__SIO_DIFF)
#endif /* (VEL_menos__SIO_CFG) */

/* Interrupt Registers */
#if defined(VEL_menos__INTSTAT)
    #define VEL_menos_INTSTAT            (* (reg8 *) VEL_menos__INTSTAT)
    #define VEL_menos_SNAP               (* (reg8 *) VEL_menos__SNAP)
    
	#define VEL_menos_0_INTTYPE_REG 		(* (reg8 *) VEL_menos__0__INTTYPE)
#endif /* (VEL_menos__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VEL_menos_H */


/* [] END OF FILE */
