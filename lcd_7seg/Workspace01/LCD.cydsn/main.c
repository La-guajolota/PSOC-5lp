#include "project.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "PSOC_LCD.h"   //Libreria lcd
#include "string.h"     // Cadenas de texto
#include "stdio.h"      // IO en general *sprintf*

//Rutina de interrrupción
uint8_t flag = 0x00;//Bandera de interrupión de la uart
CY_ISR(isr){
    isr_ClearPending();  // Limpieza de interrupción
    flag |= BIT0;// Bandera de dato recibido  
}

//Son 36 bytes por cantidad máxima del lcd 2*16 
char buffer[32], buffer_renglon1[16],buffer_renglon2[16];//Buffer para lectura
char *posicion;//Puntero pra eliminar elemento

int main(void)
{
    //INTERRUPCIONES
    CyGlobalIntEnable;
    isr_StartEx(isr);// Inicializar interrupción física
    isr_ClearPending();// Limpiar por primera vez la interrupción
    
    //UART
    UART_Start();// Corre UART
    UART_ClearRxBuffer();//Limpiamos el buffer del UART
    
    //PERIFERICOS VARIOS
    LED_Write(~BIT1);//Led verde de listo para comenzar
    
    //Inicializamos la pantalla
    LCD_Start();
    LCD_PrintString("Un saludo a la");
    LCD_Position(1,0);
    LCD_PrintString("grasa!!! WAZAAAA");
    CyDelay(3000);
    LCD_ClearDisplay();
    
    uint8_t i = 0;//variable auxiliar para la captura de info input del UART
    for(;;)
    {
        //RUTINA PARA CAPTURAR EL DATO ENVIADO POR EL uart
        if(flag == BIT0){//Se envió un mensaje por la UART
            flag &= ~BIT0;//Tiramos la bandera
            
            buffer[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
            i++;
            
            if(buffer[i-1] == '.') {//Cortamos al detectar una arroba
                // Eliminamos el @ 
                LED_Write(~BIT0);//Encendemos rojo 
                
                // Copiamos el buffer al arreglo para imprimir en el lcd
                // Copiamos el buffer al arreglo para imprimir en el lcd
                strncpy(buffer_renglon1, buffer, 16); // Copiar elementos del 0 al 15 a buffer_renglon1
                buffer_renglon1[15] = '\0'; // Añadir el carácter nulo manualmente para terminar la cadena en buffer_renglon1

                strncpy(buffer_renglon2, buffer + 16, 16); // Copiar elementos del 16 al 31 a buffer_renglon2
                buffer_renglon2[15] = '\0'; // Añadir el carácter nulo manualmente para terminar la cadena en buffer_renglon2
                
                //Imprimimos en el lcd
                LCD_ClearDisplay();
                LCD_Position(0,0);
                LCD_PrintString(buffer_renglon1);
                LCD_Position(1,0);
                LCD_PrintString(buffer_renglon2);
                
                //Limpiamos el buffer de lectura
                for(int a=0;a<32;a++){
                    buffer[a] = 0x00;
                }
                
               i=0;//Seteamos
               LED_Write(~BIT2);//Encendemos azul como indicador de algo impreso  
            }
            
            
        }
    }
}


