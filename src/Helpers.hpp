#pragma once
#include "City.hpp"
#include "LinkedList.hpp"
#include <queue>
#include <iostream>

namespace Helpers {
unsigned int CITY_ID(bool firstUsed = false, bool shouldIncrement=true);

#ifndef NDEBUG
void DUMP_CITY(City *city);
void DUMP_GRAPH(City *city);
void DUMP_LIST(LinkedList *list);
#endif
} // namespace Helpers