/* TablasDeConversion.c
 * Programa que imprime dos tablas, Fahrenheit-Celsius y Celsius-Fahrenheit respectivamente
 * 
 * Crédito extra 1
 * Franco Matias Cortinez
 * 1762060
 * 
 * Crédito extra 2
 * Jorge Ignacio Condori Aguirre
 * 20240513
 */

#include <stdio.h>
#include "Conversion.h"

void printFila(double (*funcion)(double), int valor);
void printFilas(int inicio, int fin, int incremento, double (*funcion)(double));
void printTablaCelsius(int inicio, int fin, int incremento);
void printTablaFahrenheit(int inicio, int fin, int incremento);
void printTablas(int inicio, int fin, int incremento);

int main(){
   const int LOWER = 0;
   const int UPPER = 300;
   const int STEP = 20;

   printTablas(LOWER, UPPER, STEP);

return 0;

}
void printFila(double (*funcion)(double), int valor){
    printf("%6d\t%10.1f\n",valor, funcion(valor));
}

void printFilas(int inicio, int fin, int incremento, double (*funcion)(double)){
    for(int i = inicio; i <= fin; i += incremento){
        printFila(funcion, i);
    }
}

void printTablaCelsius(int inicio, int fin, int incremento){  
    printf("%10s %8s\n","Fahrenheit","Celsius"); 
    printFilas(inicio, fin, incremento, *Celsius);
}

void printTablaFahrenheit(int inicio, int fin, int incremento){
    printf("%7s %12s\n","Celsius","Fahrenheit");
    printFilas(inicio, fin, incremento, *Fahrenheit);
}

void printTablas(int inicio, int fin, int incremento){
    printTablaCelsius(inicio, fin, incremento);
    printTablaFahrenheit(inicio, fin, incremento);
}