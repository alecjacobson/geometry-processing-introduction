#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F) {
    long Chi = 0;
    long V = F.maxCoeff() + 1;
    long F_ = F.rows();
    long E = edges(F).rows();
    Chi = V - E + F_;
    return int(Chi);
}
