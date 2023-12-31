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

/* Com */
#define Com__0__INTTYPE CYREG_PICU2_INTTYPE4
#define Com__0__MASK 0x10u
#define Com__0__PC CYREG_PRT2_PC4
#define Com__0__PORT 2u
#define Com__0__SHIFT 4u
#define Com__1__INTTYPE CYREG_PICU2_INTTYPE3
#define Com__1__MASK 0x08u
#define Com__1__PC CYREG_PRT2_PC3
#define Com__1__PORT 2u
#define Com__1__SHIFT 3u
#define Com__2__INTTYPE CYREG_PICU2_INTTYPE2
#define Com__2__MASK 0x04u
#define Com__2__PC CYREG_PRT2_PC2
#define Com__2__PORT 2u
#define Com__2__SHIFT 2u
#define Com__3__INTTYPE CYREG_PICU2_INTTYPE1
#define Com__3__MASK 0x02u
#define Com__3__PC CYREG_PRT2_PC1
#define Com__3__PORT 2u
#define Com__3__SHIFT 1u
#define Com__AG CYREG_PRT2_AG
#define Com__AMUX CYREG_PRT2_AMUX
#define Com__BIE CYREG_PRT2_BIE
#define Com__BIT_MASK CYREG_PRT2_BIT_MASK
#define Com__BYP CYREG_PRT2_BYP
#define Com__CTL CYREG_PRT2_CTL
#define Com__DM0 CYREG_PRT2_DM0
#define Com__DM1 CYREG_PRT2_DM1
#define Com__DM2 CYREG_PRT2_DM2
#define Com__DR CYREG_PRT2_DR
#define Com__INP_DIS CYREG_PRT2_INP_DIS
#define Com__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Com__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Com__LCD_EN CYREG_PRT2_LCD_EN
#define Com__PORT 2u
#define Com__PRT CYREG_PRT2_PRT
#define Com__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Com__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Com__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Com__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Com__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Com__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Com__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Com__PS CYREG_PRT2_PS
#define Com__SLW CYREG_PRT2_SLW

/* Mas */
#define Mas__0__INTTYPE CYREG_PICU3_INTTYPE0
#define Mas__0__MASK 0x01u
#define Mas__0__PC CYREG_PRT3_PC0
#define Mas__0__PORT 3u
#define Mas__0__SHIFT 0u
#define Mas__AG CYREG_PRT3_AG
#define Mas__AMUX CYREG_PRT3_AMUX
#define Mas__BIE CYREG_PRT3_BIE
#define Mas__BIT_MASK CYREG_PRT3_BIT_MASK
#define Mas__BYP CYREG_PRT3_BYP
#define Mas__CTL CYREG_PRT3_CTL
#define Mas__DM0 CYREG_PRT3_DM0
#define Mas__DM1 CYREG_PRT3_DM1
#define Mas__DM2 CYREG_PRT3_DM2
#define Mas__DR CYREG_PRT3_DR
#define Mas__INP_DIS CYREG_PRT3_INP_DIS
#define Mas__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Mas__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Mas__LCD_EN CYREG_PRT3_LCD_EN
#define Mas__MASK 0x01u
#define Mas__PORT 3u
#define Mas__PRT CYREG_PRT3_PRT
#define Mas__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Mas__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Mas__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Mas__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Mas__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Mas__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Mas__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Mas__PS CYREG_PRT3_PS
#define Mas__SHIFT 0u
#define Mas__SLW CYREG_PRT3_SLW

