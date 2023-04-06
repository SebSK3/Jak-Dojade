#include "Input.hpp"


char** Input::GetMap(LinkedList *list, int x, int y) {
    char **map = new char*[y+2];
    map[y+1] = NULL;
    for (int i=0; i<y; i++) {
        char *line = new char[x+1];
        char c;
        for (int j=0; j<x; j++) {
            std::cin >> c;
            line[j] = c;
            if (c == '*') {
                list->append(new City(NULL, {i, j}));
            }
        }
        line[x] = '\0';
        map[i] = line;
    }
    #ifndef NDEBUG
    std::cout << "LOADED MAP" << std::endl;
    #endif
    return map;
}