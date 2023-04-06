#include "City.hpp"
City::City(char *name, Position position) {
    this->name = name;
    this->pos = position;
    ID = Helpers::CITY_ID(false);
}
City::~City() {
    delete name;
    delete edges;
}
void City::AddConnection(City *city, int weight) {
    if (edges == NULL) {
        edges = new LinkedList;
    } 
    edges->append(city, weight);
}