#include "Input.hpp"

void Input::GetFlight(char *name1, char *name2, std::unordered_map<std::string, City*>& cities) {
    int weight = 0;
    std::scanf("%s %s %d", name1, name2, &weight);

    auto it1 = cities.find(name1);
    auto it2 = cities.find(name2);
    if (it1 == cities.end() || it2 == cities.end()) {
        return;
    }
    City *src = it1->second;
    City *dest = it2->second;

    ListNode *connection = src->Connection(dest);
    if (connection != NULL) {
        if (connection->weight > weight) {
            connection->weight = weight;
        }
        return;
    }
    src->AddConnection(dest, weight);
}
char **Input::GetMap(LinkedList *list, int x, int y) {
    char **map = new char *[y + 2];
    map[y + 1] = NULL;
    for (int i = 0; i < y; i++) {
        char *line = new char[x + 1];
        for (int j = 0; j < x; j++) {
            scanf("%c", &line[j]);
            if (line[j] == '*') {
                list->append(new City(NULL, {j, i}));
            }
        }
        line[x] = '\0';
        map[i] = line;
        getchar();
    }
#ifdef DEBUG
    std::cout << "LOADED MAP" << std::endl;
#endif
    return map;
}

void Input::ExtractNames(Map *map, LinkedList *cities, std::unordered_map<std::string, City*>& cities2, City **citiesArr) {
    if (cities->head == NULL)
        return;
    ListNode *tempCity = cities->head;
    while (tempCity != NULL) {

        Position foundCoords;
        bool found = false;
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dy == 0 && dx == 0) {
                    continue;
                }

                    int x = tempCity->city->pos.x + dx;
                    int y = tempCity->city->pos.y + dy;
                    if (Helpers::InsideMap(map, {x, y}) && Helpers::IsCharacter(map->lines[y][x])) {
                        foundCoords = {x, y};
                        found = true;
                        break;
                    }
            }
            if (found) break;
        }
        /* Loop just so we can break out of it */
        // while (true) {
        //     if (Helpers::InsideMap(map, {tempCity->city->pos.x - 1,
        //                                  tempCity->city->pos.y - 1})) {
        //         if (Helpers::IsCharacter(
        //                 map->lines[tempCity->city->pos.y - 1]
        //                           [tempCity->city->pos.x - 1])) {
        //             foundCoords = {tempCity->city->pos.x - 1,
        //                            tempCity->city->pos.y - 1};
        //             break;
        //         }
        //     }
        //     if (Helpers::InsideMap(
        //             map, {tempCity->city->pos.x - 1, tempCity->city->pos.y})) {
        //         if (Helpers::IsCharacter(
        //                 map->lines[tempCity->city->pos.y]
        //                           [tempCity->city->pos.x - 1])) {
        //             foundCoords = {tempCity->city->pos.x - 1,
        //                            tempCity->city->pos.y};
        //             break;
        //         }
        //     }
        //     if (Helpers::InsideMap(map, {tempCity->city->pos.x - 1,
        //                                  tempCity->city->pos.y + 1})) {
        //         if (Helpers::IsCharacter(
        //                 map->lines[tempCity->city->pos.y + 1]
        //                           [tempCity->city->pos.x - 1])) {
        //             foundCoords = {tempCity->city->pos.x - 1,
        //                            tempCity->city->pos.y + 1};
        //             break;
        //         }
        //     }
        //     if (Helpers::InsideMap(
        //             map, {tempCity->city->pos.x, tempCity->city->pos.y + 1})) {
        //         if (Helpers::IsCharacter(map->lines[tempCity->city->pos.y + 1]
        //                                            [tempCity->city->pos.x])) {
        //             foundCoords = {tempCity->city->pos.x,
        //                            tempCity->city->pos.y + 1};
        //             break;
        //         }
        //     }
        //     if (Helpers::InsideMap(map, {tempCity->city->pos.x + 1,
        //                                  tempCity->city->pos.y + 1})) {
        //         if (Helpers::IsCharacter(
        //                 map->lines[tempCity->city->pos.y + 1]
        //                           [tempCity->city->pos.x + 1])) {
        //             foundCoords = {tempCity->city->pos.x + 1,
        //                            tempCity->city->pos.y + 1};
        //             break;
        //         }
        //     }
        //     if (Helpers::InsideMap(
        //             map, {tempCity->city->pos.x + 1, tempCity->city->pos.y})) {
        //         if (Helpers::IsCharacter(
        //                 map->lines[tempCity->city->pos.y]
        //                           [tempCity->city->pos.x + 1])) {
        //             foundCoords = {tempCity->city->pos.x + 1,
        //                            tempCity->city->pos.y};
        //             break;
        //         }
        //     }
        //     if (Helpers::InsideMap(map, {tempCity->city->pos.x + 1,
        //                                  tempCity->city->pos.y - 1})) {
        //         if (Helpers::IsCharacter(
        //                 map->lines[tempCity->city->pos.y - 1]
        //                           [tempCity->city->pos.x + 1])) {
        //             foundCoords = {tempCity->city->pos.x + 1,
        //                            tempCity->city->pos.y - 1};
        //             break;
        //         }
        //     }
        //     if (Helpers::InsideMap(
        //             map, {tempCity->city->pos.x, tempCity->city->pos.y - 1})) {
        //         if (Helpers::IsCharacter(map->lines[tempCity->city->pos.y - 1]
        //                                            [tempCity->city->pos.x])) {
        //             foundCoords = {tempCity->city->pos.x - 1,
        //                            tempCity->city->pos.y - 1};
        //             break;
        //         }
        //     }
        // }
        tempCity->city->name = Helpers::BuildCityName(map, foundCoords);
        cities2.insert({tempCity->city->name, tempCity->city});
        citiesArr[tempCity->city->ID] = tempCity->city;
        tempCity = tempCity->next;
    }
}