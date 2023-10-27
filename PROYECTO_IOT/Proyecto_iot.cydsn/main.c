#include "project.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"

uint8_t flag = ~BIT0;
char buffer[32];//Buffer para lectura
//Subrutina de interrupcción
CY_ISR(wifi){
    flag |= BIT0;// Bandera de dato recibido  
}

//Variables de lectura de los sensores
uint8_t TEM=0,PRE=0,HUM=0,AIR=0,CUPLA=0;

int main(void)
{
    CyGlobalIntEnable;
    //inicializamos el hardware del PSoC
    UART_Start();
    UART_ClearRxBuffer();
    
    //Interrupciones del llamado del modulo Wifi
    wifi_StartEx(wifi);
    wifi_ClearPending();
    
    //Actuadores
    PWM_Start();
    PWM_WriteCompare(0);//Inicializamos en potencia 0
    Counter_Start();
    Counter_WriteCompare(252);//Inicializamos en potencia 0
    
    //RUTINA DE PRUEBA DE CONTROL POR FASE Y VENTILADOR
    //Rutina de prueba para concoer el estado de todo el sistema
    for(int i=0;i<5;i++){
        for(int i=255;i>=0;i--){
            Counter_WriteCompare(i);
            PWM_WriteCompare(i);
            CyDelay(25);
        }
        for(int i=0;i<=255;i++){
            Counter_WriteCompare(i);
            PWM_WriteCompare(i);
            CyDelay(25);
        }
    }
    
    int i=0;//Contador para leer el buffer de la UART
    char potencia = 0;//Variable de potencia
    uint8_t actuador = 0;
    for(;;)
    {
        
        //Rutina input del dashboard
        if(flag){//Detectamos si la bandera esytá levantada
            flag &= ~BIT0;//Tiramos la bandera
            
            buffer[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
            i++;
            
            //Cortamos al detectar el caracter
            if(buffer[i-1] == ' ') {
            //Rutina de recepción de instruciones de la dash Board
            //Capturamos qué actuador se quiere interactuar
            //Capturamos el nuevo valor de la potencia 
            } 
            
        }
        
        //Actualizamos la potencia de los actuadores
        switch (actuador){
            case 0x01://Ventilador
                PWM_WriteCompare(potencia);//Actualizamos valor de potencia
                break;
            case 0x02://FOCO
                Counter_WriteCompare(potencia);//Actualizamos potencia
                break;
            default:
                break;
        }
        
        //Capturamos lectura de Termopar
        
        //Captura de BMS
        
        //Mostramos en la LCD
        
        //Enviamos info de sensados a la Dashboard
        
    }
}


