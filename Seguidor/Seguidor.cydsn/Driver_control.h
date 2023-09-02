#include <stdio.h>

//Varibles para el control de direcciones
#define Ma 0 //Motor A
#define Mb 1 //Motor B
/*

    EN|1A|2A
    1 |0 |1     #define Derecha 0x05
    1 |1 |0     #define Izquierda 0x06
    1 |0 |0     #define Paro_seco 0x04
    0 |X |X     #define Paro_Z  0xFB
    
    Para el segndo motor hay que sumar para optener la máscara correcta
    
    Registro de ontrol que es de 8bit los ultimos dos más significantes no importan
    x |x |A  |B  |C   |a  |b  |c
    . .   2B |1B |ENb |2A |1A |ENa      Estos son los pines de Control del ic L293b
*/
//Máscara de direcciones MA
#define Paro_Z_MA  0xFB
#define Paro_seco_MA 0x04
#define Izquierda_MA 0x06
#define Derecha_MA 0x05
//Máscara de direcciones MB Son las mismas pero recorridas 3 bits a la izquierda
#define Paro_Z_MB  0xDF
#define Paro_seco_MB (Paro_seco_MA << 3)
#define Izquierda_MB (Izquierda_MA << 3)
#define Derecha_MB (Derecha_MA << 3)

//Funcion para el ontrol de direion de los motores
uint8_t Dir_Motor(uint8_t Dir, uint8_t Motor, uint8_t REG);

//Subfuncion de la misma librería
uint8_t Enmascaramiento_Rec(uint8_t mascara, uint8_t REG, uint8_t Motor);