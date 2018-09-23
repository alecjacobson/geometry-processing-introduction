#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  int rows = 0;
  int v1 = -1;
  int v2 = -1;

  // Loop over faces
  for(int i=0; i<F.rows(); i++){
    for(int j=0; j<F.cols(); j++){
      v1 = F(i,j); 
      v2 = F(i, (j+1)%F.cols());
      
      if(v1 < v2){
        // Arbitrary choice to ensure each 
        // half edge is added once
        E.conservativeResize(++rows, 2);
        E.row(rows-1) = Eigen::Vector2i(v1, v2);
      }
    }
  }

  return E;
}
