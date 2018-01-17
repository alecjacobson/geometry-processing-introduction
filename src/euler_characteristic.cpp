#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  int E = edges(F).rows();
  int V = F.maxCoeff() + 1;
  int FNum = F.rows();
  Chi = V - E + FNum;
  return Chi;
}
