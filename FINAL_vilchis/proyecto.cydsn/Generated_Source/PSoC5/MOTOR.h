/*******************************************************************************
* File Name: MOTOR.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_MOTOR_H)
#define CY_PWM_MOTOR_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 MOTOR_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define MOTOR_Resolution                     (16u)
#define MOTOR_UsingFixedFunction             (0u)
#define MOTOR_DeadBandMode                   (0u)
#define MOTOR_KillModeMinTime                (0u)
#define MOTOR_KillMode                       (0u)
#define MOTOR_PWMMode                        (0u)
#define MOTOR_PWMModeIsCenterAligned         (0u)
#define MOTOR_DeadBandUsed                   (0u)
#define MOTOR_DeadBand2_4                    (0u)

#if !defined(MOTOR_PWMUDB_genblk8_stsreg__REMOVED)
    #define MOTOR_UseStatus                  (1u)
#else
    #define MOTOR_UseStatus                  (0u)
#endif /* !defined(MOTOR_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(MOTOR_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define MOTOR_UseControl                 (1u)
#else
    #define MOTOR_UseControl                 (0u)
#endif /* !defined(MOTOR_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define MOTOR_UseOneCompareMode              (1u)
#define MOTOR_MinimumKillTime                (1u)
#define MOTOR_EnableMode                     (0u)

#define MOTOR_CompareMode1SW                 (0u)
#define MOTOR_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define MOTOR__B_PWM__DISABLED 0
#define MOTOR__B_PWM__ASYNCHRONOUS 1
#define MOTOR__B_PWM__SINGLECYCLE 2
#define MOTOR__B_PWM__LATCHED 3
#define MOTOR__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define MOTOR__B_PWM__DBMDISABLED 0
#define MOTOR__B_PWM__DBM_2_4_CLOCKS 1
#define MOTOR__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define MOTOR__B_PWM__ONE_OUTPUT 0
#define MOTOR__B_PWM__TWO_OUTPUTS 1
#define MOTOR__B_PWM__DUAL_EDGE 2
#define MOTOR__B_PWM__CENTER_ALIGN 3
#define MOTOR__B_PWM__DITHER 5
#define MOTOR__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define MOTOR__B_PWM__LESS_THAN 1
#define MOTOR__B_PWM__LESS_THAN_OR_EQUAL 2
#define MOTOR__B_PWM__GREATER_THAN 3
#define MOTOR__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define MOTOR__B_PWM__EQUAL 0
#define MOTOR__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!MOTOR_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!MOTOR_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!MOTOR_PWMModeIsCenterAligned) */
        #if (MOTOR_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (MOTOR_UseStatus) */

        /* Backup for Deadband parameters */
        #if(MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_256_CLOCKS || \
            MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(MOTOR_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (MOTOR_KillModeMinTime) */

        /* Backup control register */
        #if(MOTOR_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (MOTOR_UseControl) */

    #endif /* (!MOTOR_UsingFixedFunction) */

}MOTOR_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    MOTOR_Start(void) ;
void    MOTOR_Stop(void) ;

#if (MOTOR_UseStatus || MOTOR_UsingFixedFunction)
    void  MOTOR_SetInterruptMode(uint8 interruptMode) ;
    uint8 MOTOR_ReadStatusRegister(void) ;
#endif /* (MOTOR_UseStatus || MOTOR_UsingFixedFunction) */

#define MOTOR_GetInterruptSource() MOTOR_ReadStatusRegister()

#if (MOTOR_UseControl)
    uint8 MOTOR_ReadControlRegister(void) ;
    void  MOTOR_WriteControlRegister(uint8 control)
          ;
#endif /* (MOTOR_UseControl) */

#if (MOTOR_UseOneCompareMode)
   #if (MOTOR_CompareMode1SW)
       void    MOTOR_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (MOTOR_CompareMode1SW) */
#else
    #if (MOTOR_CompareMode1SW)
        void    MOTOR_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (MOTOR_CompareMode1SW) */
    #if (MOTOR_CompareMode2SW)
        void    MOTOR_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (MOTOR_CompareMode2SW) */
