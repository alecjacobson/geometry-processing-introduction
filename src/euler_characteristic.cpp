#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;

  // Number of faces
  int f = F.rows();
  
  // Number of vertices
  // (the vertices are numbered consecutively, starting at 0, and each vertex is included 
  // in F. This means the max numbered vertex is 1 less than the total number of vertices).
  int v = F.maxCoeff() + 1;
  
  // Number of edges
  int e = edges(F).rows();
  
  // Compute Chi using the formula for the Euler Characteristic of a polyhedral surface
  Chi = v - e + f;
  
  return Chi;
}
