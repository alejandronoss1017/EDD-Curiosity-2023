#if !defined(CURIOSITY_HPP)
#define CURIOSITY_HPP

#include "coordinate/Coordinate.hpp"

using namespace std;

class Curiosity
{
private:
    Coordinate coordinate;

public:
    Curiosity(/* args */);
    ~Curiosity();

    Coordinate GetCoordinate() const;

    void SetCoordinate(Coordinate coordinate);

    /*  Getters and Setters */
};

#include "Curiosity.cxx"

#endif // CURIOSITY_HPP
