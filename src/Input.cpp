#include "Input.hpp"

void Input::GetFlight(int flights, char *name1, char *name2, City **citiesArr,
                      std::unordered_map<std::string, int> &cities) {

    int weight = 0;

    while (flights > 0) {
    std::scanf("%s %s %d", name1, name2, &weight);
    
    City *src = citiesArr[cities.find(name1)->second];
    City *dest = citiesArr[cities.find(name2)->second];
    src->AddConnection(dest, weight);
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
                         std::unordered_map<std::string, int> &citiesMap,
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
        citiesMap.insert({tempCity->city->name, tempCity->city->ID});
        citiesArr[tempCity->city->ID] = tempCity->city;
        // citiesByPosition.insert({tempCity->city->pos, tempCity->city});
        tempCity = tempCity->next;
    }
}