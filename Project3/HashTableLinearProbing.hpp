#ifndef HASHTABLE_LINEARPROBING_HPP
#define HASHTABLE_LINEARPROBING_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

const int LINEAR_TABLE_SIZE = 101;


class HashTableLinearProbing {
private:
    // Structure for storing key-value pairs
    struct Entry {
        int key;
        int value;
        bool isOccupied;
        bool isDeleted;

        Entry();
    };

    // Array of entries
    Entry table[LINEAR_TABLE_SIZE];

    // Hash function
    int hashFunction(int key) const;

public:
    HashTableLinearProbing();

    void insert(int key, int value);
    void remove(int key);
    int get(int key) const;
    void display() const;
};



// Implementation of Entry struct constructor 
HashTableLinearProbing::Entry::Entry() : key(0), value(0), isOccupied(false), isDeleted(false) {}


// Constructor 
HashTableLinearProbing::HashTableLinearProbing() = default;


//  Hash function 
int HashTableLinearProbing::hashFunction(int key) const {
    return key % LINEAR_TABLE_SIZE;
}


// Insert 
void HashTableLinearProbing::insert(int key, int value) {
    int index = hashFunction(key);
    int startIndex = index;

    while (table[index].isOccupied && !table[index].isDeleted && table[index].key != key) {
        index = (index + 1) % LINEAR_TABLE_SIZE;
        if (index == startIndex) {
            throw overflow_error("Hash table is full");
        }
    }

    table[index].key = key;
    table[index].value = value;
    table[index].isOccupied = true;
    table[index].isDeleted = false;
}


// Remove 
void HashTableLinearProbing::remove(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (table[index].isOccupied) {
        if (!table[index].isDeleted && table[index].key == key) {
            table[index].isDeleted = true;
            return;
        }
        index = (index + 1) % LINEAR_TABLE_SIZE;
        if (index == startIndex) {
            break;
        }
    }

    throw runtime_error("Key not found");
}


// Get 
int HashTableLinearProbing::get(int key) const {
    int index = hashFunction(key);
    int startIndex = index;

    while (table[index].isOccupied) {
        if (!table[index].isDeleted && table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % LINEAR_TABLE_SIZE;
        if (index == startIndex) {
            break;
        }
    }

    throw runtime_error("Key not found");
}


// Display 
void HashTableLinearProbing::display() const {
    for (int i = 0; i < LINEAR_TABLE_SIZE; ++i) {
        cout << i << ": ";
        if (table[i].isOccupied && !table[i].isDeleted) {
            cout << "(" << table[i].key << ", " << table[i].value << ")";
        } else {
            cout << "nullptr";
        }
        cout << endl;
    }
}

#endif // HASHTABLE_LINEARPROBING_HPP

