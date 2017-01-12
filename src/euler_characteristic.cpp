#include "euler_characteristic.h"

#include <Eigen/Sparse>
#include <vector>
int euler_characteristic(const Eigen::MatrixXi &F)
{
	auto f = F.rows();

	//Need number of unique vertices. 
	//Can I get this from the adjacency matrix? number of non-zero rows/columns? 
	//Seems the easiest way. This means I'm not constructing the edge list directly.
	//So this DOESN'T use the edges function.

	auto v_max = F.maxCoeff();
	Eigen::SparseMatrix<int> adjacency(v_max + 1, v_max + 1);
	std::vector<Eigen::Triplet<int>> triplet_list;
	triplet_list.reserve(3 * f);
	for (size_t i = 0; i < f; i++) {
		//Sort the triangle indices first. This eliminates duplicates when "setFromTriplets" is called.
		int a = F(i, 0);
		int b = F(i, 1);
		int c = F(i, 2);
		if (c < b) {
			std::swap(b, c);
		}
		if (b < a) {
			std::swap(a, b);
		}
		if (c < b) {
			std::swap(b, c);
		}
		triplet_list.emplace_back(a, b, 1);
		triplet_list.emplace_back(b, c, 1);
		triplet_list.emplace_back(a, c, 1);
	}
	adjacency.setFromTriplets(triplet_list.begin(), triplet_list.end());
	auto e = adjacency.nonZeros(); //Number of non-zer entries in the adjacency matrix.
	auto v = adjacency.outerSize(); //This is the number of non-zero columns in the adjacency matrix.

	int Chi = v - e + f;
	return Chi;
}
