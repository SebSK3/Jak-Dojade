#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "LinkedList.hpp"
#include "Structures.hpp"
#include <cassert>

const int MAXINT = 214748364;

class PathFinder {
  public:
    void FindEdges(Map *map, LinkedList *cities);
    void FindPath(City **cities, City *src, City *dest, bool type, int citiesLength);

  private:
    int **createRoad(Map *map);
    void EdgesBFS(Map *map, City *city, int **road, LinkedList *cities);
};