#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
    int numF, numE, numV;
    Eigen::MatrixXi E;
    
    //Compute the edges using the faces. Unnecessary for closed meshes with 0 holes.
    E = edges(F);
    numF = F.rows();
    numE = E.rows();
    
    //We know that the maximum value of F gives us sufficient information for computing the size of V
    numV = F.maxCoeff() + 1;
    
    Chi = numV - numE + numF;

  return Chi;
}
