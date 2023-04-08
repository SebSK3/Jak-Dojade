#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include "LinkedList.hpp"
#include "Structures.hpp"
#include <cassert>
#include <limits>


class PathFinder {
  public:
    void FindEdges(Map *map, LinkedList *cities);
    void FindPath(City **cities, int srcID, int destID, bool type, int citiesLength, std::vector<int> &dist, std::vector<bool> &visited, std::vector<int> &parent);

  private:
    int **createRoad(Map *map);
    void EdgesBFS(Map *map, City *city, int **road, LinkedList *cities);
};