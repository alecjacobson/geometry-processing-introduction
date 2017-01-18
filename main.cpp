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

  //std::cout<<"There are "<<F.rows()<<" faces and x3 edges = "<<F.rows()*3<<std::endl;
  std::cout<<V.rows()<<" read vertices"<<std::endl;
  
  Eigen::MatrixXi E = edges(F);
  int Chi = euler_characteristic(F);
  std::cout<<"Edge list E is "<<E.rows()<<"x"<<E.cols()<<std::endl;
  std::cout<<"Euler Characteristic: "<<Chi<<std::endl;

  // Create a libigl Viewer object 
  igl::viewer::Viewer viewer;
  // Set the vertices and faces for the viewer
  viewer.data.set_mesh(V, F);
  
  // Debugging - Display the "unique" edges only - toggle comment
  // with the set_mesh above
  // Eigen::MatrixXd C( E.rows(), 3 );
  // C = Eigen::MatrixXd::Zero( E.rows(), 3 ); // set colors to black
  // viewer.data.set_edges(V, E, C);

// Launch a viewer instance
  viewer.launch();
  return 0;
}

