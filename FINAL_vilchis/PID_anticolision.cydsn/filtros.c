#include "filtros.h"

// Función para inicializar el promediador móvil
void inicializarPromediadorMovil(PromediadorMovil *pm) {
    pm->indice = 0;
    pm->sumatoria = 0.0;
    for (int i = 0; i < VENTANAS; ++i) {
        pm->valores[i] = 0.0;
    }
}

// Función para agregar un nuevo valor al promediador móvil
void agregarValor(PromediadorMovil *pm, uint16_t nuevoValor) {
    // Restar el valor que se va a reemplazar
    pm->sumatoria -= pm->valores[pm->indice];
    
    // Agregar el nuevo valor
    pm->valores[pm->indice] = nuevoValor;
    
    // Sumar el nuevo valor
    pm->sumatoria += nuevoValor;
    
    // Incrementar el índice y manejar el desbordamiento
    pm->indice = (pm->indice + 1) % VENTANAS;
}

// Función para obtener el promedio móvil actual
uint16_t obtenerPromedioMovil(PromediadorMovil *pm) {
    return pm->sumatoria / VENTANAS;
}