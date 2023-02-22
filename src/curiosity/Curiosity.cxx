#include "Curiosity.hpp"

Curiosity::Curiosity()
{
}

Curiosity::~Curiosity()
{
}

void Curiosity::addCommand(string command)
{
    this->commands.push_front(command);
}

void Curiosity::addElement(Element element)
{
    this->elements.push_front(element);
}

void Curiosity::addAnalysis(Analysis analysis)
{
    this->analysisList.push_front(analysis);
}

list<string> Curiosity::GetCommands() const
{
    return commands;
}

void Curiosity::SetCommands(list<string> commands)
{
    this->commands = commands;
}

list<Element> Curiosity::GetElements() const
{
    return elements;
}

void Curiosity::SetElements(list<Element> elements)
{
    this->elements = elements;
}
