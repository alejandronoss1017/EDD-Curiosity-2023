#if !defined(ELEMENT_hpp)
#define ELEMENT_hpp

#include "../enums/analysisTypes.hpp"
#include "../enums/measureTypes.hpp"

#include <string>

using namespace std;

class Element
{
private:
    elementTypes componentType;
    int size;
    measureType measureUnit;
    int coordinateX;
    int coordinateY;

public:
    Element(elementTypes componentType, int size, measureType measureUnit, int coordinateX, int coordinateY);
    ~Element();

    /*  Getters and Setters */
    elementTypes GetComponentType() const;

    void SetComponentType(elementTypes componentType);

    int GetSize() const;

    void SetSize(int size);

    measureType GetMeasureUnit() const;

    void SetMeasureUnit(measureType measureUnit);

    int GetCoordinateX() const;

    void SetCoordinateX(int coordinateX);

    int GetCoordinateY() const;

    void SetCoordinateY(int coordinateY);

    /* Operations overload */

    friend ostream &operator<<(ostream &os, const Element &element);
};

#include "Element.cxx"

#endif // ELEMENT_hpp
