#include <iostream>

#include "Helpers.hpp"
#include "City.hpp"

int main() {
    char *name = "abcdef";
    City *city = new City(name, {0, 0});
    city->AddConnection(city, 5);
    #ifndef NDEBUG
    Helpers::DUMP_CITY(city);
    #endif
    return 0;
}