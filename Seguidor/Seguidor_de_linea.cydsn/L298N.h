/*
    Librería para controlar motores dc en L298N
*/

/*
    En un registro de control para las entradas de un L298N
    ENx | IN_1 | IN_2
     0  |  x   |  x    MOOTORx OFF
     1  |  0   |  0    MOTORx freno
     1  |  0   |  1    MOTORx atras
     1  |  1   |  0    MOTORx frente
     1  |  1   |  1    MOTORx freno
*/

//Combinaciones de la tabla de verdad por un MOTOR
#define freno 0x04
#define atras 0x05
#define frente 0x06
#define OFF    0x00

//Combinaciones de la direcciones que puede tomar el seguidor 2 MOTORES
/*
                            MOTOR_b       MOTOR_a
                            00000|||||||||ooooooo
                            OOOOO|       |OOOOOOO
                            OOOOO|       |OOOOOOO
                                 |       |
                                 |       |
                                 |||||||||
        
    En un registro de control
    8bits -->> x | x | ENB | IN_3 | IN_4| ENA | IN_1 | IN_2 
*/
#define GO 0x36     //MB freno MA frente
#define BACK 0x2D   //MB atras MA atras
#define BREAK 0x24  //MB paro MA paro
#define RIGHT 0x34  //MB frente MA par0
#define LEFT  0x26  //MB paro MA frente

