#include "Input.hpp"

void Input::GetFlight(LinkedList *list) {
    char *name1 = new char[150];
    char *name2 = new char[150];
    int weight = 0;
    std::cin >> name1;
    std::cin >> name2;
    std::cin >> weight;
    ListNode *temp = list->head;

    City *src = NULL;
    City *dest = NULL;
    while (temp != NULL) {
        if (strcmp(temp->city->name, name1) == 0) {
            src = temp->city;
        }
        if (strcmp(temp->city->name, name2) == 0) {
            dest = temp->city;
        }
        temp = temp->next;
    }
    if (src == NULL || dest == NULL) {
        delete[] name1;
        delete[] name2;
        return;
    }
    ListNode *connection = src->Connection(dest);
    if (connection != NULL) {
        if (connection->weight > weight) {
            connection->weight = weight;
        }
        delete[] name1;
        delete[] name2;
        return;
    }
    src->AddConnection(dest, weight);

    delete[] name1;
    delete[] name2;
    // int i = 0;
    // int j = 0;
    // char *line = new char[50];
    // char **names = new char*[2];
    // while (true) {
    //     char c;
    //     std::cin >> c;
    //     if (c == ' ') {
    //         line[i] = '\0';
    //         names[j] = line;
    //         i = 0;
    //         j++;
    //         if (j == 2) {
    //         }
    //     }

    //     line[i] = c;
    //     i++;
    // }
}
char **Input::GetMap(LinkedList *list, int x, int y) {
    #ifdef DEBUG
    std::cout << "LOADED MAP" << std::endl;
#endif
    return NULL;
}

void Input::ExtractNames(Map *map, LinkedList *cities) {
    if (cities->head == NULL)
        return;
    ListNode *tempCity = cities->head;
    while (tempCity != NULL) {

        Position foundCoords;
        /* Loop just so we can break out of it */
        while (true) {
            if (Helpers::InsideMap(map, {tempCity->city->pos.x - 1,
                                         tempCity->city->pos.y - 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y - 1]
                                  [tempCity->city->pos.x - 1])) {
                    foundCoords = {tempCity->city->pos.x - 1,
                                   tempCity->city->pos.y - 1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x - 1, tempCity->city->pos.y})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y]
                                  [tempCity->city->pos.x - 1])) {
                    foundCoords = {tempCity->city->pos.x - 1,
                                   tempCity->city->pos.y};
                    break;
                }
            }
            if (Helpers::InsideMap(map, {tempCity->city->pos.x - 1,
                                         tempCity->city->pos.y + 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y + 1]
                                  [tempCity->city->pos.x - 1])) {
                    foundCoords = {tempCity->city->pos.x - 1,
                                   tempCity->city->pos.y + 1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x, tempCity->city->pos.y + 1})) {
                if (Helpers::IsCharacter(map->lines[tempCity->city->pos.y + 1]
                                                   [tempCity->city->pos.x])) {
                    foundCoords = {tempCity->city->pos.x,
                                   tempCity->city->pos.y + 1};
                    break;
                }
            }
            if (Helpers::InsideMap(map, {tempCity->city->pos.x + 1,
                                         tempCity->city->pos.y + 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y + 1]
                                  [tempCity->city->pos.x + 1])) {
                    foundCoords = {tempCity->city->pos.x + 1,
                                   tempCity->city->pos.y + 1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x + 1, tempCity->city->pos.y})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y]
                                  [tempCity->city->pos.x + 1])) {
                    foundCoords = {tempCity->city->pos.x + 1,
                                   tempCity->city->pos.y};
                    break;
                }
            }
            if (Helpers::InsideMap(map, {tempCity->city->pos.x + 1,
                                         tempCity->city->pos.y - 1})) {
                if (Helpers::IsCharacter(
                        map->lines[tempCity->city->pos.y - 1]
                                  [tempCity->city->pos.x + 1])) {
                    foundCoords = {tempCity->city->pos.x + 1,
                                   tempCity->city->pos.y - 1};
                    break;
                }
            }
            if (Helpers::InsideMap(
                    map, {tempCity->city->pos.x, tempCity->city->pos.y - 1})) {
                if (Helpers::IsCharacter(map->lines[tempCity->city->pos.y - 1]
                                                   [tempCity->city->pos.x])) {
                    foundCoords = {tempCity->city->pos.x - 1,
                                   tempCity->city->pos.y - 1};
                    break;
                }
            }
        }
        tempCity->city->name = Helpers::BuildCityName(map, foundCoords);
        tempCity = tempCity->next;
    }
}