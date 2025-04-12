#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <random>

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
        
        void addAtRandom(T value) {
            // If list is empty -> add to the end
            if (size == 0) {
                addToEnd(value);
                return;
            }
            
            // Set up random number generator
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, size);
            int pos = distrib(gen);  // Generate random position between 0 and size (inclusive)
            
            // Handle special cases: adding at end or beginning
            if (pos == size) {
                addToEnd(value);
            } else if (pos == 0) {
                addToStart(value);
            } else {
                if (size >= capacity) {
                    resize();
                }
                // Shifting elements to make space for new element
                for (int i = size; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                // Inserting new element at random position
                arr[pos] = value;
                size++;
            }
        }
        
        void removeLast() {
            // Check if the array is not empty
            if (size > 0) {
                size--;  
            }
        }
        
        void removeFirst() {
            // Checking if array is not empty
            if (size > 0) {
                // Shifting all elements one position to the left to overwrite the first element
                for (int i = 0; i < size - 1; i++) {
                    arr[i] = arr[i+1];
                }
                size--;  
            }
        }
        
        void removeRandom() {
            // If array is empty -> nothing to remove
            if (size == 0) {
                return;
            }
            
            // Set up random number generator
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, size - 1);
            int pos = distrib(gen);  // Generate random position between 0 and size-1
            
            // Handle special cases: removing from end or beginning
            if (pos == size - 1) {
                removeLast();
            } else if (pos == 0) {
                removeFirst();
            } else {
                // Shifting elements to fill the gap left by the removed element
                for (int i = pos; i < size - 1; i++) {
                    arr[i] = arr[i+1];
                }
                size--;  
            }
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
};


#endif // ARRAYLIST_H
