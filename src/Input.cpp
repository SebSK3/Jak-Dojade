#include "Input.hpp"

void Input::GetFlight(int flights, char *name1, char *name2,
                      Hashmap &cities) {

    int weight = 0;
    char c = '.';
    int i = 0;
    while (flights > 0) {
        getchar();
        while ((c = getchar()) != ' ') {
            name1[i] = c;
            i++;
        }
        name1[i] = '\0';
        i = 0;
        while ((c = getchar()) != ' ') {
            name2[i] = c;
            i++;
        }
        name2[i] = '\0';
        i = 0;
        std::scanf("%d", &weight);
        cities.find(name1)->edges->append(cities.find(name2),
                                                  weight);
        flights--;
    }
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

void Input::ExtractNames(Map *map, LinkedList *cities,
                         Hashmap &citiesMap,
                         City **citiesArr) {
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
                if (Helpers::InsideMap(map, {x, y}) &&
                    Helpers::IsCharacter(map->lines[y][x])) {
                    foundCoords = {x, y};
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        tempCity->city->name = Helpers::BuildCityName(map, foundCoords);
        citiesMap.insert(tempCity->city->name, tempCity->city);
        citiesArr[tempCity->city->ID] = tempCity->city;
        tempCity = tempCity->next;
    }
}