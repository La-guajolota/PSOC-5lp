
#include "project.h"
#include "Maniobras.h"


//Variables globales
uint8_t mando;//Contiene los estados de las entradas de control

int main(void)
{
    CyGlobalIntEnable;
    PWM_Mosfet_Start();
    LED_VELOCIDAD_Start();
    LED_VELOCIDAD_Write7SegNumberDec(0,0,4,0);//Mostramos la potecia inicial                                                                                                                                                                
    PWM_Mosfet_WriteCompare(0x00);//Reteamos velocidad a 0
    Driver_RELAY_Write(0x01);//sETEAMOS LA SALIDA A 0XFF PARO TOTAL
    
    for(;;)
    {
      //checamos el registro de control
       mando = Control_manual_Read();
       
      //Existió algún cambio del registro con su estado normal??
    /*
        El registro de control en los botones es
        0b00011111  --> 0x1F
      */
      if(mando != 0x1F)
    {
       
      switch(mando){
        case Der:
            SENTIDO(Derecha);
            break;
        case Izq:
            SENTIDO(Izquierda);
            break;
        case Paro:
            Driver_RELAY_Write(paro_total);;
            break;   
      }
    
    }
    
      //Evaluamos la acción a tomar
        
    }
}


