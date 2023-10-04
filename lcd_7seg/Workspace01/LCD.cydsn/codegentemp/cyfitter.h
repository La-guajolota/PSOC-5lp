/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* E */
#define E__0__INTTYPE CYREG_PICU3_INTTYPE3
#define E__0__MASK 0x08u
#define E__0__PC CYREG_PRT3_PC3
#define E__0__PORT 3u
#define E__0__SHIFT 3u
#define E__AG CYREG_PRT3_AG
#define E__AMUX CYREG_PRT3_AMUX
#define E__BIE CYREG_PRT3_BIE
#define E__BIT_MASK CYREG_PRT3_BIT_MASK
#define E__BYP CYREG_PRT3_BYP
#define E__CTL CYREG_PRT3_CTL
#define E__DM0 CYREG_PRT3_DM0
#define E__DM1 CYREG_PRT3_DM1
#define E__DM2 CYREG_PRT3_DM2
#define E__DR CYREG_PRT3_DR
#define E__INP_DIS CYREG_PRT3_INP_DIS
#define E__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define E__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define E__LCD_EN CYREG_PRT3_LCD_EN
#define E__MASK 0x08u
#define E__PORT 3u
#define E__PRT CYREG_PRT3_PRT
#define E__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define E__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define E__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define E__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define E__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define E__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define E__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define E__PS CYREG_PRT3_PS
#define E__SHIFT 3u
#define E__SLW CYREG_PRT3_SLW

/* D4 */
#define D4__0__INTTYPE CYREG_PICU3_INTTYPE4
#define D4__0__MASK 0x10u
#define D4__0__PC CYREG_PRT3_PC4
#define D4__0__PORT 3u
#define D4__0__SHIFT 4u
#define D4__AG CYREG_PRT3_AG
#define D4__AMUX CYREG_PRT3_AMUX
#define D4__BIE CYREG_PRT3_BIE
#define D4__BIT_MASK CYREG_PRT3_BIT_MASK
#define D4__BYP CYREG_PRT3_BYP
#define D4__CTL CYREG_PRT3_CTL
#define D4__DM0 CYREG_PRT3_DM0
#define D4__DM1 CYREG_PRT3_DM1
#define D4__DM2 CYREG_PRT3_DM2
#define D4__DR CYREG_PRT3_DR
#define D4__INP_DIS CYREG_PRT3_INP_DIS
#define D4__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define D4__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define D4__LCD_EN CYREG_PRT3_LCD_EN
#define D4__MASK 0x10u
#define D4__PORT 3u
#define D4__PRT CYREG_PRT3_PRT
#define D4__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define D4__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define D4__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define D4__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define D4__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define D4__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define D4__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define D4__PS CYREG_PRT3_PS
#define D4__SHIFT 4u
#define D4__SLW CYREG_PRT3_SLW

/* D5 */
#define D5__0__INTTYPE CYREG_PICU3_INTTYPE5
#define D5__0__MASK 0x20u
#define D5__0__PC CYREG_PRT3_PC5
#define D5__0__PORT 3u
#define D5__0__SHIFT 5u
#define D5__AG CYREG_PRT3_AG
#define D5__AMUX CYREG_PRT3_AMUX
#define D5__BIE CYREG_PRT3_BIE
#define D5__BIT_MASK CYREG_PRT3_BIT_MASK
#define D5__BYP CYREG_PRT3_BYP
#define D5__CTL CYREG_PRT3_CTL
#define D5__DM0 CYREG_PRT3_DM0
#define D5__DM1 CYREG_PRT3_DM1
#define D5__DM2 CYREG_PRT3_DM2
#define D5__DR CYREG_PRT3_DR
#define D5__INP_DIS CYREG_PRT3_INP_DIS
#define D5__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define D5__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define D5__LCD_EN CYREG_PRT3_LCD_EN
#define D5__MASK 0x20u
#define D5__PORT 3u
#define D5__PRT CYREG_PRT3_PRT
#define D5__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define D5__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define D5__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define D5__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define D5__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define D5__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define D5__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define D5__PS CYREG_PRT3_PS
#define D5__SHIFT 5u
#define D5__SLW CYREG_PRT3_SLW

