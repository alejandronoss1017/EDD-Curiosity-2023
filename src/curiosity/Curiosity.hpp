#if !defined(CURIOSITY_HPP)
#define CURIOSITY_HPP

#include <string>
#include <queue>
#include <fstream>
#include <filesystem>
#include <iostream>

using namespace std;

class Curiosity
{
private:
    queue<string> commands;

public:
    Curiosity(/* args */);
    ~Curiosity();

    queue<string> GetCommands() const;
    void SetCommands(queue<string> commands);
};

#include "Curiosity.cxx"

#endif // CURIOSITY_HPP
