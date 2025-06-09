#ifndef HASHTABLE_AVL_HPP
#define HASHTABLE_AVL_HPP

#include "AVLTree.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

const int AVL_TABLE_SIZE = 101;

class HashTableAVL {
private:
    AVLTree<int, int> table[AVL_TABLE_SIZE];  // Array of AVL trees

    int hashFunction(int key) const;          

public:
    void insert(int key, int value);          
    void remove(int key);                      
    int get(int key);                           
    void display() const;                       
};

// Hash function 
int HashTableAVL::hashFunction(int key) const {
    return key % AVL_TABLE_SIZE;
}

// Insert
void HashTableAVL::insert(int key, int value) {
    int index = hashFunction(key);
    table[index].insert(key, value);
}

// Remove
void HashTableAVL::remove(int key) {
    int index = hashFunction(key);
    table[index].remove(key);
}

// Get
int HashTableAVL::get(int key) {
    int index = hashFunction(key);
    int* value = table[index].get(key);
    if (value) return *value;
    throw runtime_error("Key not found");
}

// Display
void HashTableAVL::display() const {
    for (int i = 0; i < AVL_TABLE_SIZE; ++i) {
        cout << i << ": ";
        table[i].display();
    }
}

#endif // HASHTABLE_AVL_HPP


