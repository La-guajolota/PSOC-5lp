#include "string.h"
#include "project.h"
//ECOGEMOS LAS TABLAS DE VERDAD SEGUN EL DRIVER DE LOS MOTORES
// CON MODULO L293 o L298
#include "L293.h"

//Función para binarizar un numero en un array de caracteres 
void getBinary(uint8_t n, char *reg);

//INTERRUPCIONES DE DESVIO
uint8_t flag_derecha=0,flag_izquierda=0;
CY_ISR(isr_DER){
    isr_DER_ClearPending();
    flag_derecha = ~flag_derecha;
   
}
CY_ISR(isr_IZQ){
    isr_IZQ_ClearPending();
    flag_izquierda = ~flag_izquierda;
}


int main(void)
{
    CyGlobalIntEnable; 
    isr_DER_StartEx(isr_IZQ);
    isr_IZQ_StartEx(isr_DER);
    isr_IZQ_ClearPending();
    isr_IZQ_ClearPending();
    
    //COMENTABLE_ SOLO ES PARA DEBUGUEAR
    UART_Start();
    UART_ClearTxBuffer();
    char LECTURA[8];
    
    uint8_t sensores;//Para la lectura de los sensores
    
    Control_DIRECCION_Write(BREAK);
    
    for(;;)
    {
        //sensamos los motores
        sensores = SENSORES_Read();
        
        
        //Comentable NO necesario
        //getBinary(sensores,LECTURA);
        //UART_PutString(LECTURA);
        //UART_PutChar('\n');
        
        
        if(flag_derecha == 0xFF){
            flag_derecha = ~flag_derecha;
            Control_DIRECCION_Write(LEFT);
        }
        
        if(flag_izquierda == 0xFF){
            flag_izquierda = ~flag_izquierda;
            Control_DIRECCION_Write(RIGHT);
        }
        
        if(sensores == 0xE7){
           Control_DIRECCION_Write(GO);
        }
        
    }
}

void getBinary(uint8_t n, char *reg)
{
	int loop;
	/*
    3th bit to 0th bit
    Tremendo hack
    En ifs 0-->False  !=0-->True
    bit,bit,bit,bti,espacio
    */
	for(loop=7; loop>=0; loop--)
	{
		if( (0x01 << loop) & n)//Concuerda en 1&1???
			reg[loop] = '1';
		else
			reg[loop] = '0';
	}
}