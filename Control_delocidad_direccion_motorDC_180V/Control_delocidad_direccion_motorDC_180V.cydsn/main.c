
#include "project.h"
#include "Maniobras.h"


//Variables globales
uint8_t mando;//Contiene los estados de las entradas de control

int main(void)
{
    CyGlobalIntEnable;
    PWM_Mosfet_Start();
    PWM_Mosfet_WriteCompare(0x00);//Reteamos velocidad a 0
    LED_VELOCIDAD_Start();    
    
    for(;;)
    {
      //checamos el registro de control
       mando = Control_manual_Read();
       
       //Existió algún cambio del registro con su estado normal??
        
      //Evaluamos la acción a tomar
        
    }
}


