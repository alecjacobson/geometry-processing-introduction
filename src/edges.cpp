#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E(F.rows()*3,2),E1(F.rows()*3/2,2);
  int es=0;
  bool flag;
  for (int i=0; i<F.rows(); i++){
    E(i*3,0)=F(i,0);
    E(i*3,1)=F(i,1);
    E(i*3+1,0)=F(i,1);
    E(i*3+1,1)=F(i,2);
    E(i*3+2,0)=F(i,2);
    E(i*3+2,1)=F(i,0);
  }
  for (int i=0; i<F.rows(); i++){
    flag=true;
    for (int j=0; j<es; j++)
      if (((E(i,0)==E1(j,0))&&(E(i,1)==E1(j,1)))||((E(i,0)==E1(j,1))&&(E(i,1)==E1(j,0)))) flag=false;
    if (flag){
      es++;
      E1(es-1,0)=E(i,0);
      E1(es-1,1)=E(i,1);
    }
  }
  return E1;
}
