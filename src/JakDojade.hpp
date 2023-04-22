#include "City.hpp"
#include "Hashmap.hpp"
#include "Helpers.hpp"
#include "Input.hpp"
#include "PathFinder.hpp"
#include <iostream>

class JakDojade {
    public:
    ~JakDojade();
    void Start();

  private:
    void GetMap();
    void GetFlights();
    void GetEdges();
    void GetPath();
    Map *map;
    LinkedList<City *> *cities;
    City **citiesArr;
    Hashmap citiesMap;
    PathFinder *pathfinder;
};