/*******************************************************************************
* File Name: CEROS.h  
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

#if !defined(CY_PINS_CEROS_H) /* Pins CEROS_H */
#define CY_PINS_CEROS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CEROS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CEROS__PORT == 15 && ((CEROS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CEROS_Write(uint8 value);
void    CEROS_SetDriveMode(uint8 mode);
uint8   CEROS_ReadDataReg(void);
uint8   CEROS_Read(void);
void    CEROS_SetInterruptMode(uint16 position, uint16 mode);
uint8   CEROS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CEROS_SetDriveMode() function.
     *  @{
     */
        #define CEROS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CEROS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CEROS_DM_RES_UP          PIN_DM_RES_UP
        #define CEROS_DM_RES_DWN         PIN_DM_RES_DWN
        #define CEROS_DM_OD_LO           PIN_DM_OD_LO
        #define CEROS_DM_OD_HI           PIN_DM_OD_HI
        #define CEROS_DM_STRONG          PIN_DM_STRONG
        #define CEROS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CEROS_MASK               CEROS__MASK
#define CEROS_SHIFT              CEROS__SHIFT
#define CEROS_WIDTH              1u

/* Interrupt constants */
#if defined(CEROS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CEROS_SetInterruptMode() function.
     *  @{
     */
        #define CEROS_INTR_NONE      (uint16)(0x0000u)
        #define CEROS_INTR_RISING    (uint16)(0x0001u)
        #define CEROS_INTR_FALLING   (uint16)(0x0002u)
        #define CEROS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CEROS_INTR_MASK      (0x01u) 
#endif /* (CEROS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CEROS_PS                     (* (reg8 *) CEROS__PS)
/* Data Register */
#define CEROS_DR                     (* (reg8 *) CEROS__DR)
/* Port Number */
#define CEROS_PRT_NUM                (* (reg8 *) CEROS__PRT) 
/* Connect to Analog Globals */                                                  
#define CEROS_AG                     (* (reg8 *) CEROS__AG)                       
/* Analog MUX bux enable */
#define CEROS_AMUX                   (* (reg8 *) CEROS__AMUX) 
/* Bidirectional Enable */                                                        
#define CEROS_BIE                    (* (reg8 *) CEROS__BIE)
/* Bit-mask for Aliased Register Access */
#define CEROS_BIT_MASK               (* (reg8 *) CEROS__BIT_MASK)
/* Bypass Enable */
#define CEROS_BYP                    (* (reg8 *) CEROS__BYP)
/* Port wide control signals */                                                   
#define CEROS_CTL                    (* (reg8 *) CEROS__CTL)
/* Drive Modes */
#define CEROS_DM0                    (* (reg8 *) CEROS__DM0) 
#define CEROS_DM1                    (* (reg8 *) CEROS__DM1)
#define CEROS_DM2                    (* (reg8 *) CEROS__DM2) 
/* Input Buffer Disable Override */
#define CEROS_INP_DIS                (* (reg8 *) CEROS__INP_DIS)
/* LCD Common or Segment Drive */
#define CEROS_LCD_COM_SEG            (* (reg8 *) CEROS__LCD_COM_SEG)
/* Enable Segment LCD */
#define CEROS_LCD_EN                 (* (reg8 *) CEROS__LCD_EN)
/* Slew Rate Control */
#define CEROS_SLW                    (* (reg8 *) CEROS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CEROS_PRTDSI__CAPS_SEL       (* (reg8 *) CEROS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CEROS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CEROS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CEROS_PRTDSI__OE_SEL0        (* (reg8 *) CEROS__PRTDSI__OE_SEL0) 
#define CEROS_PRTDSI__OE_SEL1        (* (reg8 *) CEROS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CEROS_PRTDSI__OUT_SEL0       (* (reg8 *) CEROS__PRTDSI__OUT_SEL0) 
#define CEROS_PRTDSI__OUT_SEL1       (* (reg8 *) CEROS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CEROS_PRTDSI__SYNC_OUT       (* (reg8 *) CEROS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CEROS__SIO_CFG)
    #define CEROS_SIO_HYST_EN        (* (reg8 *) CEROS__SIO_HYST_EN)
    #define CEROS_SIO_REG_HIFREQ     (* (reg8 *) CEROS__SIO_REG_HIFREQ)
    #define CEROS_SIO_CFG            (* (reg8 *) CEROS__SIO_CFG)
    #define CEROS_SIO_DIFF           (* (reg8 *) CEROS__SIO_DIFF)
#endif /* (CEROS__SIO_CFG) */

/* Interrupt Registers */
#if defined(CEROS__INTSTAT)
    #define CEROS_INTSTAT            (* (reg8 *) CEROS__INTSTAT)
    #define CEROS_SNAP               (* (reg8 *) CEROS__SNAP)
    
	#define CEROS_0_INTTYPE_REG 		(* (reg8 *) CEROS__0__INTTYPE)
#endif /* (CEROS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CEROS_H */


/* [] END OF FILE */
