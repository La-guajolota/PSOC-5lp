/*******************************************************************************
* File Name: PWM_Mosfet_PM.c
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

#include "PWM_Mosfet.h"

static PWM_Mosfet_backupStruct PWM_Mosfet_backup;


/*******************************************************************************
* Function Name: PWM_Mosfet_SaveConfig
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
*  PWM_Mosfet_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Mosfet_SaveConfig(void) 
{

    #if(!PWM_Mosfet_UsingFixedFunction)
        #if(!PWM_Mosfet_PWMModeIsCenterAligned)
            PWM_Mosfet_backup.PWMPeriod = PWM_Mosfet_ReadPeriod();
        #endif /* (!PWM_Mosfet_PWMModeIsCenterAligned) */
        PWM_Mosfet_backup.PWMUdb = PWM_Mosfet_ReadCounter();
        #if (PWM_Mosfet_UseStatus)
            PWM_Mosfet_backup.InterruptMaskValue = PWM_Mosfet_STATUS_MASK;
        #endif /* (PWM_Mosfet_UseStatus) */

        #if(PWM_Mosfet_DeadBandMode == PWM_Mosfet__B_PWM__DBM_256_CLOCKS || \
            PWM_Mosfet_DeadBandMode == PWM_Mosfet__B_PWM__DBM_2_4_CLOCKS)
            PWM_Mosfet_backup.PWMdeadBandValue = PWM_Mosfet_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Mosfet_KillModeMinTime)
             PWM_Mosfet_backup.PWMKillCounterPeriod = PWM_Mosfet_ReadKillTime();
        #endif /* (PWM_Mosfet_KillModeMinTime) */

        #if(PWM_Mosfet_UseControl)
            PWM_Mosfet_backup.PWMControlRegister = PWM_Mosfet_ReadControlRegister();
        #endif /* (PWM_Mosfet_UseControl) */
    #endif  /* (!PWM_Mosfet_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Mosfet_RestoreConfig
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
*  PWM_Mosfet_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Mosfet_RestoreConfig(void) 
{
        #if(!PWM_Mosfet_UsingFixedFunction)
            #if(!PWM_Mosfet_PWMModeIsCenterAligned)
                PWM_Mosfet_WritePeriod(PWM_Mosfet_backup.PWMPeriod);
            #endif /* (!PWM_Mosfet_PWMModeIsCenterAligned) */

            PWM_Mosfet_WriteCounter(PWM_Mosfet_backup.PWMUdb);

            #if (PWM_Mosfet_UseStatus)
                PWM_Mosfet_STATUS_MASK = PWM_Mosfet_backup.InterruptMaskValue;
            #endif /* (PWM_Mosfet_UseStatus) */

            #if(PWM_Mosfet_DeadBandMode == PWM_Mosfet__B_PWM__DBM_256_CLOCKS || \
                PWM_Mosfet_DeadBandMode == PWM_Mosfet__B_PWM__DBM_2_4_CLOCKS)
                PWM_Mosfet_WriteDeadTime(PWM_Mosfet_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Mosfet_KillModeMinTime)
                PWM_Mosfet_WriteKillTime(PWM_Mosfet_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Mosfet_KillModeMinTime) */

            #if(PWM_Mosfet_UseControl)
                PWM_Mosfet_WriteControlRegister(PWM_Mosfet_backup.PWMControlRegister);
            #endif /* (PWM_Mosfet_UseControl) */
        #endif  /* (!PWM_Mosfet_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Mosfet_Sleep
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
*  PWM_Mosfet_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Mosfet_Sleep(void) 
{
    #if(PWM_Mosfet_UseControl)
        if(PWM_Mosfet_CTRL_ENABLE == (PWM_Mosfet_CONTROL & PWM_Mosfet_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Mosfet_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Mosfet_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Mosfet_UseControl) */

    /* Stop component */
    PWM_Mosfet_Stop();

    /* Save registers configuration */
    PWM_Mosfet_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Mosfet_Wakeup
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
*  PWM_Mosfet_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Mosfet_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Mosfet_RestoreConfig();

    if(PWM_Mosfet_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Mosfet_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
