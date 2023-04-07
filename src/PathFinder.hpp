#include <queue>
#include "LinkedList.hpp"
#include "Structures.hpp"
#include <cassert>

class PathFinder {
  public:
    void FindEdges(Map *map, LinkedList *cities);

  private:
    int **createRoad(Map *map);
    void EdgesBFS(Map *map, City *city, int **road, LinkedList *cities);
};