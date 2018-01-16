#include "euler_characteristic.h"
#include "edges.h"
int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE

  int v = F.maxCoeff() + 1;
  Eigen::MatrixXi E = edges(F);
  int e = E.rows();
  int f = F.rows();
  Chi = v - e + f;

  return Chi;
}
