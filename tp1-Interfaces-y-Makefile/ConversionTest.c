#include<assert.h>
#include "Conversion.h"

int main(void){

    assert(Fahrenheit(0.0)==32.0);

    assert(Fahrenheit(20.0)==68.0);

    assert(Fahrenheit(132.12) >= 269.7 && Fahrenheit(132.12) <= 270.0);

    assert(Fahrenheit(-34.21) >= -29.6 && Fahrenheit(-34.21) <= -29.4);

    assert(Celsius(32.0)==0);

    assert(Celsius(64.0) >= 17.5 && Celsius(64.0) <= 17.8);

    assert(Celsius(16.321) >= -8.8 && Celsius(16.321) <= -8.6);

    return 0;
}