/* PWM */
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB08_09_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB08_09_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB08_09_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB08_09_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB08_09_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB08_09_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB08_09_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB08_09_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB08_09_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define PWM_PWMUDB_genblk1_ctrlreg__7__POS 7
#define PWM_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB08_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B0_UDB08_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB08_ST_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B0_UDB08_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B0_UDB08_ST_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define PWM_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B0_UDB08_MSK
#define PWM_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define PWM_PWMUDB_genblk8_stsreg__0__POS 0
#define PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB08_09_ACTL
#define PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_B0_UDB08_09_ST
#define PWM_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define PWM_PWMUDB_genblk8_stsreg__2__POS 2
#define PWM_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define PWM_PWMUDB_genblk8_stsreg__3__POS 3
#define PWM_PWMUDB_genblk8_stsreg__MASK 0x0Du
#define PWM_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B0_UDB08_MSK
#define PWM_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define PWM_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define PWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB08_ACTL
#define PWM_PWMUDB_genblk8_stsreg__STATUS_CNT_REG CYREG_B0_UDB08_ST_CTL
#define PWM_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB08_ST_CTL
#define PWM_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B0_UDB08_ST
#define PWM_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB08_09_A0
#define PWM_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB08_09_A1
#define PWM_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB08_09_D0
#define PWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB08_09_D1
#define PWM_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB08_09_ACTL
#define PWM_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB08_09_F0
#define PWM_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB08_09_F1
#define PWM_PWMUDB_sP16_pwmdp_u0__A0_A1_REG CYREG_B0_UDB08_A0_A1
#define PWM_PWMUDB_sP16_pwmdp_u0__A0_REG CYREG_B0_UDB08_A0
#define PWM_PWMUDB_sP16_pwmdp_u0__A1_REG CYREG_B0_UDB08_A1
#define PWM_PWMUDB_sP16_pwmdp_u0__D0_D1_REG CYREG_B0_UDB08_D0_D1
#define PWM_PWMUDB_sP16_pwmdp_u0__D0_REG CYREG_B0_UDB08_D0
#define PWM_PWMUDB_sP16_pwmdp_u0__D1_REG CYREG_B0_UDB08_D1
#define PWM_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB08_ACTL
#define PWM_PWMUDB_sP16_pwmdp_u0__F0_F1_REG CYREG_B0_UDB08_F0_F1
#define PWM_PWMUDB_sP16_pwmdp_u0__F0_REG CYREG_B0_UDB08_F0
#define PWM_PWMUDB_sP16_pwmdp_u0__F1_REG CYREG_B0_UDB08_F1
#define PWM_PWMUDB_sP16_pwmdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define PWM_PWMUDB_sP16_pwmdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB08_MSK_ACTL
#define PWM_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG CYREG_B0_UDB09_10_A0
#define PWM_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG CYREG_B0_UDB09_10_A1
#define PWM_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG CYREG_B0_UDB09_10_D0
#define PWM_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG CYREG_B0_UDB09_10_D1
#define PWM_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define PWM_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG CYREG_B0_UDB09_10_F0
#define PWM_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG CYREG_B0_UDB09_10_F1
#define PWM_PWMUDB_sP16_pwmdp_u1__A0_A1_REG CYREG_B0_UDB09_A0_A1
#define PWM_PWMUDB_sP16_pwmdp_u1__A0_REG CYREG_B0_UDB09_A0
#define PWM_PWMUDB_sP16_pwmdp_u1__A1_REG CYREG_B0_UDB09_A1
#define PWM_PWMUDB_sP16_pwmdp_u1__D0_D1_REG CYREG_B0_UDB09_D0_D1
#define PWM_PWMUDB_sP16_pwmdp_u1__D0_REG CYREG_B0_UDB09_D0
#define PWM_PWMUDB_sP16_pwmdp_u1__D1_REG CYREG_B0_UDB09_D1
#define PWM_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define PWM_PWMUDB_sP16_pwmdp_u1__F0_F1_REG CYREG_B0_UDB09_F0_F1
#define PWM_PWMUDB_sP16_pwmdp_u1__F0_REG CYREG_B0_UDB09_F0
#define PWM_PWMUDB_sP16_pwmdp_u1__F1_REG CYREG_B0_UDB09_F1
#define PWM_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define PWM_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define PWM_servo__0__INTTYPE CYREG_PICU0_INTTYPE7
#define PWM_servo__0__MASK 0x80u
#define PWM_servo__0__PC CYREG_PRT0_PC7
#define PWM_servo__0__PORT 0u
#define PWM_servo__0__SHIFT 7u
#define PWM_servo__AG CYREG_PRT0_AG
#define PWM_servo__AMUX CYREG_PRT0_AMUX
#define PWM_servo__BIE CYREG_PRT0_BIE
#define PWM_servo__BIT_MASK CYREG_PRT0_BIT_MASK
#define PWM_servo__BYP CYREG_PRT0_BYP
#define PWM_servo__CTL CYREG_PRT0_CTL
#define PWM_servo__DM0 CYREG_PRT0_DM0
#define PWM_servo__DM1 CYREG_PRT0_DM1
#define PWM_servo__DM2 CYREG_PRT0_DM2
#define PWM_servo__DR CYREG_PRT0_DR
#define PWM_servo__INP_DIS CYREG_PRT0_INP_DIS
#define PWM_servo__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define PWM_servo__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define PWM_servo__LCD_EN CYREG_PRT0_LCD_EN
#define PWM_servo__MASK 0x80u
#define PWM_servo__PORT 0u
#define PWM_servo__PRT CYREG_PRT0_PRT
#define PWM_servo__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define PWM_servo__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define PWM_servo__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define PWM_servo__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define PWM_servo__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define PWM_servo__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define PWM_servo__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define PWM_servo__PS CYREG_PRT0_PS
#define PWM_servo__SHIFT 7u
#define PWM_servo__SLW CYREG_PRT0_SLW

