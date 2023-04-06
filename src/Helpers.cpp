#include "Helpers.hpp"
unsigned int Helpers::CITY_ID(bool firstUsed, bool shouldIncrement) {
    static unsigned int id;
    if (firstUsed) {
        id = 0;
        return id;
    }
    if (shouldIncrement)
    id++;
    return id;
}

#ifndef NDEBUG
void Helpers::DUMP_CITY(City *city) {
    ListNode *tempList = city->edges->head;
    std::cout << "Graph " << city->name << "(ID:" << city->ID << ") dumped:" << std::endl;
    while (tempList != NULL) {
        std::cout << "Connected: " << tempList->city->name << " (ID:" << tempList->city->ID
                  << "), with weight: " << tempList->weight << std::endl;
        tempList = tempList->next;
    }
}
void Helpers::DUMP_GRAPH(City *city) {
    int count = CITY_ID(false, false);
    bool *visited = new bool[count];
    std::queue<City*> queue;
    for (int i=0; i<count; i++) {
        visited[i] = false;
    }
    queue.push(city);
    visited[city->ID] = true;
    while (!queue.empty()) {
        City *v = queue.front();
        queue.pop();
        DUMP_CITY(v);
        ListNode *iter = v->edges->head;
        while (iter != NULL) {
            City *u = iter->city;
            if (!visited[u->ID]) {
                visited[u->ID] = true;
                queue.push(u);
            }
            iter = iter->next;
        }
    }
    delete[] visited;
}
#endif