#include "edges.h"
#include <Eigen/Sparse>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  // Compute the adjacency matrix of the triangle mesh
  // and store it in a sparse matrix 
  typedef Eigen::Triplet<int> T;
  typedef Eigen::SparseMatrix<int> SpMat;
  // Use triplets to create the sparse matrix
  std::vector<T> triplets;
  triplets.reserve(F.rows()*4);
  for (int i = 0; i < F.rows(); i++) {
	  triplets.push_back(T(F(i, 0), F(i, 1), 1));
	  triplets.push_back(T(F(i, 1), F(i, 2), 1));
	  triplets.push_back(T(F(i, 2), F(i, 0), 1));
  }
  int v_num = F.maxCoeff() + 1;
  SpMat adjMat(v_num, v_num), tmpMat;
  adjMat.setFromTriplets(triplets.begin(), triplets.end());
  // Add the adjacency matrix to its transpose to include all adjacency 
  // characteristics in the triangluar(upper/lower) part of the matrix
  tmpMat = SpMat(adjMat.transpose()) + adjMat;
  E.resize(tmpMat.nonZeros()/2, 2);
  // Obtain edge info from the lower triangular part of the adjacency matrix
  int E_idx = 0;
  for (int col = 0; col < tmpMat.outerSize(); ++col) {
	  for (SpMat::InnerIterator it(tmpMat, col); it; ++it) {
		  if (it.col() < it.row()) {
			  E(E_idx, 0) = it.row();
			  E(E_idx, 1) = it.col();
			  E_idx++;
		  }
	  }
  }
  return E;
}
