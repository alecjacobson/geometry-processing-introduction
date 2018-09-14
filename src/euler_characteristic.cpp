#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
    int Chi = 0;
    auto E = edges(F);
    Chi = F.maxCoeff() + 1 - E.rows() + F.rows();
    return Chi;
}
