#pragma once

#include "Helpers.hpp"
#include "LinkedList.hpp"

class City {
  public:
    City(char *name, Position position);
    ~City();
    void AddConnection(City *city, int weight);

    LinkedList<City *> edges;
    char *name;
    unsigned int ID = 0;
    Position pos;

  private:
};