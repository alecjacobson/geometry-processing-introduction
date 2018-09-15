#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
	int Chi = 0;
	// ADD YOUR CODE HERE
	// Chi = |V| - |E| + |F| =  2
	Eigen::MatrixXi E = edges(F);
	std::vector<int> V;
	for (int i = 0; i < F.rows(); i++) {
		for (int j = 0; j < 3; j++) {
			if (std::find(V.begin(), V.end(), F(i, j)) == V.end()) {
				V.push_back(F(i, j));
			}
		}
	}
	Chi = V.size() - E.rows() + F.rows();
	return Chi;
}
