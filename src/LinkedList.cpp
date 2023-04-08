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