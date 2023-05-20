#include "QuadTree.hpp"

QuadTree::QuadTree()
{

    QuadTree::root = nullptr;
    QuadTree::nodeCount = 0;
    QuadTree::pointCount = 0;
    QuadTree::maxPoints = 50;
    QuadTree::maxDepth = 50;
}

QuadTree::QuadTree(const Coordinate &coordinate)
{
    QuadTree::root = new QuadNode(coordinate);
    QuadTree::nodeCount = 1;
    QuadTree::pointCount = 1;
    QuadTree::maxPoints = 50;
    QuadTree::maxDepth = 50;
}

QuadTree::~QuadTree() = default;

bool QuadTree::insert(const Element &element)
{
    if (root == nullptr)
    {
        root = new QuadNode(element.getCoordinate(), element);
        nodeCount++;
        pointCount++;
        return true;
    }

    insertHelper(root, element.getCoordinate(), element);

    return true;
}

bool QuadTree::remove(const Element &element)
{
    if (root == nullptr)
    {
        return false;
    }

    removeHelper(root, element.getCoordinate());

    return true;
}

bool QuadTree::find(const Element &element)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (findHelper(root, element.getCoordinate()) == nullptr)
    {
        return false;
    }

    return true;
}

list<Element> QuadTree::search(const Coordinate &minCoordinate, const Coordinate &maxCoordinate)
{
    if (root == nullptr)
    {
        return list<Element>();
    }

    list<Element> elements;

    searchHelper(minCoordinate, maxCoordinate, root, elements);

    return elements;
}

bool QuadTree::empty()
{
    return root == nullptr;
}

void QuadTree::clear()
{
    root = clearHelper(root);
    QuadTree::nodeCount = 0;
    QuadTree::pointCount = 0;
}

int QuadTree::height()
{
    if (root == nullptr)
    {
        return 0;
    }
    return QuadTree::nodeCount;
}

QuadNode *QuadTree::insertHelper(QuadNode *node, const Coordinate &coordinate, const Element &element)
{
    if (node == nullptr)
    {
        return new QuadNode(coordinate, element);
        nodeCount++;
        pointCount++;
    }
    else
    {
        // If the point already exists, return the node
        if (coordinate.GetPosX() == node->getCoordinateX() && coordinate.GetPosY() == node->getCoordinateY())
        {
            return node;
        }
        else if (coordinate.GetPosX() < node->getCoordinateX())
        {
            if (coordinate.GetPosY() < node->getCoordinateY())
            {
                node->setChild(0, insertHelper(node->getChild(0), coordinate, element));
            }
            else
            {
                node->setChild(1, insertHelper(node->getChild(1), coordinate, element));
            }
        }
        else if (coordinate.GetPosX() > node->getCoordinateX())
        {
            if (coordinate.GetPosY() < node->getCoordinateY())
            {
                node->setChild(2, insertHelper(node->getChild(2), coordinate, element));
            }
            else
            {
                node->setChild(3, insertHelper(node->getChild(3), coordinate, element));
            }
        }
        // If coordinateX == node->getCoordinateX() && coordinateY != node->getCoordinateY()
        else
        {
            if (coordinate.GetPosY() < node->getCoordinateY())
            {
                node->setChild(0, insertHelper(node->getChild(0), coordinate, element));
            }
            else
            {
                node->setChild(3, insertHelper(node->getChild(3), coordinate, element));
            }
        }
    }
    return node;
}

QuadNode *QuadTree::removeHelper(QuadNode *node, const Coordinate &coordinate)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (coordinate.GetPosX() < node->getCoordinateX())
    {
        if (coordinate.GetPosY() < node->getCoordinateY())
        {
            node->setChild(0, removeHelper(node->getChild(0), coordinate));
        }
        else
        {
            node->setChild(1, removeHelper(node->getChild(1), coordinate));
        }
    }
    else if (coordinate.GetPosX() > node->getCoordinateX())
    {
        if (coordinate.GetPosY() < node->getCoordinateY())
        {
            node->setChild(2, removeHelper(node->getChild(2), coordinate));
        }
        else
        {
            node->setChild(3, removeHelper(node->getChild(3), coordinate));
        }
    }
    else
    {
        if (node->isLeaf())
        {
            delete node;
            node = nullptr;
            nodeCount--;
            pointCount--;
            return node;
        }
        else
        {
            QuadNode *temp = findMinHelper(node->getChild(3));
            node->setCoordinateX(temp->getCoordinateX());
            node->setCoordinateY(temp->getCoordinateY());
            node->setChild(3, removeHelper(node->getChild(3), Coordinate(temp->getCoordinateX(), temp->getCoordinateY())));
        }
    }
    return node;
}

