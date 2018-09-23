#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE

  Eigen::MatrixXi E = edges(F);
  int mod_V = 1 + F.maxCoeff();
  // Assuming all indices are referenced

  Chi = mod_V - E.rows() + F.rows();

  return Chi;
}