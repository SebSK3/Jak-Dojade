#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <unordered_map>

namespace Input {
char **GetMap(LinkedList *list, int x, int y);
void GetFlight(char *name1, char *name2, City **citiesArr, std::unordered_map<std::string, int>& cities);
int GetFlightWeight(char c);
void ExtractNames(Map *map, LinkedList *cities, std::unordered_map<std::string, int>& citiesMap, City **citiesArr);
} // namespace Input