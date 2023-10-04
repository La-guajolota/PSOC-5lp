;
; File Name: cyfitterrv.inc
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

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; seg_0
seg_0__0__INTTYPE EQU CYREG_PICU2_INTTYPE5
seg_0__0__MASK EQU 0x20
seg_0__0__PC EQU CYREG_PRT2_PC5
seg_0__0__PORT EQU 2
seg_0__0__SHIFT EQU 5
seg_0__AG EQU CYREG_PRT2_AG
seg_0__AMUX EQU CYREG_PRT2_AMUX
seg_0__BIE EQU CYREG_PRT2_BIE
seg_0__BIT_MASK EQU CYREG_PRT2_BIT_MASK
seg_0__BYP EQU CYREG_PRT2_BYP
seg_0__CTL EQU CYREG_PRT2_CTL
seg_0__DM0 EQU CYREG_PRT2_DM0
seg_0__DM1 EQU CYREG_PRT2_DM1
seg_0__DM2 EQU CYREG_PRT2_DM2
seg_0__DR EQU CYREG_PRT2_DR
seg_0__INP_DIS EQU CYREG_PRT2_INP_DIS
seg_0__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
seg_0__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
seg_0__LCD_EN EQU CYREG_PRT2_LCD_EN
seg_0__MASK EQU 0x20
seg_0__PORT EQU 2
seg_0__PRT EQU CYREG_PRT2_PRT
seg_0__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
seg_0__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
seg_0__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
seg_0__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
seg_0__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
seg_0__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
seg_0__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
seg_0__PS EQU CYREG_PRT2_PS
seg_0__SHIFT EQU 5
seg_0__SLW EQU CYREG_PRT2_SLW

; seg_1
seg_1__0__INTTYPE EQU CYREG_PICU2_INTTYPE6
seg_1__0__MASK EQU 0x40
seg_1__0__PC EQU CYREG_PRT2_PC6
seg_1__0__PORT EQU 2
seg_1__0__SHIFT EQU 6
seg_1__AG EQU CYREG_PRT2_AG
seg_1__AMUX EQU CYREG_PRT2_AMUX
seg_1__BIE EQU CYREG_PRT2_BIE
seg_1__BIT_MASK EQU CYREG_PRT2_BIT_MASK
seg_1__BYP EQU CYREG_PRT2_BYP
seg_1__CTL EQU CYREG_PRT2_CTL
seg_1__DM0 EQU CYREG_PRT2_DM0
seg_1__DM1 EQU CYREG_PRT2_DM1
seg_1__DM2 EQU CYREG_PRT2_DM2
seg_1__DR EQU CYREG_PRT2_DR
seg_1__INP_DIS EQU CYREG_PRT2_INP_DIS
seg_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
seg_1__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
seg_1__LCD_EN EQU CYREG_PRT2_LCD_EN
seg_1__MASK EQU 0x40
seg_1__PORT EQU 2
seg_1__PRT EQU CYREG_PRT2_PRT
seg_1__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
seg_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
seg_1__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
seg_1__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
seg_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
seg_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
seg_1__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
seg_1__PS EQU CYREG_PRT2_PS
seg_1__SHIFT EQU 6
seg_1__SLW EQU CYREG_PRT2_SLW

; seg_2
seg_2__0__INTTYPE EQU CYREG_PICU2_INTTYPE7
seg_2__0__MASK EQU 0x80
seg_2__0__PC EQU CYREG_PRT2_PC7
seg_2__0__PORT EQU 2
seg_2__0__SHIFT EQU 7
seg_2__AG EQU CYREG_PRT2_AG
seg_2__AMUX EQU CYREG_PRT2_AMUX
seg_2__BIE EQU CYREG_PRT2_BIE
seg_2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
seg_2__BYP EQU CYREG_PRT2_BYP
seg_2__CTL EQU CYREG_PRT2_CTL
seg_2__DM0 EQU CYREG_PRT2_DM0
seg_2__DM1 EQU CYREG_PRT2_DM1
seg_2__DM2 EQU CYREG_PRT2_DM2
seg_2__DR EQU CYREG_PRT2_DR
seg_2__INP_DIS EQU CYREG_PRT2_INP_DIS
seg_2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
seg_2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
seg_2__LCD_EN EQU CYREG_PRT2_LCD_EN
seg_2__MASK EQU 0x80
seg_2__PORT EQU 2
seg_2__PRT EQU CYREG_PRT2_PRT
seg_2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
seg_2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
seg_2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
seg_2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
seg_2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
seg_2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
seg_2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
seg_2__PS EQU CYREG_PRT2_PS
seg_2__SHIFT EQU 7
seg_2__SLW EQU CYREG_PRT2_SLW

