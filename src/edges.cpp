#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
	Eigen::MatrixXi E;
	int counter = 0;
	std::vector<std::vector<int>> all_edges;
	// ADD YOUR CODE HERE	
	E.conservativeResize(E.rows(), E.cols() + 2);
	for (int i = 0; i < F.rows(); i++) {
		for (int j = 0; j < 3; j++) {
			std::vector<int> edge;
			edge.push_back(F(i, j));
			edge.push_back(F(i, (j + 1) % 3));
			if (std::find(all_edges.begin(), all_edges.end(), edge) == all_edges.end()) {
				std::reverse(edge.begin(), edge.end());
				if (std::find(all_edges.begin(), all_edges.end(), edge) == all_edges.end()) {
					E.conservativeResize(E.rows() + 1, E.cols());
					E(counter, 0) = F(i, j);
					E(counter, 1) = F(i, (j + 1) % 3);
					all_edges.push_back(edge);
				}
			}
		}
		counter++;
	}
	return E;
}