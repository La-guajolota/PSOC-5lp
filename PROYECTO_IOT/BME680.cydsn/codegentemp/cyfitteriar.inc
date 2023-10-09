;
; File Name: cyfitteriar.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* E */
E__0__INTTYPE EQU CYREG_PICU3_INTTYPE3
E__0__MASK EQU 0x08
E__0__PC EQU CYREG_PRT3_PC3
E__0__PORT EQU 3
E__0__SHIFT EQU 3
E__AG EQU CYREG_PRT3_AG
E__AMUX EQU CYREG_PRT3_AMUX
E__BIE EQU CYREG_PRT3_BIE
E__BIT_MASK EQU CYREG_PRT3_BIT_MASK
E__BYP EQU CYREG_PRT3_BYP
E__CTL EQU CYREG_PRT3_CTL
E__DM0 EQU CYREG_PRT3_DM0
E__DM1 EQU CYREG_PRT3_DM1
E__DM2 EQU CYREG_PRT3_DM2
E__DR EQU CYREG_PRT3_DR
E__INP_DIS EQU CYREG_PRT3_INP_DIS
E__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
E__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
E__LCD_EN EQU CYREG_PRT3_LCD_EN
E__MASK EQU 0x08
E__PORT EQU 3
E__PRT EQU CYREG_PRT3_PRT
E__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
E__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
E__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
E__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
E__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
E__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
E__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
E__PS EQU CYREG_PRT3_PS
E__SHIFT EQU 3
E__SLW EQU CYREG_PRT3_SLW

/* D4 */
D4__0__INTTYPE EQU CYREG_PICU3_INTTYPE4
D4__0__MASK EQU 0x10
D4__0__PC EQU CYREG_PRT3_PC4
D4__0__PORT EQU 3
D4__0__SHIFT EQU 4
D4__AG EQU CYREG_PRT3_AG
D4__AMUX EQU CYREG_PRT3_AMUX
D4__BIE EQU CYREG_PRT3_BIE
D4__BIT_MASK EQU CYREG_PRT3_BIT_MASK
D4__BYP EQU CYREG_PRT3_BYP
D4__CTL EQU CYREG_PRT3_CTL
D4__DM0 EQU CYREG_PRT3_DM0
D4__DM1 EQU CYREG_PRT3_DM1
D4__DM2 EQU CYREG_PRT3_DM2
D4__DR EQU CYREG_PRT3_DR
D4__INP_DIS EQU CYREG_PRT3_INP_DIS
D4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
D4__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
D4__LCD_EN EQU CYREG_PRT3_LCD_EN
D4__MASK EQU 0x10
D4__PORT EQU 3
D4__PRT EQU CYREG_PRT3_PRT
D4__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
D4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
D4__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
D4__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
D4__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
D4__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
D4__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
D4__PS EQU CYREG_PRT3_PS
D4__SHIFT EQU 4
D4__SLW EQU CYREG_PRT3_SLW

/* D5 */
D5__0__INTTYPE EQU CYREG_PICU3_INTTYPE5
D5__0__MASK EQU 0x20
D5__0__PC EQU CYREG_PRT3_PC5
D5__0__PORT EQU 3
D5__0__SHIFT EQU 5
D5__AG EQU CYREG_PRT3_AG
D5__AMUX EQU CYREG_PRT3_AMUX
D5__BIE EQU CYREG_PRT3_BIE
D5__BIT_MASK EQU CYREG_PRT3_BIT_MASK
D5__BYP EQU CYREG_PRT3_BYP
D5__CTL EQU CYREG_PRT3_CTL
D5__DM0 EQU CYREG_PRT3_DM0
D5__DM1 EQU CYREG_PRT3_DM1
D5__DM2 EQU CYREG_PRT3_DM2
D5__DR EQU CYREG_PRT3_DR
D5__INP_DIS EQU CYREG_PRT3_INP_DIS
D5__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
D5__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
D5__LCD_EN EQU CYREG_PRT3_LCD_EN
D5__MASK EQU 0x20
D5__PORT EQU 3
D5__PRT EQU CYREG_PRT3_PRT
D5__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
D5__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
D5__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
D5__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
D5__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
D5__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
D5__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
D5__PS EQU CYREG_PRT3_PS
D5__SHIFT EQU 5
D5__SLW EQU CYREG_PRT3_SLW

