#include "edges.h"
#include <set>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
    // O(|F|log|F|)
	// Use additional O(|F|) storage to create edges set. 
    // std::set supports O(log(|F|)) insert and lookup. 
	// NOTE: Can change to unordered_set to support O(1) lookup if I provide hash function for pair<int,int>
	Eigen::MatrixXi E;
	Eigen::MatrixXi EBig(3*F.rows(), 2);
	std::set<std::pair<int, int>> m;
	int lostRows = 0;
	std::pair<int, bool> p;
	for (int i = 0; i < F.rows(); ++i) {
		//E.block(i, 0, 1, 2) = F.block(i, 0, 1, 2);
		p.first = F.row(i)(0);
		p.second = F.row(i)(1);
		if (m.count(p) != 1 && m.count(std::pair<int,int>(p.second,p.first)) != 1) {
			EBig.row(i)(0) = p.first;
			EBig.row(i)(1) = p.second;
			m.insert(p);
		}
		else {
			lostRows++;
		}
		//E.block(i + F.rows(), 0, 1, 2) = F.block(i, 1, 1, 2);
		p.first = F.row(i)(1);
		p.second = F.row(i)(2);
		if (m.count(p) != 1 && m.count(std::pair<int, int>(p.second, p.first)) != 1) {
			EBig.row(i + F.rows())(0) = p.first;
			EBig.row(i + F.rows())(1) = p.second;
			m.insert(p);
		}
		else {
			lostRows++;
		}
		//E.block(i + 2*F.rows(), 0, 1, 1) = F.block(i, 0, 1, 1);
		p.first = F.row(i)(0);
		p.second = F.row(i)(2);
		if (m.count(p) != 1 && m.count(std::pair<int, int>(p.second, p.first)) != 1) {
			EBig.row(i + 2 * F.rows())(0) = p.first;
			EBig.row(i + 2 * F.rows())(1) = p.second;
			m.insert(p);
		}
		else {
			lostRows++;
		}
		//E.block(i + 2*F.rows(), 1, 1, 1) = F.block(i, 2, 1, 1);
	}
  
	E = EBig.block(0, 0, EBig.rows() - lostRows, 2);

    return E;
}
