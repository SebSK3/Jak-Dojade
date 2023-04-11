#pragma once
#include "Heap.hpp"
#include <iostream>
struct PriorityQueue {
    Heap heap;
    
    void insert(int num) {
        heap.insert(num);
    }
    
    int getMin() {
        if (heap.size == 0) {
            return -1;
        }
        return heap.arr[0];
    }
    void pop() {
        if (heap.size == 0) {
            return;
        }
        heap.arr[0] = heap.arr[heap.size - 1];
        heap.size--;
        heap.heapify(0);
    }
    bool empty() {
        return heap.size == 0;
    }
};