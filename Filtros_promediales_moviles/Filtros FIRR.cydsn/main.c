/* ========================================
    Filtros de media movil y de media movil con pesos espoinenciales
 * ========================================
*/
#include "project.h"
#include <stdint.h>

uint8 retMode = 0;//Argumento de api del ADC
int16 lectura = 0;//Lectura del adc
int16 ADC_out = 0;//Suma de la ventana para aplicar el filtros FIR

//longitud de la ventana PARA FILTRO-FIR

int valores[] = {0,0,0,0,0};//Array de la ventana
int pesos[] = {1,1,1,1,1};//pesos calulados dependiendo del filtro

int main(void)
{
    char VENTANA = 5;
    char cont = 0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    //Inicializamos la Uart
    UART_Start();
    //Inicializamos el ADC
    ADC_Start();
    ADC_StartConvert();
    
    //Mandamos saludo de inicialización
    UART_PutString("Hola soy tu psoc Y te voy a mandar lectura del adc filtrado y sin filtrar \n \n");
    
    for(;;)
    {
              
        while(cont<VENTANA){//Salimos del bucle hasta tener n lecturas segun nuestra ventana
            
            if(ADC_IsEndConversion(retMode)){//Checamos si alguna converción a terminado
                
                int16 adc_raw = ADC_GetResult16();//Optenemos lectur adc raw
                lectura = ADC_CountsTo_Volts(adc_raw);//Convertimos a V con puntro decimal
           
                cont++;//Agregamos al contador
            }
        }
        cont = 0; //Seteamos el contador para realizar depsues el siguiente lote de lecturas       
        

        
    }
}

/* [] END OF FILE */
