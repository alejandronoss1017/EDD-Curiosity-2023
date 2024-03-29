#if !defined(DATA_STRUCTURES_GRAPH_NODE_HPP)
#define DATA_STRUCTURES_GRAPH_NODE_HPP

#include <vector>

using namespace std;

/**
 *
 * @brief Node class for Graphs, contains id, matrixId and data.
 *
 * Id is the id of the node in the graph.
 *
 * MatrixId is the id of the node in the adjacency matrix.
 *
 * data is the data of the node.
 *
 * @tparam K is the type of the Id of the node.
 * @tparam T is the data of the node.
 *
 */
template <typename K, typename T>
class Node
{
private:
    // Id of the node.
    K id;
    // Id of the adjacency matrix.
    int matrixId;
    // Data of the node.
    T data;

public:
    /* Constructors and Destructors */

    Node();
    Node(T data);
    Node(K id, int matrixId, T data);

    ~Node();

    /* Getters and Setters */

    K getId() const;
    void setId(K id);

    int getMatrixId() const;
    void setMatrixId(int matrixId);

    T getData() const;
    void setData(T data);

    /* Operators */

    bool operator==(const Node<K, T> &otherNode) const;

    bool operator!=(const Node<K, T> &otherNode) const;

    bool operator<(const Node<K, T> &otherNode) const;

    bool operator>(const Node<K, T> &otherNode) const;

    template <typename U, typename L>
    friend ostream &operator<<(ostream &os, const Node<U, L> &node);

    /* Methods */
};

#include "Node.cpp"

#endif // DATA_STRUCTURES_GRAPH_NODE_HPP
