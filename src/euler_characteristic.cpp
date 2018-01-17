#include <set>
#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{

	int faceCount = F.rows();

	Eigen::MatrixXi theEdges = edges(F);
	int edgeCount = theEdges.rows();

	// Have to calculate set of vertex indices so that we can get the correct
	// vertex count.
	// Looks like vertices were already indexed nicely, but oh well...
	std::set<int> vertexSet;
	for (int i = 0; i < faceCount; i++) {
		vertexSet.insert(F(i, 0));
		vertexSet.insert(F(i, 1));
		vertexSet.insert(F(i, 2));
	}
	int vertexCount = vertexSet.size();

	// Formula from the readme. Assumes polyhedral surfaces.
	int Chi = vertexCount - edgeCount + faceCount;
	return Chi;
}
