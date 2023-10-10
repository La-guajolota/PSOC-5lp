#include "project.h"
#include "stdio.h"
#include "max6675.h"

int main(void)
{
    CyGlobalIntEnable;
    UART_Start();
    UART_ClearTxBuffer();
    SPIM_Start();
    
    //Variables
    uint16_t temp=0;//Variable alamacena la temperatura 
    char lec[32];//Buffer a mostrar en pantalla
    
    //sprintf(lec,"Estado del bit tests %d \n\r",error);
    //UART_PutString(lec);
    //CyDelay(5000);
    for(;;)
    {
        //Sensamos
        temp = raw();
        
        //Un segundo de poleo
        CyDelay(500);
        
        //Mostramos 
        //sprintf(lec,"Temperatura: %d degC\n\r",temp);
        sprintf(lec,"%d\n\r",temp);
        UART_PutString(lec);
    }
}


