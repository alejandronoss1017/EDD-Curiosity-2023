#include "Coordinate.hpp"

Coordinate::Coordinate()
{
    this->posX = 0;
    this->posY = 0;
}

Coordinate::Coordinate(double posX, double posY)
{
    this->posX = posX;
    this->posY = posY;
}

Coordinate::~Coordinate()
{
}

double Coordinate::GetPosX() const
{
    return posX;
}

void Coordinate::SetPosX(double posX)
{
    this->posX = posX;
}

double Coordinate::GetPosY() const
{
    return posY;
}

void Coordinate::SetPosY(double posY)
{
    this->posY = posY;
}

ostream &operator<<(ostream &os, const Coordinate &coordinate)
{
    os << "posX: " << coordinate.GetPosX() << " posY: " << coordinate.GetPosY();
    return os;
}
