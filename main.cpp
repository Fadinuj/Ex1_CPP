//fadi.nujedat@msmail.ariel.ac.il
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace graph;

/**
 * @brief Main function to demonstrate graph algorithms.
 */
int main() {
    std::cout << "Graph Algorithms Demo\n\n";

    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 5, 7);

    // Print the original graph
    std::cout << "=== Original Graph ===\n";
    g.printGraph();
    std::cout << std::endl;

    // Perform BFS
    std::cout << "=== BFS Tree from Vertex 0 ===\n";
    Graph bfsTree = Algorithms::bfs(g, 0);
    bfsTree.printGraph();
    std::cout << std::endl;

    // Perform DFS
    std::cout << "=== DFS Tree from Vertex 0 ===\n";
    Graph dfsTree = Algorithms::dfs(g, 0);
    dfsTree.printGraph();
    std::cout << std::endl;

    // Perform Dijkstra
    std::cout << "=== Dijkstra's Shortest Paths from Vertex 0 ===\n";
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree.printGraph();
    std::cout << std::endl;

    // Perform Prim
    std::cout << "=== Prim's Minimum Spanning Tree ===\n";
    Graph primMST = Algorithms::prim(g);
    primMST.printGraph();
    std::cout << std::endl;

    // Perform Kruskal
    std::cout << "=== Kruskal's Minimum Spanning Tree ===\n";
    Graph kruskalMST = Algorithms::kruskal(g);
    kruskalMST.printGraph();
    std::cout << std::endl;

    return 0;
}
