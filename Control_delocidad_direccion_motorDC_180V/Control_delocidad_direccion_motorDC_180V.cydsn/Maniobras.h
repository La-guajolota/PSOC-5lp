/*


*/
#include <stdint.h>

//Variables de control


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
    1  1  1  --> Paro total EN pone en altaimpedancia las salidad del L293B *2A Y 1A SON DONT CARE REALMENTE
 */
#define Derecha 0x02
#define Izquierda 0x04
#define paro_medio 0x06
#define paro_total 0x07

//Función para cambio de giro
/*
    Protocólo para el cambio de dirección:
    1-. (DISMINUIR VELOCIDAD GRADUALMENTE) luego Paro a medias
    2.- Paro total
    3.- Nueva dirección luego(AUMENTA LA VELOCIDAD HASTA ALCANZAR LA ANTERIOR AL REALIZAR EL CAMBIO DE SENTIDO)
*/
void SENTIDO(uint8_t Estado);

//Función para modificar la velocidad
uint16_t Velocidad(uint16_t porcentaje);
