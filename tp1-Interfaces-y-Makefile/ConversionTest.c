#include <stdio.h>
#include <windows.h>
#include<assert.h>
#include "Conversion.h"

int main(void){

    assert(Conversion_Celsius_Fahrenheit(0.0)==32.0);

    assert(Conversion_Celsius_Fahrenheit(20.0)==68.0);

    assert(Conversion_Celsius_Fahrenheit(132.12) >= 269.7 && Conversion_Celsius_Fahrenheit(132.12) <= 270.0);

    assert(Conversion_Celsius_Fahrenheit(-34.21) >= -29.6 && Conversion_Celsius_Fahrenheit(-34.21) <= -29.4);

    return 0;
}