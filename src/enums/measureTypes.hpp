#if !defined(MEASURETYPES_HPP)
#define MEASURETYPES_HPP

#include <string>
#include <iostream>

using namespace std;

enum measureType
{
    cm = 30,
    m = 31,
    km = 32,
    deg = 33,
    rad = 34,
};

bool isMeasureType(const string &str)
{
    if (str == "cm")
    {
        return true;
    }
    else if (str == "m")
    {
        return true;
    }
    else if (str == "km")
    {
        return true;
    }
    else if (str == "grados")
    {
        return true;
    }
    else
    {
        return false;
    }
}

measureType str2MeasureType(const string &str)
{
    if (str == "cm")
    {
        return measureType::cm;
    }
    else if (str == "m")
    {
        return measureType::m;
    }
    else if (str == "km")
    {
        return measureType::km;
    }
    else if (str == "deg")
    {
        return measureType::deg;
    }
    else if (str == "rad")
    {
        return measureType::rad;
    }
    else
    {
        throw runtime_error("Valor inválido para unidad de medida");
    }
}
#endif // MEASURETYPES_HPP
