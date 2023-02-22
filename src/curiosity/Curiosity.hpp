#if !defined(CURIOSITY_HPP)
#define CURIOSITY_HPP

#include <string>
#include <list>
#include <fstream>
#include <iostream>

#include "../commonFunctions/commonFunctions.hpp"
#include "../element/Element.hpp"
#include "../analysis/Analysis.hpp"

using namespace std;

class Curiosity
{
private:
    // TODO: Implementar queue segun el correo del profesor
    list<string> commands;
    list<Element> elements;
    list<Analysis> analysisList;

public:
    Curiosity(/* args */);
    ~Curiosity();

    void addCommand(string command);

    void addElement(Element element);
    void addAnalysis(Analysis analysis);

    /*  Getters and Setters */
    list<string> GetCommands() const;
    void SetCommands(list<string> commands);
    list<Element> GetElements() const;
    void SetElements(list<Element> elements);
};

#include "Curiosity.cxx"

#endif // CURIOSITY_HPP