#endif /* (MOTOR_UseOneCompareMode) */

#if (!MOTOR_UsingFixedFunction)
    uint16   MOTOR_ReadCounter(void) ;
    uint16 MOTOR_ReadCapture(void) ;

    #if (MOTOR_UseStatus)
            void MOTOR_ClearFIFO(void) ;
    #endif /* (MOTOR_UseStatus) */

    void    MOTOR_WriteCounter(uint16 counter)
            ;
#endif /* (!MOTOR_UsingFixedFunction) */

void    MOTOR_WritePeriod(uint16 period)
        ;
uint16 MOTOR_ReadPeriod(void) ;

#if (MOTOR_UseOneCompareMode)
    void    MOTOR_WriteCompare(uint16 compare)
            ;
    uint16 MOTOR_ReadCompare(void) ;
#else
    void    MOTOR_WriteCompare1(uint16 compare)
            ;
    uint16 MOTOR_ReadCompare1(void) ;
    void    MOTOR_WriteCompare2(uint16 compare)
            ;
    uint16 MOTOR_ReadCompare2(void) ;
#endif /* (MOTOR_UseOneCompareMode) */


#if (MOTOR_DeadBandUsed)
    void    MOTOR_WriteDeadTime(uint8 deadtime) ;
    uint8   MOTOR_ReadDeadTime(void) ;
#endif /* (MOTOR_DeadBandUsed) */

#if ( MOTOR_KillModeMinTime)
    void MOTOR_WriteKillTime(uint8 killtime) ;
    uint8 MOTOR_ReadKillTime(void) ;
#endif /* ( MOTOR_KillModeMinTime) */

void MOTOR_Init(void) ;
void MOTOR_Enable(void) ;
void MOTOR_Sleep(void) ;
void MOTOR_Wakeup(void) ;
void MOTOR_SaveConfig(void) ;
void MOTOR_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define MOTOR_INIT_PERIOD_VALUE          (65535u)
#define MOTOR_INIT_COMPARE_VALUE1        (7200u)
#define MOTOR_INIT_COMPARE_VALUE2        (63u)
#define MOTOR_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    MOTOR_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    MOTOR_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    MOTOR_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    MOTOR_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define MOTOR_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  MOTOR_CTRL_CMPMODE2_SHIFT)
#define MOTOR_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  MOTOR_CTRL_CMPMODE1_SHIFT)
#define MOTOR_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (MOTOR_UsingFixedFunction)
   #define MOTOR_PERIOD_LSB              (*(reg16 *) MOTOR_PWMHW__PER0)
   #define MOTOR_PERIOD_LSB_PTR          ( (reg16 *) MOTOR_PWMHW__PER0)
   #define MOTOR_COMPARE1_LSB            (*(reg16 *) MOTOR_PWMHW__CNT_CMP0)
   #define MOTOR_COMPARE1_LSB_PTR        ( (reg16 *) MOTOR_PWMHW__CNT_CMP0)
   #define MOTOR_COMPARE2_LSB            (0x00u)
   #define MOTOR_COMPARE2_LSB_PTR        (0x00u)
   #define MOTOR_COUNTER_LSB             (*(reg16 *) MOTOR_PWMHW__CNT_CMP0)
   #define MOTOR_COUNTER_LSB_PTR         ( (reg16 *) MOTOR_PWMHW__CNT_CMP0)
   #define MOTOR_CAPTURE_LSB             (*(reg16 *) MOTOR_PWMHW__CAP0)
   #define MOTOR_CAPTURE_LSB_PTR         ( (reg16 *) MOTOR_PWMHW__CAP0)
   #define MOTOR_RT1                     (*(reg8 *)  MOTOR_PWMHW__RT1)
   #define MOTOR_RT1_PTR                 ( (reg8 *)  MOTOR_PWMHW__RT1)

