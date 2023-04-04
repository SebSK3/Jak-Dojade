#pragma once
#include <iostream> 
#include "Structures.hpp"

struct LinkedList {
    LinkedList *next = NULL;
    LinkedList *prev = NULL;
    LinkedList *head = NULL;
    
    Node* data = NULL;
    void append(Node *element) {
        if (data == NULL) {
            data = element;
            return;
        }
        LinkedList *nextElementInList = new LinkedList;
        nextElementInList->data = element;
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
            delete element->data;
            delete element;
            return newHead;
        }
        while (temp != NULL) {
            if (temp->next == element) {
                temp->next = temp->next->next;
                delete element->data;
                delete element;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};