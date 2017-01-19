#include "euler_characteristic.h"
#include "edges.h"
#include <set>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE

  //use set again for uniqueness
  std::set<int> vertex;
  Eigen::MatrixXi E = edges(F);

  for (int i = 0; i < E.rows(); ++i){  
        vertex.insert( E(i,0) );
        vertex.insert( E(i,1) );
  }

  Chi = vertex.size() - E.rows() + F.rows();
  return Chi;
}
