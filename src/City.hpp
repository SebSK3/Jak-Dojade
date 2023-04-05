#pragma once

#include "LinkedList.hpp"
#include "Helpers.hpp"


class City {
public:
    City(char *name, Position position);

    ~City();
    void AddConnection(City *city, int weight);

    LinkedList *edges = NULL;
    char *name;
    unsigned int ID = 0;
        
private:
    Position pos;
};