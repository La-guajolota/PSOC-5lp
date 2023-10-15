/*******************************************************************************
* File Name: UART_PC.h
* Version 2.50
*
* Description:
*  Contains the function prototypes and constants available to the UART
*  user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_UART_UART_PC_H)
#define CY_UART_UART_PC_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/***************************************
* Conditional Compilation Parameters
***************************************/

#define UART_PC_RX_ENABLED                     (1u)
#define UART_PC_TX_ENABLED                     (1u)
#define UART_PC_HD_ENABLED                     (0u)
#define UART_PC_RX_INTERRUPT_ENABLED           (1u)
#define UART_PC_TX_INTERRUPT_ENABLED           (1u)
#define UART_PC_INTERNAL_CLOCK_USED            (1u)
#define UART_PC_RXHW_ADDRESS_ENABLED           (0u)
#define UART_PC_OVER_SAMPLE_COUNT              (8u)
#define UART_PC_PARITY_TYPE                    (0u)
#define UART_PC_PARITY_TYPE_SW                 (0u)
#define UART_PC_BREAK_DETECT                   (0u)
#define UART_PC_BREAK_BITS_TX                  (13u)
#define UART_PC_BREAK_BITS_RX                  (13u)
#define UART_PC_TXCLKGEN_DP                    (1u)
#define UART_PC_USE23POLLING                   (1u)
#define UART_PC_FLOW_CONTROL                   (0u)
#define UART_PC_CLK_FREQ                       (0u)
#define UART_PC_TX_BUFFER_SIZE                 (64u)
#define UART_PC_RX_BUFFER_SIZE                 (64u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#if defined(UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG)
    #define UART_PC_CONTROL_REG_REMOVED            (0u)
#else
    #define UART_PC_CONTROL_REG_REMOVED            (1u)
#endif /* End UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Structure Definition
***************************************/

/* Sleep Mode API Support */
typedef struct UART_PC_backupStruct_
{
    uint8 enableState;

    #if(UART_PC_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End UART_PC_CONTROL_REG_REMOVED */

} UART_PC_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void UART_PC_Start(void) ;
void UART_PC_Stop(void) ;
uint8 UART_PC_ReadControlRegister(void) ;
void UART_PC_WriteControlRegister(uint8 control) ;

void UART_PC_Init(void) ;
void UART_PC_Enable(void) ;
void UART_PC_SaveConfig(void) ;
void UART_PC_RestoreConfig(void) ;
void UART_PC_Sleep(void) ;
void UART_PC_Wakeup(void) ;

/* Only if RX is enabled */
#if( (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) )

    #if (UART_PC_RX_INTERRUPT_ENABLED)
        #define UART_PC_EnableRxInt()  CyIntEnable (UART_PC_RX_VECT_NUM)
        #define UART_PC_DisableRxInt() CyIntDisable(UART_PC_RX_VECT_NUM)
        CY_ISR_PROTO(UART_PC_RXISR);
    #endif /* UART_PC_RX_INTERRUPT_ENABLED */

    void UART_PC_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void UART_PC_SetRxAddress1(uint8 address) ;
    void UART_PC_SetRxAddress2(uint8 address) ;

    void  UART_PC_SetRxInterruptMode(uint8 intSrc) ;
    uint8 UART_PC_ReadRxData(void) ;
    uint8 UART_PC_ReadRxStatus(void) ;
    uint8 UART_PC_GetChar(void) ;
    uint16 UART_PC_GetByte(void) ;
    uint8 UART_PC_GetRxBufferSize(void)
                                                            ;
    void UART_PC_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define UART_PC_GetRxInterruptSource   UART_PC_ReadRxStatus

#endif /* End (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) */

/* Only if TX is enabled */
#if(UART_PC_TX_ENABLED || UART_PC_HD_ENABLED)

    #if(UART_PC_TX_INTERRUPT_ENABLED)
        #define UART_PC_EnableTxInt()  CyIntEnable (UART_PC_TX_VECT_NUM)
        #define UART_PC_DisableTxInt() CyIntDisable(UART_PC_TX_VECT_NUM)
        #define UART_PC_SetPendingTxInt() CyIntSetPending(UART_PC_TX_VECT_NUM)
        #define UART_PC_ClearPendingTxInt() CyIntClearPending(UART_PC_TX_VECT_NUM)
        CY_ISR_PROTO(UART_PC_TXISR);
    #endif /* UART_PC_TX_INTERRUPT_ENABLED */

    void UART_PC_SetTxInterruptMode(uint8 intSrc) ;
    void UART_PC_WriteTxData(uint8 txDataByte) ;
    uint8 UART_PC_ReadTxStatus(void) ;
    void UART_PC_PutChar(uint8 txDataByte) ;
    void UART_PC_PutString(const char8 string[]) ;
    void UART_PC_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void UART_PC_PutCRLF(uint8 txDataByte) ;
    void UART_PC_ClearTxBuffer(void) ;
    void UART_PC_SetTxAddressMode(uint8 addressMode) ;
    void UART_PC_SendBreak(uint8 retMode) ;
    uint8 UART_PC_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define UART_PC_PutStringConst         UART_PC_PutString
    #define UART_PC_PutArrayConst          UART_PC_PutArray
    #define UART_PC_GetTxInterruptSource   UART_PC_ReadTxStatus

