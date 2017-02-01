#include "edges.h"
#include <array>
#include <set>

struct ua: public std::array<int,2> {
    template <typename... Args>
        ua(Args&&... args)
        : std::array<int,2>{std::forward<Args>(args)...} {
            std::sort(begin(),end());
        }

};


Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    std::set<ua> es;


    const static int fedges[3][2] = {{0,1}, {0,2}, {1,2}};
    for(int r = 0; r < F.rows(); ++r) {
        auto&& f = F.row(r);
        for(auto&& o: fedges) {
            es.emplace(ua{f(o[0]),f(o[1])});
        }
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
