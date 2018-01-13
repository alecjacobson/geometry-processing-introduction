#include "edges.h"
#include "euler_characteristic.h"
#include <igl/read_triangle_mesh.h>
#include <igl/viewer/Viewer.h>

int main(int argc, char *argv[])
{
  Eigen::MatrixXd V;
  Eigen::MatrixXi F;
  // Load in a mesh
  igl::read_triangle_mesh(argc>1 ? argv[1] : "../shared/data/bunny.off", V, F);
  //igl::read_triangle_mesh(argc>1 ? argv[1] : "../shared/data/Torus.obj", V, F);
  int iVertexCount = V.rows();
  std::cout << "The number of vertices is " << iVertexCount << std::endl;

  Eigen::MatrixXi E = edges(F);
  int Chi = euler_characteristic(F);
  std::cout<<"Edge list E is "<<E.rows()<<"x"<<E.cols()<<std::endl;
  std::cout<<"Euler Characteristic: "<<Chi<<std::endl;

  // Create a libigl Viewer object 
  igl::viewer::Viewer viewer;
  // Set the vertices and faces for the viewer
  viewer.data.set_mesh(V, F);
  // Launch a viewer instance
  viewer.launch();

  std::cin.get();
  return 0;
}

