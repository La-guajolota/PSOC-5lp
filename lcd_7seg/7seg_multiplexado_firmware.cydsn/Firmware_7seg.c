#include "Firmware_7seg.h"
/*
    La funcion separa los digitos de un número
                            BCD codificación por default
    F(1342) ->>> Millares:1  
                 Centenas:3
                 Decenas: 4
                 Unidades 2
                
    1342 ->> 0b0000010100111110     En BCD  0001 0011 0100 0010
                                             1      3    4    2
    
                                            
    Y almacena los resultados en el registro de DIGITOS
*/
void Separa_digitos(uint16_t num){ 
    
    uint8_t digm,digc,digd,digu;
    
    //Conseguimos los dígitos en BCD
    digm = num / 1000;        // Obtén el primer dígito (miles)
    digc = (num / 100) % 10;  // Obtén el segundo dígito (centenas)
    digd = (num / 10) % 10;   // Obtén el tercer dígito (decenas)
    digu = num % 10;          // Obtén el cuarto dígito (unidades)    
    
    //Le metemos los digitos a la variable SEGMENTOS
    DIGITOS[0] = digm;
    DIGITOS[1] = digc;
    DIGITOS[2] = digd;
    DIGITOS[3] = digu;
}

//cODIFICADOR BCD--->>7SEGMENTOS
void BCD_CODIFIG(uint8_t BCD){

    //  0b XSSSS SSSS
    switch (BCD) {
        case 0x00: // 0
            Segmentos_7seg_Write(0x3F); // Código hexadecimal para el dígito 0 en 7 segmentos
            break;
        case 0x01: // 1
            Segmentos_7seg_Write(0x06); // Código hexadecimal para el dígito 1 en 7 segmentos
            break;
        case 0x02: // 2
            Segmentos_7seg_Write(0x5B); // Código hexadecimal para el dígito 2 en 7 segmentos
            break;
        case 0x03: // 3
            Segmentos_7seg_Write(0x4F); // Código hexadecimal para el dígito 3 en 7 segmentos
            break;
        case 0x04: // 4
            Segmentos_7seg_Write(0x66); // Código hexadecimal para el dígito 4 en 7 segmentos
            break;
        case 0x05: // 5
            Segmentos_7seg_Write(0x6D); // Código hexadecimal para el dígito 5 en 7 segmentos
            break;
        case 0x06: // 6
            Segmentos_7seg_Write(0x7D); // Código hexadecimal para el dígito 6 en 7 segmentos
            break;
        case 0x07: // 7
            Segmentos_7seg_Write(0x07); // Código hexadecimal para el dígito 7 en 7 segmentos
            break;
        case 0x08: // 8
            Segmentos_7seg_Write(0x7F); // Código hexadecimal para el dígito 8 en 7 segmentos
            break;
        case 0x09: // 9
            Segmentos_7seg_Write(0x6F); // Código hexadecimal para el 9 en 7 segmentos
    }
};

//