#include "edges.h"
#include <utility>
#include <set>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;

  // Use std::set to avoid duplicates.
  // Note: E should contain every undirected edge exactly once.
  std::set<std::pair<int, int>> edge_set;
  for (size_t i = 0, nRows = F.rows(); i < nRows; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::pair<int, int> current_pair;
      // Place larger index at the end to identify undirected edges.
        if (F(i, j) >= F(i, (j + 1) % 3)) {
        current_pair = std::make_pair(F(i, j), F(i, (j + 1) % 3));
      } else {
        current_pair = std::make_pair(F(i, (j + 1) % 3), F(i, j));
      }
      edge_set.insert(current_pair);
    }
  }

  // Push all elements to E.
  E.resize(edge_set.size(), 2);
  std::set<std::pair<int, int>>::iterator it;
  int idx = 0;
  for (it = edge_set.begin(); it != edge_set.end(); ++it)
  {
    E(idx, 0) = (*it).first;
    E(idx, 1) = (*it).second;
    idx++;
  }

  return E;
}
