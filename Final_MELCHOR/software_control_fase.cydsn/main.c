#include "project.h"
#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"

//Rutina de interrupcion
uint8_t angulo = 180;//angulo de dispatp
uint8_t flag = 0;
CY_ISR(actualizar){
    actualizar_ClearPending();
    
    Timer_WritePeriod(map(angulo,0,180,2,255));
}

CY_ISR(DIS){
    DIS_ClearPending();
    
    DISPARADORES_Write(BIT0);
    CyDelayUs(10);
    DISPARADORES_Write(~BIT0);
    
}

int main(void)
{
    CyGlobalIntEnable; 
    //pERIFÉRICOS
    Timer_Start();
    LCD_Start();
    
    //INTERRUPCIONES
    actualizar_StartEx(actualizar);
    actualizar_ClearPending();
    btns_InterruptEnable();
    DIS_StartEx(DIS);
    DIS_ClearPending();
    
    
    //lcd CONFIG INICIAL
    LCD_Position(0,0);
    LCD_PrintString("ANGULO:   Vrms:");
    
    //REGISTRO DE BOTONES
    uint8_t btns=0;
    for(;;)
    {
        
        btns = btns_Read();//checamos botones
        CyDelay(150);
        
        //SUMAMOS O RESTAMOS SEGUN SE QUIERA EL USUARIO
        if(btns & BIT0){
            angulo ++;
        }
        
        if((btns & BIT1)>>1){
            angulo--;
        }
        
        //TRUNCAMOS SI SE SATURA EL ACTUADORS
        angulo = trunca(angulo,0,180);
        
        //Atualizamos el angulo de disparo
        LCD_Position(1,0);
        LCD_PrintNumber(angulo);
        LCD_PrintString("*          ");
        
    }
}


