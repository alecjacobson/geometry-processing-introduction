#include "edges.h"

#include <iostream>
#include <vector>
using namespace std;

bool less_second(const vector<int> & m1, const vector<int> & m2) {

	if (m1[0] < m2[0]) {
		return true;
	} else if (m1[0] > m2[0]) {
		return false;
	} else {
		return m1[1] < m2[1];
	}

}

bool compedge(const vector<int> & m1, const vector<int> & m2) {

	return m1[0] == m2[0] && m1[1] == m2[1];

}

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {
	Eigen::MatrixXi E;
	// ADD YOUR CODE HERE

	// first, decide how many edges we have

	vector<vector<int> > edges;

	for (int i = 0; i < F.rows(); i++) {
		for (int j = 0; j < 3; j++) {
			int be = F(i, j);
			int en = F(i, (j + 1) % 3);

			vector<int> edge;
			if (be < en) {
				edge.push_back(be);
				edge.push_back(en);
			} else {
				edge.push_back(en);
				edge.push_back(be);
			}
			edges.push_back(edge);
		}
	}

	// sort
	sort(edges.begin(), edges.end(), less_second);

	// remove the same edge
	vector<vector<int> > uniqueedges;
	vector<int> lastedge;
	lastedge.push_back(0);
	lastedge.push_back(0);
	for (int i = 0; i < edges.size(); i++) {
		if (!compedge(lastedge, edges[i])) {
			uniqueedges.push_back(edges[i]);
			lastedge = edges[i];
		}
	}

	// fill data in eigen
	E = Eigen::MatrixXi::Constant(uniqueedges.size(), 2, 0);
	for (int i = 0; i < uniqueedges.size(); i++)
		for (int j = 0; j < 2; j++)
			E(i, j) = uniqueedges[i][j];

	return E;
}

