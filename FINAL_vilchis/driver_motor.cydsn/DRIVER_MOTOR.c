#include "DRIVER_MOTOR.h"

void POTENCIA(uint8_t P){
    
    uint16_t out;
    
    //Clipping de la potencia del motor
    if(P>254){
        P=100;
    }
    if(P<=0){
        P=0;
    }
    
    //1ms - 2.3ms
    out = map(P,0,254,3000,6900);
   
    MOTOR_WriteCompare(out);//Actualizamos la potencia del motor
}