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
#include "HashTableLinearProbing.hpp"
#include "HashTableAVL.hpp"
#include "HashTableChaining.hpp"
using namespace std;



void store_result(ofstream& file, chrono::time_point<chrono::steady_clock> start, chrono::time_point<chrono::steady_clock> end, unsigned int size, string algorytm)
{

    const chrono::duration<double> diff = end - start;
    file << algorytm << "," << size << "," << diff.count() << endl;
    cout << algorytm << "," << size << "," <<  diff.count() << endl;
}

int generate_random(mt19937& gen) {
    uniform_int_distribution<int> distribution; // Cały zakres int
    return distribution(gen);
}

int generate_random_dist(mt19937& gen, int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

int main()
{
    mt19937 gen;
    gen.seed((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
    ofstream file("dane.csv", ios::trunc);

    array<unsigned int, 8> data_sizes = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };

    unsigned int rep = 50;
    for (auto size : data_sizes)
    {

        for (int i = 0; i < rep; ++i)
        {
            HashTableLinearProbing hash_table_linear_probing(size+1);
            HashTableChaining hash_table_chaining(size);
            HashTableAVL hash_table_avl(size);
            vector<int> keys(size);
            vector<int> values(size);
            for (unsigned int j = 0; j < size; ++j) {
                keys[j] = generate_random(gen);
                values[j] = generate_random(gen);
            }
            for (unsigned int j = 0; j < size; ++j) {
                hash_table_linear_probing.insert(keys[j], values[j]);
                hash_table_chaining.insert(keys[j], values[j]);
                hash_table_avl.insert(keys[j], values[j]);
            }
            int idx_to_remove = generate_random_dist(gen, 0, size - 1);
            int key_to_remove = keys[idx_to_remove];

            //Linear probing insert, remove #################################################
            {
                const auto start = chrono::steady_clock::now();
                hash_table_linear_probing.insert(generate_random(gen), generate_random(gen));
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "LinearProbing insert");
            {
                const auto start = chrono::steady_clock::now();
                hash_table_linear_probing.remove(key_to_remove);
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "LinearProbing remove");
            }
            //Chaining insert, remove #######################################################
            {
                const auto start = chrono::steady_clock::now();
                hash_table_chaining.insert(generate_random(gen), generate_random(gen));
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "Chaining insert");
            }
            {
                const auto start = chrono::steady_clock::now();
                hash_table_chaining.remove(key_to_remove);
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "Chaining remove");
            }
            
            //AVL insert, remove #################################################################
            {
                const auto start = chrono::steady_clock::now();
                hash_table_avl.insert(generate_random(gen), generate_random(gen));
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "AVL insert");
            }
            {
                const auto start = chrono::steady_clock::now();
                hash_table_avl.remove(key_to_remove);
                const auto end = chrono::steady_clock::now();
                store_result(file, start, end, size, "AVL remove");
            } 

        }

    }}
    return 0;
}

