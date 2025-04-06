//fadi.nujedat@msmail.ariel.ac.il
#ifndef DATASTRUCTURES_HPP
#define DATASTRUCTURES_HPP

namespace datastructures {

/**
 * @brief A simple queue implementation using an array.
 */
class Queue {
private:
    int* arr;        ///< Array to store elements
    int capacity;    ///< Maximum number of elements
    int front;       ///< Index of front element
    int rear;        ///< Index of rear element
    int count;       ///< Current size of the queue

public:
    Queue(int size);
    ~Queue();

    void push(int item);

    /**
     * @brief Removes and returns the front item.
     * @return int The item removed.
     */
    int pop();

    int peek() const;
    bool empty() const;
    bool full() const;
};

/**
 * @brief A simple stack implementation using an array.
 */
class Stack {
private:
    int* arr;        ///< Array to store elements
    int capacity;    ///< Maximum number of elements
    int topIndex;    ///< Index of the top element

public:
    Stack(int size);
    ~Stack();

    void push(int item);

    /**
     * @brief Removes and returns the top item.
     * @return int The item removed.
     */
    int pop();

    int top() const;
    bool empty() const;
    bool full() const;
};

/**
 * @brief A priority queue implemented using a min-heap.
 */
class PriorityQueue {
private:
    int* data;
    int* priority;
    int capacity;
    int size;

    void swap(int i, int j);
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue(int capacity);
    ~PriorityQueue();

    void insert(int item, int pri);
    int extractMin();
    bool empty() const;
    void decreasePriority(int item, int newPriority);
};

/**
 * @brief A Union-Find (Disjoint Set Union) data structure.
 */
class UnionFind {
private:
    int* parent;
    int* rank;
    int size;

public:
    UnionFind(int n);
    ~UnionFind();

    int find(int x);
    void unite(int x, int y);
};

} // namespace datastructures

#endif
