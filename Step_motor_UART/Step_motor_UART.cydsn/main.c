#include "project.h"
#include "STEPM.h"

uint8_t flag = 0x00;
char buffer;
uint8_t estado;
//Rutina de interrupcción
CY_ISR(isr_1){
    isr_1_ClearPending();  // Limpieza de interrupción
    flag |= BIT0;// Bandera de dato recibido  
    buffer = UART_GetByte();//Revisamos el contenido
}

int main(void)
{
    CyGlobalIntEnable;
    
    isr_1_StartEx(isr_1);// Inicializar interrupción física
    isr_1_ClearPending();// Limpiar por primera vez la interrupción
    UART_Start();           // Corre UART
    UART_ClearRxBuffer();
    
    //eMPEZAMOS EN EL ESTADO DE PARO no hay ovimiento del motor
    estado = PAR;
    Led_indicadores_Write(~BIT2);//ROJO paro
    
    for(;;)
    {
        if(flag == BIT0){//Se resivió un daro de la UART? Cuál nueva dirección escogemos
            flag &= ~BIT0;//Tiramos la bandera
            
            switch (buffer){
                case '1':
                    Led_indicadores_Write(~BIT0);//Azul izquierda
                    estado = IZQ;
                    break;
                case '2':
                    Led_indicadores_Write(~BIT1);//Verde derecha
                    estado = DER;
                    break;
                case '3':
                    Led_indicadores_Write(~BIT2);//ROJO paro
                    estado = PAR;
                    break;}
            }
        //Ejecutamos la secuencia de movimiento UN PASO
        Corrimiento(estado);
    }
}


