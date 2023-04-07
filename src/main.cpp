#include "City.hpp"
#include "Helpers.hpp"
#include "Input.hpp"
#include "PathFinder.hpp"
#include <iostream>

int main() {
    Helpers::CITY_ID(true);
    int x, y;
    Map *map = new Map;
    LinkedList *cities = new LinkedList;
    PathFinder *pathfinder = new PathFinder;
    std::cin >> x >> y;
    map->x = x;
    map->y = y;
    map->lines = Input::GetMap(cities, map->x, map->y);
    for (int i = 0; i < map->y; i++) {
        std::cout << map->lines[i] << std::endl;
    }
    

    Input::ExtractNames(map, cities);
    pathfinder->FindEdges(map, cities);
#ifdef DEBUG
    // Helpers::DUMP_CITY(cities->head->city);
    Helpers::DUMP_LIST(cities);
#endif

    ListNode *temp = cities->head; 
    while (temp != NULL) {
        delete temp->city;
        temp = temp->next;
    }
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