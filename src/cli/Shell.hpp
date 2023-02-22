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
    queue<string> commands;
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
    vector<string> readfile(string filename);

    void uploadCommands(string filename);
    void addCommand(string command);

    /*  Getters and Setters */
    string getCommand() const;
    void setCommand(string command);
};

#include "Shell.cxx"

#endif // SHELL__HPP