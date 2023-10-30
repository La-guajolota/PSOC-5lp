/*******************************************************************************
* File Name: ventalidor.h  
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

#if !defined(CY_PINS_ventalidor_H) /* Pins ventalidor_H */
#define CY_PINS_ventalidor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ventalidor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ventalidor__PORT == 15 && ((ventalidor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ventalidor_Write(uint8 value);
void    ventalidor_SetDriveMode(uint8 mode);
uint8   ventalidor_ReadDataReg(void);
uint8   ventalidor_Read(void);
void    ventalidor_SetInterruptMode(uint16 position, uint16 mode);
uint8   ventalidor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ventalidor_SetDriveMode() function.
     *  @{
     */
        #define ventalidor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ventalidor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ventalidor_DM_RES_UP          PIN_DM_RES_UP
        #define ventalidor_DM_RES_DWN         PIN_DM_RES_DWN
        #define ventalidor_DM_OD_LO           PIN_DM_OD_LO
        #define ventalidor_DM_OD_HI           PIN_DM_OD_HI
        #define ventalidor_DM_STRONG          PIN_DM_STRONG
        #define ventalidor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ventalidor_MASK               ventalidor__MASK
#define ventalidor_SHIFT              ventalidor__SHIFT
#define ventalidor_WIDTH              1u

/* Interrupt constants */
#if defined(ventalidor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ventalidor_SetInterruptMode() function.
     *  @{
     */
        #define ventalidor_INTR_NONE      (uint16)(0x0000u)
        #define ventalidor_INTR_RISING    (uint16)(0x0001u)
        #define ventalidor_INTR_FALLING   (uint16)(0x0002u)
        #define ventalidor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ventalidor_INTR_MASK      (0x01u) 
#endif /* (ventalidor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ventalidor_PS                     (* (reg8 *) ventalidor__PS)
/* Data Register */
#define ventalidor_DR                     (* (reg8 *) ventalidor__DR)
/* Port Number */
#define ventalidor_PRT_NUM                (* (reg8 *) ventalidor__PRT) 
/* Connect to Analog Globals */                                                  
#define ventalidor_AG                     (* (reg8 *) ventalidor__AG)                       
/* Analog MUX bux enable */
#define ventalidor_AMUX                   (* (reg8 *) ventalidor__AMUX) 
/* Bidirectional Enable */                                                        
#define ventalidor_BIE                    (* (reg8 *) ventalidor__BIE)
/* Bit-mask for Aliased Register Access */
#define ventalidor_BIT_MASK               (* (reg8 *) ventalidor__BIT_MASK)
/* Bypass Enable */
#define ventalidor_BYP                    (* (reg8 *) ventalidor__BYP)
/* Port wide control signals */                                                   
#define ventalidor_CTL                    (* (reg8 *) ventalidor__CTL)
/* Drive Modes */
#define ventalidor_DM0                    (* (reg8 *) ventalidor__DM0) 
#define ventalidor_DM1                    (* (reg8 *) ventalidor__DM1)
#define ventalidor_DM2                    (* (reg8 *) ventalidor__DM2) 
/* Input Buffer Disable Override */
#define ventalidor_INP_DIS                (* (reg8 *) ventalidor__INP_DIS)
/* LCD Common or Segment Drive */
#define ventalidor_LCD_COM_SEG            (* (reg8 *) ventalidor__LCD_COM_SEG)
/* Enable Segment LCD */
#define ventalidor_LCD_EN                 (* (reg8 *) ventalidor__LCD_EN)
/* Slew Rate Control */
#define ventalidor_SLW                    (* (reg8 *) ventalidor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ventalidor_PRTDSI__CAPS_SEL       (* (reg8 *) ventalidor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ventalidor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ventalidor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ventalidor_PRTDSI__OE_SEL0        (* (reg8 *) ventalidor__PRTDSI__OE_SEL0) 
#define ventalidor_PRTDSI__OE_SEL1        (* (reg8 *) ventalidor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ventalidor_PRTDSI__OUT_SEL0       (* (reg8 *) ventalidor__PRTDSI__OUT_SEL0) 
#define ventalidor_PRTDSI__OUT_SEL1       (* (reg8 *) ventalidor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ventalidor_PRTDSI__SYNC_OUT       (* (reg8 *) ventalidor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ventalidor__SIO_CFG)
    #define ventalidor_SIO_HYST_EN        (* (reg8 *) ventalidor__SIO_HYST_EN)
    #define ventalidor_SIO_REG_HIFREQ     (* (reg8 *) ventalidor__SIO_REG_HIFREQ)
    #define ventalidor_SIO_CFG            (* (reg8 *) ventalidor__SIO_CFG)
    #define ventalidor_SIO_DIFF           (* (reg8 *) ventalidor__SIO_DIFF)
#endif /* (ventalidor__SIO_CFG) */

/* Interrupt Registers */
#if defined(ventalidor__INTSTAT)
    #define ventalidor_INTSTAT            (* (reg8 *) ventalidor__INTSTAT)
    #define ventalidor_SNAP               (* (reg8 *) ventalidor__SNAP)
    
	#define ventalidor_0_INTTYPE_REG 		(* (reg8 *) ventalidor__0__INTTYPE)
#endif /* (ventalidor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ventalidor_H */


/* [] END OF FILE */
