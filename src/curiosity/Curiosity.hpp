#if !defined(CURIOSITY_HPP)
#define CURIOSITY_HPP

#include <string>
#include <list>
#include <fstream>
#include <iostream>

#include "../commonFunctions/commonFunctions.hpp"
#include "../element/Element.hpp"

using namespace std;

class Curiosity
{
private:
    list<string> commands;
    list<Element> elements;
    // TODO: Crear lista de analisis

public:
    Curiosity(/* args */);
    ~Curiosity();

    /* //TODO: Cambiar la lectura del archivo a la shell y hacer validacion
        de cada comando en el archivo
    */
    void uploadCommands(string filename);
    void addCommand(string command);

    void uploadElements(string filename);
    void addElement(Element element);

    /*  Getters and Setters */
    list<string> GetCommands() const;
    void SetCommands(list<string> commands);
    list<Element> GetElements() const;
    void SetElements(list<Element> elements);
};

#include "Curiosity.cxx"

#endif // CURIOSITY_HPP
