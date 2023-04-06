#include "City.hpp"
#include "Helpers.hpp"
#include "Input.hpp"
#include <iostream>

int main() {
    Helpers::CITY_ID(true);
    Map *map = new Map;
    LinkedList *cities = new LinkedList;
    std::cin >> map->x >> map->y;
    map->lines = Input::GetMap(cities, map->x, map->y);
    for (int i = 0; i < map->y; i++) {
        std::cout << map->lines[i] << std::endl;
    }
    

    Input::ExtractNames(map, cities);
#ifndef NDEBUG
    // Helpers::DUMP_CITY(cities->head->city);
    Helpers::DUMP_LIST(cities);
#endif


    delete cities;
    delete map;
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
    // #ifndef NDEBUG
    // Helpers::DUMP_GRAPH(city);
    // #endif
    return 0;
}