/* ========================================
Del sensor BME680, adquirir los valores de humedad, presión atmosférica, 
calidad del aire y temperatura ambiental e imprimirlos en el display LCD 16x2 
(polling de 1 segundo).
 * ========================================
*/
//Librerias
#include <stdio.h>
#include "project.h"
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"//LCD
#include "bme680.h"

/* Variables        --------------------------------*/
int8_t error = 0;
sdata_bme680 datos_bme680;

uint32_t lecturas[4] = {0,0,0,0};
void sense(void){
    datos_bme680 = bme680_readData(&sensor_bme680);
    
    //Vaciamos
    lecturas[0] = datos_bme680.gas_resistance;
    lecturas[1] = datos_bme680.humidity;
    lecturas[2] = datos_bme680.pressure;
    lecturas[3] = datos_bme680.temperature;
}

char *etiquetas[4] = {"Calidad de aire","Humedad","Presion","Temperatura"};
void show(void){
    
    for(int i=0;i<4;i++){
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString(etiquetas[i]);
        LCD_Position(1,0);
        LCD_PrintNumber(lecturas[i]);
        CyDelay(1000);
    }

}

void TEST(void){
    //Testeo de Periferico con interfaz de I2C
    uint8_t ERR=0,data[2];//vALOR DIFERENTE A 0 ES UN ERROR
    
    uint8_t REG = 0xD0;//REGISTRO A LEER
    
    //Mandamos address en WR=0
    ERR = I2C_MasterSendStart(0x76,0);//adress
    ERR = I2C_MasterWriteByte(REG);//CHIP ID
    //Mandamos address en WR=1
    ERR = I2C_MasterSendRestart(0x76,1);//adress
    
    //Leemos los registros
    char i = 0;
    while(i < (3 - 1)) {
        data[i] = I2C_MasterReadByte(I2C_ACK_DATA);//ACK para continuar con el siguiente registro
        i++;
    }
    //Siempre el ultimo registro a leer manda un NAK
    data[i] = I2C_MasterReadByte(I2C_NAK_DATA);
    
    ERR = I2C_MasterSendStop();//Paramos la actividad e lectura de registros
   
    LCD_Position(0,0);
    LCD_PrintNumber(ERR);//Estaus si hay errores en la comunicacion
    LCD_Position(1,0);
    LCD_PrintHex16(data[0]);//INfo capturada
    LCD_Position(1,5);
    LCD_PrintHex16(data[1]);//INfo capturada
}

int main(void)
{
    CyGlobalIntEnable;
    
    //Inicializamos perifericos
    LCD_Start();
    I2C_Start();
    
    //FUNCION DE TESTE
    //TEST();
    
    //Inicializamos el BME con su configuraciones
    error = bme680_Start(&sensor_bme680);
    
    for(;;)
    {
        //SENSAMOS
        sense();
        
        //MOSTRAMOS DATOS SENSADOS
        show();
    }
}

