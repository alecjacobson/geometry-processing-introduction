#include "edges.h"
#include "igl/unique_rows.h"

void insertRawEdges(int start, int end, Eigen::MatrixXi &E, int index)
{
  int temp = 0;

  if (start >= end)
  {
    temp = start;
    start = end;
    end = temp;
  }

  E.row(index) << start, end;
}

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi TempE, IC, IA;
  TempE.resize((int)F.rows() * 3, 2);
  for (int i = 0; i < (int)F.rows(); i++)
  {
    insertRawEdges(F(i, 0), F(i, 1), TempE, i * 3);
    insertRawEdges(F(i, 1), F(i, 2), TempE, i * 3 + 1);
    insertRawEdges(F(i, 2), F(i, 0), TempE, i * 3 + 2);
  }

  igl::unique_rows(TempE, E, IA, IC);

  return E;
}
