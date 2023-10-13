/*******************************************************************************
* File Name: Azul.h  
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

#if !defined(CY_PINS_Azul_H) /* Pins Azul_H */
#define CY_PINS_Azul_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Azul_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Azul__PORT == 15 && ((Azul__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Azul_Write(uint8 value);
void    Azul_SetDriveMode(uint8 mode);
uint8   Azul_ReadDataReg(void);
uint8   Azul_Read(void);
void    Azul_SetInterruptMode(uint16 position, uint16 mode);
uint8   Azul_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Azul_SetDriveMode() function.
     *  @{
     */
        #define Azul_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Azul_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Azul_DM_RES_UP          PIN_DM_RES_UP
        #define Azul_DM_RES_DWN         PIN_DM_RES_DWN
        #define Azul_DM_OD_LO           PIN_DM_OD_LO
        #define Azul_DM_OD_HI           PIN_DM_OD_HI
        #define Azul_DM_STRONG          PIN_DM_STRONG
        #define Azul_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Azul_MASK               Azul__MASK
#define Azul_SHIFT              Azul__SHIFT
#define Azul_WIDTH              1u

/* Interrupt constants */
#if defined(Azul__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Azul_SetInterruptMode() function.
     *  @{
     */
        #define Azul_INTR_NONE      (uint16)(0x0000u)
        #define Azul_INTR_RISING    (uint16)(0x0001u)
        #define Azul_INTR_FALLING   (uint16)(0x0002u)
        #define Azul_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Azul_INTR_MASK      (0x01u) 
#endif /* (Azul__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Azul_PS                     (* (reg8 *) Azul__PS)
/* Data Register */
#define Azul_DR                     (* (reg8 *) Azul__DR)
/* Port Number */
#define Azul_PRT_NUM                (* (reg8 *) Azul__PRT) 
/* Connect to Analog Globals */                                                  
#define Azul_AG                     (* (reg8 *) Azul__AG)                       
/* Analog MUX bux enable */
#define Azul_AMUX                   (* (reg8 *) Azul__AMUX) 
/* Bidirectional Enable */                                                        
#define Azul_BIE                    (* (reg8 *) Azul__BIE)
/* Bit-mask for Aliased Register Access */
#define Azul_BIT_MASK               (* (reg8 *) Azul__BIT_MASK)
/* Bypass Enable */
#define Azul_BYP                    (* (reg8 *) Azul__BYP)
/* Port wide control signals */                                                   
#define Azul_CTL                    (* (reg8 *) Azul__CTL)
/* Drive Modes */
#define Azul_DM0                    (* (reg8 *) Azul__DM0) 
#define Azul_DM1                    (* (reg8 *) Azul__DM1)
#define Azul_DM2                    (* (reg8 *) Azul__DM2) 
/* Input Buffer Disable Override */
#define Azul_INP_DIS                (* (reg8 *) Azul__INP_DIS)
/* LCD Common or Segment Drive */
#define Azul_LCD_COM_SEG            (* (reg8 *) Azul__LCD_COM_SEG)
/* Enable Segment LCD */
#define Azul_LCD_EN                 (* (reg8 *) Azul__LCD_EN)
/* Slew Rate Control */
#define Azul_SLW                    (* (reg8 *) Azul__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Azul_PRTDSI__CAPS_SEL       (* (reg8 *) Azul__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Azul_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Azul__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Azul_PRTDSI__OE_SEL0        (* (reg8 *) Azul__PRTDSI__OE_SEL0) 
#define Azul_PRTDSI__OE_SEL1        (* (reg8 *) Azul__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Azul_PRTDSI__OUT_SEL0       (* (reg8 *) Azul__PRTDSI__OUT_SEL0) 
#define Azul_PRTDSI__OUT_SEL1       (* (reg8 *) Azul__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Azul_PRTDSI__SYNC_OUT       (* (reg8 *) Azul__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Azul__SIO_CFG)
    #define Azul_SIO_HYST_EN        (* (reg8 *) Azul__SIO_HYST_EN)
    #define Azul_SIO_REG_HIFREQ     (* (reg8 *) Azul__SIO_REG_HIFREQ)
    #define Azul_SIO_CFG            (* (reg8 *) Azul__SIO_CFG)
    #define Azul_SIO_DIFF           (* (reg8 *) Azul__SIO_DIFF)
#endif /* (Azul__SIO_CFG) */

/* Interrupt Registers */
#if defined(Azul__INTSTAT)
    #define Azul_INTSTAT            (* (reg8 *) Azul__INTSTAT)
    #define Azul_SNAP               (* (reg8 *) Azul__SNAP)
    
	#define Azul_0_INTTYPE_REG 		(* (reg8 *) Azul__0__INTTYPE)
#endif /* (Azul__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Azul_H */


/* [] END OF FILE */
