/*******************************************************************************
* File Name: seg_4.h  
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

#if !defined(CY_PINS_seg_4_H) /* Pins seg_4_H */
#define CY_PINS_seg_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "seg_4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 seg_4__PORT == 15 && ((seg_4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    seg_4_Write(uint8 value);
void    seg_4_SetDriveMode(uint8 mode);
uint8   seg_4_ReadDataReg(void);
uint8   seg_4_Read(void);
void    seg_4_SetInterruptMode(uint16 position, uint16 mode);
uint8   seg_4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the seg_4_SetDriveMode() function.
     *  @{
     */
        #define seg_4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define seg_4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define seg_4_DM_RES_UP          PIN_DM_RES_UP
        #define seg_4_DM_RES_DWN         PIN_DM_RES_DWN
        #define seg_4_DM_OD_LO           PIN_DM_OD_LO
        #define seg_4_DM_OD_HI           PIN_DM_OD_HI
        #define seg_4_DM_STRONG          PIN_DM_STRONG
        #define seg_4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define seg_4_MASK               seg_4__MASK
#define seg_4_SHIFT              seg_4__SHIFT
#define seg_4_WIDTH              1u

/* Interrupt constants */
#if defined(seg_4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in seg_4_SetInterruptMode() function.
     *  @{
     */
        #define seg_4_INTR_NONE      (uint16)(0x0000u)
        #define seg_4_INTR_RISING    (uint16)(0x0001u)
        #define seg_4_INTR_FALLING   (uint16)(0x0002u)
        #define seg_4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define seg_4_INTR_MASK      (0x01u) 
#endif /* (seg_4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define seg_4_PS                     (* (reg8 *) seg_4__PS)
/* Data Register */
#define seg_4_DR                     (* (reg8 *) seg_4__DR)
/* Port Number */
#define seg_4_PRT_NUM                (* (reg8 *) seg_4__PRT) 
/* Connect to Analog Globals */                                                  
#define seg_4_AG                     (* (reg8 *) seg_4__AG)                       
/* Analog MUX bux enable */
#define seg_4_AMUX                   (* (reg8 *) seg_4__AMUX) 
/* Bidirectional Enable */                                                        
#define seg_4_BIE                    (* (reg8 *) seg_4__BIE)
/* Bit-mask for Aliased Register Access */
#define seg_4_BIT_MASK               (* (reg8 *) seg_4__BIT_MASK)
/* Bypass Enable */
#define seg_4_BYP                    (* (reg8 *) seg_4__BYP)
/* Port wide control signals */                                                   
#define seg_4_CTL                    (* (reg8 *) seg_4__CTL)
/* Drive Modes */
#define seg_4_DM0                    (* (reg8 *) seg_4__DM0) 
#define seg_4_DM1                    (* (reg8 *) seg_4__DM1)
#define seg_4_DM2                    (* (reg8 *) seg_4__DM2) 
/* Input Buffer Disable Override */
#define seg_4_INP_DIS                (* (reg8 *) seg_4__INP_DIS)
/* LCD Common or Segment Drive */
#define seg_4_LCD_COM_SEG            (* (reg8 *) seg_4__LCD_COM_SEG)
/* Enable Segment LCD */
#define seg_4_LCD_EN                 (* (reg8 *) seg_4__LCD_EN)
/* Slew Rate Control */
#define seg_4_SLW                    (* (reg8 *) seg_4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define seg_4_PRTDSI__CAPS_SEL       (* (reg8 *) seg_4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define seg_4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) seg_4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define seg_4_PRTDSI__OE_SEL0        (* (reg8 *) seg_4__PRTDSI__OE_SEL0) 
#define seg_4_PRTDSI__OE_SEL1        (* (reg8 *) seg_4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define seg_4_PRTDSI__OUT_SEL0       (* (reg8 *) seg_4__PRTDSI__OUT_SEL0) 
#define seg_4_PRTDSI__OUT_SEL1       (* (reg8 *) seg_4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define seg_4_PRTDSI__SYNC_OUT       (* (reg8 *) seg_4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(seg_4__SIO_CFG)
    #define seg_4_SIO_HYST_EN        (* (reg8 *) seg_4__SIO_HYST_EN)
    #define seg_4_SIO_REG_HIFREQ     (* (reg8 *) seg_4__SIO_REG_HIFREQ)
    #define seg_4_SIO_CFG            (* (reg8 *) seg_4__SIO_CFG)
    #define seg_4_SIO_DIFF           (* (reg8 *) seg_4__SIO_DIFF)
#endif /* (seg_4__SIO_CFG) */

/* Interrupt Registers */
#if defined(seg_4__INTSTAT)
    #define seg_4_INTSTAT            (* (reg8 *) seg_4__INTSTAT)
    #define seg_4_SNAP               (* (reg8 *) seg_4__SNAP)
    
	#define seg_4_0_INTTYPE_REG 		(* (reg8 *) seg_4__0__INTTYPE)
#endif /* (seg_4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_seg_4_H */


/* [] END OF FILE */