#endif /* End UART_PC_TX_ENABLED || UART_PC_HD_ENABLED */

#if(UART_PC_HD_ENABLED)
    void UART_PC_LoadRxConfig(void) ;
    void UART_PC_LoadTxConfig(void) ;
#endif /* End UART_PC_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_PC) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    UART_PC_CyBtldrCommStart(void) CYSMALL ;
    void    UART_PC_CyBtldrCommStop(void) CYSMALL ;
    void    UART_PC_CyBtldrCommReset(void) CYSMALL ;
    cystatus UART_PC_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus UART_PC_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_PC)
        #define CyBtldrCommStart    UART_PC_CyBtldrCommStart
        #define CyBtldrCommStop     UART_PC_CyBtldrCommStop
        #define CyBtldrCommReset    UART_PC_CyBtldrCommReset
        #define CyBtldrCommWrite    UART_PC_CyBtldrCommWrite
        #define CyBtldrCommRead     UART_PC_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_PC) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define UART_PC_BYTE2BYTE_TIME_OUT (25u)
    #define UART_PC_PACKET_EOP         (0x17u) /* End of packet defined by bootloader */
    #define UART_PC_WAIT_EOP_DELAY     (5u)    /* Additional 5ms to wait for End of packet */
    #define UART_PC_BL_CHK_DELAY_MS    (1u)    /* Time Out quantity equal 1mS */

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define UART_PC_SET_SPACE      (0x00u)
#define UART_PC_SET_MARK       (0x01u)

/* Status Register definitions */
#if( (UART_PC_TX_ENABLED) || (UART_PC_HD_ENABLED) )
    #if(UART_PC_TX_INTERRUPT_ENABLED)
        #define UART_PC_TX_VECT_NUM            (uint8)UART_PC_TXInternalInterrupt__INTC_NUMBER
        #define UART_PC_TX_PRIOR_NUM           (uint8)UART_PC_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* UART_PC_TX_INTERRUPT_ENABLED */

    #define UART_PC_TX_STS_COMPLETE_SHIFT          (0x00u)
    #define UART_PC_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
    #define UART_PC_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #if(UART_PC_TX_ENABLED)
        #define UART_PC_TX_STS_FIFO_FULL_SHIFT     (0x02u)
    #else /* (UART_PC_HD_ENABLED) */
        #define UART_PC_TX_STS_FIFO_FULL_SHIFT     (0x05u)  /* Needs MD=0 */
    #endif /* (UART_PC_TX_ENABLED) */

    #define UART_PC_TX_STS_COMPLETE            (uint8)(0x01u << UART_PC_TX_STS_COMPLETE_SHIFT)
    #define UART_PC_TX_STS_FIFO_EMPTY          (uint8)(0x01u << UART_PC_TX_STS_FIFO_EMPTY_SHIFT)
    #define UART_PC_TX_STS_FIFO_FULL           (uint8)(0x01u << UART_PC_TX_STS_FIFO_FULL_SHIFT)
    #define UART_PC_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << UART_PC_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (UART_PC_TX_ENABLED) || (UART_PC_HD_ENABLED)*/

