/*******************************************************************************
* File Name: MOTOR.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "MOTOR.h"

/* Error message for removed <resource> through optimization */
#ifdef MOTOR_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* MOTOR_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 MOTOR_initVar = 0u;


/*******************************************************************************
* Function Name: MOTOR_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void MOTOR_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(MOTOR_initVar == 0u)
    {
        MOTOR_Init();
        MOTOR_initVar = 1u;
    }
    MOTOR_Enable();

}


/*******************************************************************************
* Function Name: MOTOR_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  MOTOR_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MOTOR_Init(void) 
{
    #if (MOTOR_UsingFixedFunction || MOTOR_UseControl)
        uint8 ctrl;
    #endif /* (MOTOR_UsingFixedFunction || MOTOR_UseControl) */

    #if(!MOTOR_UsingFixedFunction)
        #if(MOTOR_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 MOTOR_interruptState;
        #endif /* (MOTOR_UseStatus) */
    #endif /* (!MOTOR_UsingFixedFunction) */

    #if (MOTOR_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        MOTOR_CONTROL |= MOTOR_CFG0_MODE;
        #if (MOTOR_DeadBand2_4)
            MOTOR_CONTROL |= MOTOR_CFG0_DB;
        #endif /* (MOTOR_DeadBand2_4) */

        ctrl = MOTOR_CONTROL3 & ((uint8 )(~MOTOR_CTRL_CMPMODE1_MASK));
        MOTOR_CONTROL3 = ctrl | MOTOR_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        MOTOR_RT1 &= ((uint8)(~MOTOR_RT1_MASK));
        MOTOR_RT1 |= MOTOR_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        MOTOR_RT1 &= ((uint8)(~MOTOR_SYNCDSI_MASK));
        MOTOR_RT1 |= MOTOR_SYNCDSI_EN;

    #elif (MOTOR_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = MOTOR_CONTROL & ((uint8)(~MOTOR_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~MOTOR_CTRL_CMPMODE1_MASK));
        MOTOR_CONTROL = ctrl | MOTOR_DEFAULT_COMPARE2_MODE |
                                   MOTOR_DEFAULT_COMPARE1_MODE;
    #endif /* (MOTOR_UsingFixedFunction) */

    #if (!MOTOR_UsingFixedFunction)
        #if (MOTOR_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            MOTOR_AUX_CONTROLDP0 |= (MOTOR_AUX_CTRL_FIFO0_CLR);
        #else /* (MOTOR_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            MOTOR_AUX_CONTROLDP0 |= (MOTOR_AUX_CTRL_FIFO0_CLR);
            MOTOR_AUX_CONTROLDP1 |= (MOTOR_AUX_CTRL_FIFO0_CLR);
        #endif /* (MOTOR_Resolution == 8) */

        MOTOR_WriteCounter(MOTOR_INIT_PERIOD_VALUE);
    #endif /* (!MOTOR_UsingFixedFunction) */

    MOTOR_WritePeriod(MOTOR_INIT_PERIOD_VALUE);

        #if (MOTOR_UseOneCompareMode)
            MOTOR_WriteCompare(MOTOR_INIT_COMPARE_VALUE1);
        #else
            MOTOR_WriteCompare1(MOTOR_INIT_COMPARE_VALUE1);
            MOTOR_WriteCompare2(MOTOR_INIT_COMPARE_VALUE2);
        #endif /* (MOTOR_UseOneCompareMode) */

        #if (MOTOR_KillModeMinTime)
            MOTOR_WriteKillTime(MOTOR_MinimumKillTime);
        #endif /* (MOTOR_KillModeMinTime) */

        #if (MOTOR_DeadBandUsed)
            MOTOR_WriteDeadTime(MOTOR_INIT_DEAD_TIME);
        #endif /* (MOTOR_DeadBandUsed) */

    #if (MOTOR_UseStatus || MOTOR_UsingFixedFunction)
        MOTOR_SetInterruptMode(MOTOR_INIT_INTERRUPTS_MODE);
    #endif /* (MOTOR_UseStatus || MOTOR_UsingFixedFunction) */

    #if (MOTOR_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        MOTOR_GLOBAL_ENABLE |= MOTOR_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        MOTOR_CONTROL2 |= MOTOR_CTRL2_IRQ_SEL;
    #else
        #if(MOTOR_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            MOTOR_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            MOTOR_STATUS_AUX_CTRL |= MOTOR_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(MOTOR_interruptState);

            /* Clear the FIFO to enable the MOTOR_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            MOTOR_ClearFIFO();
        #endif /* (MOTOR_UseStatus) */
    #endif /* (MOTOR_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: MOTOR_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void MOTOR_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (MOTOR_UsingFixedFunction)
        MOTOR_GLOBAL_ENABLE |= MOTOR_BLOCK_EN_MASK;
        MOTOR_GLOBAL_STBY_ENABLE |= MOTOR_BLOCK_STBY_EN_MASK;
    #endif /* (MOTOR_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (MOTOR_UseControl || MOTOR_UsingFixedFunction)
        MOTOR_CONTROL |= MOTOR_CTRL_ENABLE;
    #endif /* (MOTOR_UseControl || MOTOR_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: MOTOR_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void MOTOR_Stop(void) 
{
    #if (MOTOR_UseControl || MOTOR_UsingFixedFunction)
        MOTOR_CONTROL &= ((uint8)(~MOTOR_CTRL_ENABLE));
    #endif /* (MOTOR_UseControl || MOTOR_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (MOTOR_UsingFixedFunction)
        MOTOR_GLOBAL_ENABLE &= ((uint8)(~MOTOR_BLOCK_EN_MASK));
        MOTOR_GLOBAL_STBY_ENABLE &= ((uint8)(~MOTOR_BLOCK_STBY_EN_MASK));
    #endif /* (MOTOR_UsingFixedFunction) */
}

