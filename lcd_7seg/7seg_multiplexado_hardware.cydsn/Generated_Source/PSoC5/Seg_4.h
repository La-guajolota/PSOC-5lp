/*******************************************************************************
* File Name: Seg_4.h  
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

#if !defined(CY_PINS_Seg_4_H) /* Pins Seg_4_H */
#define CY_PINS_Seg_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Seg_4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Seg_4__PORT == 15 && ((Seg_4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Seg_4_Write(uint8 value);
void    Seg_4_SetDriveMode(uint8 mode);
uint8   Seg_4_ReadDataReg(void);
uint8   Seg_4_Read(void);
void    Seg_4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Seg_4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Seg_4_SetDriveMode() function.
     *  @{
     */
        #define Seg_4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Seg_4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Seg_4_DM_RES_UP          PIN_DM_RES_UP
        #define Seg_4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Seg_4_DM_OD_LO           PIN_DM_OD_LO
        #define Seg_4_DM_OD_HI           PIN_DM_OD_HI
        #define Seg_4_DM_STRONG          PIN_DM_STRONG
        #define Seg_4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Seg_4_MASK               Seg_4__MASK
#define Seg_4_SHIFT              Seg_4__SHIFT
#define Seg_4_WIDTH              1u

/* Interrupt constants */
#if defined(Seg_4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Seg_4_SetInterruptMode() function.
     *  @{
     */
        #define Seg_4_INTR_NONE      (uint16)(0x0000u)
        #define Seg_4_INTR_RISING    (uint16)(0x0001u)
        #define Seg_4_INTR_FALLING   (uint16)(0x0002u)
        #define Seg_4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Seg_4_INTR_MASK      (0x01u) 
#endif /* (Seg_4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Seg_4_PS                     (* (reg8 *) Seg_4__PS)
/* Data Register */
#define Seg_4_DR                     (* (reg8 *) Seg_4__DR)
/* Port Number */
#define Seg_4_PRT_NUM                (* (reg8 *) Seg_4__PRT) 
/* Connect to Analog Globals */                                                  
#define Seg_4_AG                     (* (reg8 *) Seg_4__AG)                       
/* Analog MUX bux enable */
#define Seg_4_AMUX                   (* (reg8 *) Seg_4__AMUX) 
/* Bidirectional Enable */                                                        
#define Seg_4_BIE                    (* (reg8 *) Seg_4__BIE)
/* Bit-mask for Aliased Register Access */
#define Seg_4_BIT_MASK               (* (reg8 *) Seg_4__BIT_MASK)
/* Bypass Enable */
#define Seg_4_BYP                    (* (reg8 *) Seg_4__BYP)
/* Port wide control signals */                                                   
#define Seg_4_CTL                    (* (reg8 *) Seg_4__CTL)
/* Drive Modes */
#define Seg_4_DM0                    (* (reg8 *) Seg_4__DM0) 
#define Seg_4_DM1                    (* (reg8 *) Seg_4__DM1)
#define Seg_4_DM2                    (* (reg8 *) Seg_4__DM2) 
/* Input Buffer Disable Override */
#define Seg_4_INP_DIS                (* (reg8 *) Seg_4__INP_DIS)
/* LCD Common or Segment Drive */
#define Seg_4_LCD_COM_SEG            (* (reg8 *) Seg_4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Seg_4_LCD_EN                 (* (reg8 *) Seg_4__LCD_EN)
/* Slew Rate Control */
#define Seg_4_SLW                    (* (reg8 *) Seg_4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Seg_4_PRTDSI__CAPS_SEL       (* (reg8 *) Seg_4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Seg_4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Seg_4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Seg_4_PRTDSI__OE_SEL0        (* (reg8 *) Seg_4__PRTDSI__OE_SEL0) 
#define Seg_4_PRTDSI__OE_SEL1        (* (reg8 *) Seg_4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Seg_4_PRTDSI__OUT_SEL0       (* (reg8 *) Seg_4__PRTDSI__OUT_SEL0) 
#define Seg_4_PRTDSI__OUT_SEL1       (* (reg8 *) Seg_4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Seg_4_PRTDSI__SYNC_OUT       (* (reg8 *) Seg_4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Seg_4__SIO_CFG)
    #define Seg_4_SIO_HYST_EN        (* (reg8 *) Seg_4__SIO_HYST_EN)
    #define Seg_4_SIO_REG_HIFREQ     (* (reg8 *) Seg_4__SIO_REG_HIFREQ)
    #define Seg_4_SIO_CFG            (* (reg8 *) Seg_4__SIO_CFG)
    #define Seg_4_SIO_DIFF           (* (reg8 *) Seg_4__SIO_DIFF)
#endif /* (Seg_4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Seg_4__INTSTAT)
    #define Seg_4_INTSTAT            (* (reg8 *) Seg_4__INTSTAT)
    #define Seg_4_SNAP               (* (reg8 *) Seg_4__SNAP)
    
	#define Seg_4_0_INTTYPE_REG 		(* (reg8 *) Seg_4__0__INTTYPE)
#endif /* (Seg_4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Seg_4_H */


/* [] END OF FILE */
