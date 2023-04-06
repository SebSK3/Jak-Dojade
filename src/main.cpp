#include <iostream>
#include "City.hpp"
#include "Helpers.hpp"
#include "Input.hpp"

int main() {
    Helpers::CITY_ID(true);
    int x,y;
    LinkedList *cities = new LinkedList;
    std::cin >> x >> y;
    char **map = Input::GetMap(cities, x, y);
    for (int i=0; i<y; i++) {
        std::cout << map[i] << std::endl;
    }
    


    for (int i=0; i<y; i++) {
        delete[] map[i];
    }
    delete[] map;
    delete cities;
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