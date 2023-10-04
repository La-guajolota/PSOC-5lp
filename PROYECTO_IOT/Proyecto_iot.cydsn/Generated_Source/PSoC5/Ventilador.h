/*******************************************************************************
* File Name: Ventilador.h  
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

#if !defined(CY_PINS_Ventilador_H) /* Pins Ventilador_H */
#define CY_PINS_Ventilador_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Ventilador_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Ventilador__PORT == 15 && ((Ventilador__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Ventilador_Write(uint8 value);
void    Ventilador_SetDriveMode(uint8 mode);
uint8   Ventilador_ReadDataReg(void);
uint8   Ventilador_Read(void);
void    Ventilador_SetInterruptMode(uint16 position, uint16 mode);
uint8   Ventilador_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Ventilador_SetDriveMode() function.
     *  @{
     */
        #define Ventilador_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Ventilador_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Ventilador_DM_RES_UP          PIN_DM_RES_UP
        #define Ventilador_DM_RES_DWN         PIN_DM_RES_DWN
        #define Ventilador_DM_OD_LO           PIN_DM_OD_LO
        #define Ventilador_DM_OD_HI           PIN_DM_OD_HI
        #define Ventilador_DM_STRONG          PIN_DM_STRONG
        #define Ventilador_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Ventilador_MASK               Ventilador__MASK
#define Ventilador_SHIFT              Ventilador__SHIFT
#define Ventilador_WIDTH              1u

/* Interrupt constants */
#if defined(Ventilador__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Ventilador_SetInterruptMode() function.
     *  @{
     */
        #define Ventilador_INTR_NONE      (uint16)(0x0000u)
        #define Ventilador_INTR_RISING    (uint16)(0x0001u)
        #define Ventilador_INTR_FALLING   (uint16)(0x0002u)
        #define Ventilador_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Ventilador_INTR_MASK      (0x01u) 
#endif /* (Ventilador__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ventilador_PS                     (* (reg8 *) Ventilador__PS)
/* Data Register */
#define Ventilador_DR                     (* (reg8 *) Ventilador__DR)
/* Port Number */
#define Ventilador_PRT_NUM                (* (reg8 *) Ventilador__PRT) 
/* Connect to Analog Globals */                                                  
#define Ventilador_AG                     (* (reg8 *) Ventilador__AG)                       
/* Analog MUX bux enable */
#define Ventilador_AMUX                   (* (reg8 *) Ventilador__AMUX) 
/* Bidirectional Enable */                                                        
#define Ventilador_BIE                    (* (reg8 *) Ventilador__BIE)
/* Bit-mask for Aliased Register Access */
#define Ventilador_BIT_MASK               (* (reg8 *) Ventilador__BIT_MASK)
/* Bypass Enable */
#define Ventilador_BYP                    (* (reg8 *) Ventilador__BYP)
/* Port wide control signals */                                                   
#define Ventilador_CTL                    (* (reg8 *) Ventilador__CTL)
/* Drive Modes */
#define Ventilador_DM0                    (* (reg8 *) Ventilador__DM0) 
#define Ventilador_DM1                    (* (reg8 *) Ventilador__DM1)
#define Ventilador_DM2                    (* (reg8 *) Ventilador__DM2) 
/* Input Buffer Disable Override */
#define Ventilador_INP_DIS                (* (reg8 *) Ventilador__INP_DIS)
/* LCD Common or Segment Drive */
#define Ventilador_LCD_COM_SEG            (* (reg8 *) Ventilador__LCD_COM_SEG)
/* Enable Segment LCD */
#define Ventilador_LCD_EN                 (* (reg8 *) Ventilador__LCD_EN)
/* Slew Rate Control */
#define Ventilador_SLW                    (* (reg8 *) Ventilador__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Ventilador_PRTDSI__CAPS_SEL       (* (reg8 *) Ventilador__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Ventilador_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Ventilador__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Ventilador_PRTDSI__OE_SEL0        (* (reg8 *) Ventilador__PRTDSI__OE_SEL0) 
#define Ventilador_PRTDSI__OE_SEL1        (* (reg8 *) Ventilador__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Ventilador_PRTDSI__OUT_SEL0       (* (reg8 *) Ventilador__PRTDSI__OUT_SEL0) 
#define Ventilador_PRTDSI__OUT_SEL1       (* (reg8 *) Ventilador__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Ventilador_PRTDSI__SYNC_OUT       (* (reg8 *) Ventilador__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Ventilador__SIO_CFG)
    #define Ventilador_SIO_HYST_EN        (* (reg8 *) Ventilador__SIO_HYST_EN)
    #define Ventilador_SIO_REG_HIFREQ     (* (reg8 *) Ventilador__SIO_REG_HIFREQ)
    #define Ventilador_SIO_CFG            (* (reg8 *) Ventilador__SIO_CFG)
    #define Ventilador_SIO_DIFF           (* (reg8 *) Ventilador__SIO_DIFF)
#endif /* (Ventilador__SIO_CFG) */

/* Interrupt Registers */
#if defined(Ventilador__INTSTAT)
    #define Ventilador_INTSTAT            (* (reg8 *) Ventilador__INTSTAT)
    #define Ventilador_SNAP               (* (reg8 *) Ventilador__SNAP)
    
	#define Ventilador_0_INTTYPE_REG 		(* (reg8 *) Ventilador__0__INTTYPE)
#endif /* (Ventilador__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Ventilador_H */


/* [] END OF FILE */
