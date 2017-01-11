#ifndef EULER_CHARACTERISTIC_H
#define EULER_CHARACTERISTIC_H

#include <Eigen/Core>

// Compute the Euler Characteristic of a given triangle mesh.
//
// Inputs:
//   F  #F by 3 list of triangle indices into V
// Returns Euler Characteristic as an integer
int euler_characteristic(
  const Eigen::MatrixXd &V, 
  const Eigen::MatrixXi &F, 
  const Eigen::MatrixXi &E);
#endif
