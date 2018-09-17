#include "euler_characteristic.h"
#include "edges.h"

//Chi = |V| - |E| + |F|
int euler_characteristic(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E = edges(F);
  int edgeCount = E.rows();
  int faceCount = F.rows();
  int vertexCount = E.maxCoeff() + 1; //+1 because vertex indices start at 0
  int Chi = vertexCount - edgeCount + faceCount;
  return Chi;
}
