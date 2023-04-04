#include <iostream>
#include "Helpers.hpp"
#include "MyGraph.hpp"
#include "Structures.hpp"

int main() {
    MyGraph *city = new MyGraph;
    Node *node = new Node;
    node->weight = 5;
    char *name = "abcdef";
    node->name = name;
    city->data = node;
    #ifndef NDEBUG
    DUMP_CITY(city);
    #endif
    delete city;
    delete node;
    return 0;
}