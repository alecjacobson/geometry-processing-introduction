#ifndef EDGES_H
#define EDGES_H
#include <Eigen/Core>
#include <iostream>
#include <set>
#include <tuple>

// From a list of triangle indices into some vertex set V, determine the
// set of unique undirected edges.
//
// Inputs:
//   F  #F by 3 list of triangles indices into some vertex set V
// Returns E  #E by 2 list of undirected edge indices into V
Eigen::MatrixXi edges(const Eigen::MatrixXi &F);

// Adds the undirected edge (vertexA, vertexB) to E if it is not in seenEdges, and returns an updated E_size
int addToEdges(Eigen::MatrixXi &E, int E_size, std::set<std::tuple<int, int>> &seenEdges, int vertexA, int vertexB);

// Returns true if the undirected edge (vertexA, vertexB) is in seenEdges, otherwise false
bool alreadySeen(std::set<std::tuple<int, int>> seenEdges, int vertexA, int vertexB);
#endif
