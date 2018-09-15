#include "edges.h"
#include <vector>

using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  vector<vector<int>> edges;
  for (int i = 0; i < F.rows(); i++) {
    for (int j = 0; j < 3; j++) {
      vector<int> edge1, edge2;
      edge1 = {F(i, j), F(i, (j + 1) % 3)};
      edge2 = {F(i, (j + 1) % 3), F(i, j)};
      bool check_edge1, check_edge2;
      check_edge1 = find(edges.begin(), edges.end(), edge1) == edges.end();
      check_edge2 = find(edges.begin(), edges.end(), edge2) == edges.end();
      if (check_edge1 && check_edge2) {
        edges.push_back(edge1);
      }
    }
  }
  E.resize(edges.size(), 2);
  for (int i = 0; i < E.rows(); i++) {
    E(i, 0) = edges[i][0];
    E(i, 1) = edges[i][1];
  }
  return E;
}
