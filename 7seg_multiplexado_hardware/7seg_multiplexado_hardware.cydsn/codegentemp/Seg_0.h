/*******************************************************************************
* File Name: Seg_0.h  
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

#if !defined(CY_PINS_Seg_0_H) /* Pins Seg_0_H */
#define CY_PINS_Seg_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Seg_0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Seg_0__PORT == 15 && ((Seg_0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Seg_0_Write(uint8 value);
void    Seg_0_SetDriveMode(uint8 mode);
uint8   Seg_0_ReadDataReg(void);
uint8   Seg_0_Read(void);
void    Seg_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   Seg_0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Seg_0_SetDriveMode() function.
     *  @{
     */
        #define Seg_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Seg_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Seg_0_DM_RES_UP          PIN_DM_RES_UP
        #define Seg_0_DM_RES_DWN         PIN_DM_RES_DWN
        #define Seg_0_DM_OD_LO           PIN_DM_OD_LO
        #define Seg_0_DM_OD_HI           PIN_DM_OD_HI
        #define Seg_0_DM_STRONG          PIN_DM_STRONG
        #define Seg_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Seg_0_MASK               Seg_0__MASK
#define Seg_0_SHIFT              Seg_0__SHIFT
#define Seg_0_WIDTH              1u

/* Interrupt constants */
#if defined(Seg_0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Seg_0_SetInterruptMode() function.
     *  @{
     */
        #define Seg_0_INTR_NONE      (uint16)(0x0000u)
        #define Seg_0_INTR_RISING    (uint16)(0x0001u)
        #define Seg_0_INTR_FALLING   (uint16)(0x0002u)
        #define Seg_0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Seg_0_INTR_MASK      (0x01u) 
#endif /* (Seg_0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Seg_0_PS                     (* (reg8 *) Seg_0__PS)
/* Data Register */
#define Seg_0_DR                     (* (reg8 *) Seg_0__DR)
/* Port Number */
#define Seg_0_PRT_NUM                (* (reg8 *) Seg_0__PRT) 
/* Connect to Analog Globals */                                                  
#define Seg_0_AG                     (* (reg8 *) Seg_0__AG)                       
/* Analog MUX bux enable */
#define Seg_0_AMUX                   (* (reg8 *) Seg_0__AMUX) 
/* Bidirectional Enable */                                                        
#define Seg_0_BIE                    (* (reg8 *) Seg_0__BIE)
/* Bit-mask for Aliased Register Access */
#define Seg_0_BIT_MASK               (* (reg8 *) Seg_0__BIT_MASK)
/* Bypass Enable */
#define Seg_0_BYP                    (* (reg8 *) Seg_0__BYP)
/* Port wide control signals */                                                   
#define Seg_0_CTL                    (* (reg8 *) Seg_0__CTL)
/* Drive Modes */
#define Seg_0_DM0                    (* (reg8 *) Seg_0__DM0) 
#define Seg_0_DM1                    (* (reg8 *) Seg_0__DM1)
#define Seg_0_DM2                    (* (reg8 *) Seg_0__DM2) 
/* Input Buffer Disable Override */
#define Seg_0_INP_DIS                (* (reg8 *) Seg_0__INP_DIS)
/* LCD Common or Segment Drive */
#define Seg_0_LCD_COM_SEG            (* (reg8 *) Seg_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Seg_0_LCD_EN                 (* (reg8 *) Seg_0__LCD_EN)
/* Slew Rate Control */
#define Seg_0_SLW                    (* (reg8 *) Seg_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Seg_0_PRTDSI__CAPS_SEL       (* (reg8 *) Seg_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Seg_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Seg_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Seg_0_PRTDSI__OE_SEL0        (* (reg8 *) Seg_0__PRTDSI__OE_SEL0) 
#define Seg_0_PRTDSI__OE_SEL1        (* (reg8 *) Seg_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Seg_0_PRTDSI__OUT_SEL0       (* (reg8 *) Seg_0__PRTDSI__OUT_SEL0) 
#define Seg_0_PRTDSI__OUT_SEL1       (* (reg8 *) Seg_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Seg_0_PRTDSI__SYNC_OUT       (* (reg8 *) Seg_0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Seg_0__SIO_CFG)
    #define Seg_0_SIO_HYST_EN        (* (reg8 *) Seg_0__SIO_HYST_EN)
    #define Seg_0_SIO_REG_HIFREQ     (* (reg8 *) Seg_0__SIO_REG_HIFREQ)
    #define Seg_0_SIO_CFG            (* (reg8 *) Seg_0__SIO_CFG)
    #define Seg_0_SIO_DIFF           (* (reg8 *) Seg_0__SIO_DIFF)
#endif /* (Seg_0__SIO_CFG) */

/* Interrupt Registers */
#if defined(Seg_0__INTSTAT)
    #define Seg_0_INTSTAT            (* (reg8 *) Seg_0__INTSTAT)
    #define Seg_0_SNAP               (* (reg8 *) Seg_0__SNAP)
    
	#define Seg_0_0_INTTYPE_REG 		(* (reg8 *) Seg_0__0__INTTYPE)
#endif /* (Seg_0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Seg_0_H */


/* [] END OF FILE */
