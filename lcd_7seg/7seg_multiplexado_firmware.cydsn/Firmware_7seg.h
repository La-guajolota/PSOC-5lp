#include "project.h"

//Mascaras de bits
#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80

//Registro que almacena el código BCD correspondiente de cada dídigot
/*
      Millar    Centenas    Decenas     Unidades
    0bxxxx      xxxx        xxxx        xxxx
*/
uint8_t DIGITOS[4];// 

//*******FUNCIONES********

//Funion para separar los digits del numero entregado
//Lo colocamos en los registros
void Separa_digitos(uint16_t num);

//cODIFICADOR BCD--->>7SEGMENTOS
void BCD_CODIFIG(uint8_t BCD);

//Sellecion de displaypor el multiplexado
void MUX(uint8_t DIG);