#include <queue>
#include <vector>
#include "LinkedList.hpp"
#include "Structures.hpp"
#include <cassert>

class PathFinder {
  public:
    void FindEdges(Map *map, LinkedList *cities);
    void FindPath(LinkedList *cities, City *src, City *dest, bool type);

  private:
    int **createRoad(Map *map);
    void EdgesBFS(Map *map, City *city, int **road, LinkedList *cities);
};