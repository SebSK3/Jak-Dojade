#include "PathFinder.hpp"
#include "City.hpp"

void PathFinder::FindEdges(Map *map, LinkedList<City*> *cities) {
    int **road = createRoad(map);
    ListNode<City*> *tempNode = cities->head;
    while (tempNode != NULL) {
        PathFinder::EdgesBFS(map, tempNode->data, road, cities);
        tempNode = tempNode->next;
    }

    for (int i = 0; i < map->y; i++) {
        delete[] road[i];
    }
    delete[] road;
}

void PathFinder::FindPath(City **cities, City *src, City *dest, bool type,
                          int *dist, bool *visited, int *parent) {

    Stack<int> changedIndices;
    Stack<City *> path;

    dist[src->ID] = 0;
    changedIndices.push(src->ID);

    PriorityQueue queue;
    queue.insert(0, src->ID);

    while (!queue.empty()) {
        unsigned int currNodeID = queue.getMin();
        queue.pop();
        if (visited[currNodeID]) {
            continue;
        }
        visited[currNodeID] = true;
        changedIndices.push(currNodeID);

        if (currNodeID == dest->ID) {
            break;
        }

        if (cities[currNodeID]->edges.length == 0) {
            continue;
        }
        ListNode<City*> *node = cities[currNodeID]->edges.head;

        while (node != NULL) {
            int neighborID = node->data->ID;
            int weight = node->weight;
            int newDist = dist[currNodeID] + weight;
            if (!visited[neighborID] && newDist < dist[neighborID]) {
                parent[neighborID] = currNodeID;
                dist[neighborID] = newDist;
                queue.insert(dist[neighborID], neighborID);
                changedIndices.push(neighborID);
            }
            node = node->next;
        }
    }
    printf("%d", dist[dest->ID]);
    if (type) {
        unsigned int curr = parent[dest->ID];
        while (curr != src->ID) {
            path.push(cities[curr]);
            curr = parent[curr];
        }
        printf(" ");
        while (!path.empty()) {
            printf("%s ", path.top()->name);
            path.pop();
        }
    }
    putchar('\n');
    while (!changedIndices.empty()) {
        int i = changedIndices.top();
        changedIndices.pop();
        dist[i] = std::numeric_limits<int>::max();
        visited[i] = false;
        parent[i] = -1;
    }
}
void PathFinder::EdgesBFS(Map *map, City *city, int **road,
                          LinkedList<City*> *cities) {
    Queue<Position> q;
    Queue<Position> visited;
    q.push(city->pos);
    visited.push(city->pos);
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
                    // city->AddConnection(
                    //     citiesByPosition.find({column, row})->second,
                    //     road[row][column]);
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