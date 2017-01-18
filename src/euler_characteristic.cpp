#include "euler_characteristic.h"
#include "edges.h"
#include <climits>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  // Chi = |V| - |E| + |F|.
  
  Eigen::MatrixXi E = edges(F);
  int E_num = E.rows();
  int F_num = F.rows();
  int V_num = INT_MIN;

  //find maximum vertex index which is equal to number of verticies in total minus 1
  for (int i = 0; i < E_num; ++i) 
  {
  	V_num = (V_num < E(i,0)) ? E(i,0) : V_num;
  	V_num = (V_num < E(i,1)) ? E(i,1) : V_num;
  }

  V_num++; //since indexing starts from 0
  Chi = V_num - E_num + F_num;

  return Chi;
}
