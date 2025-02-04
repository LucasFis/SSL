#include "histograma.h"
#include <assert.h>

int main(){
    int maxima_longitud = 16;
    int array_auxiliar[maxima_longitud];
    struct data_set datos = {maxima_longitud,array_auxiliar}; 

    for(int i = 0; i < maxima_longitud; i++)
        datos.array[i] = 0;

    int array_respuesta[16] = {0,0,0,2,4,2,1,1,0,1,0,1,0,1,0,4};
    
    histograma_1(datos);

    for(int i = 0; i < maxima_longitud; i++)
        assert(datos.array[i] == array_respuesta[i]);
    
    histograma_2(datos);
    
    for(int i = 0; i < maxima_longitud; i++)
        assert(datos.array[i] == array_respuesta[i]);

    histograma_3(datos);

    for(int i = 0; i < maxima_longitud; i++)
        assert(datos.array[i] == array_respuesta[i]);
    
    histograma_x(datos);

    for(int i = 0; i < maxima_longitud; i++)
        assert(datos.array[i] == array_respuesta[i]);

    return 0;
}
