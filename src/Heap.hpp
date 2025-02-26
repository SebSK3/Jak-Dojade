#pragma once
#include "City.hpp"
#include "Config.hpp"
struct Heap {
    int *arr;
    int *vals;
    int size = 0;
    int capacity;
    Heap() {
        arr = new int[CAPACITY_HEAP];
        vals = new int[CAPACITY_HEAP];
        capacity = CAPACITY_HEAP;
    }
    ~Heap() {
        delete[] arr;
        delete[] vals;
    }
    static int parent(int i) { return (i - 1) / 2; }
    static int left(int i) { return 2 * i + 1; }
    static int right(int i) { return 2 * i + 2; }
    static void swap(int &l, int &r) {
        int temp = l;
        l = r;
        r = temp;
    }
    void heapify(int i) {
        int lChild = left(i);
        int rChild = right(i);
        int lowest = i;
        if (lChild < size && arr[lChild] < arr[lowest]) {
            lowest = lChild;
        }
        if (rChild < size && arr[rChild] < arr[lowest]) {
            lowest = rChild;
        }
        if (lowest != i) {
            swap(arr[i], arr[lowest]);
            swap(vals[i], vals[lowest]);
            heapify(lowest);
        }
    }
    void insert(int num, int val) {
        if (size >= capacity) {
            capacity *= CAPACITY_REALLOC_EVERY;
            int *new_arr = new int[capacity];
            int *new_vals = new int[capacity];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
                new_vals[i] = vals[i];
            }
            delete[] arr;
            delete[] vals;
            arr = new_arr;
            vals = new_vals;
        }

        int index = size;
        arr[index] = num;
        vals[index] = val;
        size++;

        while (index != 0 && arr[index] < arr[parent(index)]) {
            swap(arr[index], arr[parent(index)]);
            swap(vals[index], vals[parent(index)]);
            index = parent(index);
        }
    }
};