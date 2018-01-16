#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);
  int V_size = getVSize(F);
  Chi = V_size - E.rows() + F.rows();
  return Chi;
}

int getVSize(const Eigen::MatrixXi &F){
  std::set<int> seenVertices;
  int V_size = 0;
  for(int f_idx =0; f_idx < F.rows() ; f_idx++){
    for(int v_idx=0; v_idx < 3 ; v_idx++){
      if(! (seenVertices.find(F(f_idx, v_idx)) != seenVertices.end())){
        V_size += 1;
        seenVertices.insert(F(f_idx, v_idx));
      }
    }
  }
  return V_size;
}