; seg_3
seg_3__0__INTTYPE EQU CYREG_PICU1_INTTYPE2
seg_3__0__MASK EQU 0x04
seg_3__0__PC EQU CYREG_PRT1_PC2
seg_3__0__PORT EQU 1
seg_3__0__SHIFT EQU 2
seg_3__AG EQU CYREG_PRT1_AG
seg_3__AMUX EQU CYREG_PRT1_AMUX
seg_3__BIE EQU CYREG_PRT1_BIE
seg_3__BIT_MASK EQU CYREG_PRT1_BIT_MASK
seg_3__BYP EQU CYREG_PRT1_BYP
seg_3__CTL EQU CYREG_PRT1_CTL
seg_3__DM0 EQU CYREG_PRT1_DM0
seg_3__DM1 EQU CYREG_PRT1_DM1
seg_3__DM2 EQU CYREG_PRT1_DM2
seg_3__DR EQU CYREG_PRT1_DR
seg_3__INP_DIS EQU CYREG_PRT1_INP_DIS
seg_3__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
seg_3__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
seg_3__LCD_EN EQU CYREG_PRT1_LCD_EN
seg_3__MASK EQU 0x04
seg_3__PORT EQU 1
seg_3__PRT EQU CYREG_PRT1_PRT
seg_3__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
seg_3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
seg_3__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
seg_3__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
seg_3__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
seg_3__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
seg_3__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
seg_3__PS EQU CYREG_PRT1_PS
seg_3__SHIFT EQU 2
seg_3__SLW EQU CYREG_PRT1_SLW

; seg_4
seg_4__0__INTTYPE EQU CYREG_PICU1_INTTYPE4
seg_4__0__MASK EQU 0x10
seg_4__0__PC EQU CYREG_PRT1_PC4
seg_4__0__PORT EQU 1
seg_4__0__SHIFT EQU 4
seg_4__AG EQU CYREG_PRT1_AG
seg_4__AMUX EQU CYREG_PRT1_AMUX
seg_4__BIE EQU CYREG_PRT1_BIE
seg_4__BIT_MASK EQU CYREG_PRT1_BIT_MASK
seg_4__BYP EQU CYREG_PRT1_BYP
seg_4__CTL EQU CYREG_PRT1_CTL
seg_4__DM0 EQU CYREG_PRT1_DM0
seg_4__DM1 EQU CYREG_PRT1_DM1
seg_4__DM2 EQU CYREG_PRT1_DM2
seg_4__DR EQU CYREG_PRT1_DR
seg_4__INP_DIS EQU CYREG_PRT1_INP_DIS
seg_4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
seg_4__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
seg_4__LCD_EN EQU CYREG_PRT1_LCD_EN
seg_4__MASK EQU 0x10
seg_4__PORT EQU 1
seg_4__PRT EQU CYREG_PRT1_PRT
seg_4__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
seg_4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
seg_4__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
seg_4__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
seg_4__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
seg_4__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
seg_4__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
seg_4__PS EQU CYREG_PRT1_PS
seg_4__SHIFT EQU 4
seg_4__SLW EQU CYREG_PRT1_SLW

