#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;

  // The maximum bound on |E| is 3*|F|.
  // Initialize E with an initial number of rows = 2*|F|.
  E.Zero(F.rows()*2, 2);

  // Variable maintaining the actual |E| as we iterate.
  int num_edges = 0;

  // Loop across the rows of F.
  for (int row_index_f = 0; row_index_f < F.rows(); row_index_f++) {
    
    // this loop runs 3 times.
    for (int col_index_f = 0; col_index_f < 3; col_index_f++) {
      
      // get the next index to form an edge (do arithmetic in mod 3 to form pairs of edges)
      int next_col_index = (col_index_f + 1) % 3;

      // Flag to check if the current edge is a duplicate (i.e., already exists in E)
      // Initialize to false as we start with num_edges = 0.
      bool isDuplicate = false;

      // Check if E has to be resized
      if (E.rows() == num_edges) {
        // Do a conservative resize to increase rows by F.rows()
        E.conservativeResize(E.rows() + F.rows(), 2);
      } 

      // Loop through E to check if duplicate.
      // Check both the directions since E is unq list of undirected edges.
      for (int row_index_e = 0; row_index_e < num_edges; row_index_e++) {
        if ((E(row_index_e, 0) == F(row_index_f, col_index_f)) && (E(row_index_e, 1) == F(row_index_f, next_col_index))) {
          isDuplicate = true;
          break;
        } else if ((E(row_index_e, 1) == F(row_index_f, col_index_f)) && (E(row_index_e, 0) == F(row_index_f, next_col_index))) {
          isDuplicate = true;
          break;
        }
      }

      if (!isDuplicate) {
        // If not a duplicate entry, add to the list of edges and update the counter num_edges.
        E(num_edges, 0) = F(row_index_f, col_index_f);
        E(num_edges, 1) = F(row_index_f, next_col_index);

        num_edges++;
      }
      
    } 

  }

  // If the final size is higher than actual num_edges, crop off garbage.
  E.conservativeResize(num_edges, 2);

  return E;
}
