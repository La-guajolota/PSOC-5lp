//Librerias de C nativas
#include "project.h"
#include "stdio.h"
#include "math.h"

//Librerias propias
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.c"
#include "..\..\PROYECTO_IOT\MAX6675.cydsn\MAX6675_.h"
#include "..\..\FINAL_vilchis\PID_anticolision.cydsn\filtros.h"
#include "..\..\FINAL_vilchis\PID_anticolision.cydsn\PID.h"

/*

    Rutinas para interactuar con el PID Labwiev interfaz

*/

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

Varibles auxiliares para el control

*/

#define DENOMINADOR 100
uint8_t Actuadores_reg = 0;//Registro de estado de los actuadores

//Rutina de sumado para actuador 0
uint16_t acomulador_0 = 0, on_0 = DENOMINADOR;
CY_ISR(contador_0){
    contador_0_ClearPending();// Limpieza de interrupción
    
    acomulador_0++; //65535 bits máximos
    
    if(acomulador_0 >= DENOMINADOR){
        acomulador_0 =0;
    }
    
    /*
        Al ser un relevador de estado solido todo integrado,
        no hay problema en no activar con pulsos-disparo
    */
    
    Actuadores_reg = Actuadores_Read();//Leemos estadoa ctual de los disparos
    if(on_0 <= acomulador_0){//ON 
    
        Actuadores_Write(Actuadores_reg | BIT0);
            
    }else{//OFF
        
        Actuadores_Write(Actuadores_reg & (~BIT0));
    }
        
}

//Rutina de sumado para actuador 1
uint16_t acomulador_1 = 0, on_1 = 0;
CY_ISR(contador_1){
    contador_1_ClearPending();// Limpieza de interrupción
    
    acomulador_1++; //65535 bits máximos
    
    if(acomulador_1 >= DENOMINADOR){
        acomulador_1 =0;
    }
    
    /*
        Al ser un relevador de estado solido todo integrado,
        no hay problema en no activar con pulsos-disparo
    */
    
    Actuadores_reg = Actuadores_Read();//Leemos estadoa ctual de los disparos
    if(on_1 <= acomulador_1){//ON 
    
        Actuadores_Write(Actuadores_reg | BIT1);
            
    }else{//OFF
        
        Actuadores_Write(Actuadores_reg & (~BIT1));
    }
        
}


int main(void)
{
    CyGlobalIntEnable;
    //Perifericos
    Sampling_Start();// Compas de sensado
    UART_Start();//Comunicacion por serial
    UART_ClearRxBuffer();
    UART_ClearTxBuffer();
    SPIM_Start();
    
    //Interrrupciones
    contador_0_StartEx(contador_0);// Inicializar interrupción física
    contador_0_ClearPending();  // Limpieza de interrupción
    contador_1_StartEx(contador_1);
    contador_1_ClearPending();
    sensado_StartEx(sensado);//Interrucion para el sampling
    sensado_ClearPending();
    interfaz_StartEx(interfaz);//Interrucion para la comunicacion con el labwiev
    interfaz_ClearPending();
    
    //INICIALIZAMOS FILTRO PRMEDIADOR
    PromediadorMovil FILTRO;
    inicializarPromediadorMovil(&FILTRO);
    
    //Sensor
    struct max6675 thermocupla; //Sensor themocupla MAX6675
    
    //Escogemos un periodo de muestreo
    /*
    Con reloj de 10khz y 2^16 de periodo máximo
    el periodo de muestreo va de 200us-6.554s
    
    1bit es 100us
    */
    Sampling_WritePeriod(2000);
    
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
    pid_instancia_variables.limMax = 100;
    
    pid_instancia_variables.limMinInt = -50;//Limites del integrador WIND-UP/
    pid_instancia_variables.limMaxInt = 50;
    
    pid_instancia_variables.T = 0.2;//Periodo de muestreo en segundos
     
    PIDController_Init(&pid_instancia_variables);//Inicializamos constantes y variables
   
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
            agregarValor(&FILTRO,thermocupla.data.temperatura_decimal);
            temperatura = obtenerPromedioMovil(&FILTRO); // SEÑAL FILTRADA
            
            //Para labwiev
            sprintf(buffer_Tx,"S%ds",(int)temperatura);
            UART_PutString(buffer_Tx);//SENSADO
                
            //Controlador PID   
            PIDController_Update(&pid_instancia_variables,setpoint,temperatura); 
            
            //Actualizacion de Actuador
            out = 100 - (uint8_t)pid_instancia_variables.out;
            on_0 = (uint8_t)out;
            on_1 = (uint8_t)out;
            
            //Para labwiev
            sprintf(buffer_Tx,"A%da",100 - out);
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


