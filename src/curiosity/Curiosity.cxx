#include "Curiosity.hpp"

Curiosity::Curiosity()
{
    this->orientation = 0;
}

Curiosity::~Curiosity()
{
}

Coordinate Curiosity::GetCoordinate() const
{
    return coordinate;
}

void Curiosity::SetCoordinate(Coordinate coordinate)
{
    this->coordinate = coordinate;
}

double Curiosity::GetOrientation() const
{
    return orientation;
}

void Curiosity::SetOrientation(double orientation)
{
    this->orientation = orientation;
}