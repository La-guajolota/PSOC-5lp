#include "project.h"
#include "stdio.h"

#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "AS5048B.h"

uint8_t address = 0x41; //Direccion I2C del sensor
uint8_t result = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //Perifericos
    I2C_Start();
    UART_Start();
    UART_ClearTxBuffer();
    LCD_Start();
    LCD_ClearDisplay();
    LCD_Position(0,0);
    
    struct AS5048B Encoder;//Creamos instancia del sensor
    //AS5048B_Cero(&Encoder); //Seteamos el cero mecanico
    
    uint16 Angulo;
    char buffer_tx[16];
    for(;;)
    {
        //Leemos sensor
        AS5048B_REGISTROS(&Encoder);
            
        //Filtramos
        Angulo = (Encoder.registros.angulo_Hi << 6) | (Encoder.registros.angulo_Lo>>4);
        
        //Calculamos el angulo en grados
        Angulo = map(Angulo,0,16383,0,360);
        
        //Imprimimos resultado
        sprintf(buffer_tx,"Angulo: %d\n\r",Angulo);
        UART_PutString(buffer_tx);
        CyDelay(250);//Delay para no saturar el puerto
        
        // Buscador de direcciones I2C
        /*
        if(address <= 127) {
            result = I2C_MasterSendStart(address, I2C_WRITE_XFER_MODE);
            CyDelayUs(10);
            LCD_Position(0,9);
            LCD_PrintString("0x");
            LCD_PrintHex8(address);
            if(!result) {
                LCD_Position(1,0);
                LCD_PrintString("Found!");
                CyDelay(3000);
                LCD_Position(1,0);
                LCD_PrintString("      ");
            }
            result = I2C_MasterSendStop();
            CyDelay(10);
            address++;
        }
        else {
            address = 0;
        }*/
        
    }
}


