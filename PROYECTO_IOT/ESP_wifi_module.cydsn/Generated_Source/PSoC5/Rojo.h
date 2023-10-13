/*******************************************************************************
* File Name: Rojo.h  
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

#if !defined(CY_PINS_Rojo_H) /* Pins Rojo_H */
#define CY_PINS_Rojo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rojo_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Rojo__PORT == 15 && ((Rojo__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Rojo_Write(uint8 value);
void    Rojo_SetDriveMode(uint8 mode);
uint8   Rojo_ReadDataReg(void);
uint8   Rojo_Read(void);
void    Rojo_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rojo_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Rojo_SetDriveMode() function.
     *  @{
     */
        #define Rojo_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Rojo_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Rojo_DM_RES_UP          PIN_DM_RES_UP
        #define Rojo_DM_RES_DWN         PIN_DM_RES_DWN
        #define Rojo_DM_OD_LO           PIN_DM_OD_LO
        #define Rojo_DM_OD_HI           PIN_DM_OD_HI
        #define Rojo_DM_STRONG          PIN_DM_STRONG
        #define Rojo_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Rojo_MASK               Rojo__MASK
#define Rojo_SHIFT              Rojo__SHIFT
#define Rojo_WIDTH              1u

/* Interrupt constants */
#if defined(Rojo__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rojo_SetInterruptMode() function.
     *  @{
     */
        #define Rojo_INTR_NONE      (uint16)(0x0000u)
        #define Rojo_INTR_RISING    (uint16)(0x0001u)
        #define Rojo_INTR_FALLING   (uint16)(0x0002u)
        #define Rojo_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Rojo_INTR_MASK      (0x01u) 
#endif /* (Rojo__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rojo_PS                     (* (reg8 *) Rojo__PS)
/* Data Register */
#define Rojo_DR                     (* (reg8 *) Rojo__DR)
/* Port Number */
#define Rojo_PRT_NUM                (* (reg8 *) Rojo__PRT) 
/* Connect to Analog Globals */                                                  
#define Rojo_AG                     (* (reg8 *) Rojo__AG)                       
/* Analog MUX bux enable */
#define Rojo_AMUX                   (* (reg8 *) Rojo__AMUX) 
/* Bidirectional Enable */                                                        
#define Rojo_BIE                    (* (reg8 *) Rojo__BIE)
/* Bit-mask for Aliased Register Access */
#define Rojo_BIT_MASK               (* (reg8 *) Rojo__BIT_MASK)
/* Bypass Enable */
#define Rojo_BYP                    (* (reg8 *) Rojo__BYP)
/* Port wide control signals */                                                   
#define Rojo_CTL                    (* (reg8 *) Rojo__CTL)
/* Drive Modes */
#define Rojo_DM0                    (* (reg8 *) Rojo__DM0) 
#define Rojo_DM1                    (* (reg8 *) Rojo__DM1)
#define Rojo_DM2                    (* (reg8 *) Rojo__DM2) 
/* Input Buffer Disable Override */
#define Rojo_INP_DIS                (* (reg8 *) Rojo__INP_DIS)
/* LCD Common or Segment Drive */
#define Rojo_LCD_COM_SEG            (* (reg8 *) Rojo__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rojo_LCD_EN                 (* (reg8 *) Rojo__LCD_EN)
/* Slew Rate Control */
#define Rojo_SLW                    (* (reg8 *) Rojo__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rojo_PRTDSI__CAPS_SEL       (* (reg8 *) Rojo__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rojo_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rojo__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rojo_PRTDSI__OE_SEL0        (* (reg8 *) Rojo__PRTDSI__OE_SEL0) 
#define Rojo_PRTDSI__OE_SEL1        (* (reg8 *) Rojo__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rojo_PRTDSI__OUT_SEL0       (* (reg8 *) Rojo__PRTDSI__OUT_SEL0) 
#define Rojo_PRTDSI__OUT_SEL1       (* (reg8 *) Rojo__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rojo_PRTDSI__SYNC_OUT       (* (reg8 *) Rojo__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Rojo__SIO_CFG)
    #define Rojo_SIO_HYST_EN        (* (reg8 *) Rojo__SIO_HYST_EN)
    #define Rojo_SIO_REG_HIFREQ     (* (reg8 *) Rojo__SIO_REG_HIFREQ)
    #define Rojo_SIO_CFG            (* (reg8 *) Rojo__SIO_CFG)
    #define Rojo_SIO_DIFF           (* (reg8 *) Rojo__SIO_DIFF)
#endif /* (Rojo__SIO_CFG) */

/* Interrupt Registers */
#if defined(Rojo__INTSTAT)
    #define Rojo_INTSTAT            (* (reg8 *) Rojo__INTSTAT)
    #define Rojo_SNAP               (* (reg8 *) Rojo__SNAP)
    
	#define Rojo_0_INTTYPE_REG 		(* (reg8 *) Rojo__0__INTTYPE)
#endif /* (Rojo__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Rojo_H */


/* [] END OF FILE */
