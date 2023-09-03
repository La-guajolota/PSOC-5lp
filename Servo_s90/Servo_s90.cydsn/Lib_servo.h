/*
    Funciones para el control de un servo de 0 a 180 grados de libertad
    por medio de dos botones, uno para aumentar y otro para disminuir la
    posición del bastago 
*/

#include <stdint.h>

//Convierte del angulo solicitado a el duty cycle necesario de 1ms-2ms
uint16_t Ang_Per(uint16_t anglulo);