/*******************************************************************************
* File Name: LED_Drive.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values and API definition for the
*  LED Driver Component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_LED_Driver_LED_Drive_H)
#define CY_LED_Driver_LED_Drive_H


/***************************************
*   Conditional Compilation Parameters
***************************************/
#define LED_Drive_BRIGHTNESS_EN                (0u)
#define LED_Drive_COM_DRIVE                    (1u)
#define LED_Drive_SEG_DRIVE                    (1u)
#define LED_Drive_NUM_COM                      (4u)
#define LED_Drive_NUM_SEG                      (8u)
#define LED_Drive_TWO_NUM_COM                  ((uint8)((uint8)LED_Drive_NUM_COM << 1u))

/* Error message for removed commons control register through optimization */
#ifdef LED_Drive_Com_Driver_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the commons terminal to be connected to pins.
#endif /* LED_Drive_Com_Driver_Sync_ctrl_reg__REMOVED */

/* Error message for removed segments control registers through optimization */
#if defined LED_Drive_Seg_Driver_L_Sync_ctrl_reg__REMOVED || \
defined LED_Drive_Seg_Driver_M_Sync_ctrl_reg__REMOVED || \
defined LED_Drive_Seg_Driver_H_Sync_ctrl_reg__REMOVED
    #error LED_Driver_v1_10 requires all the signals from the segments terminal to be connected to pins.
#endif /* LED_Drive_Seg_Driver_L_Sync_ctrl_reg__REMOVED */


/***************************************
*   Header files
***************************************/
#include <LED_Drive_Com_Driver.h>
#include <LED_Drive_Seg_Driver_L.h>
#if (LED_Drive_NUM_SEG > 8u)
    #include <LED_Drive_Seg_Driver_M.h>
#endif /* Segment_M control register */
#if (LED_Drive_NUM_SEG > 16u)
    #include <LED_Drive_Seg_Driver_H.h>
#endif /* Segment_H control register */

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#ifndef CY_PSOC5A
    #error Component LED_Driver_v1_10 requires cy_boot v3.0 or later
#endif /* CY_PSOC5A */


/***************************************
*        Structure Definitions
***************************************/
typedef struct
{
    uint8 ledEnableState;
    /* Backup the segment values when going to sleep. (Stop() clears the buffers) */
    uint8 segLBackup[LED_Drive_NUM_COM];
    #if (LED_Drive_NUM_SEG > 8u) 
        uint8 segMBackup[LED_Drive_NUM_COM];
    #endif /* (LED_Drive_NUM_SEG > 8u) */
    #if (LED_Drive_NUM_SEG > 16u) 
        uint8 segHBackup[LED_Drive_NUM_COM];
    #endif /* (LED_Drive_NUM_SEG > 16u) */
}LED_Drive_backupStruct;


/***************************************
*        Function Prototypes
***************************************/
void LED_Drive_Init(void)                       ;
void LED_Drive_Enable(void)                     ;
void LED_Drive_Start(void)                      ;
void LED_Drive_Stop(void)                       ;
void LED_Drive_SetDisplayRAM(uint8 value, uint8 position) 
                                                        ;
void LED_Drive_SetRC(uint8 row, uint8 column)    ;
void LED_Drive_ClearRC(uint8 row, uint8 column)  ;
void LED_Drive_ToggleRC(uint8 row, uint8 column) ;
uint8 LED_Drive_GetRC(uint8 row, uint8 column)   ;
void LED_Drive_ClearDisplay(uint8 position)      ;
void LED_Drive_ClearDisplayAll(void)             ;
void LED_Drive_Write7SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Drive_Write7SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Drive_WriteString7Seg(char8 const character[], uint8 position)
                                                        ;
void LED_Drive_PutChar7Seg(char8 character , uint8 position)
                                                        ;
void LED_Drive_Write7SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void LED_Drive_Write7SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void LED_Drive_Write14SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Drive_Write14SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Drive_WriteString14Seg(char8 const character[], uint8 position)
                                                        ;
void LED_Drive_PutChar14Seg(char8 character , uint8 position)
                                                        ;
