#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  int ee=F.rows()*3/2,ff=F.rows();
  Eigen::MatrixXi dd(F.rows()*3,1);
  int ds=0;
  bool flag;
  for (int i=0; i<F.rows(); i++)
    for (int j=0; j<3; j++){
      flag=true;
      for (int k=0; k<ds; k++)
        if (dd(ds,0)==F(i,j)) flag=false;
      if (flag){
        ds++;
        dd(ds-1,0)=F(i,j);
      }
    }
  Chi=ds-ee+ff;
  return Chi;
}