/* Seg */
#define Seg__0__AG CYREG_PRT2_AG
#define Seg__0__AMUX CYREG_PRT2_AMUX
#define Seg__0__BIE CYREG_PRT2_BIE
#define Seg__0__BIT_MASK CYREG_PRT2_BIT_MASK
#define Seg__0__BYP CYREG_PRT2_BYP
#define Seg__0__CTL CYREG_PRT2_CTL
#define Seg__0__DM0 CYREG_PRT2_DM0
#define Seg__0__DM1 CYREG_PRT2_DM1
#define Seg__0__DM2 CYREG_PRT2_DM2
#define Seg__0__DR CYREG_PRT2_DR
#define Seg__0__INP_DIS CYREG_PRT2_INP_DIS
#define Seg__0__INTTYPE CYREG_PICU2_INTTYPE5
#define Seg__0__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Seg__0__LCD_EN CYREG_PRT2_LCD_EN
#define Seg__0__MASK 0x20u
#define Seg__0__PC CYREG_PRT2_PC5
#define Seg__0__PORT 2u
#define Seg__0__PRT CYREG_PRT2_PRT
#define Seg__0__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Seg__0__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Seg__0__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Seg__0__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Seg__0__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Seg__0__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Seg__0__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Seg__0__PS CYREG_PRT2_PS
#define Seg__0__SHIFT 5u
#define Seg__0__SLW CYREG_PRT2_SLW
#define Seg__1__AG CYREG_PRT2_AG
#define Seg__1__AMUX CYREG_PRT2_AMUX
#define Seg__1__BIE CYREG_PRT2_BIE
#define Seg__1__BIT_MASK CYREG_PRT2_BIT_MASK
#define Seg__1__BYP CYREG_PRT2_BYP
#define Seg__1__CTL CYREG_PRT2_CTL
#define Seg__1__DM0 CYREG_PRT2_DM0
#define Seg__1__DM1 CYREG_PRT2_DM1
#define Seg__1__DM2 CYREG_PRT2_DM2
#define Seg__1__DR CYREG_PRT2_DR
#define Seg__1__INP_DIS CYREG_PRT2_INP_DIS
#define Seg__1__INTTYPE CYREG_PICU2_INTTYPE6
#define Seg__1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Seg__1__LCD_EN CYREG_PRT2_LCD_EN
#define Seg__1__MASK 0x40u
#define Seg__1__PC CYREG_PRT2_PC6
#define Seg__1__PORT 2u
#define Seg__1__PRT CYREG_PRT2_PRT
#define Seg__1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Seg__1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Seg__1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Seg__1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Seg__1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Seg__1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Seg__1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Seg__1__PS CYREG_PRT2_PS
#define Seg__1__SHIFT 6u
#define Seg__1__SLW CYREG_PRT2_SLW
#define Seg__2__AG CYREG_PRT2_AG
#define Seg__2__AMUX CYREG_PRT2_AMUX
#define Seg__2__BIE CYREG_PRT2_BIE
#define Seg__2__BIT_MASK CYREG_PRT2_BIT_MASK
#define Seg__2__BYP CYREG_PRT2_BYP
#define Seg__2__CTL CYREG_PRT2_CTL
#define Seg__2__DM0 CYREG_PRT2_DM0
#define Seg__2__DM1 CYREG_PRT2_DM1
#define Seg__2__DM2 CYREG_PRT2_DM2
#define Seg__2__DR CYREG_PRT2_DR
#define Seg__2__INP_DIS CYREG_PRT2_INP_DIS
#define Seg__2__INTTYPE CYREG_PICU2_INTTYPE7
#define Seg__2__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Seg__2__LCD_EN CYREG_PRT2_LCD_EN
#define Seg__2__MASK 0x80u
#define Seg__2__PC CYREG_PRT2_PC7
#define Seg__2__PORT 2u
#define Seg__2__PRT CYREG_PRT2_PRT
#define Seg__2__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Seg__2__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Seg__2__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Seg__2__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Seg__2__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Seg__2__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Seg__2__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Seg__2__PS CYREG_PRT2_PS
#define Seg__2__SHIFT 7u
#define Seg__2__SLW CYREG_PRT2_SLW
#define Seg__3__AG CYREG_PRT1_AG
#define Seg__3__AMUX CYREG_PRT1_AMUX
#define Seg__3__BIE CYREG_PRT1_BIE
#define Seg__3__BIT_MASK CYREG_PRT1_BIT_MASK
#define Seg__3__BYP CYREG_PRT1_BYP
#define Seg__3__CTL CYREG_PRT1_CTL
#define Seg__3__DM0 CYREG_PRT1_DM0
#define Seg__3__DM1 CYREG_PRT1_DM1
#define Seg__3__DM2 CYREG_PRT1_DM2
#define Seg__3__DR CYREG_PRT1_DR
#define Seg__3__INP_DIS CYREG_PRT1_INP_DIS
#define Seg__3__INTTYPE CYREG_PICU1_INTTYPE2
#define Seg__3__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Seg__3__LCD_EN CYREG_PRT1_LCD_EN
#define Seg__3__MASK 0x04u
#define Seg__3__PC CYREG_PRT1_PC2
#define Seg__3__PORT 1u
#define Seg__3__PRT CYREG_PRT1_PRT
#define Seg__3__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Seg__3__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Seg__3__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Seg__3__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Seg__3__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Seg__3__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Seg__3__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Seg__3__PS CYREG_PRT1_PS
#define Seg__3__SHIFT 2u
#define Seg__3__SLW CYREG_PRT1_SLW
#define Seg__4__AG CYREG_PRT1_AG
#define Seg__4__AMUX CYREG_PRT1_AMUX
#define Seg__4__BIE CYREG_PRT1_BIE
#define Seg__4__BIT_MASK CYREG_PRT1_BIT_MASK
#define Seg__4__BYP CYREG_PRT1_BYP
#define Seg__4__CTL CYREG_PRT1_CTL
#define Seg__4__DM0 CYREG_PRT1_DM0
#define Seg__4__DM1 CYREG_PRT1_DM1
#define Seg__4__DM2 CYREG_PRT1_DM2
#define Seg__4__DR CYREG_PRT1_DR
#define Seg__4__INP_DIS CYREG_PRT1_INP_DIS
#define Seg__4__INTTYPE CYREG_PICU1_INTTYPE4
#define Seg__4__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Seg__4__LCD_EN CYREG_PRT1_LCD_EN
#define Seg__4__MASK 0x10u
#define Seg__4__PC CYREG_PRT1_PC4
#define Seg__4__PORT 1u
#define Seg__4__PRT CYREG_PRT1_PRT
#define Seg__4__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Seg__4__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Seg__4__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Seg__4__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Seg__4__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Seg__4__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Seg__4__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Seg__4__PS CYREG_PRT1_PS
#define Seg__4__SHIFT 4u
#define Seg__4__SLW CYREG_PRT1_SLW
#define Seg__5__AG CYREG_PRT1_AG
#define Seg__5__AMUX CYREG_PRT1_AMUX
#define Seg__5__BIE CYREG_PRT1_BIE
#define Seg__5__BIT_MASK CYREG_PRT1_BIT_MASK
#define Seg__5__BYP CYREG_PRT1_BYP
#define Seg__5__CTL CYREG_PRT1_CTL
#define Seg__5__DM0 CYREG_PRT1_DM0
#define Seg__5__DM1 CYREG_PRT1_DM1
#define Seg__5__DM2 CYREG_PRT1_DM2
#define Seg__5__DR CYREG_PRT1_DR
#define Seg__5__INP_DIS CYREG_PRT1_INP_DIS
#define Seg__5__INTTYPE CYREG_PICU1_INTTYPE5
#define Seg__5__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Seg__5__LCD_EN CYREG_PRT1_LCD_EN
#define Seg__5__MASK 0x20u
#define Seg__5__PC CYREG_PRT1_PC5
#define Seg__5__PORT 1u
#define Seg__5__PRT CYREG_PRT1_PRT
#define Seg__5__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Seg__5__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Seg__5__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Seg__5__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Seg__5__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Seg__5__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Seg__5__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Seg__5__PS CYREG_PRT1_PS
#define Seg__5__SHIFT 5u
#define Seg__5__SLW CYREG_PRT1_SLW
#define Seg__6__AG CYREG_PRT1_AG
#define Seg__6__AMUX CYREG_PRT1_AMUX
#define Seg__6__BIE CYREG_PRT1_BIE
#define Seg__6__BIT_MASK CYREG_PRT1_BIT_MASK
#define Seg__6__BYP CYREG_PRT1_BYP
#define Seg__6__CTL CYREG_PRT1_CTL
#define Seg__6__DM0 CYREG_PRT1_DM0
#define Seg__6__DM1 CYREG_PRT1_DM1
#define Seg__6__DM2 CYREG_PRT1_DM2
#define Seg__6__DR CYREG_PRT1_DR
#define Seg__6__INP_DIS CYREG_PRT1_INP_DIS
#define Seg__6__INTTYPE CYREG_PICU1_INTTYPE6
#define Seg__6__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Seg__6__LCD_EN CYREG_PRT1_LCD_EN
#define Seg__6__MASK 0x40u
#define Seg__6__PC CYREG_PRT1_PC6
#define Seg__6__PORT 1u
#define Seg__6__PRT CYREG_PRT1_PRT
#define Seg__6__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Seg__6__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Seg__6__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Seg__6__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Seg__6__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Seg__6__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Seg__6__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Seg__6__PS CYREG_PRT1_PS
#define Seg__6__SHIFT 6u
#define Seg__6__SLW CYREG_PRT1_SLW
#define Seg__7__AG CYREG_PRT1_AG
#define Seg__7__AMUX CYREG_PRT1_AMUX
#define Seg__7__BIE CYREG_PRT1_BIE
#define Seg__7__BIT_MASK CYREG_PRT1_BIT_MASK
#define Seg__7__BYP CYREG_PRT1_BYP
#define Seg__7__CTL CYREG_PRT1_CTL
#define Seg__7__DM0 CYREG_PRT1_DM0
#define Seg__7__DM1 CYREG_PRT1_DM1
#define Seg__7__DM2 CYREG_PRT1_DM2
#define Seg__7__DR CYREG_PRT1_DR
#define Seg__7__INP_DIS CYREG_PRT1_INP_DIS
#define Seg__7__INTTYPE CYREG_PICU1_INTTYPE7
#define Seg__7__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Seg__7__LCD_EN CYREG_PRT1_LCD_EN
#define Seg__7__MASK 0x80u
#define Seg__7__PC CYREG_PRT1_PC7
#define Seg__7__PORT 1u
#define Seg__7__PRT CYREG_PRT1_PRT
#define Seg__7__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Seg__7__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Seg__7__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Seg__7__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Seg__7__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Seg__7__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Seg__7__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Seg__7__PS CYREG_PRT1_PS
#define Seg__7__SHIFT 7u
#define Seg__7__SLW CYREG_PRT1_SLW

