#include "MAX6675_.h"

void SENS_max6675(struct max6675* sensor){

    //LEEMOS LA PALABRA DIRECTAMENTE
    //Por comunicacion ISP
    SPIM_WriteTxData(0x0000);
    sensor->data.palabra  = SPIM_ReadRxData();
    
    
    //Tomamos la secciones de bits de verificacion
    sensor->data.errores = 0;
    if((sensor->data.palabra & DUMMY >> 15) != 0){ //dummy=0
        sensor->data.errores |= 0x01;
    };
    
    if((sensor->data.palabra & Th_input >> 2) != 0){
        sensor->data.errores |= 0x02;
    };
    
    if((sensor->data.palabra & ID >> 1) != 0){
        sensor->data.errores |= 0x04;
    };
    
    
    //Si no hay errores, sensamos la temperatura
    if(sensor->data.errores > 0){
        sensor->data.temperatura = 0;
    }else{
        //Tomamos la seccion de la temperatura
        sensor->data.temperatura = map(sensor->data.palabra>>3,0,4095,0,1024);
    }
    
}

