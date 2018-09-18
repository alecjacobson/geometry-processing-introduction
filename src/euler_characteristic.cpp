#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;

  // number of faces
  int num_F = F.rows(); 

  // Matrix with undirected edges.
  Eigen::MatrixXi E = edges(F);

  // number of edges
  int num_E = E.rows(); 
  
  // We are not sure if all vertex indices in V have been used in F (as that is the input data - no guarantees).
  // So, construct a VectorXi that keeps track of unique vertex indices.
  // Upper bound on the num of vertices = |E| * 2.
  Eigen::VectorXi V(num_E * 2);

  // num_V tracks the number of unq vertices as we iterate over E
  int num_V = 0;

  for (int row_index_e = 0; row_index_e < num_E; row_index_e++) {
    
    // this loop runs twice. 
    for (int col_index_e = 0; col_index_e < 2; col_index_e++) {

      // check if the vertex is already present in the vertex list
      bool isDuplicate = false;

      for (int row_index_v = 0; row_index_v < num_V; row_index_v++) {
        if (E(row_index_e, col_index_e) == V(row_index_v)) {
          isDuplicate = true;
          break;
        }
      }

      if (!isDuplicate) {
        V(num_V) = E(row_index_e, col_index_e);
        num_V++;
      }

    }

  }

  // Compute Chi
  Chi = num_V - num_E + num_F;

  return Chi;
}