; seg_5
seg_5__0__INTTYPE EQU CYREG_PICU1_INTTYPE5
seg_5__0__MASK EQU 0x20
seg_5__0__PC EQU CYREG_PRT1_PC5
seg_5__0__PORT EQU 1
seg_5__0__SHIFT EQU 5
seg_5__AG EQU CYREG_PRT1_AG
seg_5__AMUX EQU CYREG_PRT1_AMUX
seg_5__BIE EQU CYREG_PRT1_BIE
seg_5__BIT_MASK EQU CYREG_PRT1_BIT_MASK
seg_5__BYP EQU CYREG_PRT1_BYP
seg_5__CTL EQU CYREG_PRT1_CTL
seg_5__DM0 EQU CYREG_PRT1_DM0
seg_5__DM1 EQU CYREG_PRT1_DM1
seg_5__DM2 EQU CYREG_PRT1_DM2
seg_5__DR EQU CYREG_PRT1_DR
seg_5__INP_DIS EQU CYREG_PRT1_INP_DIS
seg_5__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
seg_5__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
seg_5__LCD_EN EQU CYREG_PRT1_LCD_EN
seg_5__MASK EQU 0x20
seg_5__PORT EQU 1
seg_5__PRT EQU CYREG_PRT1_PRT
seg_5__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
seg_5__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
seg_5__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
seg_5__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
seg_5__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
seg_5__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
seg_5__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
seg_5__PS EQU CYREG_PRT1_PS
seg_5__SHIFT EQU 5
seg_5__SLW EQU CYREG_PRT1_SLW

; seg_6
seg_6__0__INTTYPE EQU CYREG_PICU1_INTTYPE6
seg_6__0__MASK EQU 0x40
seg_6__0__PC EQU CYREG_PRT1_PC6
seg_6__0__PORT EQU 1
seg_6__0__SHIFT EQU 6
seg_6__AG EQU CYREG_PRT1_AG
seg_6__AMUX EQU CYREG_PRT1_AMUX
seg_6__BIE EQU CYREG_PRT1_BIE
seg_6__BIT_MASK EQU CYREG_PRT1_BIT_MASK
seg_6__BYP EQU CYREG_PRT1_BYP
seg_6__CTL EQU CYREG_PRT1_CTL
seg_6__DM0 EQU CYREG_PRT1_DM0
seg_6__DM1 EQU CYREG_PRT1_DM1
seg_6__DM2 EQU CYREG_PRT1_DM2
seg_6__DR EQU CYREG_PRT1_DR
seg_6__INP_DIS EQU CYREG_PRT1_INP_DIS
seg_6__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
seg_6__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
seg_6__LCD_EN EQU CYREG_PRT1_LCD_EN
seg_6__MASK EQU 0x40
seg_6__PORT EQU 1
seg_6__PRT EQU CYREG_PRT1_PRT
seg_6__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
seg_6__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
seg_6__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
seg_6__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
seg_6__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
seg_6__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
seg_6__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
seg_6__PS EQU CYREG_PRT1_PS
seg_6__SHIFT EQU 6
seg_6__SLW EQU CYREG_PRT1_SLW

; Botons
Botons__0__INTTYPE EQU CYREG_PICU15_INTTYPE0
Botons__0__MASK EQU 0x01
Botons__0__PC EQU CYREG_IO_PC_PRT15_PC0
Botons__0__PORT EQU 15
Botons__0__SHIFT EQU 0
Botons__1__INTTYPE EQU CYREG_PICU15_INTTYPE1
Botons__1__MASK EQU 0x02
Botons__1__PC EQU CYREG_IO_PC_PRT15_PC1
Botons__1__PORT EQU 15
Botons__1__SHIFT EQU 1
Botons__AG EQU CYREG_PRT15_AG
Botons__AMUX EQU CYREG_PRT15_AMUX
Botons__BIE EQU CYREG_PRT15_BIE
Botons__BIT_MASK EQU CYREG_PRT15_BIT_MASK
Botons__BYP EQU CYREG_PRT15_BYP
Botons__CTL EQU CYREG_PRT15_CTL
Botons__DM0 EQU CYREG_PRT15_DM0
Botons__DM1 EQU CYREG_PRT15_DM1
Botons__DM2 EQU CYREG_PRT15_DM2
Botons__DR EQU CYREG_PRT15_DR
Botons__INP_DIS EQU CYREG_PRT15_INP_DIS
Botons__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU15_BASE
Botons__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
Botons__LCD_EN EQU CYREG_PRT15_LCD_EN
Botons__PORT EQU 15
Botons__PRT EQU CYREG_PRT15_PRT
Botons__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
Botons__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
Botons__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
Botons__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
Botons__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
Botons__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
Botons__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
Botons__PS EQU CYREG_PRT15_PS
Botons__SLW EQU CYREG_PRT15_SLW

