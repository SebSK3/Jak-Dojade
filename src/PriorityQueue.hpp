#pragma once
#include "Heap.hpp"
#include <iostream>
struct PriorityQueue {
    Heap heap;

    void insert(int num, int val) { heap.insert(num, val); }

    const int getMin() const {
        if (heap.size == 0) {
            return -1;
        }
        return heap.vals[0];
    }
    void pop() {
        if (heap.size == 0) {
            return;
        }
        heap.arr[0] = heap.arr[heap.size - 1];
        heap.vals[0] = heap.vals[heap.size - 1];
        heap.size--;
        heap.heapify(0);
    }
    const bool empty() const { return heap.size == 0; }
};