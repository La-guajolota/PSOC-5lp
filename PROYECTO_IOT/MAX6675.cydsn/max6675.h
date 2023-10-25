#include "project.h"

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
#define State 0X01 //Tristate

//Macros de errores
#define dummy 0x01
#define Cupla 0x02
#define id 0x04

//Funciones
uint8_t test(void);//Testea el el sensor

uint16_t sens(void);//Cpatura la última temperatura medida por el sensor

uint16_t raw(void);