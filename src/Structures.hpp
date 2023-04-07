#pragma once
#include <functional>
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

    // Add a default constructor
    Position() : x(0), y(0) {}

    Position(int x, int y) : x(x), y(y) {}

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template <>
    struct hash<Position> {
        std::size_t operator()(const Position& pos) const {
            std::size_t h1 = std::hash<int>{}(pos.x);
            std::size_t h2 = std::hash<int>{}(pos.y);

            // Use a simple combination of the two hashes, for example using XOR
            return h1 ^ h2;
        }
    };
}