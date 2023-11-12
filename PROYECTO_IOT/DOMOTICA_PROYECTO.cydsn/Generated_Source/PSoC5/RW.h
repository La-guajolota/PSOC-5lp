/*******************************************************************************
* File Name: RW.h  
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

#if !defined(CY_PINS_RW_H) /* Pins RW_H */
#define CY_PINS_RW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RW__PORT == 15 && ((RW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RW_Write(uint8 value);
void    RW_SetDriveMode(uint8 mode);
uint8   RW_ReadDataReg(void);
uint8   RW_Read(void);
void    RW_SetInterruptMode(uint16 position, uint16 mode);
uint8   RW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RW_SetDriveMode() function.
     *  @{
     */
        #define RW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RW_DM_RES_UP          PIN_DM_RES_UP
        #define RW_DM_RES_DWN         PIN_DM_RES_DWN
        #define RW_DM_OD_LO           PIN_DM_OD_LO
        #define RW_DM_OD_HI           PIN_DM_OD_HI
        #define RW_DM_STRONG          PIN_DM_STRONG
        #define RW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RW_MASK               RW__MASK
#define RW_SHIFT              RW__SHIFT
#define RW_WIDTH              1u

/* Interrupt constants */
#if defined(RW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RW_SetInterruptMode() function.
     *  @{
     */
        #define RW_INTR_NONE      (uint16)(0x0000u)
        #define RW_INTR_RISING    (uint16)(0x0001u)
        #define RW_INTR_FALLING   (uint16)(0x0002u)
        #define RW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RW_INTR_MASK      (0x01u) 
#endif /* (RW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RW_PS                     (* (reg8 *) RW__PS)
/* Data Register */
#define RW_DR                     (* (reg8 *) RW__DR)
/* Port Number */
#define RW_PRT_NUM                (* (reg8 *) RW__PRT) 
/* Connect to Analog Globals */                                                  
#define RW_AG                     (* (reg8 *) RW__AG)                       
/* Analog MUX bux enable */
#define RW_AMUX                   (* (reg8 *) RW__AMUX) 
/* Bidirectional Enable */                                                        
#define RW_BIE                    (* (reg8 *) RW__BIE)
/* Bit-mask for Aliased Register Access */
#define RW_BIT_MASK               (* (reg8 *) RW__BIT_MASK)
/* Bypass Enable */
#define RW_BYP                    (* (reg8 *) RW__BYP)
/* Port wide control signals */                                                   
#define RW_CTL                    (* (reg8 *) RW__CTL)
/* Drive Modes */
#define RW_DM0                    (* (reg8 *) RW__DM0) 
#define RW_DM1                    (* (reg8 *) RW__DM1)
#define RW_DM2                    (* (reg8 *) RW__DM2) 
/* Input Buffer Disable Override */
#define RW_INP_DIS                (* (reg8 *) RW__INP_DIS)
/* LCD Common or Segment Drive */
#define RW_LCD_COM_SEG            (* (reg8 *) RW__LCD_COM_SEG)
/* Enable Segment LCD */
#define RW_LCD_EN                 (* (reg8 *) RW__LCD_EN)
/* Slew Rate Control */
#define RW_SLW                    (* (reg8 *) RW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RW_PRTDSI__CAPS_SEL       (* (reg8 *) RW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RW_PRTDSI__OE_SEL0        (* (reg8 *) RW__PRTDSI__OE_SEL0) 
#define RW_PRTDSI__OE_SEL1        (* (reg8 *) RW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RW_PRTDSI__OUT_SEL0       (* (reg8 *) RW__PRTDSI__OUT_SEL0) 
#define RW_PRTDSI__OUT_SEL1       (* (reg8 *) RW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RW_PRTDSI__SYNC_OUT       (* (reg8 *) RW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RW__SIO_CFG)
    #define RW_SIO_HYST_EN        (* (reg8 *) RW__SIO_HYST_EN)
    #define RW_SIO_REG_HIFREQ     (* (reg8 *) RW__SIO_REG_HIFREQ)
    #define RW_SIO_CFG            (* (reg8 *) RW__SIO_CFG)
    #define RW_SIO_DIFF           (* (reg8 *) RW__SIO_DIFF)
#endif /* (RW__SIO_CFG) */

/* Interrupt Registers */
#if defined(RW__INTSTAT)
    #define RW_INTSTAT            (* (reg8 *) RW__INTSTAT)
    #define RW_SNAP               (* (reg8 *) RW__SNAP)
    
	#define RW_0_INTTYPE_REG 		(* (reg8 *) RW__0__INTTYPE)
#endif /* (RW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RW_H */


/* [] END OF FILE */
