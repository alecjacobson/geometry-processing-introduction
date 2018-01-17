#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  int E = F.rows() * 3.0 / 2.0;
  int V = F.maxCoeff() + 1;
  int FNum = F.rows();
  Chi = V - E + FNum;
  return Chi;
}
