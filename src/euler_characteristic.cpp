#include "edges.h"
#include "euler_characteristic.h"
#include <vector>
#include <algorithm>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  // Chi = |V| - |E| + |F|
  int Chi, v1, v2;
  Eigen::MatrixXi E = edges(F);
  
  // Find |V|
  std::vector<int> vertices;
  for (int i = 0; i < E.rows(); i = i + 1) {
    v1 = E(i,0);
    if (std::find(vertices.begin(), vertices.end(), v1) == vertices.end() ) {
      vertices.push_back(v1);
    }
    
    v2 = E(i,1);
    if (std::find(vertices.begin(), vertices.end(), v2) == vertices.end() ) {
      vertices.push_back(v1);
    }
  }
  
  Chi = vertices.size() - E.rows() + F.rows();

  return Chi;
}
