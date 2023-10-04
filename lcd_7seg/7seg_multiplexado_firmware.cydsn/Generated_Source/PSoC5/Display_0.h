/*******************************************************************************
* File Name: Display_0.h  
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

#if !defined(CY_PINS_Display_0_H) /* Pins Display_0_H */
#define CY_PINS_Display_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Display_0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Display_0__PORT == 15 && ((Display_0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Display_0_Write(uint8 value);
void    Display_0_SetDriveMode(uint8 mode);
uint8   Display_0_ReadDataReg(void);
uint8   Display_0_Read(void);
void    Display_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   Display_0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Display_0_SetDriveMode() function.
     *  @{
     */
        #define Display_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Display_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Display_0_DM_RES_UP          PIN_DM_RES_UP
        #define Display_0_DM_RES_DWN         PIN_DM_RES_DWN
        #define Display_0_DM_OD_LO           PIN_DM_OD_LO
        #define Display_0_DM_OD_HI           PIN_DM_OD_HI
        #define Display_0_DM_STRONG          PIN_DM_STRONG
        #define Display_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Display_0_MASK               Display_0__MASK
#define Display_0_SHIFT              Display_0__SHIFT
#define Display_0_WIDTH              1u

/* Interrupt constants */
#if defined(Display_0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Display_0_SetInterruptMode() function.
     *  @{
     */
        #define Display_0_INTR_NONE      (uint16)(0x0000u)
        #define Display_0_INTR_RISING    (uint16)(0x0001u)
        #define Display_0_INTR_FALLING   (uint16)(0x0002u)
        #define Display_0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Display_0_INTR_MASK      (0x01u) 
#endif /* (Display_0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Display_0_PS                     (* (reg8 *) Display_0__PS)
/* Data Register */
#define Display_0_DR                     (* (reg8 *) Display_0__DR)
/* Port Number */
#define Display_0_PRT_NUM                (* (reg8 *) Display_0__PRT) 
/* Connect to Analog Globals */                                                  
#define Display_0_AG                     (* (reg8 *) Display_0__AG)                       
/* Analog MUX bux enable */
#define Display_0_AMUX                   (* (reg8 *) Display_0__AMUX) 
/* Bidirectional Enable */                                                        
#define Display_0_BIE                    (* (reg8 *) Display_0__BIE)
/* Bit-mask for Aliased Register Access */
#define Display_0_BIT_MASK               (* (reg8 *) Display_0__BIT_MASK)
/* Bypass Enable */
#define Display_0_BYP                    (* (reg8 *) Display_0__BYP)
/* Port wide control signals */                                                   
#define Display_0_CTL                    (* (reg8 *) Display_0__CTL)
/* Drive Modes */
#define Display_0_DM0                    (* (reg8 *) Display_0__DM0) 
#define Display_0_DM1                    (* (reg8 *) Display_0__DM1)
#define Display_0_DM2                    (* (reg8 *) Display_0__DM2) 
/* Input Buffer Disable Override */
#define Display_0_INP_DIS                (* (reg8 *) Display_0__INP_DIS)
/* LCD Common or Segment Drive */
#define Display_0_LCD_COM_SEG            (* (reg8 *) Display_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Display_0_LCD_EN                 (* (reg8 *) Display_0__LCD_EN)
/* Slew Rate Control */
#define Display_0_SLW                    (* (reg8 *) Display_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Display_0_PRTDSI__CAPS_SEL       (* (reg8 *) Display_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Display_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Display_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Display_0_PRTDSI__OE_SEL0        (* (reg8 *) Display_0__PRTDSI__OE_SEL0) 
#define Display_0_PRTDSI__OE_SEL1        (* (reg8 *) Display_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Display_0_PRTDSI__OUT_SEL0       (* (reg8 *) Display_0__PRTDSI__OUT_SEL0) 
#define Display_0_PRTDSI__OUT_SEL1       (* (reg8 *) Display_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Display_0_PRTDSI__SYNC_OUT       (* (reg8 *) Display_0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Display_0__SIO_CFG)
    #define Display_0_SIO_HYST_EN        (* (reg8 *) Display_0__SIO_HYST_EN)
    #define Display_0_SIO_REG_HIFREQ     (* (reg8 *) Display_0__SIO_REG_HIFREQ)
    #define Display_0_SIO_CFG            (* (reg8 *) Display_0__SIO_CFG)
    #define Display_0_SIO_DIFF           (* (reg8 *) Display_0__SIO_DIFF)
#endif /* (Display_0__SIO_CFG) */

/* Interrupt Registers */
#if defined(Display_0__INTSTAT)
    #define Display_0_INTSTAT            (* (reg8 *) Display_0__INTSTAT)
    #define Display_0_SNAP               (* (reg8 *) Display_0__SNAP)
    
	#define Display_0_0_INTTYPE_REG 		(* (reg8 *) Display_0__0__INTTYPE)
#endif /* (Display_0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Display_0_H */


/* [] END OF FILE */
