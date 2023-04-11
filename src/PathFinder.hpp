#include <queue>
#include <vector>
#include "LinkedList.hpp"
#include "Structures.hpp"
#include <cassert>
#include <limits>
#include "Stack.hpp"


class PathFinder {
  public:
    void FindEdges(Map *map, LinkedList<City> *cities);
    void FindPath(City **cities, City *src, City *dest, bool type, int citiesLength, int *dist, bool *visited, int *parent);

  private:
    int **createRoad(Map *map);
    void EdgesBFS(Map *map, City *city, int **road, LinkedList<City> *cities);
};