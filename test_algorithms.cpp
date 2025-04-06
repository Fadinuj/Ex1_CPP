//fadi.nujedat@msmail.ariel.ac.il
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

/**
 * @brief Helper function to create a sample graph.
 */
Graph createSampleGraph() {
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 5, 7);
    return g;
}

/**
 * @brief Helper function to check if two vertices are connected.
 */
bool connected(const Graph& g, int u, int v) {
    Node* neighbor = g.getAdjList(u);
    while (neighbor) {
        if (neighbor->vertex == v) {
            return true;
        }
        neighbor = neighbor->next;
    }
    return false;
}

/**
 * @brief Test that BFS builds a connected tree.
 */
TEST_CASE("BFS returns a connected tree") {
    Graph g = createSampleGraph();
    Graph bfsTree = Algorithms::bfs(g, 0);

    int connectedEdges = 0;
    for (int i = 0; i < bfsTree.getNumVertices(); i++) {
        Node* neighbor = bfsTree.getAdjList(i);
        while (neighbor) {
            connectedEdges++;
            neighbor = neighbor->next;
        }
    }

    CHECK(connectedEdges >= bfsTree.getNumVertices() - 1);
}

/**
 * @brief Test that DFS builds a connected tree.
 */
TEST_CASE("DFS returns a connected tree") {
    Graph g = createSampleGraph();
    Graph dfsTree = Algorithms::dfs(g, 0);

    int connectedEdges = 0;
    for (int i = 0; i < dfsTree.getNumVertices(); i++) {
        Node* neighbor = dfsTree.getAdjList(i);
        while (neighbor) {
            connectedEdges++;
            neighbor = neighbor->next;
        }
    }

    CHECK(connectedEdges >= dfsTree.getNumVertices() - 1);
}

/**
 * @brief Test that Dijkstra returns valid shortest paths from vertex 0.
 */
TEST_CASE("Dijkstra returns valid shortest paths") {
    Graph g = createSampleGraph();
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);

    // In Dijkstra tree from vertex 0:
    CHECK(connected(dijkstraTree, 0, 1)); // 0 -> 1
    CHECK(connected(dijkstraTree, 1, 2)); // 1 -> 2
    CHECK(connected(dijkstraTree, 2, 4)); // 2 -> 4
    CHECK(connected(dijkstraTree, 4, 3)); // 4 -> 3
    CHECK(connected(dijkstraTree, 3, 5)); // 3 -> 5
}

/**
 * @brief Test that Prim returns a valid MST.
 */
TEST_CASE("Prim returns a valid MST") {
    Graph g = createSampleGraph();
    Graph primMST = Algorithms::prim(g);

    int edgeCount = 0;
    for (int i = 0; i < primMST.getNumVertices(); i++) {
        Node* neighbor = primMST.getAdjList(i);
        while (neighbor) {
            edgeCount++;
            neighbor = neighbor->next;
        }
    }

    // Each edge counted twice
    CHECK(edgeCount / 2 == primMST.getNumVertices() - 1);
}

/**
 * @brief Test that Kruskal returns a valid MST.
 */
TEST_CASE("Kruskal returns a valid MST") {
    Graph g = createSampleGraph();
    Graph kruskalMST = Algorithms::kruskal(g);

    int edgeCount = 0;
    for (int i = 0; i < kruskalMST.getNumVertices(); i++) {
        Node* neighbor = kruskalMST.getAdjList(i);
        while (neighbor) {
            edgeCount++;
            neighbor = neighbor->next;
        }
    }

    // Each edge counted twice
    CHECK(edgeCount / 2 == kruskalMST.getNumVertices() - 1);
}

/**
 * @brief Main function to run all tests.
 */
int main(int argc, char** argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int res = context.run(); // Run all tests
    if (context.shouldExit()) {
        return res;
    }
    return res;
}
