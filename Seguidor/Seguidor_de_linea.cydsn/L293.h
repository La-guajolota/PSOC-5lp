/*
    EN|1A|2A
    1 |0 |1     #define Derecha 0x05
    1 |1 |0     #define Izquierda 0x06
    1 |0 |0     #define Paro_seco 0x04
    1 |1 |1     #Paro_SECO2  0x07
    0 |X |X     #define Paro_Z  0x00
    
    Para el segndo motor hay que sumar para optener la máscara correcta
    
    Registro de control que es de 8bit los ultimos dos más significantes no importan
    x| |x |bit5  |bit4  |bit3   |bit2  |bit1  |bit0
    . .    ENb   |B1    |B2    |ENa    |A1    |A2      Estos son los pines de Control del ic L293b
*/

//Combinaciones de la tabla de verdad por un MOTOR
#define freno 0x04
#define atras 0x06
#define frente 0x05
#define OFF    0x00

//Combinaciones de la direcciones que puede tomar el seguidor 2 MOTORES
/*

                            MOTOR_b       MOTOR_a
                            0000000|||||||||ooooooo
                            ooOOOOO|       |OOOOOOO
                            ooOOOOO|       |OOOOOOO
                                   |       |
                                   |       |
                                   |||||||||
    En un registro de control
    8bits -->> x | x | ENB | IN_3 | IN_4| ENA | IN_1 | IN_2 
*/
#define GO 0x2D  //MB freno MA frente
#define BACK 0x36 //MB atras MA atras
#define BREAK 0x24   //MB paro MA paro
#define RIGHT 0x2C  //MB frente MA par0
#define LEFT  0x25 //MB paro MA frente

//MÁSCARAS PARA HACKS DE GIRO
#define RIGHT_HACK 0X2E //MB frente MA atrás
#define LEFT_HACK 0X35  //MB freno MA atrás