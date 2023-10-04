/*******************************************************************************
* File Name: Inicio_Paro.h  
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

#if !defined(CY_PINS_Inicio_Paro_H) /* Pins Inicio_Paro_H */
#define CY_PINS_Inicio_Paro_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Inicio_Paro_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Inicio_Paro__PORT == 15 && ((Inicio_Paro__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Inicio_Paro_Write(uint8 value);
void    Inicio_Paro_SetDriveMode(uint8 mode);
uint8   Inicio_Paro_ReadDataReg(void);
uint8   Inicio_Paro_Read(void);
void    Inicio_Paro_SetInterruptMode(uint16 position, uint16 mode);
uint8   Inicio_Paro_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Inicio_Paro_SetDriveMode() function.
     *  @{
     */
        #define Inicio_Paro_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Inicio_Paro_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Inicio_Paro_DM_RES_UP          PIN_DM_RES_UP
        #define Inicio_Paro_DM_RES_DWN         PIN_DM_RES_DWN
        #define Inicio_Paro_DM_OD_LO           PIN_DM_OD_LO
        #define Inicio_Paro_DM_OD_HI           PIN_DM_OD_HI
        #define Inicio_Paro_DM_STRONG          PIN_DM_STRONG
        #define Inicio_Paro_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Inicio_Paro_MASK               Inicio_Paro__MASK
#define Inicio_Paro_SHIFT              Inicio_Paro__SHIFT
#define Inicio_Paro_WIDTH              1u

/* Interrupt constants */
#if defined(Inicio_Paro__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Inicio_Paro_SetInterruptMode() function.
     *  @{
     */
        #define Inicio_Paro_INTR_NONE      (uint16)(0x0000u)
        #define Inicio_Paro_INTR_RISING    (uint16)(0x0001u)
        #define Inicio_Paro_INTR_FALLING   (uint16)(0x0002u)
        #define Inicio_Paro_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Inicio_Paro_INTR_MASK      (0x01u) 
#endif /* (Inicio_Paro__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Inicio_Paro_PS                     (* (reg8 *) Inicio_Paro__PS)
/* Data Register */
#define Inicio_Paro_DR                     (* (reg8 *) Inicio_Paro__DR)
/* Port Number */
#define Inicio_Paro_PRT_NUM                (* (reg8 *) Inicio_Paro__PRT) 
/* Connect to Analog Globals */                                                  
#define Inicio_Paro_AG                     (* (reg8 *) Inicio_Paro__AG)                       
/* Analog MUX bux enable */
#define Inicio_Paro_AMUX                   (* (reg8 *) Inicio_Paro__AMUX) 
/* Bidirectional Enable */                                                        
#define Inicio_Paro_BIE                    (* (reg8 *) Inicio_Paro__BIE)
/* Bit-mask for Aliased Register Access */
#define Inicio_Paro_BIT_MASK               (* (reg8 *) Inicio_Paro__BIT_MASK)
/* Bypass Enable */
#define Inicio_Paro_BYP                    (* (reg8 *) Inicio_Paro__BYP)
/* Port wide control signals */                                                   
#define Inicio_Paro_CTL                    (* (reg8 *) Inicio_Paro__CTL)
/* Drive Modes */
#define Inicio_Paro_DM0                    (* (reg8 *) Inicio_Paro__DM0) 
#define Inicio_Paro_DM1                    (* (reg8 *) Inicio_Paro__DM1)
#define Inicio_Paro_DM2                    (* (reg8 *) Inicio_Paro__DM2) 
/* Input Buffer Disable Override */
#define Inicio_Paro_INP_DIS                (* (reg8 *) Inicio_Paro__INP_DIS)
/* LCD Common or Segment Drive */
#define Inicio_Paro_LCD_COM_SEG            (* (reg8 *) Inicio_Paro__LCD_COM_SEG)
/* Enable Segment LCD */
#define Inicio_Paro_LCD_EN                 (* (reg8 *) Inicio_Paro__LCD_EN)
/* Slew Rate Control */
#define Inicio_Paro_SLW                    (* (reg8 *) Inicio_Paro__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Inicio_Paro_PRTDSI__CAPS_SEL       (* (reg8 *) Inicio_Paro__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Inicio_Paro_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Inicio_Paro__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Inicio_Paro_PRTDSI__OE_SEL0        (* (reg8 *) Inicio_Paro__PRTDSI__OE_SEL0) 
#define Inicio_Paro_PRTDSI__OE_SEL1        (* (reg8 *) Inicio_Paro__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Inicio_Paro_PRTDSI__OUT_SEL0       (* (reg8 *) Inicio_Paro__PRTDSI__OUT_SEL0) 
#define Inicio_Paro_PRTDSI__OUT_SEL1       (* (reg8 *) Inicio_Paro__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Inicio_Paro_PRTDSI__SYNC_OUT       (* (reg8 *) Inicio_Paro__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Inicio_Paro__SIO_CFG)
    #define Inicio_Paro_SIO_HYST_EN        (* (reg8 *) Inicio_Paro__SIO_HYST_EN)
    #define Inicio_Paro_SIO_REG_HIFREQ     (* (reg8 *) Inicio_Paro__SIO_REG_HIFREQ)
    #define Inicio_Paro_SIO_CFG            (* (reg8 *) Inicio_Paro__SIO_CFG)
    #define Inicio_Paro_SIO_DIFF           (* (reg8 *) Inicio_Paro__SIO_DIFF)
#endif /* (Inicio_Paro__SIO_CFG) */

/* Interrupt Registers */
#if defined(Inicio_Paro__INTSTAT)
    #define Inicio_Paro_INTSTAT            (* (reg8 *) Inicio_Paro__INTSTAT)
    #define Inicio_Paro_SNAP               (* (reg8 *) Inicio_Paro__SNAP)
    
	#define Inicio_Paro_0_INTTYPE_REG 		(* (reg8 *) Inicio_Paro__0__INTTYPE)
#endif /* (Inicio_Paro__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Inicio_Paro_H */


/* [] END OF FILE */
