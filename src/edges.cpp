#include "edges.h"
#include "map"

using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {
    Eigen::MatrixXi E;
    // I am using map. If speed is a concern, we can use unordered_map instead. count/find would be faster -> O(logn) vs O(1).
    map<pair<int, int>, int> temp_set;
    pair<int, int> p;
    for (int i = 0; i < F.rows(); i++) {
        for (int j = 0; j < F.cols(); j++) {
            // Let's get the pair...
            int f_ij_1 = F(i, j);
            int f_ij_2 = F(i, (j + 1) % 3);

            // let's keep the order consistent(f1,f2) such that f2>f1.
            // By doing this, we can quickly check into the dict/map(for all the cases)
            if (f_ij_2 > f_ij_1) {
                p = {f_ij_1, f_ij_2};
            } else {
                p = {f_ij_2, f_ij_1};
            }
            // fast lookup into the map.
            if (temp_set.count(p) == 0) {
                temp_set.insert(std::make_pair(p, 0));
            } else {
                // if this pair was already seen, it is a half-edge (duplicated)
                // Note: This assumes a manifold mesh where an edge is not shared by more than two faces.
                // but it should work in anycase
                continue;
            }
        }

    }

    // This could be also done after line 32 by using conservativeResize in the number of rows.
    // However, constantly reallocating memory should be more expensive.
    E.resize(temp_set.size(), 2);
    int i = 0;
    for (auto t : temp_set) {
        E(i, 0) = t.first.first;
        E(i, 1) = t.first.second;
        i++;
    }
    return E;
}
