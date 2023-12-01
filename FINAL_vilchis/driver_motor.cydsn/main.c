#include "project.h"
#include "DRIVER_MOTOR.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    MOTOR_Start();
    
   
    //POTENCIA(37);
    
   
    for(;;)
    {
        
        for(uint8_t i=0;i<=254;i++){
            POTENCIA(i);
            CyDelay(100);
        }
        CyDelay(3000);
        for(uint8_t i=254;i<=170;i++){
            POTENCIA(i);
            CyDelay(100);
        }
        CyDelay(3000);
        for(uint8_t i=170;i>30;i--){
            POTENCIA(i);
            CyDelay(600);
        }
        CyDelay(3000);
    }
}


