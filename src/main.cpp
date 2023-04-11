#include "City.hpp"
#include "Helpers.hpp"
#include "Input.hpp"
#include "PathFinder.hpp"
#include "Hashmap.hpp"
#include "Heap.hpp"
#include <iostream>
#include <string>

int main() {
    Heap heap;
    heap.insert(5);
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    for (int i=0; i<heap.size; i++) {
        std::cout << heap.arr[i] << std::endl;
    }
//     // Hashmap test;
//     // char *str = new char[5];
//     // char *str2 = new char[5];
//     // char *str3 = new char[5];
//     // str[0] = 'a';
//     // str[1] = 'b';
//     // str[2] = 'c';
//     // str[3] = '\0';
//     // strcpy(str2, str);
//     // strcpy(str3, str);
//     // str2[0] = 'b';
//     // str3[0] = 'c';
    
//     // City *city = new City(str, {0, 0});
//     // City *city2 = new City(str2, {2, 0});
//     // City *city3 = new City(str3, {5, 0});
//     // test.insert(city->name, city);
//     // test.insert(city2->name, city2);
//     // test.insert(city3->name, city3);
//     // std::cout << test.find(str)->pos.x << std::endl;
//     // std::cout << test.find(str2)->pos.x << std::endl;
//     // std::cout << test.find(str3)->pos.x << std::endl;
//     // delete city;

//     Helpers::CITY_ID(true);
//     int x, y;
//     Map *map = new Map;
//     LinkedList<City> *cities = new LinkedList<City>;
//     City **citiesArr;
//     Hashmap citiesMap;
//     PathFinder *pathfinder = new PathFinder;
//     scanf("%d %d", &x, &y);
//     getchar();

//     map->x = x;
//     map->y = y;
//     map->lines = Input::GetMap(cities, map->x, map->y);

//     // for (int i = 0; i < map->y; i++) {
//     //     std::cout << map->lines[i] << std::endl;
//     // }
//     citiesArr = new City *[cities->length + 1];

//     Input::ExtractNames(map, cities, citiesMap, citiesArr);

//     int flights;
//     std::cin >> flights;

//     char name1[25], name2[25];
//     Input::GetFlight(flights, name1, name2, citiesMap);

//     pathfinder->FindEdges(map, cities);
//     int *dist = new int[cities->length + 1];
//     bool *visited = new bool[cities->length + 1];
//     int *parent = new int[cities->length + 1];
//     for (int i = 0; i < cities->length + 1; i++) {
//         dist[i] = std::numeric_limits<int>::max();
//         visited[i] = false;
//         parent[i] = -1;
//     }

//     int q;
//     char *src = new char[20];
//     char *dest = new char[20];
//     int type;
//     scanf("%d", &q);
//     while (q > 0) {
//         scanf("%s %s %d", src, dest, &type);
//         if (strcmp(src, dest) == 0) {
//             std::cout << "0" << std::endl;
//             q--;
//             continue;
//         }
//         pathfinder->FindPath(citiesArr, citiesMap.find(src), citiesMap.find(dest), type,
//                              cities->length + 1, dist, visited, parent);
//         q--;
//     }
//     delete[] src;
//     delete[] dest;

// #ifdef DEBUG
//     // Helpers::DUMP_CITY(cities->head->city);
//     Helpers::DUMP_LIST(cities);
// #endif

//     ListNode<City> *temp = cities->head;
//     while (temp != NULL) {
//     delete temp->data;
//         temp = temp->next;
//     }
//     delete[] citiesArr;
//     delete cities;
//     delete map;
//     delete pathfinder;
//     delete[] dist;
//     delete[] visited;
//     delete[] parent;
// //     // char *name = "1";
// //     // char *name2 = "2";
// //     // char *name3 = "3";
// //     // char *name4 = "4";
// //     // City *city = new City(name, {0, 0});
// //     // City *city2 = new City(name2, {0, 0});
// //     // City *city3 = new City(name3, {0, 0});
// //     // City *city4 = new City(name4, {0, 0});
// //     // city->AddConnection(city2, 2);
// //     // city->AddConnection(city3, 3);
// //     // city->AddConnection(city4, 4);
// //     // city2->AddConnection(city, 4);
// //     // #ifdef DEBUG
// //     // Helpers::DUMP_GRAPH(city);
// //     // #endif
    return 0;
}