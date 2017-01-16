#include "edges.h"
#include <Eigen/SparseCore>

using namespace Eigen;

typedef Triplet<int8_t> tri;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;

  // Edges are found using the adjacency information of the vertices
  // Construct the edge adjacency matrix using the setFromTriplets() sparse matrix constructor
  std::vector<tri> tripletList;
  tripletList.reserve(F.rows()*2);

  int32_t maxIndex = 0;
  
  for(int32_t i = 0; i < F.rows(); i++)
  {
    // if F was #faces x 3, the loop would not be needed, but more for a future-proofing of the system
    for(int32_t j = 0; j < F.cols(); j++)
    {
      int32_t indexOne = F(i,j);
      int32_t indexTwo = F(i,(j + 1) % F.cols());

      // connect the two indices together in the matrix
      tripletList.push_back(tri(indexOne, indexTwo, 1));
      tripletList.push_back(tri(indexTwo, indexOne, 1));

      if(F(i,j) > maxIndex)
	maxIndex = F(i,j);
      
    }
  }

  // create the sparse adjacency matrix
  SparseMatrix<int8_t> adjMat(maxIndex + 1, maxIndex + 1);
  adjMat.setFromTriplets(tripletList.begin(), tripletList.end());

  // the edges are just the non-zero elements in the adjMat, but it has both half edges. Just want the lower half of the mat
  E.resize(adjMat.nonZeros()/2, 2);
  int32_t currentRow = 0;
  // looping through the sparse mat as outlined in eigen documentation:
  for(int32_t i = 0; i < adjMat.outerSize(); i++)
  {
    for(SparseMatrix<int8_t>::InnerIterator it(adjMat, i); it; ++it)
    {
      if(it.row() > it.col())
      {
	E(currentRow, 0) = it.row();
	E(currentRow, 1) = it.col();
	currentRow++;
      }
    }
  }
  
  return E;
}
