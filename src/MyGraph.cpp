#include "MyGraph.hpp"
MyGraph::MyGraph() {
    edges = new LinkedList;
    edges->head = edges;
}