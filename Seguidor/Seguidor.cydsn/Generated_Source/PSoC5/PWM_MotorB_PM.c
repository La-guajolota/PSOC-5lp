/*******************************************************************************
* File Name: PWM_MotorB_PM.c
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

#include "PWM_MotorB.h"

static PWM_MotorB_backupStruct PWM_MotorB_backup;


/*******************************************************************************
* Function Name: PWM_MotorB_SaveConfig
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
*  PWM_MotorB_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_MotorB_SaveConfig(void) 
{

    #if(!PWM_MotorB_UsingFixedFunction)
        #if(!PWM_MotorB_PWMModeIsCenterAligned)
            PWM_MotorB_backup.PWMPeriod = PWM_MotorB_ReadPeriod();
        #endif /* (!PWM_MotorB_PWMModeIsCenterAligned) */
        PWM_MotorB_backup.PWMUdb = PWM_MotorB_ReadCounter();
        #if (PWM_MotorB_UseStatus)
            PWM_MotorB_backup.InterruptMaskValue = PWM_MotorB_STATUS_MASK;
        #endif /* (PWM_MotorB_UseStatus) */

        #if(PWM_MotorB_DeadBandMode == PWM_MotorB__B_PWM__DBM_256_CLOCKS || \
            PWM_MotorB_DeadBandMode == PWM_MotorB__B_PWM__DBM_2_4_CLOCKS)
            PWM_MotorB_backup.PWMdeadBandValue = PWM_MotorB_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_MotorB_KillModeMinTime)
             PWM_MotorB_backup.PWMKillCounterPeriod = PWM_MotorB_ReadKillTime();
        #endif /* (PWM_MotorB_KillModeMinTime) */

        #if(PWM_MotorB_UseControl)
            PWM_MotorB_backup.PWMControlRegister = PWM_MotorB_ReadControlRegister();
        #endif /* (PWM_MotorB_UseControl) */
    #endif  /* (!PWM_MotorB_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_MotorB_RestoreConfig
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
*  PWM_MotorB_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MotorB_RestoreConfig(void) 
{
        #if(!PWM_MotorB_UsingFixedFunction)
            #if(!PWM_MotorB_PWMModeIsCenterAligned)
                PWM_MotorB_WritePeriod(PWM_MotorB_backup.PWMPeriod);
            #endif /* (!PWM_MotorB_PWMModeIsCenterAligned) */

            PWM_MotorB_WriteCounter(PWM_MotorB_backup.PWMUdb);

            #if (PWM_MotorB_UseStatus)
                PWM_MotorB_STATUS_MASK = PWM_MotorB_backup.InterruptMaskValue;
            #endif /* (PWM_MotorB_UseStatus) */

            #if(PWM_MotorB_DeadBandMode == PWM_MotorB__B_PWM__DBM_256_CLOCKS || \
                PWM_MotorB_DeadBandMode == PWM_MotorB__B_PWM__DBM_2_4_CLOCKS)
                PWM_MotorB_WriteDeadTime(PWM_MotorB_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_MotorB_KillModeMinTime)
                PWM_MotorB_WriteKillTime(PWM_MotorB_backup.PWMKillCounterPeriod);
            #endif /* (PWM_MotorB_KillModeMinTime) */

            #if(PWM_MotorB_UseControl)
                PWM_MotorB_WriteControlRegister(PWM_MotorB_backup.PWMControlRegister);
            #endif /* (PWM_MotorB_UseControl) */
        #endif  /* (!PWM_MotorB_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_MotorB_Sleep
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
*  PWM_MotorB_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_MotorB_Sleep(void) 
{
    #if(PWM_MotorB_UseControl)
        if(PWM_MotorB_CTRL_ENABLE == (PWM_MotorB_CONTROL & PWM_MotorB_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_MotorB_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_MotorB_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_MotorB_UseControl) */

    /* Stop component */
    PWM_MotorB_Stop();

    /* Save registers configuration */
    PWM_MotorB_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_MotorB_Wakeup
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
*  PWM_MotorB_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MotorB_Wakeup(void) 
{
     /* Restore registers values */
    PWM_MotorB_RestoreConfig();

    if(PWM_MotorB_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_MotorB_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
