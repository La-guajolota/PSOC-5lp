/*******************************************************************************
* File Name: Sampling.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_Sampling_H)
#define CY_TIMER_Sampling_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Sampling_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Sampling_Resolution                 16u
#define Sampling_UsingFixedFunction         1u
#define Sampling_UsingHWCaptureCounter      0u
#define Sampling_SoftwareCaptureMode        0u
#define Sampling_SoftwareTriggerMode        0u
#define Sampling_UsingHWEnable              0u
#define Sampling_EnableTriggerMode          0u
#define Sampling_InterruptOnCaptureCount    0u
#define Sampling_RunModeUsed                0u
#define Sampling_ControlRegRemoved          0u

#if defined(Sampling_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define Sampling_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (Sampling_UsingFixedFunction)
    #define Sampling_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define Sampling_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End Sampling_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!Sampling_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (Sampling_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!Sampling_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}Sampling_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Sampling_Start(void) ;
void    Sampling_Stop(void) ;

void    Sampling_SetInterruptMode(uint8 interruptMode) ;
uint8   Sampling_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Sampling_GetInterruptSource() Sampling_ReadStatusRegister()

#if(!Sampling_UDB_CONTROL_REG_REMOVED)
    uint8   Sampling_ReadControlRegister(void) ;
    void    Sampling_WriteControlRegister(uint8 control) ;
#endif /* (!Sampling_UDB_CONTROL_REG_REMOVED) */

uint16  Sampling_ReadPeriod(void) ;
void    Sampling_WritePeriod(uint16 period) ;
uint16  Sampling_ReadCounter(void) ;
void    Sampling_WriteCounter(uint16 counter) ;
uint16  Sampling_ReadCapture(void) ;
void    Sampling_SoftwareCapture(void) ;

#if(!Sampling_UsingFixedFunction) /* UDB Prototypes */
    #if (Sampling_SoftwareCaptureMode)
        void    Sampling_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Sampling_UsingFixedFunction) */

    #if (Sampling_SoftwareTriggerMode)
        void    Sampling_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Sampling_SoftwareTriggerMode) */

    #if (Sampling_EnableTriggerMode)
        void    Sampling_EnableTrigger(void) ;
        void    Sampling_DisableTrigger(void) ;
    #endif /* (Sampling_EnableTriggerMode) */


    #if(Sampling_InterruptOnCaptureCount)
        void    Sampling_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (Sampling_InterruptOnCaptureCount) */

    #if (Sampling_UsingHWCaptureCounter)
        void    Sampling_SetCaptureCount(uint8 captureCount) ;
        uint8   Sampling_ReadCaptureCount(void) ;
    #endif /* (Sampling_UsingHWCaptureCounter) */

    void Sampling_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Sampling_Init(void)          ;
void Sampling_Enable(void)        ;
void Sampling_SaveConfig(void)    ;
void Sampling_RestoreConfig(void) ;
void Sampling_Sleep(void)         ;
void Sampling_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Sampling__B_TIMER__CM_NONE 0
#define Sampling__B_TIMER__CM_RISINGEDGE 1
#define Sampling__B_TIMER__CM_FALLINGEDGE 2
#define Sampling__B_TIMER__CM_EITHEREDGE 3
#define Sampling__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Sampling__B_TIMER__TM_NONE 0x00u
#define Sampling__B_TIMER__TM_RISINGEDGE 0x04u
#define Sampling__B_TIMER__TM_FALLINGEDGE 0x08u
#define Sampling__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Sampling__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Sampling_INIT_PERIOD             1u
#define Sampling_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << Sampling_CTRL_CAP_MODE_SHIFT))
#define Sampling_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << Sampling_CTRL_TRIG_MODE_SHIFT))
#if (Sampling_UsingFixedFunction)
    #define Sampling_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << Sampling_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << Sampling_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define Sampling_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << Sampling_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Sampling_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Sampling_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (Sampling_UsingFixedFunction) */
