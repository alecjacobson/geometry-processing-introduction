#include "edges.h"
#include <igl/sort.h>
#include <igl/unique_rows.h>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  Eigen::MatrixXi Y, I, Eall;
  
  igl::sort(F,2,true,Y,I);
  for (int i = 0; i < Y.rows(); i++) {
    //igl::sort(F.row(i),1,true,Y,I);
    //std::cout << Y.row(i) << "\n";
    int rowIndex = Eall.rows();
    Eall.conservativeResize(rowIndex+3, 2);
    Eall(rowIndex,0) = Y(i,0);
    Eall(rowIndex,1) = Y(i,1);
    Eall(rowIndex+1,0) = Y(i,0);
    Eall(rowIndex+1,1) = Y(i,2);
    Eall(rowIndex+2,0) = Y(i,1);
    Eall(rowIndex+2,1) = Y(i,2);
    
  } // we get all edges now.

  Eigen::MatrixXi IE, IEall;
  igl::unique_rows(Eall,E,IEall,IE);

  return E;
}
