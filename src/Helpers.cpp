#include "Helpers.hpp"

bool Helpers::IsCharacter(char c) {
    if (isalnum(c))
        return true;
    return false;
}

City *Helpers::FindCityByPos(LinkedList<City> *cities, Position pos) {
    ListNode<City> *temp = cities->head;
    while (temp != NULL) {
        if (temp->data->pos == pos) {
            return temp->data;
        }
        temp = temp->next;
    }
    return NULL;
}

bool Helpers::InsideMap(Map *map, Position coords) {
    if (map->x - 1 < coords.x)
        return false;
    if (coords.x < 0) {
        return false;
    }
    if (map->y - 1 < coords.y) {
        return false;
    }
    if (coords.y < 0) {
        return false;
    }
    return true;
}

char *Helpers::BuildCityName(Map *map, Position coords) {
    int i = coords.x;

    int nameLength = 1;
    while (InsideMap(map, {i, coords.y}) && IsCharacter(map->lines[coords.y][i])) {
        i--;
        nameLength++;
    }
    nameLength--;
    int j = coords.x;
    while (InsideMap(map, {j, coords.y}) && IsCharacter(map->lines[coords.y][j])) {
        j++;
        nameLength++;
    }
    nameLength--;
    i++;
    char *name = new char[nameLength+1];
    name[nameLength] = '\0';
    for (int k=0; k<nameLength; k++) {
        name[k] = map->lines[coords.y][i+k];
    }
    return name;
}

unsigned int Helpers::CITY_ID(bool firstUsed, bool shouldIncrement) {
    static unsigned int id;
    if (firstUsed) {
        id = 0;
        return id;
    }
    if (shouldIncrement)
        id++;
    return id;
}

#ifdef DEBUG
void Helpers::DUMP_CITY(City *city) {
    char *empty = new char[6];
    strcpy(empty, "EMPTY");
    char *name;
    if (city->name != NULL) {
        name = city->name;
        delete[] empty;
    } else {
        name = empty;
    }

    std::cout << "City " << name << "(ID:" << city->ID
              << ") dumped:" << std::endl;
    ListNode *tempList = NULL;
    if (city->edges != NULL)
        tempList = city->edges->head;
    while (tempList != NULL) {
        std::cout << "Connected: " << tempList->city->name
                  << " (ID:" << tempList->city->ID
                  << "), with weight: " << tempList->weight << std::endl;
        tempList = tempList->next;
    }
}
void Helpers::DUMP_GRAPH(City *city) {
    int count = CITY_ID(false, false);
    bool *visited = new bool[count];
    std::queue<City *> queue;
    for (int i = 0; i < count; i++) {
        visited[i] = false;
    }
    queue.push(city);
    visited[city->ID] = true;
    while (!queue.empty()) {
        City *v = queue.front();
        queue.pop();
        DUMP_CITY(v);
        ListNode *iter = v->edges->head;
        while (iter != NULL) {
            City *u = iter->city;
            if (!visited[u->ID]) {
                visited[u->ID] = true;
                queue.push(u);
            }
            iter = iter->next;
        }
    }
    delete[] visited;
}
void Helpers::DUMP_LIST(LinkedList<City> *list) {
    ListNode *iter = list->head;
    while (iter != NULL) {
        City *u = iter->city;
        DUMP_CITY(u);
        iter = iter->next;
    }
}

void Helpers::DUMP_ROAD(Map *map, int **road) {
    for (int i=0; i<map->y; i++) {
        for (int j=0; j<map->x; j++) {
            std::cout << road[i][j] << "  ";
        }

        std::cout << std::endl;
    }
        std::cout << std::endl;
        std::cout << std::endl;
}
#endif