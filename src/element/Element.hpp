#if !defined(ELEMENT_hpp)
#define ELEMENT_hpp

#include "../enums/analysisTypes.hpp"
#include "../enums/measureTypes.hpp"
#include "../coordinate/Coordinate.hpp"

#include <string>

using namespace std;

class Element
{
private:
    elementTypes componentType;
    int size;
    measureType measureUnit;
    Coordinate coordinate;

public:
    Element();
    Element(elementTypes componentType, int size, measureType measureUnit, double coordinateX, double coordinateY);
    ~Element();

    /*  Getters and Setters */
    elementTypes GetComponentType() const;

    void SetComponentType(elementTypes componentType);

    int GetSize() const;

    void SetSize(int size);

    measureType GetMeasureUnit() const;

    void SetMeasureUnit(measureType measureUnit);

    const Coordinate &getCoordinate() const;

    void setCoordinate(const Coordinate &coordinate);

    double GetCoordinateX() const;

    void SetCoordinateX(double coordinateX);

    double GetCoordinateY() const;

    void SetCoordinateY(double coordinateY);

    /* Operations overload */

    friend ostream &operator<<(ostream &os, const Element &element);
};

#include "Element.cxx"

#endif // ELEMENT_hpp
