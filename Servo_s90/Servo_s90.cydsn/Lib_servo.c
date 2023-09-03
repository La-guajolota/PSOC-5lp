/*
    Funciones para el control de un servo de 0 a 180 grados de libertad
    por medio de dos botones, uno para aumentar y otro para disminuir la
    posición del bastago 
*/

#include <stdint.h>
#include "Lib_servo.h"

//Convierte del angulo solicitado a el duty cycle necesario de 1ms-2ms
uint8_t Ang_Per(uint8_t angulo){
     
    //Hacemos primero la converción de angulo a periodo
    /*
     Periodo      Angulo  |  representacion en tipo de dato uint8_t
        1ms   -->    0    |  100
        1.5ms -->   90    |  150
        2ms   -->  180    |  200
    */
    uint8_t periodo = 100*((angulo/180)+1); 
    
    //Hacemos la convercion ahora al valor de coparación para el pwm
    /*
        El servo funciona a una definicion de 8 bits a 50hz aprox
        Por lo que hay un conteo posible de 0 a 255 cada 5.1 segundos
        
        Periodo       Duty Cycle   |  representacion en tipo de dato uint8_t
            1ms   -->      5%      |  12.75/255  redondeado a 13/255
            1.5ms -->      7.5%    |  19.125/255 redondeado a 19/255
            2ms   -->      10%     |  25.5/255   redondeado a 25/255
    */
    uint8_t ccp = (12/100)*periodo + 1;
    
    return ccp;
}