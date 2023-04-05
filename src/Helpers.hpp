#pragma once
#include "City.hpp"
#include <iostream>

namespace Helpers {
unsigned int CITY_ID(bool firstUsed);

#ifndef NDEBUG
void DUMP_CITY(City *city);
#endif
} // namespace Helpers