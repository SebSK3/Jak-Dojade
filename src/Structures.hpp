#pragma once
struct Map {
    int x, y;
    char **lines;
    ~Map() {
        for (int i = 0; i < y; i++) {
            delete[] lines[i];
        }
        delete[] lines;
    }
};
struct Position {
    int x;
    int y;
};