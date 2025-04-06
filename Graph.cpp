//fadi.nujedat@msmail.ariel.ac.il
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {

/**
 * @brief Constructs a graph with a given number of vertices.
 */
Graph::Graph(int vertices) : numVertices(vertices) {
    adjList = new Node*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjList[i] = nullptr;
    }
}

/**
 * @brief Destructor to free all nodes in the graph.
 */
Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        Node* current = adjList[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
}

/**
 * @brief Adds an undirected edge between two vertices.
 */
void Graph::addEdge(int src, int dest, int weight) {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
        throw std::out_of_range("Invalid vertex index");

    if (!hasEdge(src, dest)) {
        Node* newNode = new Node{dest, weight, adjList[src]};
        adjList[src] = newNode;

        newNode = new Node{src, weight, adjList[dest]};
        adjList[dest] = newNode;
    }
}

/**
 * @brief Removes the edge between two vertices if it exists.
 */
void Graph::removeEdge(int src, int dest) {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
        throw std::out_of_range("Invalid vertex index");

    Node** curr = &adjList[src];
    while (*curr) {
        if ((*curr)->vertex == dest) {
            Node* temp = *curr;
            *curr = (*curr)->next;
            delete temp;
            break;
        }
        curr = &((*curr)->next);
    }

    curr = &adjList[dest];
    while (*curr) {
        if ((*curr)->vertex == src) {
            Node* temp = *curr;
            *curr = (*curr)->next;
            delete temp;
            break;
        }
        curr = &((*curr)->next);
    }
}

/**
 * @brief Prints the graph's adjacency list.
 */
void Graph::printGraph() const {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vertex " << i << ":";
        Node* temp = adjList[i];
        while (temp) {
            std::cout << " -> (" << temp->vertex << ", " << temp->weight << ")";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Checks if there is an edge between two vertices.
 */
bool Graph::hasEdge(int src, int dest) const {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
        return false;

    Node* temp = adjList[src];
    while (temp) {
        if (temp->vertex == dest)
            return true;
        temp = temp->next;
    }
    return false;
}

/**
 * @brief Returns the weight of the edge between two vertices.
 */
int Graph::getEdgeWeight(int src, int dest) const {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
        return 0;

    Node* temp = adjList[src];
    while (temp) {
        if (temp->vertex == dest)
            return temp->weight;
        temp = temp->next;
    }
    return 0;
}

/**
 * @brief Returns the number of vertices.
 */
int Graph::getNumVertices() const {
    return numVertices;
}

/**
 * @brief Returns the adjacency list of a given vertex.
 */
Node* Graph::getAdjList(int vertex) const {
    if (vertex < 0 || vertex >= numVertices)
        throw std::out_of_range("Invalid vertex index");
    return adjList[vertex];
}

} // namespace graph