void LED_Drive_Write14SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void LED_Drive_Write14SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void LED_Drive_Write16SegNumberDec(int32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Drive_Write16SegNumberHex(uint32 number, uint8 position, uint8 digits, uint8 alignment)
                                                        ;
void LED_Drive_WriteString16Seg(char8 const character[], uint8 position)
                                                        ;
void LED_Drive_PutChar16Seg(char8 character , uint8 position)
                                                        ;
void LED_Drive_Write16SegDigitDec(uint8 digit, uint8 position)
                                                        ;
void LED_Drive_Write16SegDigitHex(uint8 digit, uint8 position)
                                                        ;
void LED_Drive_PutDecimalPoint(uint8 dp, uint8 position)
                                                        ;
uint8 LED_Drive_GetDecimalPoint(uint8 position)  ;
uint8 LED_Drive_EncodeNumber7Seg(uint8 number)   ;
uint8 LED_Drive_EncodeChar7Seg(char8 input)      ;
uint16 LED_Drive_EncodeNumber14Seg(uint8 number) ;
uint16 LED_Drive_EncodeChar14Seg(char8 input)    ;
uint16 LED_Drive_EncodeNumber16Seg(uint8 number) ;
uint16 LED_Drive_EncodeChar16Seg(char8 input)    ;
void LED_Drive_SetBrightness(uint8 bright, uint8 position)
                                                        ;
uint8 LED_Drive_GetBrightness(uint8 position)    ;
void LED_Drive_Sleep(void)                       ;
void LED_Drive_Wakeup(void)                      ;


/***************************************
*           Global Variables
***************************************/
extern uint8 LED_Drive_initVar;
extern uint8 LED_Drive_enableVar;

/* Buffers used to hold the display(segment) values to be transferred to the control registers */
extern uint8 LED_Drive_segLBuffer[LED_Drive_NUM_COM];
#if (LED_Drive_NUM_SEG > 8u) 
    extern uint8 LED_Drive_segMBuffer[LED_Drive_NUM_COM];
#endif /* (LED_Drive_NUM_SEG > 8u) */
#if (LED_Drive_NUM_SEG > 16u) 
    extern uint8 LED_Drive_segHBuffer[LED_Drive_NUM_COM];
#endif /* (LED_Drive_NUM_SEG > 16u) */


/***************************************
*           API Constants
***************************************/

/* Related to conditional compilation */
#define LED_Drive_HIGH                   (0x01u)
#define LED_Drive_ENABLED                (0x01u)

/* Number of DMA channels */
#if (LED_Drive_BRIGHTNESS_EN == LED_Drive_ENABLED)
    #define LED_Drive_CHANNEL_LIMIT      (0x03u)
#else
    #define LED_Drive_CHANNEL_LIMIT      (0x02u)
#endif /* (LED_Drive_BRIGHTNESS_EN == LED_Drive_ENABLED) */

/* Defines related to sign extraction for number displays */
#define LED_Drive_SIGNED                 (0x01u)
#define LED_Drive_UNSIGNED               (0x00u)
#define LED_Drive_ZERO_NEG               ((int32)0x00000000)

/* Brightness control defines */
#define LED_Drive_INIT_BRIGHT            (0xFFu)

/* Segment display defines */
#if(LED_Drive_SEG_DRIVE == LED_Drive_HIGH)
    #define LED_Drive_CLEAR              (0x00u)
    #define LED_Drive_CLEAR_16           ((uint16)0x0000u)
    #define LED_Drive_ZERO_7CHAR         (0x3Fu)
    #define LED_Drive_ZERO_14CHAR        ((uint16)0x243Fu)
    #define LED_Drive_ZERO_16CHAR        ((uint16)0x90FFu)
#else
    #define LED_Drive_CLEAR              (0xFFu)
    #define LED_Drive_CLEAR_16           ((uint16)0xFFFFu)
    #define LED_Drive_ZERO_7CHAR         (0xC0u)
    #define LED_Drive_ZERO_14CHAR        ((uint16)0xDBC0u)
    #define LED_Drive_ZERO_16CHAR        ((uint16)0x6F00u)
#endif /* (LED_Drive_SEG_DRIVE == LED_Drive_HIGH) */

/* Shifts and 4-bit operation mask */
#define LED_Drive_SHIFT_NIBBLE           (0x04u)
#define LED_Drive_NIBBLE_MASK            (0x0Fu)
#define LED_Drive_SHIFT_BYTE             (0x08u)

/* ASCII table access defines */
#define LED_Drive_SEG_ASCII_OFFSET       (0x02u)
#define LED_Drive_SEG_ASCII_LIM_HI       (0x08u)
#define LED_Drive_SEG_ASCII_LIM_LO       (0x01u)

/* Decimal point defines */
#define LED_Drive_DEC_POINT              (0x07u)
#define LED_Drive_DEC_POINT_MASK         (0x01u)
#if(LED_Drive_SEG_DRIVE == LED_Drive_HIGH)
    #define LED_Drive_DEC_POINT_VALUE    (0x80u)
#else
    #define LED_Drive_DEC_POINT_VALUE    (0x7Fu)
#endif /* (LED_Drive_SEG_DRIVE == LED_Drive_HIGH) */

/* 7-seg position to register mapping defines */
#define LED_Drive_SEG_REG_LOW            (0x00u)
#define LED_Drive_SEG_REG_MID            (0x01u)
#define LED_Drive_SEG_REG_HIGH           (0x02u)

/* Segment display alignment defines */
#define LED_Drive_RIGHT_ALIGN            (0x00u)
#define LED_Drive_LEFT_ALIGN             (0x01u)
#define LED_Drive_ZERO_PAD               (0x02u)


/***************************************
*           Registers
***************************************/
#define LED_Drive_CONTROL_REG_BASE       (CYDEV_PERIPH_BASE)
#define LED_Drive_SRAM_BASE              (CYDEV_SRAM_BASE)

#define LED_Drive_COM_CONTROL_PTR        (LED_Drive_Com_Driver_Control_PTR)
#define LED_Drive_SEG_L_CONTROL_PTR      (LED_Drive_Seg_Driver_L_Control_PTR)

#if (LED_Drive_NUM_SEG > 8u)
    #define LED_Drive_SEG_M_CONTROL_PTR  (LED_Drive_Seg_Driver_M_Control_PTR)
#endif /* (LED_Drive_NUM_SEG > 8u) */
#if (LED_Drive_NUM_SEG > 16u)
    #define LED_Drive_SEG_H_CONTROL_PTR  (LED_Drive_Seg_Driver_H_Control_PTR)
#endif /* (LED_Drive_NUM_SEG > 16u) */


/***************************************
*           UDB PWM Registers
***************************************/
/* Control register */
#define LED_Drive_CONTROL_REG            (*(reg8 *) LED_Drive_bLED_PWM_CtlReg__CONTROL_REG)
#define LED_Drive_CONTROL_PTR            ( (reg8 *) LED_Drive_bLED_PWM_CtlReg__CONTROL_REG)

/* Counter register */
#define LED_Drive_COUNTER_REG            (*(reg8 *) LED_Drive_bLED_PWM_PwmDP_u0__A1_REG)
#define LED_Drive_COUNTER_PTR            ((reg8 *) LED_Drive_bLED_PWM_PwmDP_u0__A1_REG)
/* Compare value buffer */
#define LED_Drive_COMPARE_REG            (*(reg8 *) LED_Drive_bLED_PWM_PwmDP_u0__D0_REG)
#define LED_Drive_COMPARE_PTR            ((reg8 *) LED_Drive_bLED_PWM_PwmDP_u0__D0_REG)


/***************************************
*          Register Constants
***************************************/
/* Control Register Enable/Disable. Also use for LED_Drive_enableVar */
#define LED_Drive_CTRL_ENABLE            (0x01u)
#define LED_Drive_CTRL_DISABLE           (0x00u)

#endif /* CY_LED_Driver_LED_Drive_H Header File */


/* [] END OF FILE */
