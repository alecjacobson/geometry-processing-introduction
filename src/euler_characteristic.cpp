#include "euler_characteristic.h"
#include "edges.h"
#include <set>
#include <iostream>

int euler_characteristic(const Eigen::MatrixXi &F)
{
    std::set<int> v;
    std::copy(F.data(),F.data()+F.size(),std::inserter(v,v.end()));

    int nV = v.size();
    int nE = edges(F).rows();
    int nF = F.rows();


    return nV -nE + nF;
}
