#include "espU1.h"
#include "..\..\..\psoc\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"
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
char buffer[32],i=0;

//Funcion con metodos para confirmación bilateral
/*
void esp_wifi() {
    // Enviar el comando "AT" con saltos de línea
    UART_PutString("AT");
    UART_PutChar(0x0A); // Salto de línea
    UART_PutChar(0x0D); // Vuelta de carro
    
    // Esperar la confirmación
    while (1) {
        buffer[i] = UART_GetByte();
        i++;
        if (!strcmp("OK", buffer)) {
            break;
        }
    }
    
    // Configurar el modo WiFi
    UART_PutString("AT+CWMODE=3");
    UART_PutChar(0x0A); // Salto de línea
    UART_PutChar(0x0D); // Vuelta de carro

    // Conectar a la red WiFi
    UART_PutString("AT+CWJAP=\"FOCOS\",\"focointeligente\""); // Nombre de red y contraseña
    UART_PutChar(0x0A); // Salto de línea
    UART_PutChar(0x0D); // Vuelta de carro

    
    AT+CWJAP="FOCOS","focointeligente"
    WIFI CONNECTED
    WIFI GOT IP
    OK
    */
    
    // Obtener la dirección IP
    //UART_PutString("AT+CIFSR");
    //UART_PutChar(0x0A); // Salto de línea
    //UART_PutChar(0x0D); // Vuelta de carro

    // Capturar la dirección IP
    //char *IP[16];
    
    // Iniciar una conexión UDP
    //UART_PutString("AT+CIPSTART=\"UDP\",\"192.168.100.55\",8085,8081,2");
    //UART_PutChar(0x0A); // Salto de línea
    //UART_PutChar(0x0D); // Vuelta de carro

    // Cerrar la conexión
    //UART_PutString("AT+CIPCLOSE");
//}


//Funcion de inicializacion sin tanto shitpost
void esp_wifi_Start(){
    
    UART_PutString("AT+CWMODE=3");
    UART_PutChar(0x0A);
    UART_PutChar(0x0D);
    CyDelay(250);
    
     UART_PutString("AT+CWJAP=\"FOCOS\",\"focointeligente\"");//MICANTON}
    //UART_PutString("AT+CWJAP=\"moto\",\"729edb6b0e42\"");//MICUERNOFONO
    UART_PutChar(0x0A);
    UART_PutChar(0x0D);
    CyDelay(250);
    
    UART_PutString("AT+CIPSTART=\"UDP\",\"192.168.100.55\",8085,8081,2");
    UART_PutChar(0x0A);
    UART_PutChar(0x0D);
    CyDelay(250);
}

//Funcion para mandar string de informacion