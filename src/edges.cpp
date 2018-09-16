#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  int start;
  int end;
  int index = 0;

  for (int i = 0; i < F.rows(); i++){
    for (int j = 0; j < 3; j++){
      if (j == 0){
        start = F(i, 0);
        end = F(i, 1);
      } else if (j == 1){
        start = F(i, 0);
        end = F(i, 2);
      } else {
        start = F(i, 1);
        end = F(i, 2);
      }

      bool flag = true;
      for (int k = 0; k < E.rows(); k++){
        if (((start == E(k, 0)) && (end == E(k, 1))) || ((start == E(k, 1)) && (end == E(k, 0)))){
          flag = false;
        }
      }

      if (flag){
        E.conservativeResize(index + 1, 2);
        E(index, 0) = start;
        E(index, 1) = end;
        index++;
      }


    }
  }
  return E;
}
