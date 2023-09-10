#include "project.h"

//Máscaras de bits
#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80

//bits de direccion para el registro de control
#define PAR 0X01
#define IZQ 0x02
#define DER 0x04

//Función para realizar un corrimiento (Tomar una dirección y efectuar avance de rotación)
void Corrimiento(uint8_t DIR);
//Subrutinas de direccion de corrimiento
void derecha();
void izquierda();