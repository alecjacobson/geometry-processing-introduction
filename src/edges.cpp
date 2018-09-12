#include "edges.h"
#include <vector>
using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  
  int num_faces = F.rows();
  int num_vertices = F.maxCoeff() + 1;
  
  vector<int> adj[num_vertices];
  vector<int> edge_list;
  
  for (int i = 0; i < num_faces; i++) {
    for (int j = 0; j < 3; j++) {
      int v1 = F(i, j);
      int v2 = F(i, (j+1) % 3);
      if (find(adj[v1].begin(), adj[v1].end(), v2) == adj[v1].end()) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        edge_list.push_back(v1);
        edge_list.push_back(v2);
      }
    }
  }
  
  E.resize(edge_list.size() / 2, 2);
  for (int i = 0; i < edge_list.size(); i++) {
    E(i / 2, i % 2) = edge_list[i];
  }
  
  return E;
}
