//fadi.nujedat@msmail.ariel.ac.il
#include "DataStructures.hpp"
#include <stdexcept>

namespace datastructures {

// ================= Queue =================
Queue::Queue(int size) : capacity(size), front(0), rear(-1), count(0) {
    arr = new int[capacity];
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::push(int item) {
    if (full()) throw std::overflow_error("Queue Full");
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int Queue::pop() {
    if (empty()) throw std::underflow_error("Queue Empty");
    int item = arr[front];
    front = (front + 1) % capacity;
    count--;
    return item;
}

int Queue::peek() const {
    if (empty()) throw std::underflow_error("Queue Empty");
    return arr[front];
}

bool Queue::empty() const {
    return count == 0;
}

bool Queue::full() const {
    return count == capacity;
}

// ================= Stack =================
Stack::Stack(int size) : capacity(size), topIndex(-1) {
    arr = new int[capacity];
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int item) {
    if (full()) throw std::overflow_error("Stack Full");
    arr[++topIndex] = item;
}

int Stack::pop() {
    if (empty()) throw std::underflow_error("Stack Empty");
    return arr[topIndex--];
}

int Stack::top() const {
    if (empty()) throw std::underflow_error("Stack Empty");
    return arr[topIndex];
}

bool Stack::empty() const {
    return topIndex == -1;
}

bool Stack::full() const {
    return topIndex == capacity - 1;
}

// ================= PriorityQueue =================
PriorityQueue::PriorityQueue(int cap) : capacity(cap), size(0) {
    data = new int[capacity];
    priority = new int[capacity];
}

PriorityQueue::~PriorityQueue() {
    delete[] data;
    delete[] priority;
}

void PriorityQueue::swap(int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    int tmpP = priority[i];
    priority[i] = priority[j];
    priority[j] = tmpP;
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (priority[index] < priority[parent]) {
            swap(index, parent);
            index = parent;
        } else break;
    }
}

void PriorityQueue::heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if (left < size && priority[left] < priority[smallest])
        smallest = left;
    if (right < size && priority[right] < priority[smallest])
        smallest = right;
    if (smallest != index) {
        swap(index, smallest);
        heapifyDown(smallest);
    }
}

void PriorityQueue::insert(int item, int pri) {
    if (size == capacity) throw std::overflow_error("PriorityQueue Full");
    data[size] = item;
    priority[size] = pri;
    heapifyUp(size);
    size++;
}

int PriorityQueue::extractMin() {
    if (empty()) throw std::underflow_error("PriorityQueue Empty");
    int minItem = data[0];
    data[0] = data[size - 1];
    priority[0] = priority[size - 1];
    size--;
    heapifyDown(0);
    return minItem;
}

bool PriorityQueue::empty() const {
    return size == 0;
}

void PriorityQueue::decreasePriority(int item, int newPriority) {
    for (int i = 0; i < size; i++) {
        if (data[i] == item && newPriority < priority[i]) {
            priority[i] = newPriority;
            heapifyUp(i);
            break;
        }
    }
}

// ================= UnionFind =================
UnionFind::UnionFind(int n) : size(n) {
    parent = new int[n];
    rank = new int[n]();
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

int UnionFind::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void UnionFind::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

} // namespace datastructures
