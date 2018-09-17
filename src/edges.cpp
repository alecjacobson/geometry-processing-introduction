#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E_temp(F.rows() * 3, 2);
  int max_vert_idx = 0;
  // ADD YOUR CODE HERE
  for (int i = 0; i < F.rows(); i++) {
      // add the 3 half-edges specified from a single face in F
      E_temp(3 * i, 0) = F(i, 0);
      E_temp(3 * i, 1) = F(i, 1);
      E_temp(3 * i + 1, 0) = F(i, 1);
      E_temp(3 * i + 1, 1) = F(i, 2);
      E_temp(3 * i + 2, 0) = F(i, 2);
      E_temp(3 * i + 2, 1) = F(i, 0);
      int max_of_three = std::max(std::max(F(i,0), F(i,1)), F(i,2));
      if (max_of_three > max_vert_idx) {
	max_vert_idx = max_of_three;
      }
  } 

  // Count number of unique edges and produce that list.
  Eigen::MatrixXi Unique_Edge_Mat = Eigen::MatrixXi::Zero(max_vert_idx + 1, max_vert_idx + 1);
  for (int i = 0; i < E_temp.rows(); i++) {
	Unique_Edge_Mat(E_temp(i,0), E_temp(i,1)) = 1;
  } 
  int N_edges = Unique_Edge_Mat.sum() / 2; // Each half-edge has been counted twice


  Eigen::MatrixXi E(N_edges, 2);
  int curRow = 0;
  for (int i = 0; i <= max_vert_idx; i++) {
	for (int j = 0; j <= i; j++) {
            if (Unique_Edge_Mat(i,j) == 1) {
		E(curRow, 0) = i;
		E(curRow, 1) = j;
		curRow++;
	  }
	}
  }

  return E;
}
