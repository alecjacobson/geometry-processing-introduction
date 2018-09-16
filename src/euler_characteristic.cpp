#include "euler_characteristic.h"
#include "igl/unique.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);
  Eigen::MatrixXi V;
  igl::unique(F, V);

  Chi = V.rows() - E.rows() + F.rows();
  return Chi;
}
