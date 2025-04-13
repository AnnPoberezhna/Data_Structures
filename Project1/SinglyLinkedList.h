#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H 


#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
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

    void display() const;
};

// Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
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
void SinglyLinkedList<T>::add_to_beginning(T value)
{
    Node* new_node = new Node(value);
    if (!head)
    {
        head = tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

// Adding at the end
template <typename T>
void SinglyLinkedList<T>::add_to_end(T value)
{
    Node* new_node = new Node(value);
    if (!head)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

// Adding at random position 
template <typename T>
void SinglyLinkedList<T>::add_at_random(int position, T value)
{
    if (position == 0)
    {
        add_to_beginning(value);
        return;
    }

    Node* new_node = new Node(value);
    Node* current = head;

    for (int i = 0; i < position - 1; ++i)
    {
        if (!current)
        {
            throw out_of_range("Position out of the range");
        }
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    if (!new_node->next)
    {
        tail = new_node;
    }
}

// Deleting from the beggining
template <typename T>
void SinglyLinkedList<T>::remove_from_beginning()
{
    if (!head) {
        throw runtime_error("Linked List is empty");
    }

    Node* temp = head;
    head = head->next;

    if (!head)
    {
        tail = nullptr;
    }

    delete temp;
}

// Deleting from the end
template <typename T>
void SinglyLinkedList<T>::remove_from_end()
{
    if (!head)
    {
        throw runtime_error("Linked List is empty");
    }

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != tail)
    {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
}

// Deleting from the random position
template <typename T>
void SinglyLinkedList<T>::remove_at_random(int position)
{
    if (position == 0)
    {
        remove_from_beginning();
        return;
    }

    Node* current = head;

    for (int i = 0; i < position - 1; ++i)
    {
        if (!current || !current->next)
        {
            throw out_of_range("Position out of the range");
        }
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;

    if (!current->next)
    {
        tail = current;
    }

    delete temp;
}

// Displaying Linked List
template <typename T>
void SinglyLinkedList<T>::display() const
{
    Node* current = head;
    while (current)
    {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

#endif // SINGLYLINKEDLIST_H


