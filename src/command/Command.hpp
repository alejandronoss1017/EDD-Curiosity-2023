#if !defined(COMMAND_HPP)
#define COMMAND_HPP

#include <string>
#include <vector>

#include "../enums/commandTypes.hpp"

using namespace std;

class Command
{
private:
    // TODO: Implementar clase de comandos en vez de utilizar strings
    commandTypes command;
    vector<string> params;

public:
    Command();

    Command(commandTypes command, vector<string> params);

    ~Command();

    commandTypes GetCommand() const;

    void SetCommand(commandTypes command);

    vector<string> GetParams() const;

    void SetParams(vector<string> params);

    /*  Operator overloaods  */
    friend ostream &operator<<(ostream &os, const Command &command);
    friend ostream &operator<<(ostream &os, const vector<string> &theV);
};

#include "Command.cxx"

#endif // COMMAND_HPP
