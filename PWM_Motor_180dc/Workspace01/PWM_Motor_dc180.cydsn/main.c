#include "project.h"

//Variables de control
#define Max_count 255 //Resolución del PWM
uint8 Potencia = 100;
uint8 Reg_botones = 0x00;
uint8 CMP = 0;

//Función para hacer converción de potencia porcentual a
//su correspondiente valor en CMP
uint8 Potencia_CMP(uint8 potencia){
    
    //Converción de potencia en porcentaje a CMP
    CMP = (potencia)*Max_count/100;

    return CMP;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Iniciamos perifericos para este proyecto
    PWM_Start();
    LED_Drive_Start();
    
    LED_Drive_Write7SegNumberDec(CMP,0,4,0);//Inicializamos la potencia 0
    PWM_WriteCompare(0x00);
    
    for(;;)
    {
        //Capturamos el registro de estado
        Reg_botones = Botones_Read();
        
        //Verificamos que hubo una interración con los botones de control
        if(Reg_botones != 0x03){
            
            //Las condicionales es para prevenir que se salga se 0%<->100%
            switch(Reg_botones){
                case 0x01:
                      if(Potencia<100){
                        Potencia++;//Aumentamos potencia
                    }
                      break;
                case 0x02:
                      if(Potencia>0){
                        Potencia--;//Disminuimos potencia
                    }
                      break;
            }
            
            //Actualizamos CMP del PWM
            CMP = Potencia_CMP(Potencia);//Hacemos converción
            PWM_WriteCompare(CMP);//Actualizmaos potencia en PWM
            LED_Drive_Write7SegNumberDec(Potencia,0,4,0);//Actualizamos la potencia actual en el motor
            CyDelay(25);     
        }
        
        
    }
}


