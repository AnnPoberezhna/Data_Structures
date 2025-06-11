#ifndef HASHTABLE_LINEARPROBING_HPP
#define HASHTABLE_LINEARPROBING_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

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

    Entry* table;      // Dynamic array of entries
    int tableSize;     

    int hashFunction(int key) const;

public:
    HashTableLinearProbing(int size);
    ~HashTableLinearProbing();

    void insert(int key, int value);
    void remove(int key);
    int get(int key) const;
    void display() const;
};

// Implementation of Entry constructor
HashTableLinearProbing::Entry::Entry() : key(0), value(0), isOccupied(false), isDeleted(false) {}

// Constructor
HashTableLinearProbing::HashTableLinearProbing(int size) : tableSize(size) {
    if (size <= 0)
        throw invalid_argument("Table size must be positive");

    table = new Entry[tableSize];
}

// Destructor
HashTableLinearProbing::~HashTableLinearProbing() {
    delete[] table;
}

// Hash function
int HashTableLinearProbing::hashFunction(int key) const {
    return key % tableSize;
}

// Insert
void HashTableLinearProbing::insert(int key, int value) {
    int index = hashFunction(key);
    int startIndex = index;
    int firstDeletedIndex = -1;

    while (table[index].isOccupied) {
        if (!table[index].isDeleted && table[index].key == key) {
            table[index].value = value;
            return;
        }

        if (table[index].isDeleted && firstDeletedIndex == -1) {
            firstDeletedIndex = index;
        }

        index = (index + 1) % tableSize;
        if (index == startIndex) {
            break; 
        }
    }

    
    if (firstDeletedIndex != -1) {
        index = firstDeletedIndex;
    } else if (table[index].isOccupied && !table[index].isDeleted && table[index].key != key) {
        throw overflow_error("Hash table is full");
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
        index = (index + 1) % tableSize;
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
        index = (index + 1) % tableSize;
        if (index == startIndex) {
            break;
        }
    }

    throw runtime_error("Key not found");
}

// Display
void HashTableLinearProbing::display() const {
    for (int i = 0; i < tableSize; ++i) {
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

