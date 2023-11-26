/*******************************************************************************
* File Name: MOTOR_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "MOTOR.h"

static MOTOR_backupStruct MOTOR_backup;


/*******************************************************************************
* Function Name: MOTOR_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void MOTOR_SaveConfig(void) 
{

    #if(!MOTOR_UsingFixedFunction)
        #if(!MOTOR_PWMModeIsCenterAligned)
            MOTOR_backup.PWMPeriod = MOTOR_ReadPeriod();
        #endif /* (!MOTOR_PWMModeIsCenterAligned) */
        MOTOR_backup.PWMUdb = MOTOR_ReadCounter();
        #if (MOTOR_UseStatus)
            MOTOR_backup.InterruptMaskValue = MOTOR_STATUS_MASK;
        #endif /* (MOTOR_UseStatus) */

        #if(MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_256_CLOCKS || \
            MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_2_4_CLOCKS)
            MOTOR_backup.PWMdeadBandValue = MOTOR_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(MOTOR_KillModeMinTime)
             MOTOR_backup.PWMKillCounterPeriod = MOTOR_ReadKillTime();
        #endif /* (MOTOR_KillModeMinTime) */

        #if(MOTOR_UseControl)
            MOTOR_backup.PWMControlRegister = MOTOR_ReadControlRegister();
        #endif /* (MOTOR_UseControl) */
    #endif  /* (!MOTOR_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: MOTOR_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void MOTOR_RestoreConfig(void) 
{
        #if(!MOTOR_UsingFixedFunction)
            #if(!MOTOR_PWMModeIsCenterAligned)
                MOTOR_WritePeriod(MOTOR_backup.PWMPeriod);
            #endif /* (!MOTOR_PWMModeIsCenterAligned) */

            MOTOR_WriteCounter(MOTOR_backup.PWMUdb);

            #if (MOTOR_UseStatus)
                MOTOR_STATUS_MASK = MOTOR_backup.InterruptMaskValue;
            #endif /* (MOTOR_UseStatus) */

            #if(MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_256_CLOCKS || \
                MOTOR_DeadBandMode == MOTOR__B_PWM__DBM_2_4_CLOCKS)
                MOTOR_WriteDeadTime(MOTOR_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(MOTOR_KillModeMinTime)
                MOTOR_WriteKillTime(MOTOR_backup.PWMKillCounterPeriod);
            #endif /* (MOTOR_KillModeMinTime) */

            #if(MOTOR_UseControl)
                MOTOR_WriteControlRegister(MOTOR_backup.PWMControlRegister);
            #endif /* (MOTOR_UseControl) */
        #endif  /* (!MOTOR_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: MOTOR_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void MOTOR_Sleep(void) 
{
    #if(MOTOR_UseControl)
        if(MOTOR_CTRL_ENABLE == (MOTOR_CONTROL & MOTOR_CTRL_ENABLE))
        {
            /*Component is enabled */
            MOTOR_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            MOTOR_backup.PWMEnableState = 0u;
        }
    #endif /* (MOTOR_UseControl) */

    /* Stop component */
    MOTOR_Stop();

    /* Save registers configuration */
    MOTOR_SaveConfig();
}


/*******************************************************************************
* Function Name: MOTOR_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void MOTOR_Wakeup(void) 
{
     /* Restore registers values */
    MOTOR_RestoreConfig();

    if(MOTOR_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        MOTOR_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
