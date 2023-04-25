#include "Input.hpp"
#include <iostream>

void Input::GetFlights(char *name1, char *name2, Hashmap *cities) {

    int flights;
    scanf("%d", &flights);
    int weight = 0;
    int i = 0;
    while (flights > 0) {
        char c = '.';
        getchar();
        while ((c = getchar()) != ' ') {
            if (Helpers::isNotWeirdAsciiChar(c)) {
                name1[i] = c;
                i++;
            }
        }
        name1[i] = '\0';
        i = 0;
        while ((c = getchar()) != ' ') {
            if (Helpers::isNotWeirdAsciiChar(c)) {
                name2[i] = c;
                i++;
            }
        }
        name2[i] = '\0';
        i = 0;
        std::scanf("%d", &weight);
        cities->find(name1)->edges.append(cities->find(name2), weight);
        flights--;
    }
}
char **Input::GetMap(LinkedList<City *> *list, const int &x, const int &y) {
    char **map = new char *[y + 2];
    map[y + 1] = nullptr;
    for (int i = 0; i < y; i++) {
        char *line = new char[x + 1];
        for (int j = 0; j < x; j++) {
            char c = getchar();
            if (Helpers::isNotWeirdAsciiChar(c)) {
                line[j] = c;
                if (line[j] == '*') {
                    list->append(new City(nullptr, {j, i}));
                }
            } else {
                j--;
            }
        }
        line[x] = '\0';
        map[i] = line;
        getchar();
    }
    return map;
}

void Input::ExtractNames(const Map &map, LinkedList<City *> *cities,
                         Hashmap *citiesMap, City **citiesArr) {
    if (cities->head == nullptr)
        return;
    ListNode<City *> *tempCity = cities->head;
    while (tempCity != nullptr) {

        Position foundCoords;
        bool found = false;
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dy == 0 && dx == 0) {
                    continue;
                }

                int x = tempCity->data->pos.x + dx;
                int y = tempCity->data->pos.y + dy;
                if (Helpers::InsideMap(map, {x, y}) &&
                    Helpers::IsCharacter(map.lines[y][x])) {
                    foundCoords = {x, y};
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        tempCity->data->name = Helpers::BuildCityName(map, foundCoords);
        citiesMap->insert(tempCity->data->name, tempCity->data);
        citiesArr[tempCity->data->ID] = tempCity->data;
        tempCity = tempCity->next;
    }
}