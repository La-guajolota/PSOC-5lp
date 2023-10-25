#include "project.h"
#include "stdio.h"
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"//LCD
#include "max6675.h"

int main(void)
{
    CyGlobalIntEnable;
    UART_Start();
    UART_ClearTxBuffer();
    LCD_Start();
    SPIM_Start();
    
    //Variables
    uint16_t temp,error,R;//Variable alamacena la temperatura 
    
    char lec[16];//Buffer a mostrar en pantalla
    
    for(;;)
    {
        error = test();//Extraemos bits de testeo
        temp = sens();//sensamos
        R = raw();//lectrua en crudo
        
        //Mostramos temp si no hay errror de comunicacion
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString("TEMPERATURA");
        LCD_Position(1,0);
        LCD_PrintNumber(temp);
        sprintf(lec,"TEM: %d\n\r",temp);
        UART_PutString(lec);
        CyDelay(500);      
        
        //MOSTRAMOS ERROR 
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString("ERRORES:");
        LCD_Position(1,0);
        sprintf(lec,"ERROR: %d\n\r",error);
        UART_PutString(lec);
        LCD_PrintNumber(error);
        CyDelay(500);
        
        //MOSTRAMOS lectrura de la palabras del modulo 
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString("raw:");
        LCD_Position(1,0);
        sprintf(lec,"raw en hexa %x\n\r",R);
        UART_PutString(lec);
        LCD_PrintHex16(R);
        CyDelay(500);
        
    }
}


