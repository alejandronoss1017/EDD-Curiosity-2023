#if !defined(MEASURETYPES_HPP)
#define MEASURETYPES_HPP

#include <string>
#include <iostream>

using namespace std;

enum measureUnit
{
    cm,
    m,
    km,
    grados,
};

enum movementType
{
    avanzar,
    girar,
};

bool isMeasureUnit(const string &str)
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

measureUnit str2MeasureUnit(const string &str)
{
    if (str == "cm")
    {
        return measureUnit::cm;
    }
    else if (str == "m")
    {
        return measureUnit::m;
    }
    else if (str == "km")
    {
        return measureUnit::km;
    }
    else if (str == "grados")
    {
        return measureUnit::grados;
    }
    else
    {
        throw runtime_error("Valor inválido para unidad de medida");
    }
}

bool isMovementType(const string &str)
{
    if (str == "avanzar")
    {
        return true;
    }
    else if (str == "girar")
    {
        return true;
    }
    else
    {
        return false;
    }
}

movementType str2MovementType(const string &str)
{
    if (str == "avanzar")
    {
        return movementType::avanzar;
    }
    else if (str == "girar")
    {
        return movementType::girar;
    }
    else
    {
        throw runtime_error("Valor inválido para unidad de medida");
    }
}

#endif // MEASURETYPES_HPP
