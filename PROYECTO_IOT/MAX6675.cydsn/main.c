#include "project.h"
#include "stdio.h"
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"//LCD
#include "MAX6675_.h"

/*
ACTUALIZAMOS POR INTERRUPCCIÓN CADA CAMVIO QUE HAYA DE SETPOINT
    LABVIEW:
    si se quiere mandar un setpoint nuevo al micro, debe de llegar de este modo:
    EJEMPLO:
    
    actualizamos el setpoint a 67 grados
    el buffer del uart debe de recibir en codigo ascci 
    
    "067*" 
    
    actualizamos el setpoint a 9 grados
    el buffer del uart debe de recibir en codigo ascci 
    
    "009*" 
    
    actualizamos el setpoint a 146 grados
    el buffer del uart debe de recibir en codigo ascci 
    
    "146*" 
    
    SOLO SE PODRA ACTUALIZAR EL SETPOINT ENTRE NUMEROS ENTEROS DEL O-255
*/
char buffer_Rx[4];//Buffer para lectura
uint8_t i = 0, setpoint = 0; //contador para leer el buffer
CY_ISR(isr_setpoint){
    isr_setpoint_ClearPending();  // Limpieza de interrupción
    
    buffer_Rx[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
    i++;
    
    if(buffer_Rx[i-1] == '*'){ //REBIZAMOS EL BUFFER SETPOINT
        setpoint = 0;                    // Limpiar valor de PWM
                
        setpoint += (buffer_Rx[i-2] - 0x30) * 1;     // Unidades
        setpoint += (buffer_Rx[i-3] - 0x30) * 10;    // Decenas
        setpoint += (buffer_Rx[i-4] - 0x30) * 100;   // Centenas
        
        i=0;   
    }
    
    /* Comming soon
    Recibimiento de Kp Ki y Kd
    */
}



int main(void)
{
    CyGlobalIntEnable;
    //Inicializamos perifericos
    LCD_Start();
    SPIM_Start();
    UART_Start();
    UART_ClearTxBuffer();
    LCD_ClearDisplay();    
    struct max6675 thermocupla; //Sensor themocupla MAX6675
    
    //Interrrupciones
    isr_setpoint_StartEx(isr_setpoint);// Inicializar interrupción física
    isr_setpoint_ClearPending();  // Limpieza de interrupción
    
    
    //variables
    char buffer_Tx[8];
    for(;;)
    {
        
        //Sensamos
        SENS_max6675(&thermocupla);
        CyDelay(500);
        
        //Mostramos temp si no hay errror de comunicacion
        if(thermocupla.data.errores){
            //PARA LA LCD
            LCD_Position(0,0);
            LCD_PrintString("ERRORES        ");
            LCD_Position(1,0);
            LCD_PrintHex8(thermocupla.data.errores);//Expresado en 
            LCD_PrintString("                  ");
            
            //PARA INTERFAZ LABVIEW
            //sprintf(buffer_Tx, "%d\n\r",thermocupla.data.errores);
            UART_PutString("ERRORES\n\r");
        }else{
            //PARA LA LCD
            LCD_Position(0,0);
            LCD_PrintString("TEMP: ");
            LCD_PrintNumber(thermocupla.data.temperatura);
            LCD_PrintString("degC");
            LCD_Position(1,0);
            LCD_PrintString("SP:   ");
            LCD_PrintNumber(setpoint);
            LCD_PrintString("degC");
            
            //PARA INTERFAZ LABVIEW
            sprintf(buffer_Tx, "%d\n\r",thermocupla.data.temperatura);
            UART_PutString(buffer_Tx);            
        }
        
    }
}


