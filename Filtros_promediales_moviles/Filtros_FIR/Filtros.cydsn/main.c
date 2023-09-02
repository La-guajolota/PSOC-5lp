
#include "project.h"
#include <stdio.h>

int main(void)
 {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Variables para filtros
    int16 cont=0,ventana = 15;
    int16 suma = 0;
    
    //variables para el ADC
    int16 lec_binaria,lec_Volts;
    char8 Filtrado[4], NoFiltrado[4];//4 caracteres numéricos
    int16 array[ventana];//Inicializamos el array en 0
    
    UART_Start();
    ADC_Start();
    ADC_StartConvert();
    
    for(;;)
    {
        
        while(cont<ventana){
            
            if(ADC_IsEndConversion(0x00u)){//Verifica que se haya terminado una converción
           
                lec_binaria = ADC_GetResult16();//Recupera valor en el regisrtro del SAR
                lec_Volts = ADC_CountsTo_mVolts(lec_binaria);//Hace converción a mV
                
                //Enviamos lectura con ruido
                sprintf(NoFiltrado,"%d", lec_Volts);
                UART_PutChar('R');//Mandamos un espacio de caractier para separar
                UART_PutString(NoFiltrado);
                UART_PutChar('r');//Mandamos un espacio de caractier para separar
                
                //Agregamos resultado al array
                array[cont] = lec_Volts;

                //Sumamos al contador por cada dato que recuperemos
                cont++;
            }
            
        }cont=0;
        
        //Sacamos suma y promedio de la ventana. Aplicamos el filtro
        suma=0;  
        for(int i=0; i<ventana ;i++){
            suma += array[i]/ventana;
        }
        
        //Convertimos a char para ponerlo en un array de char
        sprintf(Filtrado,"%d",suma);
        
        UART_PutChar('F');//Mandamos un F de caractier para separar
        UART_PutString(Filtrado);//Mandamos la info ya filtrada     
        UART_PutString("f\r\n");//fin de la trama    
    }    
}

/* [] END OF FILE */
