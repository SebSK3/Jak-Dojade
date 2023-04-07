#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <iostream>

namespace Input {
char **GetMap(LinkedList *list, int x, int y);
void GetFlight(LinkedList *list);
int GetFlightWeight(char c);
void ExtractNames(Map *map, LinkedList *cities);
} // namespace Input