#if( (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) )
    #if(UART_PC_RX_INTERRUPT_ENABLED)
        #define UART_PC_RX_VECT_NUM            (uint8)UART_PC_RXInternalInterrupt__INTC_NUMBER
        #define UART_PC_RX_PRIOR_NUM           (uint8)UART_PC_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* UART_PC_RX_INTERRUPT_ENABLED */
    #define UART_PC_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define UART_PC_RX_STS_BREAK_SHIFT             (0x01u)
    #define UART_PC_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define UART_PC_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define UART_PC_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define UART_PC_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define UART_PC_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define UART_PC_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define UART_PC_RX_STS_MRKSPC           (uint8)(0x01u << UART_PC_RX_STS_MRKSPC_SHIFT)
    #define UART_PC_RX_STS_BREAK            (uint8)(0x01u << UART_PC_RX_STS_BREAK_SHIFT)
    #define UART_PC_RX_STS_PAR_ERROR        (uint8)(0x01u << UART_PC_RX_STS_PAR_ERROR_SHIFT)
    #define UART_PC_RX_STS_STOP_ERROR       (uint8)(0x01u << UART_PC_RX_STS_STOP_ERROR_SHIFT)
    #define UART_PC_RX_STS_OVERRUN          (uint8)(0x01u << UART_PC_RX_STS_OVERRUN_SHIFT)
    #define UART_PC_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << UART_PC_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define UART_PC_RX_STS_ADDR_MATCH       (uint8)(0x01u << UART_PC_RX_STS_ADDR_MATCH_SHIFT)
    #define UART_PC_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << UART_PC_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define UART_PC_RX_HW_MASK                     (0x7Fu)
#endif /* End (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) */

/* Control Register definitions */
#define UART_PC_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define UART_PC_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define UART_PC_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define UART_PC_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define UART_PC_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define UART_PC_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define UART_PC_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define UART_PC_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define UART_PC_CTRL_HD_SEND               (uint8)(0x01u << UART_PC_CTRL_HD_SEND_SHIFT)
#define UART_PC_CTRL_HD_SEND_BREAK         (uint8)(0x01u << UART_PC_CTRL_HD_SEND_BREAK_SHIFT)
#define UART_PC_CTRL_MARK                  (uint8)(0x01u << UART_PC_CTRL_MARK_SHIFT)
#define UART_PC_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << UART_PC_CTRL_PARITY_TYPE0_SHIFT)
#define UART_PC_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << UART_PC_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define UART_PC_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define UART_PC_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define UART_PC_SEND_BREAK                         (0x00u)
#define UART_PC_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define UART_PC_REINIT                             (0x02u)
#define UART_PC_SEND_WAIT_REINIT                   (0x03u)

#define UART_PC_OVER_SAMPLE_8                      (8u)
#define UART_PC_OVER_SAMPLE_16                     (16u)

#define UART_PC_BIT_CENTER                         (UART_PC_OVER_SAMPLE_COUNT - 2u)

#define UART_PC_FIFO_LENGTH                        (4u)
#define UART_PC_NUMBER_OF_START_BIT                (1u)
#define UART_PC_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation */
#define UART_PC_TXBITCTR_BREAKBITS8X   ((UART_PC_BREAK_BITS_TX * UART_PC_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation */
#define UART_PC_TXBITCTR_BREAKBITS ((UART_PC_BREAK_BITS_TX * UART_PC_OVER_SAMPLE_COUNT) - 1u)

#define UART_PC_HALF_BIT_COUNT   \
                            (((UART_PC_OVER_SAMPLE_COUNT / 2u) + (UART_PC_USE23POLLING * 1u)) - 2u)
#if (UART_PC_OVER_SAMPLE_COUNT == UART_PC_OVER_SAMPLE_8)
    #define UART_PC_HD_TXBITCTR_INIT   (((UART_PC_BREAK_BITS_TX + \
                            UART_PC_NUMBER_OF_START_BIT) * UART_PC_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define UART_PC_RXBITCTR_INIT  ((((UART_PC_BREAK_BITS_RX + UART_PC_NUMBER_OF_START_BIT) \
                            * UART_PC_OVER_SAMPLE_COUNT) + UART_PC_HALF_BIT_COUNT) - 1u)

#else /* UART_PC_OVER_SAMPLE_COUNT == UART_PC_OVER_SAMPLE_16 */
    #define UART_PC_HD_TXBITCTR_INIT   ((8u * UART_PC_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount = 16 */
    #define UART_PC_RXBITCTR_INIT      (((7u * UART_PC_OVER_SAMPLE_COUNT) - 1u) + \
                                                      UART_PC_HALF_BIT_COUNT)
#endif /* End UART_PC_OVER_SAMPLE_COUNT */

#define UART_PC_HD_RXBITCTR_INIT                   UART_PC_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 UART_PC_initVar;
#if (UART_PC_TX_INTERRUPT_ENABLED && UART_PC_TX_ENABLED)
    extern volatile uint8 UART_PC_txBuffer[UART_PC_TX_BUFFER_SIZE];
    extern volatile uint8 UART_PC_txBufferRead;
    extern uint8 UART_PC_txBufferWrite;
