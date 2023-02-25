#include "Command.hpp"

Command::Command() {}

Command::Command(commandTypes command, vector<string> params)
{
    this->command = command;
    this->params = params;
}

Command::~Command()
{
}

commandTypes Command::GetCommand() const
{
    return command;
}

void Command::SetCommand(commandTypes command)
{
    command = command;
}

vector<string> Command::GetParams() const
{
    return params;
}

void Command::SetParams(vector<string> params)
{
    params = params;
}

ostream &operator<<(ostream &os, const vector<string> &theV)
{
    for (auto i = theV.begin(); i != theV.end(); i++)
    {
        if (*i == theV.back())
        {
            os << *i;
            break;
        }
        os << *i << " ";
    }

    return os;
}
ostream &operator<<(ostream &os, const Command &command)
{
    os << commandTypes2Str(command.command) << " " << command.params;
    return os;
}
