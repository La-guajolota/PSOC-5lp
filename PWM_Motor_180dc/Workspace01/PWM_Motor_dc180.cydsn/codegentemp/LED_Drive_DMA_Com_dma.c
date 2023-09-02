/***************************************************************************
* File Name: LED_Drive_DMA_Com_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <LED_Drive_DMA_Com_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* LED_Drive_DMA_Com__DRQ_CTL_REG
* 
* 
* LED_Drive_DMA_Com__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* LED_Drive_DMA_Com__NUMBEROF_TDS
* 
* Priority of this channel.
* LED_Drive_DMA_Com__PRIORITY
* 
* True if LED_Drive_DMA_Com_TERMIN_SEL is used.
* LED_Drive_DMA_Com__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* LED_Drive_DMA_Com__TERMIN_SEL
* 
* 
* True if LED_Drive_DMA_Com_TERMOUT0_SEL is used.
* LED_Drive_DMA_Com__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* LED_Drive_DMA_Com__TERMOUT0_SEL
* 
* 
* True if LED_Drive_DMA_Com_TERMOUT1_SEL is used.
* LED_Drive_DMA_Com__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* LED_Drive_DMA_Com__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of LED_Drive_DMA_Com dma channel */
uint8 LED_Drive_DMA_Com_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 LED_Drive_DMA_Com_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 LED_Drive_DMA_Com_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    LED_Drive_DMA_Com_DmaHandle = (uint8)LED_Drive_DMA_Com__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(LED_Drive_DMA_Com_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)LED_Drive_DMA_Com__TERMOUT0_SEL,
                                  (uint8)LED_Drive_DMA_Com__TERMOUT1_SEL,
                                  (uint8)LED_Drive_DMA_Com__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(LED_Drive_DMA_Com_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(LED_Drive_DMA_Com_DmaHandle, (uint8)LED_Drive_DMA_Com__PRIORITY);
    
    return LED_Drive_DMA_Com_DmaHandle;
}

/*********************************************************************
* Function Name: void LED_Drive_DMA_Com_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with LED_Drive_DMA_Com.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void LED_Drive_DMA_Com_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(LED_Drive_DMA_Com_DmaHandle);
}

