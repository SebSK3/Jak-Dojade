#include "Helpers.hpp"
unsigned int Helpers::CITY_ID(bool firstUsed = false) {
    static unsigned int id;
    if (firstUsed) {
        id = 0;
        return id;
    }
    id++;
    return id;
}

#ifndef NDEBUG
void Helpers::DUMP_CITY(City *city) {
    LinkedList *tempList = city->edges;
    std::cout << "Graph " << city->name << " dumped:" << std::endl;
    while (tempList != NULL) {
        std::cout << "Connected: " << tempList->city->name
                  << ", with weight: " << tempList->weight << std::endl;
        tempList = tempList->next;
    }
}
#endif