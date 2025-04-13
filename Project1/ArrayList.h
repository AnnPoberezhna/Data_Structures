#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class ArrayList{
private:
    T *arr;             // pointer to the array in heap
    int size;           // current number of elements in array
    int capacity;       // total space available in array

    void resize() {
        capacity *= 2;
        
        // Create a new array with the increased capacity
        T* newArr = new T[capacity];
        
        // Copy elements from the old array to the new one
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        
        // Delete old array
        delete[] arr;
        
        // Updating the pointer to a new array
        arr = newArr;
    }

public:
    ArrayList() {
        arr = nullptr;
        size = 0;
        capacity = 5; 
        arr = new T[capacity];  // Allocate initial memory
    }
    
    ~ArrayList() {
        delete[] arr;
    }
    
    void addToEnd(T value) {
        // Checking if need to be resize
        if (size >= capacity) {
            resize();
        }
        
        // Add new element at the end
        arr[size] = value;
        size++;
    }
    
    void addToStart(T value) {
        if (size >= capacity) {
            resize();
        }
        
        // Shifting all elements one position to the right
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        
        // Add new element at the beginning
        arr[0] = value;
        size++;
    }
    
    void addAtPosition(int position, T value) {
        // Check if position is valid
        if (position < 0 || position > size) {
            throw out_of_range("Position out of range");
        }
        
        // Handle special cases
        if (position == 0) {
            addToStart(value);
            return;
        }
        
        if (position == size) {
            addToEnd(value);
            return;
        }
        
        // Regular case: insert at position
        if (size >= capacity) {
            resize();
        }
        
        // Shift elements to make space
        for (int i = size; i > position; i--) {
            arr[i] = arr[i-1];
        }
        
        // Insert the new element
        arr[position] = value;
        size++;
    }
    
    void removeLast() {
        // Check if the array is not empty
        if (size <= 0) {
            throw runtime_error("List is empty");
        }
        size--;
    }
    
    void removeFirst() {
        // Checking if array is not empty
        if (size <= 0) {
            throw runtime_error("List is empty");
        }
        
        // Shifting all elements one position to the left to overwrite the first element
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }
    
    void removeAtPosition(int position) {
        // Check if array is empty
        if (size <= 0) {
            throw runtime_error("List is empty");
        }
        
        // Check if position is valid
        if (position < 0 || position >= size) {
            throw out_of_range("Position out of range");
        }
        
        // Handle special cases
        if (position == size - 1) {
            removeLast();
            return;
        }
        
        if (position == 0) {
            removeFirst();
            return;
        }
        
        // Regular case: remove from position
        // Shift elements to fill the gap
        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }
    
    bool contains(T value) {
        // Linear search through the array
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;  // Value found
            }
        }
        return false;  // Value not found
    }


    // Displaying Array List
    void display() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << arr[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
};

#endif // ARRAYLIST_H
