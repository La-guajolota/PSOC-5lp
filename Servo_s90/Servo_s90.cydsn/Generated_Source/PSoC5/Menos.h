/*******************************************************************************
* File Name: Menos.h  
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

#if !defined(CY_PINS_Menos_H) /* Pins Menos_H */
#define CY_PINS_Menos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Menos_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Menos__PORT == 15 && ((Menos__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Menos_Write(uint8 value);
void    Menos_SetDriveMode(uint8 mode);
uint8   Menos_ReadDataReg(void);
uint8   Menos_Read(void);
void    Menos_SetInterruptMode(uint16 position, uint16 mode);
uint8   Menos_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Menos_SetDriveMode() function.
     *  @{
     */
        #define Menos_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Menos_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Menos_DM_RES_UP          PIN_DM_RES_UP
        #define Menos_DM_RES_DWN         PIN_DM_RES_DWN
        #define Menos_DM_OD_LO           PIN_DM_OD_LO
        #define Menos_DM_OD_HI           PIN_DM_OD_HI
        #define Menos_DM_STRONG          PIN_DM_STRONG
        #define Menos_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Menos_MASK               Menos__MASK
#define Menos_SHIFT              Menos__SHIFT
#define Menos_WIDTH              1u

/* Interrupt constants */
#if defined(Menos__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Menos_SetInterruptMode() function.
     *  @{
     */
        #define Menos_INTR_NONE      (uint16)(0x0000u)
        #define Menos_INTR_RISING    (uint16)(0x0001u)
        #define Menos_INTR_FALLING   (uint16)(0x0002u)
        #define Menos_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Menos_INTR_MASK      (0x01u) 
#endif /* (Menos__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Menos_PS                     (* (reg8 *) Menos__PS)
/* Data Register */
#define Menos_DR                     (* (reg8 *) Menos__DR)
/* Port Number */
#define Menos_PRT_NUM                (* (reg8 *) Menos__PRT) 
/* Connect to Analog Globals */                                                  
#define Menos_AG                     (* (reg8 *) Menos__AG)                       
/* Analog MUX bux enable */
#define Menos_AMUX                   (* (reg8 *) Menos__AMUX) 
/* Bidirectional Enable */                                                        
#define Menos_BIE                    (* (reg8 *) Menos__BIE)
/* Bit-mask for Aliased Register Access */
#define Menos_BIT_MASK               (* (reg8 *) Menos__BIT_MASK)
/* Bypass Enable */
#define Menos_BYP                    (* (reg8 *) Menos__BYP)
/* Port wide control signals */                                                   
#define Menos_CTL                    (* (reg8 *) Menos__CTL)
/* Drive Modes */
#define Menos_DM0                    (* (reg8 *) Menos__DM0) 
#define Menos_DM1                    (* (reg8 *) Menos__DM1)
#define Menos_DM2                    (* (reg8 *) Menos__DM2) 
/* Input Buffer Disable Override */
#define Menos_INP_DIS                (* (reg8 *) Menos__INP_DIS)
/* LCD Common or Segment Drive */
#define Menos_LCD_COM_SEG            (* (reg8 *) Menos__LCD_COM_SEG)
/* Enable Segment LCD */
#define Menos_LCD_EN                 (* (reg8 *) Menos__LCD_EN)
/* Slew Rate Control */
#define Menos_SLW                    (* (reg8 *) Menos__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Menos_PRTDSI__CAPS_SEL       (* (reg8 *) Menos__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Menos_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Menos__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Menos_PRTDSI__OE_SEL0        (* (reg8 *) Menos__PRTDSI__OE_SEL0) 
#define Menos_PRTDSI__OE_SEL1        (* (reg8 *) Menos__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Menos_PRTDSI__OUT_SEL0       (* (reg8 *) Menos__PRTDSI__OUT_SEL0) 
#define Menos_PRTDSI__OUT_SEL1       (* (reg8 *) Menos__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Menos_PRTDSI__SYNC_OUT       (* (reg8 *) Menos__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Menos__SIO_CFG)
    #define Menos_SIO_HYST_EN        (* (reg8 *) Menos__SIO_HYST_EN)
    #define Menos_SIO_REG_HIFREQ     (* (reg8 *) Menos__SIO_REG_HIFREQ)
    #define Menos_SIO_CFG            (* (reg8 *) Menos__SIO_CFG)
    #define Menos_SIO_DIFF           (* (reg8 *) Menos__SIO_DIFF)
#endif /* (Menos__SIO_CFG) */

/* Interrupt Registers */
#if defined(Menos__INTSTAT)
    #define Menos_INTSTAT            (* (reg8 *) Menos__INTSTAT)
    #define Menos_SNAP               (* (reg8 *) Menos__SNAP)
    
	#define Menos_0_INTTYPE_REG 		(* (reg8 *) Menos__0__INTTYPE)
#endif /* (Menos__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Menos_H */


/* [] END OF FILE */
