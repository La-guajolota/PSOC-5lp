#include "project.h"
#include "Firmware_7seg.h"

#define Conteo_max 9999 //Cambiamos esta madre para el conteo máximo

uint16_t bandera =0x00;
uint8_t Reg_Botones;//Aqui van qué botones se había apretado
CY_ISR(ISR_botones){
      ISR_botones_ClearPending();
      bandera ^= bandera;//Paramos la ventana xd
    
      Reg_Botones = Status_Botones_Read();//Por el sticky se limpia despues de leer
}


int main(void)
{
    CyGlobalIntEnable;
    ISR_botones_StartEx(ISR_botones);
    ISR_botones_ClearPending();
    
    uint16_t cont=0x00;//Contador para el cronometro
    uint8_t Mux_dig[] = {BIT0,BIT1,BIT2,BIT3};//Iniciamos con el primer los transistores habilitados
    for(;;)
    {
        
        
        for(int i=0;i<=3;i++){
            //Rutina del multiplexado con displa
            BCD_CODIFIG(DIGITOS[i]);//Codificamos digito
            Displays_mux_Write(Mux_dig[i]);//Ensendemos el digito que le toca y apagamos los otros
            
            CyDelay(10);//Pa que lusca alvrg
        }
        
        
        //imulamos el conteo de segundo
        if(cont<=Conteo_max){
            //Actualizamos el valor de 7 segmentos
            Separa_digitos(cont);//separamos digitos
            cont++;
        }else{
            cont=0;
        }
        
    }
}

