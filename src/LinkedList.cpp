#include "LinkedList.hpp"
#include "City.hpp"
LinkedList::~LinkedList() {
    ListNode *current = head;
    while (current != NULL) {
        ListNode *next = current->next;
        delete current;
        current = next;
    }
}

ListNode *LinkedList::getNodeByCityId(int ID) {
    ListNode *temp = head;
    while (temp != NULL) {
        if (temp->city->ID == ID) {
            return temp->city->edges->head;
        }
        temp = temp->next;
    }
    return NULL;
}

City *LinkedList::getCityByName(char *name) {
    ListNode *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->city->name, name) == 0) {
            return temp->city;
        }
        temp = temp->next;
    }
    return NULL;
}

City *LinkedList::getCityById(int ID) {
    ListNode *temp = head;
    while (temp != NULL) {
        if (temp->city->ID == ID) {
            return temp->city;
        }
        temp = temp->next;
    }
    return NULL;
}