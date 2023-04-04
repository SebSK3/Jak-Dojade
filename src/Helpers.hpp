#pragma once
#include <iostream>
#include "MyGraph.hpp"

#ifndef NDEBUG
void DUMP_CITY(MyGraph *graph) {
    
    LinkedList *tempList = graph->edges;
    std::cout << "Graph " << graph->data->name << " dumped:" << std::endl;
    while (tempList != NULL) {
        std::cout << "Connected: " << tempList->data->name 
        << ", with weight: " << tempList->data->weight << std::endl;
        tempList = tempList->next;
    }
}
#endif