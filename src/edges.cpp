#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  int E_size = 0;
  std::set<std::tuple<int, int>> seenEdges;
  std::cout << "Size of F is " << F.rows() << std::endl;
  for(int f_idx=0; f_idx < F.rows(); f_idx++){
    E_size = addToEdges(E, E_size, seenEdges, F(f_idx,0), F(f_idx,1));
    E_size = addToEdges(E, E_size, seenEdges, F(f_idx,0), F(f_idx,2));
    E_size = addToEdges(E, E_size, seenEdges, F(f_idx,1), F(f_idx,2));
  }
  std::cout << E_size << std::endl; //10449
  return E;
}

int addToEdges(Eigen::MatrixXi &E, int E_size, std::set<std::tuple<int, int>> &seenEdges, int vertexA, int vertexB){
  if(!alreadySeen(seenEdges, vertexA, vertexB)){
    E_size += 1;
    E.resize(E_size, 2);
    E(E_size-1, 0) = vertexA;
    E(E_size-1,1) = vertexB;
    seenEdges.insert(std::make_tuple(vertexA, vertexB));
  }
  return E_size;
}
bool alreadySeen(std::set<std::tuple<int, int>> seenEdges, int vertexA, int vertexB){
  std::tuple<int,int> edge = std::make_tuple(vertexA, vertexB);
  std::tuple<int,int> reversedEdge = std::make_tuple(vertexB, vertexA);
  return (seenEdges.find(edge) != seenEdges.end()) || (seenEdges.find(reversedEdge) != seenEdges.end());
}
