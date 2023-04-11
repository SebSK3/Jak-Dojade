#pragma once
#include <iostream>


template <typename T>
struct StackNode {
    T element;
    StackNode<T> *previous;
    explicit StackNode(T el) {
        element = el;
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
    const bool empty() const {
        return length == 0 ? true : false;
    }
    const T top() const {
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