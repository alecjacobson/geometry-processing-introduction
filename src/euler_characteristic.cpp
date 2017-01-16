#include "edges.h"
#include "euler_characteristic.h"
#include <set>
int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  typedef std::set<int> VertexSet;
  VertexSet vs;
  for ( int i = 0 ; i < F.rows() ; ++i ) {
    for ( int j = 0 ; j < 3 ; ++j ) {
      vs.insert(F(i, j));
    }
  }
  Eigen::MatrixXi E = edges(F);
  Chi = vs.size() - E.rows() + F.rows();
  return Chi;
}
