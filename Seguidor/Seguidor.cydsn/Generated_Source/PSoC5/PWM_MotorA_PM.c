/*******************************************************************************
* File Name: PWM_MotorA_PM.c
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

#include "PWM_MotorA.h"

static PWM_MotorA_backupStruct PWM_MotorA_backup;


/*******************************************************************************
* Function Name: PWM_MotorA_SaveConfig
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
*  PWM_MotorA_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_MotorA_SaveConfig(void) 
{

    #if(!PWM_MotorA_UsingFixedFunction)
        #if(!PWM_MotorA_PWMModeIsCenterAligned)
            PWM_MotorA_backup.PWMPeriod = PWM_MotorA_ReadPeriod();
        #endif /* (!PWM_MotorA_PWMModeIsCenterAligned) */
        PWM_MotorA_backup.PWMUdb = PWM_MotorA_ReadCounter();
        #if (PWM_MotorA_UseStatus)
            PWM_MotorA_backup.InterruptMaskValue = PWM_MotorA_STATUS_MASK;
        #endif /* (PWM_MotorA_UseStatus) */

        #if(PWM_MotorA_DeadBandMode == PWM_MotorA__B_PWM__DBM_256_CLOCKS || \
            PWM_MotorA_DeadBandMode == PWM_MotorA__B_PWM__DBM_2_4_CLOCKS)
            PWM_MotorA_backup.PWMdeadBandValue = PWM_MotorA_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_MotorA_KillModeMinTime)
             PWM_MotorA_backup.PWMKillCounterPeriod = PWM_MotorA_ReadKillTime();
        #endif /* (PWM_MotorA_KillModeMinTime) */

        #if(PWM_MotorA_UseControl)
            PWM_MotorA_backup.PWMControlRegister = PWM_MotorA_ReadControlRegister();
        #endif /* (PWM_MotorA_UseControl) */
    #endif  /* (!PWM_MotorA_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_MotorA_RestoreConfig
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
*  PWM_MotorA_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MotorA_RestoreConfig(void) 
{
        #if(!PWM_MotorA_UsingFixedFunction)
            #if(!PWM_MotorA_PWMModeIsCenterAligned)
                PWM_MotorA_WritePeriod(PWM_MotorA_backup.PWMPeriod);
            #endif /* (!PWM_MotorA_PWMModeIsCenterAligned) */

            PWM_MotorA_WriteCounter(PWM_MotorA_backup.PWMUdb);

            #if (PWM_MotorA_UseStatus)
                PWM_MotorA_STATUS_MASK = PWM_MotorA_backup.InterruptMaskValue;
            #endif /* (PWM_MotorA_UseStatus) */

            #if(PWM_MotorA_DeadBandMode == PWM_MotorA__B_PWM__DBM_256_CLOCKS || \
                PWM_MotorA_DeadBandMode == PWM_MotorA__B_PWM__DBM_2_4_CLOCKS)
                PWM_MotorA_WriteDeadTime(PWM_MotorA_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_MotorA_KillModeMinTime)
                PWM_MotorA_WriteKillTime(PWM_MotorA_backup.PWMKillCounterPeriod);
            #endif /* (PWM_MotorA_KillModeMinTime) */

            #if(PWM_MotorA_UseControl)
                PWM_MotorA_WriteControlRegister(PWM_MotorA_backup.PWMControlRegister);
            #endif /* (PWM_MotorA_UseControl) */
        #endif  /* (!PWM_MotorA_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_MotorA_Sleep
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
*  PWM_MotorA_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_MotorA_Sleep(void) 
{
    #if(PWM_MotorA_UseControl)
        if(PWM_MotorA_CTRL_ENABLE == (PWM_MotorA_CONTROL & PWM_MotorA_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_MotorA_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_MotorA_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_MotorA_UseControl) */

    /* Stop component */
    PWM_MotorA_Stop();

    /* Save registers configuration */
    PWM_MotorA_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_MotorA_Wakeup
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
*  PWM_MotorA_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MotorA_Wakeup(void) 
{
     /* Restore registers values */
    PWM_MotorA_RestoreConfig();

    if(PWM_MotorA_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_MotorA_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
