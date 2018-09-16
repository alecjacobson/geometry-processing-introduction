#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;

  int k = 0;

  for (int i=0; i < F.rows(); i ++) {
    for (int j=0; j < 3; j ++) {

      // Construct current edge
      Eigen::RowVector2i edge;
      if (j == 2)
        edge << F(i, j), F(i, 0);
      else
        edge << F(i, j), F(i, j + 1);
      
      // Check if current edge already in E
      // Idea: two half-edge's have opposite 
      // orientation on a consistently oriented mesh
      Eigen::RowVector2i oppo_edge;
      oppo_edge << edge(1), edge(0);

      if (E.rows() != 0) {
        if ( ((E.rowwise() - oppo_edge
              ).cwiseAbs().rowwise().sum().array() == 0).any() ) {
          continue;
        }
      }

      // Able to add a new edge
      E.conservativeResize(k + 1, 2);
      E(k, 0) = edge(0);
      E(k, 1) = edge(1);
      k ++;
    }
  }
  return E;
}
