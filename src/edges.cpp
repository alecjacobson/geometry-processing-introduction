#include "edges.h"
#include <set>
#include <algorithm>
Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  typedef std::set<std::pair<int, int> > EdgeSet;
  EdgeSet es;
  for ( int i = 0 ; i < F.rows() ; ++i ) {
    for ( int j = 0 ; j < 3 ; ++j ) {
      if ( F(i, j) < F(i, (j+1)%3) ) {
        es.insert(std::pair<int, int>(F(i, j), F(i, (j+1)%3)));
      } else {
        es.insert(std::pair<int, int>(F(i, (j+1)%3), F(i, j)));
      }
    }
  }
  E.resize(es.size(), 2);
  int offset = 0;
  for ( EdgeSet::iterator i = es.begin() ; i != es.end() ; ++i ) {
    E(offset, 0) = i->first;
    E(offset, 1) = i->second;
    offset++;
  }
  return E;
}
