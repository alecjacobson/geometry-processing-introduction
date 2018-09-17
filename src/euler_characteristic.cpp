#include "euler_characteristic.h"
#include "edges.h"
#include <set>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);
  // Get the unique vertices from E
  std::set<int> V;
  for (int i = 0; i < E.rows(); i++) {
	  V.insert(E(i, 0));
	  V.insert(E(i, 1));
  }
  Chi = V.size() - E.rows() + F.rows();
  return Chi;
}
