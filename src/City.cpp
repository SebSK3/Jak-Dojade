#include "City.hpp"
City::City(char *name, Position position) : name(name), pos(position) {
    ID = Helpers::CITY_ID(false);
}
City::~City() { delete[] name; }
void City::AddConnection(City *city, int weight) { edges.append(city, weight); }