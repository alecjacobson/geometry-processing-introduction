#include "euler_characteristic.h"

#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F) {
	int Chi = 0;
	// ADD YOUR CODE HERE

	int vnum = 0;
	int fnum = F.rows();

	Eigen::MatrixXi E = edges(F);
	int enm = E.rows();

	// assign max value in F as vertex number
	for (int i = 0; i < fnum; i++) {
		for (int j = 0; j < 3; j++) {
			if (vnum < F(i, j))
				vnum = F(i, j);
		}
	}

	Chi = vnum + fnum - enm;

	return Chi;
}
