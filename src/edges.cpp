#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  int E_size = 0;
  Eigen::MatrixXi E;

  // F contains indicies into V, and no vertex is unreferenced
  // so |V| is the largest index seen + 1
  int V_size = F.maxCoeff() + 1;
  Eigen::MatrixXi seenEdges = Eigen::MatrixXi::Zero(V_size, V_size);

  // Iterate over F and add each of its edges to E
  for(int f_idx = 0; f_idx < F.rows(); f_idx++){
    addToEdges(E, E_size, seenEdges, F(f_idx,0), F(f_idx,1));
    addToEdges(E, E_size, seenEdges, F(f_idx,0), F(f_idx,2));
    addToEdges(E, E_size, seenEdges, F(f_idx,1), F(f_idx,2));
  }
  return E;
}

// Adds the undirected edge (vertexA, vertexB) to E if it is not in seenEdges, and returns an updated E_size
void addToEdges(Eigen::MatrixXi &E, int &E_size, Eigen::MatrixXi &seenEdges, int vertexA, int vertexB){
  if(!seenEdges(vertexA, vertexB)){
    E_size += 1;
    E.resize(E_size, 2);
    // Add the new undirected edge to E
    E(E_size-1, 0) = vertexA;
    E(E_size-1,1) = vertexB;
    // Mark the edge as seen in either direction
    seenEdges(vertexA, vertexB) = 1;
    seenEdges(vertexB, vertexA) = 1;
  }
}
