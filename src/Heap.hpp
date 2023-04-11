#pragma once
#include "City.hpp"
const int CAPACITY_HEAP = 500;
struct Heap {
    int *arr;
    int size = 0;
    Heap() {
        arr = new int[CAPACITY_HEAP];
    }
    ~Heap() {
        delete arr;
    }
    int parent(int i) { return i / 2; }
    int left(int i) { return i * 2; }
    int right(int i) { return i * 2 + 1; }
    void swap(int &l, int &r) {
        int temp = l;
        l = r;
        r = temp;
    }
    void heapify(int i) {
        int lChild = left(i);
        int rChild = right(i);
        int largest = i;
        if (lChild < size && arr[lChild] > arr[largest]) {
            largest = lChild;
        }
        if (rChild < size && arr[rChild] > arr[largest]) {
            largest = rChild;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
    void insert(int num) {
        if (size >= CAPACITY_HEAP) {
            // Cannot insert more elements, the heap is full
            return;
        }

        int index = size;
        arr[index] = num;
        size++;

        while (index != 0 && arr[index] > arr[(index - 1) / 2]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
};