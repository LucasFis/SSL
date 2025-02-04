#include"Graficador.h"
#include"histograma.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){   //argv[1] = {Numero histograma} (se toma el grafico horizontal como default)
                                    //argv[2] = {Numero histograma, horizontal} 1 = true (horizontal), 0 = false (vertical)
    int maxima_longitud = 16;
    int array_auxiliar[maxima_longitud];

    for(int i = 0; i < maxima_longitud;i++){
        array_auxiliar[i] = 0;
    }

    t_data_set datos = {maxima_longitud,array_auxiliar}; 

    if(argc == 2){
        switch(atoi(argv[1])){
            case 1:
                histograma_1(datos);
                break;
            case 2:
                histograma_2(datos);
                break;
            case 3:
                histograma_3(datos);
                break;
            case 4:
                histograma_x(datos);
                break;
            default:
                printf("Valor de histograma invalido (debe ser: {1, 2, 3, 4})");
                return 0;
        }
        graficar_svg(datos,1);
    }
    else if(argc==3){
        switch(atoi(argv[1])){
            case 1:
                histograma_1(datos);
                break;
            case 2:
                histograma_2(datos);
                break;
            case 3:
                histograma_3(datos);
                break;
            case 4:
                histograma_x(datos);
                break;
            default:
                printf("Valor de histograma invalido (debe ser: {1, 2, 3, 4})");
                return 0;
        }
        graficar_svg(datos,atoi(argv[2]));
    }
    else 
        printf("No hay suficientes o hay muchos argumentos en -> .\\main _ _ ");
    return 0;
}