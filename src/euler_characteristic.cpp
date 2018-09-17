#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F) {
    int Chi = 0;
    // ADD YOUR CODE HERE

    // maxCoeff returns the largest vertex index
    Chi = F.maxCoeff() + 1 - edges(F).rows() + F.rows();

    return Chi;
}