/* Menos */
#define Menos__0__INTTYPE CYREG_PICU3_INTTYPE1
#define Menos__0__MASK 0x02u
#define Menos__0__PC CYREG_PRT3_PC1
#define Menos__0__PORT 3u
#define Menos__0__SHIFT 1u
#define Menos__AG CYREG_PRT3_AG
#define Menos__AMUX CYREG_PRT3_AMUX
#define Menos__BIE CYREG_PRT3_BIE
#define Menos__BIT_MASK CYREG_PRT3_BIT_MASK
#define Menos__BYP CYREG_PRT3_BYP
#define Menos__CTL CYREG_PRT3_CTL
#define Menos__DM0 CYREG_PRT3_DM0
#define Menos__DM1 CYREG_PRT3_DM1
#define Menos__DM2 CYREG_PRT3_DM2
#define Menos__DR CYREG_PRT3_DR
#define Menos__INP_DIS CYREG_PRT3_INP_DIS
#define Menos__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Menos__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Menos__LCD_EN CYREG_PRT3_LCD_EN
#define Menos__MASK 0x02u
#define Menos__PORT 3u
#define Menos__PRT CYREG_PRT3_PRT
#define Menos__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Menos__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Menos__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Menos__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Menos__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Menos__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Menos__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Menos__PS CYREG_PRT3_PS
#define Menos__SHIFT 1u
#define Menos__SLW CYREG_PRT3_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* Clock_2 */
#define Clock_2__CFG0 CYREG_CLKDIST_DCFG2_CFG0
#define Clock_2__CFG1 CYREG_CLKDIST_DCFG2_CFG1
#define Clock_2__CFG2 CYREG_CLKDIST_DCFG2_CFG2
#define Clock_2__CFG2_SRC_SEL_MASK 0x07u
#define Clock_2__INDEX 0x02u
#define Clock_2__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_2__PM_ACT_MSK 0x04u
#define Clock_2__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_2__PM_STBY_MSK 0x04u

