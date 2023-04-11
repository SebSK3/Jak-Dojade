#pragma once
#include "string.h"

const int CAPACITY = 10001;

struct Hashmap {
    int size = 0;
    char ***map; // changed to char***
    City ***citiesArr; // changed to City***

    Hashmap() {
        map = new char**[CAPACITY];
        citiesArr = new City**[CAPACITY];
        for (int i = 0; i < CAPACITY; i++) {
            map[i] = nullptr;
            citiesArr[i] = nullptr;
        }

    }

    ~Hashmap() {
        for (int i = 0; i < CAPACITY; i++) {
            delete[] citiesArr[i];
            delete[] map[i];
        }
        delete[] citiesArr;
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
        if (map[hashed] == nullptr) {
            map[hashed] = new char*[2];
            map[hashed][0] = str;
            map[hashed][1] = nullptr;
            citiesArr[hashed] = new City*[2];
            citiesArr[hashed][0] = city;
            citiesArr[hashed][1] = nullptr;
        } else {
            int count = 0;
            while (map[hashed][count] != nullptr) {
                if (strcmp(map[hashed][count], str) == 0) {
                    citiesArr[hashed][count] = city;
                    return;
                }
                count++;
            }
            char** temp = new char*[count + 2];
            City** tempCity = new City*[count + 2];
            memcpy(temp, map[hashed], count * sizeof(char*));
            memcpy(tempCity, citiesArr[hashed], count * sizeof(City*));
            temp[count] = str;
            temp[count + 1] = nullptr;
            tempCity[count] = city;
            tempCity[count + 1] = nullptr;
            delete[] map[hashed];
            delete[] citiesArr[hashed];
            map[hashed] = temp;
            citiesArr[hashed] = tempCity;
        }
    }

    City *find(char *str) {
        int hashed = hash(str);
        if (map[hashed] == nullptr) {
            return NULL;
        }
        for (int i = 0; map[hashed][i] != nullptr; i++) {
            if (strcmp(map[hashed][i], str) == 0) {
                return citiesArr[hashed][i];
            }
        }
        return NULL;
    }
};