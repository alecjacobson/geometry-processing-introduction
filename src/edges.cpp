#include "edges.h"
#include <vector>
#include "assert.h"

#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

typedef std::vector<std::vector<bool>> vertexBitset_t;

static void test(Eigen::MatrixXi &E) {
    for (int i = 0; i < E.cols(); i++) {
        assert(E(i, 0) != E(i, 1));

        for (int j = 0; j < E.cols(); j++) {
            if (i == j)
                continue;

            assert(!(E(j, 0) == E(i, 0) && E(j, 1) == E(i, 1)));
            assert(!(E(j, 1) == E(i, 0) && E(j, 0) == E(i, 1)));
        }
    }
}

static void process_edge(Eigen::MatrixXi &E, vertexBitset_t &vertexBitset, int v1, int v2) {
    int k = E.rows();

    if (!vertexBitset[v1][v2]) {
        E.conservativeResize(k + 1, E.cols());

        vertexBitset[v1][v2] = 1;
        vertexBitset[v2][v1] = 1;

        E(k, 0) = v1;
        E(k, 1) = v2;

        DEBUG_PRINT(("%d %d\n", E(k, 0), E(k, 1)));
    }
}

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {
    Eigen::MatrixXi E;
    // ADD YOUR CODE HERE

    E = Eigen::MatrixXi(0, 2);

    vertexBitset_t vertexBitset(F.rows(), std::vector<bool>(F.rows(), 0));

    // Process the three edges of each triangle
    for (int i = 0; i < F.rows(); i++) {
        DEBUG_PRINT(("%d %d %d\n", F(i, 0), F(i, 1), F(i, 2)));

        process_edge(E, vertexBitset, F(i, 0), F(i, 1));
        process_edge(E, vertexBitset, F(i, 1), F(i, 2));
        process_edge(E, vertexBitset, F(i, 0), F(i, 2));
    }

    test(E);

    return E;
}