/* D6 */
D6__0__INTTYPE EQU CYREG_PICU3_INTTYPE6
D6__0__MASK EQU 0x40
D6__0__PC EQU CYREG_PRT3_PC6
D6__0__PORT EQU 3
D6__0__SHIFT EQU 6
D6__AG EQU CYREG_PRT3_AG
D6__AMUX EQU CYREG_PRT3_AMUX
D6__BIE EQU CYREG_PRT3_BIE
D6__BIT_MASK EQU CYREG_PRT3_BIT_MASK
D6__BYP EQU CYREG_PRT3_BYP
D6__CTL EQU CYREG_PRT3_CTL
D6__DM0 EQU CYREG_PRT3_DM0
D6__DM1 EQU CYREG_PRT3_DM1
D6__DM2 EQU CYREG_PRT3_DM2
D6__DR EQU CYREG_PRT3_DR
D6__INP_DIS EQU CYREG_PRT3_INP_DIS
D6__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
D6__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
D6__LCD_EN EQU CYREG_PRT3_LCD_EN
D6__MASK EQU 0x40
D6__PORT EQU 3
D6__PRT EQU CYREG_PRT3_PRT
D6__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
D6__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
D6__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
D6__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
D6__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
D6__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
D6__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
D6__PS EQU CYREG_PRT3_PS
D6__SHIFT EQU 6
D6__SLW EQU CYREG_PRT3_SLW

/* D7 */
D7__0__INTTYPE EQU CYREG_PICU3_INTTYPE7
D7__0__MASK EQU 0x80
D7__0__PC EQU CYREG_PRT3_PC7
D7__0__PORT EQU 3
D7__0__SHIFT EQU 7
D7__AG EQU CYREG_PRT3_AG
D7__AMUX EQU CYREG_PRT3_AMUX
D7__BIE EQU CYREG_PRT3_BIE
D7__BIT_MASK EQU CYREG_PRT3_BIT_MASK
D7__BYP EQU CYREG_PRT3_BYP
D7__CTL EQU CYREG_PRT3_CTL
D7__DM0 EQU CYREG_PRT3_DM0
D7__DM1 EQU CYREG_PRT3_DM1
D7__DM2 EQU CYREG_PRT3_DM2
D7__DR EQU CYREG_PRT3_DR
D7__INP_DIS EQU CYREG_PRT3_INP_DIS
D7__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
D7__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
D7__LCD_EN EQU CYREG_PRT3_LCD_EN
D7__MASK EQU 0x80
D7__PORT EQU 3
D7__PRT EQU CYREG_PRT3_PRT
D7__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
D7__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
D7__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
D7__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
D7__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
D7__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
D7__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
D7__PS EQU CYREG_PRT3_PS
D7__SHIFT EQU 7
D7__SLW EQU CYREG_PRT3_SLW

/* RS */
RS__0__INTTYPE EQU CYREG_PICU3_INTTYPE2
RS__0__MASK EQU 0x04
RS__0__PC EQU CYREG_PRT3_PC2
RS__0__PORT EQU 3
RS__0__SHIFT EQU 2
RS__AG EQU CYREG_PRT3_AG
RS__AMUX EQU CYREG_PRT3_AMUX
RS__BIE EQU CYREG_PRT3_BIE
RS__BIT_MASK EQU CYREG_PRT3_BIT_MASK
RS__BYP EQU CYREG_PRT3_BYP
RS__CTL EQU CYREG_PRT3_CTL
RS__DM0 EQU CYREG_PRT3_DM0
RS__DM1 EQU CYREG_PRT3_DM1
RS__DM2 EQU CYREG_PRT3_DM2
RS__DR EQU CYREG_PRT3_DR
RS__INP_DIS EQU CYREG_PRT3_INP_DIS
RS__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
RS__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
RS__LCD_EN EQU CYREG_PRT3_LCD_EN
RS__MASK EQU 0x04
RS__PORT EQU 3
RS__PRT EQU CYREG_PRT3_PRT
RS__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
RS__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
RS__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
RS__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
RS__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
RS__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
RS__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
RS__PS EQU CYREG_PRT3_PS
RS__SHIFT EQU 2
RS__SLW EQU CYREG_PRT3_SLW

