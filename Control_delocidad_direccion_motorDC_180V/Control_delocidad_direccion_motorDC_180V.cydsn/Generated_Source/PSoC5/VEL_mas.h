/*******************************************************************************
* File Name: VEL_mas.h  
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

#if !defined(CY_PINS_VEL_mas_H) /* Pins VEL_mas_H */
#define CY_PINS_VEL_mas_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VEL_mas_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VEL_mas__PORT == 15 && ((VEL_mas__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VEL_mas_Write(uint8 value);
void    VEL_mas_SetDriveMode(uint8 mode);
uint8   VEL_mas_ReadDataReg(void);
uint8   VEL_mas_Read(void);
void    VEL_mas_SetInterruptMode(uint16 position, uint16 mode);
uint8   VEL_mas_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VEL_mas_SetDriveMode() function.
     *  @{
     */
        #define VEL_mas_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VEL_mas_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VEL_mas_DM_RES_UP          PIN_DM_RES_UP
        #define VEL_mas_DM_RES_DWN         PIN_DM_RES_DWN
        #define VEL_mas_DM_OD_LO           PIN_DM_OD_LO
        #define VEL_mas_DM_OD_HI           PIN_DM_OD_HI
        #define VEL_mas_DM_STRONG          PIN_DM_STRONG
        #define VEL_mas_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VEL_mas_MASK               VEL_mas__MASK
#define VEL_mas_SHIFT              VEL_mas__SHIFT
#define VEL_mas_WIDTH              1u

/* Interrupt constants */
#if defined(VEL_mas__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VEL_mas_SetInterruptMode() function.
     *  @{
     */
        #define VEL_mas_INTR_NONE      (uint16)(0x0000u)
        #define VEL_mas_INTR_RISING    (uint16)(0x0001u)
        #define VEL_mas_INTR_FALLING   (uint16)(0x0002u)
        #define VEL_mas_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VEL_mas_INTR_MASK      (0x01u) 
#endif /* (VEL_mas__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VEL_mas_PS                     (* (reg8 *) VEL_mas__PS)
/* Data Register */
#define VEL_mas_DR                     (* (reg8 *) VEL_mas__DR)
/* Port Number */
#define VEL_mas_PRT_NUM                (* (reg8 *) VEL_mas__PRT) 
/* Connect to Analog Globals */                                                  
#define VEL_mas_AG                     (* (reg8 *) VEL_mas__AG)                       
/* Analog MUX bux enable */
#define VEL_mas_AMUX                   (* (reg8 *) VEL_mas__AMUX) 
/* Bidirectional Enable */                                                        
#define VEL_mas_BIE                    (* (reg8 *) VEL_mas__BIE)
/* Bit-mask for Aliased Register Access */
#define VEL_mas_BIT_MASK               (* (reg8 *) VEL_mas__BIT_MASK)
/* Bypass Enable */
#define VEL_mas_BYP                    (* (reg8 *) VEL_mas__BYP)
/* Port wide control signals */                                                   
#define VEL_mas_CTL                    (* (reg8 *) VEL_mas__CTL)
/* Drive Modes */
#define VEL_mas_DM0                    (* (reg8 *) VEL_mas__DM0) 
#define VEL_mas_DM1                    (* (reg8 *) VEL_mas__DM1)
#define VEL_mas_DM2                    (* (reg8 *) VEL_mas__DM2) 
/* Input Buffer Disable Override */
#define VEL_mas_INP_DIS                (* (reg8 *) VEL_mas__INP_DIS)
/* LCD Common or Segment Drive */
#define VEL_mas_LCD_COM_SEG            (* (reg8 *) VEL_mas__LCD_COM_SEG)
/* Enable Segment LCD */
#define VEL_mas_LCD_EN                 (* (reg8 *) VEL_mas__LCD_EN)
/* Slew Rate Control */
#define VEL_mas_SLW                    (* (reg8 *) VEL_mas__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VEL_mas_PRTDSI__CAPS_SEL       (* (reg8 *) VEL_mas__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VEL_mas_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VEL_mas__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VEL_mas_PRTDSI__OE_SEL0        (* (reg8 *) VEL_mas__PRTDSI__OE_SEL0) 
#define VEL_mas_PRTDSI__OE_SEL1        (* (reg8 *) VEL_mas__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VEL_mas_PRTDSI__OUT_SEL0       (* (reg8 *) VEL_mas__PRTDSI__OUT_SEL0) 
#define VEL_mas_PRTDSI__OUT_SEL1       (* (reg8 *) VEL_mas__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VEL_mas_PRTDSI__SYNC_OUT       (* (reg8 *) VEL_mas__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VEL_mas__SIO_CFG)
    #define VEL_mas_SIO_HYST_EN        (* (reg8 *) VEL_mas__SIO_HYST_EN)
    #define VEL_mas_SIO_REG_HIFREQ     (* (reg8 *) VEL_mas__SIO_REG_HIFREQ)
    #define VEL_mas_SIO_CFG            (* (reg8 *) VEL_mas__SIO_CFG)
    #define VEL_mas_SIO_DIFF           (* (reg8 *) VEL_mas__SIO_DIFF)
#endif /* (VEL_mas__SIO_CFG) */

/* Interrupt Registers */
#if defined(VEL_mas__INTSTAT)
    #define VEL_mas_INTSTAT            (* (reg8 *) VEL_mas__INTSTAT)
    #define VEL_mas_SNAP               (* (reg8 *) VEL_mas__SNAP)
    
	#define VEL_mas_0_INTTYPE_REG 		(* (reg8 *) VEL_mas__0__INTTYPE)
#endif /* (VEL_mas__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VEL_mas_H */


/* [] END OF FILE */
