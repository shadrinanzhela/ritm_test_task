#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <memory>

class EdgeData {
private:
	int in;
	int out;
	double attr = std::numeric_limits<double>::quiet_NaN();
	bool visited;
	int numRul; //1 - 1 число, 2 -буква + число, 3 - *
	double val; // 1 правило, значение
	bool fromVertex; //2 правило, 1 если значение из узла, 0 - из ребра
	int num; //2 правило, номер узла или ребра

public:
	void ChangeAttr(double i);
	void ChangeNumRul(int i);
	void ChangeVal(double i);
	void ChangeFromVertex(bool i);
	void ChangeNum(int i);
	void ChangeVisited(bool i);
	int ReadIn();
	int ReadOut();
	double ReadAttr();
	int ReadNumRul();
	double ReadVal();
	bool ReadFromVertex();
	int ReadNum();
	bool ReadVisited();


	double ComputeEdge();
	EdgeData(int v, int u) { in = v; out = u; visited = 0; }
};