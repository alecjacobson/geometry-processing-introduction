#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;

  Eigen::MatrixXi E = edges(F);
  int n_V = F.maxCoeff() + 1;
  int n_E = E.rows();
  int n_F = F.rows();

  Chi = n_V - n_E + n_F;

  return Chi;
}