; Clock_1
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x00
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x01
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x01

; Display_0
Display_0__0__INTTYPE EQU CYREG_PICU2_INTTYPE4
Display_0__0__MASK EQU 0x10
Display_0__0__PC EQU CYREG_PRT2_PC4
Display_0__0__PORT EQU 2
Display_0__0__SHIFT EQU 4
Display_0__AG EQU CYREG_PRT2_AG
Display_0__AMUX EQU CYREG_PRT2_AMUX
Display_0__BIE EQU CYREG_PRT2_BIE
Display_0__BIT_MASK EQU CYREG_PRT2_BIT_MASK
Display_0__BYP EQU CYREG_PRT2_BYP
Display_0__CTL EQU CYREG_PRT2_CTL
Display_0__DM0 EQU CYREG_PRT2_DM0
Display_0__DM1 EQU CYREG_PRT2_DM1
Display_0__DM2 EQU CYREG_PRT2_DM2
Display_0__DR EQU CYREG_PRT2_DR
Display_0__INP_DIS EQU CYREG_PRT2_INP_DIS
Display_0__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
Display_0__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
Display_0__LCD_EN EQU CYREG_PRT2_LCD_EN
Display_0__MASK EQU 0x10
Display_0__PORT EQU 2
Display_0__PRT EQU CYREG_PRT2_PRT
Display_0__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
Display_0__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
Display_0__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
Display_0__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
Display_0__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
Display_0__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
Display_0__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
Display_0__PS EQU CYREG_PRT2_PS
Display_0__SHIFT EQU 4
Display_0__SLW EQU CYREG_PRT2_SLW

; Display_1
Display_1__0__INTTYPE EQU CYREG_PICU2_INTTYPE3
Display_1__0__MASK EQU 0x08
Display_1__0__PC EQU CYREG_PRT2_PC3
Display_1__0__PORT EQU 2
Display_1__0__SHIFT EQU 3
Display_1__AG EQU CYREG_PRT2_AG
Display_1__AMUX EQU CYREG_PRT2_AMUX
Display_1__BIE EQU CYREG_PRT2_BIE
Display_1__BIT_MASK EQU CYREG_PRT2_BIT_MASK
Display_1__BYP EQU CYREG_PRT2_BYP
Display_1__CTL EQU CYREG_PRT2_CTL
Display_1__DM0 EQU CYREG_PRT2_DM0
Display_1__DM1 EQU CYREG_PRT2_DM1
Display_1__DM2 EQU CYREG_PRT2_DM2
Display_1__DR EQU CYREG_PRT2_DR
Display_1__INP_DIS EQU CYREG_PRT2_INP_DIS
Display_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
Display_1__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
Display_1__LCD_EN EQU CYREG_PRT2_LCD_EN
Display_1__MASK EQU 0x08
Display_1__PORT EQU 2
Display_1__PRT EQU CYREG_PRT2_PRT
Display_1__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
Display_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
Display_1__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
Display_1__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
Display_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
Display_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
Display_1__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
Display_1__PS EQU CYREG_PRT2_PS
Display_1__SHIFT EQU 3
Display_1__SLW EQU CYREG_PRT2_SLW

