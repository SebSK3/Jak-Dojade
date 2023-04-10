#pragma once
#include "string.h"

const int CAPACITY = 10001;

struct Hashmap {
    int size = 0;
    std::vector<std::pair<char*, City*>>* map; // vector of key-value pairs
    City **citiesArr;

    Hashmap() {
        map = new std::vector<std::pair<char*, City*>>[CAPACITY]; // initialize each bucket as an empty vector
        citiesArr = new City*[CAPACITY];
    }

    ~Hashmap() {
        delete[] citiesArr;
        for (int i = 0; i < CAPACITY; i++) {
            map[i].clear(); // free the memory used by each bucket
        }
        delete[] map;
    }

    int hash(char *str) {
        unsigned long int hash = 0;
        for (int i = 0; i < strlen(str); i++) {
            hash = str[i] + (hash << 6) + (hash << 16) - hash;
        }
        return hash % CAPACITY;
    }

    void insert(char *str, City *city) {
        int hashed = hash(str);
        for (auto& kv : map[hashed]) {
            if (strcmp(kv.first, str) == 0) { // if the key already exists, update the value
                kv.second = city;
                return;
            }
        }
        map[hashed].emplace_back(str, city); // insert the new key-value pair
        citiesArr[hashed] = city;
    }

    City *find(char *str) {
        int hashed = hash(str);
        for (auto& kv : map[hashed]) {
            if (strcmp(kv.first, str) == 0) {
                return kv.second;
            }
        }
        return NULL;
    }
};