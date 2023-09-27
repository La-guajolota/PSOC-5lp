/*******************************************************************************
* File Name: Analog_input.h  
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

#if !defined(CY_PINS_Analog_input_H) /* Pins Analog_input_H */
#define CY_PINS_Analog_input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Analog_input_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Analog_input__PORT == 15 && ((Analog_input__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Analog_input_Write(uint8 value);
void    Analog_input_SetDriveMode(uint8 mode);
uint8   Analog_input_ReadDataReg(void);
uint8   Analog_input_Read(void);
void    Analog_input_SetInterruptMode(uint16 position, uint16 mode);
uint8   Analog_input_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Analog_input_SetDriveMode() function.
     *  @{
     */
        #define Analog_input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Analog_input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Analog_input_DM_RES_UP          PIN_DM_RES_UP
        #define Analog_input_DM_RES_DWN         PIN_DM_RES_DWN
        #define Analog_input_DM_OD_LO           PIN_DM_OD_LO
        #define Analog_input_DM_OD_HI           PIN_DM_OD_HI
        #define Analog_input_DM_STRONG          PIN_DM_STRONG
        #define Analog_input_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Analog_input_MASK               Analog_input__MASK
#define Analog_input_SHIFT              Analog_input__SHIFT
#define Analog_input_WIDTH              1u

/* Interrupt constants */
#if defined(Analog_input__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Analog_input_SetInterruptMode() function.
     *  @{
     */
        #define Analog_input_INTR_NONE      (uint16)(0x0000u)
        #define Analog_input_INTR_RISING    (uint16)(0x0001u)
        #define Analog_input_INTR_FALLING   (uint16)(0x0002u)
        #define Analog_input_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Analog_input_INTR_MASK      (0x01u) 
#endif /* (Analog_input__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Analog_input_PS                     (* (reg8 *) Analog_input__PS)
/* Data Register */
#define Analog_input_DR                     (* (reg8 *) Analog_input__DR)
/* Port Number */
#define Analog_input_PRT_NUM                (* (reg8 *) Analog_input__PRT) 
/* Connect to Analog Globals */                                                  
#define Analog_input_AG                     (* (reg8 *) Analog_input__AG)                       
/* Analog MUX bux enable */
#define Analog_input_AMUX                   (* (reg8 *) Analog_input__AMUX) 
/* Bidirectional Enable */                                                        
#define Analog_input_BIE                    (* (reg8 *) Analog_input__BIE)
/* Bit-mask for Aliased Register Access */
#define Analog_input_BIT_MASK               (* (reg8 *) Analog_input__BIT_MASK)
/* Bypass Enable */
#define Analog_input_BYP                    (* (reg8 *) Analog_input__BYP)
/* Port wide control signals */                                                   
#define Analog_input_CTL                    (* (reg8 *) Analog_input__CTL)
/* Drive Modes */
#define Analog_input_DM0                    (* (reg8 *) Analog_input__DM0) 
#define Analog_input_DM1                    (* (reg8 *) Analog_input__DM1)
#define Analog_input_DM2                    (* (reg8 *) Analog_input__DM2) 
/* Input Buffer Disable Override */
#define Analog_input_INP_DIS                (* (reg8 *) Analog_input__INP_DIS)
/* LCD Common or Segment Drive */
#define Analog_input_LCD_COM_SEG            (* (reg8 *) Analog_input__LCD_COM_SEG)
/* Enable Segment LCD */
#define Analog_input_LCD_EN                 (* (reg8 *) Analog_input__LCD_EN)
/* Slew Rate Control */
#define Analog_input_SLW                    (* (reg8 *) Analog_input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Analog_input_PRTDSI__CAPS_SEL       (* (reg8 *) Analog_input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Analog_input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Analog_input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Analog_input_PRTDSI__OE_SEL0        (* (reg8 *) Analog_input__PRTDSI__OE_SEL0) 
#define Analog_input_PRTDSI__OE_SEL1        (* (reg8 *) Analog_input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Analog_input_PRTDSI__OUT_SEL0       (* (reg8 *) Analog_input__PRTDSI__OUT_SEL0) 
#define Analog_input_PRTDSI__OUT_SEL1       (* (reg8 *) Analog_input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Analog_input_PRTDSI__SYNC_OUT       (* (reg8 *) Analog_input__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Analog_input__SIO_CFG)
    #define Analog_input_SIO_HYST_EN        (* (reg8 *) Analog_input__SIO_HYST_EN)
    #define Analog_input_SIO_REG_HIFREQ     (* (reg8 *) Analog_input__SIO_REG_HIFREQ)
    #define Analog_input_SIO_CFG            (* (reg8 *) Analog_input__SIO_CFG)
    #define Analog_input_SIO_DIFF           (* (reg8 *) Analog_input__SIO_DIFF)
#endif /* (Analog_input__SIO_CFG) */

/* Interrupt Registers */
#if defined(Analog_input__INTSTAT)
    #define Analog_input_INTSTAT            (* (reg8 *) Analog_input__INTSTAT)
    #define Analog_input_SNAP               (* (reg8 *) Analog_input__SNAP)
    
	#define Analog_input_0_INTTYPE_REG 		(* (reg8 *) Analog_input__0__INTTYPE)
#endif /* (Analog_input__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Analog_input_H */


/* [] END OF FILE */
