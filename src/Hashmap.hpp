#pragma once
#include "string.h"

const int CAPACITY = 10001;
struct Hashmap {
    int size = 0;
    char **map;
    bool taken[CAPACITY] = {};
    City **citiesArr;

    Hashmap() {
        map = new char*[CAPACITY];
        citiesArr = new City*[CAPACITY];
    }
    ~Hashmap() {
        delete[] citiesArr;
        delete[] map;
    }
    int hash(char *str) {
        unsigned long int hash = 0;
        for (int i=0; i<strlen(str); i++) {
            hash = str[i] + (hash <<6) + (hash << 16) - hash;
        }
        return hash % CAPACITY;
    }
    void insert(char *str, City *city) {
        int hashed = hash(str);
        if (taken[hashed]) {
            delete[] map[hashed];
        }
        taken[hashed] = true;
        map[hashed] = str;
        citiesArr[hashed] = city;
    }
    City *find(char *str) {
        int hashed = hash(str);
        if (taken[hashed]) {
            return citiesArr[hashed];
        }
        return NULL;
    }
};