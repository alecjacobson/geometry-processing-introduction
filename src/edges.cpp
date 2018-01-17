#include "edges.h"
#include <algorithm>    // std::sort
#include <vector>       // std::vector

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    Eigen::MatrixXi E, tempE;
    
    
    int numRows, counter, sizeCounter, maxInd ;
    numRows = F.rows();
    
    int indices [(int) (3*numRows)];
    maxInd = F.maxCoeff();
    tempE.resize((int) (3*(double)numRows), 2);
    
    //We add all directed edges into the graph
    for (int section = 0; section < 3; section++){
        tempE.middleRows(section*numRows,numRows) << F.col(section), F.col(section < 2? section + 1 : 0);
        
    }
    
    counter = 0;
    //We assign a unique value to each undirected edge, directed edges that share the same end point have the same identifier
    for (int counter = 0; counter  < (3*numRows); counter++){
        indices[counter] = tempE.row(counter).minCoeff() * numRows +tempE.row(counter).maxCoeff();
    }
    
    //We sort this value
    std::vector<int> myvector (indices, indices+3*numRows);
    std::sort(myvector.begin(), myvector.end());
    
    
    //We loop over the sorted values, and only add edges when there are no duplicates
    sizeCounter = 0;
    E.resize(sizeCounter + 1,2);
    E(0,0) = myvector[0] / numRows;
    E(0,1) = myvector[0] - (int) E(0,0) * numRows;
    for (int counter = 1; counter  < (3*numRows); counter++){
        
        if (myvector[counter-1] != myvector[counter]){
            sizeCounter = sizeCounter + 1;
            E.resize(sizeCounter + 1, 2);
            
            //This extracts the end points from the unique identifier
            E(sizeCounter,0) = myvector[counter] / numRows;
            E(sizeCounter,1) = myvector[counter] - (int) E(sizeCounter,0) * numRows;
        }
        
    }
    return E;

}
