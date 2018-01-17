#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);
  // F contains indicies into V, and no vertex is unreferenced
  int V_size = F.maxCoeff() + 1;
  Chi = V_size - E.rows() + F.rows();
  return Chi;
}
