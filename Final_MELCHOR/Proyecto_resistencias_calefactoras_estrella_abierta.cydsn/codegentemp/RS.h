/*******************************************************************************
* File Name: RS.h  
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

#if !defined(CY_PINS_RS_H) /* Pins RS_H */
#define CY_PINS_RS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RS__PORT == 15 && ((RS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RS_Write(uint8 value);
void    RS_SetDriveMode(uint8 mode);
uint8   RS_ReadDataReg(void);
uint8   RS_Read(void);
void    RS_SetInterruptMode(uint16 position, uint16 mode);
uint8   RS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RS_SetDriveMode() function.
     *  @{
     */
        #define RS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RS_DM_RES_UP          PIN_DM_RES_UP
        #define RS_DM_RES_DWN         PIN_DM_RES_DWN
        #define RS_DM_OD_LO           PIN_DM_OD_LO
        #define RS_DM_OD_HI           PIN_DM_OD_HI
        #define RS_DM_STRONG          PIN_DM_STRONG
        #define RS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RS_MASK               RS__MASK
#define RS_SHIFT              RS__SHIFT
#define RS_WIDTH              1u

/* Interrupt constants */
#if defined(RS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RS_SetInterruptMode() function.
     *  @{
     */
        #define RS_INTR_NONE      (uint16)(0x0000u)
        #define RS_INTR_RISING    (uint16)(0x0001u)
        #define RS_INTR_FALLING   (uint16)(0x0002u)
        #define RS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RS_INTR_MASK      (0x01u) 
#endif /* (RS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RS_PS                     (* (reg8 *) RS__PS)
/* Data Register */
#define RS_DR                     (* (reg8 *) RS__DR)
/* Port Number */
#define RS_PRT_NUM                (* (reg8 *) RS__PRT) 
/* Connect to Analog Globals */                                                  
#define RS_AG                     (* (reg8 *) RS__AG)                       
/* Analog MUX bux enable */
#define RS_AMUX                   (* (reg8 *) RS__AMUX) 
/* Bidirectional Enable */                                                        
#define RS_BIE                    (* (reg8 *) RS__BIE)
/* Bit-mask for Aliased Register Access */
#define RS_BIT_MASK               (* (reg8 *) RS__BIT_MASK)
/* Bypass Enable */
#define RS_BYP                    (* (reg8 *) RS__BYP)
/* Port wide control signals */                                                   
#define RS_CTL                    (* (reg8 *) RS__CTL)
/* Drive Modes */
#define RS_DM0                    (* (reg8 *) RS__DM0) 
#define RS_DM1                    (* (reg8 *) RS__DM1)
#define RS_DM2                    (* (reg8 *) RS__DM2) 
/* Input Buffer Disable Override */
#define RS_INP_DIS                (* (reg8 *) RS__INP_DIS)
/* LCD Common or Segment Drive */
#define RS_LCD_COM_SEG            (* (reg8 *) RS__LCD_COM_SEG)
/* Enable Segment LCD */
#define RS_LCD_EN                 (* (reg8 *) RS__LCD_EN)
/* Slew Rate Control */
#define RS_SLW                    (* (reg8 *) RS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RS_PRTDSI__CAPS_SEL       (* (reg8 *) RS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RS_PRTDSI__OE_SEL0        (* (reg8 *) RS__PRTDSI__OE_SEL0) 
#define RS_PRTDSI__OE_SEL1        (* (reg8 *) RS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RS_PRTDSI__OUT_SEL0       (* (reg8 *) RS__PRTDSI__OUT_SEL0) 
#define RS_PRTDSI__OUT_SEL1       (* (reg8 *) RS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RS_PRTDSI__SYNC_OUT       (* (reg8 *) RS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RS__SIO_CFG)
    #define RS_SIO_HYST_EN        (* (reg8 *) RS__SIO_HYST_EN)
    #define RS_SIO_REG_HIFREQ     (* (reg8 *) RS__SIO_REG_HIFREQ)
    #define RS_SIO_CFG            (* (reg8 *) RS__SIO_CFG)
    #define RS_SIO_DIFF           (* (reg8 *) RS__SIO_DIFF)
#endif /* (RS__SIO_CFG) */

/* Interrupt Registers */
#if defined(RS__INTSTAT)
    #define RS_INTSTAT            (* (reg8 *) RS__INTSTAT)
    #define RS_SNAP               (* (reg8 *) RS__SNAP)
    
	#define RS_0_INTTYPE_REG 		(* (reg8 *) RS__0__INTTYPE)
#endif /* (RS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RS_H */


/* [] END OF FILE */
