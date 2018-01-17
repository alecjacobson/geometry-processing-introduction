#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F){
	Eigen::MatrixXi E;
	// ADD YOUR CODE HERE
	// Step1: construct unique edge list
	map<pair<int,int>, int> uniqueEdge; // the third int is the useless variable
	for (int r = 0; r < F.rows(); r++){ // Iterator all faces
		for (int idx = 0; idx < 3; idx++){ 
			// Extract two vertices
			int v1 = F(r, (0+idx)%3);
			int v2 = F(r, (1+idx)%3);
			if (v1 < v2) swap(v1, v2); // make sure v1 > v2
			pair<int,int> e(v1, v2);
			if (uniqueEdge.find(e) == uniqueEdge.end()) uniqueEdge[e] = 0;
		}
	}

	// Step2: add unique edge to Eigen::MatrixXi
	E.resize(uniqueEdge.size(), 2);
	int rowIdx = 0;
	for (auto it = uniqueEdge.begin(); it != uniqueEdge.end(); it++){
		E(rowIdx, 0) = it->first.first;
		E(rowIdx, 1) = it->first.second;
		rowIdx++;
	}

	return E;
}
