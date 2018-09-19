#include "edges.h"
#include <algorithm>
#include <set>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    Eigen::MatrixXi E;
    std::set< std::pair<int,int> > fedges;
    for (int i = 0; i < F.rows(); i++)
    {
        int a, b;
        a = std::min(F(i, 0), F(i, 1));
        b = std::max(F(i, 0), F(i, 1));
        fedges.insert(std::make_pair(a,b));
        a = std::min(F(i, 1), F(i, 2));
        b = std::max(F(i, 1), F(i, 2));
        fedges.insert(std::make_pair(a,b));
        a = std::min(F(i, 2), F(i, 0));
        b = std::max(F(i, 2), F(i, 0));
        fedges.insert(std::make_pair(a,b));
    }
    Eigen::MatrixXi E2(fedges.size(), 2);
    E = E2;
    std::set< std::pair<int,int> >::iterator e;
    int i = 0;
    for (e = fedges.begin(); e != fedges.end(); ++e) {
        std::pair<int,int> edge = *e;
        E(i, 0) = edge.first;
        E(i, 1) = edge.second;
        i++;
    }
    return E;
}
