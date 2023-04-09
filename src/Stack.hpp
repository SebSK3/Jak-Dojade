#pragma once
#include "Structures.hpp"
#include <iostream>

class City;

template <typename T>
struct StackNode {
    T element;
    StackNode<T> *previous;
    StackNode(T element) {
        this->element = element;
        previous = NULL;
    }
};

template <typename T>
struct Stack {   
    StackNode<T> *head = NULL;
    int length = 0;
    ~Stack() {
        StackNode<T> *temp = head;
        while (temp != NULL) {
            StackNode<T> *deletingNode = temp;
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
        StackNode<T> *nextElement = new StackNode<T>(element);
        nextElement->previous = head;
        head = nextElement;
        
    }
    void pop() {
        StackNode<T> *temp = head;
        head = head->previous;
        length--;
        delete temp;
    }
};