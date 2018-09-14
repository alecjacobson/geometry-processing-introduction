#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    Eigen::MatrixXi E;

    if (F.rows() == 1) {
        return E;
    }

    int nE = 0;
    for (int i = 0; i < F.rows() - 1; ++i) {
        for (int j = i+1; j < F.rows(); ++j) {
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    auto xplus1  = x < 2 ? x + 1: 0;
                    auto yminus1 = y > 0 ? y - 1: 2;
                    if (F(i, x) == F(j, y) && F(i, xplus1) == F(j, yminus1)) {
                        if (E.rows() <= nE) {
                            int nAlloc = E.rows() ? E.rows()*2 : 1;
                            E.conservativeResize(nAlloc, 2);
                        }
                        E.row(nE) << F(i, x), F(i, xplus1);
                        nE += 1;
                    }
                }
            }
        }
    }
    E.conservativeResize(nE, 2);

    return E;
}