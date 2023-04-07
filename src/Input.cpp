#include "Input.hpp"

char **Input::GetMap(LinkedList *list, int x, int y) {
    char **map = new char *[y + 2];
    map[y + 1] = NULL;
    for (int i = 0; i < y; i++) {
        char *line = new char[x + 1];
        char c;
        for (int j = 0; j < x; j++) {
            std::cin >> c;
            line[j] = c;
            if (c == '*') {
                list->append(new City(NULL, {j, i}));
            }
        }
        line[x] = '\0';
        map[i] = line;
    }
#ifdef DEBUG
    std::cout << "LOADED MAP" << std::endl;
#endif
    return map;
}

void Input::ExtractNames(Map *map, LinkedList *cities) {
    if (cities->head == NULL)
        return;
    ListNode *tempCity = cities->head;
    while (tempCity != NULL) {

        Position foundCoords;
        /* Loop just so we can break out of it */
        while (true) {
            if (Helpers::InsideMap(map, {tempCity->city->pos.x - 1,
                                         tempCity->city->pos.y - 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y - 1]
                                  [tempCity->city->pos.x - 1])) {
                    foundCoords = {tempCity->city->pos.x-1, tempCity->city->pos.y-1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x - 1, tempCity->city->pos.y})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y]
                                  [tempCity->city->pos.x - 1])) {
                    foundCoords = {tempCity->city->pos.x-1, tempCity->city->pos.y};
                    break;
                }
            }
            if (Helpers::InsideMap(map, {tempCity->city->pos.x - 1,
                                         tempCity->city->pos.y + 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y + 1]
                                  [tempCity->city->pos.x - 1])) {
                    foundCoords = {tempCity->city->pos.x-1, tempCity->city->pos.y+1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x, tempCity->city->pos.y + 1})) {
                if (Helpers::IsCharacter(map->lines[tempCity->city->pos.y + 1]
                                                   [tempCity->city->pos.x])) {
                    foundCoords = {tempCity->city->pos.x, tempCity->city->pos.y+1};
                    break;
                }
            }
            if (Helpers::InsideMap(map, {tempCity->city->pos.x + 1,
                                         tempCity->city->pos.y + 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y + 1]
                                  [tempCity->city->pos.x + 1])) {
                    foundCoords = {tempCity->city->pos.x+1, tempCity->city->pos.y+1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x + 1, tempCity->city->pos.y})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y]
                                  [tempCity->city->pos.x + 1])) {
                    foundCoords = {tempCity->city->pos.x+1, tempCity->city->pos.y};
                    break;
                }
            }
            if (Helpers::InsideMap(map, {tempCity->city->pos.x + 1,
                                         tempCity->city->pos.y - 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y - 1]
                                  [tempCity->city->pos.x + 1])) {
                    foundCoords = {tempCity->city->pos.x+1, tempCity->city->pos.y-1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x, tempCity->city->pos.y - 1})) {
                if (Helpers::IsCharacter(map->lines[tempCity->city->pos.y - 1]
                                                   [tempCity->city->pos.x])) {
                    foundCoords = {tempCity->city->pos.x-1, tempCity->city->pos.y-1};
                    break;
                }
            }
        }
        tempCity->city->name = Helpers::BuildCityName(map, foundCoords);
        tempCity = tempCity->next;
    }
}