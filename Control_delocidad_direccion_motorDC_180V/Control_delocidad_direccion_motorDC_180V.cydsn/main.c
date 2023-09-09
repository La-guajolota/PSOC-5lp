
#include "project.h"
#include "Maniobras.h"

//Variables globales
uint8_t mando, mando_anterior=Paro;//Contiene los estados de las entradas de control
uint8_t Potenccia=0;//Numero de conteo comparación del PWM

int main(void)
{
    CyGlobalIntEnable;
    //Perifericos
    PWM_Mosfet_Start();
    LED_VELOCIDAD_Start();
    
    //Condiciones iniciales
    LED_VELOCIDAD_Write7SegNumberDec(0,0,4,0);//Mostramos la potecia inicial                                                                                                                                                                
    PWM_Mosfet_WriteCompare(255);//Reteamos velocidad a 0
    Driver_RELAY_Write(paro_total);//sETEAMOS LA SALIDA A PARO TOTAL
    
    for(;;)
    {
      //checamos el registro de control
       mando = Control_manual_Read();
       
      //Existió algún cambio del registro con su estado normal??
    /*
        El registro de control en los botones es
        0b00011111  --> 0x1F
      */
      if(mando != 0x1F){
        
          if(mando != mando_anterior){//Revisamos si la nueva accion no es el estado actual
            switch(mando){
            case Paro:
                SENTIDO(paro_total);
                break;
            case Der:
                SENTIDO(Derecha);
                break;
            case Izq:
                SENTIDO(Izquierda);
                break;
            case Vmas:
                if(Potenccia<100){
                    Potenccia++;//Aumentamos potencia
                    Velocidad(Potenccia);
                }
                break;
            case Vmenos:
                if(Potenccia>0){
                    Potenccia--;//Disminuimos potencia potencia
                    Velocidad(Potenccia);
                }
                break;  
          }    
    }
        mando_anterior = mando;
    }   
    }
}


