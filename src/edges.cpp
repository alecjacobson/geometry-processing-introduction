#include "edges.h"
#include <vector>

bool comp(Eigen::RowVector2i a, Eigen::RowVector2i b) {
  return a(0) > b(0) || (a(0) == b(0) && a(1) > b(1));  
}

bool equal(Eigen::RowVector2i a, Eigen::RowVector2i b) {
  return a(0) == b(0) && a(1) == b(1);
}

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;

  // There are 3 edges per face (including duplicates)
  Eigen::MatrixXi preE_a(F.rows() * 3, 2), preE_b(F.rows() * 3, 2);

  // Assign values to them
  preE_a << F.col(0), F.col(1),
          F.col(1), F.col(2),
          F.col(2), F.col(0);

  // start with higher indices
  preE_b << preE_a.rowwise().maxCoeff(), preE_a.rowwise().minCoeff();

  // using sort and unique to remove duplicates
  // Idea inspired by C++ reference http://www.cplusplus.com/reference/algorithm/unique/
  std::vector<Eigen::RowVector2i> my_vector;
  for (int i = 0; i < preE_b.rows(); i++)
      my_vector.push_back(preE_b.row(i));

  std::sort(my_vector.begin(), my_vector.end(), &comp);
  std::vector<Eigen::RowVector2i>::iterator last_iterator = 
        std::unique(my_vector.begin(), my_vector.end(), &equal);
  my_vector.erase(last_iterator, my_vector.end()); 

  // Since duplicates have been removed, construct E using my_vector
  E.conservativeResize(my_vector.size(), 2);
  for (int j = 0; j < my_vector.size(); j ++) {
    E.row(j) = my_vector[j];
  }
  return E;
}
