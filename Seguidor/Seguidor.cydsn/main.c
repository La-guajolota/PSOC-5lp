#include "project.h"
#include "Driver_control.h"
#include "Utils.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    uint8_t Sensores;//Registro de estados de los sensores
    uint8_t dir = Paro_seco_MB;//Bytes de control de los motores
    uint8_t REG;//Variable auxiliar para leer el registro de control
    uint8_t Motor = Mb;
    
    /*
    //Comentadas si no se mnecesita debuguear
    UART_Start();
    char r[2];
    */
    
    for(;;)
    {
        //Vemos el registro de los sensores
        Sensores = Sensores_Read();
        
        //Evaluamos las entradas
        //dECIDIMOS SEGUN LA SITUACION
        
        
        
        
        
        //Configuramos dirección de llantas Dirección
        REG = Control_Hdriver_Read();//LEMOS REGISTRO
        REG = Dir_Motor(dir,Motor,REG);//Enmasaramiento para obtener la actualizacion
        Control_Hdriver_Write(REG);//ACTUALIZAR REGISTRO
       
        
        /*
        //Lineas para debugguear
        UART_PutString(REG);
        sprintf(r,"%x",dir);
        UART_PutString(r);
        CyDelay(1000);
        */
        
        //Velocidad
    }
}
