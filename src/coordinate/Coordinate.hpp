#if !defined(COORDINATE_HPP)
#define COORDINATE_HPP

#include <ostream>

using namespace std;
class Coordinate
{
private:
    double posX;
    double posY;

public:
    Coordinate(/* args */);
    Coordinate(double posX, double posY);

    ~Coordinate();

    /*  Getters and Setters  */
    double GetPosX() const;

    void SetPosX(double posX);

    double GetPosY() const;

    void SetPosY(double posY);

    friend ostream &operator<<(ostream &os, const Coordinate &coordinate);
};

#include "Coordinate.cxx"

#endif // COORDINATE_HPP
