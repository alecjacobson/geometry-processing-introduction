#include "euler_characteristic.h"
#include "edges.h"
#include <iostream>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);

  int nE = E.rows();
  int nF = F.rows();
  int nV = E.maxCoeff()+1;

  //std::cout << nV << " - " << nE << " + " << nF<< std::endl;

  Chi = nV - nE + nF;

  return Chi;
}
