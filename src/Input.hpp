#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include "Hashmap.hpp"

namespace Input {
char **GetMap(LinkedList<City> *list, int x, int y);
void GetFlight(int flights, char *name1, char *name2, Hashmap &cities);
int GetFlightWeight(char c);
void ExtractNames(Map *map, LinkedList<City> *cities, Hashmap &citiesMap, City **citiesArr);
} // namespace Input