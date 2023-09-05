/*

*/
#include <stdint.h>
#include "Maniobras.h"
#include "project.h"

//Función para cambio de giro
/*
    Protocólo para el cambio de dirección:
    1-. (DISMINUIR VELOCIDAD GRADUALMENTE) luego Paro a total
    2.- Paro media
    3.- Nueva dirección luego(AUMENTA LA VELOCIDAD HASTA ALCANZAR LA ANTERIOR AL REALIZAR EL CAMBIO DE SENTIDO)
    
    Del registro de cotnrol en 8bit s¿tomamos solo los 3 menos significantes
    
    De las combinacion necesarios para controlar el sentido de rotación por parte del integrado
    L293B como driver de los relays y del Mostfet que controla la velocidad del motor
    
    Contrl del sentido de giro *DEBIDO A LOS OPTOACOPLADORES ESTO ES LÓGICA NEGADA
    2A|1A|EN
    0  1  0  --> Gira derecha  2A-ON 1A-OFF
    1  0  0  --> Gira Izquierda 1A-ON 1A-OFF
    1  1  0  --> Paro a medias  1A=2A=ON
    0  0  1  --> Paro total EN pone en altaimpedancia las salidad del L293B *2A Y 1A SON DONT CARE REALMENTE
*/
void SENTIDO(uint8_t Estado){
    
    //LEEMOS CÓMO SON LAS SALIDAS ACTUALES
     uint8_t Reg = Driver_RELAY_Read();
    
    //PASO UNO!!!!
    //Deminuimos la velocidad
    uint16_t CPP_1 = PWM_Mosfet_ReadCompare();//leemos cpp del momento
    for(int i=CPP_1;i>0;i--){
        PWM_Mosfet_WriteCompare(i);
        CyDelay(10
        );//Pocura el cambio no tan de golpe
    }
    
    //Enmascaramos
    Reg |= paro_total;
    
    //PASO DOS!!!!
    Reg |= paro_medio;
    
    //PASO TRES!!!
    Reg &= Estado;
    Driver_RELAY_Write(Reg);//Actualizamos
    CyDelay(10);
    
    //Subimos velocidad antes del cambio de estado
    uint16_t CPP_2 = PWM_Mosfet_ReadCompare();//leemos cpp del momento velocidad lenta
    for(int i=CPP_2;i<CPP_1;i++){
        PWM_Mosfet_WriteCompare(i);
        CyDelay(10);//Pocura el cambio no tan de golpe
    }
}

//Función para modificar la velocidad
/*
    El control de velocidad va de 0 a 100
    1.- Calculamos el conteo que representa la velocidad deaseada
    2.- Checamos la velocidad actual 
    3.- Evaluamos si tenemos que acelerar o desacelerar
    3.-ACTUAMOS SEGÚN EL RESULTADO DE 3.-
*/
void Velocidad(uint8_t porcentaje){
    
    uint8_t vel_nueva = (porcentaje/100.0)*resolucion;//Velocidad está expresado en conteos
    uint16_t Vel_act = PWM_Mosfet_ReadCompare();//Velocidad actual que corre el motor
    
    if(vel_nueva>Vel_act)//Tenemos que acelerar
    {
        for(int i=Vel_act;i<=vel_nueva;i++){
            PWM_Mosfet_WriteCompare(i);
            CyDelay(10);//Pocura el cambio no tan de golpe
        }
        
    }else if(Vel_act>vel_nueva)//Tenemos que desacelerar
    {
        for(int i=Vel_act;i>vel_nueva;i--){
            PWM_Mosfet_WriteCompare(i);
            CyDelay(10);//Pocura el cambio no tan de golpe
        }
    }
}


