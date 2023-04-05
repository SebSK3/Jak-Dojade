#include "City.hpp"
City::City(char *name, Position position) {
    this->name = name;
    this->pos = position;
    ID = Helpers::CITY_ID(true);
}
City::~City() {
    delete name;
    LinkedList *temp = edges;
    while (temp != NULL) {
        LinkedList *deletingList = temp;
        temp = temp->next;
        delete deletingList;
    }
}
void City::AddConnection(City *city, int weight) {
    if (edges == NULL) {
        edges = new LinkedList;
        edges->head = edges;
    } 
    edges->append(city, weight);
}