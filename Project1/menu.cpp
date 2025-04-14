#include <iostream>
#include <limits>
#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;

// Function to display main menu
void displayMainMenu() {
    cout << "\n======== DATA STRUCTURES MENU ========\n";
    cout << "1. ArrayList Operations\n";
    cout << "2. Singly Linked List Operations\n";
    cout << "3. Doubly Linked List Operations\n";
    cout << "4. Exit\n";
    cout << "======================================\n";
    cout << "Enter your choice: ";
}

// Operations menu for ArrayList
void arrayListMenu() {
    ArrayList<int> list;
    int choice, value, position;
    bool running = true;

    while (running) {
        cout << "\n======== ARRAYLIST MENU ========\n";
        cout << "1. Add element to beginning\n";
        cout << "2. Add element to end\n";
        cout << "3. Add element at position\n";
        cout << "4. Remove element from beginning\n";
        cout << "5. Remove element from end\n";
        cout << "6. Remove element at position\n";
        cout << "7. Display list\n";
        cout << "8. Get size\n";
        cout << "9. Return to main menu\n";
        cout << "===============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    cout << "Enter value to add: ";
                    cin >> value;
                    list.add_to_beginning(value);
                    cout << "Element added to beginning.\n";
                    break;
                case 2:
                    cout << "Enter value to add: ";
                    cin >> value;
                    list.add_to_end(value);
                    cout << "Element added to end.\n";
                    break;
                case 3:
                    cout << "Enter value to add: ";
                    cin >> value;
                    cout << "Enter position: ";
                    cin >> position;
                    list.add_at_random(position, value);
                    cout << "Element added at position " << position << ".\n";
                    break;
                case 4:
                    list.remove_from_beginning();
                    cout << "Element removed from beginning.\n";
                    break;
                case 5:
                    list.remove_from_end();
                    cout << "Element removed from end.\n";
                    break;
                case 6:
                    cout << "Enter position: ";
                    cin >> position;
                    list.remove_at_random(position);
                    cout << "Element removed from position " << position << ".\n";
                    break;
                case 7:
                    cout << "ArrayList contents:\n";
                    list.display();
                    break;
                case 8:
                    cout << "ArrayList size: " << list.get_size() << endl;
                    break;
                case 9:
                    running = false;
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

// Operations menu for Singly Linked List
void singlyLinkedListMenu() {
    SinglyLinkedList<int> list;
    int choice, value, position;
    bool running = true;

    while (running) {
        cout << "\n======== SINGLY LINKED LIST MENU ========\n";
        cout << "1. Add element to beginning\n";
        cout << "2. Add element to end\n";
        cout << "3. Add element at position\n";
        cout << "4. Remove element from beginning\n";
        cout << "5. Remove element from end\n";
        cout << "6. Remove element at position\n";
        cout << "7. Display list\n";
        cout << "8. Get size\n";
        cout << "9. Return to main menu\n";
        cout << "=======================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    cout << "Enter value to add: ";
                    cin >> value;
                    list.add_to_beginning(value);
                    cout << "Element added to beginning.\n";
                    break;
                case 2:
                    cout << "Enter value to add: ";
                    cin >> value;
                    list.add_to_end(value);
                    cout << "Element added to end.\n";
                    break;
                case 3:
                    cout << "Enter value to add: ";
                    cin >> value;
                    cout << "Enter position: ";
                    cin >> position;
                    list.add_at_random(position, value);
                    cout << "Element added at position " << position << ".\n";
                    break;
                case 4:
                    list.remove_from_beginning();
                    cout << "Element removed from beginning.\n";
                    break;
                case 5:
                    list.remove_from_end();
                    cout << "Element removed from end.\n";
                    break;
                case 6:
                    cout << "Enter position: ";
                    cin >> position;
                    list.remove_at_random(position);
                    cout << "Element removed from position " << position << ".\n";
                    break;
                case 7:
                    cout << "Singly Linked List contents:\n";
                    list.display();
                    break;
                case 8:
                    cout << "Singly Linked List size: " << list.get_size() << endl;
                    break;
                case 9:
                    running = false;
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

// Operations menu for Doubly Linked List
void doublyLinkedListMenu() {
    DoublyLinkedList<int> list;
    int choice, value, position;
    bool running = true;

    while (running) {
        cout << "\n======== DOUBLY LINKED LIST MENU ========\n";
        cout << "1. Add element to beginning\n";
        cout << "2. Add element to end\n";
        cout << "3. Add element at position\n";
        cout << "4. Remove element from beginning\n";
        cout << "5. Remove element from end\n";
        cout << "6. Remove element at position\n";
        cout << "7. Display list (forward)\n";
        cout << "8. Display list (backward)\n";
        cout << "9. Get size\n";
        cout << "10. Return to main menu\n";
        cout << "=======================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    cout << "Enter value to add: ";
                    cin >> value;
                    list.add_to_beginning(value);
                    cout << "Element added to beginning.\n";
                    break;
                case 2:
                    cout << "Enter value to add: ";
                    cin >> value;
                    list.add_to_end(value);
                    cout << "Element added to end.\n";
                    break;
                case 3:
                    cout << "Enter value to add: ";
                    cin >> value;
                    cout << "Enter position: ";
                    cin >> position;
                    list.add_at_position(position, value);
                    cout << "Element added at position " << position << ".\n";
                    break;
                case 4:
                    list.remove_from_beginning();
                    cout << "Element removed from beginning.\n";
                    break;
                case 5:
                    list.remove_from_end();
                    cout << "Element removed from end.\n";
                    break;
                case 6:
                    cout << "Enter position: ";
                    cin >> position;
                    list.remove_at_position(position);
                    cout << "Element removed from position " << position << ".\n";
                    break;
                case 7:
                    cout << "Doubly Linked List contents (forward):\n";
                    list.display_forward();
                    break;
                case 8:
                    cout << "Doubly Linked List contents (backward):\n";
                    list.display_backward();
                    break;
                case 9:
                    cout << "Doubly Linked List size: " << list.get_size() << endl;
                    break;
                case 10:
                    running = false;
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        displayMainMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                arrayListMenu();
                break;
            case 2:
                singlyLinkedListMenu();
                break;
            case 3:
                doublyLinkedListMenu();
                break;
            case 4:
                running = false;
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}