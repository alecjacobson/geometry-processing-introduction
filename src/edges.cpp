#include "edges.h"

bool reverseInF(const Eigen::MatrixXi &F, const int index, const int v1, const int v2) {
  bool inF = false;
  int j = index;
  while (!inF && j < F.rows()) {
    if ((F(j,0) == v2 && F(j,1) == v1) ||
        (F(j,1) == v2 && F(j,2) == v1) ||
        (F(j,2) == v2 && F(j,0) == v1)) 
    {
      inF = true;
    }
    j = j + 1;
  }
  return inF;
}

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  int v1, v2;
  int counter = 0;
  
  for (int i = 0; i < F.rows(); i = i + 1){
    int edges[3][2] = { {F(i,0),F(i,1)}, {F(i,1),F(i,2)}, {F(i,2),F(i,0)} };
    for (int k = 0; k < 3; k = k + 1) {
      v1 = edges[k][0];
      v2 = edges[k][1];
      if(reverseInF(F, i, v1, v2)) {
        E.resize(counter + 1, 2);
        E(counter,0) = v1;
        E(counter,1) = v2;
        counter = counter + 1;
      }
    }
  }
  
  return E;
}
