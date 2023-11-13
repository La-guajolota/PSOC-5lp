/*******************************************************************************
* File Name: Chipselect.h  
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

#if !defined(CY_PINS_Chipselect_H) /* Pins Chipselect_H */
#define CY_PINS_Chipselect_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Chipselect_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Chipselect__PORT == 15 && ((Chipselect__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Chipselect_Write(uint8 value);
void    Chipselect_SetDriveMode(uint8 mode);
uint8   Chipselect_ReadDataReg(void);
uint8   Chipselect_Read(void);
void    Chipselect_SetInterruptMode(uint16 position, uint16 mode);
uint8   Chipselect_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Chipselect_SetDriveMode() function.
     *  @{
     */
        #define Chipselect_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Chipselect_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Chipselect_DM_RES_UP          PIN_DM_RES_UP
        #define Chipselect_DM_RES_DWN         PIN_DM_RES_DWN
        #define Chipselect_DM_OD_LO           PIN_DM_OD_LO
        #define Chipselect_DM_OD_HI           PIN_DM_OD_HI
        #define Chipselect_DM_STRONG          PIN_DM_STRONG
        #define Chipselect_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Chipselect_MASK               Chipselect__MASK
#define Chipselect_SHIFT              Chipselect__SHIFT
#define Chipselect_WIDTH              1u

/* Interrupt constants */
#if defined(Chipselect__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Chipselect_SetInterruptMode() function.
     *  @{
     */
        #define Chipselect_INTR_NONE      (uint16)(0x0000u)
        #define Chipselect_INTR_RISING    (uint16)(0x0001u)
        #define Chipselect_INTR_FALLING   (uint16)(0x0002u)
        #define Chipselect_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Chipselect_INTR_MASK      (0x01u) 
#endif /* (Chipselect__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Chipselect_PS                     (* (reg8 *) Chipselect__PS)
/* Data Register */
#define Chipselect_DR                     (* (reg8 *) Chipselect__DR)
/* Port Number */
#define Chipselect_PRT_NUM                (* (reg8 *) Chipselect__PRT) 
/* Connect to Analog Globals */                                                  
#define Chipselect_AG                     (* (reg8 *) Chipselect__AG)                       
/* Analog MUX bux enable */
#define Chipselect_AMUX                   (* (reg8 *) Chipselect__AMUX) 
/* Bidirectional Enable */                                                        
#define Chipselect_BIE                    (* (reg8 *) Chipselect__BIE)
/* Bit-mask for Aliased Register Access */
#define Chipselect_BIT_MASK               (* (reg8 *) Chipselect__BIT_MASK)
/* Bypass Enable */
#define Chipselect_BYP                    (* (reg8 *) Chipselect__BYP)
/* Port wide control signals */                                                   
#define Chipselect_CTL                    (* (reg8 *) Chipselect__CTL)
/* Drive Modes */
#define Chipselect_DM0                    (* (reg8 *) Chipselect__DM0) 
#define Chipselect_DM1                    (* (reg8 *) Chipselect__DM1)
#define Chipselect_DM2                    (* (reg8 *) Chipselect__DM2) 
/* Input Buffer Disable Override */
#define Chipselect_INP_DIS                (* (reg8 *) Chipselect__INP_DIS)
/* LCD Common or Segment Drive */
#define Chipselect_LCD_COM_SEG            (* (reg8 *) Chipselect__LCD_COM_SEG)
/* Enable Segment LCD */
#define Chipselect_LCD_EN                 (* (reg8 *) Chipselect__LCD_EN)
/* Slew Rate Control */
#define Chipselect_SLW                    (* (reg8 *) Chipselect__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Chipselect_PRTDSI__CAPS_SEL       (* (reg8 *) Chipselect__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Chipselect_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Chipselect__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Chipselect_PRTDSI__OE_SEL0        (* (reg8 *) Chipselect__PRTDSI__OE_SEL0) 
#define Chipselect_PRTDSI__OE_SEL1        (* (reg8 *) Chipselect__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Chipselect_PRTDSI__OUT_SEL0       (* (reg8 *) Chipselect__PRTDSI__OUT_SEL0) 
#define Chipselect_PRTDSI__OUT_SEL1       (* (reg8 *) Chipselect__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Chipselect_PRTDSI__SYNC_OUT       (* (reg8 *) Chipselect__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Chipselect__SIO_CFG)
    #define Chipselect_SIO_HYST_EN        (* (reg8 *) Chipselect__SIO_HYST_EN)
    #define Chipselect_SIO_REG_HIFREQ     (* (reg8 *) Chipselect__SIO_REG_HIFREQ)
    #define Chipselect_SIO_CFG            (* (reg8 *) Chipselect__SIO_CFG)
    #define Chipselect_SIO_DIFF           (* (reg8 *) Chipselect__SIO_DIFF)
#endif /* (Chipselect__SIO_CFG) */

/* Interrupt Registers */
#if defined(Chipselect__INTSTAT)
    #define Chipselect_INTSTAT            (* (reg8 *) Chipselect__INTSTAT)
    #define Chipselect_SNAP               (* (reg8 *) Chipselect__SNAP)
    
	#define Chipselect_0_INTTYPE_REG 		(* (reg8 *) Chipselect__0__INTTYPE)
#endif /* (Chipselect__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Chipselect_H */


/* [] END OF FILE */
