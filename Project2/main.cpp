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
#include "MaxPriorityQueue_DynamicArray.h"
#include "MaxPriorityQueue_Heap.h"



void store_result(ofstream& file, chrono::time_point<chrono::high_resolution_clock> start, chrono::time_point<chrono::high_resolution_clock> end, unsigned int size, string algorytm)
{
    const chrono::duration<double> diff = (end - start)*1000;
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

    MaxPriorityQueue_DynamicArray<unsigned int> dynamic_array_queue;
    MaxPriorityQueue_Heap<unsigned int> heap_queue;
    unsigned int rep = 30;
    for (auto size : data_sizes)
    {

        for (int i = 0; i < rep; ++i)
        {
            for (int i = 0; i < size; ++i) {
                dynamic_array_queue.insert(gen(), gen());
                heap_queue.insert(gen(), gen());
            }
            {
                const auto start = chrono::high_resolution_clock::now();
                dynamic_array_queue.insert(gen(), gen());
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Dynamic extract_max");
            }
            {
                const auto start = chrono::high_resolution_clock::now();
                dynamic_array_queue.extract_max();
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Dynamic extract_max");
            }
            {
                const auto start = chrono::high_resolution_clock::now();
                dynamic_array_queue.peek();
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Dynamic peek");
            }
            auto keys = dynamic_array_queue.get_values();
            if (!keys.empty()) {
                int index = generate_random(gen, 0, keys.size() - 1);
                int chosen_key = keys[index];
                int new_priority = gen();
                const auto start = chrono::high_resolution_clock::now();
                dynamic_array_queue.modify_key(chosen_key, new_priority);
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Dynamic modify_key");
            }
            {
                const auto start = chrono::high_resolution_clock::now();
                dynamic_array_queue.return_size();
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Dynamic return_size");
            }

//#########################################################################################################################

            {
                const auto start = chrono::high_resolution_clock::now();
                heap_queue.insert(gen(), gen());
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Heap extract_max");
            }
            {
                const auto start = chrono::high_resolution_clock::now();
                heap_queue.extract_max();
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Heap extract_max");
            }
            {
                const auto start = chrono::high_resolution_clock::now();
                heap_queue.peek();
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Heap peek");
            }
            auto keys_h = heap_queue.get_values();
            if (!keys_h.empty()) {
                int index = generate_random(gen, 0, keys_h.size() - 1);
                int chosen_key = keys_h[index];
                int new_priority = gen();
                const auto start = chrono::high_resolution_clock::now();
                heap_queue.modify_key(chosen_key, new_priority);
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Heap modify_key");
            }
            {
                const auto start = chrono::high_resolution_clock::now();
                heap_queue.return_size();
                const auto end = chrono::high_resolution_clock::now();
                store_result(file, start, end, size, "Heap return_size");
            }
        }
    }
    return 0;
}


