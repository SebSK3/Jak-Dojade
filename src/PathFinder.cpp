#include "PathFinder.hpp"
#include "City.hpp"

void PathFinder::FindEdges(Map *map, LinkedList *cities) {
    int **road = createRoad(map);
    ListNode *tempNode = cities->head;
    while (tempNode != NULL) {
        PathFinder::EdgesBFS(map, tempNode->city, road, cities);
        tempNode = tempNode->next;
    }

    for (int i = 0; i < map->y; i++) {
        delete[] road[i];
    }
    delete[] road;
}

void PathFinder::FindPath(City **cities, City *src, City *dest,
                          bool type, int citiesLength) {

    std::vector<int> dist(citiesLength + 1, INT_MAX);
    std::vector<bool> visited(citiesLength + 1, false);
    std::vector<int> parent(citiesLength + 1, -1);
    std::vector<City *> path;
    
    dist[src->ID] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    pq.emplace(0, src->ID);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        if (cities[u]->edges == NULL) {
            continue;
        }
        ListNode *node = cities[u]->edges->head;
        
        while (node != NULL) {
            int v = node->city->ID;
            int weight = node->weight;
            int newDist = dist[u] + weight;
            if (!visited[v] && dist[u] != INT_MAX && newDist < dist[v]) {
                parent[v] = u;
                dist[v] = newDist;
                pq.emplace(dist[v], v);
            }
            node = node->next;
        }
    }
    std::cout << dist[dest->ID];
    if (type) {
        int curr = parent[dest->ID];
        while (curr != src->ID) {
            path.push_back(cities[curr]);
            curr = parent[curr];
        }
        std::reverse(path.begin(), path.end());
        std::cout << " ";
        for (City *city : path) {
            std::cout << city->name << " ";
        }
   }
    std::cout << std::endl;

}
void PathFinder::EdgesBFS(Map *map, City *city, int **road,
                          LinkedList *cities) {
    std::queue<Position> q;
    std::queue<Position> visited;
    q.push(city->pos);
    visited.push(city->pos);
#ifdef DEBUG
    for (int i = 0; i < map->y; i++) {
        for (int j = 0; j < map->x; j++) {
            assert(road[i][j] == -1);
        }
    }
#endif
    road[city->pos.y][city->pos.x] = 0;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if ((dr == 0 && dc == 0) || (dr != 0 && dc != 0)) {
                    continue;
                }
                int column = current.x + dc;
                int row = current.y + dr;
                if (!Helpers::InsideMap(map, {column, row}) ||
                    (map->lines[row][column] != '#' &&
                     map->lines[row][column] != '*') ||
                    road[row][column] >= 0) {
                    continue;
                }
                road[row][column] = road[current.y][current.x] + 1;
                visited.push({column, row});
                // #ifdef DEBUG
                // Helpers::DUMP_ROAD(map, road);
                // #endif
                if (map->lines[row][column] == '*') {
                    city->AddConnection(
                        Helpers::FindCityByPos(cities, {column, row}),
                        road[row][column]);
                } else {
                    q.push({column, row});
                }
            }
        }
    }
    while (!visited.empty()) {
        road[visited.front().y][visited.front().x] = -1;
        visited.pop();
    }
}

int **PathFinder::createRoad(Map *map) {
    int **road = new int *[map->y];
    for (int i = 0; i < map->y; i++) {
        road[i] = new int[map->x];
    }
    for (int i = 0; i < map->y; i++) {
        for (int j = 0; j < map->x; j++) {
            road[i][j] = -1;
        }
    }
    return road;
}