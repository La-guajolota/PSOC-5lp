#include "project.h"
#include "STEPM.h"

//Secuencia para realizar un paso
uint8_t secuencia[8]={
    0x08,
    0x0C,
    0x04,
    0x06,
    0x02,
    0x03,
    0x01,
    0x09,
};


//Función para realizar un corrimiento (Tomar una dirección y efectuar avance de rotación)
void Corrimiento(uint8_t DIR){
    
    switch (DIR){
        case PAR:
            STEP_MOTOR_driver_Write(0x00);
            break;
        case IZQ:
            izquierda();
            break;
        case DER:
            derecha();
            break;
    }
    
};
//Subrutinas de direccion de corrimiento
void derecha(){
    for(int i=0;i<7;i++){
        STEP_MOTOR_driver_Write(secuencia[i]);
        CyDelay(5);
    }
};
void izquierda(){
    for(int i=7;i>0;i--){
        STEP_MOTOR_driver_Write(secuencia[i]);
        CyDelay(5);
    }
};