#include "euler_characteristic.h"
#include "edges.h"
int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  int num_F = F.rows(); //number of faces
  Eigen::MatrixXi e_matrix = edges(F); 
  int num_E = e_matrix.rows(); //number of edges
  int num_V = F.maxCoeff() + 1; //number of vertices, assume no unreferenced vertices
  Chi = num_V - num_E + num_F; 
  return Chi;
}
