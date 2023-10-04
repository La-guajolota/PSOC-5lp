/*******************************************************************************
* File Name: Segmentos_7seg.h  
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

#if !defined(CY_CONTROL_REG_Segmentos_7seg_H) /* CY_CONTROL_REG_Segmentos_7seg_H */
#define CY_CONTROL_REG_Segmentos_7seg_H

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

} Segmentos_7seg_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Segmentos_7seg_Write(uint8 control) ;
uint8   Segmentos_7seg_Read(void) ;

void Segmentos_7seg_SaveConfig(void) ;
void Segmentos_7seg_RestoreConfig(void) ;
void Segmentos_7seg_Sleep(void) ; 
void Segmentos_7seg_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Segmentos_7seg_Control        (* (reg8 *) Segmentos_7seg_Sync_ctrl_reg__CONTROL_REG )
#define Segmentos_7seg_Control_PTR    (  (reg8 *) Segmentos_7seg_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Segmentos_7seg_H */


/* [] END OF FILE */
