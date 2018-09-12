#include <edges.h>
#include "euler_characteristic.h"
#include <set>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);

  // Calculate V
  std::set<int> vertices;
  for (int i = 0; i < F.rows(); i++) {
    vertices.insert(F(i, 0));
    vertices.insert(F(i, 1));
    vertices.insert(F(i, 2));
  }

  Chi = (int) (vertices.size() - E.rows() + F.rows());
  return Chi;
}
