#include "euler_characteristic.h"
#include "edges.h"
#include <set>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;

  // Obtain |V|.
  std::set<int> V;
  for (size_t i = 0, nRows = F.rows(); i < nRows; ++i)
  {
    V.insert(F(i, 0));
    V.insert(F(i, 1));
    V.insert(F(i, 2));
  }
  int v_size = V.size();

  // Obtain |E|.
  Eigen::MatrixXi E = edges(F);
  int e_size = E.rows();

  // Obtain |F|.
  int f_size = F.rows();

  // Chi = |V| - |E| + |F|.
  Chi = v_size - e_size + f_size;

  return Chi;
}
