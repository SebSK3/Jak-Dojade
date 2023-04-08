#include "City.hpp"
City::City(char *name, Position position) : name(name), pos(position) {
    edges = new LinkedList;
    ID = Helpers::CITY_ID(false);
}
City::City() {
    
}
City::~City() {
    delete[] name;
    delete edges;
}
void City::AddConnection(City *city, int weight) {
    edges->append(city, weight);
}

ListNode *City::Connection(City *city) {
    if (edges != NULL) {
        ListNode *temp = edges->head;
        while (temp != NULL) {
            if (temp->city == city) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}