#include "PSOC_LCD.h"

/***************************************
*           API Constants
***************************************/

/* LCD & GLCD interface pin */
#define E                               0x10
#define RS                              0x20

/* LCD commands */
#define LCD_DISPLAY_8_BIT_INIT          0x03
#define LCD_DISPLAY_4_BIT_INIT          0x02
#define LCD_DISPLAY_CURSOR_OFF          0x08
#define LCD_CLEAR_DISPLAY               0x01
#define LCD_CURSOR_AUTO_INCR_ON         0x06
#define LCD_DISPLAY_CURSOR_ON           0x0E
#define LCD_DISPLAY_2_LINES_5x10        0x28
#define LCD_DISPLAY_ON_CURSOR_OFF       0x0C
#define LCD_RESET_CURSOR_POSITION       0x03
#define LCD_CURSOR_WINK                 0x0D
#define LCD_CURSOR_BLINK                0x0F
#define LCD_CURSOR_SH_LEFT              0x10
#define LCD_CURSOR_SH_RIGHT             0x14
#define LCD_DISPLAY_SCRL_LEFT           0x18
#define LCD_DISPLAY_SCRL_RIGHT          0x1E
#define LCD_CURSOR_HOME                 0x02
#define LCD_CURSOR_LEFT                 0x04
#define LCD_CURSOR_RIGHT                0x06

/* LCD conversion routines */
#define LCD_NUMBER_OF_REMAINDERS_U32    0x0A
#define LCD_TEN                         0x0A
#define LCD_8_BIT_SHIFT                 8
#define LCD_32_BIT_SHIFT                32
#define LCD_ZERO_CHAR_ASCII             0x30
#define LCD_LETTER_CHAR_ASCII           0x37

/* LCD nibble offset and mask */
#define LCD_NIBBLE_SHIFT                0x04
#define LCD_NIBBLE_MASK                 0x0F

/* LCD Module Address Constants */
#define LCD_ROW_0_START                 0x80
#define LCD_ROW_1_START                 0xC0
#define LCD_ROW_2_START                 0x94
#define LCD_ROW_3_START                 0xD4

/* LCD position control mask */
#define LCD_COLUMN_MASK                 0x0F
#define LCD_ROW_MASK                    0x03

/* Other definitions */
#define LCD_BYTE_UPPER_NIBBLE_SHIFT     0x04
#define LCD_BYTE_LOWER_NIBBLE_MASK      0x0F
#define LCD_U16_UPPER_BYTE_SHIFT        0x08
#define LCD_U16_LOWER_BYTE_SHIFT        0xFF
#define LCD_8_BIT_SHIFT                 8
#define LCD_32_BIT_SHIFT                32


/***************************************
*           Variables
***************************************/

static const char LCD_CodeHex[16] = "0123456789ABCDEF";


/***************************************
*           Functions
***************************************/

/* Function prototypes */
static void LCD_WriteControl(unsigned char cByte);
static void LCD_WriteData(unsigned char dByte);
static void LCD_WriteControlNibble(unsigned char nibble);
static void LCD_WriteDataNibble(unsigned char nibble);

