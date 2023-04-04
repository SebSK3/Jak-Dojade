#pragma once
#include "LinkedList.hpp"
struct Node;

class MyGraph {
public:
    MyGraph();
    Node *data;
    LinkedList *edges;
};