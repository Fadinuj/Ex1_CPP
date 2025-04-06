# README

## Ex1 - Graph Algorithms Project

This project implements basic graph algorithms using an adjacency list structure, with custom data structures (without STL):
- Graph Representation: Using a `Node*` linked list for each vertex.
- Algorithms:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Dijkstra's Shortest Paths
  - Prim's Minimum Spanning Tree (MST)
  - Kruskal's Minimum Spanning Tree (MST)

All algorithms return new graphs as their results.

---

## Project Structure

| File | Purpose |
|-----|---------|
| `Graph.hpp / Graph.cpp` | Graph implementation |
| `Algorithms.hpp / Algorithms.cpp` | Algorithms implementation |
| `DataStructures.hpp / DataStructures.cpp` | Custom Queue, PriorityQueue, UnionFind |
| `main.cpp` | Demonstrates the algorithms on a sample graph |
| `test_algorithms.cpp` | Unit tests using Doctest framework |
| `Makefile` | Compilation and testing automation |
| `doctest.h` | Testing library (header-only) |

---

## Build Instructions

To compile the project:

```bash
make
```

This generates an executable called:

```bash
./main
```

To run the demo:

```bash
./main
```

---

## Running Tests

To compile and run all tests:

```bash
make test
./test_algorithms
```

The tests will check:

- BFS correctness
- DFS correctness
- Dijkstra's paths
- Prim's MST
- Kruskal's MST

---

## Cleaning the Project

To remove all compiled files:

```bash
make clean
```

---

## Memory Check (Valgrind)

To run the program with full memory leak checks:

```bash
make valgrind
```

You should see:

```
All heap blocks were freed -- no leaks are possible
```

---

## Notes

- No STL containers are used (no `std::queue`, `std::priority_queue`, etc.).
- All data structures (Queue, PriorityQueue, UnionFind) are implemented manually.
- All functions return new graphs instead of modifying the input graph.

---

## Project Status

| Part | Status |
|------|--------|
| Compilation | OK |
| Algorithms | OK |
| Tests (Doctest) | OK |
| Memory Leak Check | OK |
| Compliance with Restrictions | OK |

---

Good Luck!
