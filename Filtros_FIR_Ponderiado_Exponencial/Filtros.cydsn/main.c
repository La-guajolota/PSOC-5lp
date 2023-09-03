
#include "project.h"
#include <stdio.h>
#include <stdbool.h>
#include <Cal_pesos.h>


//Variables para filtros
#define ventana 3
int cont=0;
uint16 suma = 0;

//variables para el ADC
int16 lec_binaria,lec_Volts;
char8 Filtrado[5], NoFiltrado[5];//4 caracteres numéricos
int16 array[ventana];//Inicializamos el array en 0
int16 promedio=0;

int main(void)
 {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    for (int i=0; i<ventana; i++) {//Limpiamos con ceros el array de las lecturas
        array[i]=0;
    }
    
    //Para el filtro ponderiado
    //Parametros escogidos por el usuario para según el diseño de su filtro
    float b = 0.8; // 0<b<1
    float pesos[ventana];//array para guardar los pesos calculados
    
    P(ventana,b,pesos);//LLamamos la función para calcular y popular nuestro array con los pesos correspondientes
    
    UART_Start();
    ADC_Start();
    ADC_StartConvert();
    
    for(;;)
    {
        
        //hacemos nueva lectura
        while(ADC_IsEndConversion(0x00u)){//Verifica que se haya terminado una converción
            
            suma = suma - array[cont]; //Quitamos viejo elemento
            
            lec_binaria = ADC_GetResult16();//Recupera valor en el regisrtro del SAR
            lec_Volts = ADC_CountsTo_mVolts(lec_binaria);//Hace converción a mV
            array[cont] = pesos[cont]*lec_Volts;
            
            suma = suma + array[cont];;//agregamos dato a la suma
            cont++;
            
            if(cont>=ventana){
                 cont=0;
            }
            
            
            break;
        }
        
        
        
        //Enviamos lectura con ruido
        sprintf(NoFiltrado,"%d", lec_Volts);
        UART_PutChar('R');//Mandamos un espacio de caractier para separar
        UART_PutString(NoFiltrado);
        UART_PutChar('r');//Mandamos un espacio de caractier para separar
        
        //Convertimos a char para ponerlo en un array de char
        sprintf(Filtrado,"%d",suma);
        UART_PutChar('F');//Mandamos un F de caractier para separar
        UART_PutString(Filtrado);//Mandamos la info ya filtrada     
        UART_PutString("f\r\n");//fin de la trama
        
    }    
}

/* [] END OF FILE */
