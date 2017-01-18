#include "euler_characteristic.h"
#include "edges.h"

#include <map>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  
  //Euler Characteristic -> Chi = |V| - |E| + |F|

  //Find |V| -> The number of unique indices referenced in F
  std::map<int, int> vertexMap;
  for (int i = 0; i < F.size(); i++) {
	  vertexMap.insert(std::make_pair(F(i), 1));
  }
  int V = vertexMap.size();

  //Find |E| -> The number of unique edges, found in edges()
  int E = edges(F).rows();

  //Find |F| -> The number of faces, i.e the rows of F
  int f = F.rows();

  //Calculate Euler Characteristic
  Chi = V - E + f;

  return Chi;
}
