#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  
  // n: the number of vertices
  // (the vertices are numbered consecutively, starting at 0, and each vertex is included 
  // in F. This means the max numbered vertex is 1 less than the total number of vertices).
  int n = F.maxCoeff() + 1;
  
  // Adjacent is used to keep track of which vertices are adjacent to one another
  // (i.e. there is an edge connecting them).
  Eigen::MatrixXi Adjacent(n,n);
  
  // Populate Adjacent with a 1 at the (i,j)th and (j,i)th position whenever
  // there is an edge between vertices i and j.
  for (int i = 0; i < F.rows(); i++) {
    
    // The vertices that make up the face.
    int v0 = F(i,0);
    int v1 = F(i,1);
    int v2 = F(i,2);
    
    // There is an edge between each pair of vertices on the face.
    Adjacent(v0,v1) = 1; 
    Adjacent(v1,v0) = 1;
    Adjacent(v0,v2) = 1;
    Adjacent(v2,v0) = 1;
    Adjacent(v1,v2) = 1;
    Adjacent(v2,v1) = 1;
  }
  
  // r: keeps track of the current row in E in the below nested loop structure.
  // To populate E, we iterate through each row of Adjacent. At each row, we iterate
  // through each column up to but not including the diagonal - in this way, we avoid double
  // counting edges (i.e. where k < j and there is an edge connecting k and j, we count 
  // (j,k) but not (k,j)).
  int r = 0;
  for (int j = 1; j < n; j++) {
    for (int k = 0; k < j; k++) {
        if (Adjacent(j,k) == 1) {
            // Each time we find a new edge, we need to increase the number of rows
            // in E by 1. The use of conservativeResize instead of resize preserves
            // the existing data in the matrix.
            E.conservativeResize(E.rows() + 1, 2);
            E(r,0) = j;
            E(r,1) = k;
            r++;
        }
    }
  }
  
  return E;
}
