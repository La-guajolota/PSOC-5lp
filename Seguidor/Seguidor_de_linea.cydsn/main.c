#include "string.h"
#include "project.h"
//ECOGEMOS LAS TABLAS DE VERDAD SEGUN EL DRIVER DE LOS MOTORES
// CON MODULO L293 o L298
#include "L298N_trable.h"

//Función para binarizar un numero en un array de caracteres 
void getBinary(uint8_t n, char *reg);

int main(void)
{
    CyGlobalIntEnable; 
    
    //COMENTABLE_ SOLO ES PARA DEBUGUEAR
    UART_Start();
    UART_ClearTxBuffer();
    char LECTURA[8];
    
    uint8_t sensores;//Para la lectura de los sensores
    for(;;)
    {
        //sensamos los motores
        sensores = SENSORES_Read();
        
        //Comentable NO necesario
        getBinary(sensores,LECTURA);
        UART_PutString(LECTURA);
        UART_PutChar('\n');
        CyDelay(10);
        
        //*** SITUACIONES POSIBLES CONSIDERADAS Y RESPECTIVAS RESPUESTA ANTE ELLAS****
        if(sensores == 0xC3){//Continuamos hacia adelante
            Control_DIRECCION_Write(GO);
            CyDelay(10);
        }
        if(!(sensores &= 0XC0)){//Si sensores del lado MB está en línea
            Control_DIRECCION_Write(LEFT);
            CyDelay(10);
        }
        if(!(sensores &= 0X03)){//Si sensores del lado MB está en línea
            Control_DIRECCION_Write(RIGHT);
            CyDelay(10);
        }
        if(sensores == 0xFF){//nOS SALIMOS DE LA LINEA
           Control_DIRECCION_Write(BACK);
           CyDelay(10);
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