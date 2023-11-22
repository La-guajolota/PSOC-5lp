#include "project.h"
#include "stdio.h"

#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\..\PROYECTO_IOT\MAX6675.cydsn\MAX6675_.h"


float Kp = 8.0;//Contrante proporcional
float setpoint = 0;
//INTERRUPCION DE ACTUALIZACIÓN DE SETPOINT Y KP
char buffer_Rx[4];//Buffer para lectura
uint8_t i = 0; //contador para leer el buffer
CY_ISR(isr_setpoint){
    isr_setpoint_ClearPending();  // Limpieza de interrupción
    
    buffer_Rx[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
    i++;
    
    if(buffer_Rx[i-1] == '*'){ //REBIZAMOS EL BUFFER SETPOINT
        setpoint = 0;                    // Limpiar valor de SP
                
        setpoint += (buffer_Rx[i-2] - 0x30) * 1;     // Unidades
        setpoint += (buffer_Rx[i-3] - 0x30) * 10;    // Decenas
        setpoint += (buffer_Rx[i-4] - 0x30) * 100;   // Centenas
        
        i=0;
        
        //Actualizamos en displat LCD KP
        LCD_Position(1,10);
        LCD_PrintNumber(setpoint);
        LCD_PrintString("C");
    }
    
    if(buffer_Rx[i-1] == '+'){ //REBIZAMOS EL KP
        Kp = 0;                    // Limpiar valor de SP
        
        Kp += (buffer_Rx[i-2] - 0x30) * 0.01;     // Unidades
        Kp += (buffer_Rx[i-3] - 0x30) * 0.10;    // Decenas
        
        Kp += (buffer_Rx[i-2] - 0x30) * 1;     // Unidades
        Kp += (buffer_Rx[i-3] - 0x30) * 10;    // Decenas
        Kp += (buffer_Rx[i-4] - 0x30) * 100;   // Centenas
        
        i=0;   
    }
   
}

//RUTINAS POR LINEA DE ANGULO DE DISPARO DE CADA LINEA
CY_ISR(DIS_0){ //linea1
    DIS_0_ClearPending();
    
    DISPARADORES_Write(DISPARADORES_Read() | BIT0);
    CyDelayUs(10);
    DISPARADORES_Write(DISPARADORES_Read() & (~BIT0));
}

CY_ISR(DIS_1){ //linea2
    DIS_1_ClearPending();
    
    DISPARADORES_Write(DISPARADORES_Read() | BIT1);
    CyDelayUs(10);
    DISPARADORES_Write(DISPARADORES_Read() & (~BIT1));
}

CY_ISR(DIS_2){//Linea3
    DIS_2_ClearPending();
    
    DISPARADORES_Write(DISPARADORES_Read() | BIT2);
    CyDelayUs(10);
    DISPARADORES_Write(DISPARADORES_Read() & (~BIT2));
}

//Actualizacion de sensado
uint8_t flag = ~BIT0;
CY_ISR(sensado){
    sensado_ClearPending();
   
    flag = BIT0;
}

int main(void)
{
    CyGlobalIntEnable; 
    //pERIFERICOS DE COMUNICACION
    UART_Start();
    UART_ClearTxBuffer();
    UART_ClearRxBuffer();
    SPIM_Start();
    
    //PERIFÉRICOS TIMERS    
    Timer_0_Start();
    Timer_1_Start();
    Timer_2_Start();
    
    //Congifuramos las interrupcciones de los cruces por cero
    DIS_0_StartEx(DIS_0);
    DIS_0_ClearPending();
    DIS_1_StartEx(DIS_1);
    DIS_1_ClearPending();
    DIS_2_StartEx(DIS_2);
    DIS_2_ClearPending();
    
    //Iterrupciion de ssampling
    SAMPLING_Start();
    sensado_StartEx(sensado);
    sensado_ClearPending();
    
    //Interrupcion de actualizadode controlador
    isr_setpoint_StartEx(isr_setpoint);
    isr_setpoint_ClearPending();
    
    //LCD
    LCD_Start();
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("TEMP:");
    LCD_Position(1,0);
    LCD_PrintString("SetPoint:");
    
    //SENSOR DE TEMPERATURA
    struct max6675 thermocupla; //Sensor themocupla MAX6675
    
    //cONTROLADOR PROPORCIONAL
    float ERROR = 0;
    float out = 0;
    float temp = 0;
    
    uint8_t ang_dis;
    char buffer_Tx[16];
    for(;;)
    {
        if(flag == BIT0){// Cada segundo se entra y ejecuta el controlador
            flag = ~BIT0;
            
            //SENSAMOS
            SENS_max6675(&thermocupla);
            temp = thermocupla.data.temperatura_decimal;
            
            //ENVIAMOS A LABWIEV LO SENSADO
            //sprintf(buffer_Tx,"%d.%d\n\r",thermocupla.data.temperatura>>7,thermocupla.data.temperatura & 0x7F);
            sprintf(buffer_Tx,"%d\n\r",thermocupla.data.temperatura>>7);
            UART_PutString(buffer_Tx);
            
            //Mostramos en LCD
            LCD_Position(0,10);
            LCD_PrintNumber(thermocupla.data.temperatura>>7);
            LCD_PrintString("c");
            
            ERROR = setpoint - temp;
            
            //CONTROLADOR proporcional
            out = Kp*ERROR;
            
            //ACTUALIZACION EN EL ACTUADOR        
            //mapeo de out a actuador
            //Cliping del actuador en caso de saturacion
            ang_dis = map(out,0,220,2,255);
            
            //Actualizamos actuador
            Timer_0_WritePeriod(ang_dis);
            Timer_1_WritePeriod(ang_dis);
            Timer_2_WritePeriod(ang_dis);
        }        
    }
}

