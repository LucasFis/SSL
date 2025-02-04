#include "Conversion.h"

double Celsius (double fahr)
{
    return (fahr - 32) * 5.0 / 9.0;
}

double Fahrenheit (double celsius)
{
    return 9.0*(celsius/5.0)+32;
}
