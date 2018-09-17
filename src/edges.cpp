#include "edges.h"
#include <utility>
#include <set>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  int v1;
  int v2;
  int faceCount = F.rows();
  std::set<std::pair<int,int>> uniqueEdges;

  for (int f = 0; f < faceCount; f++ ) {
    for (int v = 0; v < 3; v++ ) {
      v1 = F(f, v);
      v2 = F(f, (v + 1) % 3); // wraparound

      //ensure a consistent order of the vertices so that there's only one representation for an edge
      if (v1 > v2) {
        std::swap(v1, v2);
      }

      //add edge to set (will be rejected automatically if not unique)
      uniqueEdges.insert(std::make_pair(v1, v2));
    }
  }

  //copy contents of the set over to a matrix
  Eigen::MatrixXi E(uniqueEdges.size(),2);
  int i = 0;

  for (std::pair<int,int> edge : uniqueEdges) {
    E(i, 0) = edge.first;
    E(i, 1) = edge.second;
    i++;
  }

  return E;
}
