#include "project.h"
#include "stdio.h"
#include "math.h"

#include "..\..\FINAL_vilchis\PID_anticolision.cydsn\filtros.h"
#include "..\..\PROYECTO_IOT\MAX6675.cydsn\MAX6675_.h"
#include "..\..\FINAL_vilchis\PID_anticolision.cydsn\PID.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"

//Subrutina de la interrupcion para sampling
uint8_t sens_flag = ~BIT0;
CY_ISR(sensado){
    sensado_ClearPending();
    
    sens_flag = BIT0;
}

//Subrutina para interactuar con Labwiev
uint8_t interfaz_lab = ~BIT0;
CY_ISR(interfaz){
    interfaz_ClearPending();
    
    interfaz_lab = BIT0;
}

/*
    RUTINAS DE DISPARA PARA LOS CONTROLES POR FASE
*/
uint8_t Disparadores_reg=0;

CY_ISR(DIS_0){
    DIS_0_ClearPending();
    
    Disparadores_reg = DISPARADORES_Read();//Leemos estadoa ctual de los disparos
    
    DISPARADORES_Write(Disparadores_reg | BIT0);
    CyDelayUs(10);
    DISPARADORES_Write(Disparadores_reg & (~BIT0));
    
}

CY_ISR(DIS_1){
    DIS_1_ClearPending();
    
    Disparadores_reg = DISPARADORES_Read();//Leemos estadoa ctual de los disparos
    
    DISPARADORES_Write(Disparadores_reg | BIT1);
    CyDelayUs(10);
    DISPARADORES_Write(Disparadores_reg & (~BIT1));
    
}

