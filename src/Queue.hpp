#pragma once
#include <iostream>


template <typename T>
struct QueueNode {
    T element;
    QueueNode<T> *next = NULL;
    explicit QueueNode(T el) {
        element = el;
    }
};

template <typename T>
struct Queue {   
    QueueNode<T> *head = NULL;
    QueueNode<T> *tail = NULL;
    int length = 0;
    ~Queue() {
        QueueNode<T> *temp = head;
        while (temp != NULL) {
            QueueNode<T> *deletingNode = temp;
            temp = temp->next;
            delete deletingNode;
        }
    }
    const bool empty() {
        return length == 0 ? true : false;
    }
    void push(T element) {
        
        length++;
        QueueNode<T> *nextElement = new QueueNode<T>(element);
        if (length == 1) {
            head = nextElement;
            tail = nextElement;
            return;
        }
        tail->next = nextElement;
        tail = nextElement;

    }
    T front() {
        return head->element;
    }
    void pop() {
        QueueNode<T> *temp = head;
        head = head->next;
        length--;
        delete temp;
    }
};