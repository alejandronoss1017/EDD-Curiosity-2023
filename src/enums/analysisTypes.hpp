#if !defined(ANALYSISTYPES_HPP)
#define ANALYSISTYPES_HPP

#include <string>
#include <iostream>

using namespace std;

enum analysisTypes
{
    fotografiar,
    composicion,
    perforar,
};

enum elementTypes
{
    roca,
    crater,
    monticulo,
    arena,
    duna,
};

bool isAnalysisTypes(const string &str)
{
    if (str == "fotografiar")
    {
        return true;
    }
    else if (str == "composicion")
    {
        return true;
    }
    else if (str == "perforar")
    {
        return true;
    }
    else
    {
        return false;
    }
}

analysisTypes str2AnalysisTypes(const string &str)
{
    if (str == "fotografiar")
    {
        return analysisTypes::fotografiar;
    }
    else if (str == "composicion")
    {
        return analysisTypes::composicion;
    }
    else if (str == "perforar")
    {
        return analysisTypes::perforar;
    }
    else
    {
        throw runtime_error("Valor inválido para el tipo de analisis.");
    }
}

bool isElementTypes(const string &str)
{
    if (str == "roca")
    {
        return true;
    }
    else if (str == "crater")
    {
        return true;
    }
    else if (str == "monticulo")
    {
        return true;
    }
    else if (str == "arena")
    {
        return true;
    }
    else if (str == "duna")
    {
        return true;
    }
    else
    {
        return false;
    }
}

elementTypes str2ElementType(const string &str)
{
    if (str == "roca")
    {
        return elementTypes::roca;
    }
    else if (str == "crater")
    {
        return elementTypes::crater;
    }
    else if (str == "monticulo")
    {
        return elementTypes::monticulo;
    }
    else if (str == "arena")
    {
        return elementTypes::arena;
    }
    else if (str == "duna")
    {
        return elementTypes::duna;
    }
    else
    {
        throw runtime_error("Valor inválido para el tipo de analisis.");
    }
}

#endif // ANALYSISTYPES_HPP