#endif /* (UART_PC_TX_INTERRUPT_ENABLED && UART_PC_TX_ENABLED) */
#if (UART_PC_RX_INTERRUPT_ENABLED && (UART_PC_RX_ENABLED || UART_PC_HD_ENABLED))
    extern uint8 UART_PC_errorStatus;
    extern volatile uint8 UART_PC_rxBuffer[UART_PC_RX_BUFFER_SIZE];
    extern volatile uint8 UART_PC_rxBufferRead;
    extern volatile uint8 UART_PC_rxBufferWrite;
    extern volatile uint8 UART_PC_rxBufferLoopDetect;
    extern volatile uint8 UART_PC_rxBufferOverflow;
    #if (UART_PC_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 UART_PC_rxAddressMode;
        extern volatile uint8 UART_PC_rxAddressDetected;
    #endif /* (UART_PC_RXHW_ADDRESS_ENABLED) */
#endif /* (UART_PC_RX_INTERRUPT_ENABLED && (UART_PC_RX_ENABLED || UART_PC_HD_ENABLED)) */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define UART_PC__B_UART__AM_SW_BYTE_BYTE 1
#define UART_PC__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define UART_PC__B_UART__AM_HW_BYTE_BY_BYTE 3
#define UART_PC__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define UART_PC__B_UART__AM_NONE 0

#define UART_PC__B_UART__NONE_REVB 0
#define UART_PC__B_UART__EVEN_REVB 1
#define UART_PC__B_UART__ODD_REVB 2
#define UART_PC__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define UART_PC_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define UART_PC_NUMBER_OF_STOP_BITS    (1u)

#if (UART_PC_RXHW_ADDRESS_ENABLED)
    #define UART_PC_RX_ADDRESS_MODE    (0u)
    #define UART_PC_RX_HW_ADDRESS1     (0u)
    #define UART_PC_RX_HW_ADDRESS2     (0u)
#endif /* (UART_PC_RXHW_ADDRESS_ENABLED) */

#define UART_PC_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << UART_PC_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << UART_PC_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << UART_PC_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << UART_PC_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << UART_PC_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << UART_PC_RX_STS_BREAK_SHIFT) \
                                        | (0 << UART_PC_RX_STS_OVERRUN_SHIFT))

