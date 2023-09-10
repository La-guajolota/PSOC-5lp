/*******************************************************************************
* File Name: Led_indicadores.h  
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

#if !defined(CY_CONTROL_REG_Led_indicadores_H) /* CY_CONTROL_REG_Led_indicadores_H */
#define CY_CONTROL_REG_Led_indicadores_H

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

} Led_indicadores_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Led_indicadores_Write(uint8 control) ;
uint8   Led_indicadores_Read(void) ;

void Led_indicadores_SaveConfig(void) ;
void Led_indicadores_RestoreConfig(void) ;
void Led_indicadores_Sleep(void) ; 
void Led_indicadores_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Led_indicadores_Control        (* (reg8 *) Led_indicadores_Sync_ctrl_reg__CONTROL_REG )
#define Led_indicadores_Control_PTR    (  (reg8 *) Led_indicadores_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Led_indicadores_H */


/* [] END OF FILE */
