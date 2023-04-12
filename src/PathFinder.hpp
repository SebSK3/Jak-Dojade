#include "LinkedList.hpp"
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Structures.hpp"
#include <limits>

class PathFinder {
  public:
    void FindEdges(Map *map, LinkedList<City *> *cities);
    static void FindPath(City **cities, City *src, City *dest, bool type,
                         int *dist, bool *visited, int *parent);

  private:
    int **createRoad(Map *map);
    static void EdgesBFS(Map *map, City *city, int **road,
                         LinkedList<City *> *cities);
};