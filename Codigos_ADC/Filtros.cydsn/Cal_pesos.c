/*
    Código para generar los pesos pondereados para la implementación
    de un flitro digital de Media movil con pesos exponenciales en un
    MCU 
*/

//Funcion para calcular los pesos pondereados exponencialmentes
// Gaurda los pesos en un arreglo definido por el usuario 
void P(int ventana, float b, float *pesos){

    //variables
    float a, pow_b = 1.0;

    //calcularmos la potencia de a elevada a ventana
    for( int i=0; i < ventana; i++){
        pow_b *= b;
    }
    //calculamos a
    a = (1-b)/(1-pow_b);

    //Delvolvemos a valo 1
    pow_b = 1.0;
    //Calculamos los pesos 
    for(int i=0; i<ventana; i++){
        pesos[i] = a*pow_b;
        pow_b *= b;
    }
}


/* [] END OF FILE */
