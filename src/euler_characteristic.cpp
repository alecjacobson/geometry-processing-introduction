#include "edges.h"
#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
    Eigen::MatrixXi E = edges(F);
    int max_index = -1;

    // Since edges() returns a matrix with sorted rows, 
    // we know the highest index (which corresponds to
    // the number of vertices) must be in the second column
    for (int i = 0; i < E.rows(); i++) {
        if (E(i, 1) > max_index) {
            max_index = E(i, 1);
        }
    }

    // Add 1 since indexing starts from 0
    int V_size = max_index + 1;
    
    int Chi = V_size - E.rows() + F.rows();
    return Chi;
}
