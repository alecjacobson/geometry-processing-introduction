#include "edges.h"
#include <algorithm>    // std::swap
void AddEdge(Eigen::MatrixXi &CounterMatrix, int vert1, int vert2)
{
  if (vert1 > vert2)
    std::swap(vert1, vert2);
  if (CounterMatrix(vert1, vert2) == 0)
    CounterMatrix(vert1, vert2)  =1;
}

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  int iMaxIndex =F.maxCoeff();
  Eigen::MatrixXi cCounterMatrix(iMaxIndex + 1, iMaxIndex + 1);
  cCounterMatrix.setZero();
  int iFaceNumber = F.rows();
  for (int i = 0; i < iFaceNumber; i++)
  {
    AddEdge(cCounterMatrix, F(i, 0), F(i, 1));
    AddEdge(cCounterMatrix, F(i, 1), F(i, 2));
    AddEdge(cCounterMatrix, F(i, 2), F(i, 0));
  }
  int iTotalEdge = cCounterMatrix.sum();
  E.resize(iTotalEdge, 2);
  int iCurrentIndex = 0;
  for (int i = 0; i <= iMaxIndex; i++)
    for (int j = i; j <= iMaxIndex; j++)
      if (cCounterMatrix(i, j) > 0)
      {
        E(iCurrentIndex, 0) = i;
        E(iCurrentIndex, 1) = j;
        iCurrentIndex++;
      }
         
  return E;
}
