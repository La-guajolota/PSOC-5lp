/*******************************************************************************
* File Name: SCRA_2.h  
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

#if !defined(CY_PINS_SCRA_2_H) /* Pins SCRA_2_H */
#define CY_PINS_SCRA_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SCRA_2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SCRA_2__PORT == 15 && ((SCRA_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SCRA_2_Write(uint8 value);
void    SCRA_2_SetDriveMode(uint8 mode);
uint8   SCRA_2_ReadDataReg(void);
uint8   SCRA_2_Read(void);
void    SCRA_2_SetInterruptMode(uint16 position, uint16 mode);
uint8   SCRA_2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SCRA_2_SetDriveMode() function.
     *  @{
     */
        #define SCRA_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SCRA_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SCRA_2_DM_RES_UP          PIN_DM_RES_UP
        #define SCRA_2_DM_RES_DWN         PIN_DM_RES_DWN
        #define SCRA_2_DM_OD_LO           PIN_DM_OD_LO
        #define SCRA_2_DM_OD_HI           PIN_DM_OD_HI
        #define SCRA_2_DM_STRONG          PIN_DM_STRONG
        #define SCRA_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SCRA_2_MASK               SCRA_2__MASK
#define SCRA_2_SHIFT              SCRA_2__SHIFT
#define SCRA_2_WIDTH              1u

/* Interrupt constants */
#if defined(SCRA_2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SCRA_2_SetInterruptMode() function.
     *  @{
     */
        #define SCRA_2_INTR_NONE      (uint16)(0x0000u)
        #define SCRA_2_INTR_RISING    (uint16)(0x0001u)
        #define SCRA_2_INTR_FALLING   (uint16)(0x0002u)
        #define SCRA_2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SCRA_2_INTR_MASK      (0x01u) 
#endif /* (SCRA_2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SCRA_2_PS                     (* (reg8 *) SCRA_2__PS)
/* Data Register */
#define SCRA_2_DR                     (* (reg8 *) SCRA_2__DR)
/* Port Number */
#define SCRA_2_PRT_NUM                (* (reg8 *) SCRA_2__PRT) 
/* Connect to Analog Globals */                                                  
#define SCRA_2_AG                     (* (reg8 *) SCRA_2__AG)                       
/* Analog MUX bux enable */
#define SCRA_2_AMUX                   (* (reg8 *) SCRA_2__AMUX) 
/* Bidirectional Enable */                                                        
#define SCRA_2_BIE                    (* (reg8 *) SCRA_2__BIE)
/* Bit-mask for Aliased Register Access */
#define SCRA_2_BIT_MASK               (* (reg8 *) SCRA_2__BIT_MASK)
/* Bypass Enable */
#define SCRA_2_BYP                    (* (reg8 *) SCRA_2__BYP)
/* Port wide control signals */                                                   
#define SCRA_2_CTL                    (* (reg8 *) SCRA_2__CTL)
/* Drive Modes */
#define SCRA_2_DM0                    (* (reg8 *) SCRA_2__DM0) 
#define SCRA_2_DM1                    (* (reg8 *) SCRA_2__DM1)
#define SCRA_2_DM2                    (* (reg8 *) SCRA_2__DM2) 
/* Input Buffer Disable Override */
#define SCRA_2_INP_DIS                (* (reg8 *) SCRA_2__INP_DIS)
/* LCD Common or Segment Drive */
#define SCRA_2_LCD_COM_SEG            (* (reg8 *) SCRA_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define SCRA_2_LCD_EN                 (* (reg8 *) SCRA_2__LCD_EN)
/* Slew Rate Control */
#define SCRA_2_SLW                    (* (reg8 *) SCRA_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SCRA_2_PRTDSI__CAPS_SEL       (* (reg8 *) SCRA_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SCRA_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SCRA_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SCRA_2_PRTDSI__OE_SEL0        (* (reg8 *) SCRA_2__PRTDSI__OE_SEL0) 
#define SCRA_2_PRTDSI__OE_SEL1        (* (reg8 *) SCRA_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SCRA_2_PRTDSI__OUT_SEL0       (* (reg8 *) SCRA_2__PRTDSI__OUT_SEL0) 
#define SCRA_2_PRTDSI__OUT_SEL1       (* (reg8 *) SCRA_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SCRA_2_PRTDSI__SYNC_OUT       (* (reg8 *) SCRA_2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SCRA_2__SIO_CFG)
    #define SCRA_2_SIO_HYST_EN        (* (reg8 *) SCRA_2__SIO_HYST_EN)
    #define SCRA_2_SIO_REG_HIFREQ     (* (reg8 *) SCRA_2__SIO_REG_HIFREQ)
    #define SCRA_2_SIO_CFG            (* (reg8 *) SCRA_2__SIO_CFG)
    #define SCRA_2_SIO_DIFF           (* (reg8 *) SCRA_2__SIO_DIFF)
#endif /* (SCRA_2__SIO_CFG) */

/* Interrupt Registers */
#if defined(SCRA_2__INTSTAT)
    #define SCRA_2_INTSTAT            (* (reg8 *) SCRA_2__INTSTAT)
    #define SCRA_2_SNAP               (* (reg8 *) SCRA_2__SNAP)
    
	#define SCRA_2_0_INTTYPE_REG 		(* (reg8 *) SCRA_2__0__INTTYPE)
#endif /* (SCRA_2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SCRA_2_H */


/* [] END OF FILE */
