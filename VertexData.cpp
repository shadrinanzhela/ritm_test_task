#include "VertexData.h"


void VertexData::ChangeAttr(double i) { attr = i; }
void VertexData::ChangeNumRul(int i) { numRul = i; }
void VertexData::ChangeVal(double i) { val = i; }
void VertexData::ChangeFromVertex(bool i) { fromVertex = i; }
void VertexData::ChangeNum(int i) { num = i; }
void VertexData::ChangeVisited(bool i) { visited = i; }
double VertexData::ReadAttr() { return attr; }
int VertexData::ReadNumRul() { return numRul; }
double VertexData::ReadVal() { return val; }
bool VertexData::ReadFromVertex() { return fromVertex; }
int VertexData::ReadNum() { return num; }
bool VertexData::ReadVisited() { return visited; }
vector<shared_ptr<EdgeData>>& VertexData::ReadInEdge() { return inEdge; }