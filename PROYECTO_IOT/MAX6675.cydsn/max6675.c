#include "max6675.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"

//oPTINE LOS BIST DE TEST
uint8_t MAX_INIT(void){
    char ERROR=OK;// Si cero al final todo está bien
    uint16_t bit[3] = {0x0000,0x0000,0x0000},word=0x0000;//Lectura recuperada del sensor
    //Variable temporal de lectura
    
    //Por comunicacion ISP
    SPIM_WriteTxData(0x0000);
    word = SPIM_ReadRxData();
    
    //Separamos los bits Dummy,Th_input,ID
    bit[0] = (word & DUMMY) >> 14;
    bit[1] = (word & Th_input) >> 2;
    bit[2] = (word & ID) >> 1;
    
    //EVALUAMOS
    if(bit[0] == 0){//Error en el Dummy signed??
        ERROR = OK;
    }else{
        ERROR |= dummy;
    }
    
    if(bit[1] == 0){//Hay o no cupla conectada?
        ERROR = OK;
    }else{
        ERROR |= Cupla;
    }
    
    if(bit[2] == 0){//Id correcto?
        ERROR = OK;
    }else{
        ERROR |= id;
    }
    
    return ERROR;
}

//Captura de temperatura
uint16_t sens(void){
    uint16_t temp=0x0000,word=0x0000;//Lectura recuperada del sensor
    //Variable temporal de lectura

    //Por comunicacion ISP
    SPIM_WriteTxData(0x0000);
    word = SPIM_ReadRxData();
    
    //Separamos los bits BIT14--BIT3
    temp = word >> 3;
    temp = map(temp,0,4095,0,1023);
        
    return temp;
}

//Optine la palabra del sensor en raw
uint16_t raw(void){
    uint16_t word;//Lectura recuperada del sensor
    
    //Por comunicacion ISP
    SPIM_WriteTxData(0x0000);
    word = SPIM_ReadRxData();
    
    return word;
}