/* Reg_btn */
#define Reg_btn_sts_sts_reg__0__MASK 0x01u
#define Reg_btn_sts_sts_reg__0__POS 0
#define Reg_btn_sts_sts_reg__1__MASK 0x02u
#define Reg_btn_sts_sts_reg__1__POS 1
#define Reg_btn_sts_sts_reg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define Reg_btn_sts_sts_reg__16BIT_STATUS_REG CYREG_B0_UDB09_10_ST
#define Reg_btn_sts_sts_reg__MASK 0x03u
#define Reg_btn_sts_sts_reg__MASK_REG CYREG_B0_UDB09_MSK
#define Reg_btn_sts_sts_reg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Reg_btn_sts_sts_reg__PER_ST_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Reg_btn_sts_sts_reg__STATUS_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define Reg_btn_sts_sts_reg__STATUS_CNT_REG CYREG_B0_UDB09_ST_CTL
#define Reg_btn_sts_sts_reg__STATUS_CONTROL_REG CYREG_B0_UDB09_ST_CTL
#define Reg_btn_sts_sts_reg__STATUS_REG CYREG_B0_UDB09_ST

/* LED_Grados */
#define LED_Grados_ClkInternal__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define LED_Grados_ClkInternal__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define LED_Grados_ClkInternal__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define LED_Grados_ClkInternal__CFG2_SRC_SEL_MASK 0x07u
#define LED_Grados_ClkInternal__INDEX 0x01u
#define LED_Grados_ClkInternal__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define LED_Grados_ClkInternal__PM_ACT_MSK 0x02u
#define LED_Grados_ClkInternal__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define LED_Grados_ClkInternal__PM_STBY_MSK 0x02u
#define LED_Grados_Com_Driver_Sync_ctrl_reg__0__MASK 0x01u
#define LED_Grados_Com_Driver_Sync_ctrl_reg__0__POS 0
#define LED_Grados_Com_Driver_Sync_ctrl_reg__1__MASK 0x02u
#define LED_Grados_Com_Driver_Sync_ctrl_reg__1__POS 1
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB13_14_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB13_14_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_B0_UDB13_14_MSK
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB13_14_MSK
#define LED_Grados_Com_Driver_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define LED_Grados_Com_Driver_Sync_ctrl_reg__2__MASK 0x04u
#define LED_Grados_Com_Driver_Sync_ctrl_reg__2__POS 2
#define LED_Grados_Com_Driver_Sync_ctrl_reg__3__MASK 0x08u
#define LED_Grados_Com_Driver_Sync_ctrl_reg__3__POS 3
#define LED_Grados_Com_Driver_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__CONTROL_REG CYREG_B0_UDB13_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__CONTROL_ST_REG CYREG_B0_UDB13_ST_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__COUNT_REG CYREG_B0_UDB13_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__COUNT_ST_REG CYREG_B0_UDB13_ST_CTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__MASK 0x0Fu
#define LED_Grados_Com_Driver_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define LED_Grados_Com_Driver_Sync_ctrl_reg__PERIOD_REG CYREG_B0_UDB13_MSK
#define LED_Grados_DMA_Com__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define LED_Grados_DMA_Com__DRQ_NUMBER 0u
#define LED_Grados_DMA_Com__NUMBEROF_TDS 0u
#define LED_Grados_DMA_Com__PRIORITY 2u
#define LED_Grados_DMA_Com__TERMIN_EN 0u
#define LED_Grados_DMA_Com__TERMIN_SEL 0u
#define LED_Grados_DMA_Com__TERMOUT0_EN 1u
#define LED_Grados_DMA_Com__TERMOUT0_SEL 0u
#define LED_Grados_DMA_Com__TERMOUT1_EN 0u
#define LED_Grados_DMA_Com__TERMOUT1_SEL 0u
#define LED_Grados_DMA_Seg__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define LED_Grados_DMA_Seg__DRQ_NUMBER 1u
#define LED_Grados_DMA_Seg__NUMBEROF_TDS 0u
#define LED_Grados_DMA_Seg__PRIORITY 2u
#define LED_Grados_DMA_Seg__TERMIN_EN 0u
#define LED_Grados_DMA_Seg__TERMIN_SEL 0u
#define LED_Grados_DMA_Seg__TERMOUT0_EN 1u
#define LED_Grados_DMA_Seg__TERMOUT0_SEL 1u
#define LED_Grados_DMA_Seg__TERMOUT1_EN 0u
#define LED_Grados_DMA_Seg__TERMOUT1_SEL 0u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__0__MASK 0x01u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__0__POS 0
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__1__MASK 0x02u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__1__POS 1
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB09_10_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB09_10_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_B0_UDB09_10_MSK
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB09_10_MSK
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__2__MASK 0x04u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__2__POS 2
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__3__MASK 0x08u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__3__POS 3
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__4__MASK 0x10u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__4__POS 4
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__5__MASK 0x20u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__5__POS 5
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__6__MASK 0x40u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__6__POS 6
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__7__MASK 0x80u
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__7__POS 7
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__CONTROL_REG CYREG_B0_UDB09_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__CONTROL_ST_REG CYREG_B0_UDB09_ST_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__COUNT_REG CYREG_B0_UDB09_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__COUNT_ST_REG CYREG_B0_UDB09_ST_CTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__MASK 0xFFu
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define LED_Grados_Seg_Driver_L_Sync_ctrl_reg__PERIOD_REG CYREG_B0_UDB09_MSK

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "Servo_s90"
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
#define CYDEV_INTR_RISING 0x00000000u
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
#define DMA_CHANNELS_USED__MASK0 0x00000003u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
