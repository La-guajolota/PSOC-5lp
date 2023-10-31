#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
char buffer[64];//Buffer para lectura
char buffer_Tx[3];// Buffer para transmisión de datos UART
CY_ISR(isr){
    isr_ClearPending();  // Limpieza de interrupción
    
    buffer[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
    UART_PC_PutChar(buffer[i]);
    i++;
    
    if(buffer[i-1] == '*'){
        flag |= BIT0;// Bandera de dato recibido  
    }
}


// Función para extraer y retornar todos los números entre caracteres < y > en una cadena
uint8_t* extraerNumerosEntreCaracteres(const char *cadena, size_t *numNumeros) {
    const char *inicio = cadena;
    size_t capacidad = 1;  // Inicializamos la capacidad del arreglo dinámico a 1
    uint8_t *numeros = (uint8_t *)malloc(capacidad * sizeof(uint8_t)); // Reservamos memoria para el arreglo dinámico
    *numNumeros = 0;  // Inicializamos el número de elementos encontrados a cero

    while ((inicio = strchr(inicio, '<')) != NULL) {  // Buscamos el carácter '<' en la cadena
        const char *fin = strchr(inicio, '>');  // Buscamos el carácter '>' después del '<'
        
        if (fin != NULL) {
            inicio++; // Avanzamos una posición para evitar el '<'
            int longitud = fin - inicio; // Calculamos la longitud de la subcadena entre '<' y '>'
            
            char numeroStr[longitud + 1];  // Creamos un arreglo para almacenar la representación en cadena del número
            strncpy(numeroStr, inicio, longitud);  // Copiamos la subcadena a 'numeroStr'
            numeroStr[longitud] = '\0'; // Agregamos un carácter nulo al final de 'numeroStr'

            uint8_t numero = (uint8_t)atoi(numeroStr); // Convertimos la cadena en un número entero sin signo de 8 bits

            if (*numNumeros == capacidad) {  // Comprobamos si el número de elementos encontrados iguala la capacidad actual del arreglo dinámico
                capacidad *= 2; // Duplicamos la capacidad si es necesario para permitir más elementos
                numeros = (uint8_t *)realloc(numeros, capacidad * sizeof(uint8_t)); // Reasignamos memoria para el arreglo dinámico con la nueva capacidad
            }

            numeros[*numNumeros] = numero; // Almacenamos el número en el arreglo dinámico
            (*numNumeros)++; // Incrementamos el contador de elementos encontrados

            inicio = fin; // Movemos 'inicio' al siguiente carácter '<' para continuar buscando
        }
    }
    
    return numeros; // Devolvemos el arreglo dinámico que contiene todos los números encontrados
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
    
    PWM_Start();
    Counter_Start();
    
    //Inicializamos las plantas en ceros
    Counter_WriteCompare(0);
    PWM_WriteCompare(0);
    
    //Puente de UART
    UART_Start();
    UART_ClearRxBuffer();
    UART_PC_Start();
    UART_PC_ClearRxBuffer();
    //Interrrupciones
    isr_StartEx(isr);// Inicializar interrupción física
    isr_ClearPending();// Limpiar por primera vez la interrupción
    
    //wifi con esp
    esp_wifi_Start(0);
    
    //sensores
    error = bme680_Start(&sensor_bme680);
    uint16_t thermo = 0;
    
    //Parse de streamlit a psoc
    size_t numNumeros;
    uint8_t *p_numeros;
    
    for(;;)
    {
        
        datos_bme680 = bme680_readData(&sensor_bme680);//obtenemos datos del bme       
        thermo = sens();//Optenemos valores del thermopar
        
        //MANDAMOS INFO
        sprintf(buffer_Tx,"%d",thermo);
        UART_PC_PutChar('T');
        UART_PC_PutString(buffer_Tx);//Enviamos dato
        UART_PC_PutChar('t');
        
        
        sprintf(buffer_Tx,"%d",datos_bme680.pressure); //100
        UART_PC_PutChar('R');
        UART_PC_PutString(buffer_Tx);//Enviamos presion
        UART_PC_PutChar('r');
        
        sprintf(buffer_Tx,"%d",datos_bme680.temperature); //100
        UART_PC_PutChar('G');
        UART_PC_PutString(buffer_Tx);//Enviamos presion
        UART_PC_PutChar('g');
        
        sprintf(buffer_Tx,"%d",datos_bme680.humidity); //1000
        UART_PC_PutChar('A');
        UART_PC_PutString(buffer_Tx);//Enviamos humedad
        UART_PC_PutChar('a');
        
         sprintf(buffer_Tx,"%d",datos_bme680.gas_resistance);//1000
        UART_PC_PutChar('P');
        UART_PC_PutString(buffer_Tx);//Enviamos aire
        UART_PC_PutString("p\r\n");
        
        
        CyDelay(100);//POLLING DE 3 SEGUNDO EN SENSAR TODO
      
        
        //DESCOMENTAR PARA DEBUGUEAR
        
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
        
        LCD_Position(0,0);
        LCD_PrintString("THERMOPAR          ");
        LCD_Position(1,0);
        LCD_PrintNumber(thermo);
        LCD_PrintString(" degC              ");
        CyDelay(500);
        
        
        
        //RECIVIMOS INFO
        //RUTINA PARA CAPTURAR EL DATO ENVIADO POR EL uart
        if(flag){//Se envió un mensaje por la UART
            flag &= ~BIT0;//Tiramos la bandera
            
            //Parseamos las potencias de la plantas
            p_numeros = extraerNumerosEntreCaracteres(buffer, &numNumeros);
            
            //DESCOMENTAR PARA DEBUGUEAR
            
            //PARA EL EL FOCO
            
            LCD_Position(0,0);//Mostramos info en LCD
            LCD_PrintString("FOCO:           ");
            LCD_Position(1,0);
            LCD_PrintNumber(p_numeros[0]);
            LCD_PrintString("bits               ");
            CyDelay(2000);
            
            //PARA EL VENTILADOR
            LCD_Position(0,0);//Mostramos info en LCD
            LCD_PrintString("VENTILADOR:     ");
            LCD_Position(1,0);
            LCD_PrintNumber(p_numeros[1]);
            LCD_PrintString("bits               ");
            CyDelay(2000);
            
            
            //ACTUALIZAMOS Plantas
            Counter_WriteCompare(p_numeros[0]-20);
            PWM_WriteCompare(p_numeros[1]);
                
            //Limpiamos el buffer de lectura
            for(int a=0;a<63;a++){
                buffer[a] = 0x00;
            }
                
            i=0;//Seteamos
            }
        }
    
}