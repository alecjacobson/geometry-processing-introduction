#include "edges.h"
#include <array>
#include <set>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    using EA = std::array<int,2>;
    std::set<EA> es;

    auto mkarr = [](int a, int b) -> EA {
        if(a < b) {
            return {{a,b}};
        } else {
            return {{b,a}};
        }
    };

    for(int r = 0; r < F.rows(); ++r) {
        auto&& f = F.row(r);
        es.emplace(mkarr(f(0),f(1)));
        es.emplace(mkarr(f(0),f(2)));
        es.emplace(mkarr(f(2),f(1)));
    }



    Eigen::MatrixXi E(es.size(),2);
    int r = 0;
    for(auto&& e: es) {
        E(r,0) = e[0];
        E(r,1) = e[1];
        r++;
    }

    return E;
}
