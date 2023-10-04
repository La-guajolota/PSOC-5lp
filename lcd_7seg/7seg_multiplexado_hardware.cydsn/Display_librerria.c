#include "Display_librerria.h"
#include "project.h"


void Separa_digitos(uint16_t num){ 
    
    uint8_t digm,digc,digd,digu;
    
    digm = num / 1000;        // Obtén el primer dígito (miles)
    digc = (num / 100) % 10;  // Obtén el segundo dígito (centenas)
    uint8_t Reg_cm = (digm<<0x04)| digc; 
    
    digd = (num / 10) % 10;   // Obtén el tercer dígito (decenas)
    digu = num % 10;          // Obtén el cuarto dígito (unidades)    
    uint8_t Reg_ud = (digd<<0x04)| digu; 
    
    //Checamos cuales digitos se van a utilizar
    ceros(num);
    
    //Actualizamos los registros de los digitos
    num_Unidades_Decenas_Write(Reg_ud);//Agregamos unidades y decenas
    num_Centenas_MIllar_Write(Reg_cm);//Agregamos centenas y millares
}


void ceros(uint16_t num){
    uint8_t ceros = Control_ceros_Read();
    if(num<1000){
        Control_ceros_Write(ceros &= ~BIT3);
    }else{
        Control_ceros_Write(ceros |= BIT3);
    }
    if(num<100){
        Control_ceros_Write(ceros &= ~BIT2);
    }else{
        Control_ceros_Write(ceros |= BIT2);
    }
    if(num<10){
        Control_ceros_Write(ceros &= ~BIT1);
    }else{
        Control_ceros_Write(ceros |= BIT1);
    }
}