#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int f_count = F.rows();
  int v_count = F.maxCoeff() + 1;
  int e_count = edges(F).rows();
  
  return v_count - e_count + f_count;
}
