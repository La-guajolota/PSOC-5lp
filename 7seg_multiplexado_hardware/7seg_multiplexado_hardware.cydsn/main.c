#include "project.h"
#include "Display_librerria.h"

uint16_t num=0;
char bandera=0x00;

//Rutina de interrupcion
CY_ISR(isr_1){//Paro/inicio
    isr_1_ClearPending();
    bandera ^= BIT0;//Habilitamos el conteo
}
CY_ISR(isr_2){//reset
    isr_2_ClearPending();
    num=0;//Seteamos el cronometro 
    
    //Actualizamos en el display
    Separa_digitos(num);  
}



int main(void)
{
    CyGlobalIntEnable;
    //Activamos y limpiamos las interrupcione
    isr_1_StartEx(isr_1);
    isr_1_ClearPending();
    isr_2_StartEx(isr_2);
    isr_2_ClearPending();
    
    for(;;)
    {

        if(bandera){
            //Simulamos el segundo de conteo
            CyDelay(10);//segundo 1
            if(num < 9999){
                //Actualizamos en el display
                Separa_digitos(num);   
                num++;
            }else{
                num=0;
            }
        }
        
    }
}
