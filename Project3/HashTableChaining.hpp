#ifndef HASHTABLECHAINING_HPP
#define HASHTABLECHAINING_HPP

#include <iostream>
#include <stdexcept>
#include "SinglyLinkedList.hpp"

using namespace std;

class HashTableChaining {
private:
    struct KeyValue {
        int key;
        int value;

        bool operator==(const KeyValue& other) const {
            return key == other.key;
        }
    };

    static const int TABLE_SIZE = 101;
    SinglyLinkedList<KeyValue>* table[TABLE_SIZE];

    int hashFunction(int key) const {
        return key % TABLE_SIZE;
    }

public:
    HashTableChaining();
    ~HashTableChaining();

    void insert(int key, int value);
    void remove(int key);
    void display() const;
};

// Constructor
HashTableChaining::HashTableChaining() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = new SinglyLinkedList<KeyValue>();
    }
}

// Destructor
HashTableChaining::~HashTableChaining() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        delete table[i];
    }
}

// Insert
void HashTableChaining::insert(int key, int value) {
    int index = hashFunction(key);
    SinglyLinkedList<KeyValue>* bucket = table[index];

    int size = bucket->get_size();
    for (int i = 0; i < size; ++i) {
        KeyValue current = bucket->get(i);
        if (current.key == key) {
            bucket->remove_at_random(i);
            break;
        }
    }

    KeyValue kv = { key, value };
    bucket->add_to_end(kv);
}

// Remove
void HashTableChaining::remove(int key) {
    int index = hashFunction(key);
    SinglyLinkedList<KeyValue>* bucket = table[index];

    int size = bucket->get_size();
    for (int i = 0; i < size; ++i) {
        KeyValue current = bucket->get(i);
        if (current.key == key) {
            bucket->remove_at_random(i);
            return;
        }
    }

    throw runtime_error("Key not found");
}

// Display
void HashTableChaining::display() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << i << ": ";
        SinglyLinkedList<KeyValue>* bucket = table[i];
        int size = bucket->get_size();
        for (int j = 0; j < size; ++j) {
            KeyValue kv = bucket->get(j);
            cout << "(" << kv.key << ", " << kv.value << ") -> ";
        }
        cout << "nullptr" << endl;
    }
}

#endif // HASHTABLECHAINING_HPP
