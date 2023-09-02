#include <stdio.h>
#include "Driver_control.h"

//Subfuncion de la misma librería
uint8_t Enmascaramiento_Rec(uint8_t mascara, uint8_t REG, uint8_t Motor){
    
    if(Motor == Ma){
        //Paso 1  REG = REG OR MASK colocamos los 1
        REG = REG | mascara;
        //Paso 2 REG = REG ADN (MASK+SUMA)  colocamos los 0
        REG = REG & (mascara + 0XF8);
    }
    if(Motor == Mb){
        //Paso 1  REG = REG OR MASK colocamos los 1
        REG = REG | mascara;
        //Paso 2 REG = REG ADN (MASK+SUMA)  colocamos los 0
        REG = REG & (mascara + 0XC7);
    }

    return REG;
}

//Funciones para el ontrol de la direccióm y paro o arranque
uint8_t Dir_Motor(uint8_t Dir, uint8_t Motor, uint8_t REG){
    
    int8_t R_dir = 0x00;//paro
    
    if(Motor == Ma){//Si vamos a configurar Motor A
        
        switch(Dir){//Evaluamos que direccion vamos a escoger
        case Paro_seco_MA:
            R_dir = Enmascaramiento_Rec(Paro_seco_MA,REG,Ma);
            break;
        case Paro_Z_MA:
            R_dir = REG & Paro_Z_MA;//Caso especial solo se resetea un bit
            break;
        case Derecha_MA:
            R_dir = Enmascaramiento_Rec(Derecha_MA,REG,Ma);
            break;
        case Izquierda_MA:
            R_dir = Enmascaramiento_Rec(Izquierda_MA,REG,Ma);
            break;
        }
        
    }else if(Motor == Mb){ //Si vamos a configua Motor B
        
        switch(Dir){//Evaluamos que direccion vamos a escoger
        case Paro_seco_MB:
            R_dir = Enmascaramiento_Rec(Paro_seco_MB,REG,Mb);
            break;
        case Paro_Z_MB:
            R_dir = REG & Paro_Z_MB;//Caso especial solo se resetea un bit
            break;
        case Derecha_MB:
            R_dir = Enmascaramiento_Rec(Derecha_MB,REG,Mb);
            break;
        case Izquierda_MB:
            R_dir = Enmascaramiento_Rec(Izquierda_MB,REG,Mb);
            break;
        }
        
    }
    

    return R_dir;
}