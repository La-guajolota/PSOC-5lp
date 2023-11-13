/*******************************************************************************
* File Name: SAMPLING.c
* Version 2.80
*
* Description:
*  The Timer component consists of a 8, 16, 24 or 32-bit timer with
*  a selectable period between 2 and 2^Width - 1.  The timer may free run
*  or be used as a capture timer as well.  The capture can be initiated
*  by a positive or negative edge signal as well as via software.
*  A trigger input can be programmed to enable the timer on rising edge
*  falling edge, either edge or continous run.
*  Interrupts may be generated due to a terminal count condition
*  or a capture event.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "SAMPLING.h"

uint8 SAMPLING_initVar = 0u;


/*******************************************************************************
* Function Name: SAMPLING_Init
********************************************************************************
*
* Summary:
*  Initialize to the schematic state
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_Init(void) 
{
    #if(!SAMPLING_UsingFixedFunction)
            /* Interrupt State Backup for Critical Region*/
            uint8 SAMPLING_interruptState;
    #endif /* Interrupt state back up for Fixed Function only */

    #if (SAMPLING_UsingFixedFunction)
        /* Clear all bits but the enable bit (if it's already set) for Timer operation */
        SAMPLING_CONTROL &= SAMPLING_CTRL_ENABLE;

        /* Clear the mode bits for continuous run mode */
        #if (CY_PSOC5A)
            SAMPLING_CONTROL2 &= ((uint8)(~SAMPLING_CTRL_MODE_MASK));
        #endif /* Clear bits in CONTROL2 only in PSOC5A */

        #if (CY_PSOC3 || CY_PSOC5LP)
            SAMPLING_CONTROL3 &= ((uint8)(~SAMPLING_CTRL_MODE_MASK));
        #endif /* CONTROL3 register exists only in PSoC3 OR PSoC5LP */

        /* Check if One Shot mode is enabled i.e. RunMode !=0*/
        #if (SAMPLING_RunModeUsed != 0x0u)
            /* Set 3rd bit of Control register to enable one shot mode */
            SAMPLING_CONTROL |= 0x04u;
        #endif /* One Shot enabled only when RunModeUsed is not Continuous*/

        #if (SAMPLING_RunModeUsed == 2)
            #if (CY_PSOC5A)
                /* Set last 2 bits of control2 register if one shot(halt on
                interrupt) is enabled*/
                SAMPLING_CONTROL2 |= 0x03u;
            #endif /* Set One-Shot Halt on Interrupt bit in CONTROL2 for PSoC5A */

            #if (CY_PSOC3 || CY_PSOC5LP)
                /* Set last 2 bits of control3 register if one shot(halt on
                interrupt) is enabled*/
                SAMPLING_CONTROL3 |= 0x03u;
            #endif /* Set One-Shot Halt on Interrupt bit in CONTROL3 for PSoC3 or PSoC5LP */

        #endif /* Remove section if One Shot Halt on Interrupt is not enabled */

        #if (SAMPLING_UsingHWEnable != 0)
            #if (CY_PSOC5A)
                /* Set the default Run Mode of the Timer to Continuous */
                SAMPLING_CONTROL2 |= SAMPLING_CTRL_MODE_PULSEWIDTH;
            #endif /* Set Continuous Run Mode in CONTROL2 for PSoC5A */

            #if (CY_PSOC3 || CY_PSOC5LP)
                /* Clear and Set ROD and COD bits of CFG2 register */
                SAMPLING_CONTROL3 &= ((uint8)(~SAMPLING_CTRL_RCOD_MASK));
                SAMPLING_CONTROL3 |= SAMPLING_CTRL_RCOD;

                /* Clear and Enable the HW enable bit in CFG2 register */
                SAMPLING_CONTROL3 &= ((uint8)(~SAMPLING_CTRL_ENBL_MASK));
                SAMPLING_CONTROL3 |= SAMPLING_CTRL_ENBL;

                /* Set the default Run Mode of the Timer to Continuous */
                SAMPLING_CONTROL3 |= SAMPLING_CTRL_MODE_CONTINUOUS;
            #endif /* Set Continuous Run Mode in CONTROL3 for PSoC3ES3 or PSoC5A */

        #endif /* Configure Run Mode with hardware enable */

        /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        SAMPLING_RT1 &= ((uint8)(~SAMPLING_RT1_MASK));
        SAMPLING_RT1 |= SAMPLING_SYNC;

        /*Enable DSI Sync all all inputs of the Timer*/
        SAMPLING_RT1 &= ((uint8)(~SAMPLING_SYNCDSI_MASK));
        SAMPLING_RT1 |= SAMPLING_SYNCDSI_EN;

        /* Set the IRQ to use the status register interrupts */
        SAMPLING_CONTROL2 |= SAMPLING_CTRL2_IRQ_SEL;
    #endif /* Configuring registers of fixed function implementation */

    /* Set Initial values from Configuration */
    SAMPLING_WritePeriod(SAMPLING_INIT_PERIOD);
    SAMPLING_WriteCounter(SAMPLING_INIT_PERIOD);

    #if (SAMPLING_UsingHWCaptureCounter)/* Capture counter is enabled */
        SAMPLING_CAPTURE_COUNT_CTRL |= SAMPLING_CNTR_ENABLE;
        SAMPLING_SetCaptureCount(SAMPLING_INIT_CAPTURE_COUNT);
    #endif /* Configure capture counter value */

    #if (!SAMPLING_UsingFixedFunction)
        #if (SAMPLING_SoftwareCaptureMode)
            SAMPLING_SetCaptureMode(SAMPLING_INIT_CAPTURE_MODE);
        #endif /* Set Capture Mode for UDB implementation if capture mode is software controlled */

        #if (SAMPLING_SoftwareTriggerMode)
            #if (!SAMPLING_UDB_CONTROL_REG_REMOVED)
                if (0u == (SAMPLING_CONTROL & SAMPLING__B_TIMER__TM_SOFTWARE))
                {
                    SAMPLING_SetTriggerMode(SAMPLING_INIT_TRIGGER_MODE);
                }
            #endif /* (!SAMPLING_UDB_CONTROL_REG_REMOVED) */
        #endif /* Set trigger mode for UDB Implementation if trigger mode is software controlled */

        /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
        /* Enter Critical Region*/
        SAMPLING_interruptState = CyEnterCriticalSection();

        /* Use the interrupt output of the status register for IRQ output */
        SAMPLING_STATUS_AUX_CTRL |= SAMPLING_STATUS_ACTL_INT_EN_MASK;

        /* Exit Critical Region*/
        CyExitCriticalSection(SAMPLING_interruptState);

        #if (SAMPLING_EnableTriggerMode)
            SAMPLING_EnableTrigger();
        #endif /* Set Trigger enable bit for UDB implementation in the control register*/
		
		
        #if (SAMPLING_InterruptOnCaptureCount && !SAMPLING_UDB_CONTROL_REG_REMOVED)
            SAMPLING_SetInterruptCount(SAMPLING_INIT_INT_CAPTURE_COUNT);
        #endif /* Set interrupt count in UDB implementation if interrupt count feature is checked.*/

        SAMPLING_ClearFIFO();
    #endif /* Configure additional features of UDB implementation */

    SAMPLING_SetInterruptMode(SAMPLING_INIT_INTERRUPT_MODE);
}


