/* ========================================
Del sensor BME680, adquirir los valores de humedad, presión atmosférica, 
calidad del aire y temperatura ambiental e imprimirlos en el display LCD 16x2 
(polling de 1 segundo).
 * ========================================
*/

//Librerias nativas de C y PSoC
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Librerias propias
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"//LCD
#include "D:\design-mpu\source\ejemplos\BME680\bme680.h"//Sensor BME680

//Variables sensor
int8_t error = 0;
sdata_bme680 datos_bme680;


//Varibles globlales
char *Etiquetas[] = {"Humedad:", "Presion atm:", "Calidad de aire:", "Temperatura amb:"};
int lecturas[4] = {0,0,0,0}; 

//Función para motrado de datos
void SHOW(){
    for(int i=0;i<=3;i++){
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString(Etiquetas[i]);
        LCD_Position(1,0);
        LCD_PrintNumber(lecturas[i]);
        CyDelay(1000);
    }
}

char LCD_msg[16];
//Funcion para captura de datos del sensor en I2C
void SENS(){
    
    datos_bme680 = bme680_readData(&sensor_bme680);//Optenemos las lecturas 
    
    //sprintf(LCD_msg,"T: %d degC, P: %d hPa, H: %d %%rH, G: %d ohms\r\n", datos_bme680.temperature /*/ 100*/,
    //datos_bme680.pressure /*/ 100*/, datos_bme680.humidity /*/ 1000*/, datos_bme680.gas_resistance);
}

int main(void)
{
    CyGlobalIntEnable;
    
    //Inicializamos perifericos
    LCD_Start();
    I2C_Start();
    
    error = bme680_Start(&sensor_bme680);
    
    for(;;)
    {
        //Sensamos
        SENS();
        
        //Mostramos
        SHOW();
    }
}

