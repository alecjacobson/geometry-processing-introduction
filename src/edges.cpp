#include <iostream>
#include <igl/sort.h>
#include <igl/unique_rows.h>
#include "edges.h"

using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {

	Eigen::MatrixXi E_duprow(3 * F.rows(), 2), E_duprow_sorted, E, I;

	// get E with duplicated rows
	E_duprow << F.col(0), F.col(1), F.col(0), F.col(2), F.col(1), F.col(2);

	// sort within each row  e.g. (1,2) -> (1,2), (2,1) -> (1,2)
 	igl::sort(E_duprow, 0, true, E_duprow_sorted, I);

 	// remove duplicated edges
 	igl::unique_rows(E_duprow_sorted,E,I,I);

	return E;
}
