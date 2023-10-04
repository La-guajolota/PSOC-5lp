#include "project.h"
#ifndef PSOC_LCD
#define PSOC_LCD

///////////////////////////////////////////////
/* LCD (16x2 or 20x4) */
///////////////////////////////////////////////

void LCD_Start(void);//INICIALIZA LA LCD EN MODO DE 4bits
void LCD_ClearDisplay(void); //limpia la pantalla
void LCD_Position(unsigned char row, unsigned char column);//Te posiciona en la matriz el cursor
//Funciones para la escritura de info
void LCD_PrintHex8(unsigned int hex8);
void LCD_PrintHex16(unsigned short hex16);
void LCD_PrintHex32(unsigned long hex32);
void LCD_PrintNumber(unsigned long value);
void LCD_PrintString(char const string[]);
void LCD_PutChar(char character);

#endif