/* D6 */
#define D6__0__INTTYPE CYREG_PICU3_INTTYPE6
#define D6__0__MASK 0x40u
#define D6__0__PC CYREG_PRT3_PC6
#define D6__0__PORT 3u
#define D6__0__SHIFT 6u
#define D6__AG CYREG_PRT3_AG
#define D6__AMUX CYREG_PRT3_AMUX
#define D6__BIE CYREG_PRT3_BIE
#define D6__BIT_MASK CYREG_PRT3_BIT_MASK
#define D6__BYP CYREG_PRT3_BYP
#define D6__CTL CYREG_PRT3_CTL
#define D6__DM0 CYREG_PRT3_DM0
#define D6__DM1 CYREG_PRT3_DM1
#define D6__DM2 CYREG_PRT3_DM2
#define D6__DR CYREG_PRT3_DR
#define D6__INP_DIS CYREG_PRT3_INP_DIS
#define D6__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define D6__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define D6__LCD_EN CYREG_PRT3_LCD_EN
#define D6__MASK 0x40u
#define D6__PORT 3u
#define D6__PRT CYREG_PRT3_PRT
#define D6__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define D6__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define D6__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define D6__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define D6__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define D6__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define D6__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define D6__PS CYREG_PRT3_PS
#define D6__SHIFT 6u
#define D6__SLW CYREG_PRT3_SLW

/* D7 */
#define D7__0__INTTYPE CYREG_PICU3_INTTYPE7
#define D7__0__MASK 0x80u
#define D7__0__PC CYREG_PRT3_PC7
#define D7__0__PORT 3u
#define D7__0__SHIFT 7u
#define D7__AG CYREG_PRT3_AG
#define D7__AMUX CYREG_PRT3_AMUX
#define D7__BIE CYREG_PRT3_BIE
#define D7__BIT_MASK CYREG_PRT3_BIT_MASK
#define D7__BYP CYREG_PRT3_BYP
#define D7__CTL CYREG_PRT3_CTL
#define D7__DM0 CYREG_PRT3_DM0
#define D7__DM1 CYREG_PRT3_DM1
#define D7__DM2 CYREG_PRT3_DM2
#define D7__DR CYREG_PRT3_DR
#define D7__INP_DIS CYREG_PRT3_INP_DIS
#define D7__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define D7__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define D7__LCD_EN CYREG_PRT3_LCD_EN
#define D7__MASK 0x80u
#define D7__PORT 3u
#define D7__PRT CYREG_PRT3_PRT
#define D7__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define D7__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define D7__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define D7__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define D7__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define D7__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define D7__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define D7__PS CYREG_PRT3_PS
#define D7__SHIFT 7u
#define D7__SLW CYREG_PRT3_SLW

/* RS */
#define RS__0__INTTYPE CYREG_PICU3_INTTYPE2
#define RS__0__MASK 0x04u
#define RS__0__PC CYREG_PRT3_PC2
#define RS__0__PORT 3u
#define RS__0__SHIFT 2u
#define RS__AG CYREG_PRT3_AG
#define RS__AMUX CYREG_PRT3_AMUX
#define RS__BIE CYREG_PRT3_BIE
#define RS__BIT_MASK CYREG_PRT3_BIT_MASK
#define RS__BYP CYREG_PRT3_BYP
#define RS__CTL CYREG_PRT3_CTL
#define RS__DM0 CYREG_PRT3_DM0
#define RS__DM1 CYREG_PRT3_DM1
#define RS__DM2 CYREG_PRT3_DM2
#define RS__DR CYREG_PRT3_DR
#define RS__INP_DIS CYREG_PRT3_INP_DIS
#define RS__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define RS__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define RS__LCD_EN CYREG_PRT3_LCD_EN
#define RS__MASK 0x04u
#define RS__PORT 3u
#define RS__PRT CYREG_PRT3_PRT
#define RS__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define RS__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define RS__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define RS__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define RS__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define RS__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define RS__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define RS__PS CYREG_PRT3_PS
#define RS__SHIFT 2u
#define RS__SLW CYREG_PRT3_SLW

