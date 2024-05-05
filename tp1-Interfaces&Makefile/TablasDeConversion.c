#include<stdio.h>
#include "Conversion.h"

int main(){
    float Celsius;
    printf("Ingrese un valor en Celsius a transformar a fahrenheit: ");
    scanf("%f",&Celsius);

    for(int i = 0; i < 10; i++){
        printf("%8.2f grados Celsius ------> %8.2f grados fahrenheit\n",Celsius,Conversion_Celsius_Fahrenheit(Celsius));
        Celsius = Celsius + 20;
    }
    return 0;
}