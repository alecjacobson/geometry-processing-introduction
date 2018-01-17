#include <iostream>
#include "euler_characteristic.h"
#include "edges.h"
#include <set>

using namespace std;

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  Eigen::MatrixXi E = edges(F);
  int n_E = E.rows();
  cout << "Number of Edges: " << n_E << endl;

  int n_F = F.rows();
  // cout << "Number of Faces: " << n_F << endl;

  set<int> s;
  for(int i = 0; i < n_E; i = i + 1) {
	s.insert(E(i, 0));
	s.insert(E(i, 1));
  }
  int n_V = s.size();
  cout << "Number of Vertices: " << n_V << endl;

  Chi = n_V - n_E + n_F;

  return Chi;
}
