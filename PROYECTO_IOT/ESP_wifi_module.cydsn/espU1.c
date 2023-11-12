#include "espU1.h"
#include <stdio.h>
/*
--- Ejemplo UDP ---

1. Configuración del Modo de Operación:
AT+CWMODE=3: Este comando configura el módulo en modo tanto cliente como punto de acceso, permitiendo tanto enviar como recibir datos.

2. Conexión a la Red WiFi:
AT+CWJAP="nombre_de_tu_red","contraseña_de_tu_red": Este comando conecta el módulo a tu red WiFi.
AT+CWJAP="MiHotspot","Pass123"
AT+CIFSR: Para consultar la dirección IP del dispositivo.

3. Inicio de la Conexión UDP:
AT+CIPSTART="UDP","ip_destino",puerto_destino,puerto_local,modo:
Reemplaza "ip_destino" con la dirección IP del dispositivo al que deseas enviar datos,
"puerto_destino" con el puerto del dispositivo destino,
"puerto_local" con un puerto local en el ESP8266 para recibir datos,
y "modo" con 2 para permitir enviar y recibir datos sin cambiar la conexión.
AT+CIPSTART="UDP","192.168.100.55",8080,8081,2

4. Envío de Datos:
AT+CIPSEND=tamaño_del_mensaje: Este comando especifica el tamaño del mensaje que deseas enviar.
Luego, ingresa los datos que deseas enviar.
AT+CIPSEND=4
> Hola

5. Recepción de Datos:
Los datos recibidos serán mostrados en la interfaz serial automáticamente si el módulo está correctamente configurado y conectado.

6. Cierre de la Conexión:
AT+CIPCLOSE: Este comando cerrará la conexión UDP.
*/
//Funcion de inicializacion sin tanto shitpost


uint8_t esp_wifi_Start(uint8_t ROUTER){
    
    UART_PutString("AT+CIPCLOSE\r\n");
    CyDelay(3000);
    UART_PutString("AT+CWMODE=3\r\n");
    CyDelay(3000);
    
    if (ROUTER ==0){//VILCHISs
        UART_PutString("AT+CWJAP=\"IET501_Psoc>Arduino_2.4\",\"Lo_toco_araiza?\"\r\n");
        CyDelay(10000);
        
        UART_PutString("AT+CIFSR\r\n");
        CyDelay(1000);
        
        UART_PutString("AT+CIPSTART=\"UDP\",\"192.168.0.100\",8501,8081,2\r\n");
    }
    
    if (ROUTER ==1){//cuernofono
    }
    
    if(ROUTER ==2){//CANTON
        UART_PutString("AT+CWJAP=\"FOCOS\",\"focointeligente\"\r\n");
        CyDelay(10000);
        
        UART_PutString("AT+CIFSR\r\n");
        CyDelay(1000);
        
        UART_PutString("AT+CIPSTART=\"UDP\",\"192.168.0.25\",8501,8081,2\r\n");
    }

    INDICADORES_Write(BIT0);//El buzzer indica el fin de la inicializacion
    CyDelay(150);
    INDICADORES_Write(~BIT0);//El buzzer indica el fin de la inicializacion
    
    return 0;
}

void send(uint8_t len, char *msg){
    char *send;
    sprintf(send,"AT+CIPSEND=%d\r\n",len);
    
    UART_PutString(send);
    CyDelay(5000);
    UART_PutString(msg);
    UART_PutString("\r\n");
}