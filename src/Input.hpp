#pragma once
#include "City.hpp"
#include "Hashmap.hpp"
#include "LinkedList.hpp"

namespace Input {
char **GetMap(LinkedList<City *> *list, const int &x, const int &y);
void GetFlights(char *name1, char *name2, Hashmap *cities);
void ExtractNames(const Map &map, LinkedList<City *> *cities, Hashmap *citiesMap,
                  City **citiesArr);
} // namespace Input