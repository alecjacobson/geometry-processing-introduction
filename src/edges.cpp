#include <iostream>
#include <set>
#include <vector>

#include <assert.h>

#include "edges.h"

class Edge
{
public:
    Edge( const int &a, const int &b )
        {
            // always sort the edges that come in, these are undirected! so {1,2} == {2,1}
            // so we'll always store E e(2,1) internally as {1,2}.
            // makes comparing/sorting easier...
            if( a < b )
            {
                m_e[0] = a;
                m_e[1] = b;
            }
            else
            {
                m_e[0] = b;
                m_e[1] = a;
            }
            
            // error!  Degenerate edge!
            // throw an assert in debug,
            // optimized out in release :)
            assert( a != b );
        }
    
    friend bool operator<(const Edge &e1, const Edge &e2 );

    int m_e[2];
};

bool operator<(const Edge &e1, const Edge &e2 )
{
    if( e1.m_e[0] < e2.m_e[0] )
        return true;
    else if( e2.m_e[0] < e1.m_e[0] )
        return false;
    else
        return( e1.m_e[1] < e2.m_e[1] ); // first element is equal
}


Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;

  // ADD YOUR CODE HERE
  // not the most efficient way to do this, but it's the first assignment...
  const unsigned int rows = F.rows();
  
  std::set<Edge> Edges;
  for( unsigned int i = 0; i < rows; ++i )
  {
    for( int j = 0; j < 3; ++j )
    {
        Edges.insert( Edge( F(i,j),
                            F(i, (j+1)%3 ) )); // yields {0,1}, {1,2} {2,0}
    }
  }
  

  E.resize( Edges.size(), 2 );

  unsigned int i = 0;
  for( auto && e : Edges )
  {
      E( i, 0 ) = e.m_e[0];
      E( i, 1 ) = e.m_e[1];
      ++i;
  }

  // uncomment to see contents of E.
  // std::cout << "Print E..." << std::endl;
  // std::cout << E << std::endl;
  
  return E;
}
