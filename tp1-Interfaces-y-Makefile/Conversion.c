#include "Conversion.h"

double Celsius(double fahrenheit){
    return (fahrenheit-32)*5.0/9.0;
}

double Fahrenheit(double Celsius){
    return (9.0/5.0) * Celsius + 32;
}

void PrintTablas(double limite_inferior,double limite_superior, double incremento){
    for(double i = limite_inferior ; i <= limite_superior ; i += incremento){
        printf("%8.2f grados Celsius ------> %8.2f grados Fahrenheit\n",i,Fahrenheit(i));
    }
}

void PrintTablasCelsius(double limite_inferior,double limite_superior, double incremento){
    for(double i = limite_inferior ; i <= limite_superior ; i += incremento){
        printf("%8.2f grados Celsius\n", i);
    }
}

void PrintTablasFahrenheit(double limite_inferior, double limite_superior, double incremento) {
    for(double i = limite_inferior ; i <= limite_superior ; i += incremento) {
        printf("%8.2f grados Fahrenheit\n", Fahrenheit(i));
    }
}

void PrintFila(double limite_inferior){
    printf("%8.2f grados Celsius ------> %8.2f grados Fahrenheit\n",limite_inferior,Fahrenheit(limite_inferior));
}

void PrintFilas(double limite_inferior, double limite_superior, double incremento){
    for(double i = limite_inferior ; i <= limite_superior ; i += incremento) {
        PrintFila(i);
    }
}