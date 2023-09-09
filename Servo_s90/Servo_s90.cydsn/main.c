#include <stdint.h>
#include "project.h"
#include "Lib_servo.h"

//Variables globales 
uint16_t cpp, angulo=0;
char bandera = 0x00;//bandera de interrupcion


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Inicializamos perifericos
    PWM_Start();
    LED_Grados_Start();
   
    /*
    //Para debuguear
    for(int i=0; i<=180; i+=45){
        cpp = Ang_Per(i);
        PWM_WriteCompare(cpp);
        CyDelay(1000);
    }
    */
    
    cpp = Ang_Per(angulo);//Actualizamos el capture compare del pwm 
    PWM_WriteCompare(cpp);//y cambiamos el DUTYCYCLE
    
    for(;;)
    {
     
        //Chcamos cual se activo
        uint8_t reg_btn = Reg_btn_Read();
        
        if(reg_btn != 0x00){//Se precionó un boton?
            bandera++;
            
            switch(reg_btn)
            {
                case 0x01:
                    if(angulo<=179){
                        angulo++;                       
                    }
                    break;
                case 0x02:
                    if(angulo>=1){
                        angulo--;
                    }
                    break;
            }
        }
        
        if(bandera){//Revisamos la bandera
            
            cpp = Ang_Per(angulo);//Actualizamos el capture compare del pwm 
            PWM_WriteCompare(cpp);//y cambiamos el DUTYCYCLE
            LED_Grados_Write7SegNumberDec(angulo,0,4,0);
            CyDelay(10);//Tiempo de cambio entre posición
            
            bandera=0x00;//Reseteamos la bandera
        }
        
       
    }
}
