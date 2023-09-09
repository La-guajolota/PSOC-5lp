/*******************************************************************************
* File Name: Dis1.h  
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

#if !defined(CY_PINS_Dis1_H) /* Pins Dis1_H */
#define CY_PINS_Dis1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dis1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dis1__PORT == 15 && ((Dis1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dis1_Write(uint8 value);
void    Dis1_SetDriveMode(uint8 mode);
uint8   Dis1_ReadDataReg(void);
uint8   Dis1_Read(void);
void    Dis1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dis1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dis1_SetDriveMode() function.
     *  @{
     */
        #define Dis1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dis1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dis1_DM_RES_UP          PIN_DM_RES_UP
        #define Dis1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dis1_DM_OD_LO           PIN_DM_OD_LO
        #define Dis1_DM_OD_HI           PIN_DM_OD_HI
        #define Dis1_DM_STRONG          PIN_DM_STRONG
        #define Dis1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dis1_MASK               Dis1__MASK
#define Dis1_SHIFT              Dis1__SHIFT
#define Dis1_WIDTH              1u

/* Interrupt constants */
#if defined(Dis1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dis1_SetInterruptMode() function.
     *  @{
     */
        #define Dis1_INTR_NONE      (uint16)(0x0000u)
        #define Dis1_INTR_RISING    (uint16)(0x0001u)
        #define Dis1_INTR_FALLING   (uint16)(0x0002u)
        #define Dis1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dis1_INTR_MASK      (0x01u) 
#endif /* (Dis1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dis1_PS                     (* (reg8 *) Dis1__PS)
/* Data Register */
#define Dis1_DR                     (* (reg8 *) Dis1__DR)
/* Port Number */
#define Dis1_PRT_NUM                (* (reg8 *) Dis1__PRT) 
/* Connect to Analog Globals */                                                  
#define Dis1_AG                     (* (reg8 *) Dis1__AG)                       
/* Analog MUX bux enable */
#define Dis1_AMUX                   (* (reg8 *) Dis1__AMUX) 
/* Bidirectional Enable */                                                        
#define Dis1_BIE                    (* (reg8 *) Dis1__BIE)
/* Bit-mask for Aliased Register Access */
#define Dis1_BIT_MASK               (* (reg8 *) Dis1__BIT_MASK)
/* Bypass Enable */
#define Dis1_BYP                    (* (reg8 *) Dis1__BYP)
/* Port wide control signals */                                                   
#define Dis1_CTL                    (* (reg8 *) Dis1__CTL)
/* Drive Modes */
#define Dis1_DM0                    (* (reg8 *) Dis1__DM0) 
#define Dis1_DM1                    (* (reg8 *) Dis1__DM1)
#define Dis1_DM2                    (* (reg8 *) Dis1__DM2) 
/* Input Buffer Disable Override */
#define Dis1_INP_DIS                (* (reg8 *) Dis1__INP_DIS)
/* LCD Common or Segment Drive */
#define Dis1_LCD_COM_SEG            (* (reg8 *) Dis1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dis1_LCD_EN                 (* (reg8 *) Dis1__LCD_EN)
/* Slew Rate Control */
#define Dis1_SLW                    (* (reg8 *) Dis1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dis1_PRTDSI__CAPS_SEL       (* (reg8 *) Dis1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dis1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dis1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dis1_PRTDSI__OE_SEL0        (* (reg8 *) Dis1__PRTDSI__OE_SEL0) 
#define Dis1_PRTDSI__OE_SEL1        (* (reg8 *) Dis1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dis1_PRTDSI__OUT_SEL0       (* (reg8 *) Dis1__PRTDSI__OUT_SEL0) 
#define Dis1_PRTDSI__OUT_SEL1       (* (reg8 *) Dis1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dis1_PRTDSI__SYNC_OUT       (* (reg8 *) Dis1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dis1__SIO_CFG)
    #define Dis1_SIO_HYST_EN        (* (reg8 *) Dis1__SIO_HYST_EN)
    #define Dis1_SIO_REG_HIFREQ     (* (reg8 *) Dis1__SIO_REG_HIFREQ)
    #define Dis1_SIO_CFG            (* (reg8 *) Dis1__SIO_CFG)
    #define Dis1_SIO_DIFF           (* (reg8 *) Dis1__SIO_DIFF)
#endif /* (Dis1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dis1__INTSTAT)
    #define Dis1_INTSTAT            (* (reg8 *) Dis1__INTSTAT)
    #define Dis1_SNAP               (* (reg8 *) Dis1__SNAP)
    
	#define Dis1_0_INTTYPE_REG 		(* (reg8 *) Dis1__0__INTTYPE)
#endif /* (Dis1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dis1_H */


/* [] END OF FILE */
