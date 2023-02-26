#include "Element.hpp"

Element::Element(elementTypes componentType, int size, measureType measureUnit, int coordinateX, int coordinateY)
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

elementTypes Element::GetComponentType() const
{
    return componentType;
}

void Element::SetComponentType(elementTypes componentType)
{
    componentType = componentType;
}

int Element::GetSize() const
{
    return size;
}

void Element::SetSize(int size)
{
    size = size;
}

measureType Element::GetMeasureUnit() const
{
    return measureUnit;
}

void Element::SetMeasureUnit(measureType measureUnit)
{
    measureUnit = measureUnit;
}

int Element::GetCoordinateX() const
{
    return coordinateX;
}

void Element::SetCoordinateX(int coordinateX)
{
    coordinateX = coordinateX;
}

int Element::GetCoordinateY() const
{
    return coordinateY;
}

void Element::SetCoordinateY(int coordinateY)
{
    coordinateY = coordinateY;
}
