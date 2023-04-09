#pragma once
#include <iostream>

template <typename T>
struct DequeNode {
    T element;
    DequeNode<T> *previous;
    DequeNode(T el) {
        element = el;
        previous = NULL;
    }
};

template <typename T>
struct Deque {   
    DequeNode<T> *head = NULL;
    int length = 0;
    ~Deque() {
        DequeNode<T> *temp = head;
        while (temp != NULL) {
            DequeNode<T> *deletingNode = temp;
            temp = temp->previous;
            delete deletingNode;
        }
    }
    bool empty() {
        return length == 0 ? true : false;
    }
    T top() {
        return head->element;
    }
    void push(T element) {
        length++;
        DequeNode<T> *nextElement = new DequeNode<T>(element);
        nextElement->previous = head;
        head = nextElement;
        
    }
    void pop() {
        DequeNode<T> *temp = head;
        head = head->previous;
        length--;
        delete temp;
    }
};