#include "edges.h"
#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E;
  E = edges(F);
  Chi = (F.maxCoeff() + 1) - E.rows() + F.rows();
  return Chi;
}
