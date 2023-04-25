#include "Helpers.hpp"
#include <iostream>

bool Helpers::IsCharacter(char c) {
    if (isalnum(c))
        return true;
    return false;
}

bool Helpers::isNotWeirdAsciiChar(char c) {
    if (isalnum(c)) {
        return true;
    }
    if (c == 35 || c == 42 || c == 46) {
        return true;
    }
    return false;
}

City *Helpers::FindCityByPos(LinkedList<City *> *cities, Position pos) {
    ListNode<City *> *temp = cities->head;
    while (temp != nullptr) {
        if (temp->data->pos == pos) {
            return temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool Helpers::InsideMap(const Map &map, Position coords) {
    if (map.x - 1 < coords.x)
        return false;
    if (coords.x < 0) {
        return false;
    }
    if (map.y - 1 < coords.y) {
        return false;
    }
    if (coords.y < 0) {
        return false;
    }
    return true;
}

char *Helpers::BuildCityName(const Map &map, Position coords) {
    int i = coords.x;

    int nameLength = 1;
    while (InsideMap(map, {i, coords.y}) &&
           IsCharacter(map.lines[coords.y][i])) {
        i--;
        nameLength++;
    }
    nameLength--;
    int j = coords.x;
    while (InsideMap(map, {j, coords.y}) &&
           IsCharacter(map.lines[coords.y][j])) {
        j++;
        nameLength++;
    }
    nameLength--;
    i++;
    char *name = new char[nameLength + 1];
    name[nameLength] = '\0';
    for (int k = 0; k < nameLength; k++) {
        name[k] = map.lines[coords.y][i + k];
    }
    return name;
}

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

