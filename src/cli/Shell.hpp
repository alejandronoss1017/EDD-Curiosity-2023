#if !defined(SHELL__HPP)
#define SHELL__HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

class Shell
{
private:
    string command;

    /* data */
public:
    // Constructor
    Shell(/* args */);
    // Destructor
    ~Shell();

    void showMenu();
    void helpMenu(const string command);
    void begin();
    void evaluateCommand();
    vector<string> myStrTok(const string str);
    bool checkArgumentsNumber(vector<string> commands, int args);
    bool checkInt(string arg);
    bool is_valid_float(const string &str);
    vector<string> readfile(string filename);

    /*  Getters and Setters */
    string getCommand() const;
    void setCommand(string command);
};

#include "Shell.cxx"

#endif // SHELL__HPP