#include "edges.h"
#include <Eigen/SparseCore>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {
    Eigen::MatrixXi E;

    // ADD YOUR CODE HERE
    // Compute expected number of edges (assuming F is a closed polyhedron).
    int nEdges = F.rows() * F.cols() / 2;

    E.resize(nEdges, 2);
    int Eindex = 0;

    int nRows = F.rows();
    int nCols = F.cols();

    // Search through all edges (adjacent pairs) in the face matrix.
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            int first = F(row, col);
            int second = F(row, (col + 1) % nCols);

	    // Only record edges if their first vertex index is less than their
	    // second vertex index (to avoid double-adding).
            if (first < second) {
                E(Eindex, 0) = first;
                E(Eindex, 1) = second;
		Eindex += 1;
	    }
        }
    }

    return E;
}
