#include "edges.h"

#include <set>
#include <vector>
#include <algorithm>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  
  std::set<std::pair<int, int>> edge_set;
  for(int i = 0; i < F.rows(); i++) {
    for(int j = 0; j < F.cols(); j++) {
        int v1 = F(i, j);
        int v2 = F(i, (j + 1) % F.cols());

        if(v1 > v2) std::swap(v1, v2);

        edge_set.insert(std::make_pair(v1, v2));
    }
  }

  E = Eigen::MatrixXi(edge_set.size(), 2);
  int i = 0;
  for(auto edge : edge_set) {
    E.row(i++) = Eigen::Vector2i(edge.first, edge.second);
  }

  return E;
}
