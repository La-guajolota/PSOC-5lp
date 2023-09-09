/*******************************************************************************
* File Name: Dis2.h  
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

#if !defined(CY_PINS_Dis2_H) /* Pins Dis2_H */
#define CY_PINS_Dis2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dis2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dis2__PORT == 15 && ((Dis2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dis2_Write(uint8 value);
void    Dis2_SetDriveMode(uint8 mode);
uint8   Dis2_ReadDataReg(void);
uint8   Dis2_Read(void);
void    Dis2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dis2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dis2_SetDriveMode() function.
     *  @{
     */
        #define Dis2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dis2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dis2_DM_RES_UP          PIN_DM_RES_UP
        #define Dis2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dis2_DM_OD_LO           PIN_DM_OD_LO
        #define Dis2_DM_OD_HI           PIN_DM_OD_HI
        #define Dis2_DM_STRONG          PIN_DM_STRONG
        #define Dis2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dis2_MASK               Dis2__MASK
#define Dis2_SHIFT              Dis2__SHIFT
#define Dis2_WIDTH              1u

/* Interrupt constants */
#if defined(Dis2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dis2_SetInterruptMode() function.
     *  @{
     */
        #define Dis2_INTR_NONE      (uint16)(0x0000u)
        #define Dis2_INTR_RISING    (uint16)(0x0001u)
        #define Dis2_INTR_FALLING   (uint16)(0x0002u)
        #define Dis2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dis2_INTR_MASK      (0x01u) 
#endif /* (Dis2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dis2_PS                     (* (reg8 *) Dis2__PS)
/* Data Register */
#define Dis2_DR                     (* (reg8 *) Dis2__DR)
/* Port Number */
#define Dis2_PRT_NUM                (* (reg8 *) Dis2__PRT) 
/* Connect to Analog Globals */                                                  
#define Dis2_AG                     (* (reg8 *) Dis2__AG)                       
/* Analog MUX bux enable */
#define Dis2_AMUX                   (* (reg8 *) Dis2__AMUX) 
/* Bidirectional Enable */                                                        
#define Dis2_BIE                    (* (reg8 *) Dis2__BIE)
/* Bit-mask for Aliased Register Access */
#define Dis2_BIT_MASK               (* (reg8 *) Dis2__BIT_MASK)
/* Bypass Enable */
#define Dis2_BYP                    (* (reg8 *) Dis2__BYP)
/* Port wide control signals */                                                   
#define Dis2_CTL                    (* (reg8 *) Dis2__CTL)
/* Drive Modes */
#define Dis2_DM0                    (* (reg8 *) Dis2__DM0) 
#define Dis2_DM1                    (* (reg8 *) Dis2__DM1)
#define Dis2_DM2                    (* (reg8 *) Dis2__DM2) 
/* Input Buffer Disable Override */
#define Dis2_INP_DIS                (* (reg8 *) Dis2__INP_DIS)
/* LCD Common or Segment Drive */
#define Dis2_LCD_COM_SEG            (* (reg8 *) Dis2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dis2_LCD_EN                 (* (reg8 *) Dis2__LCD_EN)
/* Slew Rate Control */
#define Dis2_SLW                    (* (reg8 *) Dis2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dis2_PRTDSI__CAPS_SEL       (* (reg8 *) Dis2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dis2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dis2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dis2_PRTDSI__OE_SEL0        (* (reg8 *) Dis2__PRTDSI__OE_SEL0) 
#define Dis2_PRTDSI__OE_SEL1        (* (reg8 *) Dis2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dis2_PRTDSI__OUT_SEL0       (* (reg8 *) Dis2__PRTDSI__OUT_SEL0) 
#define Dis2_PRTDSI__OUT_SEL1       (* (reg8 *) Dis2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dis2_PRTDSI__SYNC_OUT       (* (reg8 *) Dis2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dis2__SIO_CFG)
    #define Dis2_SIO_HYST_EN        (* (reg8 *) Dis2__SIO_HYST_EN)
    #define Dis2_SIO_REG_HIFREQ     (* (reg8 *) Dis2__SIO_REG_HIFREQ)
    #define Dis2_SIO_CFG            (* (reg8 *) Dis2__SIO_CFG)
    #define Dis2_SIO_DIFF           (* (reg8 *) Dis2__SIO_DIFF)
#endif /* (Dis2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dis2__INTSTAT)
    #define Dis2_INTSTAT            (* (reg8 *) Dis2__INTSTAT)
    #define Dis2_SNAP               (* (reg8 *) Dis2__SNAP)
    
	#define Dis2_0_INTTYPE_REG 		(* (reg8 *) Dis2__0__INTTYPE)
#endif /* (Dis2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dis2_H */


/* [] END OF FILE */
