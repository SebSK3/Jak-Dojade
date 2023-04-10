#pragma once

#include "Helpers.hpp"
#include "LinkedList.hpp"


class City {
public:
    City(char *name, Position position);
    City();
    ~City();
    void AddConnection(City *city, int weight);

    LinkedList<City> *edges = NULL;
    char *name;
    unsigned int ID = 0;   
    Position pos;
private:
};