#define UART_PC_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << UART_PC_TX_STS_COMPLETE_SHIFT) \
                                        | (1 << UART_PC_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << UART_PC_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << UART_PC_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_PC_CONTROL_REG \
                            (* (reg8 *) UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define UART_PC_CONTROL_PTR \
                            (  (reg8 *) UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_PC_TX_ENABLED)
    #define UART_PC_TXDATA_REG          (* (reg8 *) UART_PC_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_PC_TXDATA_PTR          (  (reg8 *) UART_PC_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_PC_TXDATA_AUX_CTL_REG  (* (reg8 *) UART_PC_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_PC_TXDATA_AUX_CTL_PTR  (  (reg8 *) UART_PC_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_PC_TXSTATUS_REG        (* (reg8 *) UART_PC_BUART_sTX_TxSts__STATUS_REG)
    #define UART_PC_TXSTATUS_PTR        (  (reg8 *) UART_PC_BUART_sTX_TxSts__STATUS_REG)
    #define UART_PC_TXSTATUS_MASK_REG   (* (reg8 *) UART_PC_BUART_sTX_TxSts__MASK_REG)
    #define UART_PC_TXSTATUS_MASK_PTR   (  (reg8 *) UART_PC_BUART_sTX_TxSts__MASK_REG)
    #define UART_PC_TXSTATUS_ACTL_REG   (* (reg8 *) UART_PC_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define UART_PC_TXSTATUS_ACTL_PTR   (  (reg8 *) UART_PC_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(UART_PC_TXCLKGEN_DP)
        #define UART_PC_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_PC_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_PC_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define UART_PC_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define UART_PC_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_PC_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_PC_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_PC_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_PC_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define UART_PC_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) UART_PC_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* UART_PC_TXCLKGEN_DP */

#endif /* End UART_PC_TX_ENABLED */

#if(UART_PC_HD_ENABLED)

    #define UART_PC_TXDATA_REG             (* (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_PC_TXDATA_PTR             (  (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_PC_TXDATA_AUX_CTL_REG     (* (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define UART_PC_TXDATA_AUX_CTL_PTR     (  (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_PC_TXSTATUS_REG           (* (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_REG )
    #define UART_PC_TXSTATUS_PTR           (  (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_REG )
    #define UART_PC_TXSTATUS_MASK_REG      (* (reg8 *) UART_PC_BUART_sRX_RxSts__MASK_REG )
    #define UART_PC_TXSTATUS_MASK_PTR      (  (reg8 *) UART_PC_BUART_sRX_RxSts__MASK_REG )
    #define UART_PC_TXSTATUS_ACTL_REG      (* (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_PC_TXSTATUS_ACTL_PTR      (  (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End UART_PC_HD_ENABLED */

#if( (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) )
    #define UART_PC_RXDATA_REG             (* (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_PC_RXDATA_PTR             (  (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_PC_RXADDRESS1_REG         (* (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_PC_RXADDRESS1_PTR         (  (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_PC_RXADDRESS2_REG         (* (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_PC_RXADDRESS2_PTR         (  (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_PC_RXDATA_AUX_CTL_REG     (* (reg8 *) UART_PC_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_PC_RXBITCTR_PERIOD_REG    (* (reg8 *) UART_PC_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_PC_RXBITCTR_PERIOD_PTR    (  (reg8 *) UART_PC_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_PC_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_PC_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_PC_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_PC_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_PC_RXBITCTR_COUNTER_REG   (* (reg8 *) UART_PC_BUART_sRX_RxBitCounter__COUNT_REG )
    #define UART_PC_RXBITCTR_COUNTER_PTR   (  (reg8 *) UART_PC_BUART_sRX_RxBitCounter__COUNT_REG )

    #define UART_PC_RXSTATUS_REG           (* (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_REG )
    #define UART_PC_RXSTATUS_PTR           (  (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_REG )
    #define UART_PC_RXSTATUS_MASK_REG      (* (reg8 *) UART_PC_BUART_sRX_RxSts__MASK_REG )
    #define UART_PC_RXSTATUS_MASK_PTR      (  (reg8 *) UART_PC_BUART_sRX_RxSts__MASK_REG )
    #define UART_PC_RXSTATUS_ACTL_REG      (* (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_PC_RXSTATUS_ACTL_PTR      (  (reg8 *) UART_PC_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) */

#if(UART_PC_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define UART_PC_INTCLOCK_CLKEN_REG     (* (reg8 *) UART_PC_IntClock__PM_ACT_CFG)
    #define UART_PC_INTCLOCK_CLKEN_PTR     (  (reg8 *) UART_PC_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define UART_PC_INTCLOCK_CLKEN_MASK    UART_PC_IntClock__PM_ACT_MSK
#endif /* End UART_PC_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(UART_PC_TX_ENABLED)
    #define UART_PC_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End UART_PC_TX_ENABLED */

#if(UART_PC_HD_ENABLED)
    #define UART_PC_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End UART_PC_HD_ENABLED */

#if( (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) )
    #define UART_PC_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

/* UART v2_40 obsolete definitions */
#define UART_PC_WAIT_1_MS      UART_PC_BL_CHK_DELAY_MS   

#define UART_PC_TXBUFFERSIZE   UART_PC_TX_BUFFER_SIZE
#define UART_PC_RXBUFFERSIZE   UART_PC_RX_BUFFER_SIZE

#if (UART_PC_RXHW_ADDRESS_ENABLED)
    #define UART_PC_RXADDRESSMODE  UART_PC_RX_ADDRESS_MODE
    #define UART_PC_RXHWADDRESS1   UART_PC_RX_HW_ADDRESS1
    #define UART_PC_RXHWADDRESS2   UART_PC_RX_HW_ADDRESS2
    /* Backward compatible define */
    #define UART_PC_RXAddressMode  UART_PC_RXADDRESSMODE
#endif /* (UART_PC_RXHW_ADDRESS_ENABLED) */

/* UART v2_30 obsolete definitions */
#define UART_PC_initvar                    UART_PC_initVar

#define UART_PC_RX_Enabled                 UART_PC_RX_ENABLED
#define UART_PC_TX_Enabled                 UART_PC_TX_ENABLED
#define UART_PC_HD_Enabled                 UART_PC_HD_ENABLED
#define UART_PC_RX_IntInterruptEnabled     UART_PC_RX_INTERRUPT_ENABLED
#define UART_PC_TX_IntInterruptEnabled     UART_PC_TX_INTERRUPT_ENABLED
#define UART_PC_InternalClockUsed          UART_PC_INTERNAL_CLOCK_USED
#define UART_PC_RXHW_Address_Enabled       UART_PC_RXHW_ADDRESS_ENABLED
#define UART_PC_OverSampleCount            UART_PC_OVER_SAMPLE_COUNT
#define UART_PC_ParityType                 UART_PC_PARITY_TYPE

#if( UART_PC_TX_ENABLED && (UART_PC_TXBUFFERSIZE > UART_PC_FIFO_LENGTH))
    #define UART_PC_TXBUFFER               UART_PC_txBuffer
    #define UART_PC_TXBUFFERREAD           UART_PC_txBufferRead
    #define UART_PC_TXBUFFERWRITE          UART_PC_txBufferWrite
#endif /* End UART_PC_TX_ENABLED */
#if( ( UART_PC_RX_ENABLED || UART_PC_HD_ENABLED ) && \
     (UART_PC_RXBUFFERSIZE > UART_PC_FIFO_LENGTH) )
    #define UART_PC_RXBUFFER               UART_PC_rxBuffer
    #define UART_PC_RXBUFFERREAD           UART_PC_rxBufferRead
    #define UART_PC_RXBUFFERWRITE          UART_PC_rxBufferWrite
    #define UART_PC_RXBUFFERLOOPDETECT     UART_PC_rxBufferLoopDetect
    #define UART_PC_RXBUFFER_OVERFLOW      UART_PC_rxBufferOverflow
#endif /* End UART_PC_RX_ENABLED */

#ifdef UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_PC_CONTROL                UART_PC_CONTROL_REG
#endif /* End UART_PC_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_PC_TX_ENABLED)
    #define UART_PC_TXDATA                 UART_PC_TXDATA_REG
    #define UART_PC_TXSTATUS               UART_PC_TXSTATUS_REG
    #define UART_PC_TXSTATUS_MASK          UART_PC_TXSTATUS_MASK_REG
    #define UART_PC_TXSTATUS_ACTL          UART_PC_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(UART_PC_TXCLKGEN_DP)
        #define UART_PC_TXBITCLKGEN_CTR        UART_PC_TXBITCLKGEN_CTR_REG
        #define UART_PC_TXBITCLKTX_COMPLETE    UART_PC_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define UART_PC_TXBITCTR_PERIOD        UART_PC_TXBITCTR_PERIOD_REG
        #define UART_PC_TXBITCTR_CONTROL       UART_PC_TXBITCTR_CONTROL_REG
        #define UART_PC_TXBITCTR_COUNTER       UART_PC_TXBITCTR_COUNTER_REG
    #endif /* UART_PC_TXCLKGEN_DP */
#endif /* End UART_PC_TX_ENABLED */

#if(UART_PC_HD_ENABLED)
    #define UART_PC_TXDATA                 UART_PC_TXDATA_REG
    #define UART_PC_TXSTATUS               UART_PC_TXSTATUS_REG
    #define UART_PC_TXSTATUS_MASK          UART_PC_TXSTATUS_MASK_REG
    #define UART_PC_TXSTATUS_ACTL          UART_PC_TXSTATUS_ACTL_REG
#endif /* End UART_PC_HD_ENABLED */

#if( (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) )
    #define UART_PC_RXDATA                 UART_PC_RXDATA_REG
    #define UART_PC_RXADDRESS1             UART_PC_RXADDRESS1_REG
    #define UART_PC_RXADDRESS2             UART_PC_RXADDRESS2_REG
    #define UART_PC_RXBITCTR_PERIOD        UART_PC_RXBITCTR_PERIOD_REG
    #define UART_PC_RXBITCTR_CONTROL       UART_PC_RXBITCTR_CONTROL_REG
    #define UART_PC_RXBITCTR_COUNTER       UART_PC_RXBITCTR_COUNTER_REG
    #define UART_PC_RXSTATUS               UART_PC_RXSTATUS_REG
    #define UART_PC_RXSTATUS_MASK          UART_PC_RXSTATUS_MASK_REG
    #define UART_PC_RXSTATUS_ACTL          UART_PC_RXSTATUS_ACTL_REG
#endif /* End  (UART_PC_RX_ENABLED) || (UART_PC_HD_ENABLED) */

#if(UART_PC_INTERNAL_CLOCK_USED)
    #define UART_PC_INTCLOCK_CLKEN         UART_PC_INTCLOCK_CLKEN_REG
#endif /* End UART_PC_INTERNAL_CLOCK_USED */

#define UART_PC_WAIT_FOR_COMLETE_REINIT    UART_PC_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_UART_PC_H */


/* [] END OF FILE */
