#include "edges.h"
#include <unordered_set>

struct Edge
{
    int v1,v2;
    
    Edge(int v1, int v2) : v1(v1), v2(v2) {}
    
    int getId() const {return v1+v2;}
    
    bool operator ==(const Edge &other) const {
        return ((other.v1 == this->v1) && (other.v2 == this->v2)) ||
               ((other.v2 == this->v1) && (other.v1 == this->v2));
    }
};

namespace std {
    template<> struct hash<Edge> {
        size_t operator()(const Edge & obj) const {
            return hash<int>()(obj.getId());
        }
    };
}

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  std::unordered_set<Edge> edgeSet;
  for (int i = 0; i < F.rows(); ++i) 
  {
  	edgeSet.insert(Edge(F(i,0), F(i,1)));
  	edgeSet.insert(Edge(F(i,0), F(i,2)));
  	edgeSet.insert(Edge(F(i,1), F(i,2)));
  }

  int numEdges = edgeSet.size();
  //printf("Num of Edges %i\n", numEdges);
  E.resize(numEdges,2);

  int row = 0;
  for (const auto& elem : edgeSet) 
  {
  	E(row, 0) = elem.v1;
  	E(row++, 1) = elem.v2;
  }

  return E;
}
