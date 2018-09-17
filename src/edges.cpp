#include "edges.h"
#include <tuple>
#include <set>

using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    set<tuple<int, int>> edges;
    const int row_len = 3;
    
    for (int i = 0; i < F.rows(); i++) 
    {
        // Sort the vector in ascending order to ensure
        // there are no duplicate edges in the set
        Eigen::Vector3i row = F.row(i);
        sort(row.data(), row.data() + row.size());

        edges.insert(tuple<int, int>(row[0], row[1]));
        edges.insert(tuple<int, int>(row[0], row[2]));
        edges.insert(tuple<int, int>(row[1], row[2]));
	}
    
    Eigen::MatrixXi E(edges.size(), 2);
    int cur_col = 0;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        E(cur_col, 0) = get<0>(*it);
        E(cur_col, 1) = get<1>(*it);
        cur_col++;
    }
    
    return E;
}
