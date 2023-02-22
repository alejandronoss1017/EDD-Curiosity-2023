#include "./Curiosity.hpp"

Curiosity::Curiosity()
{
}

Curiosity::~Curiosity()
{
}

queue<string> Curiosity::GetCommands() const
{
    return commands;
}

void Curiosity::SetCommands(queue<string> commands)
{
    commands = commands;
}