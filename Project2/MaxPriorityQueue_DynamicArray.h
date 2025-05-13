#ifndef MAXPRIORITYQUEUE_DYNAMICARRAY_H
#define MAXPRIORITYQUEUE_DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class MaxPriorityQueue_DynamicArray {
private:
    struct Element {
        T value;
        int priority;
        int timestamp;  // Insertion time for tie-breaking
    };

    Element* arr;
    int size;
    int capacity;
    int current_timestamp;

    void resize();
    int find_max_index() const;

public:
    MaxPriorityQueue_DynamicArray();
    ~MaxPriorityQueue_DynamicArray();

    void insert(T value, int priority);
    T extract_max();
    T peek() const;
    void modify_key(T value, int new_priority);
    int return_size() const;
    void display() const;
};

// Constructor
template <typename T>
MaxPriorityQueue_DynamicArray<T>::MaxPriorityQueue_DynamicArray() {
    capacity = 10;
    size = 0;
    current_timestamp = 0;
    arr = new Element[capacity];
}

// Destructor
template <typename T>
MaxPriorityQueue_DynamicArray<T>::~MaxPriorityQueue_DynamicArray() {
    delete[] arr;
}

// Resize
template <typename T>
void MaxPriorityQueue_DynamicArray<T>::resize() {
    capacity *= 2;
    Element* newArr = new Element[capacity];
    for (int i = 0; i < size; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

// Find Max
template <typename T>
int MaxPriorityQueue_DynamicArray<T>::find_max_index() const {
    if (size == 0) throw runtime_error("Queue is empty");
    int maxIndex = 0;    // Assume first element is max
    for (int i = 1; i < size; ++i) {
         // Compare priority, then timestamp if equal
        if (arr[i].priority > arr[maxIndex].priority ||
           (arr[i].priority == arr[maxIndex].priority && arr[i].timestamp < arr[maxIndex].timestamp)) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Insert
template <typename T>
void MaxPriorityQueue_DynamicArray<T>::insert(T value, int priority) {
    if (size >= capacity) resize();
    arr[size++] = {value, priority, current_timestamp++};
}

// Extract Max
template <typename T>
T MaxPriorityQueue_DynamicArray<T>::extract_max() {
    int maxIdx = find_max_index();
    T maxValue = arr[maxIdx].value;
    for (int i = maxIdx; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    size--;
    return maxValue;
}

// Peek
template <typename T>
T MaxPriorityQueue_DynamicArray<T>::peek() const {
    return arr[find_max_index()].value;
}

// Modify Key
template <typename T>
void MaxPriorityQueue_DynamicArray<T>::modify_key(T value, int new_priority) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].value == value) {
            arr[i].priority = new_priority;
            return;
        }
    }
    throw runtime_error("Element not found");
}

// Return Size
template <typename T>
int MaxPriorityQueue_DynamicArray<T>::return_size() const {
    return size;
}

// Display
template <typename T>
void MaxPriorityQueue_DynamicArray<T>::display() const {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << "(" << arr[i].value << ", p=" << arr[i].priority << ")";
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

#endif


