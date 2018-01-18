#include "edges.h"
#include <iostream> 
#include <algorithm>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  int n = F.maxCoeff() + 1;
  Eigen::MatrixXi E (3*n, 2);
  // Temporary matrix to house edges
  Eigen::MatrixXi edge (n, n);

// Order nodes from min to max for each Face
// Save edges with that ordering
  for (int i = 0; i < F.rows(); i = i + 1) {
  	int a = F.row(i).minCoeff();
  	int c = F.row(i).maxCoeff();
  	int b = F(i, 0) + F(i, 1) + F(i, 2) - a - c;
  	edge(a, b) = 1;
  	edge(a, c) = 1;
  	edge(b, c) = 1;
}
// Fill E Matrix with edges
  int numE = 0;

  for (int i = 0; i < n; i = i + 1) {
  	for (int j = 0; j < n; j = j + 1) {
  	if (edge(i, j) == 1){
      numE += 1;
  		E(i, 0) = i;
   		E(i, 1) = j;
  }
}
}
  E.resize(numE,2);
  return E;
}