/*******************************************************************************
* Function Name: SAMPLING_Enable
********************************************************************************
*
* Summary:
*  Enable the Timer
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (SAMPLING_UsingFixedFunction)
        SAMPLING_GLOBAL_ENABLE |= SAMPLING_BLOCK_EN_MASK;
        SAMPLING_GLOBAL_STBY_ENABLE |= SAMPLING_BLOCK_STBY_EN_MASK;
    #endif /* Set Enable bit for enabling Fixed function timer*/

    /* Remove assignment if control register is removed */
    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED || SAMPLING_UsingFixedFunction)
        SAMPLING_CONTROL |= SAMPLING_CTRL_ENABLE;
    #endif /* Remove assignment if control register is removed */
}


/*******************************************************************************
* Function Name: SAMPLING_Start
********************************************************************************
*
* Summary:
*  The start function initializes the timer with the default values, the
*  enables the timerto begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  SAMPLING_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void SAMPLING_Start(void) 
{
    if(SAMPLING_initVar == 0u)
    {
        SAMPLING_Init();

        SAMPLING_initVar = 1u;   /* Clear this bit for Initialization */
    }

    /* Enable the Timer */
    SAMPLING_Enable();
}


/*******************************************************************************
* Function Name: SAMPLING_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the timer, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the timer.
*
*******************************************************************************/
void SAMPLING_Stop(void) 
{
    /* Disable Timer */
    #if(!SAMPLING_UDB_CONTROL_REG_REMOVED || SAMPLING_UsingFixedFunction)
        SAMPLING_CONTROL &= ((uint8)(~SAMPLING_CTRL_ENABLE));
    #endif /* Remove assignment if control register is removed */

    /* Globally disable the Fixed Function Block chosen */
    #if (SAMPLING_UsingFixedFunction)
        SAMPLING_GLOBAL_ENABLE &= ((uint8)(~SAMPLING_BLOCK_EN_MASK));
        SAMPLING_GLOBAL_STBY_ENABLE &= ((uint8)(~SAMPLING_BLOCK_STBY_EN_MASK));
    #endif /* Disable global enable for the Timer Fixed function block to stop the Timer*/
}


