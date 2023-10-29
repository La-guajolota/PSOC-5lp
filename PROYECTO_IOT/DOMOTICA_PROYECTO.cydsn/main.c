#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\ESP_wifi_module.cydsn\espU1.h"
#include "D:\mcu\design-mpu\source\ejemplos\BME680\bme680.h"
#include "..\MAX6675.cydsn\max6675.h"
#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"

//Variables de BME
int8_t error = 0;
sdata_bme680 datos_bme680;
uint8_t datochu = 0;
uint8_t result = 0;
uint8_t address = 0x76;

//Rutina de interrrupción
uint8_t flag = 0;//Bandera de interrupión de la uart
int i=0;//Contador para leer el buffer de la UART
char buffer[32];//Buffer para lectura
CY_ISR(isr){
    isr_ClearPending();  // Limpieza de interrupción
    
    buffer[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
    UART_PC_PutChar(buffer[i]);
    i++;
    
    if(buffer[i-1] == '*'){
        flag |= BIT0;// Bandera de dato recibido  
    }
}



int main(void)
{
    CyGlobalIntEnable;
    //INCIALIZAMOS HARDWARE
    I2C_Start();
    SPIM_Start();
    LCD_Start();
    LCD_ClearDisplay();
    LCD_Position(0,0);
    
    //Puente de UART
    UART_Start();
    UART_ClearRxBuffer();
    UART_PC_Start();
    UART_PC_ClearRxBuffer();
    //Interrrupciones
    isr_StartEx(isr);// Inicializar interrupción física
    isr_ClearPending();// Limpiar por primera vez la interrupción
    
    //wifi con esp
    esp_wifi_Start(2);
    
    //sensores
    error = bme680_Start(&sensor_bme680);
    uint16_t thermo = 0;//Variable alamacena la temperatura 
    for(;;)
    {
        //obtenemos datos del bme
        datos_bme680 = bme680_readData(&sensor_bme680);
        
        LCD_Position(0,0);
        LCD_PrintString("Temperatura:    ");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.temperature/100);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.temperature%100);
        LCD_PrintString("C               ");
        CyDelay(500);
        
        LCD_Position(0,0);
        LCD_PrintString("Humedad:        ");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.humidity/1000);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.humidity%1000);
        LCD_PrintString("%               ");
        CyDelay(500);
        
        LCD_Position(0,0);
        LCD_PrintString("Presion atmos:  ");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.pressure/100);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.pressure%100);
        LCD_PrintString("hPa             ");
        CyDelay(500);
        
        LCD_Position(0,0);
        LCD_PrintString("Resistencia gas:");
        LCD_Position(1,0);
        LCD_PrintNumber(datos_bme680.gas_resistance/1000);
        LCD_PrintString(".");
        LCD_PrintNumber(datos_bme680.gas_resistance%1000);
        LCD_PrintString(" Kohm            ");
        CyDelay(500);
        
        //Optenemos valores del thermopar
        thermo = sens();//sensamos
        LCD_Position(0,0);
        LCD_PrintString("THERMOPAR          ");
        LCD_Position(1,0);
        LCD_PrintNumber(thermo);
        LCD_PrintString("degC               ");
        CyDelay(500);
        
        //Mandamos info a streamlit
        
        //RECIVIMOS INFO
        //RUTINA PARA CAPTURAR EL DATO ENVIADO POR EL uart
        if(flag){//Se envió un mensaje por la UART
            flag &= ~BIT0;//Tiramos la bandera
                          
            if(strstr(buffer,"FOCO")!= NULL){//rojo
                LCD_Position(0,0);
                LCD_PrintString("POTENCIA FOCO:  ");
                CyDelay(3000);
            }
            if(strstr(buffer,"VENTILADOR")!= NULL){//rojo
                LCD_Position(0,0);
                LCD_PrintString("POTENCIA VENTILADOR:  ");
                CyDelay(3000);
            }
            
            //ACTUALIZAMOS Plantas
                
            //Limpiamos el buffer de lectura
            for(int a=0;a<31;a++){
                buffer[a] = 0x00;
            }
                
            i=0;//Seteamos
            }
        }
    
}