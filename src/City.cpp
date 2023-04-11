#include "City.hpp"
City::City(char *name, Position position) : name(name), pos(position) {
    edges = new LinkedList<City>;
    ID = Helpers::CITY_ID(false);
}
City::~City() {
    delete[] name;
    delete edges;
}
void City::AddConnection(City *city, int weight) {
    edges->append(city, weight);
}