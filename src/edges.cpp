#include <vector>
#include <set>
#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
	Eigen::MatrixXi E;

	// Make sure edges are unique by generating a set.
	std::set<std::pair<int, int>> edgeSet;
	int faceCount = F.rows();
	for (int i = 0; i < faceCount; i++) {
		edgeSet.insert(std::pair<int, int>(F(i, 0), F(i, 1)));
		edgeSet.insert(std::pair<int, int>(F(i, 1), F(i, 2)));
		edgeSet.insert(std::pair<int, int>(F(i, 2), F(i, 0)));
	}

	// Convert set into a vector so that we can use MatrixXi::Map(...).
	std::vector<int> edgeData;
	for (auto edge : edgeSet) {
		edgeData.push_back(edge.first);
		edgeData.push_back(edge.second);
	}

	int edgeCount = edgeSet.size();
	E = Eigen::MatrixXi::Map(&edgeData.front(), edgeCount, 2);

	return E;
}
