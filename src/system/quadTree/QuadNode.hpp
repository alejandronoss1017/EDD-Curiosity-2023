#if !defined(EDD_CURIOSITY_QUAD_NODE_HPP)
#define EDD_CURIOSITY_QUAD_NODE_HPP

#include <array>
#include "../../curiosity/coordinate/Coordinate.hpp"

using namespace std;

class QuadNode
{
protected:
    Coordinate coordinate;

    // 4 children, 0 = SW (South West), 1 = NW (North West), 2 = SE (South East), 3 = NE (North East)
    array<QuadNode *, 4> children;

public:
    /*  Constructors and Destructors  */
    QuadNode();

    QuadNode(const Coordinate &coordinate);

    QuadNode(const Coordinate &coordinate, const array<QuadNode *, 4> &children);

    ~QuadNode();

    /*  Getters and Setters  */
    Coordinate getCoordinate();

    double getCoordinateX();

    double getCoordinateY();

    array<QuadNode *, 4> getChildren();

    QuadNode *getChild(const int &index);

    void setCoordinateX(const double &coordinateX);

    void setCoordinateY(const double &coordinateY);

    void setChildren(const array<QuadNode *, 4> &children);

    void setChild(const int &index, QuadNode *child);

    /*  Other Methods  */
    bool isLeaf() const;
};

// This must removed when compiling in CMake
#include "QuadNode.cpp"

#endif // EDD_CURIOSITY_QUAD_NODE_HPP
