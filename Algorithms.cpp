//fadi.nujedat@msmail.ariel.ac.il
#include "Algorithms.hpp"
#include "DataStructures.hpp"

namespace graph {

using namespace datastructures;

// ================= Private Relax Helper =================

/**
 * @brief Tries to relax the edge from u to v with given weight.
 * 
 * If the current known distance to v is greater than the distance to u plus the weight,
 * then update dist[v] and set u as the parent of v.
 */
bool Algorithms::relax(int u, int v, int weight, int* dist, int* parent) {
    if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        parent[v] = u;
        return true;
    }
    return false;
}

// ================= BFS =================

/**
 * @brief Performs Breadth-First Search starting from a given vertex.
 * 
 * Builds a BFS tree by visiting neighbors level by level using a custom queue.
 */
Graph Algorithms::bfs(const Graph& graph, int startVertex) {
    Graph bfsTree(graph.getNumVertices());
    Queue queue(graph.getNumVertices());
    bool* visited = new bool[graph.getNumVertices()]();

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int current = queue.pop();
        Node* neighbor = graph.getAdjList(current);

        // Visit all unvisited neighbors
        while (neighbor) {
            int v = neighbor->vertex;
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
                bfsTree.addEdge(current, v, neighbor->weight);
            }
            neighbor = neighbor->next;
        }
    }

    delete[] visited;
    return bfsTree;
}

// ================= DFS Helper =================

/**
 * @brief Recursive helper function for Depth-First Search.
 */
void dfsHelper(const Graph& graph, Graph& dfsTree, bool* visited, int current) {
    visited[current] = true;
    Node* neighbor = graph.getAdjList(current);

    // Explore each unvisited neighbor
    while (neighbor) {
        int v = neighbor->vertex;
        if (!visited[v]) {
            dfsTree.addEdge(current, v, neighbor->weight);
            dfsHelper(graph, dfsTree, visited, v);
        }
        neighbor = neighbor->next;
    }
}

// ================= DFS =================

/**
 * @brief Performs Depth-First Search starting from a given vertex.
 * 
 * Builds a DFS tree by visiting as deep as possible into the graph.
 */
Graph Algorithms::dfs(const Graph& graph, int startVertex) {
    Graph dfsTree(graph.getNumVertices());
    bool* visited = new bool[graph.getNumVertices()]();

    dfsHelper(graph, dfsTree, visited, startVertex);

    delete[] visited;
    return dfsTree;
}

// ================= Dijkstra =================

/**
 * @brief Finds the shortest paths from the start vertex using Dijkstra's algorithm.
 * 
 * Uses a custom priority queue to always process the closest vertex next.
 */
Graph Algorithms::dijkstra(const Graph& graph, int startVertex) {
    int n = graph.getNumVertices();
    Graph dijkstraTree(n);

    int* dist = new int[n];
    int* parent = new int[n];
    bool* visited = new bool[n]();

    for (int i = 0; i < n; i++) {
        dist[i] = 1e9; // Simulate infinity
        parent[i] = -1;
    }
    dist[startVertex] = 0;

    PriorityQueue pq(n);
    for (int i = 0; i < n; i++) {
        pq.insert(i, dist[i]);
    }

    while (!pq.empty()) {
        int u = pq.extractMin();
        visited[u] = true;

        Node* neighbor = graph.getAdjList(u);
        while (neighbor) {
            int v = neighbor->vertex;
            int w = neighbor->weight;

            // Try to relax the neighbor
            if (!visited[v] && relax(u, v, w, dist, parent)) {
                pq.decreasePriority(v, dist[v]);
            }
            neighbor = neighbor->next;
        }
    }

    // Build the shortest-path tree from parent array
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            int w = graph.getEdgeWeight(i, parent[i]);
            dijkstraTree.addEdge(i, parent[i], w);
        }
    }

    delete[] dist;
    delete[] parent;
    delete[] visited;
    return dijkstraTree;
}

// ================= Prim =================

/**
 * @brief Finds a Minimum Spanning Tree (MST) using Prim's algorithm.
 * 
 * Always expands the MST by adding the minimum-weight edge.
 */
Graph Algorithms::prim(const Graph& graph) {
    int n = graph.getNumVertices();
    Graph mst(n);

    int* key = new int[n];
    int* parent = new int[n];
    bool* inMST = new bool[n]();

    for (int i = 0; i < n; i++) {
        key[i] = 1e9; // Simulate infinity
        parent[i] = -1;
    }
    key[0] = 0;

    PriorityQueue pq(n);
    for (int i = 0; i < n; i++) {
        pq.insert(i, key[i]);
    }

    while (!pq.empty()) {
        int u = pq.extractMin();
        inMST[u] = true;

        Node* neighbor = graph.getAdjList(u);
        while (neighbor) {
            int v = neighbor->vertex;
            int w = neighbor->weight;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.decreasePriority(v, key[v]);
            }
            neighbor = neighbor->next;
        }
    }

    // Build MST from parent array
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            int w = graph.getEdgeWeight(i, parent[i]);
            mst.addEdge(i, parent[i], w);
        }
    }

    delete[] key;
    delete[] parent;
    delete[] inMST;
    return mst;
}

// ================= Kruskal =================

/**
 * @brief Finds a Minimum Spanning Tree (MST) using Kruskal's algorithm.
 * 
 * Sorts all edges and greedily adds the smallest edge that doesn't form a cycle.
 */
struct Edge {
    int u, v, w;
};

Graph Algorithms::kruskal(const Graph& graph) {
    int n = graph.getNumVertices();
    Edge* edges = new Edge[n * n];
    int edgeCount = 0;

    // Collect all edges
    for (int u = 0; u < n; u++) {
        Node* neighbor = graph.getAdjList(u);
        while (neighbor) {
            int v = neighbor->vertex;
            if (u < v) {
                edges[edgeCount++] = {u, v, neighbor->weight};
            }
            neighbor = neighbor->next;
        }
    }

    // Simple bubble sort by weight
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    UnionFind uf(n);
    Graph mst(n);
    int edgesUsed = 0;

    // Add edges while avoiding cycles
    for (int i = 0; i < edgeCount && edgesUsed < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            mst.addEdge(u, v, edges[i].w);
            uf.unite(u, v);
            edgesUsed++;
        }
    }

    delete[] edges;
    return mst;
}

} // namespace graph