/* LCD */
#define LCD_Sync_ctrl_reg__0__MASK 0x01u
#define LCD_Sync_ctrl_reg__0__POS 0
#define LCD_Sync_ctrl_reg__1__MASK 0x02u
#define LCD_Sync_ctrl_reg__1__POS 1
#define LCD_Sync_ctrl_reg__2__MASK 0x04u
#define LCD_Sync_ctrl_reg__2__POS 2
#define LCD_Sync_ctrl_reg__3__MASK 0x08u
#define LCD_Sync_ctrl_reg__3__POS 3
#define LCD_Sync_ctrl_reg__4__MASK 0x10u
#define LCD_Sync_ctrl_reg__4__POS 4
#define LCD_Sync_ctrl_reg__5__MASK 0x20u
#define LCD_Sync_ctrl_reg__5__POS 5
#define LCD_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_B1_UDB11_ACTL
#define LCD_Sync_ctrl_reg__CONTROL_REG CYREG_B1_UDB11_CTL
#define LCD_Sync_ctrl_reg__CONTROL_ST_REG CYREG_B1_UDB11_ST_CTL
#define LCD_Sync_ctrl_reg__COUNT_REG CYREG_B1_UDB11_CTL
#define LCD_Sync_ctrl_reg__COUNT_ST_REG CYREG_B1_UDB11_ST_CTL
#define LCD_Sync_ctrl_reg__MASK 0x3Fu
#define LCD_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB11_MSK_ACTL
#define LCD_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB11_MSK_ACTL
#define LCD_Sync_ctrl_reg__PERIOD_REG CYREG_B1_UDB11_MSK

/* LED */
#define LED_Sync_ctrl_reg__0__MASK 0x01u
#define LED_Sync_ctrl_reg__0__POS 0
#define LED_Sync_ctrl_reg__1__MASK 0x02u
#define LED_Sync_ctrl_reg__1__POS 1
#define LED_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB08_09_ACTL
#define LED_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB08_09_CTL
#define LED_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB08_09_CTL
#define LED_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB08_09_CTL
#define LED_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB08_09_CTL
#define LED_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_B0_UDB08_09_MSK
#define LED_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB08_09_MSK
#define LED_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB08_09_MSK
#define LED_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB08_09_MSK
#define LED_Sync_ctrl_reg__2__MASK 0x04u
#define LED_Sync_ctrl_reg__2__POS 2
#define LED_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_B0_UDB08_ACTL
#define LED_Sync_ctrl_reg__CONTROL_REG CYREG_B0_UDB08_CTL
#define LED_Sync_ctrl_reg__CONTROL_ST_REG CYREG_B0_UDB08_ST_CTL
#define LED_Sync_ctrl_reg__COUNT_REG CYREG_B0_UDB08_CTL
#define LED_Sync_ctrl_reg__COUNT_ST_REG CYREG_B0_UDB08_ST_CTL
#define LED_Sync_ctrl_reg__MASK 0x07u
#define LED_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define LED_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define LED_Sync_ctrl_reg__PERIOD_REG CYREG_B0_UDB08_MSK

/* isr */
#define isr__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr__INTC_MASK 0x02u
#define isr__INTC_NUMBER 1u
#define isr__INTC_PRIOR_NUM 7u
#define isr__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define isr__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* BLUE */
#define BLUE__0__INTTYPE CYREG_PICU12_INTTYPE3
#define BLUE__0__MASK 0x08u
#define BLUE__0__PC CYREG_PRT12_PC3
#define BLUE__0__PORT 12u
#define BLUE__0__SHIFT 3u
#define BLUE__AG CYREG_PRT12_AG
#define BLUE__BIE CYREG_PRT12_BIE
#define BLUE__BIT_MASK CYREG_PRT12_BIT_MASK
#define BLUE__BYP CYREG_PRT12_BYP
#define BLUE__DM0 CYREG_PRT12_DM0
#define BLUE__DM1 CYREG_PRT12_DM1
#define BLUE__DM2 CYREG_PRT12_DM2
#define BLUE__DR CYREG_PRT12_DR
#define BLUE__INP_DIS CYREG_PRT12_INP_DIS
#define BLUE__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define BLUE__MASK 0x08u
#define BLUE__PORT 12u
#define BLUE__PRT CYREG_PRT12_PRT
#define BLUE__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define BLUE__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define BLUE__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define BLUE__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define BLUE__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define BLUE__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define BLUE__PS CYREG_PRT12_PS
#define BLUE__SHIFT 3u
#define BLUE__SIO_CFG CYREG_PRT12_SIO_CFG
#define BLUE__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define BLUE__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define BLUE__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define BLUE__SLW CYREG_PRT12_SLW

