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
	int numRul; //1 - 1 �����, 2 -����� + �����, 3 - *
	double val; // 1 �������, ��������
	bool fromVertex; //2 �������, 1 ���� �������� �� ����, 0 - �� �����
	int num; //2 �������, ����� ���� ��� �����

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