#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  typedef Eigen::Array<bool,Eigen::Dynamic,Eigen::Dynamic> ArrayXb;
  int num_vertices = F.maxCoeff() + 1;
  ArrayXb flags = ArrayXb::Constant(num_vertices, num_vertices, false);

  E = Eigen::MatrixXi(F.rows()*3,2);  // F.rows()*3 upperbound

  int num_edges = 0;

  // for each triangle
  for (int i = 0; i < F.rows(); ++i) {
    // for each side of triangle
    for (int ii = 0; ii < 3; ++ii) {
      const int& v1 = F(i, ii);
      const int& v2 = F(i, (ii+1)%3);

      if (!flags(v1,v2) && !flags(v2,v1)) {
        // new edge
        E(num_edges,0) = v1;
        E(num_edges,1) = v2;
        
        // set flag
        flags(v1,v2) = true;
        flags(v2,v1) = true;

         ++num_edges;
      }

    } // end loop ii
  } // end loop i

  E.conservativeResize(num_edges,2);

  return E;
}