/* ROJO */
#define ROJO__0__INTTYPE CYREG_PICU12_INTTYPE5
#define ROJO__0__MASK 0x20u
#define ROJO__0__PC CYREG_PRT12_PC5
#define ROJO__0__PORT 12u
#define ROJO__0__SHIFT 5u
#define ROJO__AG CYREG_PRT12_AG
#define ROJO__BIE CYREG_PRT12_BIE
#define ROJO__BIT_MASK CYREG_PRT12_BIT_MASK
#define ROJO__BYP CYREG_PRT12_BYP
#define ROJO__DM0 CYREG_PRT12_DM0
#define ROJO__DM1 CYREG_PRT12_DM1
#define ROJO__DM2 CYREG_PRT12_DM2
#define ROJO__DR CYREG_PRT12_DR
#define ROJO__INP_DIS CYREG_PRT12_INP_DIS
#define ROJO__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define ROJO__MASK 0x20u
#define ROJO__PORT 12u
#define ROJO__PRT CYREG_PRT12_PRT
#define ROJO__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define ROJO__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define ROJO__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define ROJO__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define ROJO__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define ROJO__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define ROJO__PS CYREG_PRT12_PS
#define ROJO__SHIFT 5u
#define ROJO__SIO_CFG CYREG_PRT12_SIO_CFG
#define ROJO__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define ROJO__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define ROJO__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define ROJO__SLW CYREG_PRT12_SLW

/* Rx_1 */
#define Rx_1__0__INTTYPE CYREG_PICU12_INTTYPE6
#define Rx_1__0__MASK 0x40u
#define Rx_1__0__PC CYREG_PRT12_PC6
#define Rx_1__0__PORT 12u
#define Rx_1__0__SHIFT 6u
#define Rx_1__AG CYREG_PRT12_AG
#define Rx_1__BIE CYREG_PRT12_BIE
#define Rx_1__BIT_MASK CYREG_PRT12_BIT_MASK
#define Rx_1__BYP CYREG_PRT12_BYP
#define Rx_1__DM0 CYREG_PRT12_DM0
#define Rx_1__DM1 CYREG_PRT12_DM1
#define Rx_1__DM2 CYREG_PRT12_DM2
#define Rx_1__DR CYREG_PRT12_DR
#define Rx_1__INP_DIS CYREG_PRT12_INP_DIS
#define Rx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define Rx_1__MASK 0x40u
#define Rx_1__PORT 12u
#define Rx_1__PRT CYREG_PRT12_PRT
#define Rx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define Rx_1__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define Rx_1__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define Rx_1__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define Rx_1__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define Rx_1__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define Rx_1__PS CYREG_PRT12_PS
#define Rx_1__SHIFT 6u
#define Rx_1__SIO_CFG CYREG_PRT12_SIO_CFG
#define Rx_1__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define Rx_1__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define Rx_1__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define Rx_1__SLW CYREG_PRT12_SLW

