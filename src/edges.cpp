#include "edges.h"
#include <igl/unique.h>
#include <igl/sort.h>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E(F.rows()*3, 2);
  // ADD YOUR CODE HERE
  
  int j = 0;
  for (int i = 0; i < F.rows(); i++)
  {
	  E(j, 0) = F(i, 0);
	  E(j, 1) = F(i, 1);
	  E(j+1, 0) = F(i, 1);
	  E(j+1, 1) = F(i, 2);
	  E(j+2, 0) = F(i, 2);
	  E(j+2, 1) = F(i, 0);
	  j += 3;
  }

  Eigen::MatrixXi Y;
  Eigen::MatrixXi IX;

  igl::sort(E, 2, true, Y, IX);

  Eigen::MatrixXi C;
  Eigen::VectorXi IA;
  Eigen::VectorXi IC;
  igl::unique_rows(Y, C, IA, IC);

  E = C;

  return E;
}
