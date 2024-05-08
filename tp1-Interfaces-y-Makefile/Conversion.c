#include "Conversion.h"

float Conversion_Celsius_Fahrenheit(float Celsius){
    return (9.0/5.0) * Celsius + 32;
}

void PrintTablas(float limite_inferior,float limite_superior, float incremento){
    for(float i = limite_inferior ; i <= limite_superior ; i += incremento){
        printf("%8.2f grados Celsius ------> %8.2f grados Fahrenheit\n",i,Conversion_Celsius_Fahrenheit(i));
    }
}

void PrintTablasCelsius(float limite_inferior,float limite_superior, float incremento){
    for(float i = limite_inferior ; i <= limite_superior ; i += incremento){
        printf("%8.2f grados Celsius\n", i);
    }
}

void PrintTablasFahrenheit(float limite_inferior, float limite_superior, float incremento) {
    for(float i = limite_inferior ; i <= limite_superior ; i += incremento) {
        printf("%8.2f grados Fahrenheit\n", Conversion_Celsius_Fahrenheit(i));
    }
}

void PrintFila(float limite_inferior){
    printf("%8.2f grados Celsius ------> %8.2f grados Fahrenheit\n",limite_inferior,Conversion_Celsius_Fahrenheit(limite_inferior));
}

void PrintFilas(float limite_inferior, float limite_superior, float incremento){
    for(float i = limite_inferior ; i <= limite_superior ; i += incremento) {
        PrintFila(i);
    }
}