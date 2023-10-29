/* ========================================
Del sensor BME680, adquirir los valores de humedad, presión atmosférica, 
calidad del aire y temperatura ambiental e imprimirlos en el display LCD 16x2 
(polling de 1 segundo).
*/
//Librerias
#include <stdio.h>
#include "project.h"
#include <stdlib.h>
#include <string.h>
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
#include "bme680.h"

/* Variables*/
int8_t error = 0;
sdata_bme680 datos_bme680;
uint8_t datochu = 0;
uint8_t result = 0;
uint8_t address = 0x76;//

int main(void)
{
    CyGlobalIntEnable;
    
    //Inicializamos perifericos
    LCD_Start();
    LCD_ClearDisplay();
    LCD_Position(0,0);
    
    I2C_Start();
    
    //Inicializamos el BME con su configuraciones
    error = bme680_Start(&sensor_bme680);
    
    for(;;)
    {
        datos_bme680 = bme680_readData(&sensor_bme680);

        LCD_Position(0,0);
        LCD_PrintString("Temperatura:    ");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.temperature/100);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.temperature%100);
        LCD_PrintString("C               ");
        CyDelay(2000);
        
        LCD_Position(0,0);
        LCD_PrintString("Humedad:        ");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.humidity/1000);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.humidity%1000);
        LCD_PrintString("%               ");
        CyDelay(2000);
        
        LCD_Position(0,0);
        LCD_PrintString("Presion atmos:  ");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.pressure/100);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.pressure%100);
        LCD_PrintString("hPa             ");
        CyDelay(2000);
        
        LCD_Position(0,0);
        LCD_PrintString("Resistencia gas:");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.gas_resistance/1000);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.gas_resistance%1000);
        LCD_PrintString(" Kohm            ");
        CyDelay(2000);
        
        CyDelay(1000);
         
        // Buscador de direcciones I2C
        /*if(address <= 127) {
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

