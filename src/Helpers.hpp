#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <string.h>
#include <queue>
#include <iostream>

namespace Helpers {
bool InsideMap(Map *map, Position coords);
bool IsCharacter(char c);
City *FindCityByPos(LinkedList *cities, Position pos);
char *BuildCityName(Map *map, Position coords);
unsigned int CITY_ID(bool firstUsed = false, bool shouldIncrement=true);
#ifdef DEBUG
void DUMP_CITY(City *city);
void DUMP_GRAPH(City *city);
void DUMP_LIST(LinkedList *list);
void DUMP_ROAD(Map *map, int **road);
#endif
} // namespace Helpers