#define Sampling_INIT_CAPTURE_COUNT      (2u)
#define Sampling_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << Sampling_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (Sampling_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Sampling_STATUS         (*(reg8 *) Sampling_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Sampling_STATUS_MASK    (*(reg8 *) Sampling_TimerHW__SR0 )
    #define Sampling_CONTROL        (*(reg8 *) Sampling_TimerHW__CFG0)
    #define Sampling_CONTROL2       (*(reg8 *) Sampling_TimerHW__CFG1)
    #define Sampling_CONTROL2_PTR   ( (reg8 *) Sampling_TimerHW__CFG1)
    #define Sampling_RT1            (*(reg8 *) Sampling_TimerHW__RT1)
    #define Sampling_RT1_PTR        ( (reg8 *) Sampling_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Sampling_CONTROL3       (*(reg8 *) Sampling_TimerHW__CFG2)
        #define Sampling_CONTROL3_PTR   ( (reg8 *) Sampling_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Sampling_GLOBAL_ENABLE  (*(reg8 *) Sampling_TimerHW__PM_ACT_CFG)
    #define Sampling_GLOBAL_STBY_ENABLE  (*(reg8 *) Sampling_TimerHW__PM_STBY_CFG)

    #define Sampling_CAPTURE_LSB         (* (reg16 *) Sampling_TimerHW__CAP0 )
    #define Sampling_CAPTURE_LSB_PTR       ((reg16 *) Sampling_TimerHW__CAP0 )
    #define Sampling_PERIOD_LSB          (* (reg16 *) Sampling_TimerHW__PER0 )
    #define Sampling_PERIOD_LSB_PTR        ((reg16 *) Sampling_TimerHW__PER0 )
    #define Sampling_COUNTER_LSB         (* (reg16 *) Sampling_TimerHW__CNT_CMP0 )
    #define Sampling_COUNTER_LSB_PTR       ((reg16 *) Sampling_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Sampling_BLOCK_EN_MASK                     Sampling_TimerHW__PM_ACT_MSK
    #define Sampling_BLOCK_STBY_EN_MASK                Sampling_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Sampling_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Sampling_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Sampling_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Sampling_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Sampling_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Sampling_CTRL_ENABLE                        ((uint8)((uint8)0x01u << Sampling_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Sampling_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Sampling_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << Sampling_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Sampling_CTRL_MODE_SHIFT                 0x01u
        #define Sampling_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << Sampling_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Sampling_CTRL_RCOD_SHIFT        0x02u
        #define Sampling_CTRL_ENBL_SHIFT        0x00u
        #define Sampling_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Sampling_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << Sampling_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define Sampling_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << Sampling_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define Sampling_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << Sampling_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define Sampling_CTRL_RCOD       ((uint8)((uint8)0x03u << Sampling_CTRL_RCOD_SHIFT))
        #define Sampling_CTRL_ENBL       ((uint8)((uint8)0x80u << Sampling_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Sampling_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Sampling_RT1_MASK                        ((uint8)((uint8)0x03u << Sampling_RT1_SHIFT))
    #define Sampling_SYNC                            ((uint8)((uint8)0x03u << Sampling_RT1_SHIFT))
    #define Sampling_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Sampling_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << Sampling_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define Sampling_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << Sampling_SYNCDSI_SHIFT))

    #define Sampling_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << Sampling_CTRL_MODE_SHIFT))
    #define Sampling_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << Sampling_CTRL_MODE_SHIFT))
    #define Sampling_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << Sampling_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Sampling_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Sampling_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Sampling_STATUS_TC_INT_MASK_SHIFT        (Sampling_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Sampling_STATUS_CAPTURE_INT_MASK_SHIFT   (Sampling_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define Sampling_STATUS_TC                       ((uint8)((uint8)0x01u << Sampling_STATUS_TC_SHIFT))
    #define Sampling_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << Sampling_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Sampling_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << Sampling_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Sampling_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << Sampling_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Sampling_STATUS              (* (reg8 *) Sampling_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Sampling_STATUS_MASK         (* (reg8 *) Sampling_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Sampling_STATUS_AUX_CTRL     (* (reg8 *) Sampling_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Sampling_CONTROL             (* (reg8 *) Sampling_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(Sampling_Resolution <= 8u) /* 8-bit Timer */
        #define Sampling_CAPTURE_LSB         (* (reg8 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Sampling_CAPTURE_LSB_PTR       ((reg8 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Sampling_PERIOD_LSB          (* (reg8 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Sampling_PERIOD_LSB_PTR        ((reg8 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Sampling_COUNTER_LSB         (* (reg8 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define Sampling_COUNTER_LSB_PTR       ((reg8 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(Sampling_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define Sampling_CAPTURE_LSB         (* (reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Sampling_CAPTURE_LSB_PTR       ((reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Sampling_PERIOD_LSB          (* (reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Sampling_PERIOD_LSB_PTR        ((reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Sampling_COUNTER_LSB         (* (reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define Sampling_COUNTER_LSB_PTR       ((reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Sampling_CAPTURE_LSB         (* (reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define Sampling_CAPTURE_LSB_PTR       ((reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define Sampling_PERIOD_LSB          (* (reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define Sampling_PERIOD_LSB_PTR        ((reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define Sampling_COUNTER_LSB         (* (reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define Sampling_COUNTER_LSB_PTR       ((reg16 *) Sampling_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(Sampling_Resolution <= 24u)/* 24-bit Timer */
        #define Sampling_CAPTURE_LSB         (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Sampling_CAPTURE_LSB_PTR       ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define Sampling_PERIOD_LSB          (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Sampling_PERIOD_LSB_PTR        ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define Sampling_COUNTER_LSB         (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define Sampling_COUNTER_LSB_PTR       ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Sampling_CAPTURE_LSB         (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Sampling_CAPTURE_LSB_PTR       ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define Sampling_PERIOD_LSB          (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Sampling_PERIOD_LSB_PTR        ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define Sampling_COUNTER_LSB         (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define Sampling_COUNTER_LSB_PTR       ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Sampling_CAPTURE_LSB         (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define Sampling_CAPTURE_LSB_PTR       ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define Sampling_PERIOD_LSB          (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define Sampling_PERIOD_LSB_PTR        ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define Sampling_COUNTER_LSB         (* (reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define Sampling_COUNTER_LSB_PTR       ((reg32 *) Sampling_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define Sampling_COUNTER_LSB_PTR_8BIT       ((reg8 *) Sampling_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (Sampling_UsingHWCaptureCounter)
        #define Sampling_CAP_COUNT              (*(reg8 *) Sampling_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Sampling_CAP_COUNT_PTR          ( (reg8 *) Sampling_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Sampling_CAPTURE_COUNT_CTRL     (*(reg8 *) Sampling_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Sampling_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Sampling_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Sampling_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Sampling_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Sampling_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Sampling_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Sampling_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Sampling_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Sampling_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << Sampling_CTRL_INTCNT_SHIFT))
    #define Sampling_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << Sampling_CTRL_TRIG_MODE_SHIFT))
    #define Sampling_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << Sampling_CTRL_TRIG_EN_SHIFT))
    #define Sampling_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << Sampling_CTRL_CAP_MODE_SHIFT))
    #define Sampling_CTRL_ENABLE                    ((uint8)((uint8)0x01u << Sampling_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Sampling_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Sampling_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Sampling_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Sampling_STATUS_TC_INT_MASK_SHIFT       Sampling_STATUS_TC_SHIFT
    #define Sampling_STATUS_CAPTURE_INT_MASK_SHIFT  Sampling_STATUS_CAPTURE_SHIFT
    #define Sampling_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Sampling_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Sampling_STATUS_FIFOFULL_INT_MASK_SHIFT Sampling_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Sampling_STATUS_TC                      ((uint8)((uint8)0x01u << Sampling_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define Sampling_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << Sampling_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Sampling_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << Sampling_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Sampling_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << Sampling_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Sampling_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << Sampling_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Sampling_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << Sampling_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Sampling_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << Sampling_STATUS_FIFOFULL_SHIFT))

    #define Sampling_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Sampling_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Sampling_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Sampling_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Sampling_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Sampling_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_Sampling_H */


/* [] END OF FILE */
