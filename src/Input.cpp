#include "Input.hpp"

char** Input::GetMap(int x, int y) {
    char **map = new char*[y+2];
    map[y+1] = NULL;
    for (int i=0; i<y; i++) {
        char *line = new char[x+1];
        std::cin >> line;
        map[i] = line;
    }
    #ifndef NDEBUG
    std::cout << "LOADED MAP" << std::endl;
    #endif
    return map;
}