#include "LinkedList.hpp"
#include "City.hpp"
LinkedList::~LinkedList() {
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *next = current->next;
        delete current->city;
        delete current;
        current = next;
    }
}