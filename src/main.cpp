#include "City.hpp"
#include "Helpers.hpp"
#include "Input.hpp"
#include "PathFinder.hpp"
#include "Hashmap.hpp"
#include <iostream>

int main() {
    /* Start the function to give every city unique ID */
    Helpers::CITY_ID(true); 

    Map *map = new Map;
    LinkedList<City*> *cities = new LinkedList<City*>;
    City **citiesArr;
    Hashmap citiesMap;

    int x, y;
    scanf("%d %d", &x, &y);
    getchar(); // Skip newline char
    map->x = x;
    map->y = y;

    map->lines = Input::GetMap(cities, map->x, map->y);
    citiesArr = new City *[cities->length + 1];
    Input::ExtractNames(map, cities, citiesMap, citiesArr);

    int flights;
    std::cin >> flights;


    /* According to Wikipedia, longest city name is 85 chars */
    char name1[86], name2[86];
    Input::GetFlight(flights, name1, name2, citiesMap);


    PathFinder *pathfinder = new PathFinder;
    pathfinder->FindEdges(map, cities);
    
    /* Allocate once, later in use for dijkstra */
    int *dist = new int[cities->length + 1];
    bool *visited = new bool[cities->length + 1];
    int *parent = new int[cities->length + 1];
    for (int i = 0; i < cities->length + 1; i++) {
        dist[i] = std::numeric_limits<int>::max();
        visited[i] = false;
        parent[i] = -1;
    }

    int q;
    /* According to Wikipedia, longest city name is 85 chars */
    char *src = new char[86];
    char *dest = new char[86];
    int type;
    scanf("%d", &q);
    while (q > 0) {
        scanf("%s %s %d", src, dest, &type);
        if (strcmp(src, dest) == 0) {
            std::cout << "0" << std::endl;
            q--;
            continue;
        }
        pathfinder->FindPath(citiesArr, citiesMap.find(src), citiesMap.find(dest), type,
                            dist, visited, parent);
        q--;
    }
    delete[] src;
    delete[] dest;

    ListNode<City*> *temp = cities->head;
    while (temp != NULL) {
    delete temp->data;
        temp = temp->next;
    }
    delete[] citiesArr;
    delete cities;
    delete map;
    delete pathfinder;
    delete[] dist;
    delete[] visited;
    delete[] parent;

    return 0;
}