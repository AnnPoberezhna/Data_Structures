#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MaxPriorityQueue_DynamicArray.h"
#include "MaxPriorityQueue_Heap.h"

using namespace std;

int main() {
    srand(time(0)); // dla losowych priorytetow (uzyj w tych testach i usun ten komentrz lol)

    cout << "=== Kolejka priorytetowa na bazie dynamicznej tablicy ===" << endl;
    MaxPriorityQueue_DynamicArray<string> pq_array;

    pq_array.insert("A", 3);
    pq_array.insert("B", 5);
    pq_array.insert("C", 1);
    pq_array.insert("D", 4);

    cout << "Zawartosc kolejki:" << endl;
    pq_array.display();

    cout << "Najwiekszy element (peek): " << pq_array.peek() << endl;
    cout << "Usuwam max: " << pq_array.extract_max() << endl;

    cout << "Zawartosc po usunieciu max:" << endl;
    pq_array.display();

    pq_array.modify_key("C", 10);
    cout << "Po zmianie priorytetu C na 10:" << endl;
    pq_array.display();

    cout << "Rozmiar kolejki: " << pq_array.return_size() << endl;

    // === TEST FIFO ===
    pq_array.insert("X1", 7);
    pq_array.insert("X2", 7);
    pq_array.insert("X3", 7);

    cout << "\nTest FIFO (te same priorytety = 7):" << endl;
    pq_array.display();
    cout << "peek: " << pq_array.peek() << endl;
    cout << "extract: " << pq_array.extract_max() << endl;
    pq_array.display();  // Wyswietla po pierwszym usunieciu
    cout << "extract: " << pq_array.extract_max() << endl;
    pq_array.display();  // Wyswietla po drugim usunieciu
    cout << "extract: " << pq_array.extract_max() << endl;
    pq_array.display();  // Wyswietla po trzecim usunieciu

    cout << "\n=== Kolejka priorytetowa na bazie kopca (heap) ===" << endl;
    MaxPriorityQueue_Heap<string> pq_heap;

    pq_heap.insert("A", 3);
    pq_heap.insert("B", 5);
    pq_heap.insert("C", 1);
    pq_heap.insert("D", 4);

    cout << "Zawartosc kolejki:" << endl;
    pq_heap.display();

    cout << "Najwiekszy element (peek): " << pq_heap.peek() << endl;
    cout << "Usuwam max: " << pq_heap.extract_max() << endl;

    cout << "Zawartosc po usunieciu max:" << endl;
    pq_heap.display();

    pq_heap.modify_key("C", 10);
    cout << "Po zmianie priorytetu C na 10:" << endl;
    pq_heap.display();

    cout << "Rozmiar kolejki: " << pq_heap.return_size() << endl;

    // === TEST FIFO ===
    pq_heap.insert("X1", 7);
    pq_heap.insert("X2", 7);
    pq_heap.insert("X3", 7);

    cout << "\nTest FIFO (kopiec, priorytet = 7):" << endl;
    pq_heap.display();
    cout << "peek: " << pq_heap.peek() << endl;
    cout << "extract: " << pq_heap.extract_max() << endl;
    pq_heap.display();  // Wyswietla po pierwszym usunieciu
    cout << "extract: " << pq_heap.extract_max() << endl;
    pq_heap.display();  // Wyswietla po drugim usunieciu
    cout << "extract: " << pq_heap.extract_max() << endl;
    pq_heap.display();  // Wyswietla po trzecim usunieciu

    return 0;
}



