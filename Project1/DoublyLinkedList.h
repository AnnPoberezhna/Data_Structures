#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class DoublyLinkedList {
private:
    // Node structure for the doubly linked list
    struct Node {
        T value;          
        Node* next;       
        Node* prev;       
        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;           
    Node* tail;           

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    ~DoublyLinkedList() {
        // Clean up all nodes to prevent memory leaks
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    
    void add_to_beginning(T value) {
        Node* new_node = new Node(value);
        
        // Handle empty list case
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }
        
        // Non-empty list
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    
    void add_to_end(T value) {
        Node* new_element = new Node(value);
        
        // Handle empty list
        if (head == nullptr) {
            head = new_element;
            tail = new_element;
            return;
        }
        
        // Adding to end
        tail->next = new_element;
        new_element->prev = tail;
        tail = new_element;
    }
    
    void add_at_position(int position, T value) {
        // Check if position is valid
        int size = get_size();
        if (position < 0 || position > size) {
            throw out_of_range("Invalid position for insertion");
        }
        
        // Handle special cases
        if (position == 0) {
            add_to_beginning(value);
            return;
        }
        
        if (position == size) {
            add_to_end(value);
            return;
        }
        
        // Navigate to insertion position
        Node* current = head;
        int i = 0;
        while (i < position - 1) {
            current = current->next;
            i++;
        }
        
        // Adding new node between existing nodes
        Node* new_element = new Node(value);
        Node* after = current->next;
        
        current->next = new_element;
        new_element->prev = current;
        new_element->next = after;
        after->prev = new_element;
    }
    
    void remove_from_beginning() {
        // Checking if list is not empty
        if (head == nullptr) {
            throw runtime_error("Cannot remove from empty list");
        }

        Node* old_head = head;
        
        // If only one element
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete old_head;
    }
    
    void remove_from_end() {
        // Checking if list is not empty
        if (head == nullptr) {
            throw runtime_error("Cannot remove from empty list");
        }
        
        Node* old_tail = tail;
        
        // Handle single element case
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete old_tail;
    }
    
    void remove_at_position(int position) {
        // Validate position and list state
        int size = get_size();
        if (head == nullptr) {
            throw runtime_error("Cannot remove from empty list");
        }
        
        if (position < 0 || position >= size) {
            throw out_of_range("Invalid position for removal");
        }
        
        // Handle edge cases
        if (position == 0) {
            remove_from_beginning();
            return;
        }
        
        if (position == size - 1) {
            remove_from_end();
            return;
        }
        
        // Navigate to the node to remove
        Node* to_remove = head;
        for (int i = 0; i < position; ++i) {
            to_remove = to_remove->next;
        }
        
        // Updating pointers to skip the removed node
        Node* before = to_remove->prev;
        Node* after = to_remove->next;
        
        before->next = after;
        after->prev = before;
        
        delete to_remove;
    }
    
    bool contains(T value) {
        // Linear search through the list
        if (head == nullptr) {
            return false;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->value == value) {
                return true;  // Value found
            }
            temp = temp->next;
        }
        
        return false;  // Value not found
    }
    
    void display_forward() {
        if (head == nullptr) {
            cout << "[ empty ]" << endl;
            return;
        }
        
        cout << "[ ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value;
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << " ]" << endl;
    }
    
    void display_backward() {
        if (tail == nullptr) {
            cout << "[ empty ]" << endl;
            return;
        }
        
        Node* temp = tail;
        cout << "[ ";
        bool first = true;
        
        while (temp != nullptr) {
            if (!first) {
                cout << ", ";
            }
            cout << temp->value;
            first = false;
            temp = temp->prev;
        }
        
        cout << " ]" << endl;
    }
    
    // Getter for size
    int get_size() const {
        if (head == nullptr) {
            return 0;
        }
        
        int length = 0;
        Node* temp = head;
        
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        return length;
    }
};

#endif // DOUBLYLINKEDLIST_H
