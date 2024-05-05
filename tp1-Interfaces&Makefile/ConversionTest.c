#include <stdio.h>
#include <windows.h>
#include "Conversion.h"

int main(void){
    printf("Probando 0 grados celsius = 32 grados fahrenheit...\n");
    Sleep(2000);
    if(Conversion_Celsius_Fahrenheit(0.0)==32.0){
        printf("Retorno exitoso\n");
    }
    else{
        printf("Error detectado, terminando programa.\n");
        return -1;
    }
    Sleep(2000);
    printf("Probando 20.0 grados celsius = 68.0 grados fahrenheit...\n");
    Sleep(2000);
    if(Conversion_Celsius_Fahrenheit(20.0)==68.0){
        printf("Retorno exitoso\n");
    }
    else{
        printf("Error detectado, terminando programa.\n");
        return -1;
    }
    Sleep(2000);
    printf("Probando 132.12 grados celsius = 269.81 grados fahrenheit (aproximadamente)...\n");
    Sleep(2000);
    if(Conversion_Celsius_Fahrenheit(132.12) >= 269.7 && Conversion_Celsius_Fahrenheit(132.12) <= 270.0){
        printf("Retorno exitoso\n");
    }
    else{
        printf("Error detectado, terminando programa.\n");
        return -1;
    }
    Sleep(2000);
    printf("Probando -34.21 grados celsius = -29.57 grados fahrenheit (aproximadamente)...\n");
    Sleep(2000);
    if(Conversion_Celsius_Fahrenheit(-34.21) >= -29.6 && Conversion_Celsius_Fahrenheit(-34.21) <= -29.4){
        printf("Retorno exitoso\n");
    }
    else{
        printf("Error detectado, terminando programa.\n");
        return -1;
    }
    return 0;
}