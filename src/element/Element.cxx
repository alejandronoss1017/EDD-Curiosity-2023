#include "Element.hpp"

Element::Element() = default;

Element::Element(elementTypes componentType, int size, measureType measureUnit, double coordinateX, double coordinateY)
{
    this->componentType = componentType;
    this->size = size;
    this->measureUnit = measureUnit;
    this->coordinate = Coordinate(coordinateX, coordinateY);
}

Element::~Element()
{
}

ostream &operator<<(ostream &os, const Element &element)
{
    os << "Componente: " << elementType2Str(element.componentType) << endl
       << "Tamaño: " << element.size << endl
       << "Unidad de medidad: " << measureType2String(element.measureUnit) << endl
       << element.coordinate << endl;
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

double Element::GetCoordinateX() const
{
    return coordinate.GetPosX();
}

void Element::SetCoordinateX(double coordinateX)
{
    Element::coordinate.SetPosX(coordinateX);
}

double Element::GetCoordinateY() const
{
    return coordinate.GetPosY();
}

void Element::SetCoordinateY(double coordinateY)
{
    Element::coordinate.SetPosY(coordinateY);
}

const Coordinate &Element::getCoordinate() const
{
    return coordinate;
}

void Element::setCoordinate(const Coordinate &coordinate)
{
    Element::coordinate = coordinate;
}
