#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  std::map<int, std::vector<int>> rmap;
  for (int i = 0; i< F.rows(); ++i){
  	for (int j = 0; j< 3; ++j){//3 potional edges
  		int start = F(i,j);
  		int end = F(i,(j+1) % 3);
  		bool duplicate = false
  		if (rmap.find(start) != rmap.end() ) {
  			std::vector<int> v = rmap[start];
  			if (std::find(v.begin(), v.end(), end) != v.end()){
  				duplicate = true;
  			}
		}
		if (!duplicate && rmap.find(end) != rmap.end()){
  			std::vector<int> v = rmap[end];
  			if (std::find(v.begin(), v.end(), start) != v.end()){
  				duplicate = true;
  			}
		}
  		if (!duplicate){
  			E(E.rows()+1, 0) = start;
  			E(E.rows()+1, 1) = end;
  			if (rmap.find(start) != rmap.end()){
  				rmap[start].push_back(end);
  			} else {
  				rmap[start] = std::vector();
  				rmap[start].push_back(end);
  			}
  		}
  	}
  }
  return E;
}
