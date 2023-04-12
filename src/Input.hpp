#pragma once
#include "City.hpp"
#include "Hashmap.hpp"
#include "LinkedList.hpp"
#include <iostream>

namespace Input {
char **GetMap(LinkedList<City *> *list, int x, int y);
void GetFlight(int flights, char *name1, char *name2, Hashmap &cities);
void ExtractNames(Map *map, LinkedList<City *> *cities, Hashmap &citiesMap,
                  City **citiesArr);
} // namespace Input