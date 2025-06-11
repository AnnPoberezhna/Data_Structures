#ifndef HASHTABLE_AVL_HPP
#define HASHTABLE_AVL_HPP

#include "AVLTree.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

class HashTableAVL {
private:
    AVLTree<int, int>* table;   // Dynamic array
    int tableSize;              

    int hashFunction(int key) const;

public:
    HashTableAVL(int size);      
    ~HashTableAVL();             
 
    void insert(int key, int value);
    void remove(int key);
    int get(int key);
    void display() const;
};

// Konstruktor
HashTableAVL::HashTableAVL(int size) : tableSize(size) {
    if (size <= 0) {
        throw invalid_argument("Table size must be positive");
    }
    table = new AVLTree<int, int>[tableSize];
}

// Destruktor
HashTableAVL::~HashTableAVL() {
    delete[] table;
}

// Hash function 
int HashTableAVL::hashFunction(int key) const {
    return key % tableSize;
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
    for (int i = 0; i < tableSize; ++i) {
        cout << i << ": ";
        table[i].display();
    }
}

#endif // HASHTABLE_AVL_HPP


