#pragma once
#include "Structures.hpp"
#include <iostream>

class City;

struct ListNode {
    City *city;
    int weight;
    ListNode *next;
    ListNode(City *city, int weight=0) {
        this->city = city;
        this->weight = weight;
        next = NULL;
    }
};
struct LinkedList {   
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int length = 0;
    ~LinkedList();
    void append(City *element, int weight = 0) {
        length++;
        ListNode *nextElement = new ListNode(element, weight);
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