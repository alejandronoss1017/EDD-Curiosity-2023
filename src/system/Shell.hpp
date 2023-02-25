#if !defined(SHELL__HPP)
#define SHELL__HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <queue>

#include "../element/Element.hpp"
#include "../commonFunctions/commonFunctions.hpp"
#include "../enums/measureTypes.hpp"
#include "../enums/commandTypes.hpp"
#include "../enums/analysisTypes.hpp"
#include "../command/Command.hpp"
#include "../curiosity/Curiosity.hpp"
#include "../analysis/Analysis.hpp"

using namespace std;

class Shell
{
private:
    // TODO: Implementar nuevo parámetro "orientación" en simular comando

    Command command;
    queue<Command> commands;
    list<Element> elements;
    list<Analysis> analysisList;
    Curiosity robot;

public:
    // Constructor
    Shell(/* args */);
    // Destructor
    ~Shell();

    void showMenu();
    void helpMenu(const string command);
    void begin();
    void evaluateCommand();
    bool checkArgumentsNumber(vector<string> commands, int args);
    void writeFile(string fileType, string fileName);
    void readCommands(string fileName);
    void readElements(string fileName);

    void addCommand(Command command);
    void addAnalysis(Analysis analysis);
    void addElement(Element element);

    // TODO: Hacer metodo para limpiar consola tanto el linux y windows

    /*  Getters and Setters */

    void setCommands(queue<Command> commands);
    void setElements(list<Element> elements);

    Command getCommand() const;
    void setCommand(Command command);
};

#include "Shell.cxx"

#endif // SHELL__HPP