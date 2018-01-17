#include "edges.h"
#include <vector>
#include <map>
#include <algorithm>
Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE
  std::map<int, std::vector<int>> rmap;//use map to store v-v relation
  std::vector<int> v_start;
  std::vector<int> v_end;
  for (int i = 0; i< F.rows(); ++i){
  	for (int j = 0; j< 3; ++j){//3 potional edges
  		int start = F(i,j);
  		int end = F(i,(j+1) % 3);
  		bool duplicate = false;
  		if (rmap.find(start) != rmap.end() ) { //check if already have this edge
  			std::vector<int> v = rmap[start];
  			if (std::find(v.begin(), v.end(), end) != v.end()){
  				duplicate = true;
  			}
		  }
		  if (!duplicate && rmap.find(end) != rmap.end()){ //the other way around
  			std::vector<int> v = rmap[end];
  			if (std::find(v.begin(), v.end(), start) != v.end()){
  				duplicate = true;
    		}
  		}
    	if (!duplicate){ // add the edge
  			v_start.push_back(start);
  			v_end.push_back(end);
  			if (rmap.find(start) != rmap.end()){
  				rmap[start].push_back(end);
  			} else {
  				rmap[start] = std::vector<int>();
  				rmap[start].push_back(end);
  			}
    	}
  	}
  }
  E.resize(v_start.size(),2);
  for (int i = 0; i<v_start.size(); ++i){ //add to the matrix
    E(i,0) = v_start[i];
    E(i,1) = v_end[i];
  }
  return E;
}