/* I2C */
I2C_I2C_FF__ADR EQU CYREG_I2C_ADR
I2C_I2C_FF__CFG EQU CYREG_I2C_CFG
I2C_I2C_FF__CLK_DIV1 EQU CYREG_I2C_CLK_DIV1
I2C_I2C_FF__CLK_DIV2 EQU CYREG_I2C_CLK_DIV2
I2C_I2C_FF__CSR EQU CYREG_I2C_CSR
I2C_I2C_FF__D EQU CYREG_I2C_D
I2C_I2C_FF__MCSR EQU CYREG_I2C_MCSR
I2C_I2C_FF__PM_ACT_CFG EQU CYREG_PM_ACT_CFG5
I2C_I2C_FF__PM_ACT_MSK EQU 0x04
I2C_I2C_FF__PM_STBY_CFG EQU CYREG_PM_STBY_CFG5
I2C_I2C_FF__PM_STBY_MSK EQU 0x04
I2C_I2C_FF__TMOUT_CFG0 EQU CYREG_I2C_TMOUT_CFG0
I2C_I2C_FF__TMOUT_CFG1 EQU CYREG_I2C_TMOUT_CFG1
I2C_I2C_FF__TMOUT_CSR EQU CYREG_I2C_TMOUT_CSR
I2C_I2C_FF__TMOUT_SR EQU CYREG_I2C_TMOUT_SR
I2C_I2C_FF__XCFG EQU CYREG_I2C_XCFG
I2C_I2C_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
I2C_I2C_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
I2C_I2C_IRQ__INTC_MASK EQU 0x8000
I2C_I2C_IRQ__INTC_NUMBER EQU 15
I2C_I2C_IRQ__INTC_PRIOR_NUM EQU 7
I2C_I2C_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_15
I2C_I2C_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
I2C_I2C_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* LCD */
LCD_Sync_ctrl_reg__0__MASK EQU 0x01
LCD_Sync_ctrl_reg__0__POS EQU 0
LCD_Sync_ctrl_reg__1__MASK EQU 0x02
LCD_Sync_ctrl_reg__1__POS EQU 1
LCD_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB05_06_ACTL
LCD_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB05_06_CTL
LCD_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB05_06_CTL
LCD_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB05_06_CTL
LCD_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB05_06_CTL
LCD_Sync_ctrl_reg__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB05_06_MSK
LCD_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB05_06_MSK
LCD_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB05_06_MSK
LCD_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB05_06_MSK
LCD_Sync_ctrl_reg__2__MASK EQU 0x04
LCD_Sync_ctrl_reg__2__POS EQU 2
LCD_Sync_ctrl_reg__3__MASK EQU 0x08
LCD_Sync_ctrl_reg__3__POS EQU 3
LCD_Sync_ctrl_reg__4__MASK EQU 0x10
LCD_Sync_ctrl_reg__4__POS EQU 4
LCD_Sync_ctrl_reg__5__MASK EQU 0x20
LCD_Sync_ctrl_reg__5__POS EQU 5
LCD_Sync_ctrl_reg__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB05_ACTL
LCD_Sync_ctrl_reg__CONTROL_REG EQU CYREG_B1_UDB05_CTL
LCD_Sync_ctrl_reg__CONTROL_ST_REG EQU CYREG_B1_UDB05_ST_CTL
LCD_Sync_ctrl_reg__COUNT_REG EQU CYREG_B1_UDB05_CTL
LCD_Sync_ctrl_reg__COUNT_ST_REG EQU CYREG_B1_UDB05_ST_CTL
LCD_Sync_ctrl_reg__MASK EQU 0x3F
LCD_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
LCD_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
LCD_Sync_ctrl_reg__PERIOD_REG EQU CYREG_B1_UDB05_MSK

/* SCL */
SCL__0__INTTYPE EQU CYREG_PICU12_INTTYPE0
SCL__0__MASK EQU 0x01
SCL__0__PC EQU CYREG_PRT12_PC0
SCL__0__PORT EQU 12
SCL__0__SHIFT EQU 0
SCL__AG EQU CYREG_PRT12_AG
SCL__BIE EQU CYREG_PRT12_BIE
SCL__BIT_MASK EQU CYREG_PRT12_BIT_MASK
SCL__BYP EQU CYREG_PRT12_BYP
SCL__DM0 EQU CYREG_PRT12_DM0
SCL__DM1 EQU CYREG_PRT12_DM1
SCL__DM2 EQU CYREG_PRT12_DM2
SCL__DR EQU CYREG_PRT12_DR
SCL__INP_DIS EQU CYREG_PRT12_INP_DIS
SCL__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
SCL__MASK EQU 0x01
SCL__PORT EQU 12
SCL__PRT EQU CYREG_PRT12_PRT
SCL__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
SCL__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
SCL__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
SCL__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
SCL__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
SCL__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
SCL__PS EQU CYREG_PRT12_PS
SCL__SHIFT EQU 0
SCL__SIO_CFG EQU CYREG_PRT12_SIO_CFG
SCL__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
SCL__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
SCL__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
SCL__SLW EQU CYREG_PRT12_SLW

/* SDA */
SDA__0__INTTYPE EQU CYREG_PICU12_INTTYPE1
SDA__0__MASK EQU 0x02
SDA__0__PC EQU CYREG_PRT12_PC1
SDA__0__PORT EQU 12
SDA__0__SHIFT EQU 1
SDA__AG EQU CYREG_PRT12_AG
SDA__BIE EQU CYREG_PRT12_BIE
SDA__BIT_MASK EQU CYREG_PRT12_BIT_MASK
SDA__BYP EQU CYREG_PRT12_BYP
SDA__DM0 EQU CYREG_PRT12_DM0
SDA__DM1 EQU CYREG_PRT12_DM1
SDA__DM2 EQU CYREG_PRT12_DM2
SDA__DR EQU CYREG_PRT12_DR
SDA__INP_DIS EQU CYREG_PRT12_INP_DIS
SDA__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
SDA__MASK EQU 0x02
SDA__PORT EQU 12
SDA__PRT EQU CYREG_PRT12_PRT
SDA__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
SDA__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
SDA__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
SDA__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
SDA__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
SDA__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
SDA__PS EQU CYREG_PRT12_PS
SDA__SHIFT EQU 1
SDA__SIO_CFG EQU CYREG_PRT12_SIO_CFG
SDA__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
SDA__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
SDA__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
SDA__SLW EQU CYREG_PRT12_SLW

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00008000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */