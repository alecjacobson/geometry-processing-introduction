#include "euler_characteristic.h"
#include "edges.h"
#include <set>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;

  // ADD YOUR CODE HERE

  std::set<int> V;
  Eigen::MatrixXi E = edges(F);

  for(int i=0; i<F.rows(); ++i)
  {
	  V.insert(F(i, 0));
	  V.insert(F(i, 1));
	  V.insert(F(i, 2));
  }

  Chi = V.size() - E.rows() + F.rows();

  return Chi;
}