QuadNode *QuadTree::findMinHelper(QuadNode *node)
{
    while (node != nullptr && node->getChild(0) != nullptr)
    {
        node = node->getChild(0);
    }
    return node;
}

QuadNode *QuadTree::findMaxHelper(QuadNode *node)
{
    while (node != nullptr && node->getChild(3) != nullptr)
    {
        node = node->getChild(3);
    }
    return node;
}

QuadNode *QuadTree::findHelper(QuadNode *node, const Coordinate &coordinate)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (coordinate.GetPosX() < node->getCoordinateX())
    {
        if (coordinate.GetPosY() < node->getCoordinateY())
        {
            return findHelper(node->getChild(0), coordinate);
        }
        else
        {
            return findHelper(node->getChild(1), coordinate);
        }
    }
    else if (coordinate.GetPosX() > node->getCoordinateX())
    {
        if (coordinate.GetPosY() < node->getCoordinateY())
        {
            return findHelper(node->getChild(2), coordinate);
        }
        else
        {
            return findHelper(node->getChild(3), coordinate);
        }
    }
    return node;
}

QuadNode *QuadTree::clearHelper(QuadNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    clearHelper(node->getChild(0));
    clearHelper(node->getChild(1));
    clearHelper(node->getChild(2));
    clearHelper(node->getChild(3));
    delete node;
    node = nullptr;
    return node;
}

void QuadTree::searchHelper(const Coordinate &minCoordinate, const Coordinate &maxCoordinate, QuadNode *node, list<Element> &elements)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->getCoordinateX() >= minCoordinate.GetPosX() && node->getCoordinateX() <= maxCoordinate.GetPosX() && node->getCoordinateY() >= minCoordinate.GetPosY() && node->getCoordinateY() <= maxCoordinate.GetPosY())
    {
        elements.push_back(node->getElement());
    }
    if (node->getChild(0) != nullptr && minCoordinate.GetPosX() <= node->getCoordinateX() && minCoordinate.GetPosY() <= node->getCoordinateY())
    {
        searchHelper(minCoordinate, maxCoordinate, node->getChild(0), elements);
    }
    if (node->getChild(1) != nullptr && minCoordinate.GetPosX() <= node->getCoordinateX() && maxCoordinate.GetPosY() >= node->getCoordinateY())
    {
        searchHelper(minCoordinate, maxCoordinate, node->getChild(1), elements);
    }
    if (node->getChild(2) != nullptr && maxCoordinate.GetPosX() >= node->getCoordinateX() && minCoordinate.GetPosY() <= node->getCoordinateY())
    {
        searchHelper(minCoordinate, maxCoordinate, node->getChild(2), elements);
    }
    if (node->getChild(3) != nullptr && maxCoordinate.GetPosX() >= node->getCoordinateX() && maxCoordinate.GetPosY() >= node->getCoordinateY())
    {
        searchHelper(minCoordinate, maxCoordinate, node->getChild(3), elements);
    }
}

void QuadTree::traverseInOrderHelper(QuadNode *node, ostream &os) const
{
    if (node == nullptr)
    {
        return;
    }
    traverseInOrderHelper(node->getChild(0), os);
    os << node->getCoordinateX() << " " << node->getCoordinateY() << endl;
    traverseInOrderHelper(node->getChild(1), os);
    traverseInOrderHelper(node->getChild(2), os);
    traverseInOrderHelper(node->getChild(3), os);
}

bool QuadTree::equals(const QuadNode *node1, const QuadNode *node2)
{
    return true;
}

ostream &operator<<(ostream &os, const QuadTree &tree)
{
    tree.traverseInOrderHelper(tree.root, os);
    return os;
}
