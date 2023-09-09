/*

*/
#include <stdint.h>

//Variables de control
#define resolucion 8 //Modifica segun la resolucpon del pwm

//Mascaras de inputs por los botones 
#define Vmenos 0x1E
#define Vmas 0x1D
#define Der 0x1B
#define Izq 0x17
#define Paro 0x0F

//Mascaras para control
/*
    Del registro de cotnrol en 8bit s¿tomamos solo los 3 menos significantes
    
    De las combinacion necesarios para controlar el sentido de rotación por parte del integrado
    L293B como driver de los relays y del Mostfet que controla la velocidad del motor
    
    Contrl del sentido de giro *DEBIDO A LOS OPTOACOPLADORES ESTO ES LÓGICA NEGADA
    2A|1A|EN
    0  1  0  --> Gira derecha  2A-ON 1A-OFF
    1  0  0  --> Gira Izquierda 1A-ON 1A-OFF
    1  1  0  --> Paro a medias  1A=2A=ON
    0  0  1--> Paro total EN pone en altaimpedancia las salidad del L293B *2A Y 1A SON DONT CARE REALMENTE
 */
#define Derecha 0x02
#define Izquierda 0x04
#define paro_medio 0x06
#define paro_total 0x01

//Función para cambio de giro
/*
    Protocólo para el cambio de dirección:
    1-. (DISMINUIR VELOCIDAD GRADUALMENTE) luego Paro a total
    2.- Paro medio
    3.- Nueva dirección luego(AUMENTA LA VELOCIDAD HASTA ALCANZAR LA ANTERIOR AL REALIZAR EL CAMBIO DE SENTIDO)
*/
void SENTIDO(uint8_t Estado);

//Función para modificar la velocidad
void Velocidad(uint8_t porcentaje);
