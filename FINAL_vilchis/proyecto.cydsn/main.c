#include "project.h"
#include "stdio.h"
#include "math.h"

#include "..\PID_anticolision.cydsn\PID.h"
#include "..\AS5048.cydsn\AS5048B.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\driver_motor.cydsn\DRIVER_MOTOR.h"

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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //Perifericos
    MOTOR_Start(); //ACTUADOR
    Sampling_Start();//Compas de sampling
    UART_Start();//UART PARA COMUNICARCE CON LA INTERFAZ DE LABWIEV
    UART_ClearRxBuffer();
    UART_ClearTxBuffer();
    I2C_Start();//Para comunicacrse con el sensor
    struct AS5048B Encoder;//Creamos instancia del sensor
    AS5048B_Cero(&Encoder); //Seteamos el cero mecanico
    
    //Interrupcciones
    sensado_StartEx(sensado);
    sensado_ClearPending();
    
    interfaz_StartEx(interfaz);
    interfaz_ClearPending();
    //Escogemos un periodo de muestreo
    /*
    Con reloj de 10khz y 2^16 de periodo máximo
    el periodo de muestreo va de 200us-6.554s
    
    1bit es 100us
    */
    Sampling_WritePeriod(2);
    
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
    pid_instancia_variables.limMax = 254;
    
    pid_instancia_variables.limMinInt = 0;//Limites del integrador WIND-UP/
    pid_instancia_variables.limMaxInt = 90;
    
    pid_instancia_variables.T = 0.0002;//Periodo de muestreo en segundos
     
    PIDController_Init(&pid_instancia_variables);//Inicializamos constantes y variables
   
    //Auxiliares
    uint8_t out = 0;
    uint16_t ANGULO = 0;
    float setpoint = 0;
   
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
            //Leemos sensor
            AS5048B_REGISTROS(&Encoder);
            ANGULO = (Encoder.registros.angulo_Hi << 6) | (Encoder.registros.angulo_Lo);
            
            //Calculamos el angulo en grados
            ANGULO = map(ANGULO,0,1023,0,360);
            
            
            //Para labwiev
            sprintf(buffer_Tx,"S%ds",ANGULO);
            UART_PutString(buffer_Tx);//SENSADO
                
            //Controlador PID   
            PIDController_Update(&pid_instancia_variables,setpoint,ANGULO); 
            
            //Actualizacion de Actuador
            out = (uint8_t)pid_instancia_variables.out;
            POTENCIA(out);
            
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