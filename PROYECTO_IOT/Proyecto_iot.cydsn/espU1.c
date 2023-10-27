#include "espU1.h"
#include "project.h"
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
void esp_wifi_Start(){
    
    UART_PutString("AT+CWMODE=3\r\n");
    //UART_PC_PutString("AT+CWMODE=3\r\n");
    CyDelay(1000);
    
    UART_PutString("AT+CWJAP=\"IET501_Psoc>Arduino_2.4\",\"Lo_toco_araiza?\"\r\n");
    //UART_PutString("AT+CWJAP=\"IET501_Psoc>Arduino_2.4\",\"Lo_toco_araiza?\"\r\n");
    CyDelay(1000);
    
    //AT+CIPSTART="UDP","192.168.0.102",8501,8081,2
    UART_PutString("AT+CIPSTART=\"UDP\",\"169.254.175.21\",8051,8081,2\r\n");
    //UART_PC_PutString("AT+CIPSTART=\"UDP\",\"192.168.123.228\",8051,8081,2\r\n");
    CyDelay(1000);
}