#if (MOTOR_UseOneCompareMode)
    #if (MOTOR_CompareMode1SW)


        /*******************************************************************************
        * Function Name: MOTOR_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void MOTOR_SetCompareMode(uint8 comparemode) 
        {
            #if(MOTOR_UsingFixedFunction)

                #if(0 != MOTOR_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << MOTOR_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != MOTOR_CTRL_CMPMODE1_SHIFT) */

                MOTOR_CONTROL3 &= ((uint8)(~MOTOR_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                MOTOR_CONTROL3 |= comparemodemasked;

            #elif (MOTOR_UseControl)

                #if(0 != MOTOR_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << MOTOR_CTRL_CMPMODE1_SHIFT)) &
                                                MOTOR_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & MOTOR_CTRL_CMPMODE1_MASK;
                #endif /* (0 != MOTOR_CTRL_CMPMODE1_SHIFT) */

                #if(0 != MOTOR_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << MOTOR_CTRL_CMPMODE2_SHIFT)) &
                                               MOTOR_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & MOTOR_CTRL_CMPMODE2_MASK;
                #endif /* (0 != MOTOR_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                MOTOR_CONTROL &= ((uint8)(~(MOTOR_CTRL_CMPMODE1_MASK |
                                            MOTOR_CTRL_CMPMODE2_MASK)));
                MOTOR_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (MOTOR_UsingFixedFunction) */
        }
    #endif /* MOTOR_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (MOTOR_CompareMode1SW)


        /*******************************************************************************
        * Function Name: MOTOR_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void MOTOR_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != MOTOR_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << MOTOR_CTRL_CMPMODE1_SHIFT)) &
                                           MOTOR_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & MOTOR_CTRL_CMPMODE1_MASK;
            #endif /* (0 != MOTOR_CTRL_CMPMODE1_SHIFT) */

            #if (MOTOR_UseControl)
                MOTOR_CONTROL &= ((uint8)(~MOTOR_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                MOTOR_CONTROL |= comparemodemasked;
            #endif /* (MOTOR_UseControl) */
        }
    #endif /* MOTOR_CompareMode1SW */

#if (MOTOR_CompareMode2SW)


    /*******************************************************************************
    * Function Name: MOTOR_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void MOTOR_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != MOTOR_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << MOTOR_CTRL_CMPMODE2_SHIFT)) &
                                                 MOTOR_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & MOTOR_CTRL_CMPMODE2_MASK;
        #endif /* (0 != MOTOR_CTRL_CMPMODE2_SHIFT) */

        #if (MOTOR_UseControl)
            MOTOR_CONTROL &= ((uint8)(~MOTOR_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            MOTOR_CONTROL |= comparemodemasked;
        #endif /* (MOTOR_UseControl) */
    }
    #endif /*MOTOR_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!MOTOR_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: MOTOR_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void MOTOR_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(MOTOR_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: MOTOR_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 MOTOR_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(MOTOR_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(MOTOR_CAPTURE_LSB_PTR));
    }

    #if (MOTOR_UseStatus)


        /*******************************************************************************
        * Function Name: MOTOR_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void MOTOR_ClearFIFO(void) 
        {
            while(0u != (MOTOR_ReadStatusRegister() & MOTOR_STATUS_FIFONEMPTY))
            {
                (void)MOTOR_ReadCapture();
            }
        }

    #endif /* MOTOR_UseStatus */

#endif /* !MOTOR_UsingFixedFunction */


/*******************************************************************************
* Function Name: MOTOR_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void MOTOR_WritePeriod(uint16 period) 
{
    #if(MOTOR_UsingFixedFunction)
        CY_SET_REG16(MOTOR_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(MOTOR_PERIOD_LSB_PTR, period);
    #endif /* (MOTOR_UsingFixedFunction) */
}

