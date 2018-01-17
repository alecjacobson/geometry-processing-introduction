#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
	// ADD YOUR CODE HERE
  	Eigen::MatrixXi E = edges(F);
	int numEdge = E.rows();
	int numFace = F.rows();

	// Compute number of vertices from faces
	std::unordered_map<int, int> uniqueVert;
	for (int i = 0; i < E.rows(); i++){
		if (uniqueVert.find(E(i,0)) == uniqueVert.end()) uniqueVert[E(i,0)] = 1;
		if (uniqueVert.find(E(i,1)) == uniqueVert.end()) uniqueVert[E(i,1)] = 1;
	}  
	int numVert = uniqueVert.size();
	return numVert - numEdge + numFace;
}
