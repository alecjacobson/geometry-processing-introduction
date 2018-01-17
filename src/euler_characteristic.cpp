#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);
  int Vcount = F.maxCoeff() + 1;
  int Ecount = E.rows();
  int Fcount = F.rows();
  Chi = Vcount - Ecount + Fcount;
  return Chi;
}
