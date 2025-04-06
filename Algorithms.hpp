//fadi.nujedat@msmail.ariel.ac.il
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace graph {

/**
 * @brief A class containing graph algorithms.
 */
class Algorithms {
public:
    /**
     * @brief Performs Breadth-First Search (BFS) from a given start vertex.
     * @param graph The input graph.
     * @param startVertex The starting vertex.
     * @return Graph The BFS tree.
     */
    static Graph bfs(const Graph& graph, int startVertex);

    /**
     * @brief Performs Depth-First Search (DFS) from a given start vertex.
     * @param graph The input graph.
     * @param startVertex The starting vertex.
     * @return Graph The DFS tree.
     */
    static Graph dfs(const Graph& graph, int startVertex);

    /**
     * @brief Finds the shortest paths from a start vertex using Dijkstra's algorithm.
     * @param graph The input graph.
     * @param startVertex The starting vertex.
     * @return Graph The shortest paths tree.
     */
    static Graph dijkstra(const Graph& graph, int startVertex);

    /**
     * @brief Finds a Minimum Spanning Tree (MST) using Prim's algorithm.
     * @param graph The input graph.
     * @return Graph The MST found by Prim's algorithm.
     */
    static Graph prim(const Graph& graph);

    /**
     * @brief Finds a Minimum Spanning Tree (MST) using Kruskal's algorithm.
     * @param graph The input graph.
     * @return Graph The MST found by Kruskal's algorithm.
     */
    static Graph kruskal(const Graph& graph);
private:
    /**
     * @brief Tries to relax the edge from u to v with given weight.
     * @param u Source vertex.
     * @param v Destination vertex.
     * @param weight Weight of the edge.
     * @param dist Distance array.
     * @param parent Parent array.
     * @return true if relaxation occurred, false otherwise.
     */
    static bool relax(int u, int v, int weight, int* dist, int* parent);
};
} // namespace graph

#endif
