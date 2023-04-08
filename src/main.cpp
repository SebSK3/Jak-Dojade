#include "City.hpp"
#include "Helpers.hpp"
#include "Input.hpp"
#include "PathFinder.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    Helpers::CITY_ID(true);
    int x, y;
    Map *map = new Map;
    LinkedList *cities = new LinkedList;
    City **citiesArr;
    std::unordered_map<std::string, City*> citiesMap;
    // std::unordered_map<Position, City *> citiesByPos;
    PathFinder *pathfinder = new PathFinder;
    scanf("%d %d", &x, &y);
    getchar();

    map->x = x;
    map->y = y;
    map->lines = Input::GetMap(cities, map->x, map->y);

    // for (int i = 0; i < map->y; i++) {
    //     std::cout << map->lines[i] << std::endl;
    // }
    citiesArr = new City *[cities->length + 1];

    Input::ExtractNames(map, cities, citiesMap, citiesArr);

    int flights;
    std::cin >> flights;

    char name1[25], name2[25];
        Input::GetFlight(flights, name1, name2, citiesArr, citiesMap);

    pathfinder->FindEdges(map, cities);
    std::vector<int> dist(cities->length + 1, std::numeric_limits<int>::max());
    std::vector<bool> visited(cities->length + 1, false);
    std::vector<int> parent(cities->length + 1, -1);
    int q;
    char *src = new char[20];
    char *dest = new char[20];
    int type;
    scanf("%d", &q);
    while (q > 0) {
        scanf("%s %s %d", src, dest, &type);
        if (strcmp(src, dest) == 0) {
            std::cout << "0" << std::endl;
            q--;
            continue;
        }
        auto it1 = citiesMap.find(src);
        auto it2 = citiesMap.find(dest);

        pathfinder->FindPath(citiesArr, it1->second, it2->second, type,
                             cities->length + 1, dist, visited, parent);
        q--;
    }
    delete[] src;
    delete[] dest;

#ifdef DEBUG
    // Helpers::DUMP_CITY(cities->head->city);
    Helpers::DUMP_LIST(cities);
#endif

    ListNode *temp = cities->head;
    while (temp != NULL) {
        delete temp->city;
        temp = temp->next;
    }
    delete[] citiesArr;
    delete cities;
    delete map;
    delete pathfinder;
    // char *name = "1";
    // char *name2 = "2";
    // char *name3 = "3";
    // char *name4 = "4";
    // City *city = new City(name, {0, 0});
    // City *city2 = new City(name2, {0, 0});
    // City *city3 = new City(name3, {0, 0});
    // City *city4 = new City(name4, {0, 0});
    // city->AddConnection(city2, 2);
    // city->AddConnection(city3, 3);
    // city->AddConnection(city4, 4);
    // city2->AddConnection(city, 4);
    // #ifdef DEBUG
    // Helpers::DUMP_GRAPH(city);
    // #endif
    return 0;
}