#include "project.h"
#include "Firmware_7seg.h"

#define Conteo_max 9999 //Cambiamos esta madre para el conteo máximo

uint16_t cont=0x00;//Contador para el cronometro
uint16_t bandera =0x00;
uint8_t Reg_Botones=0x00;//Aqui van qué botones se había apretado
CY_ISR(ISR_botones){
      ISR_botones_ClearPending();
    
      Reg_Botones = Status_Botones_Read()-0x80;//Por el sticky se limpia despues de leer
      if(Reg_Botones == 0x02){//SETEO
        cont = 0;
        }
      if(Reg_Botones == 0x01){// 0inicio/1paro
        bandera = ~bandera;//Hacemos
      }
}


int main(void)
{
    CyGlobalIntEnable;
    ISR_botones_StartEx(ISR_botones);
    ISR_botones_ClearPending();
    Status_Botones_InterruptEnable();
    
    
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
        /* 
            B1,B0
            0  0   B0 PARO   
            0  1   B0 INICIO
            1  0   SETEO
            1  1   N/A
      */
        if(bandera == 0x00){
            if(cont<=Conteo_max){
            //Actualizamos el valor de 7 segmentos
            Separa_digitos(cont);//separamos digitos
            cont++;
            }else{
                cont=0;
            }
        }
    }
}

