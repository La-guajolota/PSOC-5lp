/*******************************************************************************
* File Name: Verde.h  
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

#if !defined(CY_PINS_Verde_H) /* Pins Verde_H */
#define CY_PINS_Verde_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Verde_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Verde__PORT == 15 && ((Verde__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Verde_Write(uint8 value);
void    Verde_SetDriveMode(uint8 mode);
uint8   Verde_ReadDataReg(void);
uint8   Verde_Read(void);
void    Verde_SetInterruptMode(uint16 position, uint16 mode);
uint8   Verde_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Verde_SetDriveMode() function.
     *  @{
     */
        #define Verde_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Verde_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Verde_DM_RES_UP          PIN_DM_RES_UP
        #define Verde_DM_RES_DWN         PIN_DM_RES_DWN
        #define Verde_DM_OD_LO           PIN_DM_OD_LO
        #define Verde_DM_OD_HI           PIN_DM_OD_HI
        #define Verde_DM_STRONG          PIN_DM_STRONG
        #define Verde_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Verde_MASK               Verde__MASK
#define Verde_SHIFT              Verde__SHIFT
#define Verde_WIDTH              1u

/* Interrupt constants */
#if defined(Verde__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Verde_SetInterruptMode() function.
     *  @{
     */
        #define Verde_INTR_NONE      (uint16)(0x0000u)
        #define Verde_INTR_RISING    (uint16)(0x0001u)
        #define Verde_INTR_FALLING   (uint16)(0x0002u)
        #define Verde_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Verde_INTR_MASK      (0x01u) 
#endif /* (Verde__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Verde_PS                     (* (reg8 *) Verde__PS)
/* Data Register */
#define Verde_DR                     (* (reg8 *) Verde__DR)
/* Port Number */
#define Verde_PRT_NUM                (* (reg8 *) Verde__PRT) 
/* Connect to Analog Globals */                                                  
#define Verde_AG                     (* (reg8 *) Verde__AG)                       
/* Analog MUX bux enable */
#define Verde_AMUX                   (* (reg8 *) Verde__AMUX) 
/* Bidirectional Enable */                                                        
#define Verde_BIE                    (* (reg8 *) Verde__BIE)
/* Bit-mask for Aliased Register Access */
#define Verde_BIT_MASK               (* (reg8 *) Verde__BIT_MASK)
/* Bypass Enable */
#define Verde_BYP                    (* (reg8 *) Verde__BYP)
/* Port wide control signals */                                                   
#define Verde_CTL                    (* (reg8 *) Verde__CTL)
/* Drive Modes */
#define Verde_DM0                    (* (reg8 *) Verde__DM0) 
#define Verde_DM1                    (* (reg8 *) Verde__DM1)
#define Verde_DM2                    (* (reg8 *) Verde__DM2) 
/* Input Buffer Disable Override */
#define Verde_INP_DIS                (* (reg8 *) Verde__INP_DIS)
/* LCD Common or Segment Drive */
#define Verde_LCD_COM_SEG            (* (reg8 *) Verde__LCD_COM_SEG)
/* Enable Segment LCD */
#define Verde_LCD_EN                 (* (reg8 *) Verde__LCD_EN)
/* Slew Rate Control */
#define Verde_SLW                    (* (reg8 *) Verde__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Verde_PRTDSI__CAPS_SEL       (* (reg8 *) Verde__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Verde_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Verde__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Verde_PRTDSI__OE_SEL0        (* (reg8 *) Verde__PRTDSI__OE_SEL0) 
#define Verde_PRTDSI__OE_SEL1        (* (reg8 *) Verde__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Verde_PRTDSI__OUT_SEL0       (* (reg8 *) Verde__PRTDSI__OUT_SEL0) 
#define Verde_PRTDSI__OUT_SEL1       (* (reg8 *) Verde__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Verde_PRTDSI__SYNC_OUT       (* (reg8 *) Verde__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Verde__SIO_CFG)
    #define Verde_SIO_HYST_EN        (* (reg8 *) Verde__SIO_HYST_EN)
    #define Verde_SIO_REG_HIFREQ     (* (reg8 *) Verde__SIO_REG_HIFREQ)
    #define Verde_SIO_CFG            (* (reg8 *) Verde__SIO_CFG)
    #define Verde_SIO_DIFF           (* (reg8 *) Verde__SIO_DIFF)
#endif /* (Verde__SIO_CFG) */

/* Interrupt Registers */
#if defined(Verde__INTSTAT)
    #define Verde_INTSTAT            (* (reg8 *) Verde__INTSTAT)
    #define Verde_SNAP               (* (reg8 *) Verde__SNAP)
    
	#define Verde_0_INTTYPE_REG 		(* (reg8 *) Verde__0__INTTYPE)
#endif /* (Verde__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Verde_H */


/* [] END OF FILE */