#else
   #if (MOTOR_Resolution == 8u) /* 8bit - PWM */

       #if(MOTOR_PWMModeIsCenterAligned)
           #define MOTOR_PERIOD_LSB      (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define MOTOR_PERIOD_LSB_PTR  ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define MOTOR_PERIOD_LSB      (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define MOTOR_PERIOD_LSB_PTR  ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (MOTOR_PWMModeIsCenterAligned) */

       #define MOTOR_COMPARE1_LSB        (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define MOTOR_COMPARE1_LSB_PTR    ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define MOTOR_COMPARE2_LSB        (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define MOTOR_COMPARE2_LSB_PTR    ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define MOTOR_COUNTERCAP_LSB      (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define MOTOR_COUNTERCAP_LSB_PTR  ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define MOTOR_COUNTER_LSB         (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define MOTOR_COUNTER_LSB_PTR     ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define MOTOR_CAPTURE_LSB         (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define MOTOR_CAPTURE_LSB_PTR     ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(MOTOR_PWMModeIsCenterAligned)
               #define MOTOR_PERIOD_LSB      (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define MOTOR_PERIOD_LSB_PTR  ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define MOTOR_PERIOD_LSB      (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define MOTOR_PERIOD_LSB_PTR  ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (MOTOR_PWMModeIsCenterAligned) */

            #define MOTOR_COMPARE1_LSB       (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define MOTOR_COMPARE1_LSB_PTR   ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define MOTOR_COMPARE2_LSB       (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define MOTOR_COMPARE2_LSB_PTR   ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define MOTOR_COUNTERCAP_LSB     (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define MOTOR_COUNTERCAP_LSB_PTR ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define MOTOR_COUNTER_LSB        (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define MOTOR_COUNTER_LSB_PTR    ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define MOTOR_CAPTURE_LSB        (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define MOTOR_CAPTURE_LSB_PTR    ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(MOTOR_PWMModeIsCenterAligned)
               #define MOTOR_PERIOD_LSB      (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define MOTOR_PERIOD_LSB_PTR  ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define MOTOR_PERIOD_LSB      (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define MOTOR_PERIOD_LSB_PTR  ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (MOTOR_PWMModeIsCenterAligned) */

            #define MOTOR_COMPARE1_LSB       (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define MOTOR_COMPARE1_LSB_PTR   ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define MOTOR_COMPARE2_LSB       (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define MOTOR_COMPARE2_LSB_PTR   ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define MOTOR_COUNTERCAP_LSB     (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define MOTOR_COUNTERCAP_LSB_PTR ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define MOTOR_COUNTER_LSB        (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define MOTOR_COUNTER_LSB_PTR    ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define MOTOR_CAPTURE_LSB        (*(reg16 *) MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define MOTOR_CAPTURE_LSB_PTR    ((reg16 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define MOTOR_AUX_CONTROLDP1          (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define MOTOR_AUX_CONTROLDP1_PTR      ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (MOTOR_Resolution == 8) */

   #define MOTOR_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define MOTOR_AUX_CONTROLDP0          (*(reg8 *)  MOTOR_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define MOTOR_AUX_CONTROLDP0_PTR      ((reg8 *)   MOTOR_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (MOTOR_UsingFixedFunction) */

#if(MOTOR_KillModeMinTime )
    #define MOTOR_KILLMODEMINTIME        (*(reg8 *)  MOTOR_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define MOTOR_KILLMODEMINTIME_PTR    ((reg8 *)   MOTOR_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (MOTOR_KillModeMinTime ) */

#if(MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_256_CLOCKS)
    #define MOTOR_DEADBAND_COUNT         (*(reg8 *)  MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define MOTOR_DEADBAND_COUNT_PTR     ((reg8 *)   MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define MOTOR_DEADBAND_LSB_PTR       ((reg8 *)   MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define MOTOR_DEADBAND_LSB           (*(reg8 *)  MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (MOTOR_UsingFixedFunction)
        #define MOTOR_DEADBAND_COUNT         (*(reg8 *)  MOTOR_PWMHW__CFG0)
        #define MOTOR_DEADBAND_COUNT_PTR     ((reg8 *)   MOTOR_PWMHW__CFG0)
        #define MOTOR_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << MOTOR_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define MOTOR_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define MOTOR_DEADBAND_COUNT         (*(reg8 *)  MOTOR_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define MOTOR_DEADBAND_COUNT_PTR     ((reg8 *)   MOTOR_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define MOTOR_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << MOTOR_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define MOTOR_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (MOTOR_UsingFixedFunction) */
