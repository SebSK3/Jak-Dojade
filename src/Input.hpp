#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <iostream>

namespace Input {
char **GetMap(LinkedList *list, int x, int y);
void ExtractNames(Map *map, LinkedList *cities);
} // namespace Input