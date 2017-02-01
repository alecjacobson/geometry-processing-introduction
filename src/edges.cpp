#include "edges.h"
#include <Eigen/Sparse>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
	//I think the nicest (in terms of elegance) 
	//way to do this is to create a sparse adjacency matrix. 
	size_t num_faces = F.rows();
	int v_max = F.maxCoeff();
	Eigen::SparseMatrix<int> adjacency(v_max + 1, v_max + 1);
	std::vector<Eigen::Triplet<int>> triplet_list;
	triplet_list.reserve(3 * num_faces);

	for (size_t i = 0; i < num_faces; i++) {
		//Sort the triangle indices first. Only 3 entries, so do it manually.
		int a = F(i, 0);
		int b = F(i, 1);
		int c = F(i, 2);
		if (c < b) {
			std::swap(b, c);
		}
		if (b < a) {
			std::swap(a, b);
			if (c < b) {
				std::swap(b, c);
			}
		}

		triplet_list.emplace_back(a, b, 1);
		triplet_list.emplace_back(b, c, 1);
		triplet_list.emplace_back(a, c, 1);
	}

	adjacency.setFromTriplets(triplet_list.begin(), triplet_list.end());

	//Now, iterate over entries and add to edge list.
	Eigen::MatrixXi E;
	E.resize(adjacency.nonZeros(), 2);
	size_t i = 0;
	for (int k = 0; k < adjacency.outerSize(); ++k) {
		for (Eigen::SparseMatrix<int>::InnerIterator it(adjacency, k); it; ++it) {
			E(i, 0) = it.row();
			E(i, 1) = it.col();
			i++;
		}
	}

	return E;
}