#endif /* (MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_256_CLOCKS) */



#if (MOTOR_UsingFixedFunction)
    #define MOTOR_STATUS                 (*(reg8 *) MOTOR_PWMHW__SR0)
    #define MOTOR_STATUS_PTR             ((reg8 *) MOTOR_PWMHW__SR0)
    #define MOTOR_STATUS_MASK            (*(reg8 *) MOTOR_PWMHW__SR0)
    #define MOTOR_STATUS_MASK_PTR        ((reg8 *) MOTOR_PWMHW__SR0)
    #define MOTOR_CONTROL                (*(reg8 *) MOTOR_PWMHW__CFG0)
    #define MOTOR_CONTROL_PTR            ((reg8 *) MOTOR_PWMHW__CFG0)
    #define MOTOR_CONTROL2               (*(reg8 *) MOTOR_PWMHW__CFG1)
    #define MOTOR_CONTROL3               (*(reg8 *) MOTOR_PWMHW__CFG2)
    #define MOTOR_GLOBAL_ENABLE          (*(reg8 *) MOTOR_PWMHW__PM_ACT_CFG)
    #define MOTOR_GLOBAL_ENABLE_PTR      ( (reg8 *) MOTOR_PWMHW__PM_ACT_CFG)
    #define MOTOR_GLOBAL_STBY_ENABLE     (*(reg8 *) MOTOR_PWMHW__PM_STBY_CFG)
    #define MOTOR_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) MOTOR_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define MOTOR_BLOCK_EN_MASK          (MOTOR_PWMHW__PM_ACT_MSK)
    #define MOTOR_BLOCK_STBY_EN_MASK     (MOTOR_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define MOTOR_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define MOTOR_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define MOTOR_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define MOTOR_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define MOTOR_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define MOTOR_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define MOTOR_CTRL_ENABLE            (uint8)((uint8)0x01u << MOTOR_CTRL_ENABLE_SHIFT)
    #define MOTOR_CTRL_RESET             (uint8)((uint8)0x01u << MOTOR_CTRL_RESET_SHIFT)
    #define MOTOR_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << MOTOR_CTRL_CMPMODE2_SHIFT)
    #define MOTOR_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << MOTOR_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define MOTOR_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define MOTOR_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << MOTOR_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define MOTOR_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define MOTOR_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define MOTOR_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define MOTOR_STATUS_TC_INT_EN_MASK_SHIFT            (MOTOR_STATUS_TC_SHIFT - 4u)
    #define MOTOR_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define MOTOR_STATUS_CMP1_INT_EN_MASK_SHIFT          (MOTOR_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define MOTOR_STATUS_TC              (uint8)((uint8)0x01u << MOTOR_STATUS_TC_SHIFT)
    #define MOTOR_STATUS_CMP1            (uint8)((uint8)0x01u << MOTOR_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define MOTOR_STATUS_TC_INT_EN_MASK              (uint8)((uint8)MOTOR_STATUS_TC >> 4u)
    #define MOTOR_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)MOTOR_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define MOTOR_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define MOTOR_RT1_MASK              (uint8)((uint8)0x03u << MOTOR_RT1_SHIFT)
    #define MOTOR_SYNC                  (uint8)((uint8)0x03u << MOTOR_RT1_SHIFT)
    #define MOTOR_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define MOTOR_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << MOTOR_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define MOTOR_SYNCDSI_EN            (uint8)((uint8)0x0Fu << MOTOR_SYNCDSI_SHIFT)


