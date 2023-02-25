#if !defined(COMMANDTYPES_HPP)
#define COMMANDTYPES_HPP

#include <string>
#include <iostream>

using namespace std;

enum commandTypes
{
    avanzar,
    girar,
    cargar_comandos,
    cargar_elementos,
    agregar_movimiento,
    agregar_analisis,
    agregar_elemento,
    guardar,
    simular_comandos,
    ubicar_elementos,
    en_cuadrante,
    crear_mapa,
    ruta_mas_larga,
    quit,
    help,
};

bool isCommandType(const string &str)
{
    if (str == "avanzar")
    {
        return true;
    }
    else if (str == "girar")
    {
        return true;
    }

    else if (str == "cargar_comandos")
    {
        return true;
    }
    else if (str == "cargar_elementos")
    {
        return true;
    }
    else if (str == "agregar_movimiento")
    {
        return true;
    }
    else if (str == "agregar_analisis")
    {
        return true;
    }
    else if (str == "agregar_elemento")
    {
        return true;
    }
    else if (str == "guardar")
    {
        return true;
    }
    else if (str == "simular_comandos")
    {
        return true;
    }
    else if (str == "ubicar_elementos")
    {
        return true;
    }
    else if (str == "en_cuadrante")
    {
        return true;
    }
    else if (str == "crear_mapa")
    {
        return true;
    }
    else if (str == "ruta_mas_larga")
    {
        return true;
    }
    else if (str == "quit")
    {
        return true;
    }
    else if (str == "help")
    {
        return true;
    }
    else
    {
        return false;
    }
}

commandTypes str2CommandTypes(const string &str)
{
    if (str == "avanzar")
    {
        return commandTypes::avanzar;
    }
    else if (str == "girar")
    {
        return commandTypes::girar;
    }
    else if (str == "cargar_comandos")
    {
        return commandTypes::cargar_comandos;
    }
    else if (str == "cargar_elementos")
    {
        return commandTypes::cargar_elementos;
    }
    else if (str == "agregar_movimiento")
    {
        return commandTypes::agregar_movimiento;
    }
    else if (str == "agregar_analisis")
    {
        return commandTypes::agregar_analisis;
    }
    else if (str == "agregar_elemento")
    {
        return commandTypes::agregar_elemento;
    }
    else if (str == "guardar")
    {
        return commandTypes::guardar;
    }
    else if (str == "simular_comandos")
    {
        return commandTypes::simular_comandos;
    }
    else if (str == "ubicar_elementos")
    {
        return commandTypes::ubicar_elementos;
    }
    else if (str == "en_cuadrante")
    {
        return commandTypes::en_cuadrante;
    }
    else if (str == "crear_mapa")
    {
        return commandTypes::crear_mapa;
    }
    else if (str == "ruta_mas_larga")
    {
        return commandTypes::ruta_mas_larga;
    }
    else if (str == "quit")
    {
        return commandTypes::quit;
    }
    else if (str == "help")
    {
        return commandTypes::help;
    }
    else
    {
        throw runtime_error("Valor inválido para el tipo de de comando.");
    }
}

string commandTypes2Str(const commandTypes &command)
{
    if (command == avanzar)
    {
        return "avanzar";
    }
    else if (command == girar)
    {
        return "girar";
    }
    else if (command == cargar_comandos)
    {
        return "cargar_comandos";
    }
    else if (command == cargar_elementos)
    {
        return "cargar_elementos";
    }
    else if (command == agregar_movimiento)
    {
        return "agregar_movimiento";
    }
    else if (command == agregar_analisis)
    {
        return "agregar_analisis";
    }
    else if (command == agregar_elemento)
    {
        return "agregar_elemento";
    }
    else if (command == guardar)
    {
        return "guardar";
    }
    else if (command == simular_comandos)
    {
        return "simular_comandos";
    }
    else if (command == ubicar_elementos)
    {
        return "ubicar_elementos";
    }
    else if (command == en_cuadrante)
    {
        return "en_cuadrante";
    }
    else if (command == crear_mapa)
    {
        return "crear_mapa";
    }
    else if (command == ruta_mas_larga)
    {
        return "ruta_mas_larga";
    }
    else if (command == quit)
    {
        return "quit";
    }
    else if (command == help)
    {
        return "help";
    }
    else
    {
        throw runtime_error("Valor inválido para el tipo de de comando.");
    }
}

#endif // COMMANDTYPES_HPP
