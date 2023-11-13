#include "project.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"

#ifndef MAX6675_H
#define MAX6675_H

//Macros para enmascarar
/*
   TRAMA DE SALIDA SERIAL DEL SENSOR:
    BIT15 --> Dummy sign bit
    BIT14-BIT3 -->Temperatur Reading  MSB->>LSB
    BIT2 --> Thermocouple input
    Bit1 --> Device ID
    Bit0 --> State
¨*/
#define DUMMY 0x8000 //Siempre = 0
#define Th_input 0x04 // =0 Con cupla =1 Sin cupla
#define READING 0x7FF8 // unos en los bits en donde se tiene la temperatira
#define ID 0X02 // ID=0  
 
// Definimos la estructura para almacenar los datos del sensor    
struct max6675_data {
	uint16_t palabra;
    uint8_t errores;
    
    uint16_t temperatura;
    float temperatura_decimal;
};

// Definimos una estructura que agrupa el sensor y sus datos
struct max6675 {
    struct max6675_data data;
};

//Optenemos la palabra que escupe el integrado
void SENS_max6675(struct max6675* sensor);

#endif