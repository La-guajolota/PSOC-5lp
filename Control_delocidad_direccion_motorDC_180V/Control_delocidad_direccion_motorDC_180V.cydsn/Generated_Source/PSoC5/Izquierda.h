/*******************************************************************************
* File Name: Izquierda.h  
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

#if !defined(CY_PINS_Izquierda_H) /* Pins Izquierda_H */
#define CY_PINS_Izquierda_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Izquierda_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Izquierda__PORT == 15 && ((Izquierda__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Izquierda_Write(uint8 value);
void    Izquierda_SetDriveMode(uint8 mode);
uint8   Izquierda_ReadDataReg(void);
uint8   Izquierda_Read(void);
void    Izquierda_SetInterruptMode(uint16 position, uint16 mode);
uint8   Izquierda_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Izquierda_SetDriveMode() function.
     *  @{
     */
        #define Izquierda_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Izquierda_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Izquierda_DM_RES_UP          PIN_DM_RES_UP
        #define Izquierda_DM_RES_DWN         PIN_DM_RES_DWN
        #define Izquierda_DM_OD_LO           PIN_DM_OD_LO
        #define Izquierda_DM_OD_HI           PIN_DM_OD_HI
        #define Izquierda_DM_STRONG          PIN_DM_STRONG
        #define Izquierda_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Izquierda_MASK               Izquierda__MASK
#define Izquierda_SHIFT              Izquierda__SHIFT
#define Izquierda_WIDTH              1u

/* Interrupt constants */
#if defined(Izquierda__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Izquierda_SetInterruptMode() function.
     *  @{
     */
        #define Izquierda_INTR_NONE      (uint16)(0x0000u)
        #define Izquierda_INTR_RISING    (uint16)(0x0001u)
        #define Izquierda_INTR_FALLING   (uint16)(0x0002u)
        #define Izquierda_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Izquierda_INTR_MASK      (0x01u) 
#endif /* (Izquierda__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Izquierda_PS                     (* (reg8 *) Izquierda__PS)
/* Data Register */
#define Izquierda_DR                     (* (reg8 *) Izquierda__DR)
/* Port Number */
#define Izquierda_PRT_NUM                (* (reg8 *) Izquierda__PRT) 
/* Connect to Analog Globals */                                                  
#define Izquierda_AG                     (* (reg8 *) Izquierda__AG)                       
/* Analog MUX bux enable */
#define Izquierda_AMUX                   (* (reg8 *) Izquierda__AMUX) 
/* Bidirectional Enable */                                                        
#define Izquierda_BIE                    (* (reg8 *) Izquierda__BIE)
/* Bit-mask for Aliased Register Access */
#define Izquierda_BIT_MASK               (* (reg8 *) Izquierda__BIT_MASK)
/* Bypass Enable */
#define Izquierda_BYP                    (* (reg8 *) Izquierda__BYP)
/* Port wide control signals */                                                   
#define Izquierda_CTL                    (* (reg8 *) Izquierda__CTL)
/* Drive Modes */
#define Izquierda_DM0                    (* (reg8 *) Izquierda__DM0) 
#define Izquierda_DM1                    (* (reg8 *) Izquierda__DM1)
#define Izquierda_DM2                    (* (reg8 *) Izquierda__DM2) 
/* Input Buffer Disable Override */
#define Izquierda_INP_DIS                (* (reg8 *) Izquierda__INP_DIS)
/* LCD Common or Segment Drive */
#define Izquierda_LCD_COM_SEG            (* (reg8 *) Izquierda__LCD_COM_SEG)
/* Enable Segment LCD */
#define Izquierda_LCD_EN                 (* (reg8 *) Izquierda__LCD_EN)
/* Slew Rate Control */
#define Izquierda_SLW                    (* (reg8 *) Izquierda__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Izquierda_PRTDSI__CAPS_SEL       (* (reg8 *) Izquierda__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Izquierda_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Izquierda__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Izquierda_PRTDSI__OE_SEL0        (* (reg8 *) Izquierda__PRTDSI__OE_SEL0) 
#define Izquierda_PRTDSI__OE_SEL1        (* (reg8 *) Izquierda__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Izquierda_PRTDSI__OUT_SEL0       (* (reg8 *) Izquierda__PRTDSI__OUT_SEL0) 
#define Izquierda_PRTDSI__OUT_SEL1       (* (reg8 *) Izquierda__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Izquierda_PRTDSI__SYNC_OUT       (* (reg8 *) Izquierda__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Izquierda__SIO_CFG)
    #define Izquierda_SIO_HYST_EN        (* (reg8 *) Izquierda__SIO_HYST_EN)
    #define Izquierda_SIO_REG_HIFREQ     (* (reg8 *) Izquierda__SIO_REG_HIFREQ)
    #define Izquierda_SIO_CFG            (* (reg8 *) Izquierda__SIO_CFG)
    #define Izquierda_SIO_DIFF           (* (reg8 *) Izquierda__SIO_DIFF)
#endif /* (Izquierda__SIO_CFG) */

/* Interrupt Registers */
#if defined(Izquierda__INTSTAT)
    #define Izquierda_INTSTAT            (* (reg8 *) Izquierda__INTSTAT)
    #define Izquierda_SNAP               (* (reg8 *) Izquierda__SNAP)
    
	#define Izquierda_0_INTTYPE_REG 		(* (reg8 *) Izquierda__0__INTTYPE)
#endif /* (Izquierda__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Izquierda_H */


/* [] END OF FILE */
