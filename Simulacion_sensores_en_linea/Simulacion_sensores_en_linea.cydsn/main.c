#include "project.h"

//Rutina de interrupción
uint8_t flag = 0x00;
CY_ISR(isr_1){
    isr_1_ClearPending();
    flag |= 0x01;//Levantamos la bandera
}

//Tomamos el un entero y sacamos u binario en entero
void getBinary(uint8_t n, char *reg)
{
	int loop;
	/*
    3th bit to 0th bit
    Tremendo hack
    En ifs 0-->False  !0-->True
    bit,bit,bit,bti,espacio
    */
	for(loop=3; loop>=0; loop--)
	{
		if( (0x01 << loop) & n)//Concuerda en 1&1???
			reg[loop] = '1';
		else
			reg[loop] = '0';
	}
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(isr_1);
    isr_1_ClearPending();
    Status_Reg_InterruptEnable();
    UART_Start();
    UART_ClearTxBuffer();
    
    uint8_t sensores = 0x00;
    char registro[4];//4 datos
    
    for(;;)
    {
        if(flag & 0x01){
            flag ^= flag;//Tiramos la bandera
            
            //Checamos qué se tiene en el latch de registro
            sensores = Status_Reg_Read();//aL ESTAR EN sTIKY MODE SE SETEA EL REGISTRO DESPÚES DE LA LECTURA
          
            //Madamos la actualización de la lectura Owo
            getBinary(sensores,registro); // uint8_t --> char
            UART_PutString(registro);
            UART_PutChar('\n');
            
        }
    }
}
