/*******************************************************************************
* File Name: Dis3.h  
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

#if !defined(CY_PINS_Dis3_H) /* Pins Dis3_H */
#define CY_PINS_Dis3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dis3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dis3__PORT == 15 && ((Dis3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dis3_Write(uint8 value);
void    Dis3_SetDriveMode(uint8 mode);
uint8   Dis3_ReadDataReg(void);
uint8   Dis3_Read(void);
void    Dis3_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dis3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dis3_SetDriveMode() function.
     *  @{
     */
        #define Dis3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dis3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dis3_DM_RES_UP          PIN_DM_RES_UP
        #define Dis3_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dis3_DM_OD_LO           PIN_DM_OD_LO
        #define Dis3_DM_OD_HI           PIN_DM_OD_HI
        #define Dis3_DM_STRONG          PIN_DM_STRONG
        #define Dis3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dis3_MASK               Dis3__MASK
#define Dis3_SHIFT              Dis3__SHIFT
#define Dis3_WIDTH              1u

/* Interrupt constants */
#if defined(Dis3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dis3_SetInterruptMode() function.
     *  @{
     */
        #define Dis3_INTR_NONE      (uint16)(0x0000u)
        #define Dis3_INTR_RISING    (uint16)(0x0001u)
        #define Dis3_INTR_FALLING   (uint16)(0x0002u)
        #define Dis3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dis3_INTR_MASK      (0x01u) 
#endif /* (Dis3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dis3_PS                     (* (reg8 *) Dis3__PS)
/* Data Register */
#define Dis3_DR                     (* (reg8 *) Dis3__DR)
/* Port Number */
#define Dis3_PRT_NUM                (* (reg8 *) Dis3__PRT) 
/* Connect to Analog Globals */                                                  
#define Dis3_AG                     (* (reg8 *) Dis3__AG)                       
/* Analog MUX bux enable */
#define Dis3_AMUX                   (* (reg8 *) Dis3__AMUX) 
/* Bidirectional Enable */                                                        
#define Dis3_BIE                    (* (reg8 *) Dis3__BIE)
/* Bit-mask for Aliased Register Access */
#define Dis3_BIT_MASK               (* (reg8 *) Dis3__BIT_MASK)
/* Bypass Enable */
#define Dis3_BYP                    (* (reg8 *) Dis3__BYP)
/* Port wide control signals */                                                   
#define Dis3_CTL                    (* (reg8 *) Dis3__CTL)
/* Drive Modes */
#define Dis3_DM0                    (* (reg8 *) Dis3__DM0) 
#define Dis3_DM1                    (* (reg8 *) Dis3__DM1)
#define Dis3_DM2                    (* (reg8 *) Dis3__DM2) 
/* Input Buffer Disable Override */
#define Dis3_INP_DIS                (* (reg8 *) Dis3__INP_DIS)
/* LCD Common or Segment Drive */
#define Dis3_LCD_COM_SEG            (* (reg8 *) Dis3__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dis3_LCD_EN                 (* (reg8 *) Dis3__LCD_EN)
/* Slew Rate Control */
#define Dis3_SLW                    (* (reg8 *) Dis3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dis3_PRTDSI__CAPS_SEL       (* (reg8 *) Dis3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dis3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dis3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dis3_PRTDSI__OE_SEL0        (* (reg8 *) Dis3__PRTDSI__OE_SEL0) 
#define Dis3_PRTDSI__OE_SEL1        (* (reg8 *) Dis3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dis3_PRTDSI__OUT_SEL0       (* (reg8 *) Dis3__PRTDSI__OUT_SEL0) 
#define Dis3_PRTDSI__OUT_SEL1       (* (reg8 *) Dis3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dis3_PRTDSI__SYNC_OUT       (* (reg8 *) Dis3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dis3__SIO_CFG)
    #define Dis3_SIO_HYST_EN        (* (reg8 *) Dis3__SIO_HYST_EN)
    #define Dis3_SIO_REG_HIFREQ     (* (reg8 *) Dis3__SIO_REG_HIFREQ)
    #define Dis3_SIO_CFG            (* (reg8 *) Dis3__SIO_CFG)
    #define Dis3_SIO_DIFF           (* (reg8 *) Dis3__SIO_DIFF)
#endif /* (Dis3__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dis3__INTSTAT)
    #define Dis3_INTSTAT            (* (reg8 *) Dis3__INTSTAT)
    #define Dis3_SNAP               (* (reg8 *) Dis3__SNAP)
    
	#define Dis3_0_INTTYPE_REG 		(* (reg8 *) Dis3__0__INTTYPE)
#endif /* (Dis3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dis3_H */


/* [] END OF FILE */
