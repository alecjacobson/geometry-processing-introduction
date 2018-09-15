#include <iostream>
#include "euler_characteristic.h"
#include "edges.h"

using namespace std;

int euler_characteristic(const Eigen::MatrixXi &F)
{
	// Chi = |V| - |E| + |F|
  	int Chi = (F.maxCoeff() + 1) - edges(F).rows() + F.rows();

  	return Chi;
}
