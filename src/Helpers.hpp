#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <string.h>

namespace Helpers {
bool InsideMap(const Map &map, Position coords);
bool isNotWeirdAsciiChar(char c);
bool IsCharacter(char c);
City *FindCityByPos(LinkedList<City *> *cities, Position pos);
char *BuildCityName(const Map &map, Position coords);
unsigned int CITY_ID(bool firstUsed = false, bool shouldIncrement = true);

} // namespace Helpers