#include <iostream>
#include <set>

#include "edges.h"
#include "euler_characteristic.h"


// helper function to "count" the # of vertices that are referenced
// assumes that "E" is properly calculated first :)
unsigned int calcMagV( const Eigen::MatrixXi &E )
{
    std::set<int> Vi;
    
    unsigned int nRows = E.rows();
    for( unsigned int i = 0; i < nRows; ++i )
    {
        Vi.insert( E(i, 0) );
        Vi.insert( E(i, 1) );
    }

    //std::cout<<"calculated "<<Vi.size()<<" verts from unique edges "<<std::endl;

    return Vi.size();
}


int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  // ADD YOUR CODE HERE
  // Chi = |V| - |E| + |F|

  // Assuming no holes...assuming polyhedral surface...
  // V should only contain "referenced" vertices, we'll count those
  // from the edges matrix which has already reduced the # of vertices
  // to consider :)
  Eigen::MatrixXi E = edges( F );
  
  Chi = calcMagV( E ) - E.rows() + F.rows();
  
  return Chi;
}