CY_ISR(DIS_2){
    DIS_2_ClearPending();
    
    Disparadores_reg = DISPARADORES_Read();//Leemos estadoa ctual de los disparos
    
    DISPARADORES_Write(Disparadores_reg | BIT2);
    CyDelayUs(10);
    DISPARADORES_Write(Disparadores_reg & (~BIT2));
    
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*
      Perifericos
    */
    Timer_0_Start();//Actuadores
    Timer_1_Start();
    Timer_2_Start();
    Sampling_Start();//Compas de muestreo
    UART_Start();//Uart para comunicacion con el usuario-Labwiev
    UART_ClearRxBuffer();
    UART_ClearTxBuffer();
    SPIM_Start();//Comunicacion con el sensor
    LCD_Start();//Pantalla lcd
    LCD_ClearDisplay();    
    
    /*
        Interrupcciones
    */
    sensado_StartEx(sensado); //Para el sambpling
    sensado_ClearPending();
    interfaz_StartEx(interfaz);//Para la comunicion con la interfaz de labwiev
    interfaz_ClearPending();
    DIS_0_StartEx(DIS_0);// interrupciones para el diparon en el control por fase
    DIS_0_ClearPending();
    DIS_1_StartEx(DIS_1);// interrupciones para el diparon en el control por fase
    DIS_1_ClearPending();
    DIS_2_StartEx(DIS_2);// interrupciones para el diparon en el control por fase
    DIS_2_ClearPending();
    
    //Escogemos un periodo de muestreo
    /*
    Con reloj de 10khz y 2^16 de periodo máximo
    el periodo de muestreo va de 200us-6.554s
    
    1bit es 100us
    */
    Sampling_WritePeriod(10000);
    
    /***
    
    PID PID PID PID PID PID PID PID PID PID PID PID
    Configuración preliminar de conrtol PID
    
    ***/
    PIDController pid_instancia_variables;
    
    //constantes del controlador
    pid_instancia_variables.Kp = 0;
    pid_instancia_variables.Ki = 0;
    pid_instancia_variables.Kd = 0;
    
    pid_instancia_variables.tau = 0.25;//filtro pasabaja derivativo
    
    pid_instancia_variables.limMin = 0; //Limites del actuador
    pid_instancia_variables.limMax = 165;
    
    pid_instancia_variables.limMinInt = 0;//Limites del integrador WIND-UP/
    pid_instancia_variables.limMaxInt = 150;
    
    pid_instancia_variables.T = 1;//Periodo de muestreo en segundos
     
    PIDController_Init(&pid_instancia_variables);//Inicializamos constantes y variables
    
    //INICIALIZAMOS FILTRO PRMEDIADOR
    PromediadorMovil FILTRO;
    inicializarPromediadorMovil(&FILTRO);
   
    //Inicializamos sensor themopar
    struct max6675 thermocupla; //Sensor themocupla MAX6675
    
    //Auxiliares
    uint8_t out = 0;
    float temperatura = 0.0;
    float setpoint = 25.0;//Temperatura ambiente
   
    //Variables para el parseo de informacion
    char buffer_Tx[16],buffer_Rx[16];
    uint8_t i = 0; //contador para leer el buffer
    int x;//contador auxiliar para parsear
    uint8_t enteros;
    /// Parseo con punto decimal como caracter 
    char *posicion;// Utilizar la función strchr para encontrar la posición del carácter
    int posicionEnCadena;     
    
    for(;;)
    {
        if(sens_flag == BIT0){//RUTINA PRINCIPAR DEL SISTEMA DE CONTROL
            sens_flag = ~BIT0;
            
            //Sensamos
            SENS_max6675(&thermocupla);
            
            //Filtro
            agregarValor(&FILTRO,thermocupla.data.temperatura>>7);
            temperatura = (float)obtenerPromedioMovil(&FILTRO); // SEÑAL FILTRADA
            
            //Mostramos en lcd
            LCD_Position(1,0);
            LCD_PrintNumber(temperatura);
            LCD_PrintString(" degC      ");
            
            //Para labwiev
            sprintf(buffer_Tx,"S%ds",(int)temperatura);
            UART_PutString(buffer_Tx);//SENSADO
                
            //Controlador PID   
            PIDController_Update(&pid_instancia_variables,setpoint,temperatura); 
            
            //Actualizacion de Actuador_valor_output
            out = 180 - (uint8_t)pid_instancia_variables.out;
            
            //Modificamos fisicamente los acuadores
            Timer_0_WritePeriod(map(out,0,180,2,255));
            Timer_1_WritePeriod(map(out,0,180,2,255));
            Timer_2_WritePeriod(map(out,0,180,2,255));
            
            //Para labwiev
            sprintf(buffer_Tx,"A%da",out);
            UART_PutString(buffer_Tx);//ACTUADOR
        }
        
        if(interfaz_lab == BIT0){//RUTINA DE ACTUALIZADO DE VARIBLES
            interfaz_lab = ~BIT0;
            
            buffer_Rx[i] =  UART_GetByte();//Agregamos al arreglo el ascci del caracter recibido
            i++;
            
            if(buffer_Rx[i-1] == 'S'){ //REBIZAMOS EL BUFFER SETPOINT
                setpoint = 0;                    // Limpiar valor de SP
                        
                //Parseamos
                x = -2;
                enteros = 0;
                while ((i+x)>=0){
                
                    setpoint += (buffer_Rx[i+x] - 0x30) * pow(10.0,enteros);
                    
                    x--;//Recorremos una posicion del string
                    enteros++;
                }
                
                i=0;  
                
                for(int i=0;i<16;i++){//limpiamos buffer
                    buffer_Rx[i] = 0;
                }
                
                //Mostramos en lcd
                LCD_Position(0,0);
                LCD_PrintString("SP: ");
                LCD_PrintNumber(setpoint);
                LCD_PrintString(" degC  ");
                
                
            }
            
            if(buffer_Rx[i-1] == 'P'){ //REBIZAMOS EL KP
                pid_instancia_variables.Kp = 0;                    // Limpiar valor de SP
                
                //Parseamos
                x = -2;
                
                //Encontramos la posicion del punto dentro de la cadena
                posicion = strchr(buffer_Rx, '.');
                posicionEnCadena = posicion - buffer_Rx;
                
                while (buffer_Rx[i+x] != '.'){//Miestras sea la parte decimal
                

                    pid_instancia_variables.Kp += (buffer_Rx[i+x] - 0x30) * powf(0.1,(float)i+x-posicionEnCadena);
                    
                    x--;//Recorremos una posicion del string
                }
                
                enteros = 0;
                x--;//Nos saltamos el punto 
                while ((i+x)>=0){//Pate entera
                
                    pid_instancia_variables.Kp += (buffer_Rx[i+x] - 0x30) * pow(10.0,enteros);
                    
                    x--;//Recorremos una posicion del string
                }
                
                i=0;  
                
                for(int i=0;i<16;i++){//limpiamos buffer
                    buffer_Rx[i] = 0;
                }
            }
            
            if(buffer_Rx[i-1] == 'I'){ //REBIZAMOS EL KI
                pid_instancia_variables.Ki = 0;
                
                //Parseamos
                x = -2;
                
                //Encontramos la posicion del punto dentro de la cadena
                posicion = strchr(buffer_Rx, '.');
                posicionEnCadena = posicion - buffer_Rx;
                
                while (buffer_Rx[i+x] != '.'){//Miestras sea la parte decimal
                

                    pid_instancia_variables.Ki += (buffer_Rx[i+x] - 0x30) * powf(0.1,(float)i+x-posicionEnCadena);
                    
                    x--;//Recorremos una posicion del string
                }
                
                enteros = 0;
                x--;//Nos saltamos el punto 
                while ((i+x)>=0){//Pate entera
                
                    pid_instancia_variables.Ki += (buffer_Rx[i+x] - 0x30) * pow(10.0,enteros);
                    
                    x--;//Recorremos una posicion del string
                }
                
                i=0;
                
                for(int i=0;i<16;i++){//limpiamos buffer
                    buffer_Rx[i] = 0;
                }
            }
            
            if(buffer_Rx[i-1] == 'D'){ //REBIZAMOS EL KD
                pid_instancia_variables.Kd = 0;
                
                //Parseamos
                x = -2;
                
                //Encontramos la posicion del punto dentro de la cadena
                posicion = strchr(buffer_Rx, '.');
                posicionEnCadena = posicion - buffer_Rx;
                
                while (buffer_Rx[i+x] != '.'){//Miestras sea la parte decimal
                

                    pid_instancia_variables.Kd += (buffer_Rx[i+x] - 0x30) * powf(0.1,(float)i+x-posicionEnCadena);
                    
                    x--;//Recorremos una posicion del string
                }
                
                enteros = 0;
                x--;//Nos saltamos el punto 
                while ((i+x)>=0){//Pate entera
                
                    pid_instancia_variables.Kd += (buffer_Rx[i+x] - 0x30) * pow(10.0,enteros);
                    
                    x--;//Recorremos una posicion del string
                }
                
                i=0;
                
                for(int i=0;i<16;i++){//limpiamos buffer
                    buffer_Rx[i] = 0;
                }
            }
            
            
        }
    } 
}