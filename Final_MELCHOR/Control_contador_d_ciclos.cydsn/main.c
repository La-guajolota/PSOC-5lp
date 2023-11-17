#include "project.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"

//Rutina de sumado
uint16_t on = 0, acomulador = 0;
CY_ISR(contador){
    contador_ClearPending();// Limpieza de interrupción
    
    acomulador++; //65535 bits máximos
    
    /*
        Al ser un relevador de estado solido todo integrado,
        no hay problema en no activar con pulsos-disparo
    */
    if(on<=acomulador){//ON disparos
        
        Actuadores_Write(0xFF);
        
    }else{//OFF
        
        Actuadores_Write(0x00);
    }
        
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Interrrupciones
    contador_StartEx(contador);// Inicializar interrupción física
    contador_ClearPending();  // Limpieza de interrupción
    
    //lcd CONFIG INICIAL
    LCD_Position(0,0);
    LCD_PrintString("Potencia:   ON/65535:");
    
    uint8_t Potencia = 0, btns;
    
    for(;;)
    {
        btns = btns_Read();//checamos botones
        CyDelay(100);
        
        //SUMAMOS O RESTAMOS SEGUN SE QUIERA EL USUARIO
        if(btns & BIT0){
            Potencia++;
        }
        
        if((btns & BIT1)>>1){
            Potencia--;
        }
        
        //TRUNCAMOS SI SE SATURA EL ACTUADORS
        Potencia = trunca(Potencia,0,100);
        
        on = map(Potencia,0,100,0,65535);//Se actualiza la proporcion ON/OFF
        
        //Atualizamos el angulo de disparo
        LCD_Position(1,0);
        LCD_PrintNumber(Potencia);
        LCD_PrintString("* ");
        
    }
}


