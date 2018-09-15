#include <iostream>
#include <igl/sort.h>
#include <igl/sortrows.h>
#include "edges.h"

using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {

	Eigen::MatrixXi E_duprow(3 * F.rows(), 2), Y, E_duprow_sorted, I;

	// get E with duplicated rows
	E_duprow << F.col(0), F.col(1), F.col(0), F.col(2), F.col(1), F.col(2);

	// sort within each row  e.g. (1,2) -> (1,2), (2,1) -> (1,2)
 	igl::sort(E_duprow, 0, true, Y, I);

 	// sort rows so that every two rows are identical
 	igl::sortrows(Y, true, E_duprow_sorted, I);

 	// pick odd rows
	Eigen::MatrixXi E = Eigen::MatrixXi::Map(E_duprow_sorted.data(), E_duprow.rows()/2, 2, Eigen::Stride<Eigen::Dynamic,2>(E_duprow.rows(),2));
	
	return E;
}
