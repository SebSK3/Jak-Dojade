#pragma once
#include <iostream> 
#include "Structures.hpp"
class City;

struct LinkedList {
    LinkedList *next = NULL;
    LinkedList *prev = NULL;
    LinkedList *head = NULL;
    
    City *city = NULL;
    int weight = 0;
    void append(City *element, int weight) {
        if (city == NULL) {
            city = element;
            this->weight = weight;
            return;
        }
        LinkedList *nextElementInList = new LinkedList;
        nextElementInList->city = element;
        nextElementInList->weight = weight;
        LinkedList *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        nextElementInList->head = head;
        temp->next = nextElementInList;
    }
    LinkedList *remove(LinkedList *element) {
        LinkedList *temp = head;
        if (temp == head) {
            LinkedList *newHead = head->next;
            while (temp != NULL) {
                temp->head = newHead;
                temp = temp->next;
            }
            delete element;
            return newHead;
        }
        while (temp != NULL) {
            if (temp->next == element) {
                temp->next = temp->next->next;
                delete element;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};