#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "LinkedList.hpp"
#include "Structures.hpp"
#include <cassert>
#include <limits>


class PathFinder {
  public:
    void FindEdges(Map *map, LinkedList *cities, std::unordered_map<Position, City*>& citiesByPosition);
    void FindPath(City **cities, City *src, City *dest, bool type, int citiesLength, std::vector<int> &dist, std::vector<bool> &visited, std::vector<int> &parent);

  private:
    int **createRoad(Map *map);
    void EdgesBFS(Map *map, City *city, int **road, LinkedList *cities, std::unordered_map<Position,
     City*>& citiesByPosition);
};