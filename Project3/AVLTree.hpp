#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
using namespace std;


template<typename Key, typename Value>
class AVLTree {
private:
    // Node Structure
    struct Node {
        Key key;                  // Node Key
        Value value;              // Node Value
        Node* left;               // Left Child
        Node* right;              // Right Child
        int height;               // Height of Node

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;                   // Root of AVL Tree

    // Helper Methods
    int height(Node* n);                          // Get height of node (0 if null)
    int balanceFactor(Node* n);                   // Compute balance factor
    void updateHeight(Node* n);                   // Update height of node

    Node* rotateRight(Node* y);                   // Perform right rotation
    Node* rotateLeft(Node* x);                    // Perform left rotation
    Node* balance(Node* n);                       // Balance the node if unbalanced

    Node* insert(Node* node, Key key, Value value);  // Recursive insert helper
    Node* remove(Node* node, Key key);               // Recursive remove helper
    Value* search(Node* node, Key key) const;        // Recursive search helper
    Node* minValueNode(Node* node);                 // Find node with min key
    void display(Node* node) const;                 // In-order display of tree
    void destroyTree(Node* node);                   // Recursively delete nodes

public:
    AVLTree();                     
    ~AVLTree();                    

    void insert(Key key, Value value);  
    void remove(Key key);               
    Value* get(Key key) const;          
    void display() const;               
};

// Constructor
template<typename Key, typename Value>
AVLTree<Key, Value>::AVLTree() : root(nullptr) {}

// Destructor
template<typename Key, typename Value>
AVLTree<Key, Value>::~AVLTree() {
    destroyTree(root);
}

// Recursively delete all nodes
template<typename Key, typename Value>
void AVLTree<Key, Value>::destroyTree(Node* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

// Get height of node
template<typename Key, typename Value>
int AVLTree<Key, Value>::height(Node* n) {
    return n ? n->height : 0;
}

// Calculate balance factor
template<typename Key, typename Value>
int AVLTree<Key, Value>::balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Update height based on children
template<typename Key, typename Value>
void AVLTree<Key, Value>::updateHeight(Node* n) {
    n->height = 1 + max(height(n->left), height(n->right));
}

// Right rotation
template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotation
template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Balance node using rotations if necessary
template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::balance(Node* n) {
    updateHeight(n);
    int bf = balanceFactor(n);

    // Left heavy
    if (bf > 1) {
        if (balanceFactor(n->left) < 0) // Left-Right case
            n->left = rotateLeft(n->left);
        return rotateRight(n);         // Left-Left case
    }

    // Right heavy
    if (bf < -1) {
        if (balanceFactor(n->right) > 0) // Right-Left case
            n->right = rotateRight(n->right);
        return rotateLeft(n);           // Right-Right case
    }

    return n; // Already balanced
}

// Recursive insert
template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::insert(Node* node, Key key, Value value) {
    if (!node)
        return new Node(key, value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        node->value = value; // Update value if key exists

    return balance(node);
}

// Find node with minimum key
template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::minValueNode(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

// Recursive remove
template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::remove(Node* node, Key key) {
    if (!node) return nullptr;

    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else {
        // Node has one or zero children
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }

        // Node with two children
        Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = remove(node->right, temp->key);
    }

    return balance(node);
}

// Recursive search
template<typename Key, typename Value>
Value* AVLTree<Key, Value>::search(Node* node, Key key) const {
    if (!node) return nullptr;
    if (key == node->key) return &node->value;
    if (key < node->key) return search(node->left, key);
    return search(node->right, key);
}

// In-order display
template<typename Key, typename Value>
void AVLTree<Key, Value>::display(Node* node) const {
    if (!node) return;
    display(node->left);
    cout << "(" << node->key << ", " << node->value << ") ";
    display(node->right);
}

// Public insert
template<typename Key, typename Value>
void AVLTree<Key, Value>::insert(Key key, Value value) {
    root = insert(root, key, value);
}

// Public remove
template<typename Key, typename Value>
void AVLTree<Key, Value>::remove(Key key) {
    root = remove(root, key);
}

// Public get
template<typename Key, typename Value>
Value* AVLTree<Key, Value>::get(Key key) const {
    return search(root, key);
}

// Public display
template<typename Key, typename Value>
void AVLTree<Key, Value>::display() const {
    display(root);
    cout << endl;
}

#endif // AVLTREE_HPP