; Display_2
Display_2__0__INTTYPE EQU CYREG_PICU2_INTTYPE2
Display_2__0__MASK EQU 0x04
Display_2__0__PC EQU CYREG_PRT2_PC2
Display_2__0__PORT EQU 2
Display_2__0__SHIFT EQU 2
Display_2__AG EQU CYREG_PRT2_AG
Display_2__AMUX EQU CYREG_PRT2_AMUX
Display_2__BIE EQU CYREG_PRT2_BIE
Display_2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
Display_2__BYP EQU CYREG_PRT2_BYP
Display_2__CTL EQU CYREG_PRT2_CTL
Display_2__DM0 EQU CYREG_PRT2_DM0
Display_2__DM1 EQU CYREG_PRT2_DM1
Display_2__DM2 EQU CYREG_PRT2_DM2
Display_2__DR EQU CYREG_PRT2_DR
Display_2__INP_DIS EQU CYREG_PRT2_INP_DIS
Display_2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
Display_2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
Display_2__LCD_EN EQU CYREG_PRT2_LCD_EN
Display_2__MASK EQU 0x04
Display_2__PORT EQU 2
Display_2__PRT EQU CYREG_PRT2_PRT
Display_2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
Display_2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
Display_2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
Display_2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
Display_2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
Display_2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
Display_2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
Display_2__PS EQU CYREG_PRT2_PS
Display_2__SHIFT EQU 2
Display_2__SLW EQU CYREG_PRT2_SLW

; Display_3
Display_3__0__INTTYPE EQU CYREG_PICU2_INTTYPE1
Display_3__0__MASK EQU 0x02
Display_3__0__PC EQU CYREG_PRT2_PC1
Display_3__0__PORT EQU 2
Display_3__0__SHIFT EQU 1
Display_3__AG EQU CYREG_PRT2_AG
Display_3__AMUX EQU CYREG_PRT2_AMUX
Display_3__BIE EQU CYREG_PRT2_BIE
Display_3__BIT_MASK EQU CYREG_PRT2_BIT_MASK
Display_3__BYP EQU CYREG_PRT2_BYP
Display_3__CTL EQU CYREG_PRT2_CTL
Display_3__DM0 EQU CYREG_PRT2_DM0
Display_3__DM1 EQU CYREG_PRT2_DM1
Display_3__DM2 EQU CYREG_PRT2_DM2
Display_3__DR EQU CYREG_PRT2_DR
Display_3__INP_DIS EQU CYREG_PRT2_INP_DIS
Display_3__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
Display_3__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
Display_3__LCD_EN EQU CYREG_PRT2_LCD_EN
Display_3__MASK EQU 0x02
Display_3__PORT EQU 2
Display_3__PRT EQU CYREG_PRT2_PRT
Display_3__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
Display_3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
Display_3__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
Display_3__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
Display_3__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
Display_3__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
Display_3__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
Display_3__PS EQU CYREG_PRT2_PS
Display_3__SHIFT EQU 1
Display_3__SLW EQU CYREG_PRT2_SLW

; ISR_botones
ISR_botones__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
ISR_botones__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
ISR_botones__INTC_MASK EQU 0x01
ISR_botones__INTC_NUMBER EQU 0
ISR_botones__INTC_PRIOR_NUM EQU 7
ISR_botones__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
ISR_botones__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
ISR_botones__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Displays_mux
Displays_mux_Sync_ctrl_reg__0__MASK EQU 0x01
Displays_mux_Sync_ctrl_reg__0__POS EQU 0
Displays_mux_Sync_ctrl_reg__1__MASK EQU 0x02
Displays_mux_Sync_ctrl_reg__1__POS EQU 1
Displays_mux_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
Displays_mux_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
Displays_mux_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
Displays_mux_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
Displays_mux_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
Displays_mux_Sync_ctrl_reg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB13_14_MSK
Displays_mux_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
Displays_mux_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB13_14_MSK
Displays_mux_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
Displays_mux_Sync_ctrl_reg__2__MASK EQU 0x04
Displays_mux_Sync_ctrl_reg__2__POS EQU 2
Displays_mux_Sync_ctrl_reg__3__MASK EQU 0x08
Displays_mux_Sync_ctrl_reg__3__POS EQU 3
Displays_mux_Sync_ctrl_reg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
Displays_mux_Sync_ctrl_reg__CONTROL_REG EQU CYREG_B0_UDB13_CTL
Displays_mux_Sync_ctrl_reg__CONTROL_ST_REG EQU CYREG_B0_UDB13_ST_CTL
Displays_mux_Sync_ctrl_reg__COUNT_REG EQU CYREG_B0_UDB13_CTL
Displays_mux_Sync_ctrl_reg__COUNT_ST_REG EQU CYREG_B0_UDB13_ST_CTL
Displays_mux_Sync_ctrl_reg__MASK EQU 0x0F
Displays_mux_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
Displays_mux_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
Displays_mux_Sync_ctrl_reg__PERIOD_REG EQU CYREG_B0_UDB13_MSK

