/*******************************************************************************
* File Name: Naranja.h  
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

#if !defined(CY_PINS_Naranja_H) /* Pins Naranja_H */
#define CY_PINS_Naranja_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Naranja_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Naranja__PORT == 15 && ((Naranja__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Naranja_Write(uint8 value);
void    Naranja_SetDriveMode(uint8 mode);
uint8   Naranja_ReadDataReg(void);
uint8   Naranja_Read(void);
void    Naranja_SetInterruptMode(uint16 position, uint16 mode);
uint8   Naranja_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Naranja_SetDriveMode() function.
     *  @{
     */
        #define Naranja_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Naranja_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Naranja_DM_RES_UP          PIN_DM_RES_UP
        #define Naranja_DM_RES_DWN         PIN_DM_RES_DWN
        #define Naranja_DM_OD_LO           PIN_DM_OD_LO
        #define Naranja_DM_OD_HI           PIN_DM_OD_HI
        #define Naranja_DM_STRONG          PIN_DM_STRONG
        #define Naranja_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Naranja_MASK               Naranja__MASK
#define Naranja_SHIFT              Naranja__SHIFT
#define Naranja_WIDTH              1u

/* Interrupt constants */
#if defined(Naranja__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Naranja_SetInterruptMode() function.
     *  @{
     */
        #define Naranja_INTR_NONE      (uint16)(0x0000u)
        #define Naranja_INTR_RISING    (uint16)(0x0001u)
        #define Naranja_INTR_FALLING   (uint16)(0x0002u)
        #define Naranja_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Naranja_INTR_MASK      (0x01u) 
#endif /* (Naranja__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Naranja_PS                     (* (reg8 *) Naranja__PS)
/* Data Register */
#define Naranja_DR                     (* (reg8 *) Naranja__DR)
/* Port Number */
#define Naranja_PRT_NUM                (* (reg8 *) Naranja__PRT) 
/* Connect to Analog Globals */                                                  
#define Naranja_AG                     (* (reg8 *) Naranja__AG)                       
/* Analog MUX bux enable */
#define Naranja_AMUX                   (* (reg8 *) Naranja__AMUX) 
/* Bidirectional Enable */                                                        
#define Naranja_BIE                    (* (reg8 *) Naranja__BIE)
/* Bit-mask for Aliased Register Access */
#define Naranja_BIT_MASK               (* (reg8 *) Naranja__BIT_MASK)
/* Bypass Enable */
#define Naranja_BYP                    (* (reg8 *) Naranja__BYP)
/* Port wide control signals */                                                   
#define Naranja_CTL                    (* (reg8 *) Naranja__CTL)
/* Drive Modes */
#define Naranja_DM0                    (* (reg8 *) Naranja__DM0) 
#define Naranja_DM1                    (* (reg8 *) Naranja__DM1)
#define Naranja_DM2                    (* (reg8 *) Naranja__DM2) 
/* Input Buffer Disable Override */
#define Naranja_INP_DIS                (* (reg8 *) Naranja__INP_DIS)
/* LCD Common or Segment Drive */
#define Naranja_LCD_COM_SEG            (* (reg8 *) Naranja__LCD_COM_SEG)
/* Enable Segment LCD */
#define Naranja_LCD_EN                 (* (reg8 *) Naranja__LCD_EN)
/* Slew Rate Control */
#define Naranja_SLW                    (* (reg8 *) Naranja__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Naranja_PRTDSI__CAPS_SEL       (* (reg8 *) Naranja__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Naranja_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Naranja__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Naranja_PRTDSI__OE_SEL0        (* (reg8 *) Naranja__PRTDSI__OE_SEL0) 
#define Naranja_PRTDSI__OE_SEL1        (* (reg8 *) Naranja__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Naranja_PRTDSI__OUT_SEL0       (* (reg8 *) Naranja__PRTDSI__OUT_SEL0) 
#define Naranja_PRTDSI__OUT_SEL1       (* (reg8 *) Naranja__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Naranja_PRTDSI__SYNC_OUT       (* (reg8 *) Naranja__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Naranja__SIO_CFG)
    #define Naranja_SIO_HYST_EN        (* (reg8 *) Naranja__SIO_HYST_EN)
    #define Naranja_SIO_REG_HIFREQ     (* (reg8 *) Naranja__SIO_REG_HIFREQ)
    #define Naranja_SIO_CFG            (* (reg8 *) Naranja__SIO_CFG)
    #define Naranja_SIO_DIFF           (* (reg8 *) Naranja__SIO_DIFF)
#endif /* (Naranja__SIO_CFG) */

/* Interrupt Registers */
#if defined(Naranja__INTSTAT)
    #define Naranja_INTSTAT            (* (reg8 *) Naranja__INTSTAT)
    #define Naranja_SNAP               (* (reg8 *) Naranja__SNAP)
    
	#define Naranja_0_INTTYPE_REG 		(* (reg8 *) Naranja__0__INTTYPE)
#endif /* (Naranja__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Naranja_H */


/* [] END OF FILE */
