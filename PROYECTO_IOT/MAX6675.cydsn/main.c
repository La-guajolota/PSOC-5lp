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
    uint16_t temp,error;//Variable alamacena la temperatura 
    
    char lec[16];//Buffer a mostrar en pantalla
    
    for(;;)
    {
        //SENSAMOS 
        CyDelay(250);
        error = MAX_INIT();
        temp = sens();
        
        if (error == 0){
            //Mostramos temp si no hay errror de comunicacion
            LCD_Position(0,0);
            LCD_PrintString("TEMPERATURA");
            LCD_Position(1,0);
            LCD_PrintNumber(temp);
            sprintf(lec,"%d\n\r",temp);
            UART_PutString(lec);
        }else{
            //MOSTRAMOS ERROR 
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("ERRORES:");
            LCD_Position(1,0);
            LCD_PrintHex8(error);
            CyDelay(3000);
        }
        
    }
}


