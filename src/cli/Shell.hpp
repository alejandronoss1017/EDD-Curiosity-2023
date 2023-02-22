#if !defined(SHELL__HPP)
#define SHELL__HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

#include "../curiosity/Curiosity.hpp"
#include "../commonFunctions/commonFunctions.hpp"
#include "../enums/analysisTypes.hpp"
#include "../enums/measureTypes.hpp"

using namespace std;

class Shell
{
private:
    // TODO: Implementar nuevo parámetro "orientación" en simular comando
    Curiosity robot;
    string command;

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

    // TODO: Hacer metodo para limpiar consola tanto el linux y windows

    /*  Getters and Setters */
    string getCommand() const;
    void setCommand(string command);
};

#include "Shell.cxx"

#endif // SHELL__HPP