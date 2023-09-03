#include <stdint.h>
#include "project.h"
#include "Lib_servo.h"

//Variables globales 
uint8_t cpp, angulo=0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Inicializamos perifericos
    PWM_Start();
    Reg_btn_InterruptEnable();    
    
    for(;;)
    {
        
    }
}
