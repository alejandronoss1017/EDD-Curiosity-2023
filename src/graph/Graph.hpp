#ifndef DATA_STRUCTURES_GRAPH_HPP
#define DATA_STRUCTURES_GRAPH_HPP

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <ostream>
#include <iostream>
#include <regex>
#include <sstream>
#include <limits>

#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

/**
 * @brief Graph class, contains nodes and edges.
 *
 * Nodes is a map of nodes, where the key is the id of the node and the
 * value is the node.
 *
 * Edges is a map of edges, where the first index is the id of the relationship,
 * this id is composed by the id of the first node and the id of the second node,
 * the data type of the edge Id is string.
 *
 * @tparam K Key is the type of the key of the nodes map, same type as node Id.
 * @tparam T Data is the type of the data of the node.
 *
 *
 */
template <typename K, typename T>
class Graph
{
protected:
    /* Attributes */

    // map of nodes that contains the nodes of the graph,
    // where the key is the id of the node and the value is the node.
    map<K, Node<K, T>> nodes;

    // map of edges that contains the edges of the graph, where the key is the id of the relationship,
    // this id is composed by the id of the first node and the id of the second node,
    // the data type of the edge Id is string.
    map<string, Edge<K, T>> edges;

    // vector<vector<int>> edges;
private:
    vector<Node<K, T>> depthFirstSearchHelper(K id, vector<Node<K, T>> &result);

    vector<Node<K, T>> breadthFirstSearchHelper(K id, vector<Node<K, T>> &result, set<K> &visited);

public:
    /* Constructors and Destructors */

    Graph();
    Graph(map<K, Node<K, T>> nodes, map<string, Edge<K, T>> edges);
    ~Graph();

    /* Getters and Setters */

    map<K, Node<K, T>> getNodes() const;
    void setNodes(map<K, Node<K, T>> nodes);

    map<string, Edge<K, T>> getEdges() const;
    void setEdges(map<string, Edge<K, T>> edges);

    /* Operators */

    Graph<K, T> &operator=(const Graph<K, T> &otherGraph);

    bool operator==(const Graph &otherGraph) const;

    bool operator!=(const Graph &otherGraph) const;

    template <typename U, typename R>
    friend ostream &operator<<(ostream &os, const Graph<U, R> &graph);

    /* Methods */

    bool addNode(K id, T data);

    bool addNode(Node<K, T> node);

    bool addEdge(K id1, K id2, double weight);

    bool addEdge(K id1, K id2, double weight, bool directed);

    int getNodeIndex(K id) const;

    bool removeNode(K id);

    bool removeNode(Node<K, T> node);

    bool removeEdge(const string &id1, const string &id2);

    bool removeEdge(string id1, string id2, bool directed);

    bool removeEdge(Edge<K, T> edge);

    bool removeEdge(Edge<K, T> edge, bool directed);

    Edge<K, T> getEdge(K source, K destination);

    vector<Node<K, T>> getNeighbors(K id);

    vector<Node<K, T>> depthFirstSearch(K id);

    vector<Node<K, T>> breadthFirstSearch(K id);

    map<Node<K, T>, double> dijkstra(K startNodeId);

    vector<Node<K, T>> shortestPath(K sourceId, K destinationId);

    vector<vector<double>> floydWarshall();
};

#include "Graph.cpp"

#endif // DATA_STRUCTURES_GRAPH_HPP