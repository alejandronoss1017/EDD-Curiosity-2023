#if !defined(SHELL__HPP)
#define SHELL__HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

#include "../curiosity/Curiosity.hpp"
#include "../commonFunctions/commonFunctions.hpp"

using namespace std;

class Shell
{
private:
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

    // TODO: Hacer metodo para limpiar consola tanto el linux y windows

    /*  Getters and Setters */
    string getCommand() const;
    void setCommand(string command);
};

#include "Shell.cxx"

#endif // SHELL__HPP