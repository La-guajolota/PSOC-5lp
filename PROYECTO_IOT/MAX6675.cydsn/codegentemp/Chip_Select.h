/*******************************************************************************
* File Name: Chip_Select.h  
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

#if !defined(CY_PINS_Chip_Select_H) /* Pins Chip_Select_H */
#define CY_PINS_Chip_Select_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Chip_Select_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Chip_Select__PORT == 15 && ((Chip_Select__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Chip_Select_Write(uint8 value);
void    Chip_Select_SetDriveMode(uint8 mode);
uint8   Chip_Select_ReadDataReg(void);
uint8   Chip_Select_Read(void);
void    Chip_Select_SetInterruptMode(uint16 position, uint16 mode);
uint8   Chip_Select_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Chip_Select_SetDriveMode() function.
     *  @{
     */
        #define Chip_Select_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Chip_Select_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Chip_Select_DM_RES_UP          PIN_DM_RES_UP
        #define Chip_Select_DM_RES_DWN         PIN_DM_RES_DWN
        #define Chip_Select_DM_OD_LO           PIN_DM_OD_LO
        #define Chip_Select_DM_OD_HI           PIN_DM_OD_HI
        #define Chip_Select_DM_STRONG          PIN_DM_STRONG
        #define Chip_Select_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Chip_Select_MASK               Chip_Select__MASK
#define Chip_Select_SHIFT              Chip_Select__SHIFT
#define Chip_Select_WIDTH              1u

/* Interrupt constants */
#if defined(Chip_Select__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Chip_Select_SetInterruptMode() function.
     *  @{
     */
        #define Chip_Select_INTR_NONE      (uint16)(0x0000u)
        #define Chip_Select_INTR_RISING    (uint16)(0x0001u)
        #define Chip_Select_INTR_FALLING   (uint16)(0x0002u)
        #define Chip_Select_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Chip_Select_INTR_MASK      (0x01u) 
#endif /* (Chip_Select__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Chip_Select_PS                     (* (reg8 *) Chip_Select__PS)
/* Data Register */
#define Chip_Select_DR                     (* (reg8 *) Chip_Select__DR)
/* Port Number */
#define Chip_Select_PRT_NUM                (* (reg8 *) Chip_Select__PRT) 
/* Connect to Analog Globals */                                                  
#define Chip_Select_AG                     (* (reg8 *) Chip_Select__AG)                       
/* Analog MUX bux enable */
#define Chip_Select_AMUX                   (* (reg8 *) Chip_Select__AMUX) 
/* Bidirectional Enable */                                                        
#define Chip_Select_BIE                    (* (reg8 *) Chip_Select__BIE)
/* Bit-mask for Aliased Register Access */
#define Chip_Select_BIT_MASK               (* (reg8 *) Chip_Select__BIT_MASK)
/* Bypass Enable */
#define Chip_Select_BYP                    (* (reg8 *) Chip_Select__BYP)
/* Port wide control signals */                                                   
#define Chip_Select_CTL                    (* (reg8 *) Chip_Select__CTL)
/* Drive Modes */
#define Chip_Select_DM0                    (* (reg8 *) Chip_Select__DM0) 
#define Chip_Select_DM1                    (* (reg8 *) Chip_Select__DM1)
#define Chip_Select_DM2                    (* (reg8 *) Chip_Select__DM2) 
/* Input Buffer Disable Override */
#define Chip_Select_INP_DIS                (* (reg8 *) Chip_Select__INP_DIS)
/* LCD Common or Segment Drive */
#define Chip_Select_LCD_COM_SEG            (* (reg8 *) Chip_Select__LCD_COM_SEG)
/* Enable Segment LCD */
#define Chip_Select_LCD_EN                 (* (reg8 *) Chip_Select__LCD_EN)
/* Slew Rate Control */
#define Chip_Select_SLW                    (* (reg8 *) Chip_Select__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Chip_Select_PRTDSI__CAPS_SEL       (* (reg8 *) Chip_Select__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Chip_Select_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Chip_Select__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Chip_Select_PRTDSI__OE_SEL0        (* (reg8 *) Chip_Select__PRTDSI__OE_SEL0) 
#define Chip_Select_PRTDSI__OE_SEL1        (* (reg8 *) Chip_Select__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Chip_Select_PRTDSI__OUT_SEL0       (* (reg8 *) Chip_Select__PRTDSI__OUT_SEL0) 
#define Chip_Select_PRTDSI__OUT_SEL1       (* (reg8 *) Chip_Select__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Chip_Select_PRTDSI__SYNC_OUT       (* (reg8 *) Chip_Select__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Chip_Select__SIO_CFG)
    #define Chip_Select_SIO_HYST_EN        (* (reg8 *) Chip_Select__SIO_HYST_EN)
    #define Chip_Select_SIO_REG_HIFREQ     (* (reg8 *) Chip_Select__SIO_REG_HIFREQ)
    #define Chip_Select_SIO_CFG            (* (reg8 *) Chip_Select__SIO_CFG)
    #define Chip_Select_SIO_DIFF           (* (reg8 *) Chip_Select__SIO_DIFF)
#endif /* (Chip_Select__SIO_CFG) */

/* Interrupt Registers */
#if defined(Chip_Select__INTSTAT)
    #define Chip_Select_INTSTAT            (* (reg8 *) Chip_Select__INTSTAT)
    #define Chip_Select_SNAP               (* (reg8 *) Chip_Select__SNAP)
    
	#define Chip_Select_0_INTTYPE_REG 		(* (reg8 *) Chip_Select__0__INTTYPE)
#endif /* (Chip_Select__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Chip_Select_H */


/* [] END OF FILE */