/* UART */
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB08_09_ACTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB08_09_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB08_09_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB08_09_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_COUNT_COUNT_REG CYREG_B1_UDB08_09_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_MASK_MASK_REG CYREG_B1_UDB08_09_MSK
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_MASK_PERIOD_REG CYREG_B1_UDB08_09_MSK
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_PERIOD_MASK_REG CYREG_B1_UDB08_09_MSK
#define UART_BUART_sCR_SyncCtl_CtrlReg__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB08_09_MSK
#define UART_BUART_sCR_SyncCtl_CtrlReg__5__MASK 0x20u
#define UART_BUART_sCR_SyncCtl_CtrlReg__5__POS 5
#define UART_BUART_sCR_SyncCtl_CtrlReg__6__MASK 0x40u
#define UART_BUART_sCR_SyncCtl_CtrlReg__6__POS 6
#define UART_BUART_sCR_SyncCtl_CtrlReg__7__MASK 0x80u
#define UART_BUART_sCR_SyncCtl_CtrlReg__7__POS 7
#define UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_AUX_CTL_REG CYREG_B1_UDB08_ACTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG CYREG_B1_UDB08_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_ST_REG CYREG_B1_UDB08_ST_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__COUNT_REG CYREG_B1_UDB08_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__COUNT_ST_REG CYREG_B1_UDB08_ST_CTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__MASK 0xE0u
#define UART_BUART_sCR_SyncCtl_CtrlReg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define UART_BUART_sCR_SyncCtl_CtrlReg__PERIOD_REG CYREG_B1_UDB08_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB09_10_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB09_10_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB09_10_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB09_10_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB09_CTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB09_ST_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB09_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB09_ST_CTL
#define UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB09_MSK
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB09_10_ST
#define UART_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB09_MSK
#define UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB09_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB09_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB09_ST
#define UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B1_UDB08_09_A0
#define UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B1_UDB08_09_A1
#define UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B1_UDB08_09_D0
#define UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B1_UDB08_09_D1
#define UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB08_09_ACTL
#define UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B1_UDB08_09_F0
#define UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B1_UDB08_09_F1
#define UART_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B1_UDB08_A0_A1
#define UART_BUART_sRX_RxShifter_u0__A0_REG CYREG_B1_UDB08_A0
#define UART_BUART_sRX_RxShifter_u0__A1_REG CYREG_B1_UDB08_A1
#define UART_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B1_UDB08_D0_D1
#define UART_BUART_sRX_RxShifter_u0__D0_REG CYREG_B1_UDB08_D0
#define UART_BUART_sRX_RxShifter_u0__D1_REG CYREG_B1_UDB08_D1
#define UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B1_UDB08_ACTL
#define UART_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B1_UDB08_F0_F1
#define UART_BUART_sRX_RxShifter_u0__F0_REG CYREG_B1_UDB08_F0
#define UART_BUART_sRX_RxShifter_u0__F1_REG CYREG_B1_UDB08_F1
#define UART_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define UART_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define UART_BUART_sRX_RxSts__0__MASK 0x01u
#define UART_BUART_sRX_RxSts__0__POS 0
#define UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B0_UDB11_12_ST
#define UART_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_BUART_sRX_RxSts__3__POS 3
#define UART_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_BUART_sRX_RxSts__4__POS 4
#define UART_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_BUART_sRX_RxSts__5__POS 5
#define UART_BUART_sRX_RxSts__6__MASK 0x40u
#define UART_BUART_sRX_RxSts__6__POS 6
#define UART_BUART_sRX_RxSts__MASK 0x79u
#define UART_BUART_sRX_RxSts__MASK_REG CYREG_B0_UDB11_MSK
#define UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define UART_BUART_sRX_RxSts__STATUS_REG CYREG_B0_UDB11_ST
#define UART_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define UART_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define UART_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define UART_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_IntClock__INDEX 0x00u
#define UART_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_IntClock__PM_ACT_MSK 0x01u
#define UART_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_IntClock__PM_STBY_MSK 0x01u
#define UART_RXInternalInterrupt__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define UART_RXInternalInterrupt__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define UART_RXInternalInterrupt__INTC_MASK 0x01u
#define UART_RXInternalInterrupt__INTC_NUMBER 0u
#define UART_RXInternalInterrupt__INTC_PRIOR_NUM 7u
#define UART_RXInternalInterrupt__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define UART_RXInternalInterrupt__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define UART_RXInternalInterrupt__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* GREEN */
#define GREEN__0__INTTYPE CYREG_PICU12_INTTYPE4
#define GREEN__0__MASK 0x10u
#define GREEN__0__PC CYREG_PRT12_PC4
#define GREEN__0__PORT 12u
#define GREEN__0__SHIFT 4u
#define GREEN__AG CYREG_PRT12_AG
#define GREEN__BIE CYREG_PRT12_BIE
#define GREEN__BIT_MASK CYREG_PRT12_BIT_MASK
#define GREEN__BYP CYREG_PRT12_BYP
#define GREEN__DM0 CYREG_PRT12_DM0
#define GREEN__DM1 CYREG_PRT12_DM1
#define GREEN__DM2 CYREG_PRT12_DM2
#define GREEN__DR CYREG_PRT12_DR
#define GREEN__INP_DIS CYREG_PRT12_INP_DIS
#define GREEN__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define GREEN__MASK 0x10u
#define GREEN__PORT 12u
#define GREEN__PRT CYREG_PRT12_PRT
#define GREEN__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define GREEN__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define GREEN__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define GREEN__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define GREEN__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define GREEN__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define GREEN__PS CYREG_PRT12_PS
#define GREEN__SHIFT 4u
#define GREEN__SIO_CFG CYREG_PRT12_SIO_CFG
#define GREEN__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define GREEN__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define GREEN__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define GREEN__SLW CYREG_PRT12_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "LCD"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000003u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
