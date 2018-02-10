#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{

  int Chi;
  Eigen::MatrixXi E = edges(F);
    int Fcard = F.rows();
    int Ecard = E.rows();
    int Vcard = F.maxCoeff() + 1;
    Chi = Vcard - Ecard + Fcard;

  return Chi;
}
