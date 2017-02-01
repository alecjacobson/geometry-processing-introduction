#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  Eigen::MatrixXi E = edges(F);
  Chi = (F.maxCoeff() + 1) - E.rows() + F.rows(); //Assuming all vertices are used to form triangles, then maxCoeff + 1 is number of vertices (zero indexing)
  return Chi;
}
