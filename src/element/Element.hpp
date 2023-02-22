#if !defined(ELEMENT_hpp)
#define ELEMENT_hpp

#include <string>

using namespace std;

class Element
{
private:
    string componentType;
    int size;
    string measureUnit;
    int coordinateX;
    int coordinateY;

public:
    Element(string componentType, int size, string measureUnit, int coordinateX, int coordinateY);
    ~Element();

    /* Operations overload */

    friend ostream &operator<<(ostream &os, const Element &element);
};

#include "Element.cxx"

#endif // ELEMENT_hpp
