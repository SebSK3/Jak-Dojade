#pragma once
class MyGraph;

struct Position {
    int x;
    int y;
};
struct Node {
    Position pos;
    MyGraph *graph;
    int weight;
    char *name;
};