#if (MOTOR_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: MOTOR_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void MOTOR_WriteCompare(uint16 compare) \
                                       
    {
        #if(MOTOR_UsingFixedFunction)
            CY_SET_REG16(MOTOR_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(MOTOR_COMPARE1_LSB_PTR, compare);
        #endif /* (MOTOR_UsingFixedFunction) */

        #if (MOTOR_PWMMode == MOTOR__B_PWM__DITHER)
            #if(MOTOR_UsingFixedFunction)
                CY_SET_REG16(MOTOR_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(MOTOR_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (MOTOR_UsingFixedFunction) */
        #endif /* (MOTOR_PWMMode == MOTOR__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: MOTOR_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void MOTOR_WriteCompare1(uint16 compare) \
                                        
    {
        #if(MOTOR_UsingFixedFunction)
            CY_SET_REG16(MOTOR_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(MOTOR_COMPARE1_LSB_PTR, compare);
        #endif /* (MOTOR_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: MOTOR_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void MOTOR_WriteCompare2(uint16 compare) \
                                        
    {
        #if(MOTOR_UsingFixedFunction)
            CY_SET_REG16(MOTOR_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(MOTOR_COMPARE2_LSB_PTR, compare);
        #endif /* (MOTOR_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (MOTOR_DeadBandUsed)


    /*******************************************************************************
    * Function Name: MOTOR_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void MOTOR_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!MOTOR_DeadBand2_4)
            CY_SET_REG8(MOTOR_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            MOTOR_DEADBAND_COUNT &= ((uint8)(~MOTOR_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(MOTOR_DEADBAND_COUNT_SHIFT)
                MOTOR_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << MOTOR_DEADBAND_COUNT_SHIFT)) &
                                                    MOTOR_DEADBAND_COUNT_MASK;
            #else
                MOTOR_DEADBAND_COUNT |= deadtime & MOTOR_DEADBAND_COUNT_MASK;
            #endif /* (MOTOR_DEADBAND_COUNT_SHIFT) */

        #endif /* (!MOTOR_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: MOTOR_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 MOTOR_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!MOTOR_DeadBand2_4)
            return (CY_GET_REG8(MOTOR_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(MOTOR_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(MOTOR_DEADBAND_COUNT & MOTOR_DEADBAND_COUNT_MASK)) >>
                                                                           MOTOR_DEADBAND_COUNT_SHIFT));
            #else
                return (MOTOR_DEADBAND_COUNT & MOTOR_DEADBAND_COUNT_MASK);
            #endif /* (MOTOR_DEADBAND_COUNT_SHIFT) */
        #endif /* (!MOTOR_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (MOTOR_UseStatus || MOTOR_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: MOTOR_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void MOTOR_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(MOTOR_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: MOTOR_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 MOTOR_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(MOTOR_STATUS_PTR));
    }

#endif /* (MOTOR_UseStatus || MOTOR_UsingFixedFunction) */


#if (MOTOR_UseControl)


    /*******************************************************************************
    * Function Name: MOTOR_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 MOTOR_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(MOTOR_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: MOTOR_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void MOTOR_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(MOTOR_CONTROL_PTR, control);
    }

#endif /* (MOTOR_UseControl) */


#if (!MOTOR_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: MOTOR_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 MOTOR_ReadCapture(void) 
    {
        return (CY_GET_REG16(MOTOR_CAPTURE_LSB_PTR));
    }

#endif /* (!MOTOR_UsingFixedFunction) */


#if (MOTOR_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: MOTOR_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 MOTOR_ReadCompare(void) 
    {
        #if(MOTOR_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(MOTOR_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(MOTOR_COMPARE1_LSB_PTR));
        #endif /* (MOTOR_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: MOTOR_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 MOTOR_ReadCompare1(void) 
    {
        return (CY_GET_REG16(MOTOR_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: MOTOR_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 MOTOR_ReadCompare2(void) 
    {
        return (CY_GET_REG16(MOTOR_COMPARE2_LSB_PTR));
    }

#endif /* (MOTOR_UseOneCompareMode) */


/*******************************************************************************
* Function Name: MOTOR_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 MOTOR_ReadPeriod(void) 
{
    #if(MOTOR_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(MOTOR_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(MOTOR_PERIOD_LSB_PTR));
    #endif /* (MOTOR_UsingFixedFunction) */
}

#if ( MOTOR_KillModeMinTime)


    /*******************************************************************************
    * Function Name: MOTOR_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void MOTOR_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(MOTOR_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: MOTOR_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 MOTOR_ReadKillTime(void) 
    {
        return (CY_GET_REG8(MOTOR_KILLMODEMINTIME_PTR));
    }

#endif /* ( MOTOR_KillModeMinTime) */

/* [] END OF FILE */
