#include "JakDojade.hpp"
JakDojade::~JakDojade() {

    ListNode<City *> *temp = cities->head;
    while (temp != nullptr) {
        delete temp->data;
        temp = temp->next;
    }
    delete[] citiesArr;
    delete cities;
    delete map;
    delete pathfinder;
}
void JakDojade::Start() {
    /* Start the function to give every city unique ID */
    Helpers::CITY_ID(true);

    GetMap();
    GetFlights();
    GetEdges();
    GetPath();
}

void JakDojade::GetMap() {
    map = new Map;
    cities = new LinkedList<City *>;
    int x, y;
    scanf("%d %d", &x, &y);
    getchar(); // Skip newline char
    map->x = x;
    map->y = y;
    map->lines = Input::GetMap(cities, map->x, map->y);
#ifdef DEBUG
    std::cout << std::endl;
    std::cout << std::endl;
    for (int i=0; i<map->y; i++) {
        for (int j=0; j<map->x; j++) {
            std::cout << map->lines[i][j];
        }
        std::cout << std::endl;
    }
#endif
    citiesArr = new City *[cities->length + 1];
    Input::ExtractNames(*map, cities, &citiesMap, citiesArr);

}

void JakDojade::GetFlights() {
    /* According to Wikipedia, longest city name is 85 chars */
    char name1[86], name2[86];
    Input::GetFlights(name1, name2, &citiesMap);
}

void JakDojade::GetEdges() {
    pathfinder = new PathFinder;
    pathfinder->FindEdges(map, cities);
}

void JakDojade::GetPath() {
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
    /* According to Wikipedia, longest city name in the world is 85 chars,
     * so there's some room if wikipedia is wrong */
    char *src = new char[100];
    char *dest = new char[100];
    int type;
    scanf("%d", &q);
    while (q > 0) {
        scanf("%s %s %d", src, dest, &type);
        if (strcmp(src, dest) == 0) {
            std::cout << "0" << std::endl;
            q--;
            continue;
        }
        pathfinder->FindPath(citiesArr, *citiesMap.find(src),
                             *citiesMap.find(dest), type, dist, visited,
                             parent);
        q--;
    }
    delete[] src;
    delete[] dest;
    delete[] dist;
    delete[] visited;
    delete[] parent;
}