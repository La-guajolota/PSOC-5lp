#include "project.h"
#include "stdio.h"

#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "MPU6050.h"

uint8_t address = 0x68; //Direccion I2C del sensor
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
    
    //Creamos instancia del sensor
    struct MPU6050 acelerometro;
    MPU6050_Start(&acelerometro);
    MPU6050_CONFIG_ACCEL(&acelerometro,2);//Configuracion del sensor -+4g
    
    
    int16 Acc_X,Acc_Y,Acc_Z; //Valores de acelerometro ejex X y Y
    char buffer_tx[16];
    for(;;)
    {
        //Leemos sensor
        MPU6050_REGISTROS(&acelerometro);
        
        Acc_X = acelerometro.DATA_SENSADO.ACCEL_XOUT>>4;
        Acc_Y = acelerometro.DATA_SENSADO.ACCEL_YOUT>>4;
        Acc_Z = acelerometro.DATA_SENSADO.ACCEL_ZOUT>>4;
        
        //Imprimimos resultado
        sprintf(buffer_tx,"X%dxZ%dz\n",Acc_X,Acc_Z);
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
