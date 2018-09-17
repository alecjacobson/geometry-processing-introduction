#include "euler_characteristic.h"
#include "edges.h"


// Assuming no vertices are unreferenced by F
// for |V| - |E| + |F| formula to be valid.
int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  Eigen::MatrixXi E = edges(F);
  int N_edges = E.rows();
  int N_faces = F.rows(); 

  // List all vertices in the mesh
  Eigen::VectorXi Vertices(F.rows() * 3);
  for (int i = 0; i < F.rows(); i++) {
 	Vertices(3 * i) = F(i,0);
	Vertices(3 * i + 1) = F(i,1);
	Vertices(3 * i + 2) = F(i,2);
  }

  // Count the number of unique vertices
  int max_vert_idx = 0;
  for (int i = 0; i < Vertices.size(); i++) {
	if (Vertices(i) > max_vert_idx) {
		max_vert_idx = Vertices(i);	
	}
  }

  Eigen::VectorXi Unique_Verts = Eigen::VectorXi::Zero(max_vert_idx + 1);
  for (int i = 0; i < Vertices.size(); i++) {
	Unique_Verts(Vertices(i)) = 1;
  }
  int N_verts = Unique_Verts.sum();


  // Calculate chi using chi = |V| - |E| + |F|
  Chi = N_verts - N_edges + N_faces; 
  return Chi;
}
