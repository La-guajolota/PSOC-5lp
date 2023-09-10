/*******************************************************************************
* File Name: IN3.h  
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

#if !defined(CY_PINS_IN3_H) /* Pins IN3_H */
#define CY_PINS_IN3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IN3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IN3__PORT == 15 && ((IN3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IN3_Write(uint8 value);
void    IN3_SetDriveMode(uint8 mode);
uint8   IN3_ReadDataReg(void);
uint8   IN3_Read(void);
void    IN3_SetInterruptMode(uint16 position, uint16 mode);
uint8   IN3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IN3_SetDriveMode() function.
     *  @{
     */
        #define IN3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IN3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IN3_DM_RES_UP          PIN_DM_RES_UP
        #define IN3_DM_RES_DWN         PIN_DM_RES_DWN
        #define IN3_DM_OD_LO           PIN_DM_OD_LO
        #define IN3_DM_OD_HI           PIN_DM_OD_HI
        #define IN3_DM_STRONG          PIN_DM_STRONG
        #define IN3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IN3_MASK               IN3__MASK
#define IN3_SHIFT              IN3__SHIFT
#define IN3_WIDTH              1u

/* Interrupt constants */
#if defined(IN3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IN3_SetInterruptMode() function.
     *  @{
     */
        #define IN3_INTR_NONE      (uint16)(0x0000u)
        #define IN3_INTR_RISING    (uint16)(0x0001u)
        #define IN3_INTR_FALLING   (uint16)(0x0002u)
        #define IN3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IN3_INTR_MASK      (0x01u) 
#endif /* (IN3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IN3_PS                     (* (reg8 *) IN3__PS)
/* Data Register */
#define IN3_DR                     (* (reg8 *) IN3__DR)
/* Port Number */
#define IN3_PRT_NUM                (* (reg8 *) IN3__PRT) 
/* Connect to Analog Globals */                                                  
#define IN3_AG                     (* (reg8 *) IN3__AG)                       
/* Analog MUX bux enable */
#define IN3_AMUX                   (* (reg8 *) IN3__AMUX) 
/* Bidirectional Enable */                                                        
#define IN3_BIE                    (* (reg8 *) IN3__BIE)
/* Bit-mask for Aliased Register Access */
#define IN3_BIT_MASK               (* (reg8 *) IN3__BIT_MASK)
/* Bypass Enable */
#define IN3_BYP                    (* (reg8 *) IN3__BYP)
/* Port wide control signals */                                                   
#define IN3_CTL                    (* (reg8 *) IN3__CTL)
/* Drive Modes */
#define IN3_DM0                    (* (reg8 *) IN3__DM0) 
#define IN3_DM1                    (* (reg8 *) IN3__DM1)
#define IN3_DM2                    (* (reg8 *) IN3__DM2) 
/* Input Buffer Disable Override */
#define IN3_INP_DIS                (* (reg8 *) IN3__INP_DIS)
/* LCD Common or Segment Drive */
#define IN3_LCD_COM_SEG            (* (reg8 *) IN3__LCD_COM_SEG)
/* Enable Segment LCD */
#define IN3_LCD_EN                 (* (reg8 *) IN3__LCD_EN)
/* Slew Rate Control */
#define IN3_SLW                    (* (reg8 *) IN3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IN3_PRTDSI__CAPS_SEL       (* (reg8 *) IN3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IN3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IN3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IN3_PRTDSI__OE_SEL0        (* (reg8 *) IN3__PRTDSI__OE_SEL0) 
#define IN3_PRTDSI__OE_SEL1        (* (reg8 *) IN3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IN3_PRTDSI__OUT_SEL0       (* (reg8 *) IN3__PRTDSI__OUT_SEL0) 
#define IN3_PRTDSI__OUT_SEL1       (* (reg8 *) IN3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IN3_PRTDSI__SYNC_OUT       (* (reg8 *) IN3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IN3__SIO_CFG)
    #define IN3_SIO_HYST_EN        (* (reg8 *) IN3__SIO_HYST_EN)
    #define IN3_SIO_REG_HIFREQ     (* (reg8 *) IN3__SIO_REG_HIFREQ)
    #define IN3_SIO_CFG            (* (reg8 *) IN3__SIO_CFG)
    #define IN3_SIO_DIFF           (* (reg8 *) IN3__SIO_DIFF)
#endif /* (IN3__SIO_CFG) */

/* Interrupt Registers */
#if defined(IN3__INTSTAT)
    #define IN3_INTSTAT            (* (reg8 *) IN3__INTSTAT)
    #define IN3_SNAP               (* (reg8 *) IN3__SNAP)
    
	#define IN3_0_INTTYPE_REG 		(* (reg8 *) IN3__0__INTTYPE)
#endif /* (IN3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IN3_H */


/* [] END OF FILE */
