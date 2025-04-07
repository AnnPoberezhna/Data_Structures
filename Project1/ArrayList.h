#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class T>
class ArrayList{
    private:
        T *arr;             // pointer to the array in heap
        int size;           // current number of elements in array
        int capacity;       // total space available in array

        void resize();

    public:
        ArrayList();               // Constructor
        ~ArrayList();             // Deconstructor
        void addToEnd(T value);     // Add a value to the end
        void addToStart(T value);   // Adds an element at the beginning
        void addAtRandom(T value);  // Adds an element at random position
        void removeLast();          // Deletes the last item
        void removeFirst();         // Deletes the first item
        void removeRandom();        // Deletes an item at random position
        bool contains(T value);     // Checks if value exists in the array
        int getSize() const;       // Returns current number of elements in the list
        T get(int index) const;   // Returns element at the given index
};

// Include the implementation file to make template definitions available
#include "ArrayList.cpp"

#endif // ARRAYLIST_H
