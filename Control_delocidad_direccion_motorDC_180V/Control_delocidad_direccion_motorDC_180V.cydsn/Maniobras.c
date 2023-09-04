/*


*/
#include <stdint.h>
#include "Maniobras.h"
#include "project.h"

//Función para cambio de giro
/*
    Protocólo para el cambio de dirección:
    1-. (DISMINUIR VELOCIDAD GRADUALMENTE) luego Paro a medias
    2.- Paro total
    3.- Nueva dirección luego(AUMENTA LA VELOCIDAD HASTA ALCANZAR LA ANTERIOR AL REALIZAR EL CAMBIO DE SENTIDO)
*/
void SENTIDO(uint8_t Estado){
    
    //LEEMOS CÓMO SON LAS SALIDAS ACTUALES
     uint8_t Reg = Driver_RELAY_Read();
    
    //PASO UNO!!!!
    //Deminuimos la velocidad
    
    //Enmascaramos
    Reg |= paro_medio;
    Driver_RELAY_Write(Reg);//Actualizamos
    CyDelay(10);
    
    //PASO DOS!!!!
    Reg |= paro_total;
    Driver_RELAY_Write(Reg);//Actualizamos
    CyDelay(10);
    
    //PASO TRES!!!
    Reg &= Estado;
    Driver_RELAY_Write(Reg);//Actualizamos
    CyDelay(10);
    
    //Subimos velocidad antes del cambio de estado
    
}

//Función para modificar la velocidad

//Función paro