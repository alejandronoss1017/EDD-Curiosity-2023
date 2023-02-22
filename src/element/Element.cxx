#include "Element.hpp"

Element::Element(elementTypes componentType, int size, string measureUnit, int coordinateX, int coordinateY)
{
    this->componentType = componentType;
    this->size = size;
    this->measureUnit = measureUnit;
    this->coordinateX = coordinateX;
    this->coordinateY = coordinateY;
}

Element::~Element()
{
}

ostream &operator<<(ostream &os, const Element &element)
{
    os << "Componente: " << element.componentType << endl
       << "Tamaño: " << element.size << endl
       << "Unidad de medidad: " << element.measureUnit << endl
       << "Coordenada X: " << element.coordinateX << endl
       << "Coordenada Y: " << element.coordinateY;
    return os;
}