/*******************************************************************************
* Function Name: SAMPLING_SetInterruptMode
********************************************************************************
*
* Summary:
*  This function selects which of the interrupt inputs may cause an interrupt.
*  The twosources are caputure and terminal.  One, both or neither may
*  be selected.
*
* Parameters:
*  interruptMode:   This parameter is used to enable interrups on either/or
*                   terminal count or capture.
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_SetInterruptMode(uint8 interruptMode) 
{
    SAMPLING_STATUS_MASK = interruptMode;
}


/*******************************************************************************
* Function Name: SAMPLING_SoftwareCapture
********************************************************************************
*
* Summary:
*  This function forces a capture independent of the capture signal.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Side Effects:
*  An existing hardware capture could be overwritten.
*
*******************************************************************************/
void SAMPLING_SoftwareCapture(void) 
{
    /* Generate a software capture by reading the counter register */
    #if(SAMPLING_UsingFixedFunction)
        (void)CY_GET_REG16(SAMPLING_COUNTER_LSB_PTR);
    #else
        (void)CY_GET_REG8(SAMPLING_COUNTER_LSB_PTR_8BIT);
    #endif/* (SAMPLING_UsingFixedFunction) */
    /* Capture Data is now in the FIFO */
}


/*******************************************************************************
* Function Name: SAMPLING_ReadStatusRegister
********************************************************************************
*
* Summary:
*  Reads the status register and returns it's state. This function should use
*  defined types for the bit-field information as the bits in this register may
*  be permuteable.
*
* Parameters:
*  void
*
* Return:
*  The contents of the status register
*
* Side Effects:
*  Status register bits may be clear on read.
*
*******************************************************************************/
uint8   SAMPLING_ReadStatusRegister(void) 
{
    return (SAMPLING_STATUS);
}


#if (!SAMPLING_UDB_CONTROL_REG_REMOVED) /* Remove API if control register is unused */


/*******************************************************************************
* Function Name: SAMPLING_ReadControlRegister
********************************************************************************
*
* Summary:
*  Reads the control register and returns it's value.
*
* Parameters:
*  void
*
* Return:
*  The contents of the control register
*
*******************************************************************************/
uint8 SAMPLING_ReadControlRegister(void) 
{
    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED) 
        return ((uint8)SAMPLING_CONTROL);
    #else
        return (0);
    #endif /* (!SAMPLING_UDB_CONTROL_REG_REMOVED) */
}


/*******************************************************************************
* Function Name: SAMPLING_WriteControlRegister
********************************************************************************
*
* Summary:
*  Sets the bit-field of the control register.
*
* Parameters:
*  control: The contents of the control register
*
* Return:
*
*******************************************************************************/
void SAMPLING_WriteControlRegister(uint8 control) 
{
    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED) 
        SAMPLING_CONTROL = control;
    #else
        control = 0u;
    #endif /* (!SAMPLING_UDB_CONTROL_REG_REMOVED) */
}

#endif /* Remove API if control register is unused */


