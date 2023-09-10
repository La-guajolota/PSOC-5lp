/*******************************************************************************
* File Name: STEPO_MOTOR_driver.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_STEPO_MOTOR_driver_H) /* CY_CONTROL_REG_STEPO_MOTOR_driver_H */
#define CY_CONTROL_REG_STEPO_MOTOR_driver_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} STEPO_MOTOR_driver_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    STEPO_MOTOR_driver_Write(uint8 control) ;
uint8   STEPO_MOTOR_driver_Read(void) ;

void STEPO_MOTOR_driver_SaveConfig(void) ;
void STEPO_MOTOR_driver_RestoreConfig(void) ;
void STEPO_MOTOR_driver_Sleep(void) ; 
void STEPO_MOTOR_driver_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define STEPO_MOTOR_driver_Control        (* (reg8 *) STEPO_MOTOR_driver_Sync_ctrl_reg__CONTROL_REG )
#define STEPO_MOTOR_driver_Control_PTR    (  (reg8 *) STEPO_MOTOR_driver_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_STEPO_MOTOR_driver_H */


/* [] END OF FILE */
