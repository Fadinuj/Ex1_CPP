//fadi.nujedat@msmail.ariel.ac.il
#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {

/**
 * @brief Node structure representing a neighbor in the adjacency list.
 */
struct Node {
    int vertex;     ///< The destination vertex
    int weight;     ///< The weight of the edge
    Node* next;     ///< Pointer to the next neighbor
};

/**
 * @brief Graph class represented by an adjacency list.
 */
class Graph {
private:
    int numVertices; ///< Number of vertices
    Node** adjList;  ///< Array of pointers to the adjacency lists

public:
    /**
     * @brief Constructs a graph with a given number of vertices.
     * @param vertices Number of vertices.
     */
    Graph(int vertices);

    /**
     * @brief Destructor to free the graph memory.
     */
    ~Graph();

    /**
     * @brief Adds an undirected edge between two vertices with a given weight.
     * @param src Source vertex.
     * @param dest Destination vertex.
     * @param weight Weight of the edge (default is 1).
     */
    void addEdge(int src, int dest, int weight = 1);

    /**
     * @brief Removes the edge between two vertices.
     * @param src Source vertex.
     * @param dest Destination vertex.
     */
    void removeEdge(int src, int dest);

    /**
     * @brief Prints the graph adjacency list.
     */
    void printGraph() const;

    /**
     * @brief Checks if an edge exists between two vertices.
     * @param src Source vertex.
     * @param dest Destination vertex.
     * @return true if the edge exists, false otherwise.
     */
    bool hasEdge(int src, int dest) const;

    /**
     * @brief Returns the weight of the edge between two vertices.
     * @param src Source vertex.
     * @param dest Destination vertex.
     * @return Weight of the edge if exists, otherwise 0.
     */
    int getEdgeWeight(int src, int dest) const;

    /**
     * @brief Returns the number of vertices in the graph.
     * @return int Number of vertices.
     */
    int getNumVertices() const;

    /**
     * @brief Returns the adjacency list of a given vertex.
     * @param vertex The vertex to get neighbors of.
     * @return Pointer to the head of the adjacency list.
     */
    Node* getAdjList(int vertex) const;
};

} // namespace graph

#endif
