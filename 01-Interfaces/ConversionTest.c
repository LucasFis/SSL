#include <assert.h>
#include <stdbool.h>
#include "Conversion.h"

const double error = 0.01;

bool estanCerca(double valorEsperado, double valorReal, double error);

int main() 
{
    // Test 1
    double fahr = 32;
    double celsius = Celsius(fahr);
    double valorEsperado = 0.0;
    assert(estanCerca(valorEsperado, celsius, error));

    // Test 2
    celsius = 100;
    fahr = Fahrenheit(celsius);
    valorEsperado = 212.0;
    assert(estanCerca(valorEsperado, fahr, error));

    // Test 3
    fahr = 0;
    celsius = Celsius(fahr);
    valorEsperado = -17.77;
    assert(estanCerca(valorEsperado, celsius, error));

    // Test 4 
    celsius = 0;
    fahr = Fahrenheit(celsius);
    valorEsperado = 32;
    assert(estanCerca(valorEsperado, fahr, error));

    // Test 5 
    celsius = -3;
    fahr = Fahrenheit(celsius);
    valorEsperado = 26.6;
    assert(estanCerca(valorEsperado, fahr, error));

    // Test 6 
    fahr = 24;
    celsius = Celsius(fahr);
    valorEsperado = -4.44;
    assert(estanCerca(valorEsperado, celsius, error));
    

    // Test 7 
    celsius = -18;
    fahr = Fahrenheit(celsius);
    valorEsperado = -0.4;
    assert(estanCerca(valorEsperado, fahr, error));

    return 0;

}

bool estanCerca(double valorEsperado, double valorReal, double error){
    return (valorEsperado - valorReal) < error;
}