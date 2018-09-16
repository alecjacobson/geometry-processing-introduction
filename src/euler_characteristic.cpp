#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);
  int V_size = F.maxCoeff() + 1;
  int E_size = E.rows();
  int F_size = F.rows();
  Chi = V_size - E_size + F_size;

  return Chi;
}
