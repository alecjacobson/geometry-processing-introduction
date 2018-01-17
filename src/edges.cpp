#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  // Create a index matrix where Epair_ij is the connection between vertex i and vertex j
  Eigen::MatrixXi EPair = Eigen::MatrixXi::Zero(F.maxCoeff() + 1, F.maxCoeff() + 1);
  // Initialize Edge matrix with size #E * 2
  E = Eigen::MatrixXi::Zero(F.rows() * 3.0 / 2.0, 2);
  int idx = 0;
  // Loop through all face
  for (int i = 0; i < F.rows(); i++) {
  	// Loop through all vertex pair
  	for (int j = 0; j < 3; j++) {
  		// j = 0,1,2; next = 1,2,0
  		int next = (j + 1) % 3;
  		// Check if edge already exist
	  	if (EPair(F(i, j), F(i, next)) == 0){ 
	  		// Mark exist pair
	  		EPair(F(i, j), F(i, next)) = 1;
	  		EPair(F(i, next), F(i, j)) = 1;

	  		// Add edge to list
	  		E(idx, 0) = F(i, j);
	  		E(idx, 1) = F(i, next);
	  		idx++;
  		}
  	}
  }
  return E;
}
