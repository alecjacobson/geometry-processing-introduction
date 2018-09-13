#include <unordered_set>

#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
    int Chi = 0;
    auto E = edges(F);

    std::unordered_set<int> V;
    for (auto p = F.data(); p < F.data() + F.size(); ++p) {
        V.insert(*p);
    }

    Chi = V.size() - E.rows() + F.rows();
    return Chi;
}