; Segmentos_7seg
Segmentos_7seg_Sync_ctrl_reg__0__MASK EQU 0x01
Segmentos_7seg_Sync_ctrl_reg__0__POS EQU 0
Segmentos_7seg_Sync_ctrl_reg__1__MASK EQU 0x02
Segmentos_7seg_Sync_ctrl_reg__1__POS EQU 1
Segmentos_7seg_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
Segmentos_7seg_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
Segmentos_7seg_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
Segmentos_7seg_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
Segmentos_7seg_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
Segmentos_7seg_Sync_ctrl_reg__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB09_10_MSK
Segmentos_7seg_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
Segmentos_7seg_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB09_10_MSK
Segmentos_7seg_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
Segmentos_7seg_Sync_ctrl_reg__2__MASK EQU 0x04
Segmentos_7seg_Sync_ctrl_reg__2__POS EQU 2
Segmentos_7seg_Sync_ctrl_reg__3__MASK EQU 0x08
Segmentos_7seg_Sync_ctrl_reg__3__POS EQU 3
Segmentos_7seg_Sync_ctrl_reg__4__MASK EQU 0x10
Segmentos_7seg_Sync_ctrl_reg__4__POS EQU 4
Segmentos_7seg_Sync_ctrl_reg__5__MASK EQU 0x20
Segmentos_7seg_Sync_ctrl_reg__5__POS EQU 5
Segmentos_7seg_Sync_ctrl_reg__6__MASK EQU 0x40
Segmentos_7seg_Sync_ctrl_reg__6__POS EQU 6
Segmentos_7seg_Sync_ctrl_reg__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
Segmentos_7seg_Sync_ctrl_reg__CONTROL_REG EQU CYREG_B1_UDB09_CTL
Segmentos_7seg_Sync_ctrl_reg__CONTROL_ST_REG EQU CYREG_B1_UDB09_ST_CTL
Segmentos_7seg_Sync_ctrl_reg__COUNT_REG EQU CYREG_B1_UDB09_CTL
Segmentos_7seg_Sync_ctrl_reg__COUNT_ST_REG EQU CYREG_B1_UDB09_ST_CTL
Segmentos_7seg_Sync_ctrl_reg__MASK EQU 0x7F
Segmentos_7seg_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
Segmentos_7seg_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
Segmentos_7seg_Sync_ctrl_reg__PERIOD_REG EQU CYREG_B1_UDB09_MSK

; Status_Botones
Status_Botones_sts_intr_sts_reg__0__MASK EQU 0x01
Status_Botones_sts_intr_sts_reg__0__POS EQU 0
Status_Botones_sts_intr_sts_reg__1__MASK EQU 0x02
Status_Botones_sts_intr_sts_reg__1__POS EQU 1
Status_Botones_sts_intr_sts_reg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
Status_Botones_sts_intr_sts_reg__16BIT_STATUS_REG EQU CYREG_B1_UDB09_10_ST
Status_Botones_sts_intr_sts_reg__MASK EQU 0x03
Status_Botones_sts_intr_sts_reg__MASK_REG EQU CYREG_B1_UDB09_MSK
Status_Botones_sts_intr_sts_reg__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
Status_Botones_sts_intr_sts_reg__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
Status_Botones_sts_intr_sts_reg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
Status_Botones_sts_intr_sts_reg__STATUS_CNT_REG EQU CYREG_B1_UDB09_ST_CTL
Status_Botones_sts_intr_sts_reg__STATUS_CONTROL_REG EQU CYREG_B1_UDB09_ST_CTL
Status_Botones_sts_intr_sts_reg__STATUS_REG EQU CYREG_B1_UDB09_ST

; Miscellaneous
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
CYDEV_INTR_RISING EQU 0x00000001
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
    ENDIF
    END