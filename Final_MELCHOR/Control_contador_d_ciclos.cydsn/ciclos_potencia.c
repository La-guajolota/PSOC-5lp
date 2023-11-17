#include "ciclos_potencia.h"

uint16_t ON_ciclos(float p){

    uint16_t on = map(p,0,100,0,65535);
    
    return on;
}