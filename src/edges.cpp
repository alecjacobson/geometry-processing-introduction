#include "edges.h"
#include <igl/sortrows.h>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{

	// add all the edges in temp_E 
	// (make sure for each row, the 1st index is less than the 2nd index)
	Eigen::MatrixXi temp_E(F.rows()*3, 2);
	int pair_num = 0;
	for (int i = 0; i < F.rows(); i++) {
		for (int j = 0; j < 3; j++) {
			if (F(i, j) < F(i, (j+1)%3)) {
				temp_E(pair_num, 0) = F(i, j);
				temp_E(pair_num, 1) = F(i, (j+1)%3);
			}
			else {
				temp_E(pair_num, 0) = F(i, (j+1)%3);
				temp_E(pair_num, 1) = F(i, j);
			}
			pair_num++;
		}
	}

	// sort all the edges in temp_E
	Eigen::MatrixXi Y;
	Eigen::MatrixXi I;
	igl::sortrows(temp_E, true, Y, I);

	// get all the unique edges
	Eigen::MatrixXi E;
	int row_num = 0;
	int temp_first = -1;
	int temp_second = -1;
	for (int k = 0; k < Y.rows(); k++) {
        if (temp_first != Y(k, 0) || temp_second != Y(k, 1)) {
        	E.conservativeResize(row_num+1, 2);
			E(row_num, 0) = Y(k, 0);
			E(row_num, 1) = Y(k, 1);
			temp_first = Y(k, 0);
			temp_second = Y(k, 1);
			row_num++;
		}
	}

	return E;
}
