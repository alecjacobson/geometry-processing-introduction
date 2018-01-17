#include <iostream>
#include <set>
#include "edges.h"

using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;

  // Based off advice from: https://www.quora.com/How-can-I-use-set-in-C++-to-store-a-pair-of-integers
  // Will store unique edge pairs
  set<pair<int,int>> s;

  // Just for checking my work
  // int CHECK_ME = 0;
  
  int num_rows_F = F.rows();
  int num_cols_F = F.cols();
  
  cout << "Number of Faces: " << num_rows_F << endl;
  cout << "Number of Sides per Face (should be 3): " << num_cols_F << endl;

  for(int i = 0; i < num_rows_F; i = i + 1) {
      // cout << "Row " << i << ": " << F.row(i) << endl;

      // Iterate over all pairs of indices once
  	  for(int j = 0; j < num_cols_F; j = j + 1) {
  	  	for(int k = j +1; k < num_cols_F; k = k + 1) {
  	  		int node_1 = F(i, j);
  	  		int node_2 = F(i, k);

  	  		// Ensure we always insert pairs symmetrically
	  		if (node_1 > node_2) {
	  	  		// For work checking
	  	  		// if (node_1 == CHECK_ME or node_2 == CHECK_ME) {
	  	  		// 	cout << node_1 << '_' << node_2 << endl;
	  	  		// }
  	  			s.insert(make_pair(node_1, node_2));
  	  		}
  	  		else {
	  	  		// For work checking
	  	  		// if (node_1 == CHECK_ME or node_2 == CHECK_ME) {
	  	  		// 	cout << node_1 << '_' << node_2 << endl;
	  	  		// }
  	  		    s.insert(make_pair(node_2, node_1));
  	  		}
  	  	}
  	  }
  } 

  E.resize(s.size(), 2);

  // For loop inspired from above link
  int z = 0;
  for (__typeof(s.begin()) it = s.begin(); it != s.end(); ++it) {

  	E.row(z) << it->first, it->second;

  	// For work checking
  	// if (it->first == CHECK_ME or it->second == CHECK_ME) {
  	// 	cout << it->first << '.' << it->second << endl;
  	// }

  	z = z + 1;
  }

  return E;
}


