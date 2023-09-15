#include "project.h"
#include "L293.h"

#define Derecha 0x01
#define Izquierda 0x02
#define Mas 0x04
#define Menos 0x08
#define Quieto 0x80

/**************************************/
uint8_t REG;
uint8_t flag = 0x00;
CY_ISR(isr){
    isr_ClearPending();
    REG =  Control_manual_Read() - 0x80;
    flag = ~flag;
}

void RUTINA(uint8_t GIRO);

int main(void)
{
    CyGlobalIntEnable;
    Control_manual_InterruptEnable();
    isr_StartEx(isr);
    isr_ClearPending();
    
    LED_VELOCIDAD_Start();
    
    //CONDICIONES INCIALES
    uint8_t cpp = 0x00;//INICIAMOS EN VELOCIDAD CERO
    Driver_RELAY_Write(PARO);//Hacemos el cambio de direccion en reles
    PWM_Mosfet_Start();
    PWM_Mosfet_WriteCompare(cpp);
    LED_VELOCIDAD_Write7SegNumberDec(cpp,0,4,0);
    
    
    
    for(;;){
        
         // LOS CAMBIO DE IRECCIÓN SON POR INTERRUPCCIONES
        if(flag){//Le apretó un boton?
            flag = ~flag;//tiramos la bandera
            switch (REG){//CUAL?
                case Derecha:
                    //RUTINA DE CAMBIO DE DIRECCION
                    RUTINA(GIRO_1);
                    break;
                case Izquierda:
                    //RUTINA DE CAMBIO DE DIRECCION
                    RUTINA(GIRO_2);
                    break;
                case Quieto:
                    //RUTINA DE PARO
                    RUTINA(PARO);
                    break;
            }
        }
        
        uint8_t reg = Control_manual_Read();
        switch(reg){//LOS CAMBIOS DE VELOCIDAD SON POR POLLING
            case Mas:
                if(cpp<=254){//La resolucion del pwm es de 255
                    cpp+=5;
                    PWM_Mosfet_WriteCompare(cpp);
                    LED_VELOCIDAD_Write7SegNumberDec(cpp,0,4,0);
                    CyDelay(10);
                }
                break;
            case Menos:
                 if(cpp>=1){//La resolucion del pwm es de 255
                    cpp-=5;
                    PWM_Mosfet_WriteCompare(cpp);
                    LED_VELOCIDAD_Write7SegNumberDec(cpp,0,4,0);
                    CyDelay(10);
                }   
                break;
        }
        
    }
}

void RUTINA(uint8_t GIRO){
    
    uint8_t cpp = PWM_Mosfet_ReadCompare();
    
    for(int i=cpp; i>0 ;i--){//Bajamos de velocidad
        
        PWM_Mosfet_WriteCompare(i);
        LED_VELOCIDAD_Write7SegNumberDec(i,0,4,0);
        CyDelay(20);
    }
    
    Driver_RELAY_Write(GIRO);//Hacemos el cambio de direccion en reles
    CyDelay(2000);
    
    for(int i=0; i<=cpp ;i++){//Subimos y regresamos a la velocidad anterior
    
    PWM_Mosfet_WriteCompare(i);
    LED_VELOCIDAD_Write7SegNumberDec(i,0,4,0);
    CyDelay(20);
    }
    
};

