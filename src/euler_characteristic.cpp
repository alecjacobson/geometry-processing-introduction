#include "euler_characteristic.h"
#include <vector>
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;

  // Call the edges function to get the list of unique edges
  Eigen::MatrixXi E = edges(F);

  // Use the formula for polyhedral surfaces
  int N_faces = F.rows();
  int N_edges = E.rows();

  // To find the total number of unique vertices, go through all the vertices
  // in the faces, put them in one big vector, then sort and remove duplicates.
  std::vector<int> vertices;
  for (int ii = 0; ii < N_faces; ii++)
  	for (int jj = 0; jj < 3; jj++)
  	{
  		vertices.push_back(F(ii,jj));
  	}

  std::sort(vertices.begin(), vertices.end());
  vertices.erase(std::unique(vertices.begin(), vertices.end()), vertices.end());

  int N_vert = vertices.size();

  // Apply the formula
  Chi = N_vert - N_edges + N_faces;

  // Test
  // std::cout << Chi << std::endl;

  // Validation: based on some research online, the euler characteristic for
  // any closed surface should be 2. The bunny looks like it is a closed surface,
  // and this function returns 2, so it seems to be working.

  return Chi;
}
