#include "edges.h"
#include <igl/cat.h>
#include  <iostream>
Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  for(int i = 0; i < F.rows(); i++){
    
    //I know this is highly unoptimized but there's the deadline
    for(int j = 0; j < 3; j++){
      int endpointa;
      int endpointb;
      if(j == 0){
        endpointa = F(i,0);
        endpointb = F(i,1);
      } else if(j == 1) {
        endpointa = F(i,1);
        endpointb = F(i,2);
      } else {
        endpointa = F(i,2);
        endpointb = F(i,0);
      }
      
      int edgenew = 1;
      for(int k = 0; k < E.rows(); k++){
        if((E(k,0) == endpointa && E(k,1) == endpointb) ||
           (E(k,1) == endpointa && E(k,0) == endpointb))
          edgenew = 0;
      }
      if(edgenew){
        E.conservativeResize(E.rows()+1,2);
        E.row(E.rows()-1) = Eigen::RowVector2i(endpointa,endpointb);
      }
    }
  }
  return E;
}
