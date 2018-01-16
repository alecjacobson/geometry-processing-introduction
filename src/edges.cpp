#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  Eigen::MatrixXi ADJ;
  ADJ.resize(F.maxCoeff()+1, F.maxCoeff()+1);
  
  for (int i = 0; i < F.rows(); ++i) {
	int x = F(i, 0);
	int y = F(i, 1);
	int z = F(i, 2);

	ADJ(x, y) = 1;
	ADJ(x, z) = 1;
	ADJ(y, z) = 1;
	ADJ(y, x) = 1;
	ADJ(z, x) = 1;
	ADJ(z, y) = 1;
  }

  int n = 0;
  for (int i = 0; i < ADJ.rows(); ++i) {
	for (int j = 0; j <ADJ.cols(); ++j) {
		if (ADJ(i, j) != 0) {
			n++;
		}
	}
  }
  
  E.resize(n/2, 2);

  int e = 0;
  for (int i = 0; i<ADJ.rows(); ++i) {
	for (int j = 0; j<ADJ.cols(); ++j) {
		if (i > j) {
			if (ADJ(i, j) ==1) {
				E(e, 0) = i;
				E(e, 1) = j;
				e++;
			}
		}
	}
  }

  return E;
}
