#include <iostream>
#include <vector>
#include <iterator>
#include <array>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include "DoublyLinkedList.h"
#include "ArrayList.h"
#include "SinglyLinkedList.h"
using namespace std;



void store_result(ofstream& file, chrono::time_point<chrono::steady_clock> start, chrono::time_point<chrono::steady_clock> end, unsigned int size, string algorytm)
{

    const chrono::duration<double> diff = end - start;
    file << algorytm << "," << size << "," << diff.count() << endl;
    cout << algorytm << "," << size << "," <<  diff.count() << endl;
}

unsigned int generate_random(mt19937& gen, unsigned int min, unsigned int max) {
    uniform_int_distribution<unsigned int> distribution(min, max);
    return distribution(gen);
}

int main()
{
    mt19937 gen;
    gen.seed((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
    ofstream file("dane.csv", ios::trunc);

    array<unsigned int, 8> data_sizes = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };

    ArrayList<unsigned int> array_list;
    SinglyLinkedList<unsigned int> singly_linked_list;
    DoublyLinkedList<unsigned int> doubly_linked_list;

    unsigned int rep = 30;
    for (auto size : data_sizes)
    {

        for (int i = 0; i < rep; ++i)
        {
            for (int i = 0; i < size; ++i) {
                array_list.add_to_end(gen());
                singly_linked_list.add_to_beginning(gen());
                doubly_linked_list.add_to_beginning(gen());
            }
            {
                const auto start = chrono::steady_clock::now();
                array_list.add_to_beginning(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieStartArray");
            }
            {
                const auto start = chrono::steady_clock::now();
                array_list.add_to_end(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieEndArray");
            }
            {
                const auto start = chrono::steady_clock::now();
                array_list.add_at_random(generate_random(gen, 1, size),gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieMidArray");
            }
            {
                const auto start = chrono::steady_clock::now();
                array_list.remove_from_beginning();
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieStartArray");
            }
            {
                const auto start = chrono::steady_clock::now();
                array_list.remove_from_end();
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieEndArray");
            }
            {
                const auto start = chrono::steady_clock::now();
                array_list.remove_at_random(generate_random(gen, 1, size));
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieMidArray");
            }
            {
                const auto start = chrono::steady_clock::now();
                array_list.contains(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "przeszukiwanieArray");
            }

//##########################################################################################################################

            {
                const auto start = chrono::steady_clock::now();
                singly_linked_list.add_to_beginning(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieStartSingle");
            }
            {
                const auto start = chrono::steady_clock::now();
                singly_linked_list.add_to_end(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieEndSingle");
            }
            {
                const auto start = chrono::steady_clock::now();
                singly_linked_list.add_at_random(generate_random(gen, 1, size),gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieMidSingle");
            }
            {
                const auto start = chrono::steady_clock::now();
                singly_linked_list.remove_from_beginning();
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieStartSingle");
            }
            {
                const auto start = chrono::steady_clock::now();
                singly_linked_list.remove_from_end();
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieEndSingle");
            }
            {
                const auto start = chrono::steady_clock::now();
                singly_linked_list.remove_at_random(generate_random(gen, 1, size));
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieMidSingle");
            }
            {
                const auto start = chrono::steady_clock::now();
                singly_linked_list.contains(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "przeszukiwanieSingle");
            }

//##########################################################################################################################

            {
                const auto start = chrono::steady_clock::now();
                doubly_linked_list.add_to_beginning(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieStartDouble");
            }
            {
                const auto start = chrono::steady_clock::now();
                doubly_linked_list.add_to_end(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieEndDouble");
            }
            {
                const auto start = chrono::steady_clock::now();
                doubly_linked_list.add_at_position(generate_random(gen, 1, size),gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "dodawanieMidDouble");
            }
            {
                const auto start = chrono::steady_clock::now();
                doubly_linked_list.remove_from_beginning();
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieStartDouble");
            }
            {
                const auto start = chrono::steady_clock::now();
                doubly_linked_list.remove_from_end();
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieEndDouble");
            }
            {
                const auto start = chrono::steady_clock::now();
                doubly_linked_list.remove_at_position(generate_random(gen, 1, size));
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "usuwanieMidDouble");
            }
            {
                const auto start = chrono::steady_clock::now();
                doubly_linked_list.contains(gen());
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "przeszukiwanieDouble");
            }

        }

    }
    return 0;
}