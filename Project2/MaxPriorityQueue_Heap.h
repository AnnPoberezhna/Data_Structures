#ifndef MAXPRIORITYQUEUE_HEAP_H
#define MAXPRIORITYQUEUE_HEAP_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class MaxPriorityQueue_Heap {
private:
    struct Element {
        T value;
        int priority;
        int timestamp;  // Insertion time for tie-breaking

        bool operator>(const Element& other) const {
            if (priority != other.priority)
                return priority > other.priority;  // Higher priority = greater element
            return timestamp < other.timestamp;   // FIFO for equal priorities
        }
    };

    Element* heap;
    int size;
    int capacity;
    int current_timestamp;


    void resize();
    void heapify_up(int index);
    void heapify_down(int index);
    int find_index(T value) const;

public:
    MaxPriorityQueue_Heap();
    ~MaxPriorityQueue_Heap();

    vector<T> get_values() const;
    void insert(T value, int priority);
    T extract_max();
    T peek() const;
    void modify_key(T value, int new_priority);
    int return_size() const;
    void display() const;
};

// Constructor
template <typename T>
MaxPriorityQueue_Heap<T>::MaxPriorityQueue_Heap() {
    capacity = 10;
    size = 0;
    current_timestamp = 0;
    heap = new Element[capacity];
}

// Destructor
template <typename T>
MaxPriorityQueue_Heap<T>::~MaxPriorityQueue_Heap() {
    delete[] heap;
}

//Get keys

template <typename T>
std::vector<T> MaxPriorityQueue_Heap<T>::get_values() const {
    std::vector<T> values;
    for (int i = 0; i < size; ++i) {
        values.push_back(heap[i].value);
    }
    return values;
}

// Resize
template <typename T>
void MaxPriorityQueue_Heap<T>::resize() {
    capacity *= 2;
    Element* newHeap = new Element[capacity];
    for (int i = 0; i < size; ++i)
        newHeap[i] = heap[i];
    delete[] heap;
    heap = newHeap;
}

// Heapify Up
template <typename T>
void MaxPriorityQueue_Heap<T>::heapify_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);  // Swap with parent if higher priority
            index = parent;
        } else break;
    }
}

// Heapify Down
template <typename T>
void MaxPriorityQueue_Heap<T>::heapify_down(int index) {
    while (2 * index + 1 < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else break;
    }
}

// Insert
template <typename T>
void MaxPriorityQueue_Heap<T>::insert(T value, int priority) {
    if (size == capacity) resize();
    heap[size] = {value, priority, current_timestamp++};
    heapify_up(size);
    size++;
}

// Extract Max
template <typename T>
T MaxPriorityQueue_Heap<T>::extract_max() {
    if (size == 0) throw runtime_error("Queue is empty");
    T maxValue = heap[0].value;
    heap[0] = heap[size - 1];
    size--;
    heapify_down(0);
    return maxValue;
}

// Peek
template <typename T>
T MaxPriorityQueue_Heap<T>::peek() const {
    if (size == 0) throw runtime_error("Queue is empty");
    return heap[0].value;
}

// Modify Key
template <typename T>
void MaxPriorityQueue_Heap<T>::modify_key(T value, int new_priority) {
    int index = find_index(value);
    if (index == -1) throw runtime_error("Element not found");

    int old_priority = heap[index].priority;
    heap[index].priority = new_priority;

    if (new_priority > old_priority)
        heapify_up(index);
    else
        heapify_down(index);
}

// Find Index
template <typename T>
int MaxPriorityQueue_Heap<T>::find_index(T value) const {
    for (int i = 0; i < size; ++i)
        if (heap[i].value == value)
            return i;
    return -1;
}

// Return Size
template <typename T>
int MaxPriorityQueue_Heap<T>::return_size() const {
    return size;
}

// Display
template <typename T>
void MaxPriorityQueue_Heap<T>::display() const {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << "(" << heap[i].value << ", p=" << heap[i].priority << ")";
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

#endif


