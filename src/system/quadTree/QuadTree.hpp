#if !defined(EDD_CURIOSITY_QUAD_TREE_HPP)
#define EDD_CURIOSITY_QUAD_TREE_HPP

#include "QuadNode.hpp"

#include <ostream>

using namespace std;
class QuadTree
{
protected:
    QuadNode *root;

    int maxDepth;
    int maxPoints;
    int nodeCount;
    int pointCount;

private:
    QuadNode *insertHelper(QuadNode *node, const Coordinate &coordinate);
    QuadNode *removeHelper(QuadNode *node, const Coordinate &coordinate);
    QuadNode *findMinHelper(QuadNode *node);
    QuadNode *findMaxHelper(QuadNode *node);
    QuadNode *findHelper(QuadNode *node, const Coordinate &coordinate);
    QuadNode *clearHelper(QuadNode *node);
    void traverseInOrderHelper(QuadNode *node, ostream &os) const;
    void traversePreOrderHelper();
    void traversePostOrderHelper();
    bool equals(const QuadNode *node1, const QuadNode *node2);

public:
    QuadTree();
    QuadTree(const Coordinate &coordinate);
    ~QuadTree();

    bool insert(const Coordinate &coordinate);
    bool remove(const Coordinate &coordinate);
    bool find(const Coordinate &coordinate);
    bool empty();
    void clear();
    int height();
    int size();
    void traverseInOrder();
    void traversePreOrder();
    void traversePostOrder();

    friend ostream &operator<<(ostream &os, const QuadTree &tree);
};

// This must removed when compiling in CMake
#include "QuadTree.cpp"

#endif // EDD_CURIOSITY_QUAD_TREE_HPP