void LCD_Start(void) {    // Funcion de inicializacion del modulo de display (16x2 o 20x4)
    /* INIT CODE */
    CyDelay(80);                                                        /* Delay 40 ms */
    LCD_WriteControlNibble(LCD_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(10);                                                         /* Delay 5 ms */
    LCD_WriteControlNibble(LCD_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(30);                                                        /* Delay 15 ms */
    LCD_WriteControlNibble(LCD_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(2);                                                         /* Delay 1 ms */
    LCD_WriteControlNibble(LCD_DISPLAY_4_BIT_INIT);    /* Selects 4-bit mode */
    CyDelay(10);                                                         /* Delay 5 ms */

    LCD_WriteControl(LCD_CURSOR_AUTO_INCR_ON);    /* Incr Cursor After Writes */
    LCD_WriteControl(LCD_DISPLAY_CURSOR_ON);      /* Turn Display, Cursor ON */
    LCD_WriteControl(LCD_DISPLAY_2_LINES_5x10);   /* 2 Lines by 5x10 Characters */
    LCD_WriteControl(LCD_DISPLAY_CURSOR_OFF);     /* Turn Display, Cursor OFF */
    
    LCD_WriteControl(LCD_CLEAR_DISPLAY);          /* Clear LCD Screen */
    LCD_WriteControl(LCD_DISPLAY_ON_CURSOR_OFF);  /* Turn Display ON, Cursor OFF */
    LCD_WriteControl(LCD_RESET_CURSOR_POSITION);  /* Set Cursor to 0,0 */
    CyDelay(10);
}

void LCD_ClearDisplay(void) {    // Funcion de limpieza total de la pantalla
    LCD_WriteControl(LCD_CLEAR_DISPLAY);
    CyDelay(1);
}

void LCD_Position(unsigned char row, unsigned char column) {    // Funcion de posicionamiento de cursor en pantalla
/*
 * row      -> Fila donde va a empezar a escribir       (0-3)
 * column   -> Columna donde va a empezar a escribir    (0-15)

 * LCD_Position(1,6);
 */
    row = (LCD_ROW_MASK & row);

    switch(row) {
        case 0:
            LCD_WriteControl(LCD_ROW_0_START + column);
            break;
        case 1:
            LCD_WriteControl(LCD_ROW_1_START + column);
            break;
        case 2:
            LCD_WriteControl(LCD_ROW_2_START + column);
            break;
        case 3:
            LCD_WriteControl(LCD_ROW_3_START + column);
            break;
        default:
            break;
    }
}

void LCD_PrintHex8(unsigned int hex8) {    // Funcion de escritura de numero hexadecimal de 8 bits - Funcion de conversion de numero decimal a hexadecimal de 8 bits
/*
 * hex8 -> Numero o variable a imprimir en formato hexadecimal
 *
 * LCD_PrintHex8(0xFE);
 * LCD_PrintHex8(254);
 * LCD_PrintHex8(x);
 */
    LCD_PutChar((char) LCD_CodeHex[hex8 >> LCD_NIBBLE_SHIFT]);
    LCD_PutChar((char) LCD_CodeHex[hex8 & LCD_NIBBLE_MASK]);
}

void LCD_PrintHex16(unsigned short hex16) {    // Funcion de escritura de numero hexadecimal de 16 bits - Funcion de conversion de numero decimal a hexadecimal de 16 bits
/*
* hex16 -> Numero o variable a imprimir en formato hexadecimal
*
* LCD_PrintHex16(0xFFFE);
* LCD_PrintHex16(65534);
* LCD_PrintHex16(x);
*/
    LCD_PrintHex8((unsigned char)(hex16 >> LCD_U16_UPPER_BYTE_SHIFT));
    LCD_PrintHex8((unsigned char)(hex16 & LCD_U16_LOWER_BYTE_SHIFT));
}

void LCD_PrintHex32(unsigned long hex32) {    // Funcion de escritura de numero hexadecimal hasta de 16 bits - Funcion de conversion de numero decimal a hexadecimal hasta de 16 bits
/*
* hex -> Numero o variable a imprimir en formato hexadecimal
*
* LCD_PrintHex32(0xFFFFABCD);
* LCD_PrintHex32(4294945741);
* LCD_PrintHex32(x);
*/
    unsigned char shift = LCD_32_BIT_SHIFT;
    
    while (shift != 0) {
        /* "shift" var is to be subtracted by 8 prior shifting. This implements 
        * shifting by 24, 16, 8 and 0u. 
        */
        shift -= LCD_8_BIT_SHIFT;
        
        /* Print 8 bits of uint32 hex number */
        LCD_PrintHex8((unsigned char) ((unsigned long) (hex32 >> shift)));
    }
}

void LCD_PrintNumber(unsigned long value) {    // Funcion de impresion de numero decimal de 32 bits
/*
 * value -> Numero entero a imprimirse

 * LCD_PrintNumber(5894);
 * LCD_PrintNumber(x);
 */
    unsigned char tmpDigit;
    char number[LCD_NUMBER_OF_REMAINDERS_U32 + 1];
    unsigned char digIndex = LCD_NUMBER_OF_REMAINDERS_U32;
    
    /* This API will output a decimal number as a string and that string will be 
    * filled from end to start. Set Null termination character first.
    */
    number[digIndex] = (char) '\0';
    digIndex--;
    
    /* Load these in reverse order */
    while(value >= LCD_TEN)
    {
        /* Extract decimal digit, indexed by 'digIndex', from 'value' and
        * convert it to ASCII character.
        */
        tmpDigit = (unsigned char) (((unsigned char) (value % LCD_TEN)) + (unsigned char) LCD_ZERO_CHAR_ASCII);
        
        /* Temporary variable 'tmpDigit' is used to avoid Violation of MISRA rule 
        * #10.3.
        */
        number[digIndex] = (char) tmpDigit;
        value /= LCD_TEN;
        digIndex--;
    }
    
    /* Extract last decimal digit 'digIndex', from the 'value' and convert it
    * to ASCII character.
    */
    tmpDigit = (unsigned char) (((unsigned char)(value % LCD_TEN)) + (unsigned char) LCD_ZERO_CHAR_ASCII);
    number[digIndex] = (char) tmpDigit;

    /* Print out number */
    LCD_PrintString(&number[digIndex]);
}

void LCD_PrintString(char const string[]) {    // Funcion de impresion en pantalla de cadena alfanumerica
/*
 * text -> Texto entre comillas a imprimir

 * LCD_PrintString("Hello, World!");
 */
    unsigned char indexU8 = 1;
    char current = *string;

    /* Until null is reached, print next character */
    while((char) '\0' != current)
    {
        LCD_WriteData((unsigned char)current);
        current = string[indexU8];
        indexU8++;
    }
}

void LCD_PutChar(char character) {    // Funcion de impresion de caracter simple
/*
 * character -> Caracter simple a imprimir

 * LCD_PutChar('h');
 * LCD_PutChar(0x68);
 */
    LCD_WriteData((unsigned char)character);
}


// **** FUNCIONES DE DISEÑO PROPIO EN CLASE ***//
/*

De la referecnia de : https://github.com/LaSalleBajio-FIT/design-mpu/blob/main/source/ejemplos/LCD/Texas_DevBoard.c

static void LCD_WriteControl(unsigned char cByte) {
    static unsigned char nibble;

    //delay_ms(10); // 10
    nibble = cByte >> LCD_NIBBLE_SHIFT;

    // Escribir nibble m�s significativo 
    LCD_WriteControlNibble(nibble);
    nibble = cByte & LCD_NIBBLE_MASK;

    // Escribir nibble menos significativo
    LCD_WriteControlNibble(nibble);
    //delay_ms(5); // 5
}
static void LCD_WriteData(unsigned char dByte) {
    static unsigned char nibble;

    //delay_ms(10); // 10
    nibble = dByte >> LCD_NIBBLE_SHIFT;

    // Escribir nibble m�s significativo
    LCD_WriteDataNibble(nibble);
    nibble = dByte & LCD_NIBBLE_MASK;

    // Escribir nibble menos significativo
    LCD_WriteDataNibble(nibble);
    //delay_ms(5); // 5
}
static void LCD_WriteControlNibble(unsigned char nibble) {
    static unsigned char dPort = 0x00;

    dPort = (nibble << LCD_NIBBLE_SHIFT);
    dPort &= (~RS);

    P4OUT = (dPort | 0x03);
    P4OUT |= E;
    delay_ms(2);    // 2
    P4OUT &= (~E);
}
static void LCD_WriteDataNibble(unsigned char nibble) {
    static unsigned char dPort = 0x00;

    dPort = (nibble << LCD_NIBBLE_SHIFT);
    dPort |= RS;

    P4OUT = (dPort | 0x03);
    P4OUT |= E;
    delay_ms(2);    // 2
    P4OUT &= (~E);
}

*/


/*

                REGISTRO DE SALIDA AL LCD
    
    Las X son dont' care    RW--> 0 constante   
    BIT7 BIT8 BIT7 BIT6 BIT5 BIT4 BIT3 BIT2 BIT1 BIT0
       X    X    X   RW   RS    E   D7   D6   D5   D4

*/
//Rutinas de escitura en los registros de instrucciones y de datos
static void LCD_WriteControl(unsigned char cByte) {
    // CYBYTE = 0xABCDEFGH
    static unsigned char nibble;

    //CyDelay(10); // 10
    nibble = cByte >> LCD_NIBBLE_SHIFT; // 0Xabcdefg << 4 --> nimble = 0X0000abcd

    // Escribir nibble m�s significativo 
    LCD_WriteControlNibble(nibble);//ALGORITMO PARA ESCRIBIRLE AL LCD UN COMANDO
    nibble = cByte & LCD_NIBBLE_MASK; // 0Xabcdefg AND 0x0F  --> nimble = 0X0000efgh

    // Escribir nibble menos significativo
    LCD_WriteControlNibble(nibble);//ALGORITMO PARA ESCRIBIRLE AL LCD UN COMANDO
    //CyDelay(5); // 5

}

static void LCD_WriteData(unsigned char dByte) {
    // CYBYTE = 0xABCDEFGH
    static unsigned char nibble;

    //CyDelay(10); // 10
    nibble = dByte >> LCD_NIBBLE_SHIFT;// abcdefg << 4 --> nimble = 0000abcd

    // Escribir nibble m�s significativo
    LCD_WriteDataNibble(nibble);//ALGORITMO PARA ESCRIBIRLE AL LCD INFO
    nibble = dByte & LCD_NIBBLE_MASK; // abcdefg AND 0x0F  --> nimble = 0000efgh

    // Escribir nibble menos significativo
    LCD_WriteDataNibble(nibble);//ALGORITMO PARA ESCRIBIRLE AL LCD INFO
    //CyDelay(5); // 5

}



//Subrutinas de escitura en los registros de instrucciones y de datos
static void LCD_WriteControlNibble(unsigned char nibble) {//RS=0
    
    //PASO1
    nibble &= ~RS;
    LCD_Write(nibble);//RW es 0 constante
    
    //PASO2
    nibble |= E;
    LCD_Write(nibble);//E=1
    CyDelay(2);    // 2
    nibble &= (~E);
    LCD_Write(nibble);//E=0
}

static void LCD_WriteDataNibble(unsigned char nibble) {//RS=1
    
    //PASO1
    nibble |= RS;
    LCD_Write(nibble);//RW es 1 constante
    
    //PASO2
    nibble |= E;
    LCD_Write(nibble);//E=1
    CyDelay(2);    // 2
    nibble &= (~E);
    LCD_Write(nibble);//E=0
}