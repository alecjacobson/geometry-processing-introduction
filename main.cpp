#include "edges.h"
#include "euler_characteristic.h"
#include <igl/read_triangle_mesh.h>
#include <igl/opengl/glfw/Viewer.h>

int main(int argc, char *argv[])
{
  Eigen::MatrixXd V;
  Eigen::MatrixXi F;
  // Load in a mesh
  igl::read_triangle_mesh(argc>1 ? argv[1] : "../data/bunny.off", V, F);

  Eigen::MatrixXi E = edges(F);
  int Chi = euler_characteristic(F);
  std::cout<<"Edge list E is "<<E.rows()<<"x"<<E.cols()<<std::endl;
  std::cout<<"Euler Characteristic: "<<Chi<<std::endl;

  // Create a libigl Viewer object 
  igl::opengl::glfw::Viewer viewer;
  // Set the vertices and faces for the viewer
  viewer.data().set_mesh(V, F);
  // Launch a viewer instance
  viewer.launch();
  return 0;
}

