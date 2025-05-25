#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "EdgeData.h"

using namespace std;


class VertexData {
private:
	double attr = std::numeric_limits<double>::quiet_NaN();
	bool visited;
	int numRul; //1 - 1 число, 2 -буква + число, 3 - min
	double val; // 1 правило, значение
	bool fromVertex; //2 правило, 1 если значение из узла, 0 - из ребра
	int num; //2 правило, номер узла или ребра
	vector<shared_ptr<EdgeData>> inEdge;

public:
	void ChangeAttr(double i);
	void ChangeNumRul(int i);
	void ChangeVal(double i);
	void ChangeFromVertex(bool i);
	void ChangeNum(int i);
	void ChangeVisited(bool i);
	double ReadAttr();
	int ReadNumRul();
	double ReadVal();
	bool ReadFromVertex();
	int ReadNum();
	bool ReadVisited();
	vector<shared_ptr<EdgeData>>& ReadInEdge();

	VertexData() { visited = 0; }
	
};
