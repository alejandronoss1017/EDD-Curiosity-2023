#include "Curiosity.hpp"

Curiosity::Curiosity()
{
}

Curiosity::~Curiosity()
{
}

/**
 * @brief Upload commands from a text plain file.
 * @param filename
 * @throw runtime_error if the file doesn't exist or is empty.
 */
void Curiosity::uploadCommands(string filename)
{
    try
    {
        fstream file(filename);

        if (!file)
        {
            throw runtime_error("El archivo no existe.");
        }

        if (!this->commands.empty())
        {
            while (!commands.empty())
            {
                commands.clear();
            }
        }

        string line;
        while (getline(file, line))
        {
            addCommand(line);
        }

        if (commands.size() == 0)
        {
            throw runtime_error("El archivo se encuentra vacio.");
        }
        else
        {
            cout << commands.size() << " Comandos cargados exitosamente desde " << filename << "." << endl;
        }
        file.close();
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Curiosity::addCommand(string command)
{
    this->commands.push_front(command);
}

void Curiosity::uploadElements(string filename)
{
    try
    {
        fstream file(filename);

        if (!file)
        {
            throw runtime_error("El archivo no existe.");
        }

        if (!this->elements.empty())
        {
            elements.clear();
        }

        string line;
        while (getline(file, line))
        {
            vector<string> v;
            v = myStrTok(line);
            addElement(Element(v.at(0), stoi(v.at(1)), v.at(2), stoi(v.at(3)), stoi(v.at(4))));
        }

        if (elements.size() == 0)
        {
            throw runtime_error("El archivo se encuentra vacio.");
        }
        else
        {
            cout << elements.size() << " Elementos cargados exitosamente desde " << filename << "." << endl;
        }
        file.close();
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Curiosity::addElement(Element element)
{
    this->elements.push_front(element);
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
