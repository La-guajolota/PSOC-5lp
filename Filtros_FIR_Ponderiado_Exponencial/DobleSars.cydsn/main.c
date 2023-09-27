#include "project.h"
#include "stdio.h"// IO en general *sprintf*
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"


char buffer_Tx[3];     // Buffer para transmisión de datos UART
uint16_t raw_ADC;       // Variable para almacenar lecturas ADC

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //Activamos los periféricos
    UART_Start();          
    ADC_1_Start();
    ADC_2_Start();            
    ADC_1_StartConvert();
    ADC_2_StartConvert(); 

    for(;;)
    {
        //LECTURA PRIMER SENSADO
        raw_ADC = ADC_1_GetResult16();// Leer valor del ADC_2
        raw_ADC = map(raw_ADC, 0, 4095, 0, 255);//Comprimimos de 16bits a 8bits
        sprintf(buffer_Tx,"%d",raw_ADC);
        UART_PutChar('R');
        UART_PutString(buffer_Tx);//Enviamos dato
        UART_PutChar('r');
        
        //LECTURA SEGUNDO SENSADO
        raw_ADC = ADC_2_GetResult16();// Leer valor del ADC_2
        raw_ADC = map(raw_ADC, 0, 4095, 0, 255);//Comprimimos de 16bits a 8bits
        sprintf(buffer_Tx,"%d",raw_ADC);
        UART_PutChar('F');
        UART_PutString(buffer_Tx);//Enviamos dato
        UART_PutString("f\r\n");//fin de la trama
        
        CyDelay(50); 
    }
}


