#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T value;
        Node* next;
        Node* prev;
        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void add_to_beginning(T value);
    void add_to_end(T value);
    void add_at_position(int position, T value);

    void remove_from_beginning();
    void remove_from_end();
    void remove_at_position(int position);

    void display_forward() const;
    void display_backward() const;
};

// Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Adding at the beginning
template <typename T>
void DoublyLinkedList<T>::add_to_beginning(T value)
{
    Node* new_node = new Node(value);

    if (!head)
    {
        // If empty, both head and tail point to the new node
        head = tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

// Adding at the end
template <typename T>
void DoublyLinkedList<T>::add_to_end(T value)
{
    Node* new_node = new Node(value);
    if (!head)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

// Adding at specific position
template <typename T>
void DoublyLinkedList<T>::add_at_position(int position, T value)
{
    if (position == 0)
    {
        add_to_beginning(value);
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1; ++i)
    {
        if (!current)
        {
            throw out_of_range("Position out of range");
        }
        current = current->next;
    }

    if (!current)
    {
        throw out_of_range("Position out of range");
    }

    if (!current->next)
    {
        add_to_end(value);
        return;
    }

    Node* new_node = new Node(value);
    new_node->next = current->next;
    new_node->prev = current;
    current->next->prev = new_node;
    current->next = new_node;
}

// Removing from the beginning
template <typename T>
void DoublyLinkedList<T>::remove_from_beginning()
{
    if (!head)
    {
        throw runtime_error("List is empty");
    }

    Node* temp = head;
    
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
}

// Removing from the end
template <typename T>
void DoublyLinkedList<T>::remove_from_end()
{
    if (!head)
    {
        throw runtime_error("List is empty");
    }

    Node* temp = tail;
    
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
}

// Removing from specific position
template <typename T>
void DoublyLinkedList<T>::remove_at_position(int position)
{
    if (!head)
    {
        throw runtime_error("List is empty");
    }

    if (position == 0)
    {
        remove_from_beginning();
        return;
    }

    Node* current = head;
    for (int i = 0; i < position; ++i)
    {
        if (!current)
        {
            throw out_of_range("Position out of range");
        }
        current = current->next;
    }

    if (!current)
    {
        throw out_of_range("Position out of range");
    }

    if (current == tail)
    {
        remove_from_end();
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

// Displaying list forward
template <typename T>
void DoublyLinkedList<T>::display_forward() const
{
    Node* current = head;
    cout << "nullptr <- ";
    while (current)
    {
        cout << current->value;
        if (current->next)
            cout << " <-> ";
        current = current->next;
    }
    cout << " -> nullptr" << endl;
}

// Displaying list backward
template <typename T>
void DoublyLinkedList<T>::display_backward() const
{
    Node* current = tail;
    cout << "nullptr <- ";
    while (current)
    {
        cout << current->value;
        if (current->prev)
            cout << " <-> ";
        current = current->prev;
    }
    cout << " -> nullptr" << endl;
}

#endif // DOUBLYLINKEDLIST_H


