#include "stdint.h"

#define VENTANAS 15

// Estructura para el promediador móvil
typedef struct {
    uint16_t valores[VENTANAS];
    int indice;
    uint16_t sumatoria; // Usamos uint16_t para evitar desbordamientos
} PromediadorMovil;

void inicializarPromediadorMovil(PromediadorMovil *pm);
void agregarValor(PromediadorMovil *pm, uint16_t nuevoValor);
uint16_t obtenerPromedioMovil(PromediadorMovil *pm);