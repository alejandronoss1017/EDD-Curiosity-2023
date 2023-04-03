#include "QuadNode.hpp"

QuadNode::QuadNode() = default;

QuadNode::QuadNode(const Coordinate &coordinate)
{
    QuadNode::coordinate = coordinate;
    QuadNode::children.fill(nullptr);
    QuadNode::element = Element();
}

QuadNode::QuadNode(const Coordinate &coordinate, const Element &element)
{
    QuadNode::coordinate = coordinate;
    QuadNode::children.fill(nullptr);
    QuadNode::element = element;
}

QuadNode::QuadNode(const Coordinate &coordinate, const array<QuadNode *, 4> &children)
{
    QuadNode::coordinate = coordinate;
    QuadNode::children = children;
    QuadNode::element = Element();
}

QuadNode::QuadNode(const Coordinate &coordinate, const Element &element, const array<QuadNode *, 4> &children)
{
    QuadNode::coordinate = coordinate;
    QuadNode::element = element;
    QuadNode::children = children;
}

QuadNode::~QuadNode() = default;

Coordinate QuadNode::getCoordinate()
{
    return QuadNode::coordinate;
}

double QuadNode::getCoordinateX()
{
    return QuadNode::coordinate.GetPosX();
}

double QuadNode::getCoordinateY()
{
    return QuadNode::coordinate.GetPosY();
}

array<QuadNode *, 4> QuadNode::getChildren()
{
    return QuadNode::children;
}
QuadNode *QuadNode::getChild(const int &index)
{
    return QuadNode::children[index];
}

void QuadNode::setCoordinateX(const double &coordinateX)
{
    QuadNode::coordinate.SetPosX(coordinateX);
}

void QuadNode::setCoordinateY(const double &coordinateY)
{
    QuadNode::coordinate.SetPosY(coordinateY);
}

void QuadNode::setChildren(const array<QuadNode *, 4> &children)
{
    QuadNode::children = children;
}

void QuadNode::setChild(const int &index, QuadNode *child)
{
    QuadNode::children[index] = child;
}

bool QuadNode::isLeaf() const
{
    for (auto &&child : QuadNode::children)
    {
        if (child != nullptr)
        {
            return false;
        }
    }
    return true;
}

const Element &QuadNode::getElement() const
{
    return element;
}

void QuadNode::setElement(const Element &element)
{
    QuadNode::element = element;
}
