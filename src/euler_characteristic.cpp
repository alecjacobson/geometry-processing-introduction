#include "euler_characteristic.h"
#include "edges.h"
#include <igl/unique.h>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE

  Eigen::MatrixXi V, E;
  E = edges(F);
  igl::unique(F,V);
  Chi = V.cols() - E.cols() + F.cols();
  return Chi;
}