#include "euler_characteristic.h"
#include "edges.h"
int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi=0;
  // ADD YOUR CODE HERE
  auto E = edges(F);
  int iVertexNum = F.maxCoeff() + 1;
  int iEdgeNum = E.rows();
  int iFaceNum = F.rows();
  Chi = iVertexNum - iEdgeNum + iFaceNum;
  return Chi;
}
