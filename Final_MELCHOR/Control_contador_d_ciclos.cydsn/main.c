#include "project.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"

#define DENOMINADOR 100

//Rutina de sumado
uint16_t on = DENOMINADOR, acomulador = 0;
CY_ISR(contador){
    contador_ClearPending();// Limpieza de interrupción
    
    acomulador++; //65535 bits máximos
    
    if(acomulador >= DENOMINADOR){
        acomulador =0;
    }
    
    /*
        Al ser un relevador de estado solido todo integrado,
        no hay problema en no activar con pulsos-disparo
    */
    if(on<=acomulador){//ON 
        
        Actuadores_Write(0xFF);
        
    }else{//OFF
        
        Actuadores_Write(0x00);
    }
        
}

uint8_t Potencia = 0;
CY_ISR(actualizar){
    actualizar_ClearPending();
    
    on = map(Potencia,0,100,0,DENOMINADOR);//Se actualiza la proporcion ON/OFF
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Interrrupciones
    contador_StartEx(contador);// Inicializar interrupción física
    contador_ClearPending();  // Limpieza de interrupción
    
    actualizar_StartEx(actualizar);
    actualizar_ClearPending();
    btns_InterruptEnable();
    
    
    //lcd CONFIG INICIAL
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("Potencia:");
    
    uint8_t btns;
    
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

        //Atualizamos el angulo de disparo
        LCD_Position(1,0);
        LCD_PrintNumber(100-Potencia);
        LCD_PrintString("%              ");
        
    }
}


