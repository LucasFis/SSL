#include<stdio.h>
#include "Conversion.h"



int main(){
    float lim_inferior, lim_superior, incremento;
    int Opc = 1;
    printf("Ingrese un valor inferior en Celsius a transformar a fahrenheit: ");
    scanf("%f",&lim_inferior);


    do{//Verifica un valor valido de maximo
    printf("Ingrese un valor maximo al cual llega los grados Celsius: ");
    scanf("%f",&lim_superior);
     if(lim_superior < lim_inferior){
        printf("Valor invalido de limite superior\n");
    }
    }
    while(lim_superior < lim_inferior);


    do{//Verifica un valor valido de incremento > 0
    printf("Ingrese un valor de incremento para los grados Celsius: ");
    scanf("%f",&incremento);
    if(incremento <=0){
        printf("Valor invalido de incremento\n");
    }


    }
    while(incremento <= 0);
    while(Opc!=0){
        printf("\n\n\nIngrese una opcion para imprimir (0 = Fin): \n");
        printf("1) PrintTablas (Celsius -> Fahrenheit)\n");
        printf("2) PrintTablasCelsius\n");
        printf("3) PrintTablasFahrenheit\n");
        printf("4) PrintFila\n");
        printf("5) PrintFilas\n");
        
        scanf("%d",&Opc);

        switch (Opc)
        {
        case 0:
            printf("Terminando programa\n");
            return 0;
        case 1:

            PrintTablas(lim_inferior,lim_superior,incremento);
            break;
        
        case 2:

            PrintTablasCelsius(lim_inferior,lim_superior,incremento);
            break;
        
        case 3:

            PrintTablasFahrenheit(lim_inferior,lim_superior,incremento);
            break;

        case 4:

            printf("En esta funcion solo utilizamos un unico grado celsius...\n");
            printf("Para ello, la funcion PrintFila solo utilizara limite inferior de grados celsius brindado anteriormente\n");
            PrintFila(lim_inferior);
            break;

        case 5:

            PrintFilas(lim_inferior,lim_superior,incremento);
            break;

        default:

            printf("No se selecciono una opcion valida...\npor favor, vuelva a intentarlo");
            break;
        }
    }
    return 0;
}
