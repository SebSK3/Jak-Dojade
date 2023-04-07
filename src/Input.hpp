#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <unordered_map>

namespace Input {
char **GetMap(LinkedList *list, int x, int y);
void GetFlight(char *name1, char *name2, std::unordered_map<std::string, City*>& cities);
int GetFlightWeight(char c);
void ExtractNames(Map *map, LinkedList *cities, std::unordered_map<std::string, City*>& cities2, City **citiesArr, std::unordered_map<Position, City*>& citiesByPosition);
} // namespace Input