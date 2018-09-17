#include "edges.h"
#include <set>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  // Use a set of sets of interger to find unique edges
  std::set<std::set<int>> ss;
  for (int i = 0; i < F.rows(); i++) {
	  // The endpoints are added to s1, s2 and s3 so that
	  // when compared with other edges the order of vertices
	  // does not affect the comparison
	  std::set<int> s1, s2, s3;
	  s1.insert(F(i, 0)); s1.insert(F(i, 1));
	  ss.insert(s1);
	  s2.insert(F(i, 1)); s2.insert(F(i, 2));
	  ss.insert(s2);
	  s3.insert(F(i, 2)); s3.insert(F(i, 0));
	  ss.insert(s3);

  }

  // Iterate through the results and store the indices
  // into the output matrix
  std::set<std::set<int>>::iterator it_outer;
  std::set<int>::iterator it_inner;
  E = Eigen::MatrixXi(ss.size(), 2);
  int i = 0;
  for (it_outer = ss.begin(); it_outer != ss.end(); it_outer++) {
	  int j = 0;
	  for (it_inner = it_outer->begin(); it_inner != it_outer->end(); it_inner++) {
		  E(i, j) = *it_inner;
		  j++;
	  }
	  i++;
  }
  return E;
}
