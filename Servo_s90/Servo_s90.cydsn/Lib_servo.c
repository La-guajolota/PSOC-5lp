/*
    Funciones para el control de un servo de 0 a 180 grados de libertad
    por medio de dos botones, uno para aumentar y otro para disminuir la
    posición del bastago 

    Segun la hoja de datos 500-2400 µs es el rango del pulso
*/
#include <stdio.h>
#include <stdint.h>

//Convierte del angulo solicitado a el duty cycle necesario de 1ms-2ms
uint16_t Ang_Per(uint16_t angulo){
    
    //Hacemos primero la converción de angulo a periodo
    /*
     Periodo      Angulo     |  representacion en tipo de dato uint16_t
        0.5ms    -->    0     |  0d500  
        1.45ms   -->   90    |  0d1450  
        2.4ms    -->  180    |  0d2400  
    */
   float aux = angulo*(19.0/1800)+0.5;
    uint16_t periodo = 1000*aux; //Se le multiplica por un factor de 100 por la resolucion del tipo de dato COMODIDAD
    
    //Hacemos la convercion ahora al valor de coparación para el pwm
    /*
        El servo funciona a una definicion de 16 bits a 50hz. Esto pues al quererse 
        180 grados de libertad se tiene que 1grado --> 1/36% en dutycycle,
        siendo entonce que:
                            1/36% = 100*(1/Conteo_maximo_pwm)
                Conteo_maximo_pwm = 3600 conteos

        Por lo que hay un conteo posible va de 0 a 3600
        
        Periodo       Duty Cycle   |  representacion en tipo de dato uint16_t
            0.5ms  -->      5/2%   |  90/3600  
            1.45ms -->     29/4%   |  261/3600 
            2.4ms   -->      12%   |  432/3600   
                            
    */
    uint16_t ccp = 0.18*periodo;
    
    return ccp;
}