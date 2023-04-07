#pragma once

#include "Helpers.hpp"
#include "LinkedList.hpp"


class City {
public:
    City(char *name, Position position);

    ~City();
    void AddConnection(City *city, int weight);
    ListNode *Connection(City *city);

    LinkedList *edges = NULL;
    char *name;
    unsigned int ID = 0;   
    Position pos;
private:
};