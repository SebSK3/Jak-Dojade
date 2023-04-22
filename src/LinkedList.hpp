#pragma once
#include "Structures.hpp"

class City;

template <typename T> struct ListNode {
    T data;
    int weight;
    ListNode<T> *next;
    ListNode(T data, int weight = 0) {
        this->data = data;
        this->weight = weight;
        next = nullptr;
    }
};

template <typename T> struct LinkedList {
    ListNode<T> *head = nullptr;
    ListNode<T> *tail = nullptr;
    int length = 0;
    ~LinkedList<T>() {
        ListNode<T> *current = head;
        while (current != nullptr) {
            ListNode<T> *next = current->next;
            delete current;
            current = next;
        }
    }
    void append(T element, int weight = 0) {
        length++;
        ListNode<T> *nextElement = new ListNode<T>(element, weight);
        /* First element in list */
        if (head == nullptr) {
            head = nextElement;
            tail = nextElement;
            return;
        }
        tail->next = nextElement;
        tail = nextElement;
    }
};