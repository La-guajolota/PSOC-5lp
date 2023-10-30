#include "project.h"
#include "D:\GITHUB\Librerias_PSOC\Libreria_PSOC\LIB_psoc.h"
#include "..\..\lcd_7seg\Workspace01\LCD.cydsn\PSOC_LCD.h"

//Hacemos la coción y configuracion UDP
uint8_t esp_wifi_Start(uint8_t ROUTER);

//Esperamos una respuesta del modulo, si no concuerda con lo esperado... se cicla en error 
void send(uint8_t len, char *msg);