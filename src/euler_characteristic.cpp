#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F) {
    int Chi = 0;

    // ADD YOUR CODE HERE
    int nFaces = F.rows();
    // Search for max referenced vertex index.
    int nVertices = F.maxCoeff() + 1;

    Eigen::MatrixXi E = edges(F);
    int nEdges = E.rows();

    Chi = nVertices - nEdges + nFaces;

    return Chi;
}
