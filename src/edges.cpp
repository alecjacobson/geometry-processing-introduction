#include "edges.h"
#include <map>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
	Eigen::MatrixXi E;
	// ADD YOUR CODE HERE

	//Create a hashmap of unique edges 
	typedef std::pair<int, int> Edge;
	std::map<Edge, int> edgeMap;

	//Loop through all faces, and add sorted index edges as keys to the hashmap.
	//This will result in only unique edges being stored.
	for (int x = 0; x < F.rows(); x++) {
		for (int y = 0; y < F.cols(); y++) {

			Edge edge(F(x, y), F(x, (y + 1) % 3));

			if (F(x, (y + 1) % 3) < F(x, y)) {
				edge.swap(Edge(F(x, (y + 1) % 3), F(x, y)));
			}
			edgeMap.insert(std::make_pair(edge, 1));
		}
	}
  
	//Copy the edge hashmap to the matrix
	E.resize(edgeMap.size(), 2);

	std::map<Edge, int>::iterator it;
	int index = 0;

	//The edge vertex index are the first and second Key values.
	for (it = edgeMap.begin(); it != edgeMap.end(); ++it) 
	{
		E(index, 0) = it->first.first;
		E(index, 1) = it->first.second;
		index++;
	}

	return E;


}
