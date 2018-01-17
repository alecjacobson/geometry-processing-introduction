#include "edges.h"
#include <vector> // Not sure if this is allowed; if it isn't, I'll know for future assignments!

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  
  // First, pretend all the triangles are unconnected, so that every edge is unique.
  // So we can go through all the triangles' vertices, and store each edge.
  // Since we only care about undirected edges, just sort each pair before putting it
  // in the list. This will make it easier to remove duplicates later on.
  // If the vertices of a face are indexed as 0, 1 ,2, then we know that the
  // edges would be (0,1), (1,2), (2,0) for that face.

  // Create a temporary container for the non-unique edges. There will be 3 for each face.
  std::vector<std::vector<int>> edges_with_duplicates (F.rows()*3);

  // Iterate through the matrix of faces
  int ee = 0; // keeps track of the rows of E, which are different from rows of F
  for (int ii = 0; ii < F.rows(); ii++)
  {
  	// First edge
  	edges_with_duplicates[ee].push_back(F(ii, 0));
  	edges_with_duplicates[ee].push_back(F(ii, 1));
  	std::sort(edges_with_duplicates[ee].begin(), edges_with_duplicates[ee].end());
  	ee++;

  	// Second edge
  	edges_with_duplicates[ee].push_back(F(ii, 1));
  	edges_with_duplicates[ee].push_back(F(ii, 2));
  	std::sort(edges_with_duplicates[ee].begin(), edges_with_duplicates[ee].end());
  	ee++;

  	// Third edge
  	edges_with_duplicates[ee].push_back(F(ii, 2));
  	edges_with_duplicates[ee].push_back(F(ii, 0));
  	std::sort(edges_with_duplicates[ee].begin(), edges_with_duplicates[ee].end());
  	ee++;
  }

  // Now we have to remove duplicates. Using C++ vector methods for this.
  // the vectors have to be sorted first.
  // (source: https://stackoverflow.com/questions/2512978/how-to-delete-duplicate-vectors-within-a-multidimensional-vector)
  std::sort(edges_with_duplicates.begin(), edges_with_duplicates.end());
  edges_with_duplicates.erase(std::unique(edges_with_duplicates.begin(), edges_with_duplicates.end()), edges_with_duplicates.end());

  // Now copy over the edges to the output matrix.
  // There is probably a more efficient way to do this by giving the Eigen matrix
  // a reference to contiguously stored data in the vector, but I think the
  // vector<vector> would have stored things resembling row major, while based on
  // Eigen's documentation, the output matrix would want it to be in column major.

  E.resize(edges_with_duplicates.size(), 2);
  for (int ii = 0; ii < edges_with_duplicates.size(); ii++)
  {
  	for (int jj = 0; jj < 2; jj++)
  	{
  	  E(ii, jj) = edges_with_duplicates[ii][jj];
  	}
  }

  return E;
}