/*******************************************************************************
* Function Name: SAMPLING_ReadPeriod
********************************************************************************
*
* Summary:
*  This function returns the current value of the Period.
*
* Parameters:
*  void
*
* Return:
*  The present value of the counter.
*
*******************************************************************************/
uint8 SAMPLING_ReadPeriod(void) 
{
   #if(SAMPLING_UsingFixedFunction)
       return ((uint8)CY_GET_REG16(SAMPLING_PERIOD_LSB_PTR));
   #else
       return (CY_GET_REG8(SAMPLING_PERIOD_LSB_PTR));
   #endif /* (SAMPLING_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SAMPLING_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period: This value may be between 1 and (2^Resolution)-1.  A value of 0 will
*          result in the counter remaining at zero.
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_WritePeriod(uint8 period) 
{
    #if(SAMPLING_UsingFixedFunction)
        uint16 period_temp = (uint16)period;
        CY_SET_REG16(SAMPLING_PERIOD_LSB_PTR, period_temp);
    #else
        CY_SET_REG8(SAMPLING_PERIOD_LSB_PTR, period);
    #endif /*Write Period value with appropriate resolution suffix depending on UDB or fixed function implementation */
}


/*******************************************************************************
* Function Name: SAMPLING_ReadCapture
********************************************************************************
*
* Summary:
*  This function returns the last value captured.
*
* Parameters:
*  void
*
* Return:
*  Present Capture value.
*
*******************************************************************************/
uint8 SAMPLING_ReadCapture(void) 
{
   #if(SAMPLING_UsingFixedFunction)
       return ((uint8)CY_GET_REG16(SAMPLING_CAPTURE_LSB_PTR));
   #else
       return (CY_GET_REG8(SAMPLING_CAPTURE_LSB_PTR));
   #endif /* (SAMPLING_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SAMPLING_WriteCounter
********************************************************************************
*
* Summary:
*  This funtion is used to set the counter to a specific value
*
* Parameters:
*  counter:  New counter value.
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_WriteCounter(uint8 counter) 
{
   #if(SAMPLING_UsingFixedFunction)
        /* This functionality is removed until a FixedFunction HW update to
         * allow this register to be written
         */
        CY_SET_REG16(SAMPLING_COUNTER_LSB_PTR, (uint16)counter);
        
    #else
        CY_SET_REG8(SAMPLING_COUNTER_LSB_PTR, counter);
    #endif /* Set Write Counter only for the UDB implementation (Write Counter not available in fixed function Timer */
}


/*******************************************************************************
* Function Name: SAMPLING_ReadCounter
********************************************************************************
*
* Summary:
*  This function returns the current counter value.
*
* Parameters:
*  void
*
* Return:
*  Present compare value.
*
*******************************************************************************/
uint8 SAMPLING_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(SAMPLING_UsingFixedFunction)
        (void)CY_GET_REG16(SAMPLING_COUNTER_LSB_PTR);
    #else
        (void)CY_GET_REG8(SAMPLING_COUNTER_LSB_PTR_8BIT);
    #endif/* (SAMPLING_UsingFixedFunction) */

    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(SAMPLING_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(SAMPLING_CAPTURE_LSB_PTR));
    #else
        return (CY_GET_REG8(SAMPLING_CAPTURE_LSB_PTR));
    #endif /* (SAMPLING_UsingFixedFunction) */
}


#if(!SAMPLING_UsingFixedFunction) /* UDB Specific Functions */

    
/*******************************************************************************
 * The functions below this point are only available using the UDB
 * implementation.  If a feature is selected, then the API is enabled.
 ******************************************************************************/


#if (SAMPLING_SoftwareCaptureMode)


/*******************************************************************************
* Function Name: SAMPLING_SetCaptureMode
********************************************************************************
*
* Summary:
*  This function sets the capture mode to either rising or falling edge.
*
* Parameters:
*  captureMode: This parameter sets the capture mode of the UDB capture feature
*  The parameter values are defined using the
*  #define SAMPLING__B_TIMER__CM_NONE 0
#define SAMPLING__B_TIMER__CM_RISINGEDGE 1
#define SAMPLING__B_TIMER__CM_FALLINGEDGE 2
#define SAMPLING__B_TIMER__CM_EITHEREDGE 3
#define SAMPLING__B_TIMER__CM_SOFTWARE 4
 identifiers
*  The following are the possible values of the parameter
*  SAMPLING__B_TIMER__CM_NONE        - Set Capture mode to None
*  SAMPLING__B_TIMER__CM_RISINGEDGE  - Rising edge of Capture input
*  SAMPLING__B_TIMER__CM_FALLINGEDGE - Falling edge of Capture input
*  SAMPLING__B_TIMER__CM_EITHEREDGE  - Either edge of Capture input
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_SetCaptureMode(uint8 captureMode) 
{
    /* This must only set to two bits of the control register associated */
    captureMode = ((uint8)((uint8)captureMode << SAMPLING_CTRL_CAP_MODE_SHIFT));
    captureMode &= (SAMPLING_CTRL_CAP_MODE_MASK);

    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED)
        /* Clear the Current Setting */
        SAMPLING_CONTROL &= ((uint8)(~SAMPLING_CTRL_CAP_MODE_MASK));

        /* Write The New Setting */
        SAMPLING_CONTROL |= captureMode;
    #endif /* (!SAMPLING_UDB_CONTROL_REG_REMOVED) */
}
#endif /* Remove API if Capture Mode is not Software Controlled */


#if (SAMPLING_SoftwareTriggerMode)


