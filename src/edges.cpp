#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    Eigen::MatrixXi E;

  // ADD YOUR CODE HERE

  //make sure edge is unique, so I use set here. 
  typedef std::set<int> Edge;
  typedef std::set <Edge> EdgeSet;

    
  Edge edge;
  EdgeSet edgeset;
  Edge::iterator It;
  EdgeSet::iterator setIt;

  int a,b,c; 
  
  //get all the edges
  for (int r = 0; r < F.rows(); ++r){
       
       a=F(r,0);
       b=F(r,1);
       c=F(r,2);

       edge.insert(a);
       edge.insert(b);
       edgeset.insert(edge);
       edge.clear();

       edge.insert(b);
       edge.insert(c);
       edgeset.insert(edge);
       edge.clear();

       edge.insert(a);
       edge.insert(c);
       edgeset.insert(edge);
       edge.clear();
     
    }

    E.resize(edgeset.size(),2);

    //assign them to E
    int i =0;
    for (setIt = edgeset.begin(); setIt != edgeset.end();  setIt++){

        int j =0;
        for (It = setIt->begin(); It != setIt->end(); It++) {
            E(i,j) =  *It;
            j++;
        } 
        i++;
           
     }
 
  return E;
}
