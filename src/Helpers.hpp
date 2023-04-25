#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <string.h>

namespace Helpers {
bool InsideMap(const Map &map, Position coords);
bool IsCharacter(char c);
bool isNotWeirdAsciiChar(char c);
City *FindCityByPos(LinkedList<City *> *cities, Position pos);
char *BuildCityName(Map *map, Position coords);
unsigned int CITY_ID(bool firstUsed = false, bool shouldIncrement = true);
#ifdef DEBUG
void DUMP_CITY(City *city);
void DUMP_GRAPH(City *city);
void DUMP_ROAD(Map *map, int **road);
#endif
} // namespace Helpers