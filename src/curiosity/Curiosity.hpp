#if !defined(CURIOSITY_HPP)
#define CURIOSITY_HPP

#include "../coordinate/Coordinate.hpp"

using namespace std;

class Curiosity
{
private:
    Coordinate coordinate;
    double orientation;

public:
    Curiosity(/* args */);
    ~Curiosity();

    /*  Getters and Setters */
    Coordinate GetCoordinate() const;

    void SetCoordinate(Coordinate coordinate);

    double GetOrientation() const;

    void SetOrientation(double orientation);
};

#include "Curiosity.cxx"

#endif // CURIOSITY_HPP