/*******************************************************************************
* Function Name: SAMPLING_SetTriggerMode
********************************************************************************
*
* Summary:
*  This function sets the trigger input mode
*
* Parameters:
*  triggerMode: Pass one of the pre-defined Trigger Modes (except Software)
    #define SAMPLING__B_TIMER__TM_NONE 0x00u
    #define SAMPLING__B_TIMER__TM_RISINGEDGE 0x04u
    #define SAMPLING__B_TIMER__TM_FALLINGEDGE 0x08u
    #define SAMPLING__B_TIMER__TM_EITHEREDGE 0x0Cu
    #define SAMPLING__B_TIMER__TM_SOFTWARE 0x10u
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_SetTriggerMode(uint8 triggerMode) 
{
    /* This must only set to two bits of the control register associated */
    triggerMode &= SAMPLING_CTRL_TRIG_MODE_MASK;

    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED)   /* Remove assignment if control register is removed */
    
        /* Clear the Current Setting */
        SAMPLING_CONTROL &= ((uint8)(~SAMPLING_CTRL_TRIG_MODE_MASK));

        /* Write The New Setting */
        SAMPLING_CONTROL |= (triggerMode | SAMPLING__B_TIMER__TM_SOFTWARE);
    #endif /* Remove code section if control register is not used */
}
#endif /* Remove API if Trigger Mode is not Software Controlled */

#if (SAMPLING_EnableTriggerMode)


/*******************************************************************************
* Function Name: SAMPLING_EnableTrigger
********************************************************************************
*
* Summary:
*  Sets the control bit enabling Hardware Trigger mode
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_EnableTrigger(void) 
{
    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED)   /* Remove assignment if control register is removed */
        SAMPLING_CONTROL |= SAMPLING_CTRL_TRIG_EN;
    #endif /* Remove code section if control register is not used */
}


/*******************************************************************************
* Function Name: SAMPLING_DisableTrigger
********************************************************************************
*
* Summary:
*  Clears the control bit enabling Hardware Trigger mode
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_DisableTrigger(void) 
{
    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED )   /* Remove assignment if control register is removed */
        SAMPLING_CONTROL &= ((uint8)(~SAMPLING_CTRL_TRIG_EN));
    #endif /* Remove code section if control register is not used */
}
#endif /* Remove API is Trigger Mode is set to None */

#if(SAMPLING_InterruptOnCaptureCount)


/*******************************************************************************
* Function Name: SAMPLING_SetInterruptCount
********************************************************************************
*
* Summary:
*  This function sets the capture count before an interrupt is triggered.
*
* Parameters:
*  interruptCount:  A value between 0 and 3 is valid.  If the value is 0, then
*                   an interrupt will occur each time a capture occurs.
*                   A value of 1 to 3 will cause the interrupt
*                   to delay by the same number of captures.
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_SetInterruptCount(uint8 interruptCount) 
{
    /* This must only set to two bits of the control register associated */
    interruptCount &= SAMPLING_CTRL_INTCNT_MASK;

    #if (!SAMPLING_UDB_CONTROL_REG_REMOVED)
        /* Clear the Current Setting */
        SAMPLING_CONTROL &= ((uint8)(~SAMPLING_CTRL_INTCNT_MASK));
        /* Write The New Setting */
        SAMPLING_CONTROL |= interruptCount;
    #endif /* (!SAMPLING_UDB_CONTROL_REG_REMOVED) */
}
#endif /* SAMPLING_InterruptOnCaptureCount */


#if (SAMPLING_UsingHWCaptureCounter)


/*******************************************************************************
* Function Name: SAMPLING_SetCaptureCount
********************************************************************************
*
* Summary:
*  This function sets the capture count
*
* Parameters:
*  captureCount: A value between 2 and 127 inclusive is valid.  A value of 1
*                to 127 will cause the interrupt to delay by the same number of
*                captures.
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_SetCaptureCount(uint8 captureCount) 
{
    SAMPLING_CAP_COUNT = captureCount;
}


/*******************************************************************************
* Function Name: SAMPLING_ReadCaptureCount
********************************************************************************
*
* Summary:
*  This function reads the capture count setting
*
* Parameters:
*  void
*
* Return:
*  Returns the Capture Count Setting
*
*******************************************************************************/
uint8 SAMPLING_ReadCaptureCount(void) 
{
    return ((uint8)SAMPLING_CAP_COUNT);
}
#endif /* SAMPLING_UsingHWCaptureCounter */


/*******************************************************************************
* Function Name: SAMPLING_ClearFIFO
********************************************************************************
*
* Summary:
*  This function clears all capture data from the capture FIFO
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void SAMPLING_ClearFIFO(void) 
{
    while(0u != (SAMPLING_ReadStatusRegister() & SAMPLING_STATUS_FIFONEMP))
    {
        (void)SAMPLING_ReadCapture();
    }
}

#endif /* UDB Specific Functions */


/* [] END OF FILE */
