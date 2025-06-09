#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void add_to_beginning(T value);
    void add_to_end(T value);
    void add_at_random(int position, T value);
    void remove_from_beginning();
    void remove_from_end();
    void remove_at_random(int position);
    bool contains(T value) const;
    int get_size() const;
    T get(int position) const;
};

// Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Add to beginning
template <typename T>
void SinglyLinkedList<T>::add_to_beginning(T value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

// Add to end
template <typename T>
void SinglyLinkedList<T>::add_to_end(T value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

// Add at random position
template <typename T>
void SinglyLinkedList<T>::add_at_random(int position, T value) {
    if (position == 0) {
        add_to_beginning(value);
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1; ++i) {
        if (!current) throw out_of_range("Position out of range");
        current = current->next;
    }

    Node* new_node = new Node(value);
    new_node->next = current->next;
    current->next = new_node;

    if (!new_node->next) {
        tail = new_node;
    }
}

// Remove from beginning
template <typename T>
void SinglyLinkedList<T>::remove_from_beginning() {
    if (!head) throw runtime_error("List is empty");

    Node* temp = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete temp;
}

// Remove from end
template <typename T>
void SinglyLinkedList<T>::remove_from_end() {
    if (!head) throw runtime_error("List is empty");

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
}

// Remove at random position
template <typename T>
void SinglyLinkedList<T>::remove_at_random(int position) {
    if (position == 0) {
        remove_from_beginning();
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1; ++i) {
        if (!current || !current->next) throw out_of_range("Position out of range");
        current = current->next;
    }

    Node* temp = current->next;
    if (!temp) throw out_of_range("Position out of range");

    current->next = temp->next;
    if (!current->next) tail = current;
    delete temp;
}

// Contains
template <typename T>
bool SinglyLinkedList<T>::contains(T value) const {
    Node* current = head;
    while (current) {
        if (current->value == value) return true;
        current = current->next;
    }
    return false;
}

// Get size
template <typename T>
int SinglyLinkedList<T>::get_size() const {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Get value at position
template <typename T>
T SinglyLinkedList<T>::get(int position) const {
    if (position < 0) throw out_of_range("Negative index");

    Node* current = head;
    for (int i = 0; i < position; ++i) {
        if (!current) throw out_of_range("Index out of range");
        current = current->next;
    }

    if (!current) throw out_of_range("Index out of range");
    return current->value;
}

#endif // SINGLYLINKEDLIST_H
