#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;

  // The Euler characteristic comes from the following:
  // X = |V| - |E| + |F|
  // so need to know the number of vertices, edges, and faces

  // Number of vertices can come from the maximum value in the F mat
  int32_t numVert = F.maxCoeff() + 1;

  // Number of edges comes from the size of the edges() function
  int32_t numEdges = edges(F).rows();

  // Number of faces comes from the size of F
  int32_t numFaces = F.rows();

  Chi = numVert - numEdges + numFaces;
  
  return Chi;
}
