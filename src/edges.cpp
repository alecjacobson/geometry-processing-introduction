#include "edges.h"
#include <iostream>
#include <set>
#include <array>

using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {
    Eigen::MatrixXi E;
    // ADD YOUR CODE HERE
    set<array<int, 2>> edges;

    for (int i = 0; i < F.rows(); i++) {
        array<int, 3> tmp = {F(i, 0), F(i, 1), F(i, 2)};
        sort(tmp.begin(), tmp.end());

        array<int, 2> edge0 = {tmp[0], tmp[1]};
        array<int, 2> edge1 = {tmp[0], tmp[2]};
        array<int, 2> edge2 = {tmp[1], tmp[2]};

        edges.insert(edge0);
        edges.insert(edge1);
        edges.insert(edge2);
    }

    E.resize(edges.size(), 2);
    int i = 0;
    for (auto it = edges.begin(); it != edges.end(); it++, i++) {
        E(i, 0) = (*it)[0];
        E(i, 1) = (*it)[1];
    }

    return E;
}
