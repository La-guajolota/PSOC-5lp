#include "project.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
#include "espU1.h" //Libreria apra configura la esp wifi modulo
#include "string.h"//Funciones para Cadenas de texto

//Rutina de interrrupción
uint8_t flag = 0x00;//Bandera de interrupión de la uart
CY_ISR(isr){
    isr_ClearPending();  // Limpieza de interrupción
    flag |= BIT0;// Bandera de dato recibido  
}
char buffer[32];//Buffer para lectura

int main(void)
{
    CyGlobalIntEnable;
    isr_StartEx(isr);// Inicializar interrupción física
    isr_ClearPending();// Limpiar por primera vez la interrupción
    
    //Perifericos
    UART_Start();
    UART_ClearRxBuffer();
    //UART_PC_Start();
    //UART_PC_ClearRxBuffer();
    LCD_Start();
    esp_wifi_Start();
    
    int i=0;//Contador para leer el buffer de la UART
    uint8_t colores = 0xFF;//inicialmente todos apagados
    for(;;)
    {
        //RUTINA PARA CAPTURAR EL DATO ENVIADO POR EL uart
        if(flag){//Se envió un mensaje por la UART
            flag &= ~BIT0;//Tiramos la bandera
            
            buffer[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
            i++;
            
            //Cortamos al detectar el caracter
            if(buffer[i-1] == ' ') {
 
            //char *leds[4]={"red ","green ","blue ","orange "};   
            //******TOGGLES segun los botones del streamlit
            /*
            if(!strcmp(leds[0], buffer)){//rojo
                colores ^= BIT0;
            }
            if(!strcmp(leds[1], buffer)){//verde
                colores ^= BIT1;
            }  
            if(!strcmp(leds[2], buffer)){//azul
                colores ^= BIT2;
            }  
            if(!strcmp(leds[3], buffer)){//naranja
                colores ^= BIT3;
            }     
            */
            
            if(strstr(buffer,"red")!= NULL){//rojo
                colores ^= BIT0;
            }
            if(strstr(buffer,"green")!= NULL){//verde
                colores ^= BIT1;
            }  
            if(strstr(buffer,"blue")!= NULL){//azul
                colores ^= BIT2;
            }  
            if(strstr(buffer,"orange")!= NULL){//naranja
                colores ^= BIT3;
            }     
             
            //ACTUALIZAMOS COLORES
            LEDS_Write(colores);
                
            //Limpiamos el buffer de lectura
            for(int a=0;a<31;a++){
                buffer[a] = 0x00;
            }
                
            i=0;//Seteamos
            }
        }
        
    }
}