#else
    #define MOTOR_STATUS                (*(reg8 *)   MOTOR_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define MOTOR_STATUS_PTR            ((reg8 *)    MOTOR_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define MOTOR_STATUS_MASK           (*(reg8 *)   MOTOR_PWMUDB_genblk8_stsreg__MASK_REG)
    #define MOTOR_STATUS_MASK_PTR       ((reg8 *)    MOTOR_PWMUDB_genblk8_stsreg__MASK_REG)
    #define MOTOR_STATUS_AUX_CTRL       (*(reg8 *)   MOTOR_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define MOTOR_CONTROL               (*(reg8 *)   MOTOR_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define MOTOR_CONTROL_PTR           ((reg8 *)    MOTOR_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define MOTOR_CTRL_ENABLE_SHIFT      (0x07u)
    #define MOTOR_CTRL_RESET_SHIFT       (0x06u)
    #define MOTOR_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define MOTOR_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define MOTOR_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define MOTOR_CTRL_ENABLE            (uint8)((uint8)0x01u << MOTOR_CTRL_ENABLE_SHIFT)
    #define MOTOR_CTRL_RESET             (uint8)((uint8)0x01u << MOTOR_CTRL_RESET_SHIFT)
    #define MOTOR_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << MOTOR_CTRL_CMPMODE2_SHIFT)
    #define MOTOR_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << MOTOR_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define MOTOR_STATUS_KILL_SHIFT          (0x05u)
    #define MOTOR_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define MOTOR_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define MOTOR_STATUS_TC_SHIFT            (0x02u)
    #define MOTOR_STATUS_CMP2_SHIFT          (0x01u)
    #define MOTOR_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define MOTOR_STATUS_KILL_INT_EN_MASK_SHIFT          (MOTOR_STATUS_KILL_SHIFT)
    #define MOTOR_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (MOTOR_STATUS_FIFONEMPTY_SHIFT)
    #define MOTOR_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (MOTOR_STATUS_FIFOFULL_SHIFT)
    #define MOTOR_STATUS_TC_INT_EN_MASK_SHIFT            (MOTOR_STATUS_TC_SHIFT)
    #define MOTOR_STATUS_CMP2_INT_EN_MASK_SHIFT          (MOTOR_STATUS_CMP2_SHIFT)
    #define MOTOR_STATUS_CMP1_INT_EN_MASK_SHIFT          (MOTOR_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define MOTOR_STATUS_KILL            (uint8)((uint8)0x00u << MOTOR_STATUS_KILL_SHIFT )
    #define MOTOR_STATUS_FIFOFULL        (uint8)((uint8)0x01u << MOTOR_STATUS_FIFOFULL_SHIFT)
    #define MOTOR_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << MOTOR_STATUS_FIFONEMPTY_SHIFT)
    #define MOTOR_STATUS_TC              (uint8)((uint8)0x01u << MOTOR_STATUS_TC_SHIFT)
    #define MOTOR_STATUS_CMP2            (uint8)((uint8)0x01u << MOTOR_STATUS_CMP2_SHIFT)
    #define MOTOR_STATUS_CMP1            (uint8)((uint8)0x01u << MOTOR_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define MOTOR_STATUS_KILL_INT_EN_MASK            (MOTOR_STATUS_KILL)
    #define MOTOR_STATUS_FIFOFULL_INT_EN_MASK        (MOTOR_STATUS_FIFOFULL)
    #define MOTOR_STATUS_FIFONEMPTY_INT_EN_MASK      (MOTOR_STATUS_FIFONEMPTY)
    #define MOTOR_STATUS_TC_INT_EN_MASK              (MOTOR_STATUS_TC)
    #define MOTOR_STATUS_CMP2_INT_EN_MASK            (MOTOR_STATUS_CMP2)
    #define MOTOR_STATUS_CMP1_INT_EN_MASK            (MOTOR_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define MOTOR_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define MOTOR_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define MOTOR_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define MOTOR_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define MOTOR_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* MOTOR_UsingFixedFunction */

#endif  /* CY_PWM_MOTOR_H */


/* [] END OF FILE */
