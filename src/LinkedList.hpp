#pragma once
#include "Structures.hpp"
#include <iostream>


template<typename T>
struct ListNode {
    T *data;
    int weight;
    ListNode<T> *next;
    ListNode() {}
    ListNode(T *data, int weight = 0) {
        this->data = data;
        this->weight = weight;
        next = NULL;
    }
};

template<typename T>
struct LinkedList {   
    ListNode<T> *head = NULL;
    ListNode<T> *tail = NULL;
    int length = 0;
    ~LinkedList<T>() {
        ListNode<T> *current = head;
        while (current != NULL) {
            ListNode<T> *next = current->next;
            delete current;
            current = next;
        }
    }
    void append(T *element, int weight = 0) {
        length++;
        ListNode<City> *nextElement = new ListNode<City>(element, weight);
        /* First element in list */
        if (head == NULL) {
            head = nextElement;
            tail = nextElement;
            return;
        }
        tail->next = nextElement;
        tail = nextElement;

    }
};