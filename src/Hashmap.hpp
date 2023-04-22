#pragma once
#include "Config.hpp"
#include <string.h>

struct Hashmap {
    int size = 0;
    char ***map;
    City ***citiesArr;

    Hashmap() {
        map = new char **[CAPACITY_HASHMAP];
        citiesArr = new City **[CAPACITY_HASHMAP];
        for (int i = 0; i < CAPACITY_HASHMAP; i++) {
            map[i] = nullptr;
            citiesArr[i] = nullptr;
        }
    }

    ~Hashmap() {
        for (int i = 0; i < CAPACITY_HASHMAP; i++) {
            delete[] citiesArr[i];
            delete[] map[i];
        }
        delete[] citiesArr;
        delete[] map;
    }

    /* Found online, credits goes to Dan Bernstein http://www.cse.yorku.ca/~oz/hash.html */
    static unsigned int hash(char *str) {
        unsigned long int hash = 0;
        for (unsigned int i = 0; i < strlen(str); i++) {
            hash = str[i] + (hash << 6) + (hash << 16) - hash;
        }
        return hash % CAPACITY_HASHMAP;
    }

    void insert(char *str, City *city) {
        int hashed = hash(str);
        if (map[hashed] == nullptr) {
            /* Create city array in free slot, for chaining */
            map[hashed] = new char *[2];
            map[hashed][0] = str;
            map[hashed][1] = nullptr;
            citiesArr[hashed] = new City *[2];
            citiesArr[hashed][0] = city;
            citiesArr[hashed][1] = nullptr;
        } else {
            /* Slot not free */
            int count = 0;
            
            /* Check for duplicate, and count how much needed for copy */
            while (map[hashed][count] != nullptr) {
                if (strcmp(map[hashed][count], str) == 0) {
                    citiesArr[hashed][count] = city;
                    return;
                }
                count++;
            }
            
            /* Make new array and copy everything to new one in free slot */
            char **temp = new char *[count + 2];
            City **tempCity = new City *[count + 2];
            memcpy(temp, map[hashed], count * sizeof(char *));
            memcpy(tempCity, citiesArr[hashed], count * sizeof(City *));
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
            return nullptr;
        }
        for (int i = 0; map[hashed][i] != nullptr; i++) {
            if (strcmp(map[hashed][i], str) == 0) {
                return citiesArr[hashed][i];
            }
        }
        return nullptr;
    }
};