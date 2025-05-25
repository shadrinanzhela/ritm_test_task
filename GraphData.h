#pragma once
#include<vector>
#include "EdgeData.h"
#include "VertexData.h"
#include <memory>

using namespace std;


class GraphData {
private:
	int NV;
	int NE;
	std::vector<shared_ptr<VertexData>> Vertex;
	std::vector<shared_ptr<EdgeData>> Edge;

public:
	void ChangeNV(int i) { NV = i; }
	void ChangeNE(int i) { NE = i; }
	int ReadNE() { return NE; }
	int ReadNV() { return NV; }
	std::vector<shared_ptr<VertexData>>& ReadVertex() { return Vertex; }
	std::vector<shared_ptr<EdgeData>>& ReadEdge() { return Edge; }

	void AddRulVertex(int num, int numRul, int i, double d, string str);

	void AddRulEdge(int numEdge, int numRul, int i, double d, string str);

	double Mod(double i);

	int ComputeEdge(shared_ptr<EdgeData> edge);

	int ComputeVertex(shared_ptr <VertexData> vertex);

	int ComputeGraph();

	void AddVertex() { Vertex.push_back(make_shared<VertexData>()); }

	void AddEdge(shared_ptr<EdgeData> edge) { Edge.push_back(edge); }
};
