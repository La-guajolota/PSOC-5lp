#include "project.h"
#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"

//Rutina de interrupcion
uint8_t angulo = 180;//angulo de dispatp
uint8_t flag = 0;
CY_ISR(actualizar){
    actualizar_ClearPending();
    
     Timer_0_WritePeriod(map(angulo,0,180,2,255));
     Timer_1_WritePeriod(map(angulo,0,180,2,255));
}

/*
    Rutinas de disparo para control por fase
*/
uint8_t Disparadores_reg = 0;
CY_ISR(DIS_0){
    DIS_0_ClearPending();
    
    Disparadores_reg = DISPARADORES_Read();//Leemos estadoa ctual de los disparos
    
    DISPARADORES_Write(Disparadores_reg | BIT0);
    CyDelayUs(9);
    DISPARADORES_Write(Disparadores_reg & (~BIT0));
    
}

CY_ISR(DIS_1){
    DIS_1_ClearPending();
    
    Disparadores_reg = DISPARADORES_Read();//Leemos estadoa ctual de los disparos
    
    DISPARADORES_Write(Disparadores_reg | BIT1);
    CyDelayUs(9);
    DISPARADORES_Write(Disparadores_reg & (~BIT1));
    
}
int main(void)
{
    CyGlobalIntEnable; 
    //pERIFÉRICOS
    Timer_0_Start();
    Timer_1_Start();
    LCD_Start();
    
    //INTERRUPCIONES
    actualizar_StartEx(actualizar);
    actualizar_ClearPending();
    btns_InterruptEnable();
    DIS_0_StartEx(DIS_0);
    DIS_0_ClearPending();
    DIS_1_StartEx(DIS_1);
    DIS_1_ClearPending();
    
    
    //lcd CONFIG INICIAL
    LCD_Position(0,0);
    LCD_PrintString("ANGULO:");
    
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


